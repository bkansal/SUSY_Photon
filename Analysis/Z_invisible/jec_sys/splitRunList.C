#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
//void splitRunList(string infile,int nfPerJob, string datasetAna){
void splitRunList(string infile,int nfPerJob, string datasetAna, string dir="Zinvisibe/withoutJERC/"){
  //------------ needed for condor files --------------
  string exeCondor  = "worker2.sh";
  string exeAna     = "z_invisible";
  //  string datasetAna = "SR";
  string filesToTransfer = "PileupHistograms_2016_69mb_pm5.root,PileupHistograms_2017_69mb_pm5.root,PileupHistograms_2018_69mb_pm5.root,Zinvisible_SF.root,purityfactor.root,Zinvisible_SF.root,RK_lowMET_data.root,pdf_full_Run2.root,scale_full_Run2.root";
  //---------------------------------------------------
  cout<<"executable at worker node : "<<exeCondor<<endl
      <<"Analysis executable : "<<exeAna<<endl
      <<"dataset name for analysis : "<<datasetAna<<endl;
  //----------------- split the input files into smaller ones ------------------
  ifstream file(infile);
  if(!file){cout<<"Couldn't Open File "<<infile<<endl;}
  string str,dataset=infile;
  dataset.pop_back();  dataset.pop_back();  dataset.pop_back();  dataset.pop_back();
  string filename=dataset;
  vector<string> fname;
  while (std::getline(file, str))
    {
      fname.push_back(str);
    }
  file.close();

  int jobid=0;
  char name[200];
  ofstream outf;
  for(int i=0,j=0;i<fname.size();){
    sprintf(name,"FileList_%s_job%i.txt",dataset.c_str(),jobid);
    outf.open(name);
    for(j=0;j<nfPerJob && i<fname.size();j++){
      outf<<fname[i]<<endl;
      i++;
    }
    jobid++;
    outf.close();
  }

  //--------------------- make files for codor ------------------------------------
  char fileListName[200],logFile[200];
  for(int i=0;i<jobid;i++){
    sprintf(name,"%s_job%i.jdl",dataset.c_str(),i);
    sprintf(fileListName,"FileList_%s_job%i.txt",dataset.c_str(),i);
    sprintf(logFile,"%s_job%i",dataset.c_str(),i);
    outf.open(name);
    outf<<"universe = vanilla"<<endl
	<<"Executable = "<<exeCondor<<endl
	// <<"request_disk = 10000000"<<endl
	// <<"request_memory = 10000"<<endl
	<<"Should_Transfer_Files = YES"<<endl
	<<"WhenToTransferOutput = ON_EXIT_OR_EVICT"<<endl
	<<"Transfer_Input_Files = "<<filesToTransfer<<","<<exeAna<<","<<fileListName<<endl
      //	<<"PeriodicRemove = ( JobStatus == 2 ) && ( ( CurrentTime - EnteredCurrentStatus ) > 600 )"<<endl
	<<"Output = "<<logFile<<".stdout"<<endl
	<<"Error = "<<logFile<<".stderr"<<endl
	<<"Log = "<<logFile<<".condor"<<endl
	// <<"notification = Error"<<endl
	// <<"notify_user = vhegde@FNAL.GOV"<<endl
	<<"x509userproxy = $ENV(X509_USER_PROXY)"<<endl
	<<"Arguments = "<<exeAna<<" "<<fileListName<<" "<<logFile<<".root "<<datasetAna<<" "<<dir<<endl
	<<"+LENGTH=\"SHORT\""<<endl
	<<endl
	<<"Queue 1";
    outf.close();
  }
  //------------------------ submit to condor --------------------------------------
  int t1=100;
  cout<<"Do you want to submit "<<jobid<<" jobs? If yes enter 100"<<endl;
  //  cin>>t1;
  for(int i=0;i<jobid && t1==100;i++){
    sprintf(name,"condor_submit %s_job%i.jdl",dataset.c_str(),i);
    system(name); 
  }
  
}

void splitRunList(){
  cout<<"Please specify the input txt file to use and no. of files per job"<<endl;
  cout<<"splitRunList(string infile,int nfPerJob)"<<endl;
}
