#include"TBrowser.h"
#include"TF1.h"
#include<string>
#include<vector>
#include"TGraphErrors.h"
#include"TGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TCanvas.h"
#include"THStack.h"
#include"TStyle.h"
#include"TGraphAsymmErrors.h"

vector<int> col={kGray,kOrange,kTeal+9,kCyan-1,kCyan-1,kBlack};

void printRK(bool R_data=true, bool syst=false, bool RK=false)
{
  //  bool R_data=false;
  //bool RK=true;
  /*
  TString path1="../rootoutput/QCD/Lostlepton_lowdphi.root";
  TString path2="../rootoutput/QCD/Fakerate_lowdphi.root";
  TString path3="../rootoutput/QCD/Zinvi_lowdphi.root";
  TString path1_="../rootoutput/QCD/Lostlepton_highdphi.root";
  TString path2_="../rootoutput/QCD/Fakerate_highdphi.root";
  TString path3_="../rootoutput/QCD/Zinvi_highdphi.root";
  */

  TString path1="rootoutput/Multi//Lostlepton_lowdphi.root";
  TString path2="rootoutput/Multi/Fakerate_lowdphi.root";
  TString path3="rootoutput/Multi/Zinvi_lowdphi.root";
  TString path1_="rootoutput/Multi/Lostlepton_highdphi.root";
  TString path2_="rootoutput/Multi/Fakerate_highdphi.root";
  TString path3_="rootoutput/Multi/Zinvi_highdphi.root";

  TString pdf,png;

  pdf="pdf/Multi_R_data.pdf";
  png="png/Multi_R_data.png";
  TFile *LL_lowdphi = TFile::Open(path1,"READ");
  TFile *FR_lowdphi = TFile::Open(path2,"READ");
  TFile *Zin_lowdphi = TFile::Open(path3,"READ");
  TFile *LL_highdphi = TFile::Open(path1_,"READ");
  TFile *FR_highdphi = TFile::Open(path2_,"READ");
  TFile *Zin_highdphi = TFile::Open(path3_,"READ");
  //../multijet/rootoutput/final/noRK/
  TH1D *LL_low=(TH1D*)LL_lowdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *FR_low=(TH1D*)FR_lowdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *Zin_low=(TH1D*)Zin_lowdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *LL_high=(TH1D*)LL_highdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *FR_high=(TH1D*)FR_highdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *Zin_high=(TH1D*)Zin_highdphi->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec1_closure");
  //TFile *Multi_data = TFile::Open("../multijet/rootoutput/btagSF/Run2_METdata_CR_v18.root","READ");
  //  TFile *data = TFile::Open("../multijet/rootoutput/v2_btagSF/ST300_Rfactor_applied_noRK/Run2_METdata_CR_v18.root","READ");
  TFile *data = TFile::Open("rootoutput/Multi/Run2_METdata_CR_v18.root","READ");
  TH1D *cr=(TH1D*)data->FindObjectAny("AllSBins_v6_CD_EW_50bin_AB");

  /* other plots */  
  TH1D *h_ST=new TH1D("ST","ST",400,0,4000);
  TH1D *h_MET=new TH1D("MET","MET",200,0,2000);
  TH1D *h_BTags=new TH1D("nBTags","no. of B tags",10,0,10);
  TH1D *h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",150,0,1500);
  TH1D *h_hadAk8Mass=new TH1D("hadAk8Mass","Soft dropped Mass of AK8 Jet",1000,0,300);
  TH1D *h_nJets=new TH1D("nJets","no. of hadronic jets",10,0,10);

  //  TFile *data_pred = TFile::Open("../multijet/rootoutput/final/RK_MCclosure/Run2_METdata_CR_v18.root","READ");
  TFile *data_pred = TFile::Open("rootoutput/Multi/Run2_METdata_CR_v18.root","READ");
  h_ST  = (TH1D*)data_pred->Get("ST_D");
  h_MET  = (TH1D*)data_pred->Get("MET_D");
  h_nJets  = (TH1D*)data_pred->Get("nJets_D");
  h_BTags  = (TH1D*)data_pred->Get("nBTags_D");
  h_BestPhotonPt  = (TH1D*)data_pred->Get("BestPhotonPt_D");
  //  h_hadAk8Mass  = (TH1D*)data_pred->Get("hadAk8Mass_D");
  
  TH1D *ewk_low = (TH1D*)LL_low->Clone("ewk_low");
  ewk_low->Add(FR_low);
  ewk_low->Add(Zin_low);
  cout<<"Total EWK in bin1 = "<<ewk_low->GetBinContent(2)<<endl;

  TH1D *ewk = (TH1D*)LL_high->Clone("ewk");
  ewk->Add(FR_high);
  ewk->Add(Zin_high);
  cout<<"Total EWK in Bin1 = "<<ewk->GetBinContent(2)<<endl;
  TFile *K_valid = TFile::Open("factors/K_validation.root","READ");
  TH1D *syserror=(TH1D*)K_valid->FindObjectAny("k_valid");
  //  TFile *Multi = TFile::Open("../multijet/rootoutput/btagSF/Run2_METdata_CR_v18.root","READ");
  TFile *Multi = TFile::Open("rootoutput/Multi/Run2_METdata_CR_v18.root","READ");
  TFile *Multi_mc = TFile::Open("rootoutput/Multi/GJetsQCD_new_v18.root","READ");
  //TFile *Multi_mc = TFile::Open("../multijet/rootoutput/final/Kmc_check/GJets_wt1/GJetsQCD_new_v18.root","READ");   
  //  TFile *Multi_mc = TFile::Open("../multijet/rootoutput/final/Kmc_check/GJets_wt2/GJetsQCD_new_v18.root","READ");
  TH1D *fake_lowdphi=(TH1D*)Multi->FindObjectAny("AllSBins_v6_CD_EW_50bin_AB");
  TH1D *fake=(TH1D*)Multi->FindObjectAny("AllSBins_v6_CD_EW_50bin_CD");
  fake->Print("all");
  ewk->Print("all");
  fake_lowdphi->Add(ewk_low,-1);
  fake->Add(ewk,-1);

  TH1D *SR = (TH1D*)fake->Clone("SR");
  TH1D *CR = (TH1D*)fake_lowdphi->Clone("CR");

  //  for(int i=1;i<46;i++)
  //  cout<<fake->GetBinContent(i)<<endl;
  fake->Divide(fake_lowdphi);

  TH2D *R_highdphi_nb0=(TH2D*)Multi_mc->FindObjectAny("nJetsMET_v2_C");
  TH2D *R_lowdphi_nb0=(TH2D*)Multi_mc->FindObjectAny("nJetsMET_v2_A");
  TH2D *R_highdphi_nb1=(TH2D*)Multi_mc->FindObjectAny("nJetsMET_v2_D");
  TH2D *R_lowdphi_nb1=(TH2D*)Multi_mc->FindObjectAny("nJetsMET_v2_B");
  R_highdphi_nb0->Print("all");
  R_lowdphi_nb0->Print("all");
 
  TH1D *R_highdphi_Wtag=(TH1D*)Multi_mc->FindObjectAny("nJetsMET_R");
  TH1D *R_lowdphi_Wtag=(TH1D*)Multi_mc->FindObjectAny("nJetsMET_P");
  TH1D *R_highdphi_Htag=(TH1D*)Multi_mc->FindObjectAny("nJetsMET_S");
  TH1D *R_lowdphi_Htag=(TH1D*)Multi_mc->FindObjectAny("nJetsMET_Q");
  
  R_highdphi_nb0->Divide(R_lowdphi_nb0);
  R_highdphi_nb1->Divide(R_lowdphi_nb1);
  R_highdphi_Wtag->Divide(R_lowdphi_Wtag);
  R_highdphi_Htag->Divide(R_lowdphi_Htag);

  
  TFile *f1;
  if(!syst) f1=new TFile("rootoutput/RK_lowMET_data.root","recreate");
  else f1=new TFile("rootoutput/RK_lowMET_data_sys.root","recreate");
  TH1D *fr= new TH1D("fr","R x K factor for data in low MET",52,0,52);
  TH1D *fr1= new TH1D("fr1","R x K factor for data in low MET",52,0,52);
  TH1D *AllSBins_v6_CD_EW_50bin_elec1 = new TH1D("AllSBins_v6_CD_EW_50bin_elec1","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  TH1D *AllSBins_v6_CD_EW_50bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_50bin_elec1_closure","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  f1->cd();
  double tf_51[50], tf_err[50];
  cout<<" R (MC) : low MET & high MET"<<endl;  
  cout<<" 0b 2-4 : "<<R_highdphi_nb0->GetBinContent(1,1)<<" :  "<< R_highdphi_nb0->GetBinContent(2,1)<<endl;
  cout<<" 0b 5-6 : "<<R_highdphi_nb0->GetBinContent(1,2)<<" :  "<< R_highdphi_nb0->GetBinContent(2,2)<<endl;
  cout<<" 0b >7 : "<<R_highdphi_nb0->GetBinContent(1,3)<<" :  "<< R_highdphi_nb0->GetBinContent(2,3)<<endl;
  cout<<" 1b 2-4 : "<<R_highdphi_nb1->GetBinContent(1,1)<<" :  "<< R_highdphi_nb1->GetBinContent(2,1)<<endl;
  cout<<" 1b 5-6 : "<<R_highdphi_nb1->GetBinContent(1,2)<<" :  "<< R_highdphi_nb1->GetBinContent(2,2)<<endl;
  cout<<" 1b >7 : "<<R_highdphi_nb1->GetBinContent(1,3)<<" :  "<< R_highdphi_nb1->GetBinContent(2,3)<<endl;
  cout<<" WTag : "<<R_highdphi_Wtag->GetBinContent(1)<<" : "<<R_highdphi_Wtag->GetBinContent(2)<<endl;
  cout<<" HTag : "<<R_highdphi_Htag->GetBinContent(1)<<" : "<<R_highdphi_Htag->GetBinContent(2)<<endl;


 
  cout<<"R (data) in lowdphi : "<<endl;
  
  for(int i=1;i<46;i++)                                                                                                                                                      {

    AllSBins_v6_CD_EW_50bin_elec1->SetBinContent(i+1,fake_lowdphi->GetBinContent(i+1));
    AllSBins_v6_CD_EW_50bin_elec1->SetBinError(i+1,fake_lowdphi->GetBinError(i+1));
    //    cout<<i<<" : "<<"fake_lowdphi = "<<fake_lowdphi_->GetBinContent(i+1)<<" +- "<<fake_lowdphi_->GetBinError(i+1)<<" , ewk_low = "<<ewk_low->GetBinContent(i+1)<<" +- "<<ewk_low->GetBinError(i+1)<<" , AllSBins_v6_CD_EW_50bin_elec1 = "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i+1)<<" +- "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i+1)<<endl;

    //    cout<<i<<" : "<<"fake_lowdphi = "<<fake->GetBinContent(i+1)<<endl;
    if(i==1 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}    
    if(i>1 && i<8) {tf_51[i]=tf_51[1]*R_highdphi_nb0->GetBinContent(2,1)/R_highdphi_nb0->GetBinContent(1,1); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[1]/tf_51[1],2)+pow(R_highdphi_nb0->GetBinError(1,1)/R_highdphi_nb0->GetBinContent(1,1),2) + pow(R_highdphi_nb0->GetBinError(2,1)/R_highdphi_nb0->GetBinContent(2,1),2),0.5);} 
    if(i==8 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>8 && i<14) {tf_51[i]=tf_51[8]*R_highdphi_nb0->GetBinContent(2,2)/R_highdphi_nb0->GetBinContent(1,2); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[8]/tf_51[8],2)+pow(R_highdphi_nb0->GetBinError(1,2)/R_highdphi_nb0->GetBinContent(1,2),2) + pow(R_highdphi_nb0->GetBinError(2,2)/R_highdphi_nb0->GetBinContent(2,2),2),0.5);}
    if(i==14 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>14 && i<19) {tf_51[i]=tf_51[14]*R_highdphi_nb0->GetBinContent(2,3)/R_highdphi_nb0->GetBinContent(1,3); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[14]/tf_51[14],2)+pow(R_highdphi_nb0->GetBinError(2,3)/R_highdphi_nb0->GetBinContent(2,3),2) + pow(R_highdphi_nb0->GetBinError(1,3)/R_highdphi_nb0->GetBinContent(1,3),2),0.5);}
    if(i==19 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>19 && i<24) {tf_51[i]=tf_51[19]*R_highdphi_nb1->GetBinContent(2,1)/R_highdphi_nb1->GetBinContent(1,1); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[19]/tf_51[19],2)+pow(R_highdphi_nb1->GetBinError(1,1)/R_highdphi_nb1->GetBinContent(1,1),2) + pow(R_highdphi_nb1->GetBinError(2,1)/R_highdphi_nb1->GetBinContent(2,1),2),0.5);}
    if(i==24 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>24 && i<29) {tf_51[i]=tf_51[24]*R_highdphi_nb1->GetBinContent(2,2)/R_highdphi_nb1->GetBinContent(1,2); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[24]/tf_51[24],2)+pow(R_highdphi_nb1->GetBinError(2,2)/R_highdphi_nb1->GetBinContent(2,2),2) + pow(R_highdphi_nb1->GetBinError(1,2)/R_highdphi_nb1->GetBinContent(1,2),2),0.5);}
    if(i==29 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>29 && i<34) {tf_51[i]=tf_51[29]*R_highdphi_nb1->GetBinContent(2,3)/R_highdphi_nb1->GetBinContent(1,3); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[29]/tf_51[29],2)+pow(R_highdphi_nb1->GetBinError(2,3)/R_highdphi_nb1->GetBinContent(2,3),2) + pow(R_highdphi_nb1->GetBinError(1,3)/R_highdphi_nb1->GetBinContent(1,3),2),0.5);}
    if(i==34 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>34 && i<40) {tf_51[i]=tf_51[34]*R_highdphi_Wtag->GetBinContent(2)/R_highdphi_Wtag->GetBinContent(1); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[34]/tf_51[34],2)+pow(R_highdphi_Wtag->GetBinError(2)/R_highdphi_Wtag->GetBinContent(2),2) + pow(R_highdphi_Wtag->GetBinError(1)/R_highdphi_Wtag->GetBinContent(1),2),0.5);}
    if(i==40 ) {tf_51[i]=fake->GetBinContent(i+1); tf_err[i]=fake->GetBinError(i+1);}
    if(i>40 && i<46) {tf_51[i]=tf_51[40]*R_highdphi_Htag->GetBinContent(2)/R_highdphi_Htag->GetBinContent(1); tf_err[i]=abs(tf_51[i])*pow(pow(tf_err[40]/tf_51[40],2)+pow(R_highdphi_Htag->GetBinError(2)/R_highdphi_Htag->GetBinContent(2),2) + pow(R_highdphi_Htag->GetBinError(1)/R_highdphi_Htag->GetBinContent(1),2),0.5);}
    fr->Fill(i,tf_51[i]);                                                                                                                                              
    fr->SetBinContent(i+1,tf_51[i]);
    fr->SetBinError(i+1,tf_err[i]);                      
    //    cout<<fr->GetBinContent(i)<<endl;
    fr1->SetBinContent(i+1,1);
    fr1->SetBinError(i+1,0);

  }


  //  TFile *data = TFile::Open("../multijet/rootoutput/btagSF/Run2_METdata_CR_v18.root","READ");
  //TH1D *cr=(TH1D*)data->FindObjectAny("AllSBins_v6_CD_EW_50bin_AB");

  for(int i=1;i<=46;i++)
    {
      //      cout<<i<<" : "<<tf_51[i]<<" +- "<<tf_err[i]<<" : "<<fr->GetBinContent(i)<<" +- "<<fr->GetBinError(i)<<endl;
      if(AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i)>0){
	AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinContent(i,fr->GetBinContent(i)*AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i));
	if(!syst) AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)*fr->GetBinContent(i),2) + pow(fr->GetBinError(i)*AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2),0.5));

	else
	  AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(i)*pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)/AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2) + pow(fr->GetBinError(i)/fr->GetBinContent(i),2) + pow(syserror->GetBinContent(i),2),0.5));
	//	AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)*fr->GetBinContent(i),2) + pow(fr->GetBinError(i)*AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2) + pow(syserror->GetBinContent(i),2),0.5));
      }
      else{
	//	cout<<i<<" , cr before : "<<cr->GetBinContent(i)<<endl;
	//	cr->SetBinContent(i,0.00000000000001);
	//	cout<<"cr after : "<<cr->GetBinContent(i)<<endl;
	//	AllSBins_v6_CD_EW_50bin_elec1->SetBinContent(i,0.00000000000001);
	//AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinContent(i,0.00000000000001);
	//	AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)*fr->GetBinContent(i),2) + pow(fr->GetBinError(i)*AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2) + pow(syserror->GetBinContent(i),2),0.5));
	//        AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(i)*pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)/AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2) + pow(fr->GetBinError(i)/fr->GetBinContent(i),2)+pow(syserror->GetBinContent(i+1),2),0.5));
	//        AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(i)*pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)/AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2) + pow(fr->GetBinError(i)/fr->GetBinContent(i),2)+pow(syserror->GetBinContent(i+1),2),0.5));

	AllSBins_v6_CD_EW_50bin_elec1_closure->SetBinError(i,pow(pow(AllSBins_v6_CD_EW_50bin_elec1->GetBinError(i)*fr->GetBinContent(i),2) + pow(fr->GetBinError(i)*AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i),2),0.5));
        

      }

      //  if(cr->GetBinContent(i)==0) cr->SetBinContent(i,0.00000000000001);  
    }

  
  cout<<"(RxK) : "<<endl;
  for(int i=1;i<=46;i++)
    {
      //      cout<<fr->GetBinContent(i)<<" +- "<<fr->GetBinError(i)<<endl;//"+-"<<fr->GetBinError(i+1)<<endl;//<<" : "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(i)<<" +- "<< AllSBins_v6_CD_EW_50bin_elec1->GetBinEr
      //     cout<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(i)<<endl;
      //      cout<<fr->GetBinContent(i)<<endl;
      cout<<fr->GetBinError(i)<<endl;      
    }

  cout<<"Pred."<<endl;
  for(int i=1;i<=46;i++)
    cout<<cr->GetBinContent(i)<<endl; 
  //cout<<1<<" & "<<setprecision(4)<<sr->GetBinContent(2)<<" & "<<cr4->GetBinContent(2)<<" $\pm$ "<<cr4->GetBinError(2)<<" & "<<h_SRmc->GetBinContent(2)<<" $\pm$ "<<h_SRmc->GetBinError(2)<<" & "<<h_preddata->GetBinContent(2)<<" $\pm$ "<<h_preddata->GetBinError(2)<<" \\"<<endl;
  cout<<"Pred."<<endl;
  for(int i=1;i<=46;i++)
    {

      if(fake_lowdphi->GetBinContent(i+1)<=0) {fake_lowdphi->SetBinContent(i+1,0.00000000000001);fake_lowdphi->SetBinContent(i+1,0.00000000000001);}
      cout<<i<<" & "<<setprecision(4)<<cr->GetBinContent(i+1)<<" & "<<ewk_low->GetBinContent(i+1)<<" $\\pm$ "<<ewk_low->GetBinError(i+1)<<" & "<<fake_lowdphi->GetBinContent(i+1)<<" $\\pm$ "<<fake_lowdphi->GetBinError(i+1)<<" & "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(i+1)<<" $\\pm$ "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(i+1)<<" \\"<<endl;

    }
  cout<<endl;
  cout<<"RxK table"<<endl;
  cout<<"& 0 & 2-4 & "<<fr->GetBinContent(2)<<" $\\pm$ "<<fr->GetBinError(2)<<" & "<<R_highdphi_nb0->GetBinContent(2,1)/R_highdphi_nb0->GetBinContent(1,1)<<" $\\pm$ "<<R_highdphi_nb0->GetBinContent(2,1)/R_highdphi_nb0->GetBinContent(1,1)*pow(pow(R_highdphi_nb0->GetBinError(1,1)/R_highdphi_nb0->GetBinContent(1,1),2) + pow(R_highdphi_nb0->GetBinError(2,1)/R_highdphi_nb0->GetBinContent(2,1),2),0.5)<<" & "<<fr->GetBinContent(3)<<" $\\pm$ "<<fr->GetBinError(3)<<"  \\"<<endl;
  cout<<"& 0 & 5-6 & "<<fr->GetBinContent(9)<<" $\\pm$ "<<fr->GetBinError(9)<<" & "<<R_highdphi_nb0->GetBinContent(2,2)/R_highdphi_nb0->GetBinContent(1,2)<<" $\\pm$ "<<R_highdphi_nb0->GetBinContent(2,2)/R_highdphi_nb0->GetBinContent(1,2)*pow(pow(R_highdphi_nb0->GetBinError(1,2)/R_highdphi_nb0->GetBinContent(1,2),2) + pow(R_highdphi_nb0->GetBinError(2,2)/R_highdphi_nb0->GetBinContent(2,2),2),0.5)<<" & "<<fr->GetBinContent(10)<<" $\\pm$ "<<fr->GetBinError(10)<<"  \\"<<endl;
  cout<<"& 0 & $\\geq$7 & "<<fr->GetBinContent(15)<<" $\\pm$ "<<fr->GetBinError(15)<<" & "<<R_highdphi_nb0->GetBinContent(2,3)/R_highdphi_nb0->GetBinContent(1,3)<<" $\\pm$ "<<R_highdphi_nb0->GetBinContent(2,3)/R_highdphi_nb0->GetBinContent(1,3)*pow(pow(R_highdphi_nb0->GetBinError(1,3)/R_highdphi_nb0->GetBinContent(1,3),2) + pow(R_highdphi_nb0->GetBinError(2,2)/R_highdphi_nb0->GetBinContent(2,2),2),0.5)<<" & "<<fr->GetBinContent(16)<<" $\\pm$ "<<fr->GetBinError(16)<<"  \\"<<endl;
  cout<<"& $\\geq$0 & 2-4 & "<<fr->GetBinContent(20)<<" $\\pm$ "<<fr->GetBinError(20)<<" & "<<R_highdphi_nb1->GetBinContent(2,1)/R_highdphi_nb1->GetBinContent(1,1)<<" $\\pm$ "<<R_highdphi_nb1->GetBinContent(2,1)/R_highdphi_nb1->GetBinContent(1,1)*pow(pow(R_highdphi_nb1->GetBinError(1,1)/R_highdphi_nb1->GetBinContent(1,1),2) + pow(R_highdphi_nb1->GetBinError(2,1)/R_highdphi_nb1->GetBinContent(2,1),2),0.5)<<" & "<<fr->GetBinContent(21)<<" $\\pm$ "<<fr->GetBinError(21)<<"  \\"<<endl;
  cout<<"& $\\geq$0 & 5-6 & "<<fr->GetBinContent(25)<<" $\\pm$ "<<fr->GetBinError(25)<<" & "<<R_highdphi_nb1->GetBinContent(2,2)/R_highdphi_nb1->GetBinContent(1,2)<<" $\\pm$ "<<R_highdphi_nb1->GetBinContent(2,2)/R_highdphi_nb1->GetBinContent(1,2)*pow(pow(R_highdphi_nb1->GetBinError(1,2)/R_highdphi_nb1->GetBinContent(1,2),2) + pow(R_highdphi_nb1->GetBinError(2,2)/R_highdphi_nb1->GetBinContent(2,2),2),0.5)<<" & "<<fr->GetBinContent(26)<<" $\\pm$ "<<fr->GetBinError(26)<<"  \\"<<endl;
  cout<<"& $\\geq$0 & $\\geq$7 & "<<fr->GetBinContent(30)<<" $\\pm$ "<<fr->GetBinError(30)<<" & "<<R_highdphi_nb1->GetBinContent(2,3)/R_highdphi_nb1->GetBinContent(1,3)<<" $\\pm$ "<<R_highdphi_nb1->GetBinContent(2,3)/R_highdphi_nb1->GetBinContent(1,3)*pow(pow(R_highdphi_nb1->GetBinError(1,3)/R_highdphi_nb1->GetBinContent(1,3),2) + pow(R_highdphi_nb1->GetBinError(2,2)/R_highdphi_nb1->GetBinContent(2,2),2),0.5)<<" & "<<fr->GetBinContent(31)<<" $\\pm$ "<<fr->GetBinError(31)<<"  \\"<<endl;
  cout<<"& \multicolumn{2}{c}{\Wtag} & "<<fr->GetBinContent(35)<<" $\\pm$ "<<fr->GetBinError(35)<<" & "<<R_highdphi_Wtag->GetBinContent(2)/R_highdphi_Wtag->GetBinContent(1)<<" $\\pm "<<(R_highdphi_Wtag->GetBinContent(2)/R_highdphi_Wtag->GetBinContent(1))*pow(pow(R_highdphi_Wtag->GetBinError(2)/R_highdphi_Wtag->GetBinContent(2),2) + pow(R_highdphi_Wtag->GetBinError(1)/R_highdphi_Wtag->GetBinContent(1),2),0.5)<<" & "<<fr->GetBinContent(36)<<" $\\pm$ "<<fr->GetBinError(36)<<"  \\"<<endl;
  cout<<"& \multicolumn{2}{c}{\Htag} & "<<fr->GetBinContent(41)<<" $\\pm$ "<<fr->GetBinError(41)<<" & "<<R_highdphi_Htag->GetBinContent(2)/R_highdphi_Htag->GetBinContent(1)<<" $\\pm "<<(R_highdphi_Htag->GetBinContent(2)/R_highdphi_Htag->GetBinContent(1))*pow(pow(R_highdphi_Htag->GetBinError(2)/R_highdphi_Htag->GetBinContent(2),2) + pow(R_highdphi_Htag->GetBinError(1)/R_highdphi_Htag->GetBinContent(1),2),0.5)<<" & "<<fr->GetBinContent(46)<<" $\\pm$ "<<fr->GetBinError(46)<<"  \\"<<endl;

  
  fr->Write();                                                                                                                                                             
  fr1->Write();
  cr->Write();
  AllSBins_v6_CD_EW_50bin_elec1->Write();
  AllSBins_v6_CD_EW_50bin_elec1_closure->Write();
  syserror->Write("syserr");
  h_MET->Write("MET");
  h_nJets->Write("nJets");
  h_ST->Write("ST");
  h_BTags->Write("nBTags");
  h_BestPhotonPt->Write("BestPhotonPt");



  //  h_hadAk8Mass->Write();

  if(R_data)
    {
      
      pdf="pdf/Multi_R_data.pdf";
      png="png/Multi_R_data.png";

        TLatex textOnTop,intLumiE;
      TCanvas *c1= new TCanvas("stackhist","stackhist",800,600); 
      c1->cd();
      gStyle->SetOptStat(0);

      TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
      pad1->SetBottomMargin(0);
      pad1->SetBottomMargin(0.3);
      pad1->Draw();
      pad1->SetGridx();
      pad1->SetGridy(0);
      pad1->cd();
      pad1->SetLogy();
      TH1D *C_data = new TH1D("C_data"," C : low MET for Data ",8,1,9);
      TH1D *A_data = new TH1D("A_data"," A : low MET for Data ",8,1,9);
      TH1D *RlowMET_data = new TH1D("RlowMET_data"," R : low MET for Data ",8,1,9);
      int bin[8]={2,9,15,20,25,30,35,41};
      int j=0;
      for(int i=0;i<8;i++)
	{
	  C_data->SetBinContent(i+1,SR->GetBinContent(bin[j]));
          A_data->SetBinContent(i+1,CR->GetBinContent(bin[j]));
	  RlowMET_data->SetBinContent(i+1,fr->GetBinContent(bin[j]));
          C_data->SetBinError(i+1,SR->GetBinError(bin[j]));
          A_data->SetBinError(i+1,CR->GetBinError(bin[j]));
          RlowMET_data->SetBinError(i+1,fr->GetBinError(bin[j]));
	  j++;
	}
      //      RlowMET_data->Draw();

      C_data->GetYaxis()->SetRangeUser(0.5,2500000);
      C_data->SetLineColor(kBlue);
      A_data->SetLineColor(kRed);
      C_data->SetTitle(0);
      C_data->GetYaxis()->SetTitle("Events / Bin");
      C_data->Draw();
      A_data->Draw("sames");
      C_data->GetXaxis()->SetTickLength(0);
      TF1 *f2_=new TF1("f2_","x",1.5,9.5);
      TGaxis *A2 = new TGaxis(1,0.5,9,0.5,"f2_",8,"US");
      A2->SetTickSize(0.02);
      A2->Draw("B");

      double yset=5000;
      cout<<"yset = "<<yset<<endl;
      TLine *line1V6=new TLine( 1,0,  1,yset*4.5);
      TLine *line2V6=new TLine( 2,0,  2,yset*4.5);
      TLine *line3V6=new TLine( 3,0,  3,yset*4.5);
      TLine *line4V6=new TLine( 4,0,  4,yset*4.5);
      TLine *line5V6=new TLine( 5,0,  5,yset*4.5);
      TLine *line6V6=new TLine( 6,0,  6,yset*4.5);
      TLine *line7V6=new TLine( 7,0,  7,yset*4.5);
      TLine *line8V6=new TLine( 8,0,  8,yset*4.5);
      
      pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
      line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
      line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
      line7V6->Draw(); line8V6->Draw();

      TArrow *arrow1 = new TArrow( 1, yset, 2, yset,0.01,"<|>");
      TArrow *arrow2 = new TArrow( 2, yset, 3, yset,0.01,"<|>");
      TArrow *arrow3 = new TArrow( 3, yset, 4, yset,0.01,"<|>");
      TArrow *arrow4 = new TArrow( 4, yset, 5, yset,0.01,"<|>");
      TArrow *arrow5 = new TArrow( 5, yset, 6, yset,0.01,"<|>");
      TArrow *arrow6 = new TArrow( 6,yset, 7,yset,0.01,"<|>");
      TArrow *arrow7 = new TArrow( 7,yset, 8,yset,0.01,"<|>");
      TArrow *arrow8 = new TArrow( 8,yset, 9,yset,0.01,"<|>");
      TArrow *arrow11 = new TArrow( 1,4.5*yset, 7,4.5*yset,0.01,"<|>");
      TArrow *arrow12 = new TArrow( 7,4.5*yset, 9,4.5*yset,0.01,"<|>");

      arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
      arrow4->Draw();
      arrow5->Draw(); arrow6->Draw();
      arrow7->Draw(); arrow8->Draw();
      //      arrow11->Draw(); arrow12->Draw();

      yset=6000;
      cout<<"yset = "<<yset<<endl;

      TLatex Tl,T2;
      Tl.SetTextSize(0.04);
      T2.SetTextSize(0.04);
      Tl.DrawLatex(1.25,1.3*yset,"N^{ 0}_{ 2-4}");
      Tl.DrawLatex(2.25,1.3*yset,"N^{ 0}_{ 5-6}");
      Tl.DrawLatex(3.25,1.3*yset,"N^{ 0}_{ #geq7}");
      Tl.DrawLatex(4.25,1.3*yset,"N^{ #geq1}_{ 2-4}");
      Tl.DrawLatex(5.25,1.3*yset,"N^{ #geq1}_{ 5-6}");
      Tl.DrawLatex(6.25,1.3*yset,"N^{ #geq1}_{ #geq7}");
      Tl.DrawLatex(7.25,1.3*yset,"V tag");
      Tl.DrawLatex(8.25,1.3*yset,"H tag");
      //      T2.DrawLatex(2.5,6*yset,"SP region");
      //      T2.DrawLatex(7.5,6*yset,"EW region");
      TLegend *legend1 = new TLegend(0.45,0.75,0.89,0.89);
      legend1->AddEntry(C_data,"N_{C} (high-#Delta#phi & low-p_{T}^{miss})","lpe");
      legend1->AddEntry(A_data,"N_{A} (low-#Delta#phi & low-p_{T}^{miss}) ","lpe");
      legend1->SetTextSize(0.04);
      legend1->SetBorderSize(0);
      legend1->Draw();
      textOnTop.SetTextSize(0.04);
      intLumiE.SetTextSize(0.04);
      //      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");
      textOnTop.DrawLatexNDC(0.1,0.915,"CMS #it{#bf{Supplementary}}");
      intLumiE.DrawLatexNDC(0.73,0.92,"#bf{137 fb^{-1} (13 TeV)}");

      TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.3);
      pad2->Draw();
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.3);
      pad2->cd();
      //      pad2->SetGrid(0);                                                                                                                                             
      pad2->SetGridx();
      pad2->SetGridy(0);
      RlowMET_data->SetTitle(0);
      RlowMET_data->SetMaximum(1.45);
      RlowMET_data->SetMinimum(0);
      RlowMET_data->GetXaxis()->SetTitle("Bin index");
      RlowMET_data->GetXaxis()->SetTitleOffset(0.99);
      RlowMET_data->GetXaxis()->SetTitleSize(0.13);
      RlowMET_data->GetXaxis()->SetLabelSize(0.12);
      RlowMET_data->GetYaxis()->SetTitle("R = N_{C}/N_{A}");
      RlowMET_data->GetYaxis()->SetTitleSize(0.13);
      RlowMET_data->GetYaxis()->SetTitleOffset(0.28);
      RlowMET_data->GetYaxis()->SetLabelSize(0.1);
      RlowMET_data->SetLineColor(kBlack);
      RlowMET_data->SetLineWidth(2);
      RlowMET_data->SetMarkerColor(kBlack);
      RlowMET_data->SetMarkerSize(1.0);
      RlowMET_data->SetMarkerStyle(20);

      RlowMET_data->GetYaxis()->SetNdivisions(5);
      RlowMET_data->Draw("E0");
      RlowMET_data->GetXaxis()->SetTickLength(0);

      TGaxis *A2_ = new TGaxis(1,0.01,9,0.01,"f2_",8,"US");
      A2_->SetTickSize(0.04);
      A2_->Draw("B");
      TString temp2;
      for(int i=1;i<=RlowMET_data->GetNbinsX();i++){
        temp2 = to_string(i);
        RlowMET_data->GetXaxis()->SetBinLabel(i,temp2);
      }
      RlowMET_data->GetXaxis()->SetLabelSize(0.20);
      RlowMET_data->GetXaxis()->SetLabelOffset(0.01);
      RlowMET_data->GetXaxis()->SetTickLength(0.05);

      
      TLine *line1V7=new TLine( 1,0,  1,2);
      TLine *line2V7=new TLine( 2,0,  2,2);
      TLine *line3V7=new TLine( 3,0,  3,2);
      TLine *line4V7=new TLine( 4,0,  4,2);
      TLine *line5V7=new TLine( 5,0,  5,2);
      TLine *line6V7=new TLine( 6,0,  6,2);
      TLine *line7V7=new TLine( 7,0,  7,2);
      TLine *line8V7=new TLine( 8,0,  8,2);

      pad2->cd(); pad2->SetGridx(0); //pad2->SetGridy(0);                                                                                                                 
      line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
      line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
      line7V7->Draw(); line8V7->Draw();

      TLine *line=new TLine( 1,0.5,9,0.5);
      line->SetLineColor(1);
      line->SetLineWidth(2);
      //      line->Draw();

      c1->SaveAs(png);
      c1->SetCanvasSize(1600,1000);
      c1->SaveAs(pdf);


    }
    if(RK)
    {
      TFile *f2=new TFile("rootoutput/K_MC_1pho_wt1.root","recreate");      
      f2->cd();
      pdf="pdf/Multi_K.pdf";
      png="png/Multi_K.png";
        TLatex textOnTop,intLumiE;
      TCanvas *c1= new TCanvas("stackhist","stackhist",1600,1000); 
      c1->cd();
      gStyle->SetOptStat(0);

      TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
      pad1->SetBottomMargin(0);
      pad1->SetBottomMargin(0.3);

      pad1->Draw();
      pad1->SetGridx(0);
      pad1->SetGridy(0);
      pad1->cd();
      //      pad1->SetLogy();
      TH1D *C_MC = new TH1D("C_MC"," R (low MET) = C/A ",8,1,9);
      TH1D *D_MC = new TH1D("D_MC"," R (high MET) = D/B ",8,1,9);

      TH1D *RlowMET_data = new TH1D("RlowMET_data"," R : low MET for Data ",8,1,9);

      C_MC->SetBinContent(1,R_highdphi_nb0->GetBinContent(1,1));
      C_MC->SetBinContent(2,R_highdphi_nb0->GetBinContent(1,2));
      C_MC->SetBinContent(3,R_highdphi_nb0->GetBinContent(1,3));
      C_MC->SetBinContent(4,R_highdphi_nb1->GetBinContent(1,1));
      C_MC->SetBinContent(5,R_highdphi_nb1->GetBinContent(1,2));
      C_MC->SetBinContent(6,R_highdphi_nb1->GetBinContent(1,3));
      C_MC->SetBinContent(7,R_highdphi_Wtag->GetBinContent(1));
      C_MC->SetBinContent(8,R_highdphi_Htag->GetBinContent(1));

      
      D_MC->SetBinContent(1,R_highdphi_nb0->GetBinContent(2,1));
      D_MC->SetBinContent(2,R_highdphi_nb0->GetBinContent(2,2));
      D_MC->SetBinContent(3,R_highdphi_nb0->GetBinContent(2,3));
      D_MC->SetBinContent(4,R_highdphi_nb1->GetBinContent(2,1));
      D_MC->SetBinContent(5,R_highdphi_nb1->GetBinContent(2,2));
      D_MC->SetBinContent(6,R_highdphi_nb1->GetBinContent(2,3));
      D_MC->SetBinContent(7,R_highdphi_Wtag->GetBinContent(2));
      D_MC->SetBinContent(8,R_highdphi_Htag->GetBinContent(2));

      C_MC->SetBinError(1,R_highdphi_nb0->GetBinError(1,1));
      C_MC->SetBinError(2,R_highdphi_nb0->GetBinError(1,2));
      C_MC->SetBinError(3,R_highdphi_nb0->GetBinError(1,3));
      C_MC->SetBinError(4,R_highdphi_nb1->GetBinError(1,1));
      C_MC->SetBinError(5,R_highdphi_nb1->GetBinError(1,2));
      C_MC->SetBinError(6,R_highdphi_nb1->GetBinError(1,3));
      C_MC->SetBinError(7,R_highdphi_Wtag->GetBinError(1));
      C_MC->SetBinError(8,R_highdphi_Htag->GetBinError(1));


      D_MC->SetBinError(1,R_highdphi_nb0->GetBinError(2,1));
      D_MC->SetBinError(2,R_highdphi_nb0->GetBinError(2,2));
      D_MC->SetBinError(3,R_highdphi_nb0->GetBinError(2,3));
      D_MC->SetBinError(4,R_highdphi_nb1->GetBinError(2,1));
      D_MC->SetBinError(5,R_highdphi_nb1->GetBinError(2,2));
      D_MC->SetBinError(6,R_highdphi_nb1->GetBinError(2,3));
      D_MC->SetBinError(7,R_highdphi_Wtag->GetBinError(2));
      D_MC->SetBinError(8,R_highdphi_Htag->GetBinError(2));

      D_MC->GetYaxis()->SetRangeUser(-0.19,1.9);
      D_MC->SetLineColor(kBlue);
      C_MC->SetLineColor(kRed);
      D_MC->SetTitle(0);
      D_MC->GetYaxis()->SetTitle("R^{ MC}");
      D_MC->SetMarkerSize(0.8);
      D_MC->Draw("ep");
      C_MC->Draw("ep sames");
      
      D_MC->GetXaxis()->SetTickLength(0);
      TF1 *f2_=new TF1("f2_","x",1.5,9.5);
      TGaxis *A2 = new TGaxis(1,-0.19,9,-0.19,"f2_",8,"US");
      A2->SetTickSize(0.02);
      A2->Draw("B");

      double yset=1.0;
      cout<<"yset = "<<yset<<endl;
      TLine *line2V6=new TLine( 2,-0.19,  2,1.1*yset);
      TLine *line3V6=new TLine( 3,-0.19,  3,1.1*yset);
      TLine *line4V6=new TLine( 4,-0.19,  4,1.1*yset);
      TLine *line5V6=new TLine( 5,-0.19,  5,1.1*yset);
      TLine *line6V6=new TLine( 6,-0.19,  6,1.1*yset);
      TLine *line7V6=new TLine( 7,-0.19,  7,1.1*yset);
      TLine *line8V6=new TLine( 8,-0.19,  8,1.1*yset);
      
      line2V6->Draw();  line3V6->Draw();
      line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
      line7V6->Draw(); line8V6->Draw();
      TArrow *arrow1 = new TArrow( 1, yset, 2, yset,0.01,"<|>");
      TArrow *arrow2 = new TArrow( 2, yset, 3, yset,0.01,"<|>");
      TArrow *arrow3 = new TArrow( 3, yset, 4, yset,0.01,"<|>");
      TArrow *arrow4 = new TArrow( 4, yset, 5, yset,0.01,"<|>");
      TArrow *arrow5 = new TArrow( 5, yset, 6, yset,0.01,"<|>");
      TArrow *arrow6 = new TArrow( 6,yset, 7,yset,0.01,"<|>");
      TArrow *arrow7 = new TArrow( 7,yset, 8,yset,0.01,"<|>");
      TArrow *arrow8 = new TArrow( 8,yset, 9,yset,0.01,"<|>");
      TArrow *arrow11 = new TArrow( 1,1.3, 7,1.3,0.01,"<|>");
      TArrow *arrow12 = new TArrow( 7,1.3, 9,1.3,0.01,"<|>");

      arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
      arrow4->Draw();
      arrow5->Draw(); arrow6->Draw();
      arrow7->Draw(); arrow8->Draw();
      //      arrow11->Draw(); arrow12->Draw();

      yset=1.06;
      cout<<"yset = "<<yset<<endl;

      TLatex Tl,T2;
      Tl.SetTextSize(0.04);
      T2.SetTextSize(0.04);
      Tl.DrawLatex(1.25,yset,"N^{ 0}_{ 2-4}");
      Tl.DrawLatex(2.25,yset,"N^{ 0}_{ 5-6}");
      Tl.DrawLatex(3.25,yset,"N^{ 0}_{ #geq7}");
      Tl.DrawLatex(4.25,yset,"N^{ #geq1}_{ 2-4}");
      Tl.DrawLatex(5.25,yset,"N^{ #geq1}_{ 5-6}");
      Tl.DrawLatex(6.25,yset,"N^{ #geq1}_{ #geq7}");
      Tl.DrawLatex(7.25,yset,"V tag");
      Tl.DrawLatex(8.25,yset,"H tag");
      //      T2.DrawLatex(2.5,1.35,"SP region");
      //      T2.DrawLatex(7.5,1.35,"EW region");
      TLegend *legend1 = new TLegend(0.65,0.72,0.89,0.89);
      legend1->SetBorderSize(0);
      legend1->AddEntry(D_MC,"R_{ high-p_{T}^{miss}}","lpe");
      legend1->AddEntry(C_MC,"R_{ low-p_{T}^{miss}}","lpe");
      legend1->SetTextSize(0.045);
      legend1->Draw();
      textOnTop.SetTextSize(0.04);
      intLumiE.SetTextSize(0.04);
      textOnTop.DrawLatexNDC(0.1,0.915,"CMS #it{#bf{Simulation Supplementary}}");
      intLumiE.DrawLatexNDC(0.73,0.915,"#bf{137 fb^{-1} (13 TeV)}");

      RlowMET_data = (TH1D*)D_MC->Clone("RK");

      TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.3);
      pad2->Draw();
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.3);
      pad2->cd();
      //    pad2->SetGrid(0);                                                                                                                                             
      pad2->SetGridx(0);
      pad2->SetGridy(0);
      RlowMET_data->Divide(C_MC);
      RlowMET_data->SetTitle(0);
      RlowMET_data->SetMaximum(0.99);
      RlowMET_data->SetMinimum(0.01);
      RlowMET_data->SetLineColor(kBlack);
      RlowMET_data->SetLineWidth(2);
      RlowMET_data->SetMarkerColor(kBlack);
      RlowMET_data->SetMarkerSize(1.0);
      RlowMET_data->SetMarkerStyle(20);
      
      RlowMET_data->GetXaxis()->SetTitle("Bin index");
      RlowMET_data->GetXaxis()->SetTitleOffset(0.99);
      RlowMET_data->GetXaxis()->SetTitleSize(0.13);
      RlowMET_data->GetXaxis()->SetLabelSize(0.12);
      RlowMET_data->GetYaxis()->SetTitle("#kappa = #frac{R_{high p_{T}^{miss}}}{R_{low p_{T}^{miss}}}");
      RlowMET_data->GetYaxis()->SetTitleSize(0.1);
      RlowMET_data->GetYaxis()->SetTitleOffset(0.38);
      RlowMET_data->GetYaxis()->SetLabelSize(0.1);
      RlowMET_data->GetYaxis()->SetNdivisions(5);
      RlowMET_data->Draw("ep");
      RlowMET_data->GetXaxis()->SetTickLength(0);

      TGaxis *A2_ = new TGaxis(1,0.01,9,0.01,"f2_",8,"US");
      A2_->SetTickSize(0.04);
      A2_->Draw("B");
      TString temp2;
      for(int i=1;i<=RlowMET_data->GetNbinsX();i++){
	temp2 = to_string(i);
	RlowMET_data->GetXaxis()->SetBinLabel(i,temp2);
      }
      RlowMET_data->GetXaxis()->SetLabelSize(0.20);
      RlowMET_data->GetXaxis()->SetLabelOffset(0.01);
      RlowMET_data->GetXaxis()->SetTickLength(0.05);


      TLine *line2V7=new TLine( 2,0.01,  2,0.99);
      TLine *line3V7=new TLine( 3,0.01,  3,0.99);
      TLine *line4V7=new TLine( 4,0.01,  4,0.99);
      TLine *line5V7=new TLine( 5,0.01,  5,0.99);
      TLine *line6V7=new TLine( 6,0.01,  6,0.99);
      TLine *line7V7=new TLine( 7,0.01,  7,0.99);
      TLine *line8V7=new TLine( 8,0.01,  8,0.99);
	
      line2V7->Draw();  line3V7->Draw();
      line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
      line7V7->Draw(); line8V7->Draw();

      c1->SaveAs(png);
      c1->SetCanvasSize(1600,1000);
      c1->SaveAs(pdf);


      RlowMET_data->Write("K_MC");      
    }
  /*  
  cout<<"error =>"<<endl;
  for(int i=1;i<46;i++)                                                                                                                                                        
  cout<<tf_err[i]<<endl;
  */
}
 
  
 
