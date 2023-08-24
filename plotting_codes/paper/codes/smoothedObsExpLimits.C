#include<iostream>
#include<iomanip>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TF1.h"
#include<string>
#include<vector>
#include"TGraphErrors.h"
#include"TGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TCanvas.h"
#include"TGraph2D.h"
#include"smoothTGraph.h"

TLatex textOnTop,intLumiE;
double intLumi = 137.0;
void removePoint(double, double, TH2D*);
void removeFitFailPoints(TH2D*, TH2D*);
void smoothedObsExpLimits(TString fName){
  //---------------- set styles----------------
  gStyle->SetOptStat(0);
  gStyle->SetTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.50, 0.50, 1.00, 1.00, 1.00 };
  Double_t green[NRGBs] = { 0.50, 1.00, 1.00, 0.60, 0.50 };
  Double_t blue[NRGBs]  = { 1.00, 1.00, 0.50, 0.40, 0.50 };

  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
//---------------------------------
TFile *f1=new TFile(fName); 
//TFile *fout =new TFile("Excl_"+fName,"recreate");
double xMin = 1450, xMax = 2450;
double yMin = 0, yMax = 4000;
double zMin = 1.1e-1, zMax = 40e-1;//pb xsec
bool draw2sigmaLines = 0, smoothHists = 1;
//  double zMin = 0.0001, zMax = 2.0;
int nDivAxis = 505;
TString modelName=f1->GetName();
 cout<<"modelName : "<<modelName<<endl;
 TString old_file;
 /*
 if(modelName.Contains("T5bbbb")) old_file="rootoutputT5bbbbZg_old_exp.root";
 if(modelName.Contains("T5qqqq")) old_file="T5qqqqHg/T5qqqqHg_old_exp.root";
 if(modelName.Contains("T5tttt"))old_file="T5ttttZg/T5ttttZg_old_exp.root";
 if(modelName.Contains("T6tt"))old_file="T6ttZg/T6ttZg_old_exp.root";

 TFile *f2=new TFile(old_file);
TGraphAsymmErrors *old=(TGraphAsymmErrors*)f2->FindObjectAny("old");
 */
 if(modelName.Contains("T5bbbb") || modelName.Contains("T5qqqq")){ xMin = 1500; xMax = 2800; nDivAxis = 510; yMin = 0.; yMax = 4000.; zMin = 1.1e-1, zMax = 40e-1;}
if(modelName.Contains("T5tttt")                              )  { xMin = 1400; xMax = 2450; nDivAxis = 510;}
if(modelName.Contains("T6tt")                                )  { xMin =  800; xMax = 1600; nDivAxis = 510; yMin = 0.; yMax = 2000.;}
if(modelName.Contains("TChi")                                )  { xMin =  200; xMax = 1300; nDivAxis = 510; yMin = 0.; yMax = 800.;}

TPaveText *decayMode = new TPaveText(0.15,0.71, 0.8,0.9,"NDC");
//  TPaveText *decayMode = new TPaveText(0.15,0.7, 0.8,0.9,"NDC");
decayMode->SetShadowColor(0);   decayMode->SetFillColor(0);
decayMode->SetLineWidth(2);    //decayMode->SetBorderColor(kBlack);
//TLegend *legText = new TLegend(0.17,0.79, 0.45,0.82);
  TLegend *legText = new TLegend(0.17,0.71, 0.45,0.81);
TLine *line[9];

TH2D *h2_rMedian=(TH2D*)f1->FindObjectAny("mGlmNLSP_median");//median exp 50%
TH2D *h2_r16pc=(TH2D*)f1->FindObjectAny("mGlmNLSP_16pc");//median exp 16%
TH2D *h2_r84pc=(TH2D*)f1->FindObjectAny("mGlmNLSP_84pc");//meadian exp 84%
TH2D *h2_r2p5pc=(TH2D*)f1->FindObjectAny("mGlmNLSP_2p5pc");//median exp 2.5%
TH2D *h2_r97p5pc=(TH2D*)f1->FindObjectAny("mGlmNLSP_97p5pc");//meadian exp 97.5%

