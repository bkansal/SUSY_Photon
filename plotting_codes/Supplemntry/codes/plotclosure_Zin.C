void plotclosure_Zin(TString varName,  TString year,  TString ntuples , TString dir2, bool ExpvsPred = true, bool SRvsCR=false)
{
  gStyle->SetOptStat(0);
  
  TFile *f1, *f2,*f3;
  string lep="LL";
  TString path, path1;
  TLatex textOnTop,textOnTop2,intLumiE;
  
  TString filename,filename1;
  //  TString a="Jets";
  TString a="ZJZG";
  TFile *fout1,*fout2;
  TFile *fout,*fout3;
  TH1D *norm_fac;
  double xmin,xmax,bin,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000000;
    bool scale=false;
  //    bool scale=true;                                                                                                                                                
   //   bool invMass_=true;                                                                                                                                                   
   bool invMass_=false;
  TH1D *cr,*sr,*tf,*pred_sr;

  TString title;

  TString name,name1,name2;
  TCanvas *c1;
  //  TCanvas *c1;
  c1 = new TCanvas("stackhist","stackhist",1600,900);
  TString varName1,varName2,varName3;
  if(year == "full_Run2")
    {
      if(ntuples=="v18") //for closure
	{
	  scale=true;
	  //	  path="rootoutput/v7_btagSF/withphicut_zmass60to120_newBin2/";
	  //          path="rootoutput/v7_btagSF/withphicut_zmass60to120/";
          path="rootoutput/"+dir2+"/withphicut_zmass60to120_newBin2/";
          path="rootoutput/"+dir2+"/withphicut_zmass60to120/";

	  //          path="./tmp/";

	  a="ZJZG";
	  filename= path+a+"ToNuNu_CR_v18.root";
	  filename1= path+a+"ToLL_CR_v18.root";
	  varName1=varName;
	  varName2=varName;
	  if(varName=="AllSBins_v6_CD_EW_50bin")
            {
              varName1=varName+"_elec0";
              varName2=varName+"_elec0";
	    }
	  //	  name="factors/Zinvisible_"+varName;
	}
      else{ //for predictions 
	filename1=path1+"Run2_METdata_CR_v18.root";

	if(SRvsCR)//for SF
	  {
	    
	    path="rootoutput/"+dir2+"/withphicut_zmass60to120_data_PF/";
            path1="rootoutput/"+dir2+"/withphicut_zmass60to120_data_PF/";
	    //a="TTWZJZG";
	    a="ZJZG";
            filename1=path+a+"ToLL_CR_v18.root";
	    filename=path1+"Run2_METdata_CR_v18.root";
	    varName1=varName;
	    varName2=varName;
	    if(varName=="AllSBins_v6_CD_EW_50bin")
	    {
	      varName2=varName+"_elec0";
	      varName1=varName+"_elec0";
	    }
	    name="factors/Zinvisible_SF";
	  }
	if(ExpvsPred)//for comparision
	  {
	    a="ZJZG";
	    path="rootoutput/v7_btagSF/withphicut_zmass60to120/";
	    filename= path+a+"ToNuNu_CR_v18.root";//for comparision
	    filename1=path+a+"ToNuNu_CR_v18.root";

	    varName2=varName+"_elec1_closure";
	    varName2=varName+"_elec0";
	    varName1=varName;
            if(varName=="AllSBins_v6_CD_EW_50bin") varName1=varName+"_elec0";
	    name="factors/Zinvisible_"+varName;
	  }
      }
    }
  else
    {
      if(ntuples=="v18")
	{
	  //ZGToLLG_2016_CR_v18
	  //ZJZGToLL_2016_CR_v18
	  a="ZJZG";
	  scale=true;
	  path="./rootoutput/v6/withphicut_zmass60to120_newBin2/";
	  path="./tmp/";
          path="rootoutput/"+dir2+"/withphicut_zmass60to120_newBin2/";
          path="rootoutput/"+dir2+"/withphicut_zmass60to120/";
	  filename= path+a+"ToNuNu_"+year+"_CR_v18.root"; 
	  filename1= path+a+"ToLL_"+year+"_CR_v18.root";
	  varName1=varName;
          varName2=varName;

          if(varName=="AllSBins_v6_CD_EW_50bin")
            {
              varName1=varName+"_elec0";
              varName2=varName+"_elec0";
            }

	}

      else
	{
        filename1=path1+"Run2"+year+"_METdata_CR_v18.root";
        if(SRvsCR)//for SF                                                                                                                                                 
          {
	    path="rootoutput/v4/withphicut_zmass60to120/";
            path1="rootoutput/v4/withphicut_zmass60to120_data/";
	    //	    path1="./";
	     a="ZJZG";
            filename1=path1+a+"ToLL_"+year+"_CR_v18.root";//for SF
	    filename=path1+"Run"+year+"_METdata_CR_v18.root";
	    varName1=varName;
	    varName2=varName;
	    if(varName=="AllSBins_v6_CD_EW_50bin")
	      {
		varName1=varName+"_elec0";
		varName2=varName+"_elec0";
	      }

          }
        if(ExpvsPred)//for comparision                                                                                                                                     
          {
	    path="rootoutput/v4/withphicut_zmass60to120/";
            filename= path+a+"ToNuNu_"+year+"_CR_v18.root";//for comparision
            filename1=path+a+"ToNuNu_"+year+"_CR_v18.root";
	    varName2=varName+"_elec1_closure";
            varName1=varName;
            if(varName=="AllSBins_v6_CD_EW_50bin") varName1=varName+"_elec0";

           }
	
	}
    }
  f1 = new TFile(filename);
  f2 = new TFile(filename1);
  
  TString rootout = name + "_"+dir2+".root";

  

  TString png,pdf;
  if(ExpvsPred)
    {
      png = "png/Zin_"+varName+"_"+year+"_SF.png";
      pdf= "pdf/Zin_"+varName+"_"+year+"_SF.pdf";
    }
  else if(SRvsCR)
    {
      png = "png/Zin_"+varName+"_"+year+"_SF.png";
      pdf= "pdf/Zin_"+varName+"_"+year+"_SF.pdf";

    }
  if(ntuples=="v18"){
      png = "png/Zin_"+varName+"_"+year+"_norm.png";
      pdf= "pdf/Zin_"+varName+"_"+year+"_norm.pdf";

  }

  
  //  varName1=varName;

  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  if(varName=="AllSBins_v6_CD_SP"){
    c1 = new TCanvas("stackhist","stackhist",1600,900);
    if(ExpvsPred)    pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
    if(SRvsCR)       pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
    sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
    xmin=-100000,xmax = 100000,xmin_=0,xmax_=37;
    ymin=0 , ymax=1.99, ymin_=0.0001 , ymax_=100000;
  }
  else if(varName=="AllSBins_v7_CD_SP"){
    gStyle->SetOptStat(0);
    c1 = new TCanvas("stackhist","stackhist",1600,900);
    cr          = (TH1D*)f1->Get(varName2);
    sr          = (TH1D*)f1->Get(varName1);
    if(ExpvsPred)    pred_sr     = (TH1D*)f1->Get(varName2);
    if(SRvsCR)    pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1");
    /* cr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1"); */
    /* sr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec0"); */
    /* pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1_closure"); */
    xmin_=1,xmax_=11,xmin=1,xmax = 11,bin=10;
    //ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=10000;

   if(scale)
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=0.5, yset_=0.01;
    else
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=1;
  pred_sr->GetXaxis()->SetTitle("Bin no.");

  }
 else if(varName=="AllSBins_v7_CD"){
    c1 = new TCanvas("stackhist","stackhist",1600,900);
    cr          = (TH1D*)f1->Get("AllSBins_v7_CD");
    sr          = (TH1D*)f1->Get("AllSBins_v7_CD");
    pred_sr     = (TH1D*)f2->Get("AllSBins_v7_CD");
  pred_sr->GetXaxis()->SetTitle("Bin no.");
  xmin_=1,xmax_=37,xmin=1,xmax = 37,bin=36;
    if(scale)
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=0.5, yset_=0.01;
    else
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=1;

 }

 else if(varName=="AllSBins_v6_CD"){
    c1 = new TCanvas("stackhist","stackhist",1600,900);
    //cr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
    //    c1 = new TCanvas("stackhist","stackhist",1000,1000);
    sr          = (TH1D*)f1->Get("AllSBins_v6_CD");

    if(ExpvsPred) pred_sr     = (TH1D*)f2->Get("AllSBins_v6_CD");
    if(SRvsCR) pred_sr     = (TH1D*)f2->Get("AllSBins_v6_CD");
    //xmin_=0,xmax_=44,xmin=0,xmax = 44,bin=45;
    xmin_=1,xmax_=3,xmin=1,xmax = 3,bin=3;
    if(scale)
      ymin=0 , ymax=1.99, ymin_=0.002 , ymax_=0.5, yset_=0.01;
    else
      ymin=0 , ymax=1.99, ymin_=0.02 , ymax_=100000, yset_=1;
    fout =new TFile(rootout,"recreate");
    fout->cd();
    cout<<"root file name : "<<rootout<<endl;


  }  
 else if(varName=="AllSBins_v6_CD_EW_50bin"){
   gStyle->SetOptStat(0);
   c1 = new TCanvas("stackhist","stackhist",1600,900);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);

    pred_sr->GetYaxis()->SetTitle("Bin no.");
     
    bin=52;
    //    xmin=-100000,xmax = 100000,xmin_=0,xmax_=50;
    xmin=1,xmax = 52,xmin_=1,xmax_=52;
    if(scale)
      ymin=0 , ymax=1.99, ymin_=0.008 , ymax_=100, yset_=0.005;
    else 
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=10;
    title="closure test using optimized search bins";
 
    
    pred_sr->SetTitle(0);
 }

 else if(varName=="AllSBins_v6_CD_EW_7bin"){
   gStyle->SetOptStat(0);
   c1 = new TCanvas("stackhist","stackhist",1600,900);
   sr          = (TH1D*)f1->Get(varName1);
   pred_sr     = (TH1D*)f2->Get(varName2);
   bin=4;
   
    xmin=1,xmax = 5,xmin_=1,xmax_=5;
    if(scale)
      ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=10, yset_=0.00005;
    else 
      ymin=0 , ymax=1.99, ymin_=0.5 , ymax_=100000, yset_=10;
    title="Bin no.";
    pred_sr->SetTitle(0);
    fout =new TFile(rootout,"recreate");
    fout->cd();
    cout<<"root file name : "<<rootout<<endl;
 }

  

 else  if(varName=="BestPhotonPt" || varName=="ElectronPt" || varName=="remJetPt" || varName=="JetPt" || varName=="leadJetPt" || varName=="hadAk8jetPt" || varName=="EMObj_Pt"|| varName=="JetPt1"|| varName=="BestPhotonPt_EW" || varName=="zPt" || varName=="genzPt" || varName=="JetPt2"|| varName=="JetPt3"|| varName=="JetPt4" || varName=="BestPhotonPt_v1" || varName=="BestPhotonPt_v2" || varName=="BestPhotonPt_v3"   ) 
    {
      title=varName;
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    if(varName=="EMObj_Pt" || varName=="ElectronPt") xmin_=0,xmax_=1000,xmin=0,xmax=1000;
    else     xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    if(varName=="hadAk8jetPt") rebin=10,xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    if(varName=="BestPhotonPt") {rebin=10;title="p^{#gamma}_{T} (GeV)"; xmin_=100,xmax_=1400,xmin=100,xmax=1400; }
    else rebin=5;

    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    if(ntuples=="v18")    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000000;
    else     ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=100;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    //    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName=="BestPhotonPt_vBin")
    {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName1);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    //title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName=="hadAk8Mass")
    {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=60,xmax_=160,xmin=60,xmax=160;
    rebin=5;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="leading hadronic Ak8 jet Mass";
  pred_sr->SetTitle(title);

    }
 else if( varName=="invMass")
    {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=60,xmax_=120,xmin=60,xmax=120;
    rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    if(ntuples=="v18")    ymin=0 , ymax=1.99, ymin_=1 , ymax_=100000;
    else   ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=100;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title= "invariant M(l^{+}l^{-})";
  pred_sr->SetTitle(title);

    }
 else if(varName=="MET"||varName=="ST"||varName=="ST_EW"||varName=="MET_EW" ||varName=="HT" || varName=="MET_v1"||varName=="HT_v1"||varName=="MET_v2"||varName=="HT_v2"||varName=="MET_v3"||varName=="HT_v3")
    {

      title=varName;
      if(varName=="MET") title="p^{miss}_{T}";
      c1 = new TCanvas("stackhist","stackhist",1600,1000);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    if(varName=="ST")
      {
	xmin_=100,xmax_=2000,xmin=100,xmax=2000;
	rebin=10;
      }

    else
      {
      	xmin_=100,xmax_=1200,xmin=100,xmax=1200;
	rebin=10;
      }
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.002 , ymax_=1000000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    // title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPhi"||varName=="BestPhotonEta" || varName=="remJetEta" || varName=="remJetPhi" ||varName=="JetEta" || varName == "JetPhi" || varName=="leadJetPhi" || varName == "leadJetEta" || varName == "JetPhi1" || varName == "JetEta1" || varName == "ElectronPhi" || varName == "ElectronEta" || varName == "METPhi" || varName=="BestPhotonPhi_v1"||varName=="BestPhotonEta_v1" || varName=="BestPhotonPhi_v2"||varName=="BestPhotonEta_v2" || varName=="BestPhotonPhi_v3"||varName=="BestPhotonEta_v3"|| varName=="EMObj_Phi"  )
    {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=-3.5,xmax_=3.5,xmin=-3.5,xmax=3.5;
    rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.02 , ymax_=100000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    //    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="METvBin2" || varName =="METvBin_EW_v2" || varName =="METvBin_SP_v2")
    {
      
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=250,xmax_=2000,xmin=250,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
    }
 else if(varName=="nJets" || varName=="nvtx" || varName=="nJets_EW" ||varName=="nJets_SP"||varName=="Qmulti" ||varName=="nJets_v1"||varName=="nJets_v2"||varName=="nJets_v3" )
    {
      title=varName;
      if(varName=="nJets") title="N_{ jets}";
      c1 = new TCanvas("stackhist","stackhist",1600,1000);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    rebin=1;
    if(varName=="Qmulti")    rebin=2,xmin_=0,xmax_=30,xmin=0,xmax=30;
    if(varName=="nJets")    rebin=1,xmin_=2,xmax_=11,xmin=2,xmax=11;
    if(varName=="nvtx")    rebin=2,xmin_=0,xmax_=100,xmin=0,xmax=100;
    //      xmin_=2,xmax_=10,xmin=2,xmax=16;
    ymin=0 , ymax=1.99, ymin_=0.0025 , ymax_=50000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
    }
 else if(varName=="HT5HT" || varName=="dPhi_MET_CaloMET" || varName=="METCaloMET")
   {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.05 , ymax_=1000000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
     
   }
 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP" || varName=="h_deepcsv" || varName=="h_deepcsv_v2"|| varName=="h_deepcsv_v3"|| varName=="h_deepcsv_v4" || varName=="h_deepcsv_v1" ||varName=="nBTags_v1"||varName=="nBTags_v2"||varName=="nBTags_v3"  )
    {
      if(varName=="h_deepcsv") title="Jets with b hadron flavour";
      if(varName=="h_deepcsv_v2") title="Jets with b hadron flavour";
      if(varName=="h_deepcsv_v3") title="Jets with b hadron flavour";
      if(varName=="h_deepcsv_v4") title="NBTags";//title="hadronic Jets with bjetdeepCSV cut";
      c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName1);
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.05 , ymax_=1000000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="h_minDr_bestphoEle" || varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoremEle" || varName == "h_minDr_bestphoremJets" || varName=="h_minDr_bestphoEle_EW" || varName == "h_minDr_bestphoJets_EW" ||varName=="h_minDr_bestphoEle_SP" || varName == "h_minDr_bestphoJets_SP" || varName=="dPhi_phojet1"||varName=="dPhi_METjet1"||varName=="dPhi_phoMET" || varName=="h_madminphotonDR" || varName=="h_mindr_ph_lep" || varName=="h_mindr_genph_lep" || varName == "dPhi_METjet2" || varName == "dPhi_METjet3" || varName == "dPhi_METjet4" || varName=="h_minDr_bestphoJets" || varName=="h_minDr_Elejet1" || varName=="h_minDr_Elejet2" || varName=="h_minDphi_bestphoJets" || varName=="h_minDphi_Elejet1" || varName=="h_minDphi_Elejet2" || varName=="h_minDphi_Zjet1" || varName=="h_minDr_Zjet1" )
    {
    c1 = new TCanvas("stackhist","stackhist",900,1200);
    cr          = (TH1D*)f1->Get(varName1);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    if(varName == "dPhi_METjet1" || varName == "dPhi_METjet2" || varName == "dPhi_METjet4" || varName == "dPhi_METjet3" || varName=="h_minDphi_Elejet1" || varName=="h_minDphi_Elejet2" || varName=="h_minDphi_bestphoJets"  || varName=="h_minDphi_Zjet1" || varName=="h_minDr_Zjet1")
      {
	
	rebin=1;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.01 , ymax_=100;
      }
    else if(varName == "h_minDr_bestphoremJets" || varName=="h_minDr_bestphoremEle" || varName=="h_madminphotonDR")
      {	title="MindR(good #gamma, q/g/#gamma)";
	rebin=8;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.02 , ymax_=500;
      }
    else if(varName=="h_mindr_ph_lep")
      {
	title="MindR(good #gamma, gen l)";
	rebin=8;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.02 , ymax_=500;
      }
    else if(varName=="h_mindr_genph_lep")
      {
	title="MindR(gen #gamma, gen l)";
	rebin=8;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.02 , ymax_=500;
      }
    
    else if(varName=="dPhi_phoMET")
      {
	rebin=1;
	xmin_=0,xmax_=4,xmin=0,xmax=4;
	ymin=0 , ymax=1.99, ymin_=0.002 , ymax_=10000000;
      }
    else
      {
	rebin=10;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=1000;
      }

    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    /* pred_sr->GetXaxis()->SetRangeUser(xmin,xmax); */
    /* sr->GetXaxis()->SetRangeUser(xmin,xmax); */
    pred_sr->SetTitle(title);
    }

  TPad *pad1,*pad2;

  if(invMass_)
    {
      pad1 = new TPad("pad1","pad1",0,0,1,1);
      pad2 = new TPad("pad1","pad1",0,0,1,0.3);
      pad1->SetBottomMargin(0);
      pad1->SetBottomMargin(0.3);
      //  TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0);
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.3);
      
    }
  else{
    pad1 = new TPad("pad1","pad1",0,0,1,1);
    pad2 = new TPad("pad2","pad2",0,0.0,1,0.35);

    pad1->SetBottomMargin(0);
    pad1->SetBottomMargin(0.355);
    //  TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);


  }

  
  
  pad1->Draw();pad1->SetGridx();

  pad1->cd();
  pad1->SetLogy();
    pred_sr->SetTitle(0);

  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(0.045);
  pred_sr->GetYaxis()->SetTitle("Arbitrary units");
  pred_sr->GetXaxis()->SetTitle(title);
  pred_sr->GetYaxis()->SetTitleSize(0.045);
  pred_sr->GetYaxis()->SetTitleOffset(0.99);
  //  ymin_=0.01,ymax_=100000;
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(1.3);
  if(invMass_)
    {
      pred_sr->SetMarkerColor(kBlue);
      pred_sr->SetLineColor(kBlue);
    }
  else
    {
      pred_sr->SetMarkerColor(kRed);
      pred_sr->SetLineColor(kRed);
    }
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(1.1);
  sr->SetMarkerColor(kBlue);
  sr->SetLineColor(kBlue);

  //  (*pred_sr)=1.0*(*pred_sr);
  //  pred_sr->SetLineStyle(kBlue);
  pred_sr->Print("all");
  sr->Print("all");
  if(ntuples=="v18")
    {
      cout<<"Integral for Z->ll : "<<pred_sr->Integral()<<endl;
      cout<<"Integral for Z->nunu : "<<sr->Integral()<<endl;
    }
  if(ntuples!="v18" && ExpvsPred)
    {
      cout<<"Integral for Obs. Data : "<<pred_sr->Integral()<<endl;
      cout<<"Integral for MC(CR) : "<<sr->Integral()<<endl;
    }
   if(ntuples!="v18" && SRvsCR)
    {
      cout<<"Integral for Pred. Data (CR) : "<<pred_sr->Integral()<<endl;
      cout<<"Integral for MC(CR): "<<sr->Integral()<<endl;
    }
   double integeral=pred_sr->Integral();
  double integeral2=sr->Integral();

  if(scale){
    pred_sr->Scale(1/pred_sr->Integral());
    sr->Scale(1/sr->Integral());
    ymin_=0.00002,ymax_=10; 
    pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
    sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
    pred_sr->GetXaxis()->SetRangeUser(xmin_,xmax_);
    if(varName.Contains("AllSBins"))
      {
	pred_sr->Draw("e1");
	sr->Draw("e1 sames");
      }
    else
      {
	pred_sr->Draw("epx0");
	sr->Draw("epx0 sames");
      }
    TH1D *SR_bincontent = (TH1D*)sr->Clone("SR_bincontent");
    SR_bincontent->Write();

  }
  else{
    if(invMass_) pred_sr->Draw("hist");
    else{
      pred_sr->Draw("e1");
      sr->Draw("e1 sames");
      //sr->Write();
      //    TH1D  *SR_bincontent = (TH1D*)sr->Clone("SR_bincontent");

      //SR_bincontent->Write();
    }
  }

  if(varName=="AllSBins_v6_CD"){
    pred_sr->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,3.5);
    TGaxis *A2 = new TGaxis(1,ymin_,3,ymin_,"f2_",2,"US");
    A2->SetTickSize(0.02);
    A2->Draw("B");
  }

  if(varName.Contains("nJets") || varName.Contains("nBTags")  || varName.Contains("nPhotons")){
    pred_sr->GetXaxis()->SetTickLength(0);
    pred_sr->GetXaxis()->SetLabelSize(0.06);
    TString temp2;
    for(int i=1;i<=sr->GetNbinsX();i++){
      temp2 = to_string(i-1);
      if(i%2==0 && varName.Contains("nJets")) continue;
      pred_sr->GetXaxis()->SetBinLabel(i,temp2);
    }
    pred_sr->GetXaxis()->SetLabelSize(0.02);
    pred_sr->GetXaxis()->SetLabelOffset(0.01);
    pred_sr->GetXaxis()->SetTickLength(0.02);

  }

  
  cout<<"==============="<<endl;
  
   textOnTop.SetTextSize(0.045);
   textOnTop2.SetTextSize(0.04);
   intLumiE.SetTextSize(0.04);

   //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");                                                                 
   textOnTop.DrawLatexNDC(0.1,0.92,"CMS");
   textOnTop2.DrawLatexNDC(0.17,0.92,"#it{#bf{Simulation Supplementary}}");
   //   textOnTop.DrawLatexNDC(0.1,0.91,"work in progress"); 
  if(year=="2016")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.73,0.915,"#bf{137 fb^{-1} (13 TeV)}");

  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
    TLine *line1V6=new TLine( 8,ymin_,  8,ymax_);
    TLine *line2V6=new TLine(14,ymin_, 14,ymax_);
    TLine *line3V6=new TLine(20,ymin_, 20,ymax_);
    TLine *line4V6=new TLine(26,ymin_, 26,ymax_);
    TLine *line5V6=new TLine(32,ymin_, 32,ymax_);
    TLine *line6V6=new TLine(38,ymin_, 38,ymax_);
    TLine *line7V6=new TLine(45,ymin_, 45,ymax_);
    
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    TArrow *arrow1 = new TArrow( 1,50*yset_,  8,50*yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 8,50*yset_, 14,50*yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow(14,50*yset_, 20,50*yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow(20,50*yset_, 26,50*yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow(26,50*yset_, 32,50*yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow(32,50*yset_, 38,50*yset_,0.01,"<|>");
    TArrow *arrow7 = new TArrow(38,50*yset_, 45,50*yset_,0.01,"<|>");
    TArrow *arrow8 = new TArrow(45,50*yset_, 51,50*yset_,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.05);
    Tl.DrawLatex(2.5 ,2*50*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.0 ,2*50*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.0,2*50*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(21.0,2*50*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(27,2*50*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(33,2*50*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(38,2*50*yset_,"EW : W tag");
    Tl.DrawLatex(45,2*50*yset_,"EW : H tag");
  }

  if(varName=="AllSBins_v6_CD_EW_7bin"  ){
    TLine *line1V6=new TLine( 2,ymin_, 2,ymax_);
    TLine *line2V6=new TLine( 3,ymin_, 3,ymax_);
    TLine *line3V6=new TLine( 4,ymin_, 4,ymax_);
    
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    TArrow *arrow1 = new TArrow( 1,50*yset_, 2,50*yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 2,50*yset_, 3,50*yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow( 3,50*yset_, 4,50*yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow( 4,50*yset_, 5,50*yset_,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(1.25 ,2*50*yset_,"SP : NBTag = 0");
    Tl.DrawLatex(2.25 ,2*50*yset_,"SP : NBTag > 0");
    Tl.DrawLatex(3.2,2*50*yset_,"EW : W tag");
    Tl.DrawLatex(4.2,2*50*yset_,"EW : H tag");
  }

  if(varName=="AllSBins_v7_CD_SP"){
        TLine *line1V6=new TLine( 1,0,  1,ymax_);
        TLine *line2V6=new TLine( 2,0,  2,ymax_);
        TLine *line3V6=new TLine( 3,0,  3,ymax_);
        TLine *line4V6=new TLine( 4,0,  4,ymax_);
        TLine *line5V6=new TLine( 5,0,  5,ymax_);
        TLine *line6V6=new TLine( 6,0,  6,ymax_);
        TLine *line7V6=new TLine( 7,0,  7,ymax_);

        TLine *line8V6=new TLine( 8,0,  8,ymax_);
        TLine *line9V6=new TLine( 9,0,  9,ymax_);
        TLine *line10V6=new TLine( 10,0,  10,ymax_);
        TLine *line11V6=new TLine( 11,0,  11,ymax_);
        TLine *line12V6=new TLine( 12,0,  12,ymax_);

        pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
        line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
        line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
        line7V6->Draw(); line8V6->Draw();
        line9V6->Draw(); line10V6->Draw();
        line11V6->Draw(); line12V6->Draw();

	TArrow *arrow1 = new TArrow( 1, 0.1, 2, 0.1,0.01,"<|>");
        TArrow *arrow2 = new TArrow( 2, 0.1, 3, 0.1,0.01,"<|>");
        TArrow *arrow3 = new TArrow( 3, 0.1, 4, 0.1,0.01,"<|>");
        TArrow *arrow4 = new TArrow( 4, 0.1, 5, 0.1,0.01,"<|>");
        TArrow *arrow5 = new TArrow( 5, 0.1, 6, 0.1,0.01,"<|>");
        TArrow *arrow6 = new TArrow( 6,0.1, 7,0.1,0.01,"<|>");
        TArrow *arrow7 = new TArrow( 7,0.1, 8,0.1,0.01,"<|>");
        TArrow *arrow8 = new TArrow( 8,0.1, 9,0.1,0.01,"<|>");
        TArrow *arrow9 = new TArrow( 9, 0.1, 10, 0.1,0.01,"<|>");
        TArrow *arrow10 = new TArrow( 10,0.1, 11,0.1,0.01,"<|>");
        TArrow *arrow11 = new TArrow( 1,0.7, 9,0.7,0.01,"<|>");
        TArrow *arrow12 = new TArrow( 9,0.7, 11,0.7,0.01,"<|>");

        arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
        arrow4->Draw();
        arrow5->Draw(); arrow6->Draw();
        arrow7->Draw(); arrow8->Draw();
        arrow9->Draw(); arrow10->Draw();
        arrow11->Draw(); arrow12->Draw();
      TLatex Tl,T2;
        Tl.SetTextSize(0.05);
        Tl.DrawLatex(1.25,0.2,"N^{ 0}_{ 2}");
        Tl.DrawLatex(2.25,0.2,"N^{ 0}_{ 3}");
        Tl.DrawLatex(3.25,0.2,"N^{ 0}_{ 4}");
        Tl.DrawLatex(4.25,0.2,"N^{ 0}_{ 5-6}");
        Tl.DrawLatex(5.25,0.2,"N^{ 0}_{ #geq7}");
        Tl.DrawLatex(6.25,0.2,"N^{ #geq1}_{ 2-4}");
        Tl.DrawLatex(7.25,0.2,"N^{ #geq1}_{ 5-6}");
        Tl.DrawLatex(8.25,0.2,"N^{ #geq1}_{ #geq7}");
        Tl.DrawLatex(9,0.2,"W tag");
        Tl.DrawLatex(10,0.2,"H tag");
        T2.DrawLatex(4.5,0.8,"SP region");
        T2.DrawLatex(9.5,0.8,"EW region");
 

  }
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
    /* TLine *line1V7=new TLine( 7,0, 7,100); */
    /* TLine *line2V7=new TLine(13,0,13,100); */
    /* TLine *line3V7=new TLine(19,0,19,100); */
    /* TLine *line4V7=new TLine(25,0,25,100); */
    /* TLine *line5V7=new TLine(31,0,31,100); */

    /* pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0); */
    /* line1V7->Draw();      line2V7->Draw();  line3V7->Draw(); */
    /* line4V7->Draw();      line5V7->Draw(); */

    /* TArrow *arrow1 = new TArrow( 1,0.4, 7,0.4,0.01,"<|>"); */
    /* TArrow *arrow2 = new TArrow( 7,0.4,13,0.4,0.01,"<|>"); */
    /* TArrow *arrow3 = new TArrow(13,0.4,19,0.4,0.01,"<|>"); */
    /* TArrow *arrow4 = new TArrow(19,0.4, 25,0.4,0.01,"<|>"); */
    /* TArrow *arrow5 = new TArrow(25,0.4, 31,0.4,0.01,"<|>"); */
    /* TArrow *arrow6 = new TArrow(31,0.4, 37,0.4,0.01,"<|>"); */
    
    /* arrow1->Draw(); arrow2->Draw(); arrow3->Draw(); */
    /* arrow4->Draw(); arrow5->Draw(); arrow6->Draw(); */

    /* TLatex Tl; */
    /* Tl.SetTextSize(0.04); */
    /* Tl.DrawLatex(3.,0.47,"N^{ 0}_{ 2-4}"); */
    /* Tl.DrawLatex(8.5,0.47,"N^{ 0}_{ 5-6}"); */
    /* Tl.DrawLatex(13.5,0.47,"N^{ 0}_{ #geq7}"); */
    /* Tl.DrawLatex(18.5,0.47,"N^{ #geq1}_{ 2-4}"); */
    /* Tl.DrawLatex(23.5,0.47,"N^{ #geq1}_{ 5-6}"); */
    /* Tl.DrawLatex(28.5,0.47,"N^{ #geq1}_{ #geq7}"); */
  }

  if(varName=="AllSBins_v6_CD_SP"){
    TLine *line1V6=new TLine( 6.5,0,  6.5,100);
    TLine *line2V6=new TLine(12.5,0, 12.5,100);
    TLine *line3V6=new TLine(18.5,0, 18.5,100);
    TLine *line4V6=new TLine(24.5,0, 24.5,100);
    TLine *line5V6=new TLine(30.5,0, 30.5,100);
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();

    TArrow *arrow1 = new TArrow( 0.5,0.1, 6.5,0.1,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 6.5,0.1,12.5,0.1,0.01,"<|>");
    TArrow *arrow3 = new TArrow(12.5,0.1,18.5,0.1,0.01,"<|>");
    TArrow *arrow4 = new TArrow(18.5,0.1, 24.5,0.1,0.01,"<|>");
    TArrow *arrow5 = new TArrow(24.5,0.1, 30.5,0.1,0.01,"<|>");
    TArrow *arrow6 = new TArrow(30.5,0.1, 35.5,0.1,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(2.0,0.007,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(8.5,0.007,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(14.5,0.007,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(20.5,0.007,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(25.5,0.007,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(31.5,0.007,"N^{ #geq1}_{ #geq7}");
  }


  if(varName=="AllSBins_v6_CD"){

    TLine *line1V6=new TLine( 1,ymin_,  1,ymax_);
    TLine *line2V6=new TLine( 2,ymin_,  2,ymax_);
    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  

    TArrow *arrow1 = new TArrow( 1, yset_, 2, yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 2, yset_, 3, yset_,0.01,"<|>");
    arrow1->Draw(); arrow2->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.045);
    Tl.DrawLatex(1.35,2*yset_,"N_{ b-tags} = 0");
    Tl.DrawLatex(2.35,2*yset_,"N_{ b-tags} #geq 1");
    
  }

  //  TLegend *legend = new TLegend(0.55,0.8,0.9,0.9);
  //  TLegend *legend = new TLegend(0.65,0.75,0.9,0.9);
  TLegend *legend;

  if(varName=="AllSBins_v6_CD_EW_7bin" || varName=="AllSBins_v6_CD_EW_50bin" )
    {
      legend = new TLegend(0.35,0.8,0.9,0.9);
      legend->SetNColumns(2);

    }
  else
    {
      legend = new TLegend(0.55,0.75,0.89,0.89);  
      legend->SetNColumns(1);
    }
  legend->SetBorderSize(0);

  TLegend *legend1 = new TLegend(0.1,0.8,0.4,0.9);
  TLegend *legend2 = new TLegend(0.4,0.8,0.65,0.9);

  
  if(SRvsCR)
    {

      if(invMass_) legend->AddEntry(pred_sr,"Z -> l^{+}l^{-} + #gamma ","lp");
      else{
	if(ntuples=="v18")
	  {
	    legend->AddEntry(pred_sr," Z #rightarrow l^{+}l^{-} + #gamma (CR) ","lpe");
	    legend->AddEntry(sr," Z #rightarrow #nu#bar{#nu} + #gamma (SR)","lpe");
	  }
	else
	  {
	    //	    legend->AddEntry(sr,"#beta.N_{data} ( Z #rightarrow l^{+}l^{-} + #gamma )","lpe");
	    // legend->AddEntry(pred_sr,"N_{MC} ( Z #rightarrow l^{+}l^{-} + #gamma )","lpe");
            legend->AddEntry(pred_sr," Z #rightarrow l^{+}l^{-} + #gamma (CR) ","lpe");
            legend->AddEntry(sr," Z #rightarrow #nu#bar{#nu} + #gamma (SR)","lpe");
	    //	    legend->AddEntry(pred_sr,"Z -> #mu^{+}#mu^{-} + #gamma ","lp");
	    //  legend->AddEntry(sr,"Z -> e^{+}e^{-} + #gamma ","lp");
	  }	  
      }
    }
  else if(ExpvsPred)
    {
      if(invMass_) legend->AddEntry(pred_sr,"Z -> l^{+}l^{-} + #gamma ","lp");
      else{
	if(ntuples=="v18")
	  {
	    legend->AddEntry(pred_sr,"TF x Z -> l^{+}l^{-} + #gamma (Pred.) ","lp");
	  legend->AddEntry(sr,"Z -> #nu #nu + #gamma (Exp.)","lp");
	  }
        if(ntuples!="v18")
          {
          legend->AddEntry(sr,"Z -> #nu #nu + #gamma(MC yield) ","lp");
          legend->AddEntry(pred_sr,"Z ->#nu #nu  + #gamma (Pred.)","lp");
          }
      }
      
  /* legend->AddEntry(pred_sr,"CR : (1e + #gamma )","lp"); */
      /* legend->AddEntry(sr,"SR : (0e + #gamma )","lp"); */
    }
  
  if(invMass_)
    legend->SetTextSize(0.04);
  else
    legend->SetTextSize(0.042);

  legend->SetBorderSize(0);
  legend->Draw();
  // legend1->Draw();
  // ptstats->Draw();
  // ptstats2->Draw();

   TH1D *h4 = (TH1D*)pred_sr->Clone("h4");
  TH1D *h3 = (TH1D*)sr->Clone("h3");

  //  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.3);
  pad2->Draw();
  pad2->SetTopMargin(0);
  // pad2->SetBottomMargin(0.3);
  pad2->cd();
  pad2->SetGrid(0);
  pad2->SetGridy(0);

  h3->GetYaxis()->SetRangeUser(0.5,1.5);
  h3->SetLineColor(kBlack);
  h3->SetLineStyle(1);
  h3->SetLineWidth(2);

  if(ExpvsPred)
    {
      h3->SetMinimum(0.01);  // Define Y ..                                                                                                   
      h3->SetMaximum(1.99); // .. range                                                                                                         
    }
    
  else if(SRvsCR)
    {
      if(varName=="AllSBins_v6_CD")
	{
	  h3->SetMinimum(0.01);  // Define Y ..                                                                                                   
	  h3->SetMaximum(1.99); // .. range
	  if(scale) h3->SetMaximum(1.99);
                            
	}

      else
	{
	  h3->SetMinimum(0.01);  // Define Y ..                                                                                                   
	  h3->SetMaximum(1.99); // .. range                                                                                                         
	  if(scale) h3->SetMaximum(1.99);

	}
    }
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(1.3);
  h3->SetMarkerColor(kBlack);
  // gStyle->SetOptStat(0);                                                                                                                   
  //  h3->Draw("epx0");       // Draw the ratio plot                                                                                                
    if(varName.Contains("AllSBins"))
      { 
        h3->Draw("e1");
      }
    else
      {
        h3->Draw("epx0");
      }

  h3->SetTitle(0);
  if(varName=="METvBin2") h3->GetXaxis()->SetTitle("MET");
  //  if(varName=="METvBin2") h3->GetXaxis()->SetTitle("");
  else
   h3->GetXaxis()->SetTitle(title);
  //   h3->GetXaxis()->SetTitle(varName2) 
  //if(varName=="AllSBins_v6_CD_EW_7bin"){
   cout<<"TF : "<<endl;
  for(int i=1;i<3;i++)
    {
  cout<<h3->GetBinContent(i)<<" +- "<<h3->GetBinError(i)<<endl;
    }

  
  if(ntuples=="v18")
    {
      if(ExpvsPred)  h3->GetYaxis()->SetTitle("SR/CR");
      else if(SRvsCR) h3->GetYaxis()->SetTitle("SR/CR");
    }
  else
    {
      if(SRvsCR)
	//	h3->GetYaxis()->SetTitle("N_{data}.#beta/N_{MC}");
	h3->GetYaxis()->SetTitle("#beta#upoint data/MC");
      else
	h3->GetYaxis()->SetTitle("Z(ee)/Z(#mu #mu)");
    }
  TLine *line;
  
  if(SRvsCR)  
    {
      if(varName=="AllSBins_v6_CD") line = new TLine(xmin_,0.02,xmax_,0.02);
      if(varName=="h_minDr_bestphoJets") line = new TLine(xmin_,0.005,xmax_,0.005);
      else line = new TLine(xmin_,1,xmax_,1);

      if(scale) line = new TLine(xmin_,1,xmax_,1);
      else line = new TLine(xmin_,1,xmax_,1);
      h3->GetXaxis()->SetNdivisions(10);
      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.33);
      h3->GetYaxis()->SetTitleSize(0.13);
      h3->GetYaxis()->SetLabelSize(0.13);
      h3->GetYaxis()->CenterTitle();
      h3->GetXaxis()->SetLabelSize(0.12);
      h3->GetXaxis()->SetLabelOffset(0.01);
      h3->GetXaxis()->SetTitleOffset(0.95);
      h3->GetXaxis()->SetTitleSize(0.14);

    }
  else
    {
      h3->GetYaxis()->SetNdivisions(10);
      line = new TLine(xmin_,1,xmax_,1);
      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.24);
      h3->GetYaxis()->SetTitleSize(0.15);
      h3->GetYaxis()->SetLabelSize(0.13);
      h3->GetYaxis()->CenterTitle();
      h3->GetXaxis()->SetLabelSize(0.12);
      h3->GetXaxis()->SetLabelOffset(0.01);
      h3->GetXaxis()->SetTitleOffset(0.85);
      h3->GetXaxis()->SetTitleSize(0.15);

    }
  
  line->SetLineColor(1);
  line->SetLineStyle(2);
  line->SetLineWidth(1);
  line->Draw();

  

  if(varName.Contains("nJets") || varName.Contains("nBTags")  || varName.Contains("nPhotons")){
    h3->GetXaxis()->SetNdivisions(5);
    pad2->SetTickx(0);
    h3->GetXaxis()->SetTickLength(0);
    h3->GetXaxis()->SetLabelSize(0.06);
    TString temp2;
    for(int i=1;i<=sr->GetNbinsX();i++){
      temp2 = to_string(i-1);
      if(i%2==0 && varName.Contains("nJets")) continue;
      h3->GetXaxis()->SetBinLabel(i,temp2);
    }
    h3->GetXaxis()->SetLabelSize(0.19);
    h3->GetXaxis()->SetLabelOffset(0.01);
    h3->GetXaxis()->SetTickLength(0.05);

  }

  
  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(0.9);
   h3->GetXaxis()->SetTitle("Bin no.");
  h3->GetXaxis()->SetTitleSize(0.17);
    TLine *line1V6=new TLine( 8,ymin,  8,ymax);
    TLine *line2V6=new TLine(14,ymin, 14,ymax);
    TLine *line3V6=new TLine(20,ymin, 20,ymax);
    TLine *line4V6=new TLine(26,ymin, 26,ymax);
    TLine *line5V6=new TLine(32,ymin, 32,ymax);
    TLine *line6V6=new TLine(38,ymin, 38,ymax);
    TLine *line7V6=new TLine(45,ymin, 45,ymax);
    
    pad2->cd(); pad2->SetGridx(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    if(ExpvsPred && !scale && ntuples!="v18")     h3->Write();

  }
  
  if(varName=="AllSBins_v6_CD_EW_7bin"  ){
    h3->SetTitle(0);
    h3->GetXaxis()->SetTitleOffset(0.9);
    h3->GetXaxis()->SetTitle(title);
    h3->GetXaxis()->SetTitleSize(0.17);
    h3->GetYaxis()->SetTitleSize(0.22);
    h3->GetYaxis()->SetLabelSize(0.18);

    TLine *line1V6=new TLine( 2,ymin_, 2,ymax_);
    TLine *line2V6=new TLine( 3,ymin_, 3,ymax_);
    TLine *line3V6=new TLine( 4,ymin_, 4,ymax_);

    pad2->cd(); pad2->SetGridx(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    h3->Write();
  }
  
  if(varName=="AllSBins_v6_CD"){
    h3->GetXaxis()->SetNdivisions(5);
    h3->SetTitle(0);
    h3->GetXaxis()->SetTitleOffset(1.0);
    h3->GetXaxis()->SetTitle("Bin index");
    h3->GetXaxis()->SetTitleSize(0.14);

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
    h3->Write();
    pad2->SetTickx(0);

    for(double j=1;j<=sr->GetNbinsX();j++){
      TString temp2 = to_string(j-1);
      if((j-0.5)==0.5) {temp2=to_string(1); h3->GetXaxis()->SetBinLabel(j,temp2);}
      else if((j-0.5)==1.5) {temp2=to_string(2); h3->GetXaxis()->SetBinLabel(j,temp2);}
    }
    h3->GetXaxis()->SetLabelSize(0.20);
    h3->GetXaxis()->SetLabelOffset(0.01);
    h3->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,3.5);
    TGaxis *A2 = new TGaxis(1,ymin_,3,ymin_,"f2_",2,"US");
    A2->SetTickSize(0.05);
    A2->Draw("B");



  }

  if(varName=="AllSBins_v6_CD_SP"){
    TLine *line1V6=new TLine( 6.5,ymin,  6.5,ymax);
    TLine *line2V6=new TLine(12.5,ymin, 12.5,ymax);
    TLine *line3V6=new TLine(18.5,ymin, 18.5,ymax);
    TLine *line4V6=new TLine(24.5,ymin, 24.5,ymax);
    TLine *line5V6=new TLine(30.5,ymin, 30.5,ymax);
    pad2->cd(); pad2->SetGridx(0);// pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();

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
  pad2->SetGridx(0);
  pad1->SetGridx(0);
  /* cout<<"The TF content in bin"<<endl; */
  /* for(int i=0;i<=51;i++) */
  /*   { cout<<h3->GetBinLowEdge(i)<<" : "<<h3->GetBinContent(i)<<endl;} */
  /* cout<<"==============="<<endl; */
  
  /* /\* /\\* for(int i=bin0;i<=bin1;i++) *\\/ *\/ */
  /* /\* /\\*   { cout<<TF->GetBinContent(i)<<endl;} *\\/ *\/ */
  /* /\* /\\* cout<<"The Transfer Factor error in bin"<<endl; *\\/ *\/ */
  /* for(int i=0;i<=45;i++) */
  /*   { cout<<h3->GetBinError(i)<<endl;} */
  c1->SaveAs(png);
  c1->SetCanvasSize(1600,1000);
  c1->SaveAs(pdf);

  //c1->SaveAs(png);
}

