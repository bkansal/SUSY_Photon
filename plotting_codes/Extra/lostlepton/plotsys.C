void plotsys(TString sys="default",TString year="full_Run2",int xmin=1,int xmax=11)
{
  // gStyle->SetOptStat(0);
    gStyle->SetPalette(1);
  TLatex textOnTop,intLumiE;

 bool data_pred=false;
 TFile *f1, *f2,*f3;
 TString lep="LM";
 TString path1;
 TString path2;
 TString varname="AllSBins_v7_CD_SP";
 double ymin=0.5 , ymax=1.5, ymin_=0.0 , ymax_=2;

 if(sys=="drmodel")
   {
     path1="rootoutput/new/nominal_fr/LE/";
     path2="rootoutput/new/drpt3/LE_muo/";
   }
 else if(sys=="btagSF")
   {
     path1="rootoutput/new/nominal_fr/LL/";
     path2="rootoutput/new/bsfup/LL/";
     //     path2="rootoutput/new/scalepdf/";

   }
  else if(sys=="JECup")
   {
     path1="rootoutput/new/withoutjerc/LL/";
     path2="rootoutput/new/withJEC/LL/";
   }
  else if(sys=="JERup")
   {
     path1="rootoutput/new/withoutjerc/LL/";
     path2="rootoutput/new/withJER/LL/";
   }
   else if(sys=="lepSF")
   {
     path1="rootoutput/new/nominal_fr/LL/";
     path2="rootoutput/new/esfup/LL/";
   }
   else if(sys=="scale")
   {

     //     path1="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_newBin2/";
     // path2="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_scalepdf_newBin2/";

     
     path1="rootoutput/new/nominal_fr/LL/";
     path2="rootoutput/new/scalepdf/LL/";     

     varname="AllSBins_v7_CD_SP_scale";
   }
   else if(sys=="pdf")
   {

     //path1="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_newBin2/";
     //path2="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_scalepdf_newBin2/";
     path1="rootoutput/new/nominal_fr/LL/";
     path2="rootoutput/new/scalepdf/LL/";

     varname="AllSBins_v7_CD_SP_pdf";
   }

 else {
   cout<<" for Modelling of collinear photons : drmodel"<<endl;
   cout<<" for btagSF systematics : btagSF"<<endl;
   cout<<" for JECup systematics : JECup"<<endl;
   cout<<" for JERup systematics : JERup"<<endl;
   cout<<" for lepSF systematics : lepSF"<<endl;

 }

 TString pdf = "LL_"+sys+".pdf";
 TString png = "LL_"+sys+".png";

 TString filename,filename1,filename2;
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
  f2 = new TFile(filename1);
  f3 = new TFile(filename2);

  TH1D *cr,*sr,*tf,*pred_sr,*cr1,*sr1,*cr2,*sr2;
  TH2D *cr_,*sr_,*tf_,*pred_sr_,*cr1_,*sr1_,*cr2_,*sr2_;
  TCanvas *c1;
  double nbin,bin0=0, bin1=46,yset_;
  TH1D *total;
  int rebin=1;
  TString varname0=varname+"_elec0";
  TString varname1=varname+"_elec1";
  gStyle->SetOptStat(0);

  
  if(sys == "scale" || sys == "pdf")
    {
      c1 = new TCanvas("stackhist","stackhist",800,600);
      c1->cd();
      cr1_          = (TH2D*)f2->Get(varname1);
      sr1_          = (TH2D*)f2->Get(varname0);
      cr2_          = (TH2D*)f3->Get(varname1);
      sr2_          = (TH2D*)f3->Get(varname0);

      sr1_->GetXaxis()->SetRangeUser(xmin,xmax);
      sr2_->GetXaxis()->SetRangeUser(xmin,xmax);
      if(sys=="scale") ymin=0,ymax=8;
      if(sys=="pdf") ymin=0,ymax=100;
      sr1_->GetYaxis()->SetRangeUser(ymin,ymax);
      sr2_->GetYaxis()->SetRangeUser(ymin,ymax);

      sr1_->Divide(cr1_);
 
      sr2_->Divide(cr2_);

      sr2_->Add(sr1_,-1);
      sr2_->Divide(sr1_);
      if(sys=="pdf") sr2_->GetYaxis()->SetTitle("PDF factor index");
      if(sys=="scale") sr2_->GetYaxis()->SetTitle("SCALE factor index");
      sr2_->SetMarkerSize(1.3);
      //      sr2_->GetZaxis()->SetRangeUser(-0.1,0.1);

      if(sys=="scale") sr2_->Draw("colz text");
      if(sys=="pdf") sr2_->Draw("colz");
      //      cout<<"Scale = 1 - N(with scale unc.)/N(nominal value) : "<<abs(sr1_->GetMaximum())<<endl;
      cout<<"Max PDF uncertainty = 1 - N(with scale unc.)/N(nominal value) : "<<abs(sr2_->GetMaximum())<<endl;
      //      max->Fill(ext2,fr2->GetMaximum());                                                                                                                            

    }
  else
    {
      c1 = new TCanvas("stackhist","stackhist",800,600);
      cr1          = (TH1D*)f2->Get(varname1);
      sr1          = (TH1D*)f2->Get(varname0);
      cr2          = (TH1D*)f3->Get(varname1);
      sr2          = (TH1D*)f3->Get(varname0);
    
      sr1->GetXaxis()->SetRangeUser(xmin,xmax);
      sr2->GetXaxis()->SetRangeUser(xmin,xmax);
      sr1->Divide(cr1);
      sr2->Divide(cr2);
      //  sr2->Divide(sr2);
      TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
      pad1->SetBottomMargin(0);
      pad1->SetBottomMargin(0.35);
      pad1->Draw();pad1->SetGridx();
      pad1->cd();
      //  pad1->SetLogy();
      
      //  sr->GetXaxis()->SetRangeUser(xmin,xmax);
      sr1->GetXaxis()->SetRangeUser(xmin,xmax);
      sr2->GetYaxis()->SetLabelSize(0.07);
      sr1->GetYaxis()->SetTitle("TF = #frac{SR}{CR}");
      sr1->GetYaxis()->SetTitleSize(0.04);
      sr1->GetYaxis()->SetTitleOffset(0.92);
      sr1->GetYaxis()->SetRangeUser(ymin_,ymax_);
      //  sr2->GetYaxis()->SetRangeUser(ymin_,ymax_);
      sr2->SetMarkerStyle(20);
      sr2->SetMarkerSize(0.7);
      sr2->SetMarkerColor(kRed);
      sr2->SetLineColor(kRed);
      sr1->SetMarkerStyle(20);
      sr1->SetMarkerSize(0.7);
      sr1->SetMarkerColor(kBlue);
      sr1->SetLineColor(kBlue);
      sr1->SetTitle(0);
      sr1->Draw();
      sr2->Draw("same");

      textOnTop.SetTextSize(0.04);
      intLumiE.SetTextSize(0.04);
      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Preliminary}}");
      intLumiE.DrawLatexNDC(0.7,0.91,"#bf{137 fb^{-1} (13 TeV)}");

      double yset=(ymax_+ymin_)/1.66;
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
      TArrow *arrow11 = new TArrow( 1,yset*1.16, 9,yset*1.16,0.01,"<|>");
      TArrow *arrow12 = new TArrow( 9,yset*1.16, 11,yset*1.16,0.01,"<|>");

      arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
      arrow4->Draw();
      arrow5->Draw(); arrow6->Draw();
      arrow7->Draw(); arrow8->Draw();
      arrow9->Draw(); arrow10->Draw();
      arrow11->Draw(); arrow12->Draw();

      yset=(ymax_+ymin_)/1.6;
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
      T2.DrawLatex(4.5,yset*1.15,"SP region");
      T2.DrawLatex(9.5,yset*1.15,"EW region");
     

      
      TLegend *legend = new TLegend(0.1,0.83,0.35,0.9);
      TString title,title1;
      title1="#frac{TF_{nominal + sys} - TF_{nominal}}{TF_{nominal}}";
      title1="#frac{#Delta TF(sys)}{TF_{nominal}}";
      if(sys=="btagSF") title="btag SF sys.";
      else if (sys=="lepSF") title="lepton SF sys.";
      else if(sys=="JECup")title="JEC sys.";
      else if(sys=="JERup")title="JER sys.";
      legend->SetHeader(title,"C");
      legend->SetTextSize(0.04);
      legend->Draw();
      
      TLegend *legend1 = new TLegend(0.6,0.78,0.9,0.9);
      legend1->AddEntry(sr1,"TF_{nominal}","lp");
      legend1->AddEntry(sr2,"TF_{nominal + sys}","lp");
      legend1->SetTextSize(0.04);
      legend1->Draw();


      
      TH1D *h3 = (TH1D*)sr1->Clone("h3");
      TH1D *h4 = (TH1D*)sr2->Clone("h4");
      h3->Add(h4,-1);
      TH1D *pull = (TH1D*)h3->Clone("pull");
      TH1D *sr1_ = (TH1D*)sr1->Clone("sr1_");                                                                                                                                                                  
      TH1D *pull2 = (TH1D*)h3->Clone("pull2");
      for(int i=0 ; i<xmax; i++)
	pull->SetBinContent(i,0);

      TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.35);
      pad2->Draw();
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.35);
      pad2->cd();
      //      pad2->SetGrid(0);
      pad2->SetGridx();
      //      pull2->Sumw2();
      pull->Sumw2();
      pull->SetStats(0);      // No statistics on lower plot                                                                       
      pull->SetTitle(0);

      //      pull->Divide(pull2);
      pull2->Divide(sr1_);

      //  pull->Add(h4,-1);
     for(int i=0 ; i<xmax; i++)
	{
	  pull->SetBinError(i,sr1->GetBinError(i)/sr1->GetBinContent(i));
	  //          pull->SetBinContent(i,0);
	  pull2->SetBinError(i,0);
	}
      pull->SetMarkerColor(kBlack);
      pull->SetLineColor(kBlack);
      pull->GetXaxis()->SetTitle("Bin no.");
      pull->GetXaxis()->SetTitleOffset(0.8);
      pull->GetXaxis()->SetTitleSize(0.18);
      pull->GetXaxis()->SetLabelSize(0.12);
      pull->GetYaxis()->SetTitle(title1);
      pull->GetYaxis()->SetTitleSize(0.08);
      pull->GetYaxis()->SetTitleOffset(0.50);
      pull->GetYaxis()->SetLabelSize(0.08);

      pull->GetYaxis()->SetNdivisions(5);
      pull->SetFillColor(kGray);

      pull->SetFillColor(kGray);
        pull->SetMarkerColor(kGray);
	
      //      pull->SetLineColor(0);
      pull->Draw("E2");
      pull2->SetMarkerColor(kBlack);

				    
      pull2->Draw("same ep");


      pull->SetMinimum(-0.09);
      pull->SetMaximum(0.09);
      TLine *line= new TLine(xmin,0,xmax,0);
      line->SetLineColor(1);
      line->SetLineStyle(2);
      line->SetLineWidth(1);
      line->Draw();
      //  sr2->Draw("same");

      
      cout<<"Systematics : "<<endl;
      for(int i=0 ; i<xmax; i++)
	cout<<pull2->GetBinContent(i)<<endl;
      c1->SaveAs(pdf);
      c1->SaveAs(png);

    }

}