TH2D *h2_rObs=(TH2D*)f1->FindObjectAny("mGlmNLSP_r");//obs limit
TH2D *h2_rXsecUp=(TH2D*)f1->FindObjectAny("mGlmNLSP_r_XsecUp");//obs limit+theory xsec up
TH2D *h2_rXsecDn=(TH2D*)f1->FindObjectAny("mGlmNLSP_r_XsecDn");//obs limit+theory xsec down
TH2D *h2_XsecUL=(TH2D*)f1->FindObjectAny("mGlmNLSP_XsecUL_fb");//UL on xsec based on obs limit

// TH2D *h2_rObs=(TH2D*)f1->FindObjectAny("mGlmNLSP_median");//No obs limit
// TH2D *h2_rXsecUp=(TH2D*)f1->FindObjectAny("mGlmNLSP_median");//No obs limit+theory xsec up
// TH2D *h2_rXsecDn=(TH2D*)f1->FindObjectAny("mGlmNLSP_median");//No obs limit+theory xsec down
// TH2D *h2_XsecUL=(TH2D*)f1->FindObjectAny("mGlmNLSP_XsecULexp");//UL on xsec based on obs limit
/*
if(smoothHists){
    h2_rMedian->Smooth(1);
    h2_r16pc->Smooth(1);
    h2_r84pc->Smooth(1);
    h2_r2p5pc->Smooth(1);
    h2_r97p5pc->Smooth(1);
    h2_rObs->Smooth(1);
    h2_rXsecUp->Smooth(1);
    h2_rXsecDn->Smooth(1);
    h2_XsecUL->Smooth(1);
  }
*/
TH2D *h2_temp=new TH2D("h2temp","h2temp",60,25,3025,300,5,3005);
gStyle->SetPadGridX(0);
gStyle->SetPadGridY(0);

removeFitFailPoints(h2_rMedian,h2_rObs);
//------------------------------------------------
TGraph2D *gr2d_rMedian = new TGraph2D(h2_rMedian);
TGraph2D *gr2d_16pc = new TGraph2D(h2_r16pc);
TGraph2D *gr2d_84pc = new TGraph2D(h2_r84pc);
TGraph2D *gr2d_2p5pc = new TGraph2D(h2_r2p5pc);
TGraph2D *gr2d_97p5pc = new TGraph2D(h2_r97p5pc);

TGraph2D *gr2d_rObs = new TGraph2D(h2_rObs);
TGraph2D *gr2d_rXsecUp = new TGraph2D(h2_rXsecUp);
TGraph2D *gr2d_rXsecDn = new TGraph2D(h2_rXsecDn);
TGraph2D *gr2dXsec = new TGraph2D(h2_XsecUL);
gr2dXsec->SetNpx(250);  gr2dXsec->SetNpy(250);
//------------------------------------------------
TList *listMedian =gr2d_rMedian->GetContourList(1.05);
TList *list16pc =gr2d_16pc->GetContourList(1.05);
TList *list84pc =gr2d_84pc->GetContourList(1.05);
TList *list2p5pc =gr2d_2p5pc->GetContourList(1.05);
TList *list97p5pc =gr2d_97p5pc->GetContourList(1.05);

TList *listObs =gr2d_rObs->GetContourList(1.0);
TList *listXsecUp =gr2d_rXsecUp->GetContourList(1.0);
TList *listXsecDn =gr2d_rXsecDn->GetContourList(1.0);
//------------------------------------------------
TGraph *gr1d_Median=(TGraph*)listMedian->First();
TGraph *gr1d_16pc=(TGraph*)list16pc->First();
TGraph *gr1d_84pc=(TGraph*)list84pc->First();
TGraph *gr1d_2p5pc;
TGraph *gr1d_97p5pc;
if(draw2sigmaLines){
  gr1d_2p5pc=(TGraph*)list2p5pc->First();
  gr1d_97p5pc=(TGraph*)list97p5pc->First();
 }

 TGraph *gr1d_Obs=(TGraph*)listObs->First();
 // TGraph *gr1d_XsecUp=(TGraph*)listObs->First();
 // TGraph *gr1d_XsecDn=(TGraph*)listObs->First();
 TGraph *gr1d_XsecUp=(TGraph*)listXsecUp->First();
