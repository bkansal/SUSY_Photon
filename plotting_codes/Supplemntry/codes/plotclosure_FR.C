void plotclosure_FR(TString varName="AllSBins_v6_CD_EW_50bin",  TString year="full_Run2",  TString ntuples="v18" , bool ExpvsPred =true, bool SRvsCR=false)
//void plotclosure_FR(TString varName="AllSBins_v6_CD_EW_50bin",  TString year="full_Run2",  TString ntuples="v18" , bool ExpvsPred =false, bool SRvsCR=true)
{
  TFile *f1, *f2,*f3;
  string lep="LL";
  TString path;
  TFile *f_syserr= new TFile("factors/FR_sys.root");
  TH1D *syserr = (TH1D*)f_syserr->Get("JERC");
  TH1D *predsys = new TH1D("predsys","systematics",52,0,52);
  TString a="TTWGJ";
  gStyle->SetOptStat(0);
  if(ntuples=="v18")
    {
      path="rootoutput/fake_rate_v10_closure/";
    }
  else
    {
      path="/Users/bkansal/work/MET_Analysis/Analysis/fakerate/rootout/fake_rate_v8/FR_using_PhoPtQmulti_csv_cut_EMObjeta_qmulti_METCaloMET_lowdphi_nopxveto_SFnopxveto_newbin2/"; 
      
    }
  TLatex textOnTop,intLumiE,textOnTop2;
  
  TString filename,filename1;

   if(ntuples=="v18")
    {
      if(year == "full_Run2")
	{
	  filename  = path+a+"_CR_v18.root";
          filename1  = path+a+"_CR_v18.root";

	  
	}
      else
	{
	/* filename= path+"Run2017BtoE_METdata_CR_v18.root"; */
	/* filename1= path+"Run2017F_METdata_CR_v18.root"; */
	  filename= path+a+"_"+year+"_CR_v18.root";
	  filename1= path+a+"_"+year+"_CR_v18.root";
	}
    }
  else
    {
      //      filename1=path1+"Run2_METdata_CR_v18.root";
      a="Run";
      if(year == "full_Run2")
	{
	  filename  = path+"Run2_METdata_CR_v18.root";
	  filename1= path+"TTWGJ_CR_v18.root";

	}
      else 
	{	filename= path+a+year+"_METdata_CR_v18.root";
	  filename1= path+"TTWGJ_"+year+"_CR_v18.root";
	}
    }

  f1 = new TFile(filename);
  f2 = new TFile(filename1);
  
  double xmin,xmax,bin,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000000;

  TH1D *cr,*sr,*tf,*pred_sr;
 
  TString title;
  //  ExpvsPred=false,DatavsMC=true;
  //  ExpvsPred=true,DatavsMC=false;

  if(varName=="AllSBins_v6_CD_EW_50bin")
    title="closure test using optimized search bins";
  else
    title="closure test using "+ varName +" variable";
  TString png,pdf;
  if(ExpvsPred)
    {
      png="png/FR_"+varName+"_"+year+"_closure.png";
      pdf="pdf/FR_"+varName+"_"+year+"_closure.pdf";

    }
  else if(SRvsCR)
    {
      png = path+"/PDF/"+varName+"_"+year+".pdf";
      pdf= path+"/PDF/"+varName+"_"+year+".png";
    }

  TCanvas *c1 = new TCanvas("stackhist","stackhist",1600,900);
  //  TCanvas *c1;
  TString varName1,varName2;
  if(ExpvsPred)  varName2=varName+"_elec1_closure";
  else if(SRvsCR) varName2=varName;
  varName1=varName+"_elec0";
  //  varName1=varName;

  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  if(varName=="AllSBins_v6_CD_SP"){
    c1 = new TCanvas("stackhist","stackhist",1500,1500);
    if(ExpvsPred)    pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec1_closure");
    if(SRvsCR)       pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec1");
    sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
    xmin=-100000,xmax = 100000,xmin_=0,xmax_=37;
    ymin=0 , ymax=1.99, ymin_=0.0001 , ymax_=100000;
  }
  else if(varName=="AllSBins_v7_CD_SP"){
    gStyle->SetOptStat(0);
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    if(ExpvsPred)    pred_sr     = (TH1D*)f1->Get(varName2);
    if(SRvsCR)    pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1");
    /* cr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1"); */
    /* sr          = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec0"); */
    /* pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1_closure"); */
    xmin_=1,xmax_=11,xmin=1,xmax = 11,bin=10;
   ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=10000;
  pred_sr->GetXaxis()->SetTitle("Bin no.");

  }
 else if(varName=="AllSBins_v7_CD"){
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get("AllSBins_v7_CD_elec1");
    sr          = (TH1D*)f1->Get("AllSBins_v7_CD_elec0");
    pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_elec1_closure");
  pred_sr->GetXaxis()->SetTitle("Bin no.");

 }
  else if(varName=="AllSBins_v6_CD"){
    c1 = new TCanvas("stackhist","stackhist",1500,1500);
    //cr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    sr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec0");
    if(ExpvsPred) pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_elec1_closure");
    if(SRvsCR) pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
    xmin_=0,xmax_=44,xmin=0,xmax = 44,bin=45;
   ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=100000;
  }  
 else if(varName=="AllSBins_v6_CD_EW_50bin"){
   gStyle->SetOptStat(0);
   c1 = new TCanvas("stackhist","stackhist",1600,900);
    cr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");    
    sr          = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec0");
    if(ExpvsPred)   pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
    if(SRvsCR)   pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");
    pred_sr->GetYaxis()->SetTitle("Bin no.");
     
    bin=52;
    //    xmin=-100000,xmax = 100000,xmin_=0,xmax_=50;
    xmin=1,xmax = 46,xmin_=1,xmax_=46;
    //xmin=0.5,xmax = 45.5,xmin_=0.5,xmax_=45.5;

    ymin=0 , ymax=1.99, ymin_=0.012 , ymax_=10000000, yset_=2000;
    title="closure test using optimized search bins";
    pred_sr->SetTitle(0);
    for(int i=1; i<46; i++)
      {
	//	predsys->SetBinError(i+1,pow(pow(pred_sr->GetBinError(i+1)/sr->GetBinContent(i+1),2)+pow(sr->GetBinContent(i+1)*syserr->GetBinError(i)/pred_sr->GetBinContent(i+1),2),0.5));
        predsys->SetBinError(i+1,syserr->GetBinError(i));
	predsys->SetBinContent(i+1,1);	
      }

    //for(int i=1; i<46; i++)
    //  pred_sr->SetBinError(i+1,0);
    

 }

 else if(varName=="BestPhotonPt_0b_vBin" || varName=="BestPhotonPt_ge1b_vBin" ) 
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPt_ge1b" || varName=="BestPhotonPt_0b") 
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPt" || varName=="ElectronPt" || varName=="remJetPt" || varName=="JetPt" || varName=="leadJetPt" || varName=="hadAk8jetPt" || varName=="EMObj_Pt")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    if(varName=="EMObj_Pt") xmin_=0,xmax_=1000,xmin=0,xmax=1000;
    else     xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    if(varName=="hadAk8jetPt") rebin=100;
    if(varName=="BestPhotonPt") rebin=10;
    else rebin=10;

    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName=="BestPhotonPt_vBin")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName.Contains("hadAk8Mass"))
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=300,xmin=0,xmax=300;
    rebin=30;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="MET"||varName=="ST")
    {
    c1 = new TCanvas("stackhist","stackhist",1600,1000);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    if(varName=="ST")
      {
	xmin_=100,xmax_=4000,xmin=100,xmax=4000;
	rebin=10;
      }
    else
      {
      	xmin_=200,xmax_=1200,xmin=200,xmax=1200;
	rebin=5;
	title="p_{T}^{ miss}";
      }
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.05 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    //    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPhi"||varName=="BestPhotonEta" || varName=="remJetEta" || varName=="remJetPhi" ||varName=="JetEta" || varName == "JetPhi" || varName=="leadJetPhi" || varName == "leadJetEta")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f2->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=-3.5,xmax_=3.5,xmin=-3.5,xmax=3.5;
    rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.02 , ymax_=100000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="METvBin2" || varName =="METvBin_EW_v2" || varName =="METvBin_SP_v2")
    {
      
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=250,xmax_=2000,xmin=250,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=1000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
    }
 else if(varName=="nJets" || varName=="nvtx" || varName=="nJets_EW" ||varName=="nJets_SP"||varName=="Qmulti")
    {
      c1 = new TCanvas("stackhist","stackhist",1600,900);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    rebin=1;
    if(varName=="Qmulti")    rebin=2,xmin_=0,xmax_=20,xmin=0,xmax=20;
    if(varName=="nJets")    rebin=1,xmin_=2,xmax_=12,xmin=2,xmax=12, title="N_{jets}";
    if(varName=="nvtx")    rebin=2,xmin_=0,xmax_=100,xmin=0,xmax=100;
    //      xmin_=2,xmax_=16,xmin=2,xmax=16;
    ymin=0 , ymax=1.99, ymin_=0.002 , ymax_=50000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
    }
 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP"  )
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.05 , ymax_=1000000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="h_minDr_bestphoEle" || varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoremEle" || varName == "h_minDr_bestphoremJets" || varName=="h_minDr_bestphoEle_EW" || varName == "h_minDr_bestphoJets_EW" ||varName=="h_minDr_bestphoEle_SP" || varName == "h_minDr_bestphoJets_SP" || varName=="dPhi_phojet1"||varName=="dPhi_METjet1"||varName=="dPhi_phoMET")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    // rebin=20;
    //    xmin_=0,xmax_=5,xmin=0,xmax=5;
    if(varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoEle")
      {
	rebin=6;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.2 , ymax_=500000;
      }
    else if(varName == "h_minDr_bestphoremJets" || varName=="h_minDr_bestphoremEle")
      {
	rebin=4;
	xmin_=0,xmax_=5,xmin=0,xmax=5;
	ymin=0 , ymax=0.01, ymin_=0.2 , ymax_=5000;
      }
    
    else if(varName=="dPhi_phoMET")
      {
	rebin=1;
	xmin_=0,xmax_=4,xmin=0,xmax=4;
	ymin=0 , ymax=1.99, ymin_=0.002 , ymax_=10000000;
      }
    /* else */
    /*   { */
    /* 	rebin=20; */
    /* 	xmin_=-5,xmax_=5,xmin=-5,xmax=5; */
    /* 	ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=1000; */
    /*   } */
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    /* pred_sr->GetXaxis()->SetRangeUser(xmin,xmax); */
    /* sr->GetXaxis()->SetRangeUser(xmin,xmax); */
    pred_sr->SetTitle(title);
    }

  pred_sr->Print("all");
  //  for(int i=0;i<=53;i++) cout<<sr->GetBinContent(i)<<endl;
  
  //  for(int i=0;i<=53;i++) 
  //  {// cout<<pred_sr->GetBinContent(i)<<" +- "<<pred_sr->GetBinError(i)<<endl;
  //    cout<<pred_sr->GetBinContent(i)<<endl;
  //  } 

  // cout<<"==============="<<endl;
   /*
   for(int i=0;i<=53;i++)
     { cout<<pred_sr->GetBinError(i)<<endl;} 
   cout<<"The sr content"<<endl; 

  for(int i=0;i<=53;i++)
     { cout<<sr->GetBinContent(i)<<endl;}
   cout<<"==============="<<endl;

  for(int i=0;i<=53;i++)
     { cout<<sr->GetBinError(i)<<endl;}
   */
   //  cout<<"==============="<<endl; 


  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  //  pad1->SetBottomMargin(0.01);
  pad1->SetBottomMargin(0.355);
  pad1->SetRightMargin(0.03);
  //TPad *pad1 = new TPad("pad1","pad1",0,0.9,1,0.1);
  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.35);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->SetRightMargin(0.03);
  
  pad1->Draw();pad1->SetGridx(0);
  pad1->SetGridy(0);

  pad1->cd();
  pad1->SetLogy();
  pred_sr->SetTitle(0);
  // ymin_=0.0108;
  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(0.04);
  pred_sr->GetYaxis()->SetTitle("Events");
  pred_sr->GetYaxis()->SetTitleSize(0.045);
  pred_sr->GetYaxis()->SetTitleOffset(0.99);
  //  ymin_=0.005,ymax_=100000;
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(0.9);
  pred_sr->SetMarkerColor(kRed);
  pred_sr->SetLineColor(kRed);
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(0.9);
  sr->SetMarkerColor(kBlue);
  sr->SetLineColor(kBlue);

  //  (*pred_sr)=1.0*(*pred_sr);
  //  pred_sr->SetLineStyle(kBlue);
  pred_sr->Draw("e1");
  sr->Draw("e1 same");
  if(varName=="AllSBins_v6_CD_EW_50bin"){
    pred_sr->GetXaxis()->SetTickLength(0);
    TF1 *f2_=new TF1("f2_","x",1.5,46.5);
    TGaxis *A2 = new TGaxis(1,ymin_,46,ymin_,"f2_",45,"US");
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

  textOnTop.SetTextSize(0.045);
  textOnTop2.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");                                                                 
  // textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation Supplementary}}");
  //textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation}}");
  textOnTop.DrawLatexNDC(0.1,0.915,"CMS");
  textOnTop2.DrawLatexNDC(0.152,0.915," #it{#bf{Simulation Supplementary}}");

  //  textOnTop.DrawLatexNDC(0.12,0.91,"work in progress");
  if(year=="2016")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.8,0.92,"#bf{137 fb^{-1} (13 TeV)}");

  TLegend *legend = new TLegend(0.75,0.76,0.9,0.895);
  legend->SetNColumns(1);
  legend->SetBorderSize(0);
  legend->SetTextSize(0.04);
  if(ExpvsPred)
    {
      if(lep=="LE")
	{
	  legend->AddEntry(pred_sr,"Pred : TF x (1e + #gamma )","lp");
	  legend->AddEntry(sr,"Exp : (0e + #gamma )","lp");
	  /* legend->AddEntry(pred_sr,"CR : 1e + #gamma","lp"); */
	  /* legend->AddEntry(sr,"SR : 0e + #gamma","lp"); */
	}
      else if (lep=="LM")
	{
	  /* legend->AddEntry(pred_sr,"Pred : TF  (1 #mu + #gamma )","lp"); */
	  /* legend->AddEntry(sr,"Exp : (0 #mu + #gamma )","lp"); */
	  legend->AddEntry(pred_sr,"Pred : FR x N^{MC}(1 e + 0 #gamma )","lp");
	  legend->AddEntry(sr,"Exp : N^{MC}(0 e + 1 #gamma )","lp");

	}
      else if(lep=="LL")
	{
	  //legend->AddEntry(pred_sr,"Pred : f x N^{MC}_{1e 0#gamma}","lp");
	  //legend->AddEntry(sr,"Exp : N^{MC}_{0e 1#gamma}","lp");
	  /* legend->AddEntry(pred_sr,"Pred : TF x (1 l + #gamma )","lp"); */
	  /* legend->AddEntry(sr,"Exp : (0 l + #gamma )","lp"); */
	  legend->AddEntry(pred_sr,"Prediction","le1");
	  legend->AddEntry(sr,"Expectation","le1");
	}
    }
  if(SRvsCR)
    {
      if(lep=="LE")
	{
	  legend->AddEntry(pred_sr,"CR : (1e + #gamma )","lp");
	  legend->AddEntry(sr,"SR : (0e + #gamma )","lp");
	  /* legend->AddEntry(pred_sr,"CR : 1e + #gamma","lp"); */
	  /* legend->AddEntry(sr,"SR : 0e + #gamma","lp"); */
	}
      else if (lep=="LM")
	{
	  legend->AddEntry(pred_sr,"CR : (1 e + 0 #gamma )","lp");
	  legend->AddEntry(sr,"SR : (0 e + 1 #gamma )","lp");
	}
      else if(lep=="LL")
	{
	  legend->AddEntry(pred_sr,"CR : (1 e + 0 #gamma )","lp");
	  legend->AddEntry(sr,"SR : (0 e + 1 #gamma )","lp");
	  /* legend->AddEntry(pred_sr,"CR : TF x (1 l + #gamma )","lp"); */
	  /* legend->AddEntry(sr,"SR : (0 l + #gamma )","lp"); */
	}
    }
  
  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
    ymin_=0.005,ymax_=50000;
    yset_=2000;
    TLine *line1V6=new TLine( 8,ymin_,  8,ymax_);
    TLine *line2V6=new TLine(14,ymin_, 14,ymax_);
    TLine *line3V6=new TLine(19,ymin_, 19,ymax_);
    TLine *line4V6=new TLine(24,ymin_, 24,ymax_);
    TLine *line5V6=new TLine(29,ymin_, 29,ymax_);
    TLine *line6V6=new TLine(34,ymin_, 34,ymax_);
    TLine *line7V6=new TLine(40,ymin_, 40,ymax_);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    TArrow *arrow1 = new TArrow( 1,yset_, 8,yset_,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 8,yset_, 14,yset_,0.01,"<|>");
    TArrow *arrow3 = new TArrow(14,yset_, 19,yset_,0.01,"<|>");
    TArrow *arrow4 = new TArrow(19,yset_, 24,yset_,0.01,"<|>");
    TArrow *arrow5 = new TArrow(24,yset_, 29,yset_,0.01,"<|>");
    TArrow *arrow6 = new TArrow(29,yset_, 34,yset_,0.01,"<|>");
    TArrow *arrow7 = new TArrow(34,yset_, 40,yset_,0.01,"<|>");
    TArrow *arrow8 = new TArrow(40,yset_, 46,yset_,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.042);
    Tl.DrawLatex(3.275,2*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.75,2*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.5,2*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(20.25,2*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(25.25,2*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(30.25,2*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.DrawLatex(35.5,2*yset_,"V tag");
    Tl.DrawLatex(41.5,2*yset_,"H tag");

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
    TLine *line1V7=new TLine( 7,0,  7,100);
    TLine *line2V7=new TLine(12,0, 12,100);
    TLine *line3V7=new TLine(17,0, 17,100);
    TLine *line4V7=new TLine(22,0, 22,100);
    TLine *line5V7=new TLine(27,0, 27,100);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    line4V7->Draw();      line5V7->Draw();

    TArrow *arrow1 = new TArrow( -0.5,0.4, 7,0.4,0.01,"<|>");
    TArrow *arrow2 = new TArrow(7,0.4,12,0.4,0.01,"<|>");
    TArrow *arrow3 = new TArrow(12,0.4,17,0.4,0.01,"<|>");
    TArrow *arrow4 = new TArrow(17,0.4, 22,0.4,0.01,"<|>");
    TArrow *arrow5 = new TArrow(22,0.4, 27,0.4,0.01,"<|>");
    TArrow *arrow6 = new TArrow(27,0.4, 32,0.4,0.01,"<|>");
    
    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();

    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(3.,0.47,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(8.5,0.47,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(13.5,0.47,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(18.5,0.47,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(23.5,0.47,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(28.5,0.47,"N^{ #geq1}_{ #geq7}");
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

    TLine *line1V6=new TLine( 4,0,  4,1000);
    TLine *line2V6=new TLine( 8,0,  8,1000);
    TLine *line3V6=new TLine( 12,0,  12,1000);
    TLine *line4V6=new TLine( 16,0,  16,1000);
    TLine *line5V6=new TLine( 20,0,  20,1000);
    TLine *line6V6=new TLine( 24,0,  24,1000);
    TLine *line7V6=new TLine( 28,0,  28,1000);
    TLine *line8V6=new TLine( 32,0,  32,1000);
    TLine *line9V6=new TLine( 36,0,  36,1000);
    TLine *line10V6=new TLine( 40,0,  40,1000);
    // TLine *line11V6=new TLine( 44,0,  44,1000);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
    line7V6->Draw(); line8V6->Draw();
    line9V6->Draw(); line10V6->Draw();
    // line11V6->Draw();
    TArrow *arrow1 = new TArrow( 0, 100, 4, 100,0.01,"<|>");
    TArrow *arrow2 = new TArrow( 4, 100, 8, 100,0.01,"<|>");
    TArrow *arrow3 = new TArrow( 8, 100, 12, 100,0.01,"<|>");
    TArrow *arrow4 = new TArrow( 12, 100, 16, 100,0.01,"<|>");
    TArrow *arrow5 = new TArrow( 16, 100, 20, 100,0.01,"<|>");
    TArrow *arrow6 = new TArrow( 20,100, 24,100,0.01,"<|>");
    TArrow *arrow7 = new TArrow( 24,100, 28,100,0.01,"<|>");
    TArrow *arrow8 = new TArrow( 28,100, 32,100,0.01,"<|>");
    TArrow *arrow9 = new TArrow( 32,100, 36,100,0.01,"<|>");
    TArrow *arrow10 = new TArrow(36,100, 40,100,0.01,"<|>");
    TArrow *arrow11 = new TArrow(40,100, 44,100,0.01,"<|>");

        arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw();
    arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    arrow9->Draw(); arrow10->Draw();
    arrow11->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.03);
    Tl.DrawLatex(1.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(0.2,10,"[100,120]");
    Tl.DrawLatex(5.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(4.2,10,"[120,140]");
    Tl.DrawLatex(9.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(8.2,10,"[140,160]");
    Tl.DrawLatex(13.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(12.2,10,"[160,180]");
    Tl.DrawLatex(17.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(16.2,10,"[180,200]");
    Tl.DrawLatex(21.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(20.2,10,"[200,230]");
    /* Tl.DrawLatex(25.5,40,"p_{T}^{EM}"); */
    /* Tl.DrawLatex(24.2,10,"[200,230]"); */
    Tl.DrawLatex(25.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(24.2,10,"[230,260]");
    Tl.DrawLatex(29.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(28.2,10,"[260,300]");
    Tl.DrawLatex(33.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(32.2,10,"[300,380]");
    Tl.DrawLatex(37.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(36.2,10,"[380,500]");
    Tl.DrawLatex(41.5,40,"p_{T}^{EM}");
    Tl.DrawLatex(40.2,10,">=500");
    
    /* Tl.DrawLatex(2.5,0.47,"N^{ 0}_{ 3}"); */
    /* Tl.DrawLatex(3.5,0.47,"N^{ 0}_{ 4}"); */
    /* Tl.DrawLatex(4.5,0.47,"N^{ 0}_{ 5-6}"); */
    /* Tl.DrawLatex(5.5,0.47,"N^{ 0}_{ #geq7}"); */
    /* Tl.DrawLatex(6.5,0.47,"N^{ #geq1}_{ 2-4}"); */
    /* Tl.DrawLatex(7.5,0.47,"N^{ #geq1}_{ 5-6}"); */
    /* Tl.DrawLatex(8.5,0.47,"N^{ #geq1}_{ #geq7}"); */
  }
  legend->Draw();
  // legend1->Draw();
  //   ptstats->Draw();
  // ptstats2->Draw();

   TH1D *h4 = (TH1D*)pred_sr->Clone("h4");
  TH1D *h3 = (TH1D*)sr->Clone("h3");

  //  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.3);
  pad2->Draw();
  //  pad2->SetTopMargin(0);
  // pad2->SetBottomMargin(0.3);
  pad2->cd();
  pad2->SetGridx(0);
  pad2->SetGridy(1);

  h3->GetYaxis()->SetRangeUser(0.5,1.5);
  h3->SetLineColor(kBlack);
  h3->SetLineStyle(1);
  h3->SetLineWidth(2);

  if(ExpvsPred)
    {
      h3->SetMinimum(0.1);  // Define Y ..                                                                                                   
      h3->SetMaximum(1.9); // .. range                                                                                                         
    }
    
  else if(SRvsCR)
    {
      if(varName=="AllSBins_v6_CD")
	{
	  h3->SetMinimum(0);  // Define Y ..                                                                                                   
	  h3->SetMaximum(0.04); // .. range                                                                                                       
	}
      else if(varName=="h_minDr_bestphoJets")
	{
	  h3->SetMinimum(0);  // Define Y ..                                                                                                   
	  h3->SetMaximum(0.02); // .. range                                                                                                         
	}
      else
	{
	  h3->SetMinimum(0);  // Define Y ..                                                                                                   
	  h3->SetMaximum(0.02); // .. range                                                                                                         
	}
    }
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(0.6);
  // gStyle->SetOptStat(0);                                                                                                                   
  h3->Draw("E0");       // Draw the ratio plot                                                                                                
  predsys->SetFillStyle(3244);
  predsys->SetMarkerColor(kGray+1);
  predsys->SetFillColor(kGray+1);

  if(varName.Contains("AllSBins_v6_CD_EW_50bin")){  predsys->Draw("E2 sames");
    h3->Draw("E0 sames");
  }

  h3->SetTitle(0);
  if(varName=="METvBin2") h3->GetXaxis()->SetTitle("MET");
  //  if(varName=="METvBin2") h3->GetXaxis()->SetTitle("");
  else
   h3->GetXaxis()->SetTitle(title);


  //  if(ExpvsPred)  h3->GetYaxis()->SetTitle("Exp/Pred");
  if(ExpvsPred)  h3->GetYaxis()->SetTitle("#frac{Expectation}{Prediction}");
  else if(SRvsCR) h3->GetYaxis()->SetTitle("SR/CR");
  TLine *line;
  
  if(SRvsCR)  
    {
      if(varName=="AllSBins_v6_CD") line = new TLine(xmin_,0.02,xmax_,0.02);
      if(varName=="h_minDr_bestphoJets") line = new TLine(xmin_,0.005,xmax_,0.005);
      else line = new TLine(xmin_,0.01,xmax_,0.01);

      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.25);
      h3->GetYaxis()->SetTitleSize(0.20);
      h3->GetYaxis()->SetLabelSize(0.14);
      h3->GetXaxis()->SetTitleOffset(0.88);
      h3->GetXaxis()->SetTitleSize(0.17);
      h3->GetXaxis()->SetLabelSize(0.22);

    }
  else
    {
      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.36);
      h3->GetYaxis()->SetTitleSize(0.11);
      h3->GetYaxis()->SetLabelSize(0.12);
      h3->GetXaxis()->SetTitleOffset(1.0);
      h3->GetXaxis()->SetTitleSize(0.13);
      h3->GetXaxis()->SetLabelSize(0.12);
      line = new TLine(xmin_,1,xmax_,1);
    }
  
  line->SetLineColor(1);
  line->SetLineStyle(1);
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
    h3->GetXaxis()->SetLabelSize(0.20);
    h3->GetXaxis()->SetLabelOffset(0.01);
    h3->GetXaxis()->SetTickLength(0.05);
    h3->GetXaxis()->SetTitleOffset(0.86);
    h3->GetXaxis()->SetTitleSize(0.14);

  }



  
  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(1.0);
   h3->GetXaxis()->SetTitle("Bin index");
  h3->GetXaxis()->SetTitleSize(0.14);
  ymin=0.1;
  TLine *line1V6=new TLine( 8,ymin,  8,ymax);
    TLine *line2V6=new TLine(14,ymin, 14,ymax);
    TLine *line3V6=new TLine(19,ymin, 19,ymax);
    TLine *line4V6=new TLine(24,ymin, 24,ymax);
    TLine *line5V6=new TLine(29,ymin, 29,ymax);
    TLine *line6V6=new TLine(34,ymin, 34,ymax);
    TLine *line7V6=new TLine(40,ymin, 40,ymax);
    
    pad2->cd(); pad2->SetGridx(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
  }
  
  if(varName=="AllSBins_v6_CD"){
    TLine *line1V7=new TLine( 4 ,ymin,  4 ,ymax);
    TLine *line2V7=new TLine( 8 ,ymin,  8 ,ymax);
    TLine *line3V7=new TLine( 12,ymin,  12,ymax);
    TLine *line4V7=new TLine( 16,ymin,  16,ymax);
    TLine *line5V7=new TLine( 20,ymin,  20,ymax);
    TLine *line6V7=new TLine( 24,ymin,  24,ymax);
    TLine *line7V7=new TLine( 28,ymin,  28,ymax);
    TLine *line8V7=new TLine( 32,ymin,  32,ymax);
    TLine *line9V7=new TLine( 36,ymin,  36,ymax);
    TLine *line10V7=new TLine( 40,ymin,  40,ymax);


    pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);
    line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
    line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
    line7V7->Draw(); line8V7->Draw();
    line9V7->Draw(); line10V7->Draw();
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

  if(varName=="AllSBins_v7_CD_SP"){
  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(0.9);
   h3->GetXaxis()->SetTitle("Bin no.");
  h3->GetXaxis()->SetTitleSize(0.17);
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



  pad2->SetGridx(0);
  pad1->SetGridx(0);

  if(varName=="AllSBins_v6_CD_EW_50bin"){
    pad2->cd();
    
    pad2->SetTickx(0);
    double k[8]={5,10,15,20,25,30,35,40};
    int i=0;
    TString temp2;
    for(double j=1;j<=sr->GetNbinsX();j++){
      temp2 = to_string(j-1);
      // cout<<j<<" : "<<temp2<<endl;
      //temp2=to_string(j-1) ; h3->GetXaxis()->SetBinLabel(j+0.3,temp2);                                                                                                      
      
      if((j-1)==5){temp2=to_string(5); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==10){temp2=to_string(10); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==15){temp2=to_string(15); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==20){temp2=to_string(20); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==25){temp2=to_string(25); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==30){temp2=to_string(30); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==35){temp2=to_string(35); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==40){temp2=to_string(40); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==45){temp2=to_string(45); h3->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      
    }
    
    h3->GetXaxis()->LabelsOption("h");
    h3->GetXaxis()->SetLabelSize(0.20);
    h3->GetXaxis()->SetLabelOffset(0.01);
    h3->GetXaxis()->SetTickLength(0);
    TF1 *f1_=new TF1("f1_","x",1.5,46.5);
    TGaxis *A1 = new TGaxis(1,0.1,46,0.1,"f1_",45,"U");
    A1->SetLabelSize(0.1);
    A1->Draw("B");
  }
  c1->SaveAs(png);
  c1->SetCanvasSize(1600,1000);
  c1->SaveAs(pdf);
  //  c1->SaveAs(png);
}

