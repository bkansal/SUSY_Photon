#include<iostream>
#include<iomanip>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TTree.h"
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

//vector<int> col={kGray,kTeal+9,kRed,kCyan-1,kBlack};
vector<int> col={kGray,kTeal+9,kOrange,kCyan-1,kRed,kBlack};

void decorate(TH1D*,int,const char*);
void plotdatavsMC_LL(TString varName="AllSBins_v6_CD_EW_50bin_elec1", TString year="full_Run2", TString ntuple="v18", bool DatavsMC=true)
{
  TFile *f1, *f2,*f3,*f4;
  TFile *f_0,*f_1,*f_2,*f_3,*f_4;

  TLatex textOnTop,intLumiE;
  bool isPaper=false, AN=true, progress=false;
  TLegend *legend1 = new TLegend(0.1,0.82,0.4,0.9);
  legend1->SetHeader(year,"C");                               // option "C" allows to center the header                                        
  legend1->SetTextSize(0.08);
  TString lep="LL";
  TString path;
  //  DatavsMC=false;
  if(ntuple=="v18")
    {
      path="../lostlepton/rootoutput/new/nominal/LL/";
      path="rootoutput/LL_TF/LL/";
    }
  TString filename;
  if(ntuple=="v18"){  
    if(year=="full_Run2"){
      filename=path+"Run2_METdata_CR_v18.root";
      f2 = new TFile(filename);
      filename=path+"TTWGJ_CR_v18.root";
      f1 = new TFile(filename);
      filename=path+"TTGJets_CR_v18.root";
      f_0 = new TFile(filename);
      filename=path+"TTST_CR_v18.root";
      f_1 = new TFile(filename);
      filename=path+"WJets_CR_v18.root";
      f_2 = new TFile(filename);
      filename=path+"WGJets_CR_v18.root";
      f_3 = new TFile(filename);
      filename=path+"ST_CR_v18.root";
      f_4 = new TFile(filename);

    }
    
    else
      {
	filename=path+"Run"+year+"_METdata_CR_v18.root";
	f2 = new TFile(filename);
	filename=path+"TTWGJ_"+year+"_CR_v18.root";
	f1 = new TFile(filename);
	filename=path+"TTGJets_"+year+"_CR_v18.root";
	f_0 = new TFile(filename);
	filename=path+"TTJets_"+year+"_CR_v18.root";
	f_1 = new TFile(filename);
	filename=path+"WJets_"+year+"_CR_v18.root";
	f_2 = new TFile(filename);
	filename=path+"WGJets_"+year+"_CR_v18.root";
	f_3 = new TFile(filename);
        filename=path+"ST_"+year+"_CR_v18.root";
	f_4 = new TFile(filename);

      }
  }

  else{  
    if(year=="full_Run2"){
      filename=path+"Run2_METdata_CR.root";
      f2 = new TFile(filename);
      filename=path+"TTWGJ_CR.root";
      f1 = new TFile(filename);
      filename=path+"TTGJets_CR.root";
      f_0 = new TFile(filename);
      filename=path+"TTJets_CR.root";
      f_1 = new TFile(filename);
      filename=path+"WJets_CR.root";
      f_2 = new TFile(filename);
      filename=path+"WGJets_CR.root";
      f_3 = new TFile(filename);
      filename=path+"ST_CR_v18.root";
      f_4 = new TFile(filename);
    }
    
    else
      {
	filename=path+"Run"+year+"_METdata_CR.root";
	f2 = new TFile(filename);
	filename=path+"TTWGJ_"+year+"_CR.root";
	f1 = new TFile(filename);
	filename=path+"TTGJets_"+year+"_CR.root";
	f_0 = new TFile(filename);
	filename=path+"TTJets_"+year+"_CR.root";
	f_1 = new TFile(filename);
	filename=path+"WJets_"+year+"_CR.root";
	f_2 = new TFile(filename);
	filename=path+"WGJets_"+year+"_CR.root";
	f_3 = new TFile(filename);
	filename=path+"ST_CR_v18.root";
	f_4 = new TFile(filename);
      }
  }

  
  TString pdf;
  TString png;
  if(DatavsMC)
    {
      png="png/LL_"+varName+"_"+year+"_datavsMC.png";
      pdf="pdf/LL_"+varName+"_"+year+"_datavsMC.pdf";
    }
  if(!DatavsMC)
    {      png="../plots/png/LL/LL_"+varName+"_"+year+"_ExpvsPred.png";
      pdf="../plots/pdf/LL/LL_"+varName+"_"+year+"_ExpvsPred.pdf";
 
    }

  
  TCanvas *c1 ;
  
  double xmin,xmax,bin,xmin_,xmax_,ymax2_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000;

  TH1D *cr,*sr,*tf,*pred_sr, *h_0,*h_1,*h_2,*h_3,*h_4;
  THStack *hs_var=new THStack("var_Stack",varName);


  
  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  TLegend *legend2;
  TString varName1=varName;
  if(varName=="AllSBins_v6_CD_elec1"){
      c1= new TCanvas("stackhist","stackhist",1000,1000);

    //cr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);

    legend2=new TLegend(0.1,0.57,0.4,0.9);
    legend2->SetNColumns(3);
    legend2->SetBorderSize(0);
    bin=51.5;
    xmin_=1,xmax_=8,xmin=1,xmax = 9,bin=8;
   ymin=0.5 , ymax=1.5, ymin_=0.1 , ymax_=1000;

  }  
 else if(varName=="AllSBins_v6_CD_EW_50bin_elec1"){
  c1= new TCanvas("stackhist","stackhist",1600,900);
    cr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");
    if(DatavsMC)
      {
	sr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");
	pred_sr     = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec1");
	h_0=(TH1D*)f_0->FindObjectAny(varName);
	h_1=(TH1D*)f_1->FindObjectAny(varName);
	h_2=(TH1D*)f_2->FindObjectAny(varName);
	h_3=(TH1D*)f_3->FindObjectAny(varName);
	h_4=(TH1D*)f_4->FindObjectAny(varName);
      }
    if(!DatavsMC)
      {
        pred_sr          = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
        sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec0");
        h_0=(TH1D*)f_0->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec0");
        h_1=(TH1D*)f_1->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec0");
        h_2=(TH1D*)f_2->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec0");
        h_3=(TH1D*)f_3->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec0");
        h_4=(TH1D*)f_4->FindObjectAny("AllSBins_v6_CD_EW_50bin_elec0");
      }
    legend2=new TLegend(0.1,0.78,0.45,0.9);
    legend2->SetNColumns(3);
    //    bin=51.5;
    //   xmin=-1,xmax = 50,xmin_=0,xmax_=51;

    xmin=1,xmax = 46,xmin_=1,xmax_=46;

    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=100000,ymax2_=1000, yset_=200;

    
 }
 else if( varName=="ST" || varName=="ST_SP" || varName=="ST_EW")
    {
      c1= new TCanvas("stackhist","stackhist",1000,600);

      cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    rebin=5;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.47,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }

 else if(varName=="BestPhotonPt" ||varName=="BestPhotonPt_vBin" ||varName=="MET" || varName=="MET_EW" || varName=="MET_SP" || varName=="mTPhoMET" || varName=="mTPhoMET_elec0" || varName=="mTlepMET" || varName=="mTlepMET_elec0")
   {
       c1= new TCanvas("stackhist","stackhist",1400,1400);

    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);

    xmin_=0,xmax_=1200,xmin=0,xmax=1200;
    h_0->SetLabelSize(1000);
    h_1->SetLabelSize(1000);
    h_2->SetLabelSize(1000);
    h_3->SetLabelSize(1000);

    if(varName=="BestPhotonPt")    {rebin=10; xmin=100, xmax=1000; xmin_=100, xmax_=1000; varName1="p_{T}^{ #gamma} (GeV)";}
    else if (varName=="BestPhotonPt_vBin") {rebin=1; xmin=100, xmax=700; xmin_=100, xmax_=700; varName1="p_{T}^{ #gamma} (GeV)";}
    else if (varName=="mTlepMET" || varName=="mTlepMET_elec0") rebin=1,xmin_=0,xmax_=200,xmin=0,xmax=200,varName1="mT(l,MET)";
    else { xmin_=200,xmax_=1500,xmin=200,xmax=1500,rebin=5, varName1="p_{T}^{ miss}";}
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.38,0.75,0.89,0.89);
    //    legend2=new TLegend(0.47,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    ymin=0.05, ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   }
 else if(varName == "ElectronPt" || varName == "leadElectronPt"){
   if(lep=="LE")
     varName1="Electron Pt (GeV)";
   else if(lep=="LM")
     varName1="Muon Pt (GeV)";
   else
     varName1="Lepton Pt (GeV)";
  c1= new TCanvas("stackhist","stackhist",1000,600);
   
   cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=30,xmax_=600,xmin=30,xmax=600;
    rebin=4;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.4,0.75,0.9,0.89);
    legend2->SetNColumns(3);


    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }

 else if(varName == "JetPt" || varName == "leadJetPt" || varName == "hadAk8jetPt")
   {
     if(varName == "hadAk8jetPt") varName1="p_{T}^{leading Ak8jet}";
    else varName1="Jet Pt (GeV)";
  c1= new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=0,xmax_=1600,xmin=0,xmax=1600;
    if(varName == "hadAk8jetPt")
      rebin=50;
    else
      rebin=10;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.47,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    pred_sr->GetXaxis()->SetTitle(varName);
    }
  

  
 else if(varName.Contains("hadAk8Mass"))
   {
     varName1="M_{leading Ak8jet} (GeV)";
  c1= new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=0,xmax_=300,xmin=0,xmax=300;

    rebin=25;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.4,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    pred_sr->GetXaxis()->SetTitle(varName);
    }

 else if(varName=="METvBin2" || varName =="METvBin_EW_v2" || varName =="METvBin_SP_v2")
    {
  c1= new TCanvas("stackhist","stackhist",1000,600);

      varName1="MET (GeV)";
     
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=250,xmax_=2000,xmin=250,xmax=2000;
    rebin=1;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    legend2=new TLegend(0.47,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }
 else if(varName == "ElectronEta" || varName == "JetEta" || varName == "BestPhotonEta" || varName == "leadElectronEta" || varName == "leadJetEta")
    {
  c1= new TCanvas("stackhist","stackhist",1000,600);
      varName1="Eta";
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    rebin=8;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    legend2=new TLegend(0.47,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    xmin_=-4,xmax_=4,xmin=-4,xmax=4;
    //   rebin=20;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }
 else if( varName == "ElectronPhi" || varName == "JetPhi" || varName == "BestPhotonPhi"|| varName == "leadElectronPhi" || varName == "leadJetPhi" || varName == "METPhi")
    {
      c1= new TCanvas("stackhist","stackhist",1000,600);
      if(varName == "ElectronPhi")    varName1="l(e/#mu) #phi";
      if(varName == "JetPhi") varName1="Jet #phi";
      if(varName == "BestPhotonPhi") varName1="#gamma #phi";
      if(varName == "leadElectronPhi")  varName1="lead l(e/#mu) #phi";
      if(varName == "leadJetPhi") varName1="lead Jet #phi";
      if(varName == "METPhi") varName1="MET #phi";

      cr          = (TH1D*)f1->Get(varName);
      sr          = (TH1D*)f1->Get(varName);
      pred_sr     = (TH1D*)f2->Get(varName);
      h_0=(TH1D*)f_0->FindObjectAny(varName);
      h_1=(TH1D*)f_1->FindObjectAny(varName);
      h_2=(TH1D*)f_2->FindObjectAny(varName);
      h_3=(TH1D*)f_3->FindObjectAny(varName);
      h_4=(TH1D*)f_4->FindObjectAny(varName);
      rebin=8;
      h_0->Rebin(rebin);
      h_1->Rebin(rebin);
      h_2->Rebin(rebin);
      h_3->Rebin(rebin);
      h_4->Rebin(rebin);
      legend2=new TLegend(0.47,0.75,0.9,0.85);
      legend2->SetNColumns(3);
      xmin_=-4,xmax_=4,xmin=-4,xmax=4;
    //   rebin=20;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }
 else if(varName=="nJets" || varName=="nJets_EW" ||varName=="nJets_SP")
    {
  c1= new TCanvas("stackhist","stackhist",1600,900);
     
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    rebin=1;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    legend2=new TLegend(0.38,0.75,0.89,0.89);
    legend2->SetNColumns(3);
    xmin_=2,xmax_=12,xmin=2,xmax=12;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    varName1="N_{ jets}";
    }
 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP"  )
    {
  c1= new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    xmin_=0,xmax_=6,xmin=0,xmax=6;

    rebin=1;
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    legend2=new TLegend(0.4,0.75,0.9,0.85);
    legend2->SetNColumns(3);

    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }
 else if(varName=="h_minDr_bestphoEle" || varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoEle_EW" || varName == "h_minDr_bestphoJets_EW" ||varName=="h_minDr_bestphoEle_SP" || varName == "h_minDr_bestphoJets_SP" || varName=="h_minDr_Elejet1" || varName=="h_minDr_Elejet2" || varName=="h_minDr_EleJets" || varName=="h_minDr_Elejet3" || varName=="h_minDr_Elejet4" || varName=="h_minDr_bestphoEMJets")
    {
    
      if(varName=="h_minDr_bestphoEle") varName1="min #DeltaR(#gamma,e)";

      c1= new TCanvas("stackhist","stackhist",1000,600);
      cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);
    rebin=10;
    legend2=new TLegend(0.4,0.75,0.9,0.85);
    legend2->SetNColumns(3);
    xmin_=0,xmax_=4.5,xmin=0,xmax=4.5;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    if(varName=="h_minDr_bestphoEMJets")
      {      rebin=rebin/rebin; xmin_=0,xmax_=0.5,xmin=0,xmax=0.5;}
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);

    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    }
 else if(varName=="dPhi_METjet1" || varName=="dPhi_METjet2" || varName=="dPhi_METjet3" || varName=="dPhi_METjet4" || varName=="dPhi_METlep" || varName=="dPhi_METlep1" || varName=="dPhi_phojet1" || varName=="dPhi_phojet2" || varName=="dPhi_phojet3" || varName=="dPhi_phojet4" || varName=="MET_CaloMET" || varName=="HT5HT" || varName=="dPhi_MET_CaloMET")
   {
  c1= new TCanvas("stackhist","stackhist",1000,600);
      cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName);
    pred_sr     = (TH1D*)f2->Get(varName);
    h_0=(TH1D*)f_0->FindObjectAny(varName);
    h_1=(TH1D*)f_1->FindObjectAny(varName);
    h_2=(TH1D*)f_2->FindObjectAny(varName);
    h_3=(TH1D*)f_3->FindObjectAny(varName);
    h_4=(TH1D*)f_4->FindObjectAny(varName);

    if(varName=="dPhi_METlep" || varName=="dPhi_phojet1") rebin=1;
    else rebin=2;
    legend2=new TLegend(0.47,0.75,0.89,0.89);  
    legend2->SetNColumns(3);

    xmin_=0,xmax_=4,xmin=0,xmax=4;
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;

    if(varName=="MET_CaloMET")    xmin_=0,xmax_=5,xmin=0,xmax=5, rebin=4;
    if(varName=="HT5HT")    xmin_=0,xmax_=3,xmin=0,xmax=3, rebin=1;
    if(varName=="dPhi_METjet1"|| varName=="dPhi_METjet2" || varName=="dPhi_METjet3" || varName=="dPhi_METjet4")
      {
	xmin_=0,xmax_=4,xmin=0,xmax=4,rebin=1;
	if(varName=="dPhi_METjet1") varName1="#Delta#phi(MET,lead jet)";
        if(varName=="dPhi_METjet2") varName1="#Delta#phi(MET,2^{nd}lead jet)";

      }
    if(varName=="dPhi_MET_CaloMET")    xmin_=0,xmax_=4,xmin=0,xmax=4, rebin=1;
    ymin_=0.5,ymax_=10000;

    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    h_4->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
     
   }


  gStyle->SetOptStat(0);
  c1= new TCanvas("stackhist","stackhist",1600,1000);

  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);

  pad1->SetBottomMargin(0.355);
  pad1->SetRightMargin(0.03);
  pad1->Draw();pad1->SetGridx(0);

  pad1->cd();
  pad1->SetLogy();

  TH1D *predsys = (TH1D*)sr->Clone("predsys");
  for(int i=1; i<sr->GetNbinsX();i++)
    {
      predsys->SetBinError(i+1,sr->GetBinError(i+1)/sr->GetBinContent(i+1));
      predsys->SetBinContent(i+1,1);
    }
  for(int i=1; i<sr->GetNbinsX();i++)
    {
      sr->SetBinError(i,0);
    }

  /*
  pred_sr->GetYaxis()->SetTitle("Entries");
  pred_sr->GetXaxis()->SetTitle(0);
  pred_sr->GetYaxis()->SetTitleSize(0.07);
  pred_sr->GetYaxis()->SetTitleOffset(0.72);
  */
  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(6);
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(1.2);
  pred_sr->SetMarkerColor(kBlack);
  pred_sr->SetLineColor(kBlack);
  pred_sr->SetLineWidth(2);

  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(1.2);
  sr->SetMarkerColor(kBlack);
  sr->SetLineColor(kBlack);
  sr->SetLineWidth(2);
  h_0->GetXaxis()->SetRangeUser(xmin,xmax);
  h_1->GetXaxis()->SetRangeUser(xmin,xmax);
  h_2->GetXaxis()->SetRangeUser(xmin,xmax);
  h_3->GetXaxis()->SetRangeUser(xmin,xmax);
  h_4->GetXaxis()->SetRangeUser(xmin,xmax);

  //  pred_sr->SetLineStyle(kBlue);  
  decorate(h_0,0,f_0->GetName());
  decorate(h_1,1,f_1->GetName());
  decorate(h_2,2,f_2->GetName());
  decorate(h_3,3,f_3->GetName());
  //  decorate(h_4,4,f_4->GetName());

  hs_var->Add(h_0);
  hs_var->Add(h_1);
  hs_var->Add(h_2);
  hs_var->Add(h_3);
  //hs_var->Add(h_4);

  hs_var->Draw("hist");
  hs_var->GetYaxis()->SetLabelSize(0.05);
  //  hs_var->GetXaxis()->SetLabelSize(0.04);

    hs_var->SetTitle(0);
  hs_var->GetYaxis()->SetTitle("Events");
  hs_var->GetXaxis()->SetTitle(0);
  hs_var->GetYaxis()->SetTitleSize(0.05);
  hs_var->GetYaxis()->SetTitleOffset(0.86);

  pad1->cd();
  hs_var->SetMinimum(ymin_);
  hs_var->SetMaximum(ymax_);
  hs_var->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->Draw("ex0p same");


  if(varName.Contains("nJets") || varName.Contains("nBTags")  || varName.Contains("nPhotons")){
    pred_sr->GetXaxis()->SetTickLength(0);
    pred_sr->GetXaxis()->SetLabelSize(0.06);
    TString temp2;
    for(int i=1;i<=sr->GetNbinsX();i++){
      temp2 = to_string(i-1);
      if(i%2==0 && varName.Contains("nJets")) continue;
      pred_sr->GetXaxis()->SetBinLabel(i,temp2);
    }
    pred_sr->GetXaxis()->SetLabelSize(0.02);
    pred_sr->GetXaxis()->SetLabelOffset(0.01);
    //    pred_sr->GetXaxis()->SetTickLength(0.02);
  }



  //  sr->Draw("e1 same");
 
  pad1->cd();
  cout<<"Total events in data CR :"<<pred_sr->Integral()<<endl;  
  cout<<"Total events in MC CR :"<<sr->Integral()<<endl;
  textOnTop.SetTextSize(0.045);
  intLumiE.SetTextSize(0.042);
  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");
  else if(AN) textOnTop.DrawLatexNDC(0.1,0.915,"CMS #it{#bf{Supplementary}}");
 else if(progress)textOnTop.DrawLatexNDC(0.12,0.91,"work in progress"); 
  //   textOnTop.DrawLatexNDC(0.12,0.91,"CMS");
  if(year=="2016")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.79,0.92,"#bf{137 fb^{-1} (13 TeV)}");

  
  TLegend *legend = new TLegend(0.6,0.82,0.89,0.89);
  legend->SetBorderSize(0);
  legend->SetTextSize(0.04);
  //  legend->SetHeader("Single lepton + #gamma region");
  legend->AddEntry(pred_sr,"Data (Single lepton + #gamma)","ep");
  legend->Draw();

  if(DatavsMC)
    {
      legend2 = new TLegend(0.6,0.67,0.89,0.8);
      legend2->SetNColumns(2);   
      //      legend->AddEntry(pred_sr,"Data : Lost Lepton (CR region)","lp");
      //     legend->AddEntry(sr,"MC : Lost Lepton (CR region)","lp");
      legend2->AddEntry(h_0,"t#bar{t} + #gamma","f");
      legend2->AddEntry(h_1,"t#bar{t} / t / #bar{t}","f");
      legend2->AddEntry(h_2,"W(l#nu) + jets","f");
      legend2->AddEntry(h_3,"W(l#nu) + #gamma","f");
      // legend2->AddEntry(h_4,"Single t/#bar{t}","f");
      //legend2->AddEntry(pred_sr,"Data (Single lepton + #gamma)","lpe");
    }

  if(!DatavsMC)
    {
      //      legend = new TLegend(0.47,0.85,0.9,0.9);
      //      legend->SetNColumns(1);
      //      legend->SetBorderSize(1);

      /* legend->AddEntry(sr,"Exp : (0e + photon )","lp"); */
      /* legend->AddEntry(pred_sr,"Pred : TF x (1e + photon)","lp"); */
      //legend->AddEntry(pred_sr,"Data : Lost Lepton (CR region)","lp");
      //     legend->AddEntry(sr,"MC : Lost Lepton (CR region)","lp");                                                                                                     

      legend2->AddEntry(h_0,"t #bar{t} + #gamma","f");
      legend2->AddEntry(h_1,"t #bar{t}","f");
      legend2->AddEntry(h_2,"W(l#nu) + jets","f");
      legend2->AddEntry(h_3,"W(l#nu) + #gamma","f");
      legend2->AddEntry(h_4,"Single t/#bar{t}","f");

      // legend->AddEntry(sr,"Exp : 0l  + #gamma ","lp");
      //      legend->AddEntry(pred_sr,"Pred : TF x (1l + #gamma)","lp");
    }
  //  legend->SetTextSize(0.045);
  //  legend2->SetTextSize(0.035);
  legend2->SetTextSize(0.04);
  legend2->SetBorderSize(0);
  //  legend->Draw();
 legend2->Draw();
 // legend1->Draw();
  
  if(varName=="AllSBins_v6_CD_EW_50bin_elec1"  ){
    TLine *line1V6=new TLine( 8,ymin_, 8 ,ymax2_);
    TLine *line2V6=new TLine(14,ymin_,14 ,ymax2_);
    TLine *line3V6=new TLine(19,ymin_,19 ,ymax2_);
    TLine *line4V6=new TLine(24,ymin_,24 ,ymax2_);
    TLine *line5V6=new TLine(29,ymin_,29 ,ymax2_);
    TLine *line6V6=new TLine(34,ymin_,34 ,ymax2_);
    TLine *line7V6=new TLine(40,ymin_,40 ,ymax2_);
    
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    TArrow *arrow1 = new TArrow(1,yset_  , 8,yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 8,yset_,14,yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow(14,yset_,19,yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow(19,yset_,24,yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow(24,yset_,29,yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow(29,yset_,34,yset_,0.01,"<|>");
    TArrow *arrow7 = new TArrow(34,yset_,40,yset_,0.01,"<|>");
    TArrow *arrow8 = new TArrow(40,yset_,46,yset_,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(3.0,2*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.5,2*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.5,2*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(20.5,2*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(25.5,2*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(30.5,2*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.SetTextSize(0.03);
    Tl.DrawLatex(35,2*yset_,"EW : W tag");
    Tl.DrawLatex(41,2*yset_,"EW : H tag");
  }
  

  if(varName=="AllSBins_v6_CD"){

    TLine *line1V6=new TLine( 1,0,  1,1000);
    TLine *line2V6=new TLine( 2,0,  2,1000);
    TLine *line3V6=new TLine( 3,0,  3,1000);
    TLine *line4V6=new TLine( 4,0,  4,1000);
    TLine *line5V6=new TLine( 5,0,  5,1000);
    TLine *line6V6=new TLine( 6,0,  6,1000);
    TLine *line7V6=new TLine( 7,0,  7,1000);
    TLine *line8V6=new TLine( 8,0,  8,1000);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
    line7V6->Draw(); line8V6->Draw();
  
    TArrow *arrow1 = new TArrow( 1, 0.4, 2, 0.4,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 2, 0.4, 3, 0.4,0.01,"<|>");
    TArrow *arrow3 = new TArrow( 3, 0.4, 4, 0.4,0.01,"<|>");
    TArrow *arrow4 = new TArrow( 4, 0.4, 5, 0.4,0.01,"<|>");
    TArrow *arrow5 = new TArrow( 5, 0.4, 6, 0.4,0.01,"<|>");
    TArrow *arrow6 = new TArrow( 6,0.4, 7,0.4,0.01,"<|>");
    TArrow *arrow7 = new TArrow( 7,0.4, 8,0.4,0.01,"<|>");
    TArrow *arrow8 = new TArrow( 8,0.4, 9,0.4,0.01,"<|>");

    
    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw();
    arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(1.5,0.47,"N^{ 0}_{ 2}");
    Tl.DrawLatex(2.5,0.47,"N^{ 0}_{ 3}");
    Tl.DrawLatex(3.5,0.47,"N^{ 0}_{ 4}");
    Tl.DrawLatex(4.5,0.47,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(5.5,0.47,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(6.5,0.47,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(7.5,0.47,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(8.5,0.47,"N^{ #geq1}_{ #geq7}");
  }

  TH1D *h4,*h3;
  if(!DatavsMC)
    {
      h4 = (TH1D*)pred_sr->Clone("h4");
      h3 = (TH1D*)sr->Clone("h3");
    }
  if(DatavsMC)
    {                                                                                                                                         
      h4 = (TH1D*)sr->Clone("h4");
      h3 = (TH1D*)pred_sr->Clone("h3");
    }

  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.35);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->SetRightMargin(0.03);
  pad2->cd();
  pad2->SetGrid(0);
  h3->GetYaxis()->SetNdivisions(5);
  h3->GetYaxis()->SetRangeUser(0,2.5);
  h3->GetYaxis()->SetTitleOffset(0.34);
  h3->GetYaxis()->SetTitleSize(0.13);
  h3->GetYaxis()->SetLabelSize(0.13);
  h3->GetYaxis()->CenterTitle();

  h3->SetLineColor(kBlack);
  h3->SetMinimum(ymin);  // Define Y ..                                                                                                       
  h3->SetMaximum(ymax); // .. range                                                                                                           
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(0.95);
  //  h3->SetLabelSize(0.2);

  // gStyle->SetOptStat(0);                                                                                                                   
  h3->Draw("EX0P0 ");       // Draw the ratio plot                                                                                                
  predsys->SetFillStyle(3244);
  predsys->SetMarkerColor(kGray+1);
  predsys->SetFillColor(kGray+1);
  predsys->Draw("E2 sames");
  h3->Draw("EX0P0 sames");
  h3->GetXaxis()->SetTickLength(0);

  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(1.04);
  h3->GetXaxis()->SetTitleSize(0.14);
  h3->GetXaxis()->SetTitle(varName1);

  //  h3->GetXaxis()->SetTitle(0);
  h3->GetXaxis()->SetLabelSize(0.13);
  if(!DatavsMC) h3->GetYaxis()->SetTitle("Exp/Pred");
 if(DatavsMC) h3->GetYaxis()->SetTitle("#frac{Data}{Simulation}");
  
  TLine *line= new TLine(xmin_,1.0,xmax_,1.0);
  
  line->SetLineColor(1);
  line->SetLineWidth(2);
  line->Draw();

  if(varName.Contains("nJets") || varName.Contains("nBTags")  || varName.Contains("nPhotons")){
    h3->GetXaxis()->SetNdivisions(5);
    pad2->SetTickx(0);
    h3->GetXaxis()->SetTickLength(0);
    h3->GetXaxis()->SetLabelSize(0.06);
    TString temp2;
    for(int i=1;i<=sr->GetNbinsX();i++){
      temp2 = to_string(i-1);
      //      if(i%2==0 && varName.Contains("nJets")) continue;
      h3->GetXaxis()->SetBinLabel(i,temp2);
    }
    h3->GetXaxis()->SetLabelSize(0.20);
    h3->GetXaxis()->SetLabelOffset(0.01);
    h3->GetXaxis()->SetTickLength(0.05);
    h3->GetXaxis()->SetTitleOffset(0.95);
    h3->GetXaxis()->SetTitleSize(0.14);

  }
  
  if(varName=="AllSBins_v6_CD_EW_50bin_elec1"  ){
    TLine *line1V6=new TLine( 8,ymin, 8 ,ymax);
    TLine *line2V6=new TLine(14,ymin,14 ,ymax);
    TLine *line3V6=new TLine(19,ymin,19 ,ymax);
    TLine *line4V6=new TLine(24,ymin,24 ,ymax);
    TLine *line5V6=new TLine(29,ymin,29 ,ymax);
    TLine *line6V6=new TLine(34,ymin,34 ,ymax);
    TLine *line7V6=new TLine(40,ymin,40 ,ymax);
    
    pad2->cd(); pad2->SetGridx(0);
    h3->GetXaxis()->SetTitle("Bin no.");

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
  }
  
  if(varName=="AllSBins_v6_CD"){
    TLine *line1V7=new TLine( 1,ymin,  1,ymax);
    TLine *line2V7=new TLine( 2,ymin,  2,ymax);
    TLine *line3V7=new TLine( 3,ymin,  3,ymax);
    TLine *line4V7=new TLine( 4,ymin,  4,ymax);
    TLine *line5V7=new TLine( 5,ymin,  5,ymax);
    TLine *line6V7=new TLine( 6,ymin,  6,ymax);
    TLine *line7V7=new TLine( 7,ymin,  7,ymax);
    TLine *line8V7=new TLine( 8,ymin,  8,ymax);


    pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
    line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
    line7V7->Draw(); line8V7->Draw();
  }
  //  c1->SaveAs(pdf);
  c1->SaveAs(png);
  c1->SetCanvasSize(1600,1000);
  c1->SaveAs(pdf);

}

void decorate(TH1D* hist,int i,const char* fname){
  hist->SetLineColor(col[i]);
  hist->SetFillColor(col[i]);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(1);
  hist->SetTitle(0);
  /* hist->GetXaxis()->SetLabelSize(.06); */
  /* hist->GetYaxis()->SetLabelSize(.10); */
  hist->GetXaxis()->SetTitleSize(0.06);
  gStyle->SetOptStat(0);

}
