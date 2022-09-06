#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"TFile.h"
#include"TEnv.h"

using namespace std;
void findFailedJobs(string arg){
  char jdlStart[200];
  sprintf(jdlStart,"%s",arg.c_str());
  //  sprintf(jdlStart,"signalRegionSkim_%s_",dataset); /eos/uscms
  //  char ofileStart[300]="/eos/uscms/store/user/bkansal/GMSB_skims_TreesV16/SignalRegion/SR_";
  //  char ofileStart[300]="/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/lost_electron/CR_";
  // char ofileStart[300]="/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/SignalRegion/skims/SR_";
  char ofileStart[300]="/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/lostlepton/LM/withoutJERC/";
  char ofileEnd[200]=".root";
  char name1[200],name2[400];
  gEnv->SetValue("TFile.Recover", 0);
  vector<int> failedID;
  int totalJobs=0;
  for(int i=0;;i++){
    sprintf(name1,"%s_job%i.jdl",jdlStart,i);cout<<name1<<endl;
    ifstream infile(name1);
    if(!infile) {cout<<"Total jdl="<<i<<endl;totalJobs=i;break;}
    //    sprintf(name2,"%s%i%s",ofileStart,i,ofileEnd);
    sprintf(name2,"%s%s_job%i.root",ofileStart,jdlStart,i);//cout<<name2<<endl;
    TFile *f1=new TFile(name2);
    if(f1->IsZombie() || !f1) {
      failedID.push_back(i);
    }
    delete f1;
  }
  cout<<"-----------------------------------------------"<<endl;
  for(int i=0;i<failedID.size();i++){
    cout<<"condor_submit "<<jdlStart<<"_job"<<failedID[i]<<".jdl"<<endl;
  }
  cout<<"-----------------------------------------------"<<endl;
  cout<<"Total failed "<<jdlStart<<" jobs:"<<failedID.size()<<endl;

  if(failedID.size() == 0 && totalJobs!=0) {
    cout<<"-----------------------------------------"<<endl;
    cout<<endl<<"hadd -f"<<ofileStart<<jdlStart<<".root "<<ofileStart<<jdlStart<<"_job*.root"<<endl;
    cout<<"rm "<<ofileStart<<jdlStart<<"_job*.root"<<endl;
    cout<<"-----------------------------------------"<<endl;
    char cmd2[1000];
    sprintf(cmd2,"du -sh %s%s_job0.root",ofileStart,jdlStart);
    system(cmd2);
    cout<<"-----------------------------------------"<<endl;
    int choice1=1;
    cout<<endl<<"Enter what you want to do:"<<endl
       	<<"1: hadd -f"<<endl
     	<<"any other no. to exit"<<endl;
    //    cin>>choice1;

  
    if(choice1==1){
      sprintf(cmd2,"hadd -f %s%s.root %s%s_job*.root",ofileStart,jdlStart,ofileStart,jdlStart);
      system(cmd2);
      
      cout<<endl<<"Remove individual files? If hadd was successfull, then you may remove individual files."<<endl;
      sprintf(cmd2,"remove? %s%s_job*.root",ofileStart,jdlStart);
      cout<<cmd2<<endl;
      cout<<"Enter -1 to remove added files, any other no. to exit."<<endl;
      //      cin>>choice1;
      choice1=-1;
      if(choice1==-1){
	char cmd2[1000];
	sprintf(name2,"%s%s.root",ofileStart,jdlStart);
	TFile *f1=new TFile(name2);
	if( !(f1->IsZombie() || !f1) ) {
	  cout<<endl<<"Removing job files"<<endl;
	  sprintf(cmd2,"rm %s%s_job*.root",ofileStart,jdlStart);
	  system(cmd2);
	}
	else cout<<"hadd might have failed. Did not remove files"<<endl;
	delete f1;
      }
    }
  }
}