TGraph *gr1d_XsecDn=(TGraph*)listXsecDn->First();
//------------------------------------------------
//----------------Smoothing-----------------------

 if(smoothHists){
   /*
   Smooth(gr1d_Obs, 8, 3, "TChiWH");
  Smooth(gr1d_XsecUp, 8, 3, "TChiWH");
  Smooth(gr1d_XsecDn, 8, 3, "TChiWH");
  Smooth(gr1d_Median, 8, 3, "TChiWH");
  Smooth(gr1d_16pc, 8, 3, "TChiWH");
  Smooth(gr1d_84pc, 8, 3, "TChiWH");
   */
   Smooth(gr1d_Obs);
   Smooth(gr1d_XsecUp);
   Smooth(gr1d_XsecDn);
   Smooth(gr1d_Median);
   Smooth(gr1d_16pc);
   Smooth(gr1d_84pc);

  if(draw2sigmaLines){
    Smooth(gr1d_2p5pc, 8, 3, "TChiWH");
    Smooth(gr1d_97p5pc, 8, 3, "TChiWH");
  }
 }

//------------------------------------------------

TCanvas *c3=new TCanvas("c3","c3",1200,1000);
//c3->SetBottomMargin(0.12);
c3->SetLeftMargin(0.15);
c3->SetRightMargin(0.2);
//------------------------------------------------
/*
 old->SetLineColor(kMagenta-9);
 // old->SetLineColor(kWhite);
 old->SetLineWidth(4);old->SetLineStyle(7);
*/
 gr1d_Median->SetLineColor(kRed);
gr1d_Median->SetLineWidth(4);gr1d_Median->SetLineStyle(7);
gr1d_16pc->SetLineColor(kRed);
gr1d_16pc->SetLineWidth(2);gr1d_16pc->SetLineStyle(7);
gr1d_84pc->SetLineColor(kRed);
gr1d_84pc->SetLineWidth(2);gr1d_84pc->SetLineStyle(7);


if(draw2sigmaLines){
  gr1d_2p5pc->SetLineColor(kRed);
  gr1d_2p5pc->SetLineWidth(2);gr1d_2p5pc->SetLineStyle(2);
  gr1d_97p5pc->SetLineColor(kRed);
  gr1d_97p5pc->SetLineWidth(2);gr1d_97p5pc->SetLineStyle(2);
 }
gr1d_Obs->SetLineColor(kBlack);
gr1d_Obs->SetLineWidth(3);
gr1d_XsecUp->SetLineColor(kBlack);
gr1d_XsecUp->SetLineWidth(2);//gr1d_XsecUp->SetLineStyle(2);
gr1d_XsecDn->SetLineColor(kBlack);
gr1d_XsecDn->SetLineWidth(2);//gr1d_XsecDn->SetLineStyle(2);
//------------------------------------------------

// gr2dXsec->GetXaxis()->SetTitleSize(0.04);
// gr2dXsec->GetXaxis()->SetLabelSize(0.04);
// gr2dXsec->GetYaxis()->SetTitleSize(0.04);
// gr2dXsec->GetYaxis()->SetLabelSize(0.04);
c3->SetTitle(0);

 c3->SetLogz();
