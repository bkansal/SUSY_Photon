//////////// scale & pdf systematics for LL systematics /////////////
#include"TH3.h"
#include"TH2.h"
#include"TH1.h"


void plotoverlay(TString sys="default",TString sys2="default",TString year="full_Run2",int xmin=1,int xmax=12)
{
  TLatex textOnTop,intLumiE;
  TFile *f1, *f2,*f3;
  double ymin_=0.85 , ymax_=1.15;
  int ymin=0.0 , ymax=1;
  TString path1="rootoutput/new/nominal_fr/LL/";
  TString path2="rootoutput/new/scalepdf/LL/";
  TString varname="AllSBins_v7_CD_SP";
  TString filename,filename1,filename2;
  TString pdf,png;
  char* sname = new char[200];
  if(sys == "scale") {
    varname="AllSBins_v7_CD_SP_scale";
    ymin=0,ymax=9;
    pdf="../plots/pdf/LL/LL_scale.pdf";
    png="../plots/png/LL/LL_scale.png";

  }
  if(sys == "pdf") {
    varname="AllSBins_v7_CD_SP_pdf";
    ymin=0,ymax=100;
    pdf="../plots/pdf/LL/LL_PDF_"+to_string(ymin)+"to"+to_string(ymax)+".pdf";
    png="../plots/png/LL/LL_PDF_"+to_string(ymin)+"to"+to_string(ymax)+".png";

  }
  if(year == "full_Run2")
    {
      filename1  = path1+"TTWGJ_CR_v18.root";
      filename2  = path2+"TTWGJ_CR_v18.root";
    }
  else
    {
      filename1= path1+"TTWGJ_"+year+"_CR_v18.root";
      filename2= path2+"TTWGJ_"+year+"_CR_v18.root";
    }
  f1 = new TFile(filename1);
  f2 = new TFile(filename2);
  TH2D *cr_,*sr_,*cr1_,*sr1_,*cr2_,*sr2_;
  TCanvas *c1;
  double nbin,bin0=0, bin1=46,yset_;
  TH1D *scale_[100],*scale2_[100],*tf;
  int rebin=1;
  TString varname0=varname+"_elec0";
  TString varname1=varname+"_elec1";
  gStyle->SetOptStat(0);
  c1 = new TCanvas("stackhist","stackhist",800,600);
  c1->cd();
  c1->SetGridx();
  
  cr1_          = (TH2D*)f1->Get(varname1);
  sr1_          = (TH2D*)f1->Get(varname0);
  cr2_          = (TH2D*)f2->Get(varname1);
  sr2_          = (TH2D*)f2->Get(varname0);

  sr1_->GetXaxis()->SetRangeUser(xmin,xmax);
  sr2_->GetXaxis()->SetRangeUser(xmin,xmax);
  sr1_->Divide(cr1_);
  sr2_->Divide(cr2_);
  //  sr2_->Add(sr1_,-1);
  //   sr2_->Divide(sr1_);
  //  sr2_->Draw("colz text");
  sr1_->GetYaxis()->SetRangeUser(ymin,ymax);
  sr2_->GetYaxis()->SetRangeUser(ymin,ymax);
  
  sprintf(sname,"Px_%d",ymin);
  scale_[ymin]=sr2_->ProjectionX("Px_%d",0,1);
  scale2_[ymin]=sr2_->ProjectionX("Px_%d",0,1);

  for(int i=1; i<11; i++)
    {
      scale_[ymin]->SetBinError(i,sr1_->GetBinError(i));
      scale2_[ymin]->SetBinError(i,sr1_->GetBinError(i));
    }
  ///////////////////////////////// Average TF wrt Scale/PDF //////////////////////////////////////////////
  float average[100];
  double error[100];
  TH1F *avg_TF=new TH1F("avg_TF","Average TF for scale uncertainties",ymax,ymin,ymax);
  //  if(sys2=="avgTF"){
  scale2_[0]->Print("all");
 
  for(int i=ymin;i<ymax;i++)
      {

	sprintf(sname,"Px_%d",i);
	scale2_[i]=sr2_->ProjectionX(sname,i,i+1);
	if(i>ymin) {
	  scale2_[i]->Add(scale2_[i-1],-1);
	}

	//	scale2_[i]->Print("all");
	average[i]=0;
	error[i]=0;                                                                                                                                                         
	for(int j=1; j<11; j++)
	  {

	    average[i] += scale2_[i]->GetBinContent(j);
	    error[i] += scale2_[i]->GetBinError(j);
	  }
	
	cout<<" Average uncertainty = "<<average[i]/10<<" , error = "<<error[0]/10<<endl;    
	avg_TF->Fill(i,average[i]/10);
      }
  
    for(int j=ymin; j<ymax; j++)
      {
	//	avg_TF->SetBinContent(j+1,(average[0]-average[j])/10);
	avg_TF->SetBinContent(j+1,average[j]/10);
	avg_TF->SetBinError(j+1,error[0]/10);
      }
    //  }
    /////////////////////////////////////////////////////////////////////////////////////////

  for(int i=ymin;i<ymax;i++)
    {
      sprintf(sname,"Px_%d",i);
      scale_[i] = (TH1D*)scale2_[i]->Clone(sname);
      scale_[i]->Divide(scale2_[ymin]);
      if(i==ymin) {
	scale_[i]->GetYaxis()->SetRangeUser(ymin_,ymax_);
	if(sys=="scale") scale_[i]->GetYaxis()->SetTitle("#mu_{R}, #mu_{F} variation wrt nominal");
        if(sys=="pdf") scale_[i]->GetYaxis()->SetTitle("PDF variation wrt nominal");
	scale_[i]->GetXaxis()->SetTitle("TF bins");
	scale_[i]->SetTitle(0);
	scale_[i]->SetMarkerStyle(7);
	scale_[i]->SetFillStyle(3009);
	scale_[i]->SetFillColor(kGray);
	scale_[i]->Draw("E2");
      }
      else {
	if(i==8) scale_[i]->SetLineColor(i+3);
	else  scale_[i]->SetLineColor(i);
	scale_[i]->SetLineWidth(2);
	scale_[i]->Draw("sames hist");
      }
      //      scale_[i]->Print("all");
    }
  
  double yset=(ymax_+ymin_)/2.06;
  cout<<"yset = "<<yset<<endl;
  TArrow *arrow1 = new TArrow( 1, yset, 2, yset,0.01,"<|>");
  TArrow *arrow2 = new TArrow( 2, yset, 3, yset,0.01,"<|>");
  TArrow *arrow3 = new TArrow( 3, yset, 4, yset,0.01,"<|>");
  TArrow *arrow4 = new TArrow( 4, yset, 5, yset,0.01,"<|>");
  TArrow *arrow5 = new TArrow( 5, yset, 6, yset,0.01,"<|>");
  TArrow *arrow6 = new TArrow( 6,yset, 7,yset,0.01,"<|>");
  TArrow *arrow7 = new TArrow( 7,yset, 8,yset,0.01,"<|>");
  TArrow *arrow8 = new TArrow( 8,yset, 9,yset,0.01,"<|>");
  TArrow *arrow9 = new TArrow( 9, yset, 10, yset,0.01,"<|>");
  TArrow *arrow10 = new TArrow( 10,yset, 11,yset,0.01,"<|>");
  TArrow *arrow11 = new TArrow( 1,yset*0.97, 9,yset*0.97,0.01,"<|>");
  TArrow *arrow12 = new TArrow( 9,yset*0.97, 11,yset*0.97,0.01,"<|>");

  arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
  arrow4->Draw();
  arrow5->Draw(); arrow6->Draw();
  arrow7->Draw(); arrow8->Draw();
  arrow9->Draw(); arrow10->Draw();
  arrow11->Draw(); arrow12->Draw();
  yset=(ymax_+ymin_)/2.09;
  cout<<"yset = "<<yset<<endl;
  TLatex Tl,T2;
  Tl.SetTextSize(0.035);
  T2.SetTextSize(0.035);
  Tl.DrawLatex(1.25,yset,"N^{ 0}_{ 2}");
  Tl.DrawLatex(2.25,yset,"N^{ 0}_{ 3}");
  Tl.DrawLatex(3.25,yset,"N^{ 0}_{ 4}");
  Tl.DrawLatex(4.25,yset,"N^{ 0}_{ 5-6}");
  Tl.DrawLatex(5.25,yset,"N^{ 0}_{ #geq7}");
  Tl.DrawLatex(6.25,yset,"N^{ #geq1}_{ 2-4}");
  Tl.DrawLatex(7.25,yset,"N^{ #geq1}_{ 5-6}");
  Tl.DrawLatex(8.25,yset,"N^{ #geq1}_{ #geq7}");
  Tl.DrawLatex(9.25,yset,"W tag");
  Tl.DrawLatex(10.25,yset,"H tag");
  T2.DrawLatex(4.5,yset*0.97,"SP region");
  T2.DrawLatex(9.5,yset*0.97,"EW region");

  TLegend *legend = new TLegend(0.1,0.7,0.38,0.9);
  if(sys=="scale") {
    legend->SetNColumns(3);
    legend->SetTextSize(0.03);
  }
  if(sys=="pdf") {
    legend = new TLegend(0.1,0.65,0.9,0.9);
    legend->SetNColumns(10);
  legend->SetTextSize(0.021);
  }
  for(int i=ymin;i<ymax;i++){
    if(i==ymin) sprintf(sname,"nominal");
    else
      sprintf(sname,"index_%d",i);
    legend->AddEntry(scale_[i],sname,"lp");	  
  }

  legend->Draw();

  if(sys2=="avgTF")
    {
      avg_TF->SetTitle(0);
      avg_TF->GetYaxis()->SetRangeUser(0.70,0.82);
      avg_TF->GetYaxis()->SetTitle("Average TF for scale uncertainties");
      if(sys=="pdf") {avg_TF->GetYaxis()->SetTitle("Average TF for PDF uncertainties");avg_TF->GetXaxis()->SetTitle("PDF Weight index"); avg_TF->Draw("E0"); pdf ="LL_avgTFPDF_0to100.pdf"; png ="LL_avgTFPDF_0to100.png";}
      if(sys=="scale") {avg_TF->SetMarkerColor(kRed);avg_TF->SetMarkerSize(1.7);avg_TF->GetXaxis()->SetTitle("scale Weight index"); avg_TF->Draw("E0 text"); pdf ="LL_avgTFscale_0to100.pdf"; png ="LL_avgTFscale_0to100.png";}
    }
  textOnTop.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Preliminary}}"); 
  intLumiE.DrawLatexNDC(0.7,0.91,"#bf{137 fb^{-1} (13 TeV)}");


  c1->SaveAs(pdf);
  c1->SaveAs(png);

}
