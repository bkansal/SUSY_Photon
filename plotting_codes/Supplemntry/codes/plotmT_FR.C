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

vector<int> col={kGray,kCyan-1,kTeal+9,kOrange,kRed,kBlack};
void setLastBinAsOverFlow(TH1D*);
void decorate(TH1D*,int,const char*);
TH1D* setMyRange(TH1D*,double,double);

void plotmT_FR(TString varName="mTPhoMET")
{
 
  TFile *f1, *f2,*f3, *f_0,*f_1,*f_2,*f_3,*f_4,*f_5,*f_6,*f_7;
  TString path,path1,varname1;
  path="rootoutput/nomtcut/";
  
  TLatex textOnTop,textOnTop2,intLumiE;
  TString filename,filename2,filename3,filename4,filename5,filename6,filename7,filename8,filename9,filename10;
  filename2= path+"TTWGJ_CR_v18.root";
  filename3= path+"TTGJets_CR_v18.root";
  filename4= path+"WGJets_CR_v18.root";
  filename5= path+"TTJets_CR_v18.root";
  filename6= path+"WJets_CR_v18.root";
  filename7= path+"ST_CR_v18.root";
  filename8=path+"T5bbbbZg_2200_200_v18.root";
  filename9=path+"T5bbbbZg_2200_1000_v18.root";
  filename10=path+"T5bbbbZg_2200_2100_v18.root";

  f2 = new TFile(filename2);
  f_0 =new TFile(filename3);
  f_1 =new TFile(filename4);
  f_2 =new TFile(filename5);
  f_3 =new TFile(filename6);
  f_4 =new TFile(filename7);
  f_5 =new TFile(filename8);
  f_6 =new TFile(filename9);
  f_7 =new TFile(filename10);

  
  double xmin,xmax,bin,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000;

  TH1D *cr,*sr,*tf,*pred_sr,*h_0,*h_1,*h_2,*h_3,*h_4,*sig1,*sig2,*sig3;
  THStack *hs_var=new THStack("var_Stack",varName);
 
  TString title;

  TString png,pdf;

  png="png/FR_"+varName+"_datavsMC.png";
  pdf="pdf/FR_"+varName+"_datavsMC.pdf";


  TCanvas *c1;
  TString varName1,varName2;

  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  cout<<"varName2 : "<<varName<<endl;
  c1 = new TCanvas("stackhist","stackhist",1600,900);
  c1->cd(); gPad->SetLogy();
  sr     = (TH1D*)f2->Get(varName);
  h_0=(TH1D*)f_0->FindObjectAny(varName);
  h_1=(TH1D*)f_1->FindObjectAny(varName);
  h_2=(TH1D*)f_2->FindObjectAny(varName);
  h_3=(TH1D*)f_3->FindObjectAny(varName);
  h_4=(TH1D*)f_4->FindObjectAny(varName);
  sig1=(TH1D*)f_5->FindObjectAny(varName);
  sig2=(TH1D*)f_6->FindObjectAny(varName);
  sig3=(TH1D*)f_7->FindObjectAny(varName);

  if(varName=="mTPhoMET"){
    xmin_=0,xmax_=2000,xmin=0,xmax=2000,rebin=5,varname1="m_{T}(#vec{p}_{T}^{ e} , #vec{p}_{T}^{ miss}) (GeV)";
    ymin=0 , ymax=2.99, ymin_=0.001 , ymax_=1000000;
  }
  else if(varName=="mTPhoMET_elec0"){
    xmin_=0,xmax_=2000,xmin=0,xmax=2000,rebin=5,varname1="m_{T}(#gamma,#vec{p}_{T}^{ miss}) (GeV)";
    ymin=0 , ymax=2.99, ymin_=0.5 , ymax_=1000000;
  }

  sr->Rebin(rebin);
  h_0->Rebin(rebin);
  h_1->Rebin(rebin);
  h_2->Rebin(rebin);
  h_3->Rebin(rebin);
  h_4->Rebin(rebin);
  sig1->Rebin(rebin);
  sig2->Rebin(rebin);
  sig3->Rebin(rebin);

  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  
  sr->SetTitle(0);

  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  /*
  sr->GetYaxis()->SetLabelSize(0.05);
  sr->GetYaxis()->SetTitle("Entries");
  sr->GetXaxis()->SetTitle(varname1);
  sr->GetYaxis()->SetTitleSize(0.07);
  sr->GetYaxis()->SetTitleOffset(0.72);
  */
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(0.7);
  sr->SetMarkerColor(kBlack);
  sr->SetLineColor(kBlack);
  sr->Draw();

  decorate(h_0,0,f_0->GetName());
  decorate(h_1,1,f_1->GetName());
  decorate(h_2,2,f_2->GetName());
  decorate(h_3,3,f_3->GetName());
  decorate(h_4,4,f_4->GetName());
  h_0 = setMyRange(h_0,xmin_,xmax_);
  h_1 = setMyRange(h_1,xmin_,xmax_);
  h_2 = setMyRange(h_2,xmin_,xmax_);
  h_3 = setMyRange(h_3,xmin_,xmax_);
  h_4 = setMyRange(h_4,xmin_,xmax_);
  sig1->SetLineColor(kBlue);
  sig1->SetLineWidth(2);
  setLastBinAsOverFlow(sig1);
  sig1 = setMyRange(sig1,xmin_,xmax_);
  sig2->SetLineColor(kMagenta+3);
  sig2->SetLineWidth(2);
  setLastBinAsOverFlow(sig2);
  sig2 = setMyRange(sig2,xmin_,xmax_);
  sig3->SetLineColor(kPink+10);
  sig3->SetLineWidth(2);
  setLastBinAsOverFlow(sig3);
  sig3 = setMyRange(sig3,xmin_,xmax_);

  hs_var->Add(h_0);
  hs_var->Add(h_1);
  hs_var->Add(h_2);
  hs_var->Add(h_3);
  hs_var->Add(h_4);
  hs_var->Draw("hist");

  hs_var->GetYaxis()->SetLabelSize(0.04);
  hs_var->GetYaxis()->SetTitle("Events");
  hs_var->GetXaxis()->SetTitle(varname1);
  hs_var->GetYaxis()->SetTitleSize(0.05);
  hs_var->GetYaxis()->SetTitleOffset(0.92);
  hs_var->GetXaxis()->SetLabelSize(0.04);
  hs_var->GetXaxis()->SetTitleSize(0.035);
  hs_var->GetXaxis()->SetTitleOffset(1.15);

  sig1->Draw("hist same");
  sig2->Draw("hist same");
  sig3->Draw("hist same");

  hs_var->SetTitle(0);
  hs_var->GetXaxis()->SetLimits(xmin_-0.1,xmax_+0.1);
  hs_var->SetMinimum(ymin_);
  hs_var->SetMaximum(ymax_);
  //  sr->Draw("sames");

  textOnTop.SetTextSize(0.045);
  textOnTop2.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);

  textOnTop.DrawLatexNDC(0.1,0.915,"CMS");
  textOnTop2.DrawLatexNDC(0.157,0.915,"#it{#bf{Simulation Supplementary}}");  
  intLumiE.DrawLatexNDC(0.745,0.92,"#bf{137 fb^{-1} (13 TeV)}");

  TLegend *legend2 = new TLegend(0.6,0.82,0.89,0.89);
  legend2->SetBorderSize(0);
  legend2->SetTextSize(0.045);
  legend2->SetHeader("Single electron region");
  legend2->Draw();

  //  TLegend *legend = new TLegend(0.5,0.78,0.89,0.89);
  TLegend *legend = new TLegend(0.5,0.65,0.89,0.78); 
  legend->SetNColumns(3);
  legend->SetBorderSize(0);
  legend->SetTextSize(0.038);
  legend->AddEntry(h_0,"t#bar{t} + #gamma","f");
  legend->AddEntry(h_1,"W(l#nu) + #gamma","f");
  legend->AddEntry(h_2,"t#bar{t}","f");
  legend->AddEntry(h_3,"W(l#nu) + jets","f");
  legend->AddEntry(h_4,"Single t/#bar{t}","f");
  legend->Draw();

  //  TLegend *legend1 = new TLegend(0.5,0.6,0.89,0.76);
  TLegend *legend1 = new TLegend(0.18,0.72,0.45,0.89);
  legend1->SetNColumns(1);
  legend1->SetBorderSize(0);
  legend1->SetTextSize(0.035);
  legend1->SetMargin(0.12);
  //  legend1->AddEntry(sig1,"T5bbbbZg (2200 , 200)","l");
  legend1->AddEntry(sig1," T5bbbbZg (2200, 200)","l");
  legend1->AddEntry(sig2," T5bbbbZg (2200, 1000)","l");
  legend1->AddEntry(sig3," T5bbbbZg (2200, 2100)","l");

  //  legend1->AddEntry(sig1,"pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)","l");
  //  legend1->AddEntry(sig2,"pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 1000 GeV)","l");
  //  legend1->AddEntry(sig3,"pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 2100 GeV)","l");
  //legend1->AddEntry(sig2,"T5bbbbZg (2200 , 1000)","l");
  //legend1->AddEntry(sig3,"T5bbbbZg (2200 , 2100)","l");
  legend1->Draw();
  c1->SaveAs(png);
  c1->SetCanvasSize(1600,900);
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
  setLastBinAsOverFlow(hist);

  gStyle->SetOptStat(0);
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
