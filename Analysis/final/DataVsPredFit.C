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

const int nfiles=4;    //Specify no. of files
//vector<int> col={kBlack,kOrange,kAzure+8,kRed,kBlue,kTeal+9,kOrange,kPink+1,kGreen,kCyan,kBlue,kRed};  //Specify Colors
//vector<int> col={kBlack,kTeal+7,kOrange-4,kRed,kBlue,kTeal+9,kOrange,kPink+1,kGreen,kCyan,kBlue,kRed};  //Specify Colors
//vector<int> col={kBlack,kOrange,kPink+7,kAzure+8,kRed,kBlue,kTeal+7,kTeal+9,kOrange,kPink+1,kGreen,kCyan,kBlue,kRed};  //Specify Colors
//vector<int> col={kBlack,kGray,kOrange,kAzure+8,kRed,kBlue,kTeal+7,kTeal+9,kOrange,kPink+1,kGreen,kCyan,kBlue,kRed};  //Specify Colors
//vector<int> col={kBlack,kOrange,kTeal+9,kCyan-1,kCyan,kBlue,kMagenta+3,kPink+10,kOrange+7};
vector<int> col={kBlack,kCyan,kOrange,kTeal+9,kCyan-1,kBlue,kBlue,kMagenta+3,kRed};
//vector<int> col={kBlack,kCyan,kOrange,kTeal+9,kCyan-1,kBlue,kBlue,kRed,kMagenta+3};
TString name;
bool saveCanvas=1, set0binsSmallValue = 1, sepSystStat = 1, plotPostFitSignal = 0, printTable = 1;
void set0PredSmall(TH1D*,double);
void setLastBinAsOverFlow(TH1D*);
void setMyRange(TH1D*,double,double);
void setMyRange(THStack*,double,double);
TString getLegName(TString);
TString getXaxisName(TString);
double data_Integral=0,mc_Integral=0, datatIntgrErr = 0, mcIntgrErr = 0, stackHistMinVal = 0.7;
TLatex textOnTop,intLumiE;
double intLumi=35.9;
TFile *f, *fSig[nfiles-1];