//gr2dXsec->SetMinimum(0.0);
//  h2_temp->Draw("text");
//  h2_empty->Draw("text");
h2_XsecUL->GetXaxis()->SetRangeUser(xMin,xMax);
h2_XsecUL->GetYaxis()->SetRangeUser(yMin,yMax);
// gr2dXsec->GetXaxis()->SetRangeUser(xMin,xMax);
// gr2dXsec->GetYaxis()->SetRangeUser(yMin,yMax);
//  gr2dXsec->GetXaxis()->SetNdivisions(nDivAxis);
//gr2dXsec->GetXaxis()->SetNdivisions(505);
 if(!modelName.Contains("T6ttZg")) gr2dXsec->GetYaxis()->SetNdivisions(505);
 h2_XsecUL->SetMinimum(zMin);
 h2_XsecUL->SetMaximum(zMax);
 if(modelName.Contains("TChiWZ") || modelName.Contains("TChiWH")) h2_XsecUL->SetTitle(";m(#tilde{#chi}_{ 1}^{ #pm}/#tilde{#chi}_{ 2}^{ 0}) [GeV];m(#tilde{#chi}_{ 1}^{ 0}) [GeV]");
 if(modelName.Contains("TChiWW")) h2_XsecUL->SetTitle(";m_{#tilde{#chi}_{ 1}^{ #pm}} [GeV];m_{#tilde{#chi}_{ 1}^{ 0}} [GeV]");
  h2_XsecUL->SetTitle(0);

 // h2_XsecUL->SetTitleSize(0);
 h2_XsecUL->GetXaxis()->SetTitleSize(0.04);
 h2_XsecUL->GetXaxis()->SetLabelSize(0.04);
 h2_XsecUL->GetXaxis()->SetTitleOffset(1.12);
 h2_XsecUL->GetYaxis()->SetTitleSize(0.04);
 h2_XsecUL->GetYaxis()->SetLabelSize(0.04);
 if(modelName.Contains("T5")) h2_XsecUL->GetXaxis()->SetTitle("m_{#tilde{g}} (GeV)");
 if(modelName.Contains("T6ttZg")) h2_XsecUL->GetXaxis()->SetTitle("m_{#tilde{t}} (GeV)");
 h2_XsecUL->GetYaxis()->SetTitle("m_{#tilde{#chi}_{ 1}^{ 0}} (GeV)");
 //h2_XsecUL->GetZaxis()->SetTitle("xsec");
//  h2_XsecUL->SetTitle(";m_{#tilde{g}}(GeV);m_{#tilde{#chi}_{ 1}^{ 0}}(GeV)");
//  gr2dXsec->GetZaxis()->SetTitle(";m_{#tilde{g}}(GeV);m_{#tilde{#chi}_{ 1}^{ 0}}(GeV)");


h2_XsecUL->Draw();
//  h2_XsecUL->GetZaxis()->SetTitle("95%");
//  gr2dXsec->SetHistogram(h2_XsecUL);
gr2dXsec->Draw("same COLZ");
gr1d_Median->Draw("C");
gr1d_16pc->Draw("C");
gr1d_84pc->Draw("C");
gr1d_Obs->Draw("C");

gr1d_XsecUp->Draw("C");
gr1d_XsecDn->Draw("C");

if(draw2sigmaLines){
  gr1d_2p5pc->Draw("C");
  gr1d_97p5pc->Draw("C");
 }
// old->Draw("C");
gPad->RedrawAxis();
//-----------------------------------------------
 decayMode->SetTextSize(0.038); 
