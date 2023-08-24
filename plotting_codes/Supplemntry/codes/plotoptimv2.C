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
vector<int> col={kCyan,kOrange,kTeal+9,kCyan-1,kGray,kRed,kBlue,kMagenta+3,kPink+10,kOrange+7,kBlack,kMagenta};

TString getLegName(TString);
void setLastBinAsOverFlow(TH1D*);
void decorate(TH1D*,int,const char*);
TH1D* setMyRange(TH1D*,double,double);
void plotoptimv2(TString varName="hadAk8Mass", TString sample="default")
{
  int nfiles=10;
  gStyle->SetOptStat(0);
  gStyle->SetTitle(0);
  double yMin=0.1,yMax = 1000;
  double xMin=0.0,xMax = 2000;
  int rebin;
  TString xLabel;
  TLatex textOnTop,intLumiE, textOnTop2;

  TH1D *h[nfiles],*h1[nfiles],*h2[nfiles],*h_[6];

  TFile *f[nfiles] , *f_[6];
  TString path;
  vector<TString> name3;
  name3.push_back("Multijet + #gamma");
  name3.push_back("Z(#nu#bar{#nu}) + #gamma");
  name3.push_back("t#bar{t} + #gamma");
  name3.push_back("W(l#nu) + #gamma");
  name3.push_back("t#bar{t} + jets");
  name3.push_back("W(l#nu) + jets");


  if( varName.Contains("AllSBins_v6_CD_EW_50bin")){ xLabel = "Bin index";  rebin=1; yMin=0.5,yMax = 2000; xMin=1,xMax =45;}
  else if( varName.Contains("MET")){xLabel = "p_{T}^{miss} (GeV)";   rebin=5; yMin=0.1,yMax = 10000; xMin=100.0,xMax = 1500;}
  else if( varName.Contains("nJets")){xLabel = "N_{ jets}";   rebin=1; yMin=0.1,yMax = 3000; xMin=2,xMax = 12;}
  else if( varName.Contains("hadAk8Mass")){xLabel = "m_{J} (GeV)";  rebin=25,yMin=0.1,yMax = 1000;xMin=0,xMax = 290;}
  if( varName.Contains("AllSBins_v6_CD_EW_50bin")) path="rootoutput/nphotons/";
  //  else path="../rootoutput/nphotons/";
  //  else path="../rootoutput/rootfiles_MCcutflow_MET300/";
  path="rootoutput/nphotons/";
  TString fname=path+"TTGJets_v18.root";
  fname=path+"GJetsQCD_new_v18.root";
  f[0] = new TFile(fname);
  f_[0] = new TFile(fname);
  fname=path+"ZGZJ_NuNuG_v18.root";
  f[1] = new TFile(fname);//ZGJetsToNuNuG_2018_v17.root                                                                                                               
  f_[1] = new TFile(fname);
  //  fname=path+"TTJetsHT_v18.root";
  fname=path+"TTGJets_v18.root";
  f[2] = new TFile(fname);
  f_[2] = new TFile(fname);
  //  fname=path+"WJetsToLNu_v18.root";
  fname=path+"WGJetsToLNuG_v18.root";
  f[3] = new TFile(fname);
  f_[3] = new TFile(fname);
  //  fname=path+"TTGJets_v18.root";
  fname=path+"TTJetsHT_v18.root";    
  f[4] = new TFile(fname);
  f_[4] = new TFile(fname);
  //  fname=path+"WGJetsToLNuG_v18.root";
  fname=path+"WJetsToLNu_v18.root";
  f[5] = new TFile(fname);
  f_[5] = new TFile(fname);
  col.resize(0);
  //col={kCyan,kOrange,kTeal+9,kCyan-1,kGray,kRed,kBlue,kMagenta+3,kPink+10,kOrange+7,kBlack,kMagenta};
  col={kCyan,kOrange,kGray,kRed,kTeal+9,kCyan-1,kBlue,kMagenta+3,kPink+10,kOrange+7,kBlack,kMagenta};
  if( varName.Contains("AllSBins_v6_CD_EW_50bin") || varName.Contains("nPhotons"))path="rootoutput/nphotons/";
  else path="../rootoutput/nphotons/";

  path="rootoutput/nphotons/";
  if(sample.Contains("T5bbbbZg"))
    {
      fname=path+"T5bbbbZg_2250_200_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"T5bbbbZg_2250_1600_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"T5bbbbZg_2250_2100_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"T5qqqqHg_2250_200_FastSim_v18.root"; f[9]  = new TFile(fname);
      //      fname=path+"T5qqqqHg_2250_1600_FastSim_v18.root"; f[10] = new TFile(fname);
      //      fname=path+"T5qqqqHg_2250_2150_FastSim_v18.root"; f[11] = new TFile(fname);
    }
  else if(sample.Contains("T5ttttZg"))
    {
      fname=path+"T5ttttZg_2200_200_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"T5ttttZg_2200_1000_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"T5ttttZg_2200_1975_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"T6ttZg_1300_200_FastSim_v18.root"; f[9]  = new TFile(fname);
      //      fname=path+"T6ttZg_1300_600_FastSim_v18.root"; f[10] = new TFile(fname);
      // fname=path+"T6ttZg_1300_1200_FastSim_v18.root"; f[11] = new TFile(fname);
    }
  else if(sample.Contains("TChiWg"))
    {
      fname=path+"TChiWG_0_600_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"TChiWg_0_1000_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"TChiWg_0_1200_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"TChiNG_0_600_FastSim_v18.root"; f[9]  = new TFile(fname);
      //      fname=path+"TChiNG_0_1000_FastSim_v18.root"; f[10] = new TFile(fname);
      //      fname=path+"TChiNG_0_1200_FastSim_v18.root"; f[11] = new TFile(fname);
    }
  else{
      fname=path+"T5bbbbZg_2250_200_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"T5bbbbZg_2250_2100_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"TChiWg_0_1000_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"TChiNG_0_1000_FastSim_v18.root"; f[9] = new TFile(fname);
  }
  

  TCanvas *c1= new TCanvas("stackhist","stackhist",1000,900);  
  c1->cd();
  //  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  //  pad1->SetBottomMargin(0.6);
  TPad *pad1 = new TPad("pad1","pad1",0,0.45,1,0.9);
  pad1->SetBottomMargin (0);
  pad1->Draw();pad1->SetGridx(0);
  pad1->cd();
  pad1->SetLogy();

  THStack *hs_var=new THStack("var_Stack","MET Stacked");
  TLegend *legend=new TLegend(0.13,0.79,0.899,0.885);
  legend->SetNColumns(6);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetTextSize(0.06);
  for(int i=0;i<(nfiles-4);i++)
    {
      h_[i]=(TH1D*)f_[i]->FindObjectAny(varName);
      decorate(h_[i],i,f_[i]->GetName());
      h[i]=(TH1D*)f[i]->FindObjectAny(varName);
      h[i]->Rebin(rebin);
      //      h[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      decorate(h[i],i,f[i]->GetName());
      h[i] = setMyRange(h[i],xMin,xMax);
      hs_var->Add(h[i]);
      //      h[i]->SetLineColor(col[i]);

      legend->AddEntry(h_[i],name3[i],"f");
    }
  hs_var->Draw("hist");
  hs_var->SetMinimum(yMin);
  hs_var->SetMaximum(yMax);
  hs_var->SetTitle(0);
  hs_var->GetYaxis()->SetTitle("Events / Bin");
  hs_var->GetYaxis()->SetTitleSize(0.08);
  hs_var->GetYaxis()->SetTitleOffset(0.62);
  hs_var->GetYaxis()->SetLabelSize(0.07);
  hs_var->GetXaxis()->SetRangeUser(xMin,xMax+0.1);
  hs_var->Draw("hist");
  legend->Draw();

  ////////////////
  textOnTop.SetTextSize(0.08);
  intLumiE.SetTextSize(0.065);
  textOnTop2.SetTextSize(0.065);
  textOnTop.DrawLatexNDC(0.1,0.925,"CMS");
  textOnTop2.DrawLatexNDC(0.165,0.93," #it{#bf{Simulation Supplementary}}");
  intLumiE.DrawLatexNDC(0.716,0.93,"#bf{137 fb^{-1} (13 TeV)}");
  
  c1->cd();
  TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.45);
  pad2->SetTopMargin(0);
  //pad2->SetBottomMargin(0); 
  pad2->SetBottomMargin(0.2);

  pad2->Draw();pad2->SetGridx(0);
  pad2->cd();
  pad2->SetLogy();

  THStack *hs_var2=new THStack("var_Stack","MET Stacked");
  TLegend *legend3=new TLegend(0.12,0.87,0.299,0.97);
  legend3->SetBorderSize(0);
  legend3->SetFillColor(0);
  legend3->SetTextSize(0.06);

  TLegend *legend2=new TLegend(0.30,0.79,0.899,0.97);
  legend2->SetNColumns(2);
  legend2->SetBorderSize(0);
  legend2->SetFillColor(0);
  legend2->SetTextSize(0.056);

  for(int i=0;i<(nfiles-4);i++)
    {
      h1[i]=(TH1D*)f[i]->FindObjectAny(varName);
      cout<<"file Name = "<<f[i]->GetName()<<endl;
      h1[i]->Print("all");
      //      h1[i]->Rebin(rebin);
      //      h1[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      h1[i]->SetLineColor(kGray);
      h1[i]->SetFillColor(kGray);
      setLastBinAsOverFlow(h1[i]);
      h1[i] = setMyRange(h1[i],xMin,xMax);
      hs_var2->Add(h1[i]);
    }
  legend3->AddEntry(h1[0],"Background","f");
  hs_var2->Draw("hist");
  hs_var2->SetTitle(0);
  hs_var2->SetMinimum(yMin);
  hs_var2->SetMaximum(yMax);
  hs_var2->GetYaxis()->SetLabelSize(0.07);
  hs_var2->GetYaxis()->SetTitle("Events / Bin");
  hs_var2->GetYaxis()->SetTitleSize(0.08);
  hs_var2->GetYaxis()->SetTitleOffset(0.60);

  hs_var2->GetXaxis()->SetRangeUser(xMin,xMax+0.1);
  hs_var2->Draw("hist");
  for(int i=nfiles-4;i<(nfiles);i++)
    {
      h1[i]=(TH1D*)f[i]->FindObjectAny(varName);
      h1[i]->Rebin(rebin);
      //      h1[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      //      decorate(h1[i],i,f[i]->GetName());
      setLastBinAsOverFlow(h1[i]);
      h1[i] = setMyRange(h1[i],xMin,xMax);
      h1[i]->SetLineColor(col[i]);
      h1[i]->SetLineWidth(2);
      h1[i]->Draw("hist sames");
      h1[i]->SetMinimum(yMin);
      h1[i]->SetMaximum(20);
      legend2->AddEntry(h1[i],getLegName(f[i]->GetName()),"l");

    }
  legend2->Draw();
  legend3->Draw();

  hs_var2->GetXaxis()->SetLabelOffset(0.01);
  hs_var2->GetXaxis()->SetLabelSize(0.07);
  hs_var2->GetXaxis()->SetTitle(xLabel);
  hs_var2->GetXaxis()->SetTitleOffset(1.25);
  hs_var2->GetXaxis()->SetTitleSize(0.07);

  if(varName.Contains("hadAk8Mass")){
    TLine *line1=new TLine( 65,yMin*0.3,  65,yMax*0.1);
    TLine *line2=new TLine( 105,yMin*0.3,  105,yMax*0.1);
    TLine *line3=new TLine( 145,yMin*0.3,  145,yMax*0.1);
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line1->SetLineStyle(2);
    line2->SetLineStyle(2);
    line3->SetLineStyle(2);
    TArrow *arrow1 = new TArrow(65,30,105,30,0.01,"<|>");
    arrow1->Draw();
    TArrow *arrow2 = new TArrow(105,30,145,30,0.01,"<|>");
    arrow2->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.055);
    Tl.DrawLatex(78.5,38,"#bf{V tag}");
    Tl.DrawLatex(118.5,38,"#bf{H tag}");

  }

  
  //  c1->SetCanvasSize(1600,800);
  TString png,pdf;
  if(sample.Contains("T5bbbbZg")){
    png="png/Optimization_"+varName+"_T5bbbbZg_T5qqqqHg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1600,1000); 
    pdf="pdf/Optimization_"+varName+"_T5bbbbZg_T5qqqqHg.pdf";
    c1->SaveAs(pdf);
  }
  else if(sample.Contains("T5ttttZg")){
    png="png/Optimization_"+varName+"_T5ttttZg_T6ttZg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1600,1000);
    pdf="pdf/Optimization_"+varName+"_T5ttttZg_T6ttZg.pdf";
    c1->SaveAs(pdf);
  }

  else if(sample.Contains("TChiWg")){
    png="png/Optimization_"+varName+"_TChiWg_TChiNg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1600,1000);
    pdf="pdf/Optimization_"+varName+"_TChiWg_TChiNg.pdf";
    c1->SaveAs(pdf);
  }
  else{
    png="png/Optimization_"+varName+"_TChiWg_TChiNg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1000,900);
    pdf="pdf/Optimization_"+varName+"_TChiWg_TChiNg.pdf";
    c1->SaveAs(pdf);

  }
}