void DataVsPredFit(TString iFname, TString catName){
  TH1::SetDefaultSumw2(1);
  gStyle->SetOptStat(0);
  //  gStyle->SetOptStat("nemri");
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.1);
  TString histName, sampleName;
  TString year1;
  //  TFile *f, *fSig[nfiles-1];
  
  f = new TFile(iFname);
  if(iFname.Contains("2016")){
    intLumi=35.8;
    year1 = "2016";
    // sampleName = "NonresPred_2016.root"; f[2] = new TFile(sampleName);
    // sampleName = "LostLepPred_2016.root";    f[1] = new TFile(sampleName);
  }
  else if(iFname.Contains("2017")){
    intLumi=41.5;
    year1 = "2017";
    // sampleName = "NonresPred_2017.root"; f[2] = new TFile(sampleName);
    // sampleName = "LostLepPred_2017.root";    f[1] = new TFile(sampleName);
  }
  else if(iFname.Contains("2018")){
    intLumi=59.5;
    year1 = "2018";
    // sampleName = "NonresPred_2018.root"; f[2] = new TFile(sampleName);
    // sampleName = "LostLepPred_2018.root";    f[1] = new TFile(sampleName);
  }
  else if(iFname.Contains("Run2")){
    intLumi=137;
    year1 = "Run2";
    // sampleName = "NonresPred_Run2.root"; f[2] = new TFile(sampleName);
    // sampleName = "LostLepPred_Run2.root";    f[1] = new TFile(sampleName);
    // sampleName = "../TChiWH_1000_100_MCRun2.root"; fSig[0] = new TFile(sampleName);
    // sampleName = "../TChiWZ_800_100_MCRun2.root"; fSig[1] = new TFile(sampleName);
    // sampleName = "../TChiWH_1000_100_hino_MCRun2.root"; fSig[0] = new TFile(sampleName);
    // sampleName = "../TChiHZ_1000_100_MCRun2.root"; fSig[1] = new TFile(sampleName);
  }

  
  sampleName = "rootfiles/T5bbbbZg_2200_200_FastSim_v18.root"; fSig[0] = new TFile(sampleName);        
  //    cout<<sampleName<<endl;
  sampleName = "rootfiles/T5bbbbZg_2200_2100_FastSim_v18.root"; fSig[1] = new TFile(sampleName);	
  sampleName = "rootfiles/TChiWG_0_1000_FastSim_v18.root"; fSig[2] = new TFile(sampleName); 
      //   sampleName = "../../../Analysis/rootoutput/nphotons/T5qqqqHg_2250_2150_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
    
  //      sampleName = "../../../Analysis/rootoutput/nphotons/T5ttttZg_2200_200_FastSim_v18.root"; fSig[0] = new TFile(sampleName);
  //cout<<sampleName<<endl;
      //  sampleName = "../../../Analysis/rootoutput/nphotons/T5ttttZg_2200_1000_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
      //   sampleName = "../../../Analysis/rootoutput/nphotons/T5ttttZg_2200_1900_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
      
  
  //      sampleName = "../../../Analysis/rootoutput/nphotons/T6ttZg_1300_200_FastSim_v18.root"; fSig[0] = new TFile(sampleName);
  //   cout<<sampleName<<endl;
      //  sampleName = "../../../Analysis/rootoutput/nphotons/T6ttZg_1300_600_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
  //  sampleName = "../../../Analysis/rootoutput/nphotons/T6ttZg_1300_1200_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
      /*  
      sampleName = "../../../Analysis/rootoutput/nphotons/TChiNG_0_600_FastSim_v18.root"; fSig[0] = new TFile(sampleName);
      cout<<sampleName<<endl;
      sampleName = "../../../Analysis/rootoutput/nphotons/TChiNG_0_1000_FastSim_v18.root"; fSig[1] = new TFile(sampleName);
      sampleName = "../../../Analysis/rootoutput/nphotons/TChiNG_0_1200_FastSim_v18.root"; fSig[2] = new TFile(sampleName);
      
      */
      //      sampleName = "../../../Analysis/rootoutput/nphotons/TChiWG_0_1200_FastSim_v18.root"; fSig[2] = new TFile(sampleName);

   
	   vector<TString> name1, name3;
  // vector<int> rebin;
  // vector<double> xLow,xHigh;
 
  name1.push_back("DataFit");
  name1.push_back("QCD");
  name1.push_back("Zin");
  name1.push_back("LL");
  name1.push_back("FR");

  name3.push_back("DataFit");
  name3.push_back("#gamma + jets");
  name3.push_back("Z(#nu#bar{#nu}) + #gamma");
  name3.push_back("Lost lepton");
  name3.push_back("e #rightarrow #gamma");

  //  name1.push_back("QCD");
  
  TLegend *legend;//=new TLegend(0.6, 0.90,  0.98, 0.45);
  TCanvas *c_cA;
  TPad *p_top;
  TPad *p_bot;
  THStack *hs_hist;
  TH1D *h_sum, *h_predRelSyst, *h_predNoUnc;

  name=catName+year1;
  //  c_cA=new TCanvas(name,name,1200,800);//c_cA->Divide(4,2);
  //   p_top=new TPad(name+"_top",name+"_top",0,0.4,1,1);
  // p_bot=new TPad(name+"_bot",name+"_bot",0,0.0,1,0.395);
  /*
  p_top->Draw();
  p_top->SetGridx(0);p_top->SetGridy(0);
  p_top->SetLogy();
  p_top->SetBottomMargin(0);
  p_bot->SetTopMargin(0);
  p_bot->SetBottomMargin(0.3);
  */
  c_cA=new TCanvas(name,name,1600,900);
  p_top=new TPad(name+"_top",name+"_top",0,0,1,1);
  p_bot=new TPad(name+"_bot",name+"_bot",0,0,1,0.35);
  p_top->Draw();
  p_top->SetGridx(0);p_top->SetGridy(0);
  p_top->SetLogy();
  p_top->SetBottomMargin(0.355);
  p_bot->SetTopMargin(0);
  p_bot->SetBottomMargin(0.3);
  p_bot->Draw();p_bot->SetGridx(0);p_bot->SetGridy();    
  name="Stack";
  hs_hist = new THStack(name,name);

  //    legend=new TLegend(0.43,0.78,0.88,0.88);

  //legend=new TLegend(0.2,0.59,0.85,0.885);
   legend=new TLegend(0.2,0.73,0.85,0.885);

   //legend=new TLegend(0.36,0.55,0.85,0.88);
  // legend=new TLegend(0.33,0.45,0.88,0.88);
  //  legend=new TLegend(0.30,0.53,0.88,0.88);

   legend->SetNColumns(3);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  //  legend->SetTextSize(0.048);
      
  
  TH1D *h_data,*h_histE,*h_datacopy, *h_sig, *h_sig2[nfiles-1];
  c_cA->cd();
  name=name1[0];
  //    h_data=(TH1D*)f[0]->FindObjectAny(name);
  f->GetObject(name,h_data);
  //setLastBinAsOverFlow(h_data);
  c_cA->cd();p_top->cd();
  p_top->SetTickx();p_top->SetTicky();
  h_data->SetLineColor(kBlack);
  h_data->SetLineWidth(2);
  h_data->SetMarkerStyle(20);
  h_data->SetMarkerColor(h_data->GetLineColor());
  if(catName.Contains("SR"))legend->AddEntry(h_data,"Data : predictions","ep");
  else if(catName.Contains("CR"))legend->AddEntry(h_data,"Data","ep");
  else legend->AddEntry(h_data,"Data","ep");
  //gPad->Update();
  // gPad->BuildLegend(0.75,0.75,0.95,0.95,"");
  //mc_Integral = 0;
  for(int p=1;p<name1.size();p++){
    name=name1[p];
    f->GetObject(name,h_histE);
    //setLastBinAsOverFlow(h_histE);
    
    h_histE->SetLineColor(kBlack);
    h_histE->SetLineWidth(1);
    //      h_histE->SetMarkerStyle(21);
    h_histE->SetMarkerColor(col[p]);
    h_histE->SetFillColor(col[p]);
    legend->SetTextSize(0.03);
    hs_hist->Add(h_histE);
    legend->AddEntry(h_histE,getLegName(name3[p]),"f");
  }
  f->GetObject("TotalBG",h_sum);
  h_sum->SetLineColor(kBlack);
  h_sum->SetLineWidth(1);
  legend->AddEntry(h_sum,"Uncertainty (sys + stat)","f");

  if(plotPostFitSignal){
    f->GetObject("Signal",h_sig);
    h_sig->SetLineColor(kRed);
    h_sig->SetLineWidth(1);
    if(h_sig->Integral() < 0){
      h_sig->Scale(-1);
      legend->AddEntry(h_sig,"(-)Signal","l");
    }
    else legend->AddEntry(h_sig,"Signal","l");
  }
  else{
    for(int i=1;i<nfiles;i++){
      if(catName=="WHT" || catName=="FBWH") histName = "METvBin_FBWH_SR";
      if(catName=="WT" || catName=="FBW") histName = "METvBin_FBW_SR";
      if(catName=="HT" || catName=="FBH") histName = "METvBin_FBH_SR";
      if(catName=="wt" || catName=="WtWm1AK8") histName = "METvBin_WtWm1AK8_1b";
      if(catName=="ht" || catName=="HtHm1AK8") histName = "METvBin_HtHm1AK8_1b";
      histName = "AllSBins_v6_CD_EW_50bin_dphi";
      fSig[i-1]->GetObject(histName,h_sig2[i-1]);
      h_sig2[i-1]->SetLineColor(col[5+i]);
      h_sig2[i-1]->SetLineWidth(3);
      setLastBinAsOverFlow(h_sig2[i-1]);
      
      legend->AddEntry(h_sig2[i-1],getLegName(fSig[i-1]->GetName()),"l");
    }
  }
  c_cA->cd();    p_top->cd();
  hs_hist->SetMinimum(stackHistMinVal);
  hs_hist->SetMaximum(1500*hs_hist->GetMaximum());
  hs_hist->Draw("HIST");
  
  h_sum->SetFillColor(kGray+6);
  h_sum->SetFillStyle(3013);
  // if(set0binsSmallValue){
  //   set0PredSmall(h_sum,1e-9+stackHistMinVal);
  // }
  h_sum->Draw("e2 same");

  ///////////////////////////
  double yset_=3.5;
  TLine *line1V6=new TLine( 8,0.5,  8,3000*yset_);
  TLine *line2V6=new TLine(14,0.5, 14,3000*yset_);
  TLine *line3V6=new TLine(19,0.5, 19,3000*yset_);
  TLine *line4V6=new TLine(24,0.5, 24,3000*yset_);
  TLine *line5V6=new TLine(29,0.5, 29,3000*yset_);
  TLine *line6V6=new TLine(34,0.5, 34,3000*yset_);
  TLine *line7V6=new TLine(40,0.5, 40,3000*yset_);
  TLine *line8V6=new TLine(46,0.5, 46,3000*yset_);
  
  line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
  line4V6->Draw();      line5V6->Draw();
  line6V6->Draw();      line7V6->Draw();
  TArrow *arrow1 = new TArrow( 1,yset_*1200, 8,yset_*1200,0.01,"<|>");
  TArrow *arrow2 = new TArrow( 8,yset_*1200,14,yset_*1200,0.01,"<|>");
  TArrow *arrow3 = new TArrow(14,yset_*1200, 19,yset_*1200,0.01,"<|>");
  TArrow *arrow4 = new TArrow(19,yset_*1200, 24,yset_*1200,0.01,"<|>");
  TArrow *arrow5 = new TArrow(24,yset_*1200, 29,yset_*1200,0.01,"<|>");
  TArrow *arrow6 = new TArrow(29,yset_*1200, 34,yset_*1200,0.01,"<|>");
  TArrow *arrow7 = new TArrow(34,yset_*1200, 40,yset_*1200,0.01,"<|>");
  TArrow *arrow8 = new TArrow(40,yset_*1200, 46,yset_*1200,0.01,"<|>");
  
  arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
  arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
  arrow7->Draw(); arrow8->Draw();
  TLatex Tl;

  Tl.SetTextSize(0.04);
  Tl.DrawLatex(3.5,1980*yset_,"N^{ 0}_{ 2-4}");
  Tl.DrawLatex(10.0,1980*yset_,"N^{ 0}_{ 5-6}");
  Tl.DrawLatex(15.5,1980*yset_,"N^{ 0}_{ #geq7}");
  Tl.DrawLatex(20.5,1980*yset_,"N^{ #geq1}_{ 2-4}");
  Tl.DrawLatex(25.5,1980*yset_,"N^{ #geq1}_{ 5-6}");
  Tl.DrawLatex(30.5,1980*yset_,"N^{ #geq1}_{ #geq7}");
  Tl.SetTextSize(0.04);
  Tl.DrawLatex(35.5,1980*yset_,"V tag");
  Tl.DrawLatex(41.5,1980*yset_,"H tag");

  //////////////////////////
  
  h_predNoUnc = (TH1D*)h_sum->Clone("predNoUnc");
  h_predRelSyst = (TH1D*)h_sum->Clone("PredRelUnc");
  for(int k=1;k<=h_predRelSyst->GetNbinsX();k++){
    double err = 0.;
    if(h_predRelSyst->GetBinContent(k) < 1e-9) err = 3.0;
    else
      err = h_predRelSyst->GetBinError(k)/h_predRelSyst->GetBinContent(k);
    h_predRelSyst->SetBinContent(k,1.0);
    h_predRelSyst->SetBinError(k,err);
    h_predRelSyst->SetFillColor(kGray+1);
    h_predRelSyst->SetFillStyle(3013);
    h_predNoUnc->SetBinError(k,0.);
  }  
  
  name = h_data->GetName();
  hs_hist->GetYaxis()->SetNdivisions(5);
  //    if(name.Contains("MuPt")) setMyRange(hs_hist,xLow,xHigh);
  h_data->Draw("x0e1 same");
  hs_hist->SetTitle(";;Events / bin");
  hs_hist->GetYaxis()->SetTitleOffset(0.82);    
  hs_hist->GetYaxis()->SetTitleSize(0.05);
  hs_hist->GetYaxis()->SetLabelSize(0.05);

  if(plotPostFitSignal) h_sig->Draw("hist same");
  else{
    for(int i=1;i<nfiles;i++){
      h_sig2[i-1]->Draw("hist same");
    }
  }
  
  c_cA->Modified();
  c_cA->Update();
  //    legend->SetNColumns(3);
  legend->Draw();
  
  TH1D *h_numr=(TH1D*)h_data->Clone();
  if(!sepSystStat) h_numr->Divide(h_sum);
  else h_numr->Divide(h_predNoUnc);
  h_numr->SetLineColor(kBlack);
  h_numr->SetMarkerColor(kBlack);
  h_numr->SetTitle(0);
  //  h_numr->GetXaxis()->SetTitle("p_{T}^{miss} [GeV]");
  h_numr->GetXaxis()->SetTitle("Bin index");
  h_numr->GetXaxis()->SetTitleOffset(1.0);
  h_numr->GetXaxis()->SetTitleSize(0.14);
  h_numr->GetXaxis()->SetLabelSize(0.14);
  
  h_numr->GetYaxis()->SetTitle("#frac{Data}{Prediction}");
  h_numr->GetYaxis()->SetTitleOffset(0.36);
  h_numr->GetYaxis()->SetTitleSize(0.12);
  h_numr->GetYaxis()->SetLabelSize(0.14);
  h_numr->GetYaxis()->SetNdivisions(505);
  if((catName.Contains("WHT") || catName.Contains("FBWH")) && !iFname.Contains("PostFit"))
    h_numr->SetMaximum(2.8);
  else h_numr->SetMaximum(1.99);
  h_numr->SetMinimum(0.01);
  c_cA->cd();    p_bot->cd();
  p_bot->SetTickx();p_bot->SetTicky();
  // gPad->RedrawAxis();
  // gPad->Update();
  //    c_cB->cd(i+1);    p_bot->cd();
  h_numr->Draw("x0e1");
  if(sepSystStat){
    h_predRelSyst->Draw("e2 same");
    h_numr->Draw("x0e0 same");
  }
  else h_numr->Draw("x0e0");

  TLine *line1V7=new TLine( 8,0,  8,2);
  TLine *line2V7=new TLine(14,0, 14,2);
  TLine *line3V7=new TLine(19,0, 19,2);
  TLine *line4V7=new TLine(24,0, 24,2);
  TLine *line5V7=new TLine(29,0, 29,2);
  TLine *line6V7=new TLine(34,0, 34,2);
  TLine *line7V7=new TLine(40,0, 40,2);
  TLine *line8V7=new TLine(46,0, 46,2);

  line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
  line4V7->Draw();      line5V7->Draw();
  line6V7->Draw();      line7V7->Draw();
  
  // cout<<h_numr->GetName()<<endl;
  // for(int j=1;j<=h_numr->GetNbinsX();j++){
  //   cout<<h_numr->GetBinContent(j)<<"\t"<<h_numr->GetBinError(j)<<endl;
  // }
  
  TLine *line, *line2;
  line = new TLine(h_numr->GetBinLowEdge(1),1.0, h_numr->GetBinLowEdge(h_numr->GetNbinsX()+1),1);
  
  line->SetLineStyle(3);
  line->Draw();
  line2 = new TLine(h_numr->GetBinLowEdge(1),data_Integral/mc_Integral, h_numr->GetBinLowEdge(h_numr->GetNbinsX()+1),data_Integral/mc_Integral);
  //    line2->SetLineStyle(3);
  line2->SetLineColor(kBlue);
  //    line2->Draw();
 
  c_cA->cd();    p_top->cd(); gPad->RedrawAxis();
  TLatex SRLabel; SRLabel.SetTextSize(0.08);
  //  SRLabel.DrawLatexNDC(0.17,0.75,"b-veto SR");
  if(catName=="WHT" || catName=="FBWH") SRLabel.DrawLatexNDC(0.17,0.75,"WH SR");
  if(catName=="WT" || catName=="FBW") SRLabel.DrawLatexNDC(0.17,0.75,"W SR");
  if(catName=="HT" || catName=="FBH") SRLabel.DrawLatexNDC(0.17,0.75,"H SR");
  if(catName=="wt" || catName=="WtWm1AK8") SRLabel.DrawLatexNDC(0.17,0.75,"W VR");
  if(catName=="ht" || catName=="HtHm1AK8") SRLabel.DrawLatexNDC(0.17,0.75,"H VR");
  
  char name2[100];
  textOnTop.SetTextSize(0.045);
  intLumiE.SetTextSize(0.04);
  //  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Preliminary}}");
  textOnTop.DrawLatexNDC(0.1,0.915,"CMS");
  sprintf(name2,"#bf{%0.0f fb^{-1} (13 TeV)}",intLumi);
  intLumiE.DrawLatexNDC(0.762,0.92,name2);
  if(saveCanvas){
    if(iFname.Contains("PostFit")) {name=catName+year1+"_postFit.pdf";c_cA->SaveAs(name);}
    else {name=catName+year1+".pdf";c_cA->SaveAs(name); name=catName+year1+".png"; c_cA->SaveAs(name);}
  }
  // cout<<"Integral in Data "<<data_Integral<<endl
  //     <<"Integral in MC "<<mc_Integral<<endl
  //     <<"Data/MC "<<data_Integral/mc_Integral<<endl;
  if(printTable){
    TH1D *hz = (TH1D*)f->Get("Zin");
    TH1D *hl = (TH1D*)f->Get("LL");
    TH1D *hf = (TH1D*)f->Get("FR");
    TH1D *hq = (TH1D*)f->Get("QCD");
    TH1D *hT = (TH1D*)f->Get("TotalBG");
    TH1D *hd = (TH1D*)f->Get("DataFit");
    //    TH1D *hS = (TH1D*)fSig[0]->Get(histName);
    //    setLastBinAsOverFlow(hS);
    //////////////////////////////////////////////////

    TH1D *zin = (TH1D*)f->Get("Zin");
    TH1D *ll = (TH1D*)f->Get("LL");
    TH1D *fr = (TH1D*)f->Get("FR");
    TH1D *multi = (TH1D*)f->Get("QCD");
    TH1D *total = (TH1D*)f->Get("TotalBG");

    
    TString METbin[7]={"200 - 300","300 - 370","370 - 450","450 - 600","600 - 750","750 - 900"," >900 "};
    TString METbin2[6]={"200 - 300","300 - 370","370 - 450","450 - 600","600 - 750"," >750 "};
    TString METbin3[5]={"200 - 300","300 - 370","370 - 450","450 - 600"," >600 "};
    
    TString Nbj[8]={ "2 $\\leq N_{jets} \\leq$ 4 , $N_{b-jets}$ = 0 ","5 $\\leq N_{jets} \\leq$ 6 , $N_{b-jets}$ = 0 "," $ N_{jets} \\geq$ 7 , $N_{b-jets}$ = 0 ", "2 $\\leq N_{jets} \\leq$ 4 , $N_{b-jets} > $ 0 ","5 $\\leq N_{jets} \\leq$ 6 , $N_{b-jets} > $ 0 "," $ N_{jets} \\geq$ 7 , $N_{b-jets} > $  0 ","EW : W tag"," EW : H tag"};
    int k=0;
    cout<<"LL | FR | Zin | QCD | Total |  Observation  |  Data/Pred | Pull"<<endl;
    float pull2=0;
    for(int i=0;i<8;i++)
      {
	if(i==0){
	  cout<<"\\multicolumn{7}{|c|}{"<<Nbj[i]<<"} \\ "<<endl;
	  cout<<"\\hline"<<endl;
	  for(int j=0 ; j<7 ; j++)
	    {
	      k=k+1;
	      pull2 = (hd->GetBinContent(k) - total->GetBinContent(k))/sqrt(total->GetBinError(k)*total->GetBinError(k) + hd->GetBinError(k)*hd->GetBinError(k));
	      cout<<setprecision(3)<<METbin[j]<<" & "<<ll->GetBinContent(k)<<" $\\pm$ "<<ll->GetBinError(k)<<" & "<<fr->GetBinContent(k)<<" $\\pm$ "<<fr->GetBinError(k)<<" & "<<zin->GetBinContent(k)<<" $\\pm$ "<<zin->GetBinError(k)<<" & "<<multi->GetBinContent(k)<<" $\\pm$ "<<multi->GetBinError(k)<<" & "<<total->GetBinContent(k)<<" $\\pm$ "<<total->GetBinError(k)<<" & "<<hd->GetBinContent(k)<<" & "<<pull2<<" \\ "<<endl;
	    }
	}
	else if(i==1){
	  cout<<"\\multicolumn{7}{|c|}{"<<Nbj[i]<<"} \\ "<<endl;
	  cout<<"\\hline"<<endl;
	  for(int j=0 ; j<6 ; j++)
	    {
	      k=k+1;
	      pull2 = (hd->GetBinContent(k) - total->GetBinContent(k))/sqrt(total->GetBinError(k)*total->GetBinError(k) + hd->GetBinError(k)*hd->GetBinError(k));
	      cout<<METbin2[j]<<" & "<<ll->GetBinContent(k)<<" $\\pm$ "<<ll->GetBinError(k)<<" & "<<fr->GetBinContent(k)<<" $\\pm$ "<<fr->GetBinError(k)<<" & "<<zin->GetBinContent(k)<<" $\\pm$ "<<zin->GetBinError(k)<<" & "<<multi->GetBinContent(k)<<" $\\pm$ "<<multi->GetBinError(k)<<" & "<<total->GetBinContent(k)<<" $\\pm$ "<<total->GetBinError(k)<<" & "<<hd->GetBinContent(k)<<" & "<<pull2<<" \\ "<<endl;
	    }
	}
	else if(i<6){
	  cout<<"\\multicolumn{7}{|c|}{"<<Nbj[i]<<"} \\ "<<endl;
	  cout<<"\\hline"<<endl;
	  for(int j=0 ; j<5 ; j++)
	    {
	      k=k+1;
              pull2 = (hd->GetBinContent(k) - total->GetBinContent(k))/sqrt(total->GetBinError(k)*total->GetBinError(k) + hd->GetBinError(k)*hd->GetBinError(k));
	      cout<<METbin3[j]<<" & "<<ll->GetBinContent(k)<<" $\\pm$ "<<ll->GetBinError(k)<<" & "<<fr->GetBinContent(k)<<" $\\pm$ "<<fr->GetBinError(k)<<" & "<<zin->GetBinContent(k)<<" $\\pm$ "<<zin->GetBinError(k)<<" & "<<multi->GetBinContent(k)<<" $\\pm$ "<<multi->GetBinError(k)<<" & "<<total->GetBinContent(k)<<" $\\pm$ "<<total->GetBinError(k)<<" & "<<hd->GetBinContent(k)<<" & "<<pull2<<" \\ "<<endl;
	      
	    }
	}
	else{
	  cout<<"\\multicolumn{7}{|c|}{"<<Nbj[i]<<"} \\ "<<endl;
	  cout<<"\\hline"<<endl;
	  for(int j=0 ; j<6 ; j++)
	    {
	      k=k+1;
	      pull2 = (hd->GetBinContent(k) - total->GetBinContent(k))/sqrt(total->GetBinError(k)*total->GetBinError(k) + hd->GetBinError(k)*hd->GetBinError(k));
	      cout<<METbin2[j]<<" & "<<ll->GetBinContent(k)<<" $\\pm$ "<<ll->GetBinError(k)<<" & "<<fr->GetBinContent(k)<<" $\\pm$ "<<fr->GetBinError(k)<<" & "<<zin->GetBinContent(k)<<" $\\pm$ "<<zin->GetBinError(k)<<" & "<<multi->GetBinContent(k)<<" $\\pm$ "<<multi->GetBinError(k)<<" & "<<total->GetBinContent(k)<<" $\\pm$ "<<total->GetBinError(k)<<" & "<<hd->GetBinContent(k)<<" & "<<pull2<<" \\ "<<endl;
	    }
	}
	cout<<"\\hline"<<endl;
      }




    ////////////////////////////////////////////////


    vector<string> binBound = {"$200-250$","$250-300$","$300-350$","$350-400$","$400-450$","$450-500$","$500-600$","$600-800$","$\\geq 800$"};
    //    cout<<"Rare\t\t\t\t\t&\tTop\t\t\t\t\t&\tNonresonant\t\t\t\t\t&\tTotal\t\t\t\t\t&\tData\t&\tPull"<<endl;
    //    cout<<"\\ptmiss  &  Rare  &  Top  &  Nonresonant  &  Total  &  Observation  &  Pull  &  Signal\\\\ \\hline"<<endl;
    cout<<"Bin | Zin | LL | FR | QCD| Total |  Observation  |  Data/Pred | Pull"<<endl;
    for(int b=1;b<=h_histE->GetNbinsX();b++){
      char name3[10000];
      if(hT->GetBinContent(b) > 1e-9){
	float pull = (hd->GetBinContent(b) - hT->GetBinContent(b))/sqrt(hT->GetBinError(b)*hT->GetBinError(b) + hd->GetBinError(b)*hd->GetBinError(b));
	cout<<b<<" | "
	    <<hz->GetBinContent(b)<<" "<<hz->GetBinError(b)<<" | "
	    <<hl->GetBinContent(b)<<" "<<hl->GetBinError(b)<<" | "
	    <<hf->GetBinContent(b)<<" "<<hf->GetBinError(b)<<" | "
	    <<hq->GetBinContent(b)<<" "<<hq->GetBinError(b)<<" | "
	    <<hT->GetBinContent(b)<<" "<<hT->GetBinError(b)<<" | "
	    <<hd->GetBinContent(b)<<" | "
	    <<hd->GetBinContent(b)/hT->GetBinContent(b)<<" | "
	    <<pull<<endl;
      }
      
    

      // cout<<"$\t"<<hr->GetBinContent(b)<<"\t\\pm\t"<<hr->GetBinError(b)<<"\t$\t&\t"
      // 	  <<"$\t"<<ht->GetBinContent(b)<<"\t\\pm\t"<<ht->GetBinError(b)<<"\t$\t&\t"
      // 	  <<"$\t"<<hn->GetBinContent(b)<<"\t\\pm\t"<<hn->GetBinError(b)<<"\t$\t&\t"
      // 	  <<"$\t"<<hT->GetBinContent(b)<<"\t\\pm\t"<<hT->GetBinError(b)<<"\t$\t&\t"
      // 	  <<hd->GetBinContent(b)<<"\t&\t"
      // 	  <<(hd->GetBinContent(b) - hT->GetBinContent(b))/sqrt(hT->GetBinError(b)*hT->GetBinError(b) + hd->GetBinError(b)*hd->GetBinError(b))
      // 	  <<endl;
      ////////////
      //      sprintf(name3,"%s  &  $%0.2f \\pm %0.2f$   &   $%0.2f \\pm %0.2f$   &   $%0.2f \\pm %0.2f$   &   $%0.2f \\pm %0.2f$   &   %0.0f  &   %0.2f  &  $%0.2f \\pm %0.2f$\\\\",binBound[b-1].c_str(),hr->GetBinContent(b),hr->GetBinError(b),ht->GetBinContent(b),ht->GetBinError(b),hn->GetBinContent(b),hn->GetBinError(b),hT->GetBinContent(b),hT->GetBinError(b),hd->GetBinContent(b),pull,hS->GetBinContent(b),hS->GetBinError(b));
      //      cout<<name3<<endl;
    }
    //bhumi
    for(int i=1;i<=45;i++)
      {
	if(i==1 || i==8 || i==14 || i==19 || i==24 || i==29 || i==35 || i==40) continue;
	cout<<hl->GetBinContent(i)<<endl;
      }

  }

}



