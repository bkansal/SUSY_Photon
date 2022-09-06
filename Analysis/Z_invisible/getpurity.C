#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TTree.h"
#include"TBrowser.h"
#include"TF1.h"
#include<iomanip>
#include"TGraphErrors.h"
#include"TGraphAsymmErrors.h"
#include"TGraph.h"
#include"TCanvas.h"
#include"TPaveStats.h"
#include"TStyle.h"
#include"TLegend.h"

//#include"Variables.h"

using namespace std;

void nameLegend2(const char*);
void decorate(TH1D*,int);
TList *FileList;
vector<TString> legName;
vector<TString> histName1,histName2;
TLatex textOnTop,intLumiE;

TLegend *legend1=new TLegend(0.2,0.1,0.49,0.3);
TLegend *legend2=new TLegend(0.5,0.1,0.9,0.3);
//TString xAxisLabel;
char name[100];
int col[7]={kBlue,kRed,kOrange-3,kTeal+9,kMagenta,kOrange,kCyan};

int rebin=1;

void getpurity(TString dir){
  TH1::SetDefaultSumw2(1);

  FileList = new TList();
  int nfiles=2;
  TFile *f[nfiles], *f1[nfiles],*fout;
  TString name="PhotonPt_HT";
  //  xAxisLabel="#gamma p^{T}(GeV)";
  TString xAxisLabel="Bin no.";
  //  TString yAxisLabel="#varepsilon (DY/Total events)";
  TString yAxisLabel="#beta (DY/Total events)";
  /*
  TString path="final_rootfiles/Zin/withphicut_zmass60to120_data/";  
    TString path1="final_rootfiles/Zin/withphicut_zmass60to120_elec_muon_data/";
    TString path2="final_rootfiles/Zin/withphicut_zmass60to120_elec_muon/";	
  */
    TString path=dir+"/data/";
    TString path1=dir+"/elec_muon_data/";


    TString filename[2]={path+"ZJZGToLL_CR_v18.root",path+"Run2_METdata_CR_v18.root"};
    TString filename1[2]={path+"TTWZJZGToLL_CR_v18.root",path1+"Run2_METdata_CR_v18.root"};

    
  for(int i=0;i<nfiles;i++){

    histName1.push_back("AllSBins_v6_CD");
    histName2.push_back("AllSBins_v6_CD");

  }


  rebin=1;

  //  legName.push_back("2016 (35.9 fb^{-1})");
  // legName.push_back("2017 (41.5 fb^{-1})");
  // legName.push_back("2018 (59.6 fb^{-1})");
  legName.push_back("Using tt bar MC events");
  legName.push_back("Using e#mu data events");

  TCanvas *cA = new TCanvas("TrgEff","Trigger efficiency",1500,850);
  TCanvas *cB = new TCanvas("his","hist",1500,850);
  cA->SetTickx();cA->SetTicky();
  TGraphAsymmErrors *h_grAE[nfiles],*h_grAE_1,*h_grAE_2;
  TH1D *h1,*h2,*h1r,*h2r;

  for(int i=0;i<nfiles;i++){
    //    filename= path+"ZGToLLG_2016_CR_v18.root";
    // filename1= path+"TTWZJZGToLL_2016_CR_v18.root";
    f[i] = new TFile(filename[i]);
    f1[i]=  new TFile(filename1[i]);
    h1 = (TH1D*)f[i]->FindObjectAny(histName1[i]);
    h2 = (TH1D*)f1[i]->FindObjectAny(histName2[i]);
    h1->Rebin(rebin);
    h2->Rebin(rebin);
    
    //    if(h1->GetBinContent(j)>h2->GetBinContent(j))

      h_grAE[i] = new TGraphAsymmErrors(h1,h2);
    // h1r = dynamic_cast<TH1D*>(h1->Rebin(PhoPtLowEdge.size()-1,"h1new",&(PhoPtLowEdge[0])));
    // h2r = dynamic_cast<TH1D*>(h1->Rebin(PhoPtLowEdge.size()-1,"h2new",&(PhoPtLowEdge[0])));
    // h_grAE[i] = new TGraphAsymmErrors(h1r,h2r);
    // decorate(h1,i);
    //  decorate(h2,i);
    
    //   h_grAE[i]->SetMarkerStyle(20+i);
    h_grAE[i]->SetMarkerColor(col[i]);
    h_grAE[i]->SetLineColor(col[i]);
    h_grAE[i]->SetLineWidth(2);
    h_grAE[i]->SetMinimum(0.);
    h_grAE[i]->SetMaximum(1.1);

    
    cA->cd();
    cA->SetGridx();
    cA->SetGridy();
    TString name="factors/purityfactor_"+dir+".root";
    fout =new TFile(name,"recreate");
    fout->cd();

    if(i==0) {

      h_grAE[i]->Draw();
      h_grAE[i]->SetTitle(0);
      h_grAE[i]->GetXaxis()->SetTitle(xAxisLabel);
      h_grAE[i]->GetYaxis()->SetTitle(yAxisLabel);
      h_grAE[i]->GetYaxis()->SetTitleOffset(0.5);
      h_grAE[i]->GetYaxis()->SetTitleSize(0.06);
      h_grAE_1 = (TGraphAsymmErrors*)h_grAE[i]->Clone("h_grAE_1");

      h_grAE_1->Write("mc");
    }
    else
      {
	//	if(histName1[i]=="AllSBins_v6_CD_EW_7bin"  ){       
        if(histName1[i]=="AllSBins_v6_CD"  ){
	  h_grAE[i]->SetTitle(0);
	  h_grAE[i]->GetXaxis()->SetTitleOffset(0.9);
	  h_grAE[i]->GetXaxis()->SetTitle("Bin no.");
	  h_grAE[i]->GetXaxis()->SetTitleSize(0.17);
	  TLine *line1V6=new TLine( 1,0, 1,1);
	  TLine *line2V6=new TLine( 2,0, 2,1);
	  TLine *line3V6=new TLine( 3,0, 3,1);
	  // TLine *line4V6=new TLine( 4,0, 4,1);
	  line1V6->Draw();      line2V6->Draw();  line3V6->Draw(); //line4V6->Draw();
	  double yset_=0.0085;
	  TArrow *arrow1 = new TArrow( 1,50*yset_, 2,50*yset_,0.01,"<|>");
	  TArrow *arrow2 = new TArrow( 2,50*yset_, 3,50*yset_,0.01,"<|>");
	  //TArrow *arrow3 = new TArrow( 3,50*yset_, 4,50*yset_,0.01,"<|>");
	  //TArrow *arrow4 = new TArrow( 4,50*yset_, 5,50*yset_,0.01,"<|>");
	  
	  arrow1->Draw(); arrow2->Draw();
	  //	  arrow3->Draw(); arrow4->Draw();
	  TLatex Tl;
	  Tl.SetTextSize(0.04);
	  Tl.DrawLatex(1.05 ,1.5*50*yset_,"NBTag = 0");
          Tl.DrawLatex(2.05 ,1.5*50*yset_,"NBTag > 0");
	  //Tl.DrawLatex(1.05 ,1.5*50*yset_,"SP : NBTag = 0");
	  //Tl.DrawLatex(2.05 ,1.5*50*yset_,"SP : NBTag > 0");
	  //Tl.DrawLatex(3.2,1.5*50*yset_,"EW : W tag");
	  //Tl.DrawLatex(4.2,1.5*50*yset_,"EW : H tag");
	  h_grAE_2 = (TGraphAsymmErrors*)h_grAE[i]->Clone("h_grAE_2");

	  
	   h_grAE_2->Write("data");

	  h_grAE[i]->Draw("sames");
	}
      }
    legend1->AddEntry(h_grAE[i],legName[i],"lpe");
    //
    //    h_grAE_2->Write("data");
    // h_grAE_1->Write("mc");
	  
    Double_t *yg = h_grAE[i]->GetY();
    char leg[100];//=yg[0] +" +- " + h_grAE[i]->GetErrorYhigh(0);
    sprintf(leg,"#beta : %.3lf +- %.2lf (0b) , %.3lf +- %.2lf (>0b)",yg[0],h_grAE[i]->GetErrorYhigh(0),yg[1],h_grAE[i]->GetErrorYhigh(1));
    sprintf(leg,"#beta : %.3lf +- %.2lf (0b) , %.3lf +- %.2lf (>0b)",yg[0],h_grAE[i]->GetErrorYhigh(0),yg[1],h_grAE[i]->GetErrorYhigh(1));
    //    legend2->AddEntry(h_grAE[i],leg,"lpe");               
    legend2->AddEntry(h_grAE[i],leg,"lpe");
    for(int j=1 ; j<5 ; j++)
      cout<<j<<" : "<<h1->GetBinContent(j)<<" : "<<h2->GetBinContent(j)<<endl;
    for(int j=0 ; j<4 ; j++)
      //cout<<1-yg[j]<<" +- ("<<h_grAE[i]->GetErrorYlow(j)<<","<<h_grAE[i]->GetErrorYhigh(j)<<")"<<endl;
     cout<<i<<" : "<<yg[j]<<" ; low error = "<<h_grAE[i]->GetErrorYlow(j)<<" ; high error = "<<h_grAE[i]->GetErrorYhigh(j)<<endl;
    cout<<" DY MC events : "<<h1->Integral()<<endl;
    cout<<" DY + Non DY MC events : "<<h2->Integral()<<endl;

    gPad->Update();
    
    
  }
  legend1->SetTextSize(0.04);

  legend1->Draw();
  legend2->SetTextSize(0.03);
  //  legend2->SetMarkerSize(0.01);

  legend2->Draw();

  cB->cd();
  h1->Draw();
  h2->Draw("sames");

  cA->cd();

  char name2[100];  
  textOnTop.SetTextSize(0.035);
  intLumiE.SetTextSize(0.035);
  //  textOnTop.DrawLatexNDC(0.1,0.91,"Work in Progress");
  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Preliminary}}");
  sprintf(name2,"#bf{137 fb^{-1}(13TeV)}");
  intLumiE.DrawLatexNDC(0.73,0.91,name2);

  //  TFile *fout=new TFile("Eff_"+histName2[0]+f[0]->GetName(),"RECREATE");
  //  TFile *fout=new TFile("Eff_Purity.root","RECREATE");
  // fout->cd();
  bool root=false;
  if(root)
   for(int i=0;i<nfiles;i++){
    TString str = "0";
    //    sprintf(str, "%s", i);
    if(i==0) str="2016";
    if(i==1) str="2017";
    if(i==2) str="2018";
    h_grAE_2->Write("data");
    h_grAE_1->Write("mc");
  }

  /*
  TCanvas *c_cC=new TCanvas("PhoPtST_Eff","PhoPtST_Eff",1500,850);
  TH2D *h2_den=(TH2D*)f[0]->FindObjectAny("PhoPtST");
  TH2D *h2_num=(TH2D*)f[0]->FindObjectAny("PhoPtST_Req");
  TH2D *h2_numC1=(TH2D*)h2_num->Clone("h2_NumCopy1");
  h2_numC1->Divide(h2_den);
  h2_numC1->Draw("colz");*/
  cA->SaveAs("pdf/Purityfactor_nlo.pdf");
  cA->SaveAs("png/Purityfactor_nlo.png");

}

  //  FileList->Add(TFile::Open("b.root") );  histName.push_back(name); legName.push_back("HE_RBX_plus0p10");
   
void decorate(TH1D* h,int i){
  h->SetLineColor(col[i]);
  h->SetLineWidth(2);
  //  h->SetFillColor(h->GetLineColor());
  h->SetMarkerStyle(20+i);
  h->SetMarkerColor(col[i]);
}