void decorate(TH1D* hist,int i,const char* fname){
  hist->SetLineColor(col[i]);
  hist->SetFillColor(col[i]);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(1);
  setLastBinAsOverFlow(hist);
}

void setLastBinAsOverFlow(TH1D* h_hist){
  double lastBinCt =h_hist->GetBinContent(h_hist->GetNbinsX()),overflCt =h_hist->GetBinContent(h_hist->GetNbinsX()+1);
  double lastBinErr=h_hist->GetBinError(h_hist->GetNbinsX()),  overflErr=h_hist->GetBinError(h_hist->GetNbinsX()+1);

  if(lastBinCt!=0 && overflCt!=0)
    lastBinErr = (lastBinCt+overflCt)* (sqrt( ((lastBinErr/lastBinCt)*(lastBinErr/lastBinCt)) + ((overflErr/overflCt)*(overflErr/overflCt)) ) );

  else if(lastBinCt==0 && overflCt!=0)
    lastBinErr = overflErr;
  else if(lastBinCt!=0 && overflCt==0)
    lastBinErr = lastBinErr;
  else lastBinErr=0;

  lastBinCt = lastBinCt+overflCt;
  h_hist->SetBinContent(h_hist->GetNbinsX(),lastBinCt);
  h_hist->SetBinError(h_hist->GetNbinsX(),lastBinErr);
}