TString getLegName(TString fname){
  if(fname.Contains("TTJets")) return "t#bar{t}";
  else if(fname.Contains("WJets")) return "W+Jets";
  else if(fname.Contains("ZJets")) return "Z+Jets";
  else if(fname.Contains("Rare")) return "Rare";
  else if(fname.Contains("ST__")) return "Single t";
  else if(fname.Contains("Nonres")) return "0-res";
  else if(fname.Contains("Top")) return "Top";
  else if(fname.Contains("TChiWH_800_100")) return "TChiWH (800, 100)";
  else if(fname.Contains("TChiWZ_800_100")) return "TChiWZ (800, 100)";
  else if(fname.Contains("TChiWW_800_100")) return "TChiWW (800, 100)";
  else if(fname.Contains("TChiWH_900_1")) return "TChiWH (900, 1)";
  else if(fname.Contains("TChiHZ_900_1")) return "TChiHZ (900, 1)";
  else if(fname.Contains("TChiWH_1000_100")) return "TChiWH (1000, 100)";
  else if(fname.Contains("TChiWZ_1000_100")) return "TChiWZ (1000, 100)";  
  else if(fname.Contains("T5bbbbZg_2200_2100")) return "T5bbbbZg (2200, 2100)";
  else if(fname.Contains("T5bbbbZg_2200_200")) return "T5bbbbZg (2200, 200)";
  else if(fname.Contains("T5bbbbZg_2250_200")) return "T5bbbbZg (2250, 200)";
  else if(fname.Contains("T5bbbbZg_2250_1600")) return "T5bbbbZg (2250, 1600)";
  else if(fname.Contains("T5bbbbZg_2250_2150")) return "T5bbbbZg (2250, 2150)";
  else if(fname.Contains("T5qqqqHg_2250_200")) return "T5qqqqHg (2250, 200)";
  else if(fname.Contains("T5qqqqHg_2250_1000")) return "T5qqqqHg (2250, 1000)";
  else if(fname.Contains("T5qqqqHg_2250_2150")) return "T5qqqqHg (2250, 2150)";
  else if(fname.Contains("T5ttttZg_2200_200")) return "T5ttttZg (2200, 200)";
  else if(fname.Contains("T5ttttZg_2200_1000")) return "T5ttttZg (2200, 1000)";
  else if(fname.Contains("T5ttttZg_2200_1900")) return "T5ttttZg (2200, 1900)";
  else if(fname.Contains("T6ttZg_1300_200")) return "T6ttZg (1300, 200)";
  else if(fname.Contains("T6ttZg_1300_600")) return "T6ttZg (1300, 600)";
  else if(fname.Contains("T6ttZg_1300_1200")) return "T6ttZg (1300, 1200)";

  else if(fname.Contains("TChiWG_0_600")) return "TChiWG (0, 600)";
  else if(fname.Contains("TChiWG_0_1000")) return "TChiWG (0, 1000)";
  else if(fname.Contains("TChiWG_0_1200")) return "TChiWG (0, 1200)";
  else if(fname.Contains("TChiNG_0_600")) return "TChiNG (0, 600)";
  else if(fname.Contains("TChiNG_0_1000")) return "TChiNG (0, 1000)";
  else if(fname.Contains("TChiNG_0_1200")) return "TChiNG (0, 1200)";

  else return fname;
}
TString getXaxisName(TString axname){
  if(axname.Contains("NJets")) return "N_{Jets}";
  else if(axname.Contains("HT")) return "HT(GeV)";
  else if(axname.Contains("BTags")) return "b tags";
  else if(axname.Contains("ElePt")) return "e pT(GeV)";
  else if(axname.Contains("MuPt")) return "#mu pT(GeV)";
  else if(axname.Contains("MuEta")) return "#mu #eta";
  else if(axname.Contains("PhotonPt")) return "#gamma pT(GeV)";
  else if(axname.Contains("PhotonEta")) return "#gamma #eta";
  else if(axname.Contains("PhotonPhi")) return "#gamma #Phi";
  else if(axname.Contains("mTLep")) return "mT(l,p_{T}^{miss})(GeV)";
  else if(axname.Contains("dR_MuPho")) return "#DeltaR(#mu,#gamma)";
  else if(axname.Contains("AllSBin")) return "Bin Number";
  else if(axname.Contains("nVtx")) return "No. of primary vertices";
  else if(axname.Contains("dPhi_METjet1") || axname.Contains("dphi1_METjet1")) return "#Delta#Phi_{1}";
  else if(axname.Contains("dPhi_METjet2") || axname.Contains("dphi2_METjet2")) return "#Delta#Phi_{2}";
  else if(axname.Contains("dPhi_METBestPhoton") ) return "#Delta#Phi(MET,#gamma)";
  else if(axname.Contains("dPhi_Muon_Photon") ) return "#Delta#Phi(#mu,#gamma)";
  else if(axname.Contains("QMut") || axname.Contains("Qmut")) return "QMult";
  else if(axname.Contains("MT_Mu")) return "mT(#mu,p_{T}^{miss})(GeV)";
  else if(axname.Contains("METPhi")) return "p_{T}^{miss} #phi";
  else if(axname.Contains("MET")) return "p_{T}^{miss}(GeV)";
  else return axname;

}