if(modelName.Contains("T5qqqqHg")){
  decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma/H #tilde{G}  NLO+NLL exclusion}");
  modelName="T5qqqqHg";}
 else if(modelName.Contains("T5ttttZg")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma/Z #tilde{G}  NLO+NLL exclusion}");
   modelName="T5ttttZg";}
 else if(modelName.Contains("T5bbbbZg")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma/Z #tilde{G}  NLO+NLL exclusion}");
   modelName="T5bbbbZg";}
 else if(modelName.Contains("T6ttZg")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{t} #bar{#tilde{t}}, #tilde{t} #rightarrow t #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma/Z #tilde{G}  NLO+NLL exclusion}");
   modelName="T6ttZg";}
 else if(modelName.Contains("TChiWH")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{#chi}_{ 1}^{ #pm}#tilde{#chi}_{ 2}^{ 0}, #tilde{#chi}_{ 1}^{ #pm} #rightarrow W^{#pm} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 2}^{ 0} #rightarrow H #tilde{#chi}_{ 1}^{ 0} NLO+NLL exclusion}");
   //    decayMode->AddText(0.435,0.85,"#bf{pp #rightarrow #tilde{#chi}_{ 1}^{ #pm}#tilde{#chi}_{ 2}^{ 0}, #tilde{#chi}_{ 1}^{ #pm} #rightarrow W^{#pm} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 2}^{ 0} #rightarrow H #tilde{#chi}_{ 1}^{ 0}}");decayMode->AddText(0.26,0.66,"#bf{NLO+NLL exclusion}"); decayMode->SetTextSize(0.033);
   modelName="TChiWH";}
 else if(modelName.Contains("TChiWZ")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{#chi}_{ 1}^{ #pm} #tilde{#chi}_{ 2}^{ 0}, #tilde{#chi}_{ 1}^{ #pm} #rightarrow W^{#pm} #tilde{#chi}_{ 1}^{ 0}, #tilde{#chi}_{ 2}^{ 0} #rightarrow Z #tilde{#chi}_{ 1}^{ 0}, NLO+NLL exclusion}");
   modelName="TChiWZ";}
 else if(modelName.Contains("TChiWW")){
   decayMode->AddText("#bf{pp #rightarrow #tilde{#chi}_{ 1}^{ #pm} #tilde{#chi}_{ 1}^{ #pm}, #tilde{#chi}_{ 1}^{ #pm} #rightarrow W^{#pm} #tilde{#chi}_{ 1}^{ 0}  NLO+NLL exclusion}");
   modelName="TChiWW";}
 else decayMode->AddText(modelName);
decayMode->AddText(" ");
decayMode->AddText(" ");
decayMode->Draw();

legText->SetTextSize(0.04);
legText->SetBorderSize(0);
legText->SetFillColor(0);
legText->AddEntry(gr1d_XsecDn,"","l");
//  legText->AddEntry(gr1d_Obs,"Observed #pm 1 #sigma_{theory}","l");
legText->AddEntry(gr1d_Obs,"","l");
legText->AddEntry(gr1d_XsecDn,"","l");
if(draw2sigmaLines) legText->AddEntry(gr1d_2p5pc,"","l");
legText->AddEntry(gr1d_16pc,"","l");
//    legText->AddEntry(gr1d_Median,"Expected #pm 1, 2 #sigma_{experiment}","l");
legText->AddEntry(gr1d_Median,"","l");
legText->AddEntry(gr1d_84pc,"","l");
if(draw2sigmaLines) legText->AddEntry(gr1d_97p5pc,"","l");
//legText->AddEntry(old,"","l");
 
line[0] = new TLine(0.17,0.8,0.22,0.8); line[0]->SetNDC(1);
//line[0] = new TLine(0.17,0.78,0.22,0.78); line[0]->SetNDC(1);
line[0]->SetLineWidth(gr1d_Obs->GetLineWidth()); line[0]->SetLineColor(gr1d_Obs->GetLineColor());

line[1] = new TLine(0.17,0.807,0.22,0.807); line[1]->SetNDC(1);
//line[1] = new TLine(0.17,0.787,0.22,0.787); line[1]->SetNDC(1);
line[1]->SetLineWidth(gr1d_XsecUp->GetLineWidth()); line[1]->SetLineColor(gr1d_XsecUp->GetLineColor());

line[2] = new TLine(0.17,0.793,0.22,0.793); line[2]->SetNDC(1);
//line[2] = new TLine(0.17,0.773,0.22,0.773); line[2]->SetNDC(1);
 line[2]->SetLineWidth(gr1d_XsecDn->GetLineWidth()); line[2]->SetLineColor(gr1d_XsecDn->GetLineColor());

if(draw2sigmaLines){
  line[7] = new TLine(0.17,0.764,0.22,0.764); line[7]->SetNDC(1);
  line[7]->SetLineWidth(gr1d_97p5pc->GetLineWidth()); line[7]->SetLineColor(gr1d_97p5pc->GetLineColor()); line[7]->SetLineStyle(gr1d_97p5pc->GetLineStyle());
  line[7]->Draw();
 }

line[6] = new TLine(0.17,0.757,0.22,0.757); line[6]->SetNDC(1);
//line[6] = new TLine(0.17,0.737,0.22,0.737); line[6]->SetNDC(1);
 line[6]->SetLineWidth(gr1d_84pc->GetLineWidth()); line[6]->SetLineColor(gr1d_84pc->GetLineColor()); line[6]->SetLineStyle(gr1d_84pc->GetLineStyle());

line[3] = new TLine(0.17,0.75,0.22,0.75); line[3]->SetNDC(1);
//line[3] = new TLine(0.17,0.73,0.22,0.73); line[3]->SetNDC(1);
 line[3]->SetLineWidth(gr1d_Median->GetLineWidth()); line[3]->SetLineColor(gr1d_Median->GetLineColor()); line[3]->SetLineStyle(gr1d_Median->GetLineStyle());

line[4] = new TLine(0.17,0.743,0.22,0.743); line[4]->SetNDC(1);
//line[4] = new TLine(0.17,0.723,0.22,0.723); line[4]->SetNDC(1);
 line[4]->SetLineWidth(gr1d_16pc->GetLineWidth()); line[4]->SetLineColor(gr1d_16pc->GetLineColor()); line[4]->SetLineStyle(gr1d_16pc->GetLineStyle());

if(draw2sigmaLines){
  line[5] = new TLine(0.17,0.736,0.22,0.736); line[5]->SetNDC(1);
  line[5]->SetLineWidth(gr1d_2p5pc->GetLineWidth()); line[5]->SetLineColor(gr1d_2p5pc->GetLineColor()); line[5]->SetLineStyle(gr1d_2p5pc->GetLineStyle());
  line[5]->Draw();
 }

line[0]->Draw(); line[1]->Draw(); line[2]->Draw();
line[3]->Draw(); line[4]->Draw(); line[6]->Draw();

 
line[8] = new TLine(0.5,0.8,0.53,0.8); line[8]->SetNDC(1);
//line[8]->SetLineWidth(old->GetLineWidth()); line[8]->SetLineColor(old->GetLineColor()); line[8]->SetLineStyle(old->GetLineStyle());
//line[8]->Draw();
//legText->Draw();
TLatex legName;
legName.SetTextSize(0.04);
//  legName.DrawLatexNDC(0.245,0.788,"#bf{Observed #pm 1 #sigma_{theory}}");
legName.DrawLatexNDC(0.237,0.788,"#bf{Observed #pm 1 #sigma_{theory}}");
if(draw2sigmaLines) legName.DrawLatexNDC(0.237,0.7375,"#bf{Expected #pm 1, 2 #sigma_{experiment}}");
// legName.DrawLatexNDC(0.245,0.78,"#bf{Observed #pm 1 #sigma_{theory}}");
// if(draw2sigmaLines) legName.DrawLatexNDC(0.245,0.731,"#bf{Expected #pm 1, 2 #sigma_{experiment}}");
 else  legName.DrawLatexNDC(0.237,0.7375,"#bf{Expected #pm 1 #sigma_{experiment}}");
//legName.SetTextSize(0.03);
// legName.DrawLatexNDC(0.537,0.788,"#bf{Expected from SUS-18-002}");
//-----------------------------------------------
// gr2dXsec->GetZaxis()->SetTitleSize(0.04);
// gr2dXsec->GetZaxis()->SetTitleOffset(1.25);
gr2dXsec->SetMinimum(zMin);
gr2dXsec->SetMaximum(zMax);
gr2dXsec->GetZaxis()->SetTitle("95% CL upper limit on cross section (fb)");
gr2dXsec->GetZaxis()->SetTitleSize(0.045);
gr2dXsec->GetZaxis()->SetLabelSize(0.04);
// gr2dXsec->GetZaxis()->SetTitleOffset(0.8);
gr2dXsec->GetZaxis()->SetTitleOffset(1.1);
//gr2dXsec->GetZaxis()->SetMoreLogLabels();
//gr2dXsec->GetZaxis()->SetNoExponent();
//gr2dXsec->GetZaxis()->ChangeLabel(1);
//gr2dXsec->SetMinimum(0.00001);
//  gr2dXsec->SetMaximum(0.1);
// if(modelName!="T6ttZg")  gr2dXsec->SetTitle(";m_{#tilde{g}}(GeV);m_{#tilde{#chi}_{ 1}^{ 0}}(GeV)");
// else                     gr2dXsec->SetTitle(";m_{ #tilde{t}}(GeV);m_{#tilde{#chi}_{ 1}^{ 0}}(GeV)");


// TPaveText *pt = new TPaveText(.05,.1,.95,.8);
//   pt->AddText("A TPaveText can contain severals line of text.");
//  pt->Draw();

c3->Update();
//fout->cd();
gr2dXsec->Write();

h2_XsecUL->Write();
TGraph *gr1d_Median_cp=(TGraph*)gr1d_Median->Clone("exp");    gr1d_Median_cp->Write();
TGraph *gr1d_16pccp=(TGraph*)gr1d_16pc->Clone("exp16pc");   gr1d_16pccp->Write();
TGraph *gr1d_84pccp=(TGraph*)gr1d_84pc->Clone("exp84pc");   gr1d_84pccp->Write();

TGraph *gr1d_2p5pccp;
TGraph *gr1d_97p5pccp;
if(draw2sigmaLines){
  gr1d_2p5pccp=(TGraph*)gr1d_2p5pc->Clone("exp2p5pc");   gr1d_2p5pccp->Write();
  gr1d_97p5pccp=(TGraph*)gr1d_97p5pc->Clone("exp97p5pc");   gr1d_97p5pccp->Write();
 }

TGraph *gr1d_Obs_cp=(TGraph*)gr1d_Obs->Clone("obs");    gr1d_Obs_cp->Write();
TGraph *gr1d_ObsUp_cp=(TGraph*)gr1d_XsecUp->Clone("obs_up");    gr1d_ObsUp_cp->Write();
TGraph *gr1d_ObsDn_cp=(TGraph*)gr1d_XsecDn->Clone("obs_dn");    gr1d_ObsDn_cp->Write();


char name3[100];
textOnTop.SetTextSize(0.04);
intLumiE.SetTextSize(0.04);
textOnTop.DrawLatexNDC(0.15,0.915,"CMS #it{#bf{}}");
//textOnTop.DrawLatexNDC(0.15,0.915,"CMS");
sprintf(name3,"#bf{%0.0f fb^{-1} (13 TeV)}",intLumi);
intLumiE.DrawLatexNDC(0.63,0.915,name3);
c3->SaveAs("pdf/"+modelName+"_exclusion.pdf");
c3->SaveAs("png/"+modelName+"_exclusion.png");
}

void removePoint(double x, double y, TH2D *h){
  cout<<"!!!!! removing point (x,y) = ("<<x<<","<<y<<")"<<" for "<<h->GetName()<<endl;
  h->SetBinContent(h->GetXaxis()->FindBin(x),h->GetYaxis()->FindBin(y),0);

}

void removeFitFailPoints(TH2D* h_exp, TH2D* h){
  int nx = h_exp->GetNbinsX(), ny = h_exp->GetNbinsY();
  double limi = 0.;
  for(int i=1;i<=nx;i++){
    for(int j=1;j<=ny;j++){
      if(h->GetXaxis()->GetBinCenter(i) < h->GetYaxis()->GetBinCenter(j)) continue;
      if(h->GetBinContent(i,j) < 1e-9) continue;
      limi = h_exp->GetBinContent(i,j);
      if(limi < 1e-9){
	cout<<"rm "<<h->GetXaxis()->GetBinCenter(i)<<" "<<h->GetYaxis()->GetBinCenter(j)<<" "<<h->GetBinContent(i,j)<<"|";
	h->SetBinContent(i,j,0.);
	h->SetBinError(i,j,0.);
      }
    }
  }
}