TH1D* setMyRange(TH1D *h1,double xLow,double xHigh){
  //call it after setting last bin as overflow
  double err=0;
  if(xHigh > 13000) return h1;
  if(xLow < -13000) return h1;
  int nMax=h1->FindBin(xHigh);
  h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  h1->SetBinError(nMax,err);
  for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
    h1->SetBinContent(i,0);
    h1->SetBinError(i,0);
  }
  return h1;
}


TString getLegName(TString fname){
  if(fname.Contains("TTJets")) return "t#bar{t}";
  else if(fname.Contains("WJets")) return "W + Jets";
  else if(fname.Contains("ZJets")) return "Z + Jets";
  else if(fname.Contains("T5bbbbZg_2200_2100")) return "T5bbbbZg (2200, 2100)";
  else if(fname.Contains("T5bbbbZg_2200_200")) return "T5bbbbZg (2200, 200)";
  else if(fname.Contains("T5bbbbZg_2250_200")) return "T5bbbbZg (2250, 200)";
  else if(fname.Contains("T5bbbbZg_2250_1600")) return "T5bbbbZg (2250, 1600)";
  else if(fname.Contains("T5bbbbZg_2250_2150")) return "T5bbbbZg (2250, 2150)";
  else if(fname.Contains("T5bbbbZg_2250_2100")) return "T5bbbbZg (2250, 2100)";
  else if(fname.Contains("T5qqqqHg_2250_200")) return "T5qqqqHg (2250, 200)";
  else if(fname.Contains("T5qqqqHg_2250_1000")) return "T5qqqqHg (2250, 1000)";
  else if(fname.Contains("T5qqqqHg_2250_1600")) return "T5qqqqHg (2250, 1600)";
  else if(fname.Contains("T5qqqqHg_2250_2150")) return "T5qqqqHg (2250, 2150)";
  else if(fname.Contains("T5ttttZg_2200_200")) return "T5ttttZg (2200, 200)";
  else if(fname.Contains("T5ttttZg_2200_1000")) return "T5ttttZg (2200, 1000)";
  else if(fname.Contains("T5ttttZg_2200_1975")) return "T5ttttZg (2200, 1975)";
  else if(fname.Contains("T6ttZg_1300_200")) return "T6ttZg (1300, 200)";
  else if(fname.Contains("T6ttZg_1300_600")) return "T6ttZg (1300, 600)";
  else if(fname.Contains("T6ttZg_1300_1200")) return "T6ttZg (1300, 1200)";

  else if(fname.Contains("TChiWG_0_600")) return "TChiWG (600)";
  else if(fname.Contains("TChiWG_0_1000")) return "TChiWG (1000)";
  else if(fname.Contains("TChiWG_0_1200")) return "TChiWG (1200)";
  else if(fname.Contains("TChiWg_0_600")) return "TChiWG (600)";
  else if(fname.Contains("TChiWg_0_1000")) return "TChiWG (1000)";
  else if(fname.Contains("TChiWg_0_1200")) return "TChiWG (1200)";
  else if(fname.Contains("TChiNG_0_600")) return "TChiNG (600)";
  else if(fname.Contains("TChiNG_0_1000")) return "TChiNG (1000)";
  else if(fname.Contains("TChiNG_0_1200")) return "TChiNG (1200)";
  else if(fname.Contains("TChiNGnn_0_500")) return "TChiNGnn (500)";
  else if(fname.Contains("TChiNGnn_0_600")) return "TChiNGnn (600)";
  else if(fname.Contains("TChiNGnn_0_700")) return "TChiNGnn (700)";

  else return fname;
}