void setMyRange(TH1D *h1,double xLow,double xHigh){
  double err=0;
  if(xHigh > 13000) return;
  if(xLow < 13000) return;
  int nMax=h1->FindBin(xHigh);
  h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  h1->SetBinError(nMax,err);
  for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
    h1->SetBinContent(i,0);
    h1->SetBinError(i,0);
  }
  //  h1->GetXaxis()->SetRangeUser(xLow,xHigh);
}
void setMyRange(THStack *h1,double xLow,double xHigh){
  // double err=0;
  // if(xHigh > 13000) return;
  // int nMax=h1->FindBin(xHigh);
  // h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  // h1->SetBinError(nMax,err);
  // for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
  //   h1->SetBinContent(i,0);
  //   h1->SetBinError(i,0);
  // }
  //h1->GetXaxis()->SetRangeUser(xLow,xHigh);
}

void set0PredSmall(TH1D* h, double val){
  double err=1.0;
  for(int i=1;i<=h->GetNbinsX();i++){
    if(h->GetBinContent(i) < 0.000001){
      err = h->GetBinError(i);
      cout<<"************* To make hashed errors visible, setting 0 pred bin "<<i<<" a value of "<<val<<" for hist "<<h->GetName()<<endl;
      h->SetBinContent(i,val);
      h->SetBinError(i,err);
      cout<<h->GetBinContent(i)<<" "<<h->GetBinError(i)<<" | ";
    }
  }
}
void setLastBinAsOverFlow(TH1D* h_hist){
  double lastBinCt =h_hist->GetBinContent(h_hist->GetNbinsX()),overflCt =h_hist->GetBinContent(h_hist->GetNbinsX()+1);
  double lastBinErr=h_hist->GetBinError(h_hist->GetNbinsX()),  overflErr=h_hist->GetBinError(h_hist->GetNbinsX()+1);

  lastBinCt = lastBinCt+overflCt;
  lastBinErr = sqrt( (lastBinErr*lastBinErr) + (overflErr*overflErr) );
  
  h_hist->SetBinContent(h_hist->GetNbinsX(),lastBinCt);
  h_hist->SetBinError(h_hist->GetNbinsX(),lastBinErr);
    
}
