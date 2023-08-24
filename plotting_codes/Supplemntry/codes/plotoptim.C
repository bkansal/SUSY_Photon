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
void plotoptim(TString varName="AllSBins_v6_CD_EW_50bin", TString sample="T5bbbbZg")
{
  int nfiles=12;
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
  else if( varName.Contains("nJets")){xLabel = "N_{ jets}";   rebin=1; yMin=0.1,yMax = 5000; xMin=1,xMax = 14;}
  else if( varName.Contains("hadAk8Mass")){xLabel = "Mass_{Leading Ak8Jet} (GeV)";  rebin=20,yMin=0.1,yMax = 5000;xMin=0,xMax = 300;}
  if( varName.Contains("AllSBins_v6_CD_EW_50bin")) path="rootoutput/nphotons/";
  else path="../rootoutput/nphotons/";
  //  else path="../rootoutput/rootfiles_MCcutflow_MET300/";
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
  else path="rootoutput/nphotons/";
  if(sample.Contains("T5bbbbZg"))
    {
      fname=path+"T5bbbbZg_2250_200_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"T5bbbbZg_2250_1600_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"T5bbbbZg_2250_2100_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"T5qqqqHg_2250_200_FastSim_v18.root"; f[9]  = new TFile(fname);
      fname=path+"T5qqqqHg_2250_1600_FastSim_v18.root"; f[10] = new TFile(fname);
      fname=path+"T5qqqqHg_2250_2150_FastSim_v18.root"; f[11] = new TFile(fname);
    }
  else if(sample.Contains("T5ttttZg"))
    {
      fname=path+"T5ttttZg_2200_200_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"T5ttttZg_2200_1000_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"T5ttttZg_2200_1975_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"T6ttZg_1300_200_FastSim_v18.root"; f[9]  = new TFile(fname);
      fname=path+"T6ttZg_1300_600_FastSim_v18.root"; f[10] = new TFile(fname);
      fname=path+"T6ttZg_1300_1200_FastSim_v18.root"; f[11] = new TFile(fname);
    }
  else if(sample.Contains("TChiWg"))
    {
      fname=path+"TChiWG_0_600_FastSim_v18.root"; f[6]  = new TFile(fname);
      fname=path+"TChiWg_0_1000_FastSim_v18.root"; f[7] = new TFile(fname);
      fname=path+"TChiWg_0_1200_FastSim_v18.root"; f[8] = new TFile(fname);
      fname=path+"TChiNG_0_600_FastSim_v18.root"; f[9]  = new TFile(fname);
      fname=path+"TChiNG_0_1000_FastSim_v18.root"; f[10] = new TFile(fname);
      fname=path+"TChiNG_0_1200_FastSim_v18.root"; f[11] = new TFile(fname);
    }

  

  //  TCanvas *c1= new TCanvas("stackhist","stackhist",1600,1000);  
  TCanvas *c1= new TCanvas("stackhist","stackhist",1000,700);
  c1->cd();
  //  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  //  pad1->SetBottomMargin(0.6);
  TPad *pad1 = new TPad("pad1","pad1",0,0.6,1,0.9);
  pad1->SetBottomMargin (0);
  pad1->Draw();pad1->SetGridx(0);
  pad1->cd();
  pad1->SetLogy();

  THStack *hs_var=new THStack("var_Stack","MET Stacked");
  TLegend *legend=new TLegend(0.15,0.75,0.89,0.885);
  legend->SetNColumns(6);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetTextSize(0.09);
  for(int i=0;i<(nfiles-6);i++)
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
  hs_var->SetMaximum(yMax*100);
  hs_var->SetTitle(0);
  hs_var->GetYaxis()->SetTitle("Events / Bin");
  hs_var->GetYaxis()->SetTitleSize(0.11);
  hs_var->GetYaxis()->SetTitleOffset(0.35);
  hs_var->GetYaxis()->SetLabelSize(0.09);
  hs_var->GetXaxis()->SetRangeUser(xMin,xMax+0.1);
  hs_var->Draw("hist");
  legend->Draw();
  if(varName=="AllSBins_v6_CD_EW_50bin"){
    hs_var->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,46.5);
    TGaxis *A2 = new TGaxis(1,yMin-0.365,46,yMin-0.365,"f2_",45,"US");
    A2->SetTickSize(0.03);
    A2->Draw("B");
  }
  //////////////////
  double yset_=3.5;
  TLine *line1V6=new TLine( 8,yMin-0.365,  8,3000*yset_);
  TLine *line2V6=new TLine(14,yMin-0.365, 14,3000*yset_);
  TLine *line3V6=new TLine(19,yMin-0.365, 19,3000*yset_);
  TLine *line4V6=new TLine(24,yMin-0.365, 24,3000*yset_);
  TLine *line5V6=new TLine(29,yMin-0.365, 29,3000*yset_);
  TLine *line6V6=new TLine(34,yMin-0.365, 34,3000*yset_);
  TLine *line7V6=new TLine(40,yMin-0.365, 40,3000*yset_);
  TLine *line8V6=new TLine(46,yMin-0.365, 46,3000*yset_);

  line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
  line4V6->Draw();      line5V6->Draw();
  line6V6->Draw();      line7V6->Draw();
  TArrow *arrow1 = new TArrow( 1,yset_*700, 8,yset_*700,0.01,"<|>");
  TArrow *arrow2 = new TArrow( 8,yset_*700,14,yset_*700,0.01,"<|>");
  TArrow *arrow3 = new TArrow(14,yset_*700, 19,yset_*700,0.01,"<|>");
  TArrow *arrow4 = new TArrow(19,yset_*700, 24,yset_*700,0.01,"<|>");
  TArrow *arrow5 = new TArrow(24,yset_*700, 29,yset_*700,0.01,"<|>");
  TArrow *arrow6 = new TArrow(29,yset_*700, 34,yset_*700,0.01,"<|>");
  TArrow *arrow7 = new TArrow(34,yset_*700, 40,yset_*700,0.01,"<|>");
  TArrow *arrow8 = new TArrow(40,yset_*700, 46,yset_*700,0.01,"<|>");

  arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
  arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
  arrow7->Draw(); arrow8->Draw();

  TLatex Tl;
  Tl.SetTextSize(0.08);
  Tl.DrawLatex(3.8,1300*yset_,"N^{ 0}_{ 2-4}");
  Tl.DrawLatex(10.0,1300*yset_,"N^{ 0}_{ 5-6}");
  Tl.DrawLatex(15.5,1300*yset_,"N^{ 0}_{ #geq7}");
  Tl.DrawLatex(20.5,1300*yset_,"N^{ #geq1}_{ 2-4}");
  Tl.DrawLatex(25.5,1300*yset_,"N^{ #geq1}_{ 5-6}");
  Tl.DrawLatex(30.5,1300*yset_,"N^{ #geq1}_{ #geq7}");
  Tl.SetTextSize(0.08);
  Tl.DrawLatex(35.5,1300*yset_,"V tag");
  Tl.DrawLatex(41.5,1300*yset_,"H tag");


  ////////////////
  textOnTop.SetTextSize(0.108);
  intLumiE.SetTextSize(0.095);
  textOnTop2.SetTextSize(0.095);
  textOnTop.DrawLatexNDC(0.1,0.925,"CMS");
  textOnTop2.DrawLatexNDC(0.142,0.93," #it{#bf{Simulation Supplementary}}");
  intLumiE.DrawLatexNDC(0.76,0.93,"#bf{137 fb^{-1} (13 TeV)}");
  
  c1->cd();
  TPad *pad2 = new TPad("pad2","pad2",0,0.33,1,0.6);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0); 
  pad2->Draw();pad2->SetGridx(0);
  pad2->cd();
  pad2->SetLogy();

  THStack *hs_var2=new THStack("var_Stack","MET Stacked");
  TLegend *legend2=new TLegend(0.12,0.87,0.895,0.97);
  legend2->SetNColumns(6);
  legend2->SetBorderSize(0);
  legend2->SetFillColor(0);
  legend2->SetTextSize(0.092);
  //  legend2->SetLineSize(0.09);

  for(int i=0;i<(nfiles-6);i++)
    {
      h1[i]=(TH1D*)f[i]->FindObjectAny(varName);
      //      h1[i]->Rebin(rebin);
      //      h1[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      h1[i]->SetLineColor(kGray);
      h1[i]->SetFillColor(kGray);
      setLastBinAsOverFlow(h1[i]);
      h1[i] = setMyRange(h1[i],xMin,xMax);
      hs_var2->Add(h1[i]);
    }
  legend2->AddEntry(h1[0],"Background","f");
  hs_var2->Draw("hist");
  hs_var2->SetTitle(0);
  hs_var2->SetMinimum(yMin);
  hs_var2->SetMaximum(yMax);
  hs_var2->GetYaxis()->SetLabelSize(0.10);
  hs_var2->GetYaxis()->SetTitle("Events / Bin");
  hs_var2->GetYaxis()->SetTitleSize(0.13);
  hs_var2->GetYaxis()->SetTitleOffset(0.28);
  hs_var2->GetXaxis()->SetRangeUser(xMin,xMax+0.1);
  hs_var2->Draw("hist");
  for(int i=nfiles-6;i<(nfiles-3);i++)
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
  if(varName=="AllSBins_v6_CD_EW_50bin"){
    hs_var2->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,46.5);
    TGaxis *A2 = new TGaxis(1,yMin-0.325,46,yMin-0.325,"f2_",45,"US");
    A2->SetTickSize(0.03);
    A2->Draw("B");
  }
   yset_=0.4;
  TLine *line1V1=new TLine( 8,yMin-0.325,  8,1000*yset_);
  TLine *line2V1=new TLine(14,yMin-0.325, 14,1000*yset_);
  TLine *line3V1=new TLine(19,yMin-0.325, 19,1000*yset_);
  TLine *line4V1=new TLine(24,yMin-0.325, 24,1000*yset_);
  TLine *line5V1=new TLine(29,yMin-0.325, 29,1000*yset_);
  TLine *line6V1=new TLine(34,yMin-0.325, 34,1000*yset_);
  TLine *line7V1=new TLine(40,yMin-0.325, 40,1000*yset_);
  TLine *line8V1=new TLine(46,yMin-0.325, 46,1000*yset_);

  line1V1->Draw();      line2V1->Draw();  line3V1->Draw();
  line4V1->Draw();      line5V1->Draw();
  line6V1->Draw();      line7V1->Draw();

  c1->cd();
  TPad *pad3 = new TPad("pad3","pad3",0,0,1,0.33); 
  pad3->SetTopMargin(0);
  pad3->SetBottomMargin(0.2);
  pad3->Draw();pad3->SetGridx(0);
  pad3->cd();
  pad3->SetLogy();
  THStack *hs_var3=new THStack("var_Stack","MET Stacked");
  //  TLegend *legend3=new TLegend(0.14,0.87,0.899,0.97);
  TLegend *legend3=new TLegend(0.12,0.87,0.895,0.97);
  legend3->SetNColumns(6);
  legend3->SetBorderSize(0);
  legend3->SetFillColor(0);
  legend3->SetTextSize(0.075);
  //  legend3->SetTextAlign(32);
  for(int i=0;i<(nfiles-6);i++)
    {
      h2[i]=(TH1D*)f[i]->FindObjectAny(varName);
      //   h2[i]->Rebin(rebin);
      //h2[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      h2[i]->SetLineColor(kGray);
      h2[i]->SetFillColor(kGray);
      setLastBinAsOverFlow(h2[i]);
      h2[i] = setMyRange(h2[i],xMin,xMax);
      hs_var3->Add(h2[i]);
    }
  legend3->AddEntry(h2[0],"Background","f");

  hs_var3->Draw("hist");
  hs_var3->SetTitle(0);
  hs_var3->SetMinimum(yMin);
  hs_var3->SetMaximum(yMax);
  hs_var3->GetYaxis()->SetLabelSize(0.08);
  hs_var3->GetXaxis()->SetLabelSize(0.08);
  hs_var3->GetXaxis()->SetTitle(xLabel);
  hs_var3->GetXaxis()->SetTitleOffset(0.92);
  hs_var3->GetXaxis()->SetTitleSize(0.10);
  hs_var3->GetYaxis()->SetTitle("Events / Bin");
  hs_var3->GetYaxis()->SetTitleSize(0.11);
  hs_var3->GetYaxis()->SetTitleOffset(0.31);

  hs_var3->GetXaxis()->SetRangeUser(xMin,xMax+0.1);
  hs_var3->Draw("hist");
  for(int i=nfiles-3;i<(nfiles);i++)
    {
      h2[i]=(TH1D*)f[i]->FindObjectAny(varName);
      h2[i]->Rebin(rebin);
      //      h2[i]->GetXaxis()->SetRangeUser(xMin,xMax);
      setLastBinAsOverFlow(h2[i]);
      h2[i] = setMyRange(h2[i],xMin,xMax);
      h2[i]->SetLineColor(col[i-3]);
      h2[i]->SetLineWidth(2);
      h2[i]->Draw("hist sames");
      h2[i]->SetMinimum(yMin);
      h2[i]->SetMaximum(20);
      legend3->AddEntry(h2[i],getLegName(f[i]->GetName()),"l");

    }
  legend3->Draw();
  //  decorate(hs_var,i,f[i]->GetName());


  TString temp2;

  if(varName=="AllSBins_v6_CD_EW_50bin"){
    hs_var3->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,46.5);
    TGaxis *A2 = new TGaxis(1,yMin-0.325,46,yMin-0.325,"f2_",45,"US");
    A2->SetTickSize(0.03);
    A2->Draw("B");

    for(double j=1;j<=h2[0]->GetNbinsX();j++){
      temp2 = to_string(j-1);
      if((j-1)==5){temp2=to_string(5); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==10){temp2=to_string(10); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==15){temp2=to_string(15); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==20){temp2=to_string(20); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==25){temp2=to_string(25); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==30){temp2=to_string(30); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==35){temp2=to_string(35); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==40){temp2=to_string(40); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==45){temp2=to_string(45); hs_var3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
    }
    
    hs_var3->GetXaxis()->LabelsOption("h");
    hs_var3->GetXaxis()->SetLabelOffset(0.01);
    hs_var3->GetXaxis()->SetLabelSize(0.12);

    hs_var3->GetXaxis()->SetTitle("Bin index");
    hs_var3->GetXaxis()->SetTitleOffset(0.92);
    hs_var3->GetXaxis()->SetTitleSize(0.10);
    line1V1->Draw();      line2V1->Draw();  line3V1->Draw();
    line4V1->Draw();      line5V1->Draw();
    line6V1->Draw();      line7V1->Draw();

  }

  //  c1->SetCanvasSize(1600,800);
  TString png,pdf;
  if(sample.Contains("T5bbbbZg")){
    png="png/Optimization_"+varName+"_T5bbbbZg_T5qqqqHg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1000,700); 
    //    c1->SetCanvasSize(1600,1000);
    pdf="pdf/Optimization_"+varName+"_T5bbbbZg_T5qqqqHg.pdf";
    c1->SaveAs(pdf);
  }
  if(sample.Contains("T5ttttZg")){
    png="png/Optimization_"+varName+"_T5ttttZg_T6ttZg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1000,700);
    pdf="pdf/Optimization_"+varName+"_T5ttttZg_T6ttZg.pdf";
    c1->SaveAs(pdf);
  }

  if(sample.Contains("TChiWg")){
    png="png/Optimization_"+varName+"_TChiWg_TChiNg.png";
    c1->SaveAs(png);
    c1->SetCanvasSize(1000,700);
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

