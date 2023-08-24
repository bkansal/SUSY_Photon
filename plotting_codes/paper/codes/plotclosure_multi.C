void plotclosure_multi(TString varName,  TString year,  TString ntuples , bool ExpvsPred = true, bool SRvsCR=false)
{
  cout<<"Hello !!!!! "<<endl;
  bool data_pred=false;
  TFile *f1, *f2,*f3,*fout;
  TString path,path1;
  TH1D *predsys = new TH1D("predsys","systematics",52,0,52);

  if(ntuples=="v18")
    {
      path="../multijet/rootoutput/final/RK_MCclosure/";
      path="../multijet/rootoutput/final/";
      cout<<path<<endl;
      path1=path;
    }
  else
    path="./";
  TLatex textOnTop,textOnTop2,intLumiE;
  TString png,pdf;
  
  TString filename,filename1,filename2;
  TString b="Run2_METdata";
  TString a="GJetsQCD_new";
  TString rootout;
  if(ntuples=="v18" || ntuples=="v16")
    {
      if(SRvsCR && varName=="AllSBins_v7_CD_SP")
	{ if(year=="full_Run2") rootout="Rfactor_lowMET_MC.root";
	  else rootout="Rfactor_lowMET_"+year+".root";
	}
      if(ExpvsPred && varName=="AllSBins_v7_CD_SP")
	{ if(year=="full_Run2") rootout="Rfactor_highMET.root";
	  else rootout="Rfactor_highMET_"+year+".root";
	}
  
      if(data_pred)
	{
	  if(year == "full_Run2")
	    {
	      filename  = path+"Run2_METdata_CR_v18.root";
              filename1  = path+a+"_v18.root";
	    }
	  else
	    {
	      filename= path+"Run"+year+"_METdata_CR_v18.root";  
              filename1= path+a+"_"+year+"_v18.root";
	    }
	  f2 = new TFile(filename);
	  f1 = new TFile(filename);

	}
      
      if(!data_pred)
	{
	  if(year == "full_Run2")
	    {
	      filename  = path+a+"_v18.root";
              filename1  = path1+a+"_v18.root";
	      // if(SRvsCR) rootout="Rfactor_lowMET.root";
	      //if(ExpvsPred) rootout="Rfactor_highMET.root";
	    }
	  else 
	    {
	      filename= path1+a+"_"+year+"_v18.root";
              filename1= path1+a+"_"+year+"_v18.root";
	      //  rootout="Rfactor_"+year+".root";
	    }
	  f1 = new TFile(filename);
          f2 = new TFile(filename1);

	}
    }
  else
    {
      if(year == "full_Run2")
       {
	  f1 = new TFile("Rfactor_lowMET.root");
	  f2 = new TFile("Rfactor_highMET.root");
	  rootout="Kfactor.root";
	}
      else
	{
	  rootout="Rfactor_lowMET_"+year+".root";
          f1 = new TFile(rootout);
	  rootout="Rfactor_highMET_"+year+".root";
          f2 = new TFile(rootout);
	  rootout="Kfactor_"+year+".root";

	}
    }
  
  

  double xmin,xmax,bin,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000;

  TH1D *cr,*sr,*tf,*pred_sr;
 
  TString title;


  if(varName=="AllSBins_v6_CD_EW_50bin")
    title="closure test using optimized search bins";
  else
    title="closure test using "+ varName +" variable";


  //  TCanvas *c1 = new TCanvas("stackhist","stackhist",600,500);
  TCanvas *c1;
  TString varName1,varName2;

  if(ntuples=="v18")
    {
      if(ExpvsPred)
	{
	  if(varName=="nJetsMET")
	    {
	      varName2=varName+"_Q";
	      varName1=varName+"_S";
	      if(year == "full_Run2")    rootout="Kfactor_Htag.root";
	      else     rootout="Kfactor_Htag_"+year+".root";
              pdf="pdf/Multi_"+varName+"_"+year+"_Kfactor_Htag.pdf";
              png="png/Multi_"+varName+"_"+year+"_Kfactor_Htag.png";

	    }
	  else
	    {
	      varName2=varName+"_AB";
	      varName1=varName+"_CD";
	    }
	}
      else if(SRvsCR)
	{
          if(varName=="nJetsMET")
	    {
	      varName2=varName+"_P";
	      varName1=varName+"_R";
	      if(year == "full_Run2")    rootout="Kfactor_Wtag.root";
	      else     rootout="Kfactor_Wtag_"+year+".root";
	      pdf="pdf/Multi_"+varName+"_"+year+"_Kfactor_Wtag.pdf";
	      png="png/Multi_"+varName+"_"+year+"_Kfactor_Wtag.png";

	    }
	  else
	    {
	      varName2=varName+"_A";
	      varName1=varName+"_C";
	    }
	}
    }
  
  
  double nbin,bin0, bin1,yset_;
  TH1D *total;
  int rebin=1;
  if(varName=="AllSBins_v6_CD_SP"){
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    if(ExpvsPred)    pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec1_closure");
    if(SRvsCR)       pred_sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec1");
    sr          = (TH1D*)f1->Get("AllSBins_v6_CD_SP_elec0");
    xmin=-100000,xmax = 100000,xmin_=0,xmax_=37;
    ymin=0 , ymax=1.99, ymin_=0.0001 , ymax_=1000;
  }
  else if(varName=="AllSBins_v6_CD_EW_7bin"){
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    pred_sr          = (TH1D*)f1->Get(varName2);
    sr          = (TH1D*)f1->Get(varName1);
    xmin=1,xmax = 33,xmin_=1,xmax_=33;
    ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=10000;
  }
  else if(varName=="AllSBins_v7_CD_SP"){
    gStyle->SetOptStat(0);
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    if(!data_pred){
      pred_sr          = (TH1D*)f1->Get(varName2);
      sr     = (TH1D*)f1->Get(varName1);
    }
    else
      {
	pred_sr          = (TH1D*)f2->Get(varName2);
	sr     = (TH1D*)f2->Get(varName1);
      }
    xmin_=1,xmax_=9,xmin=1,xmax = 9,bin=8;
   ymin=0 , ymax=10, ymin_=0.03 , ymax_=100000000;
   pred_sr->GetXaxis()->SetTitle("Bin index");
   //   TString rootout="Rfactor.root";
   pdf="pdf/Multi_"+varName+"_"+year+"_Rfactor_MC.pdf";
   png="png/Multi_"+varName+"_"+year+"_Rfactor_MC.png";

   fout =new TFile(rootout,"recreate");
   fout->cd();
   cout<<"root file name : "<<rootout<<endl;


  }
 else if(varName=="AllSBins_v7_CD"){
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get("AllSBins_v7_CD_elec1");
    sr          = (TH1D*)f1->Get("AllSBins_v7_CD_elec0");
    pred_sr     = (TH1D*)f1->Get("AllSBins_v7_CD_elec1_closure");
  pred_sr->GetXaxis()->SetTitle("Bin index");

 }
  else if(varName=="AllSBins_v6_CD"){
    //cr          = (TH1D*)f1->Get("AllSBins_v6_CD_elec1");
    gStyle->SetOptStat(0);

    c1 = new TCanvas("stackhist","stackhist",1000,600);

    pred_sr          = (TH1D*)f1->Get(varName2);
    sr     = (TH1D*)f1->Get(varName1);
    xmin_=1,xmax_=8,xmin=1,xmax = 9,bin=8;
   ymin=0 , ymax=1.99, ymin_=0.01 , ymax_=1000;
   pred_sr->GetXaxis()->SetTitle("Bin index");

   fout =new TFile(rootout,"recreate");
   fout->cd();
   cout<<"root file name : "<<rootout<<endl;
  }  
 else if(varName=="AllSBins_v6_CD_EW_50bin"){
   gStyle->SetOptStat(0);
   //c1 = new TCanvas("stackhist","stackhist",1000,600);
   c1 = new TCanvas("stackhist","stackhist",1600,900);
   cr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");    
    if(data_pred)
      {
	sr          = (TH1D*)f1->Get(varName1);
	pred_sr     = (TH1D*)f1->Get(varName2);
      }
	//	if(SRvsCR)   pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");
    else{
        sr          = (TH1D*)f2->Get(varName1);
        pred_sr     = (TH1D*)f2->Get(varName2);

    }
    pred_sr->GetYaxis()->SetTitle("Bin index");
     
    bin=51.5;
    //    xmin=-100000,xmax = 100000,xmin_=0,xmax_=50;
    //  xmin=-1,xmax = 50,xmin_=-1,xmax_=50;
    xmin=1,xmax = 46,xmin_=1,xmax_=46;
    //ymin=0 , ymax=1.99, ymin_=0.005 , ymax_=100000, yset_=500;
    //    ymin=0 , ymax=1.99, ymin_=0.0001 , ymax_=100000;
    ymin=0 , ymax=1.99, ymin_=0.012 , ymax_=10000000, yset_=2000;

    title="closure test using optimized search bins";
    pred_sr->SetTitle(0);
    pdf="pdf/Multi_"+varName+"_"+year+"_51bin_closure.pdf";
    png="png/Multi_"+varName+"_"+year+"_51bin_closure.png";
    for(int i=1; i<46; i++)
      {
        //predsys->SetBinError(i+1,syserr->GetBinError(i));
	if(i>=1 && i<8 ) predsys->SetBinError(i+1,0.32);
	else if(i>=8 && i<14 ) predsys->SetBinError(i+1,0.10);
	else if(i>=14 && i<19 ) predsys->SetBinError(i+1,0.18);
	else if(i>=19 && i<24 ) predsys->SetBinError(i+1,0.36);
	else if(i>=24 && i<29 ) predsys->SetBinError(i+1,0.20);
	else if(i>=29 && i<34 ) predsys->SetBinError(i+1,0.36);
	else if(i>=34 && i<40 ) predsys->SetBinError(i+1,0.31);
	else if(i>=40 && i<46 ) predsys->SetBinError(i+1,0.23);

	predsys->SetBinContent(i+1,1);
      }

 }

  else if(varName=="nJetsMET"){
    gStyle->SetOptStat(0);
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    pred_sr = (TH1D*)f1->Get(varName2);
    sr     = (TH1D*)f1->Get(varName1);
    xmin_=1,xmax_=11,xmin=1,xmax = 11,bin=10;
    ymin=0 , ymax=10, ymin_=0.01 , ymax_=1000;
    //    pred_sr->GetXaxis()->SetTitle("Bin index");
    //   TString rootout="Rfactor.root";
                                            
    fout =new TFile(rootout,"recreate");
    fout->cd();
    cout<<"root file name : "<<rootout<<endl;
  }
 
 else if(varName=="BestPhotonPt_0b_vBin" || varName=="BestPhotonPt_ge1b_vBin" ) 
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
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
    c1 = new TCanvas("stackhist","stackhist",600,500);
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
 else if(varName=="BestPhotonPt" || varName=="ElectronPt" || varName=="JetPt" || varName=="leadJetPt" || varName=="hadAk8jetPt")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=2000,xmin=0,xmax=2000;
    if(varName=="hadAk8jetPt") rebin=100;
    if(varName=="BestPhotonPt") rebin=10;
    else rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.1 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName=="BestPhotonPt_vBin")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
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
 else if( varName=="hadAk8Mass")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
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
    c1 = new TCanvas("stackhist","stackhist",2600,1800);
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
      	xmin_=100,xmax_=1200,xmin=100,xmax=1200;
	rebin=5;
      }
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPhi"||varName=="BestPhotonEta"||varName=="JetEta" || varName == "JetPhi" || varName=="leadJetPhi" || varName == "leadJetEta")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=-5,xmax_=5,xmin=-5,xmax=5;
    rebin=10;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if(varName=="METvBin2" || varName =="METvBin_EW_v2" || varName =="METvBin_SP_v2")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
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
 else if(varName=="nJets" || varName=="nJets_EW" ||varName=="nJets_SP")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f2->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=2,xmax_=11,xmin=2,xmax=11;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
    }
 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP"  )
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   }
 else if(varName=="h_minDr_bestphoEle" || varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoEle_EW" || varName == "h_minDr_bestphoJets_EW" ||varName=="h_minDr_bestphoEle_SP" || varName == "h_minDr_bestphoJets_SP" || varName=="dPhi_phojet1"||varName=="dPhi_METjet1")
    {
    c1 = new TCanvas("stackhist","stackhist",600,500);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    // rebin=20;
    //    xmin_=0,xmax_=5,xmin=0,xmax=5;
    rebin=20;
    xmin_=-5,xmax_=5,xmin=-5,xmax=5;
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=1000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    pred_sr->SetTitle(title);
    }
 else
   {
     gStyle->SetOptStat(0);
     c1 = new TCanvas("stackhist","stackhist",1000,600);
     if(ntuples=="v18")  {varName="h3";}
     pred_sr          = (TH1D*)f1->Get(varName);
     sr     = (TH1D*)f2->Get(varName);
     
     //     if(varName=="AllSBins_v7_CD_SP") xmin_=1,xmax_=11,xmin=1,xmax = 11,bin=10;
     //if(varName=="AllSBins_v6_CD")
       xmin_=1,xmax_=9,xmin=1,xmax = 9,bin=8;
     ymin=0 , ymax=1, ymin_=0 , ymax_=1;
     pred_sr->GetXaxis()->SetTitle("Bin index");
     cout<<varName<<endl;
     fout =new TFile(rootout,"recreate");
     fout->cd();
     cout<<"root file name : "<<rootout<<endl;
   }

  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  pad1->SetBottomMargin(0);
  pad1->SetBottomMargin(0.355);
  pad1->SetRightMargin(0.03);

  pad1->Draw();pad1->SetGridx();

  pad1->cd();
  if(ntuples=="v18")  pad1->SetLogy();
    pred_sr->SetTitle(0);

  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(0.05);
  pred_sr->GetYaxis()->SetTitle("Events");
  pred_sr->GetYaxis()->SetTitleSize(0.05);
  pred_sr->GetYaxis()->SetTitleOffset(0.82);
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(0.9);
  pred_sr->SetMarkerColor(kRed);
  pred_sr->SetLineColor(kRed);
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(0.9);
  sr->SetMarkerColor(kBlue);
  sr->SetLineColor(kBlue);

  
  //  pred_sr->SetLineStyle(kBlue);
  pred_sr->Draw("e1");
  sr->Draw("e1 same");
  pred_sr->GetXaxis()->SetTickLength(0);
  TF1 *f2_=new TF1("f2_","x",1.5,46.5);
  TGaxis *A2 = new TGaxis(1,ymin_,46,ymin_,"f2_",45,"US");
  A2->SetTickSize(0.02);
  A2->Draw("B");

   double chi=pred_sr->Integral();
  // double chi=pred_sr->Chi2Test(sr,"WW CHI2");
  int NDF=chi/pred_sr->Chi2Test(sr,"WW CHI2/NDF");
  double p=sr->Integral();
  //  double p=pred_sr->Chi2Test(sr,"WW p");
  textOnTop.SetTextSize(0.045);
  textOnTop2.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Preliminary }}");                                                                 
  //  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Preliminary }}");
  textOnTop.DrawLatexNDC(0.1,0.915,"CMS");
  textOnTop2.DrawLatexNDC(0.15,0.915," #it{#bf{Preliminary }}");

  if(year=="2016")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.7,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.818,0.92,"#bf{137 fb^{-1} (13 TeV)}");
  char chi2[1000],chi1[1000];
  // sprintf(chi2,"Chi2/NDF = %f",chi_NDF);
  sprintf(chi1,"Chi2/NDF = %f / %d , p = %f",chi,NDF,p);

  //  TLegend *legend = new TLegend(0.7,0.8,0.9,0.9);
  TLegend *legend = new TLegend(0.76,0.76,0.9,0.895);
  legend->SetNColumns(1);
  legend->SetBorderSize(0);
  TLegend *legend1 = new TLegend(0.1,0.82,0.45,0.9);
  //  legend1->SetHeader("with HEM veto","C");                               // option "C" allows to center the header                                      
  //  legend1->SetHeader(chi2,"C");
  legend1->SetHeader(chi1,"C");
  //  legend1->SetHeader(p,"C");
  cout<<"Chi ===> "<<chi<<endl;
  cout<<"Chi1 ===> "<<chi1<<endl;
  legend1->SetTextSize(0.04);
  legend->SetTextSize(0.06);
  // legend1->Draw();
  if(ntuples=="v18")
    {
      if(SRvsCR)
	{
	  legend->AddEntry(pred_sr,"A : (low dphi & low MET )","lp");
	  legend->AddEntry(sr,"C : (high dphi & low MET )","lp");
	}
      if(ExpvsPred)
	{
	  //	  legend->AddEntry(pred_sr,"B : (low dphi & high MET )","lp");
	  //	  legend->AddEntry(sr,"D : (high dphi & high MET )","lp");
          legend->AddEntry(pred_sr,"Prediction","le1");
          legend->AddEntry(sr,"Expectation","le1");

	}
    }
  else
    {
      legend->AddEntry(pred_sr,"R factor (low MET )","lp");
      legend->AddEntry(sr,"R factor(high MET )","lp");

    }
  legend->SetTextSize(0.04);
  
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
    TLine *line8V6=new TLine(46,ymin_, 46,ymax_);

    pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();  line8V6->Draw();
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
	//        TLine *line10V6=new TLine( 10,0,  10,ymax_);
	//        TLine *line11V6=new TLine( 11,0,  11,ymax_);
	//        TLine *line12V6=new TLine( 12,0,  12,ymax_);

        pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
        line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
        line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
        line7V6->Draw(); line8V6->Draw();
        line9V6->Draw();// line10V6->Draw();
	// line11V6->Draw(); line12V6->Draw();

	TArrow *arrow1 = new TArrow( 1, 0.1, 2, 0.1,0.01,"<|>");
        TArrow *arrow2 = new TArrow( 2, 0.1, 3, 0.1,0.01,"<|>");
        TArrow *arrow3 = new TArrow( 3, 0.1, 4, 0.1,0.01,"<|>");
        TArrow *arrow4 = new TArrow( 4, 0.1, 5, 0.1,0.01,"<|>");
        TArrow *arrow5 = new TArrow( 5, 0.1, 6, 0.1,0.01,"<|>");
        TArrow *arrow6 = new TArrow( 6,0.1, 7,0.1,0.01,"<|>");
        TArrow *arrow7 = new TArrow( 7,0.1, 8,0.1,0.01,"<|>");
        TArrow *arrow8 = new TArrow( 8,0.1, 9,0.1,0.01,"<|>");
        //TArrow *arrow9 = new TArrow( 9, 0.1, 10, 0.1,0.01,"<|>");
	//        TArrow *arrow10 = new TArrow( 10,0.1, 11,0.1,0.01,"<|>");
        //TArrow *arrow11 = new TArrow( 1,0.7, 9,0.7,0.01,"<|>");
        //TArrow *arrow12 = new TArrow( 9,0.7, 11,0.7,0.01,"<|>");

        arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
        arrow4->Draw();
        arrow5->Draw(); arrow6->Draw();
        arrow7->Draw(); arrow8->Draw();
	//        arrow9->Draw(); //arrow10->Draw();
	//        arrow11->Draw(); arrow12->Draw();
      TLatex Tl,T2;
        Tl.SetTextSize(0.05);
        Tl.DrawLatex(1.25,0.2,"N^{ 0}_{ 2-5}");
	//        Tl.DrawLatex(2.25,0.2,"N^{ 0}_{ 3}");
        //Tl.DrawLatex(3.25,0.2,"N^{ 0}_{ 4}");
        Tl.DrawLatex(2.25,0.2,"N^{ 0}_{ 5-6}");
        Tl.DrawLatex(3.25,0.2,"N^{ 0}_{ #geq7}");
        Tl.DrawLatex(4.25,0.2,"N^{ #geq1}_{ 2-4}");
        Tl.DrawLatex(5.25,0.2,"N^{ #geq1}_{ 5-6}");
        Tl.DrawLatex(6.25,0.2,"N^{ #geq1}_{ #geq7}");
        Tl.DrawLatex(7,0.2,"W tag");
        Tl.DrawLatex(8,0.2,"H tag");
        T2.DrawLatex(2.5,10,"SP region");
        T2.DrawLatex(7.5,10,"EW region");
 

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

    TLine *line1V6=new TLine( 1,0,  1,1000);
    TLine *line2V6=new TLine( 2,0,  2,1000);
    TLine *line3V6=new TLine( 3,0,  3,1000);
    TLine *line4V6=new TLine( 4,0,  4,1000);
    TLine *line5V6=new TLine( 5,0,  5,1000);
    TLine *line6V6=new TLine( 6,0,  6,1000);
    TLine *line7V6=new TLine( 7,0,  7,1000);
    TLine *line8V6=new TLine( 8,0,  8,1000);

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
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(1.5,0.47,"N^{ 0}_{ 2}");
    Tl.DrawLatex(2.5,0.47,"N^{ 0}_{ 3}");

    Tl.DrawLatex(3.5,0.47,"N^{ 0}_{ 4}");

    Tl.DrawLatex(4.5,0.47,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(5.5,0.47,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(6.5,0.47,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(7.5,0.47,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(8.5,0.47,"N^{ #geq1}_{ #geq7}");
  }

  legend->Draw();
  
  
   TH1D *h4 = (TH1D*)pred_sr->Clone("h4");
  TH1D *h3 = (TH1D*)sr->Clone("h3");

  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.35);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->SetRightMargin(0.03);
  pad2->cd();
  pad2->SetGrid(0);

  h3->GetYaxis()->SetRangeUser(0.5,1.5);
  /*h3->GetXaxis()->SetRangeUser(xmin,xmax); */
  /* h4->GetXaxis()->SetRangeUser(xmin,xmax); */

  
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
      h3->SetMinimum(0);  // Define Y ..                                                                                                   
      h3->SetMaximum(2); // .. range                                                                                                         
    }
  //  if(varName=="AllSBins_v7_CD_SP")  h3->SetMaximum(1.49);
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
  h3->GetXaxis()->SetTitleOffset(0.9);
   h3->GetXaxis()->SetTitle(varName);
  h3->GetXaxis()->SetTitleSize(0.15);
  h3->GetXaxis()->SetLabelSize(0.22);

  if(ntuples=="v18")
    {
      if(ExpvsPred)  h3->GetYaxis()->SetTitle("#frac{Expectation}{Prediction}");
      //      if(ExpvsPred)  h3->GetYaxis()->SetTitle("D/A");
      if(SRvsCR) h3->GetYaxis()->SetTitle("R=C/A");
      
      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.36);
      h3->GetYaxis()->SetTitleSize(0.12);
      h3->GetYaxis()->SetLabelSize(0.14);
      h3->GetXaxis()->SetTitleOffset(1.0);
      h3->GetXaxis()->SetTitleSize(0.14);
      h3->GetXaxis()->SetLabelSize(0.14);
    }
  else
    {
      if(varName=="h3") h3->GetYaxis()->SetTitle("#frac{R(high MET)}{R(low MET)}");

      h3->GetYaxis()->SetNdivisions(5);
      h3->GetYaxis()->SetTitleOffset(0.25);
      h3->GetYaxis()->SetTitleSize(0.16);
      h3->GetYaxis()->SetLabelSize(0.20);
      h3->GetXaxis()->SetTitle("Bin index");
    }
  TLine *line;
  
  if(SRvsCR)
    line = new TLine(xmin_,0.5,xmax_,0.5);
  else
    line = new TLine(xmin_,1.0,xmax_,1.0);

  line->SetLineColor(1);
  line->SetLineStyle(1);
  line->SetLineWidth(1);
  if(varName!="AllSBins_v7_CD_SP")  line->Draw();

  

  ymin=0.1;
  if(varName=="AllSBins_v6_CD_EW_50bin"  ){
  h3->SetTitle(0);
  h3->GetXaxis()->SetTitleOffset(1.0);
   h3->GetXaxis()->SetTitle("Bin index");
  h3->GetXaxis()->SetTitleSize(0.14);
    TLine *line1V6=new TLine( 8,ymin,  8,ymax);
    TLine *line2V6=new TLine(14,ymin, 14,ymax);
    TLine *line3V6=new TLine(19,ymin, 19,ymax);
    TLine *line4V6=new TLine(24,ymin, 24,ymax);
    TLine *line5V6=new TLine(29,ymin, 29,ymax);
    TLine *line6V6=new TLine(34,ymin, 34,ymax);
    TLine *line7V6=new TLine(40,ymin, 40,ymax);
    TLine *line8V6=new TLine(46,ymin, 46,ymax);
    
    pad2->cd(); pad2->SetGridx(0);

    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();  line8V6->Draw();
  }
  
  if(varName=="AllSBins_v6_CD"){
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
   h3->GetXaxis()->SetTitle("Bin index");
  h3->GetXaxis()->SetTitleSize(0.17);
    TLine *line1V7=new TLine( 1,ymin,  1,ymax);
        TLine *line2V7=new TLine( 2,ymin,  2,ymax);
        TLine *line3V7=new TLine( 3,ymin,  3,ymax);
        TLine *line4V7=new TLine( 4,ymin,  4,ymax);
        TLine *line5V7=new TLine( 5,ymin,  5,ymax);
	TLine *line6V7=new TLine( 6,ymin,  6,ymax);
        TLine *line7V7=new TLine( 7,ymin,  7,ymax);
        TLine *line8V7=new TLine( 8,ymin,  8,ymax);
        TLine *line9V7=new TLine( 9,ymin,  9,ymax);
	TLine *line10V7=new TLine( 10,ymin,  10,ymax);


        pad2->cd(); pad2->SetGridx(0);// pad2->SetGridy(0);                                                                                                                  
        line1V7->Draw();      line2V7->Draw();  line3V7->Draw();
        line4V7->Draw();      line5V7->Draw(); line6V7->Draw();
        line7V7->Draw(); line8V7->Draw();
        line9V7->Draw(); line10V7->Draw();
	h3->Write();
  }
  if(varName == "h3")    h3->Write();
  if(varName=="nJetsMET") h3->Write();
  bin1=xmax-xmin;
  TString temp2;
  for(double j=1;j<=sr->GetNbinsX();j++){
    temp2 = to_string(j-1);
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
  TGaxis *A1 = new TGaxis(1,ymin,46,ymin,"f1_",45,"U");
  A1->SetLabelSize(0.1);
  A1->Draw("B");
  
  c1->SetCanvasSize(2600,1800);
  c1->SaveAs(pdf);
  c1->SaveAs(png);
}

