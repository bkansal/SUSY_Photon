//void plotratio_LE_newselec_v2(TString title1="full_Run2", TString ntuples="v18" , bool lowdphi=false)
void plotratio_LE_newselec_v2(TString title1="full_Run2", TString ntuples="v18" , bool lowdphi=false)
  {
    TFile *f1,*f_0,*f_1;
  //  bool LE=true;
    bool expand=false;
    if(lowdphi) expand=false;
    string lep="LL";
  TString path,path_le,path_lm;
  //  bool LE=false;
  //  TString title1="2018";
  //  TString path = "rootoutput/newselec_LE_v2/";
  /* TString path = "rootoutput/newselec_LE_noISRjet_noHEM/"; */
  //  TString path = "rootoutput/newselec_LM_noISRjet_v2/";
  //  TString path = "rootoutput/newselec_LM_noISRjet_METfilters/";
  //  TString path = "rootoutput/newselec_LEplusLM_noISRjet/";
  //  TString path ="rootoutput/newselec_LM_noISRjet_METfilters_nogenpromptpho_forWGandTTG_EW/";
  //  TString path ="rootoutput/newselec_LE_noISRjet_METfilters_EW_hadjetID/TF_v3/";
  //  TString path ="rootoutput/newselec_LM_noISRjet_METfilters_EW_hadjetID_v18/TF_v3/";

  if(ntuples=="v18")
    {

      if(!lowdphi){
	path="final_rootfiles/LL/TF_v6_usingfullRun2_BTagDeepCSV_newBin2/";
	path="final_rootfiles/LL/TF_v6_usingfullRun2_BTagDeepCSV_SFuperror_newBin2/";
        path="final_rootfiles/LL/TF_v6_usingfullRun2_BTagSF_eSF_newBin2/";
	path="../plots/final_rootfiles/LL/TF_v7_usingfullRun2_BTagSF_SF_newBin2/";
	path="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_newBin2/";
       	path="rootoutput/new/nominal_fr/LL/";
	path_le="rootoutput/new/nominal_fr/LE/";
        path_lm="rootoutput/new/nominal_fr/LM/";
	//	path="./";
	//	path="rootoutput/new/nominal_fr/LL/";
	//path="rootoutput/new/";
	//	path="rootoutput/new/scalepdf/LL/";
	//	path="rootoutput/new/withJEC/LL/";
	//       path="rootoutput/new/drpt3/LE_muo/";
	//	path="rootoutput/new/withoutjerc/LL/";
	//        path="rootoutput/new/esfup/LL/";

      }
      //      else path="../plots/final_rootfiles/LL/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
      else { path="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
	path_le="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
	path_lm="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
      }
    }
  else
    {
      path="./tmp/";
      path="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v4_usingfullRun2_BTagDeepCSV/";
      path="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
      //      path ="rootoutput/newselec_LE_noISRjet_METfilters_EW_hadjetID/TF_v3_usingfullRun2/";
    }
      //  TString path ="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID/TF_v3_usingfullRun2/";
  //  TString path ="rootoutput/newselec_LM_noISRjet_METfilters_EW_hadjetID/";
  // TString path ="rootoutput/newselec_LM_noISRjet_METfilters_EW_hadjetID/";
  //  TString path ="rootoutput/newselec_LL_noISRjet_METfilters_nogenpromptpho_forWGandTTG_EW/";
  //  TString path ="rootoutput/newselec_LE_noISRjet_METfilters_nogenpromptpho_forWGandTTG/"
  //  path = "./";
  //  TString path = "rootoutput/newselec_LE_noISRjet_noHEM/";
  /* TString path = "rootoutput/newselec_LE_noISRjet_noHEM_noprefire/"; */
  /* TString path= "rootoutput/newselec_LE_noISRjet_noprefire/"; */
  TString path1,path1_le,path1_lm;
  if(ntuples=="v18")
    {
      if(title1=="full_Run2")
	{
	  //path1 =path+"TTGJets_CR_v18_v2.root";
	  //	path1= path+"Run2_METdata_CR_v18.root";
	  path1 =path+"TTWGJ_CR_v18.root";
          path1_le =path_le+"TTWGJ_CR_v18.root";
          path1_lm =path_lm+"TTWGJ_CR_v18.root";

	}
      else
	//	path1 =path+"TTGJets_"+title1+"_CR_v18_v2.root";
	{
	  path1 =path+"TTWGJ_"+title1+"_CR_v18.root";
          path1_le =path_le+"TTWGJ_"+title1+"_CR_v18.root";
          path1_lm =path_lm+"TTWGJ_"+title1+"_CR_v18.root";

	}
    }
  else
    {
      if(title1=="full_Run2")
	path1 =path+"TTWGJ_CR_v18.root";
      else
	//	path1 =path+"WGJets_"+title1+"_CR_v18.root";
	path1 =path+"TTWGJ_"+title1+"_CR_v18.root";
    }
    
  f1 = new TFile(path1);
  f_0 = new TFile(path1_le);
  f_1 = new TFile(path1_lm);

  TLatex textOnTop,intLumiE;

  TString name;
  if(!lowdphi){
    if (lep=="LE")
      name="Run"+title1+"_TF_LE_v6_CD";
    if (lep=="LM")
      name="Run"+title1+"_TF_LM_v6_CD";
    if (lep=="LL")
      name="Run"+title1+"_TF_LL_v6_CD";
    name="factors/lostlepton_highdphi_"+title1+".root";
    if(title1=="full_Run2")  name="factors/lostlepton_highdphi.root";
  }
  if(lowdphi){
    if (lep=="LE")
      name="Run"+title1+"_TF_lowdphi_LE_v6_CD";
    if (lep=="LM")
      name="Run"+title1+"_TF_lowdphi_LM_v6_CD";
    if (lep=="LL")
      name="Run"+title1+"_TF_lowdphi_LL_v6_CD";
    name="factors/lostlepton_lowdphi.root";
  }
  
 
  TString png;
  TString rootout;
  /* if(ntuples=="v18") */
  /*   { */
  /*     rootout= name + "_v18.root"; */
  /*   } */
  /* else */
    rootout = name;

    
    
  TString title="Tranfer factors using NJets x Nbjets binning";
  int xMin=-100000,xMax = 100000, xmin_=0, xmax_=0;

  int k=1;
  TFile *fout =new TFile(rootout,"recreate");
  cout<<"root file : "<<rootout<<endl;
  //TString varName[3]={"AllSBins_v6_CD","AllSBins_v6_CD_SP","AllSBins_v7_CD_SP"};
  //  string varName="AllSBins_v6_CD_SP";
  string varName[1]={"AllSBins_v7_CD_SP"};
  double nbin,bin0, bin1;
  //  double nbin,bin0, bin1;
  TH1D *total;
  TH1D *TF[k];
  THStack *stack[k];
  TCanvas *c1[k];
  TString pdf1;
  for(int i=0; i<k;i++)
    {
      TH1D *fail_accept,*fail_id,*fail_iso,*cr,*fake_photon,*sr,*sr_le,*sr_lm,*cr_le,*cr_lm;

      cout<<varName[i]<<endl;
      if(!lowdphi)
	{
	  png="png/LL_"+varName[i]+"_"+title1+"_TF.png";
	  pdf1="pdf/LL_"+varName[i]+"_"+title1+"_TF.pdf";
	}
      else{
	png="plots/png/LL/LL_"+varName[i]+"_"+title1+"_TF_lowdphi.png";
	pdf1="plots/pdf/LL/LL_"+varName[i]+"_"+title1+"_TF_lowdphi.pdf";
      }

      if(varName[i]=="AllSBins_v7_CD_SP"){
	cr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1");
	sr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec0");
	
        sr_le       = (TH1D*)f_0->Get("AllSBins_v7_CD_SP_elec0");
        sr_lm       = (TH1D*)f_1->Get("AllSBins_v7_CD_SP_elec0");
	cr_le       = (TH1D*)f_0->Get("AllSBins_v7_CD_SP_elec1");
        cr_lm       = (TH1D*)f_1->Get("AllSBins_v7_CD_SP_elec1");

	nbin=10, bin0=1, bin1=11;
	xmin_=1;
	total = new TH1D("total","Total = fail_id+fail_iso+fail_accept+1e_cr",nbin,bin0,bin1);
	TF[i]= new TH1D("tf_SP_2","Transfer factor for SP : NJets x Nbtag & EW : wtag & htag",nbin,bin0,bin1);
      }
      if(varName[i]=="AllSBins_v6_CD"){
	cr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
	sr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec0");
        sr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_elec0");
        sr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_elec0");
        cr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_elec1");
        cr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_elec1");

	nbin=8, bin0=1, bin1=9;
	xmin_=2;
	total = new TH1D("total","Total = fail_id+fail_accept+1e_cr",nbin,bin0,bin1);
	TF[i]= new TH1D("tf","Transfer factor for NJets x Nbtag",nbin,bin0,bin1);
	
      }  
      if(varName[i]=="AllSBins_v6_CD_SP"){
	cr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec1");
	sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
        sr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_SP_elec0");
        sr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_SP_elec0");
	cr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_SP_elec1");
        cr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_SP_elec1");                             
	nbin=12, bin0=1, bin1=13;
	xmin_=1;
	total = new TH1D("total","Total = fail_id+fail_accept+1e_cr",nbin,bin0,bin1);
	TF[i] = new TH1D("tf_SP","Transfer factor for SP : NJets x Nbtag & EW : NJets x Nbtag",nbin,bin0,bin1);

      }  
      if(varName[i]=="AllSBins_v6_CD_EW_50bin"){
	cr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");
	sr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec0");
	sr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_EW_50bin_elec0");
        sr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_EW_50bin_elec0");
        cr_le       = (TH1D*)f_0->Get("AllSBins_v6_CD_EW_50bin_elec1");
        cr_lm       = (TH1D*)f_1->Get("AllSBins_v6_CD_EW_50bin_elec1");

	nbin=51, bin0=0.5, bin1=51.5;
	xmin_=0.5;
	total = new TH1D("total","Total = fail_id+fail_accept+1e_cr",nbin,bin0,bin1);
	TF[i] = new TH1D("tf","Transfer factor for SP : NJets x Nbtag & EW : NJets x Nbtag",nbin,bin0,bin1);

      }
      /*
      cout<<"The CR content in bin"<<endl;
      for(int j=bin0;j<=bin1;j++)
      	{ cout<<cr->GetBinContent(j)<<endl;
	}
      cout<<"The Transfer Factor error in bin"<<endl;
      for(int j=bin0;j<=bin1;j++)
      	{ cout<<cr->GetBinError(j)<<endl;}
      cout<<"==============="<<endl;
     
      cout<<"The SR content in bin"<<endl;
      for(int j=bin0;j<=bin1;j++)
      	{ cout<<sr->GetBinContent(j)<<endl;}
       cout<<"The Transfer Factor error in bin"<<endl; 
       for(int j=bin0;j<=bin1;j++) 
       	{ cout<<cr->GetBinError(j)<<endl;} 
      cout<<"==============="<<endl;
      */
      
      if(expand){
	total->Add(sr_le);
	total->Add(sr_lm);
	total->Add(cr_le);
	total->Add(cr_lm);
	sr_le->Divide(total);
	sr_lm->Divide(total);
	cr_le->Divide(total);
	cr_lm->Divide(total);
      
	sr->Add(cr);
	cr->Divide(sr);
      }
      else{
	total->Add(sr);
	total->Add(cr);
	sr->Divide(total);
	cr->Divide(total);
      }

      stack[i] = new THStack("Stack","stack hist");

      c1[i] = new TCanvas("stackhist","stackhist",1600,900);

  
      TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
      //  pad1->SetBottomMargin(0);

      TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.3);
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.3);
      pad1->Draw();pad1->SetGridx();
      pad2->Draw();pad2->SetGridx();pad2->SetGridy();
      pad1->cd();
      //    pad1->SetLogy();

      gStyle->SetPalette(kOcean);
      sr_le->SetFillStyle(3008);
      sr_lm->SetFillStyle(3008);
      sr_le->SetFillColor(kRed-7);
      sr_lm->SetFillColor(kBlue-6);
      sr->SetFillStyle(3008);
      sr->SetFillColor(kGreen);
      cr->SetFillColor(kGray);
      cr_le->SetFillColor(kRed-7);
      cr_lm->SetFillColor(kBlue-6);

      TLegend *legend = new TLegend(0.15,0.82,0.9,0.9);
      TLegend *legend1 = new TLegend(0.1,0.82,0.4,0.9);
      
      //  stack[i]->Add(cr);
      if(expand){
	stack[i]->Add(cr_le);
	stack[i]->Add(cr_lm);
	stack[i]->Add(sr_le);
	stack[i]->Add(sr_lm);
      }
      else{
        stack[i]->Add(cr);
        stack[i]->Add(sr);
      }
      stack[i]->SetMaximum(1.1);
      stack[i]->SetTitle(0);
      stack[i]->Draw("hist");
      stack[i]->GetYaxis()->SetLabelSize(0.08);
      stack[i]->GetYaxis()->SetTitle("N_{SR/CR}/(N_{CR}+N_{SR})");
      //      stack[i]->GetYaxis()->SetTitle("N_{SR/CR}/(N_{CR}+N_{SR})");
      //      stack[i]->GetYaxis()->SetTitleSize(0.8);
      stack[i]->GetYaxis()->SetTitleOffset(0.69);
      stack[i]->GetYaxis()->SetTitleSize(0.06);
      stack[i]->GetYaxis()->SetRangeUser(0,4);
      stack[i]->SetMinimum(0);
      stack[i]->SetMaximum(1.8);

      textOnTop.SetTextSize(0.08);
      intLumiE.SetTextSize(0.08);
      //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");
      //      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Preliminary}}");
      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation}}");
      //textOnTop.DrawLatexNDC(0.12,0.91,"work in progress");                                                                                     
       if(title1=="2016")
    	intLumiE.DrawLatexNDC(0.75,0.9,"#bf{35.9 fb^{-1} (13 TeV)}");
      if(title1=="2017")
    	intLumiE.DrawLatexNDC(0.75,0.9,"#bf{41.5 fb^{-1} (13 TeV)}");
      if(title1=="2018")
    	intLumiE.DrawLatexNDC(0.75,0.9,"#bf{59.6 fb^{-1} (13 TeV)}");
      if(title1=="full_Run2")
    	intLumiE.DrawLatexNDC(0.7,0.91,"#bf{137 fb^{-1} (13 TeV)}");

      if(varName[i]=="AllSBins_v7_CD_SP"){

    	TLine *line1V6=new TLine( 1,0,  1,1.3);
    	TLine *line2V6=new TLine( 2,0,  2,1.3);
    	TLine *line3V6=new TLine( 3,0,  3,1.3);
    	TLine *line4V6=new TLine( 4,0,  4,1.3);
    	TLine *line5V6=new TLine( 5,0,  5,1.3);
    	TLine *line6V6=new TLine( 6,0,  6,1.3);
    	TLine *line7V6=new TLine( 7,0,  7,1.3);
    	TLine *line8V6=new TLine( 8,0,  8,1.3);
    	TLine *line9V6=new TLine( 9,0,  9,1.3);
    	TLine *line10V6=new TLine( 10,0,  10,1.3);
    	TLine *line11V6=new TLine( 11,0,  11,1.3);
    	TLine *line12V6=new TLine( 12,0,  12,1.3);
    
    	pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    	line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    	line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
    	line7V6->Draw(); line8V6->Draw();
    	line9V6->Draw(); line10V6->Draw();
    	line11V6->Draw();// line12V6->Draw();
  
    	TArrow *arrow1 = new TArrow( 1, 1.1, 2, 1.1,0.01,"<|>");
    	TArrow *arrow2 = new TArrow( 2, 1.1, 3, 1.1,0.01,"<|>");
    	TArrow *arrow3 = new TArrow( 3, 1.1, 4, 1.1,0.01,"<|>");
    	TArrow *arrow4 = new TArrow( 4, 1.1, 5, 1.1,0.01,"<|>");
    	TArrow *arrow5 = new TArrow( 5, 1.1, 6, 1.1,0.01,"<|>");
    	TArrow *arrow6 = new TArrow( 6,1.1, 7,1.1,0.01,"<|>");
    	TArrow *arrow7 = new TArrow( 7,1.1, 8,1.1,0.01,"<|>");
    	TArrow *arrow8 = new TArrow( 8,1.1, 9,1.1,0.01,"<|>");
    	TArrow *arrow9 = new TArrow( 9, 1.1, 10, 1.1,0.01,"<|>");
    	TArrow *arrow10 = new TArrow( 10,1.1, 11,1.1,0.01,"<|>");
    	TArrow *arrow11 = new TArrow( 1,1.3, 9,1.3,0.01,"<|>");
    	TArrow *arrow12 = new TArrow( 9,1.3, 11,1.3,0.01,"<|>");
	
    	arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    	arrow4->Draw();
    	arrow5->Draw(); arrow6->Draw();
    	arrow7->Draw(); arrow8->Draw();
    	arrow9->Draw(); arrow10->Draw();
    	arrow11->Draw(); arrow12->Draw();
	
    	TLatex Tl,T2;
    	Tl.SetTextSize(0.06);
    	Tl.DrawLatex(1.25,1.17,"N^{ 0}_{ 2}");
    	Tl.DrawLatex(2.25,1.17,"N^{ 0}_{ 3}");
    	Tl.DrawLatex(3.25,1.17,"N^{ 0}_{ 4}");
    	Tl.DrawLatex(4.25,1.17,"N^{ 0}_{ 5-6}");
    	Tl.DrawLatex(5.25,1.17,"N^{ 0}_{ #geq7}");
    	Tl.DrawLatex(6.25,1.17,"N^{ #geq1}_{ 2-4}");
    	Tl.DrawLatex(7.25,1.17,"N^{ #geq1}_{ 5-6}");
    	Tl.DrawLatex(8.25,1.17,"N^{ #geq1}_{ #geq7}");
    	Tl.DrawLatex(9.25,1.17,"W tag");
    	Tl.DrawLatex(10.25,1.17,"H tag");
    	T2.DrawLatex(4.5,1.37,"SP region");
    	T2.DrawLatex(9.5,1.37,"EW region");

      }
      
      if(varName[i]=="AllSBins_v6_CD_SP"){

    	TLine *line1V6=new TLine( 1,0,  1,1);
    	TLine *line2V6=new TLine( 2,0,  2,1);
    	TLine *line3V6=new TLine( 3,0,  3,1);
    	TLine *line4V6=new TLine( 4,0,  4,1);
    	TLine *line5V6=new TLine( 5,0,  5,1);
    	TLine *line6V6=new TLine( 6,0,  6,1);
    	TLine *line7V6=new TLine( 7,0,  7,1);
    	TLine *line8V6=new TLine( 8,0,  8,1);
    	TLine *line9V6=new TLine( 9,0,  9,1);
    	TLine *line10V6=new TLine( 10,0,  10,1);
    	TLine *line11V6=new TLine( 11,0,  11,1);
    	TLine *line12V6=new TLine( 12,0,  12,1);
    
    	pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    	line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    	line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
    	line7V6->Draw(); line8V6->Draw();
    	line9V6->Draw(); line10V6->Draw();
    	line11V6->Draw(); line12V6->Draw();
  
    	TArrow *arrow1 = new TArrow( 1, 0.4, 2, 0.4,0.01,"<|>");
    	TArrow *arrow2 = new TArrow( 2, 0.4, 3, 0.4,0.01,"<|>");
    	TArrow *arrow3 = new TArrow( 3, 0.4, 4, 0.4,0.01,"<|>");
    	TArrow *arrow4 = new TArrow( 4, 0.4, 5, 0.4,0.01,"<|>");
    	TArrow *arrow5 = new TArrow( 5, 0.4, 6, 0.4,0.01,"<|>");
    	TArrow *arrow6 = new TArrow( 6,0.4, 7,0.4,0.01,"<|>");
    	TArrow *arrow7 = new TArrow( 7,0.4, 8,0.4,0.01,"<|>");
    	TArrow *arrow8 = new TArrow( 8,0.4, 9,0.4,0.01,"<|>");
    	TArrow *arrow9 = new TArrow( 9, 0.4, 10, 0.4,0.01,"<|>");
    	TArrow *arrow10 = new TArrow( 10,0.4, 11,0.4,0.01,"<|>");
    	TArrow *arrow11 = new TArrow( 11,0.4, 12,0.4,0.01,"<|>");
    	TArrow *arrow12 = new TArrow( 12,0.4, 13,0.4,0.01,"<|>");
    	TArrow *arrow13 = new TArrow( 1,0.7, 9,0.7,0.01,"<|>");
    	TArrow *arrow14 = new TArrow( 9,0.7, 13,0.7,0.01,"<|>");
	
    	arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    	arrow4->Draw();
    	arrow5->Draw(); arrow6->Draw();
    	arrow7->Draw(); arrow8->Draw();
    	arrow9->Draw(); arrow10->Draw();
    	arrow11->Draw(); arrow12->Draw();
    	//    arrow9->Draw(); arrow10->Draw();
    	arrow13->Draw(); arrow14->Draw();
	
    	TLatex Tl,T2;
    	Tl.SetTextSize(0.06);
    	Tl.DrawLatex(1.5,0.47,"N^{ 0}_{ 2}");
    	Tl.DrawLatex(2.5,0.47,"N^{ 0}_{ 3}");
    	Tl.DrawLatex(3.5,0.47,"N^{ 0}_{ 4}");
    	Tl.DrawLatex(4.5,0.47,"N^{ 0}_{ 5-6}");
    	Tl.DrawLatex(5.5,0.47,"N^{ 0}_{ #geq7}");
    	Tl.DrawLatex(6.5,0.47,"N^{ #geq1}_{ 2-4}");
    	Tl.DrawLatex(7.5,0.47,"N^{ #geq1}_{ 5-6}");
    	Tl.DrawLatex(8.5,0.47,"N^{ #geq1}_{ #geq7}");
    	Tl.DrawLatex(9.5,0.47,"N^{ 0}_{ 2-4}");
    	Tl.DrawLatex(10.5,0.47,"N^{ 0}_{ 5-6}");
    	Tl.DrawLatex(11.5,0.47,"N^{ #geq1}_{ 2-4}");
    	Tl.DrawLatex(12.5,0.47,"N^{ #geq1}_{5-6}");
    	T2.DrawLatex(4.5,0.8,"SP region");
    	T2.DrawLatex(10.5,0.8,"EW region");

      }


      if(varName[i]=="AllSBins_v6_CD"){

    	TLine *line1V6=new TLine( 1,0,  1,1);
    	TLine *line2V6=new TLine( 2,0,  2,1);
    	TLine *line3V6=new TLine( 3,0,  3,1);
    	TLine *line4V6=new TLine( 4,0,  4,1);
    	TLine *line5V6=new TLine( 5,0,  5,1);
    	TLine *line6V6=new TLine( 6,0,  6,1);
    	TLine *line7V6=new TLine( 7,0,  7,1);
    	TLine *line8V6=new TLine( 8,0,  8,1);

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
    	Tl.SetTextSize(0.06);
    	Tl.DrawLatex(1.5,0.47,"N^{ 0}_{ 2}");
    	Tl.DrawLatex(2.5,0.47,"N^{ 0}_{ 3}");
    	Tl.DrawLatex(3.5,0.47,"N^{ 0}_{ 4}");
    	Tl.DrawLatex(4.5,0.47,"N^{ 0}_{ 5-6}");
    	Tl.DrawLatex(5.5,0.47,"N^{ 0}_{ #geq7}");
    	Tl.DrawLatex(6.5,0.47,"N^{ #geq1}_{ 2-4}");
    	Tl.DrawLatex(7.5,0.47,"N^{ #geq1}_{ 5-6}");
    	Tl.DrawLatex(8.5,0.47,"N^{ #geq1}_{ #geq7}");
      }
      legend->SetNColumns(4);
      legend->SetBorderSize(1);

      if(lep=="LE")
    	{
    	  legend->AddEntry(cr,"1 e + #gamma CR","f");
    	  legend->AddEntry(sr_le,"0 e + #gamma SR","f");
    	  legend->SetTextSize(0.08);
    	}
      else if(lep=="LM")
    	{
    	  legend->AddEntry(cr,"1 #mu + #gamma CR  ","f");
    	  legend->AddEntry(sr_lm,"0 #mu + had #tau + #gamma SR","f");
    	  legend->SetTextSize(0.06);
    	}
      else if( lep=="LL")
    	{
	  //    	  legend->AddEntry(cr,"1 l + 1 #gamma CR","f");
	  if(expand)
	    {
	      legend->AddEntry(cr_le,"1 e + 1 #gamma CR ","f");
	      legend->AddEntry(cr_lm,"1 #mu + 1 #gamma CR ","f");
	      legend->AddEntry(sr_le,"0 e + 1 #gamma SR ","f");
	      legend->AddEntry(sr_lm,"0 #mu & had #tau + 1 #gamma SR ","f");
	    }
	  else
	  {
    	   legend->AddEntry(cr,"1 l + 1 #gamma CR","f"); 
    	   legend->AddEntry(sr,"0 l + 1 #gamma SR ","f"); 
	  }
	   legend->SetTextSize(0.06);
    	}
      legend->Draw();
      legend1->SetHeader(title1,"C"); 				// option "C" allows to center the header
      legend1->SetTextSize(0.08);
      //  legend1->Draw();
  

      pad2->cd();

      if(expand){      
	TF[i]->Add(sr_le);
	TF[i]->Add(sr_lm);
      }
      else
	{
	  TF[i]->Add(sr);
	}
      TF[i]->Sumw2();
      TF[i]->SetStats(0);
      TF[i]->Divide(cr);
      TF[i]->Draw("ep");
      TF[i]->SetTitle(0);

      TF[i]->GetYaxis()->SetNdivisions(5);
      if(lep=="LE")
    	TF[i]->GetYaxis()->SetRangeUser(0,1.0);
      else if (lep=="LM" || lep=="LL")
    	TF[i]->GetYaxis()->SetRangeUser(0,2.0);
      
      //TF[i]->GetYaxis()->SetLabelSize(0.17);
       
      fout->cd();
      TF[i]->Write();
  
      TF[i]->GetXaxis()->SetTitle("Bin no.");
      TF[i]->GetXaxis()->SetLabelSize(0.14);
      TF[i]->GetXaxis()->SetTitleOffset(0.8);
      TF[i]->GetXaxis()->SetTitleSize(0.16);

      
      TF[i]->GetYaxis()->SetTitle("Transfer factor");
      TF[i]->GetYaxis()->SetLabelSize(0.14);
      TF[i]->SetLineWidth(3);
      TF[i]->GetYaxis()->SetTitleOffset(0.20);
      TF[i]->GetYaxis()->SetTitleSize(0.15);

      TLine *line;
      if(varName[i]=="AllSBins_v6_CD"){
    	if (lep=="LE")
    	  line= new TLine(1,0.5,8,0.5);
	
    	else if(lep=="LM" || lep=="LL")
    	  line= new TLine(1,1,8,1);


    	TLine *line1V7=new TLine( 1,0,  1,2);
    	TLine *line2V7=new TLine( 2,0,  2,2);
    	TLine *line3V7=new TLine( 3,0,  3,2);
    	TLine *line4V7=new TLine( 4,0,  4,2);
    	TLine *line5V7=new TLine( 5,0,  5,2);
    	TLine *line6V7=new TLine( 6,0,  6,2);
    	TLine *line7V7=new TLine( 7,0,  7,2);
    	TLine *line8V7=new TLine( 8,0,  8,2);


    	pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
    	line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    	line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
    	line7V7->Draw(); line8V7->Draw();
      }

      if(varName[i]=="AllSBins_v6_CD_SP"){
    	if (lep=="LE")
    	  line= new TLine(1,0.5,13,0.5);
	
    	else if(lep=="LM" || lep=="LL")
    	  line= new TLine(1,1,13,1);


    	TLine *line1V7=new TLine( 1,0,  1,2);
    	TLine *line2V7=new TLine( 2,0,  2,2);
    	TLine *line3V7=new TLine( 3,0,  3,2);
    	TLine *line4V7=new TLine( 4,0,  4,2);
    	TLine *line5V7=new TLine( 5,0,  5,2);
    	TLine *line6V7=new TLine( 6,0,  6,2);
    	TLine *line7V7=new TLine( 7,0,  7,2);
    	TLine *line8V7=new TLine( 8,0,  8,2);
    	TLine *line9V7=new TLine( 9,0,  9,2);
    	TLine *line10V7=new TLine( 10,0,  10,2);
    	TLine *line11V7=new TLine( 11,0,  11,2);
    	TLine *line12V7=new TLine( 12,0,  12,2);


    	pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
    	line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    	line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
    	line7V7->Draw(); line8V7->Draw();
    	line9V7->Draw(); line9V7->Draw();
    	line11V7->Draw(); line12V7->Draw();
      }
  
      if(varName[i]=="AllSBins_v7_CD_SP"){
    	if (lep=="LE")
    	  line= new TLine(1,0.5,11,0.5);
	
    	else if(lep=="LM" || lep=="LL")
    	  line= new TLine(1,1,11,1);


    	TLine *line1V7=new TLine( 1,0,  1,2);
    	TLine *line2V7=new TLine( 2,0,  2,2);
    	TLine *line3V7=new TLine( 3,0,  3,2);
    	TLine *line4V7=new TLine( 4,0,  4,2);
    	TLine *line5V7=new TLine( 5,0,  5,2);
    	TLine *line6V7=new TLine( 6,0,  6,2);
    	TLine *line7V7=new TLine( 7,0,  7,2);
    	TLine *line8V7=new TLine( 8,0,  8,2);
    	TLine *line9V7=new TLine( 9,0,  9,2);
    	TLine *line10V7=new TLine( 10,0,  10,2);


    	pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
    	line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    	line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
    	line7V7->Draw(); line8V7->Draw();
    	line9V7->Draw(); line10V7->Draw();
      }
      line->SetLineColor(1);
      line->SetLineWidth(2);
      line->Draw();

      cout<<"The TF content in bin"<<endl;
      for(int j=bin0;j<=bin1;j++)
      	{ cout<<TF[i]->GetBinContent(j)<<endl;}
      cout<<"The Transfer Factor error in bin"<<endl;
      for(int j=bin0;j<=bin1;j++)
      	{ cout<<TF[i]->GetBinError(j)<<endl;}
      cout<<"==============="<<endl;

  
      c1[i]->SaveAs(png);
      c1[i]->SaveAs(pdf1);
    }
}

  
