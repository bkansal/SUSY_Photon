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

//vector<int> col={kGray,kCyan-1,kTeal+9,kOrange,kBlack};
vector<int> col={kGray,kOrange,kTeal+9,kCyan-1,kBlack};
void decorate(TH1D*,int,const char*);

void plotdatavsMC(TString varName,  TString year,  TString ntuples , bool ExpvsPred = true, bool SRvsCR=false)
{
  
  TFile *f1, *f2,*f3, *f_0,*f_1,*f_2,*f_3;
  string lep="LL";
  TString path,path1;
  //  path="/Users/bkansal/work/MET_Analysis/Analysis/fakerate/rootout/fake_rate_v7/FR_using_PhoPtQmulti_csv_cut_EMO//bjeta_qmulti_METcaloMET_tmp/";
  //   path="rootoutput/withphicut_zmass60to120_btagSF_elec/";
  //    path="rootoutput/withphicut_zmass60to120_btagSF_muon_tmp/";
  //  path="rootoutput/withphicut_zmass60to120_btagSF_tmp/";
  //path="./";
  //   path="rootoutput/withphicut_zptcut200_btagSF_elec/";

  // path="rootoutput/withphicut_zptcut200_btagSF_muon_tmp/";
     //     path="rootoutput/withphicut_zptcut200_btagSF_tmp/";
  path="rootoutput/withphicut_zmass60to120_elec_muon/"; 
  //  path="rootoutput/withphicut_zmass60to120_elec/";
    //  path="rootoutput/withphicut_zmass60to120_muon/";
  // path="rootoutput/withphicut_zmass60to120_data/";
  //path="rootoutput/withphicut_zmass60to120_muon_elec/";
 path1=path;
  TLatex textOnTop,intLumiE;
  bool elec=true , muon =false;

  //   bool elec=false , muon =true;
  // bool elec=false , muon =false;
 /* if(elec)     path="rootoutput/withphicut_zmass60to120_elec/";  */
 /* else if(muon)path="rootoutput/withphicut_zmass60to120_muon/";  */
 /* else  path="rootoutput/withphicut_zmass60to120_data/";     */

 
  TString filename,filename2,filename3,filename4,filename5,filename6;
  if(year == "full_Run2")
    {
      if(elec)     {filename= path+"Run2_elecdata_CR_v18.root";}
      else if(muon){     filename= path+"Run2_Muondata_CR_v18.root";}
      else  { filename= path+"Run2_METdata_CR_v18.root";}
      filename2= path+"TTWZJZGToLL_CR_v18.root";
      filename3= path+"WG_CR_v18.root";
      filename4= path+"TTG_CR_v18.root";
      filename5= path+"DYJetsToLL_CR_v18.root";
      filename6= path+"ZGToLLG_CR_v18.root";
    }
  else {
    if(elec)    filename= path+"Run"+year+"_elecdata_CR_v18.root";
    else if(muon)    filename= path+"Run"+year+"_Muondata_CR_v18.root";
    else    filename= path+"Run"+year+"_METdata_CR_v18.root";
    filename2= path+"TTWZJZGToLL_"+year+"_CR_v18.root";
    filename3= path+"WG_"+year+"_CR_v18.root";
    filename4= path+"TTG_"+year+"_CR_v18.root";
    filename5= path+"DYJetsToLL_"+year+"_CR_v18.root";
    filename6= path+"ZGToLLG_"+year+"_CR_v18.root";
	
  }
    

  f1 = new TFile(filename);
  f2 = new TFile(filename2);
  f_0 =new TFile(filename3);
  f_1 =new TFile(filename4);
  f_2 =new TFile(filename5);
  f_3 =new TFile(filename6);
  
  
  double xmin,xmax,bin,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000;

  TH1D *cr,*sr,*tf,*pred_sr,*h_0,*h_1,*h_2,*h_3;
  THStack *hs_var=new THStack("var_Stack",varName);
 
  TString title;

  if(varName=="AllSBins_v6_CD_EW_50bin")
    title="closure test using optimized search bins";
  else
    title="closure test using "+ varName +" variable";
  TString png,pdf;
  if(ExpvsPred)
    {
      png = path1+"/PDF/closure/"+varName+"_"+year+".pdf";
      pdf= path1+"/PDF/closure/"+varName+"_"+year+".png";
    }
  else if(SRvsCR)
    {
      png = path1+"/PDF/SF/"+varName+"_"+year+".pdf";
      pdf= path1+"/PDF/SF/"+varName+"_"+year+".png";
    }
  //  TCanvas *c1 = new TCanvas("stackhist","stackhist",600,500);
  TCanvas *c1;
  TString varName1,varName2;
  //  if(ExpvsPred)  varName2=varName+"_elec1_closure";
  if(ExpvsPred)  varName2=varName+"_elec0";
  else if(SRvsCR) varName2=varName;
  if(varName=="AllSBins_v6_CD_EW_50bin") varName2=varName+"_elec0";
  varName1=varName;


  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  //  c1 = new TCanvas("stackhist","stackhist",600,500);
  c1 = new TCanvas("stackhist","stackhist",900,1000);
      //  c1 = new TCanvas("stackhist","stackhist",600,500);
  sr          = (TH1D*)f1->Get(varName2);
  pred_sr     = (TH1D*)f2->Get(varName2);
  h_0=(TH1D*)f_0->FindObjectAny(varName2);
  h_1=(TH1D*)f_1->FindObjectAny(varName2);
  h_2=(TH1D*)f_2->FindObjectAny(varName2);
  h_3=(TH1D*)f_3->FindObjectAny(varName2);

  if(varName=="AllSBins_v6_CD_EW_50bin"){
    rebin=1;
    xmin_=1,xmax_=52,xmin=1,xmax=52,    ymin=0 , ymax=3.99, ymin_=0.5 , ymax_=10000000, yset_=7000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  }
  if(varName=="AllSBins_v7_CD"){
    rebin=1;
    xmin_=1,xmax_=37,xmin=1,xmax=37;
    //    ymin=0 , ymax=3.99, ymin_=0.5 , ymax_=10000, yset_=7000;
    ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=1;

    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  }

  if(varName=="AllSBins_v6_CD"){
    rebin=1;
    xmin_=1,xmax_=9,xmin=1,xmax=9;
    //ymin=0 , ymax=3.99, ymin_=0.5 , ymax_=10000, yset_=7000;
     ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=1;
    
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  }
  if(varName=="nJets" || varName=="nvtx" || varName=="nJets_EW" ||varName=="nJets_SP"||varName=="Qmulti" )
   {
     title="No. of Jets";
     rebin=1;
     if(varName=="Qmulti")    rebin=1,xmin_=0,xmax_=20,xmin=0,xmax=20,    ymin=0 , ymax=3.99, ymin_=0.5 , ymax_=100000000;
     if(varName=="nJets" || varName=="nJets_EW")    rebin=1,xmin_=0,xmax_=10,xmin=0,xmax=10 , ymin=0 , ymax=2.99, ymin_=0.5 , ymax_=100000;
    //    if(varName=="nJets")    rebin=1,xmin_=0,xmax_=15,xmin=0,xmax=15 , ymin=0 , ymax=1.99, ymin_=0.0005 , ymax_=0.04;

    if(varName=="nvtx")    rebin=1,xmin_=0,xmax_=50,xmin=0,xmax=50, ymin=0 , ymax=2.99, ymin_=0.5 , ymax_=100000;
    
    // ymin_=0.0005 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);


    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);

    // pred_sr->SetTitle(title);
    }

 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP" || varName=="h_deepcsv_v4"|| varName=="h_deepcsv" )
    {
      title="no. of btags";
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=4.99, ymin_=0.5 , ymax_=1000000;
    // ymin_=0.0005 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="invMass" || varName=="invMass_elec0"  )
    {
      title="M(l^{+}l^{-})";
       xmin_=10,xmax_=150,xmin=10,xmax=150;
       //  xmin_=80,xmax_=100,xmin=80,xmax=100;
    rebin=10;
    //   ymin=0 , ymax=3.99, ymin_=0 , ymax_=0.05;
    ymin_=0.5 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }

 else if(varName=="ST" || varName=="HT")
    {
    xmin_=0,xmax_=1400,xmin=0,xmax=1400;
    rebin=5;
    ymin=0 , ymax=2.99, ymin_=0.1 , ymax_=10000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="MET" || varName=="JetPt" || varName=="METvBin2" || varName=="JetPt1" || varName=="JetPt2" || varName=="MET_EW" )
   {
     title="MET";
      if(varName=="METvBin2")    xmin_=200,xmax_=2000,xmin=200,xmax=2000,rebin=1;
      if(varName=="MET" || varName=="MET_EW")    xmin_=200,xmax_=1000,xmin=200,xmax=1000,rebin=5;
      if(varName=="JetPt" || varName=="JetPt1" || varName=="JetPt2")    xmin_=0,xmax_=1000,xmin=0,xmax=1000,rebin=5;
      //  rebin=1;
    ymin=0 , ymax=2.99, ymin_=0.5 , ymax_=1000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);

    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="BestPhotonEta" || varName=="JetEta" || varName=="BestPhotonPhi" || varName=="JetPhi"|| varName=="JetPhi1"|| varName=="JetPh2"|| varName=="JetPhi3"|| varName=="JetPhi4"|| varName=="JetEta1"|| varName=="JetEta2"|| varName=="JetEta3"|| varName=="JetEta4" || varName=="METPhi" || varName=="ElectronPhi" || varName =="ElectronEta" ||varName=="EMObj_Phi" ||varName=="EMObj_Eta")
    {
    xmin_=-4.5,xmax_=4.5,xmin=-4.5,xmax=4.5;
    rebin=10;
    ymin=0 , ymax=3.99, ymin_=0.5 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
    h_1->Rebin(rebin);
    h_2->Rebin(rebin);
    h_3->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="EMObj_Pt" || varName=="tagObj_Pt" || varName=="EMObj_Pt_elec0" || varName=="tagObj_Pt_elec0" || varName=="ElectronPt" || varName=="BestPhotonPt" || varName=="genzPt" || varName=="zPt" || varName=="BestPhotonPt_EW")
    {
      //    xmin_=0,xmax_=1000,xmin=0,xmax=1000;
      /* if(varName=="EMObj_Pt") */
	{
	  xmin_=0,xmax_=600,xmin=0,xmax=600;
	  rebin=5;
	  ymin=0 , ymax=2.99, ymin_=0.5 , ymax_=1000;
	}
      pred_sr->Rebin(rebin);
      sr->Rebin(rebin);
      h_0->Rebin(rebin);
      h_1->Rebin(rebin);
      h_2->Rebin(rebin);
      h_3->Rebin(rebin);
      pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
      sr->GetXaxis()->SetRangeUser(xmin,xmax);
      pred_sr->SetTitle(title);
   }
 else if(varName=="dPhi_phoMET")
      {
    xmin_=0,xmax_=1,xmin=0,xmax=1;
    ymin_=0.5,ymax_=10000000;
     rebin=1;
     pred_sr->Rebin(rebin);
     sr->Rebin(rebin);
     h_0->Rebin(rebin);
     h_1->Rebin(rebin);
     h_2->Rebin(rebin);
     h_3->Rebin(rebin);
     pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
     sr->GetXaxis()->SetRangeUser(xmin,xmax);
     pred_sr->SetTitle(title);
   }
 else if(varName=="dPhi_METjet1" || varName=="dPhi_METjet2" || varName=="dPhi_METjet3" || varName=="dPhi_METjet4"||varName=="MET_CaloMET" || varName=="HT5HT" || varName=="dPhi_MET_CaloMET" || varName=="h_minDr_bestphoJets" || varName=="h_minDr_Elejet1" || varName=="h_minDr_Elejet2")
      {
	if(varName=="MET_CaloMET")    xmin_=0,xmax_=5,xmin=0,xmax=5, rebin=4;
	else if(varName=="HT5HT")    xmin_=0,xmax_=3,xmin=0,xmax=3, rebin=1;
	else if(varName=="dPhi_METjet1"|| varName=="dPhi_METjet2" || varName=="dPhi_METjet3" || varName=="dPhi_METjet4")    xmin_=0,xmax_=4,xmin=0,xmax=4,rebin=1;
	else if(varName=="dPhi_MET_CaloMET")    xmin_=0,xmax_=4,xmin=0,xmax=4, rebin=1;
	
	else
	  xmin_=0,xmax_=2,xmin=0,xmax=2, rebin=4;
	//     rebin=1;
    ymin_=0.5,ymax_=1000;
    
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    h_0->Rebin(rebin);
     h_1->Rebin(rebin);
     h_2->Rebin(rebin);
     h_3->Rebin(rebin);
     pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
     sr->GetXaxis()->SetRangeUser(xmin,xmax);
     pred_sr->SetTitle(title);
     // pred_sr->SetTitle(title);
     
   }

 /* else */
 /*   { */
 /*    xmin_=0,xmax_=52,xmin=0,xmax=52; */

 /*     rebin=1; */
 /*     pred_sr->Rebin(rebin); */
 /*     sr->Rebin(rebin); */
 /*    h_0->Rebin(rebin); */
 /*    h_1->Rebin(rebin); */
 /*     pred_sr->GetXaxis()->SetRangeUser(xmin,xmax); */
 /*     sr->GetXaxis()->SetRangeUser(xmin,xmax); */
 /*     pred_sr->SetTitle(title); */
 /*   } */
 /* if(ntuples!="v18") */
 /*   ymin_=0.5 , ymax_=100000000; */
  
 /*  for(int i=xmin_;i<=10;i++) */
 /*    { cout<<pred_sr->GetBinContent(i)<<endl;} */
 /* cout<<"The sr content"<<endl; */

 /* for(int i=xmin_;i<=10;i++) */
 /*    { cout<<sr->GetBinContent(i)<<endl;} */
 /*  cout<<"==============="<<endl; */

  


  /* TPad *pad1 = new TPad("pad1","pad1",0,0.325,1,1); */
  /* pad1->SetBottomMargin(0); */
  /* pad1->SetBottomMargin(0.3); */
  /* //TPad *pad1 = new TPad("pad1","pad1",0,0.9,1,0.1);                                                                                                          */
  /* TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.3); */
  /* pad2->SetTopMargin(0); */
  /* pad2->SetBottomMargin(0.3); */

  TPad *pad1 = new TPad("pad1","pad1",0,0.425,1,1);
  pad1->SetBottomMargin(0);
  pad1->SetBottomMargin(0.4);
  //TPad *pad1 = new TPad("pad1","pad1",0,0.9,1,0.1);                                                                                                         
  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.4);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  
  pad1->Draw();pad1->SetGridx();

  pad1->cd();
  //  if(ntuples!="v18")

    pred_sr->SetTitle(0);
    if(varName=="invMass")
      {
	ymax_=100;
      }
    else
      	pad1->SetLogy();

  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(0.05);
  if(ntuples=="v18")
    pred_sr->GetYaxis()->SetTitle("Fake rate");
  else
    pred_sr->GetYaxis()->SetTitle("Entries");

  pred_sr->GetXaxis()->SetTitle(0);
  pred_sr->GetYaxis()->SetTitleSize(0.07);
  pred_sr->GetYaxis()->SetTitleOffset(0.72);

  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(0.7);
  pred_sr->SetMarkerColor(kRed);
  pred_sr->SetLineColor(kRed);
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(0.7);
  sr->SetMarkerColor(kBlack);
  sr->SetLineColor(kBlack);

  
  //  pred_sr->SetLineStyle(kBlue);
  pred_sr->Draw();
  h_0->GetXaxis()->SetRangeUser(xmin_,xmax_);
  h_1->GetXaxis()->SetRangeUser(xmin_,xmax_);
  decorate(h_0,0,f_0->GetName());
  decorate(h_1,1,f_1->GetName());
  decorate(h_2,2,f_2->GetName());
  decorate(h_3,3,f_3->GetName());
  hs_var->Add(h_0);
  hs_var->Add(h_1);
  hs_var->Add(h_2);
  hs_var->Add(h_3);
  hs_var->Draw("hist");
  hs_var->GetYaxis()->SetLabelSize(0.05);
  hs_var->SetTitle(0);
  hs_var->GetXaxis()->SetLimits(xmin_,xmax_);
  hs_var->SetMinimum(ymin_);
  hs_var->SetMaximum(ymax_);
  sr->Draw("sames");


   TPaveStats *ptstats = new TPaveStats(0.7,0.85,0.9,0.9,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(2);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(2);
   ptstats->SetTextFont(42);
   //   TText *ptstats_LaTex = ptstats->AddText("Integral =  140.5");
   ptstats->SetOptStat(1000000);
   ptstats->SetOptFit(0);
   pred_sr->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(pred_sr);
   TPaveStats *ptstats2 = new TPaveStats(0.7,0.8,0.9,0.85,"brNDC");
   ptstats2->SetName("stats");
   ptstats2->SetBorderSize(1);
   ptstats2->SetFillColor(0);
   ptstats2->SetLineColor(4);
   ptstats2->SetTextAlign(12);
   ptstats2->SetTextColor(4);
   ptstats2->SetTextFont(42);
   //   TText *ptstats2_LaTex = ptstats2->AddText("Integral =  140.5");
   ptstats2->SetOptStat(1000000);
   ptstats2->SetOptFit(0);
   sr->GetListOfFunctions()->Add(ptstats2);
   ptstats2->SetParent(sr);
  double chi=pred_sr->Chi2Test(sr,"WW CHI2");
  int NDF=chi/pred_sr->Chi2Test(sr,"WW CHI2/NDF");
  double p=pred_sr->Chi2Test(sr,"WW p");
  textOnTop.SetTextSize(0.06);
  intLumiE.SetTextSize(0.06);
  //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");                                                                 
  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation Preliminary}}");
  if(year=="2016")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{137 fb^{-1} (13 TeV)}");
  char chi2[1000],chi1[1000],chi3[1000];
  // sprintf(chi2,"Chi2/NDF = %f",chi_NDF);
  //  double integeral=h_0->Integral() + h_1->Integral();
  //  double integeral1=h_1->Integral() + h_2->Integral() + h_3->Integral();
  double integeral=h_1->Integral();
  double integeral2=h_1->Integral() + h_2->Integral() + h_3->Integral();
  double integeral1=sr->Integral();

  sprintf(chi1,"Chi2/NDF = %f / %d , p = %f",chi,NDF,p);
  sprintf(chi2,"MC ttbar = %f",integeral);
  sprintf(chi3,"MC = %f , Data = %f",integeral2,integeral1);
  TLegend *legend = new TLegend(0.5,0.78,0.9,0.9);
  legend->SetNColumns(3);
  legend->SetBorderSize(1);
  TLegend *legend1 = new TLegend(0.1,0.82,0.45,0.9);
  //  TLegend *legend2 = new TLegend(0.1,0.82,0.45,0.9);
  //  legend1->SetHeader("with HEM veto","C");                               // option "C" allows to center the header                                      
  legend1->SetHeader(chi3,"C");
  //  legend1->SetHeader(integeral1,"C");
  //  legend1->SetHeader(p,"C");
  cout<<"Chi ===> "<<chi<<endl;
  cout<<"Chi1 ===> "<<chi1<<endl;
  cout<<"Total events in tt+gamma : "<<chi2<<endl;
  cout<<"Total events in Z->ll + tt+gamma : "<<chi3<<endl;
  legend1->SetTextSize(0.04);
  legend->SetTextSize(0.04);
  legend1->Draw();

  legend->AddEntry(sr,"Data","lp");
  //  legend->AddEntry(pred_sr,"MC","lp");
  //  legend->AddEntry(sr,"MC","lp");
  /* legend->AddEntry(h_0,"t #bar{t} + #gamma","f"); */
  /* legend->AddEntry(h_1,"W(l#nu) + #gamma","f"); */
  legend->AddEntry(h_0,"W + #gamma ","f");
  legend->AddEntry(h_1,"tt + #gamma ","f");
  legend->AddEntry(h_2,"Z ->  l^{+}l^{-} ","f");
  legend->AddEntry(h_3,"Z -> l^{+}l^{-} + #gamma ","f");
  legend->Draw();

  legend->SetTextSize(0.06);
  if(varName=="AllSBins_v7_CD"){
    TLine *line1V6=new TLine( 8,ymin_,  8,ymax_);
    TLine *line2V6=new TLine(14,ymin_, 14,ymax_);
    TLine *line3V6=new TLine(20,ymin_, 20,ymax_);
    TLine *line4V6=new TLine(26,ymin_, 26,ymax_);
    TLine *line5V6=new TLine(32,ymin_, 32,ymax_);
    
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();

    TArrow *arrow1 = new TArrow( 1,yset_,  8,yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 8,yset_, 14,yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow(14,yset_, 20,yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow(20,yset_, 26,yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow(26,yset_, 32,yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow(32,yset_, 38,yset_,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.05);
    Tl.DrawLatex(2.5 ,2*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.0 ,2*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.0,2*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(21.0,2*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(27,2*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(33,2*yset_,"N^{ #geq1}_{ #geq7}");
  }
  if(varName=="AllSBins_v6_CD"){

    TLine *line1V6=new TLine( 1,ymin_,  1,ymax_);
    TLine *line2V6=new TLine( 2,ymin_,  2,ymax_);
    TLine *line3V6=new TLine( 3,ymin_,  3,ymax_);
    TLine *line4V6=new TLine( 4,ymin_,  4,ymax_);
    TLine *line5V6=new TLine( 5,ymin_,  5,ymax_);
    TLine *line6V6=new TLine( 6,ymin_,  6,ymax_);
    TLine *line7V6=new TLine( 7,ymin_,  7,ymax_);
    TLine *line8V6=new TLine( 8,ymin_,  8,ymax_);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
    line7V6->Draw(); line8V6->Draw();

    TArrow *arrow1 = new TArrow( 1, yset_, 2, yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 2, yset_, 3, yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow( 3, yset_, 4, yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow( 4, yset_, 5, yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow( 5, yset_, 6, yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow( 6,yset_, 7,yset_,0.01,"<|>");
    TArrow *arrow7 = new TArrow( 7,yset_, 8,yset_,0.01,"<|>");
    TArrow *arrow8 = new TArrow( 8,yset_, 9,yset_,0.01,"<|>");


    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw();
    arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.06);
    Tl.DrawLatex(1.5,yset_,"N^{ 0}_{ 2}");
    Tl.DrawLatex(2.5,yset_,"N^{ 0}_{ 3}");
    Tl.DrawLatex(3.5,yset_,"N^{ 0}_{ 4}");
    Tl.DrawLatex(4.5,yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(5.5,yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(6.5,yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(7.5,yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(8.5,yset_,"N^{ #geq1}_{ #geq7}");
    
    
  }

  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
    TLine *line1V6=new TLine( 8,ymin_, 8 ,ymax_);
    TLine *line2V6=new TLine(14,ymin_,14 ,ymax_);
    TLine *line3V6=new TLine(20,ymin_,20 ,ymax_);
    TLine *line4V6=new TLine(26,ymin_,26 ,ymax_);
    TLine *line5V6=new TLine(32,ymin_,32 ,ymax_);
    TLine *line6V6=new TLine(38,ymin_,38 ,ymax_);
    TLine *line7V6=new TLine(45,ymin_,45 ,ymax_);
    
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    TArrow *arrow1 = new TArrow(1,yset_  , 8,yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 8,yset_,14,yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow(14,yset_,20,yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow(20,yset_,26,yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow(26,yset_,32,yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow(32,yset_,38,yset_,0.01,"<|>");
    TArrow *arrow7 = new TArrow(38,yset_,45,yset_,0.01,"<|>");
    TArrow *arrow8 = new TArrow(45,yset_,51,yset_,0.01,"<|>");

    
    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(3.0,2*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.5,2*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.5,2*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(21.5,2*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(27,2*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(33,2*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(38,2*yset_,"EW : W tag");
    Tl.DrawLatex(45,2*yset_,"EW : H tag");
  }
  

  legend->Draw();
  //  legend1->Draw();
  /* ptstats->Draw(); */
  /* ptstats2->Draw(); */
  TH1D *h4 = (TH1D*)pred_sr->Clone("h4");
  TH1D *h3 = (TH1D*)sr->Clone("h3");

  //  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.3);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->cd();
  pad2->SetGrid(1);

  h3->GetYaxis()->SetRangeUser(0.5,1.5);
  
  h3->SetLineColor(kBlack);
  h3->SetLineStyle(1);
  h3->SetLineWidth(2);
  /* if(ntuples=="v18") */
  /*   { */
  /*     h3->SetMinimum(ymin);  // Define Y ..                                                                                                    */
  /*     h3->SetMaximum(ymax); // .. range                                                                                                          */
  /*   } */
  /* else */
    {
      h3->SetMinimum(0);  // Define Y ..
      h3->SetMaximum(1.99); // .. range                                                                                                                      
    }
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(0.6);
  // gStyle->SetOptStat(0);                                                                                                                   
  h3->Draw("ep");       // Draw the ratio plot                                                                                                

  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(0.8);
  if(varName=="AllSBins_v6_CD_EW_50bin") h3->GetXaxis()->SetTitle("Bin no.");
  else if(varName=="EMObj_Pt") h3->GetXaxis()->SetTitle("e p_{T}");
  else if(varName=="METvBin2") h3->GetXaxis()->SetTitle("MET");

  
  else
    h3->GetXaxis()->SetTitle(title);
  h3->GetXaxis()->SetTitleSize(0.18);
  h3->GetXaxis()->SetLabelSize(0.17);

  h3->GetYaxis()->SetTitle("Data/MC");
  TLine *line,*line1;
  
  line = new TLine(xmin_,1,xmax_,1);
  if(year=="2016")  line1 = new TLine(xmin_,0.95,xmax_,0.92);
  if(year=="2017")  line1 = new TLine(xmin_,0.85,xmax_,0.85);
  if(year=="2018")  line1 = new TLine(xmin_,0.75,xmax_,0.75);
  else  line1 = new TLine(xmin_,0.75,xmax_,0.75);
  h3->GetYaxis()->SetNdivisions(5);

  
  line->SetLineColor(1);
  line->SetLineStyle(1);
  line->SetLineWidth(1);
  line->Draw();

  //  if(year=="2017" || year=="2018")
    {
      line1->SetLineColor(4);
      line1->SetLineStyle(1);
      line1->SetLineWidth(1);
      line1->Draw();
    }

  

  //  h3->GetYaxis()->SetNdivisions(5);
  h3->GetYaxis()->SetTitleOffset(0.26);
  h3->GetYaxis()->SetTitleSize(0.15);
  h3->GetYaxis()->SetLabelSize(0.17);


  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
    TLine *line1V6=new TLine( 8,ymin, 8,ymax);
    TLine *line2V6=new TLine(14,ymin,14,ymax);
    TLine *line3V6=new TLine(20,ymin,20,ymax);
    TLine *line4V6=new TLine(26,ymin,26,ymax);
    TLine *line5V6=new TLine(32,ymin,32,ymax);
    TLine *line6V6=new TLine(38,ymin,38,ymax);
    TLine *line7V6=new TLine(45,ymin,45,ymax);
    
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

  if(varName=="AllSBins_v7_CD"){
  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(0.9);
   h3->GetXaxis()->SetTitle("Bin no.");
  h3->GetXaxis()->SetTitleSize(0.17);
     
  TLine *line1V7=new TLine( 8,ymin_,  8,ymax_);
  TLine *line2V7=new TLine(14,ymin_, 14,ymax_);
  TLine *line3V7=new TLine(20,ymin_, 20,ymax_);
  TLine *line4V7=new TLine(26,ymin_, 26,ymax_);
  TLine *line5V7=new TLine(32,ymin_, 32,ymax_);

  // pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
  pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
   line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
  line4V7->Draw();      line5V7->Draw();

   }
  
  /* if(ntuples!="v18") */


   /* for(int i=50;i<=90;i++)  */
   /*   { cout<<h_1->GetBinLowEdge(i)<<" : "<<h_1->GetBinContent(i)<<endl;}  */
  
  /* cout<<"The TF content in bin"<<endl; */
  /* for(int i=0;i<=45;i++) */
  /*   { cout<<h3->GetBinLowEdge(i)<<" : "<<h3->GetBinContent(i)<<endl;} */
  /* cout<<"==============="<<endl; */
  
  /* /\* for(int i=bin0;i<=bin1;i++) *\/ */
  /* /\*   { cout<<TF->GetBinContent(i)<<endl;} *\/ */
  /* /\* cout<<"The Transfer Factor error in bin"<<endl; *\/ */
  /* for(int i=0;i<=45;i++) */
  /*   { cout<<h3->GetBinError(i)<<endl;} */
  c1->SaveAs(pdf);
  c1->SaveAs(png);
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
