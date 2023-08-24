void plotclosure_LL(TString varName="AllSBins_v6_CD_EW_50bin",  TString year="full_Run2",  TString ntuples="v18" , bool ExpvsPred = true, bool SRvsCR=false)
{
  gStyle->SetOptStat(0);
  bool data_pred=false;
  TFile *f1, *f2,*f3;
  TH1D *cr,*sr,*tf,*pred_sr,*total;
  string lep="LL";
  TString title,filename,filename1,png,pdf;
  TLatex textOnTop,intLumiE, textOnTop2;
  double xmin,xmax,bin,bin1,xmin_,xmax_;
  double ymin=0.5 , ymax=1.5, ymin_=0.0001 , ymax_=1000, yset_;

  //// Systematics for LL ////////////
  TFile *f_= new TFile("../lostlepton/Lostlepton_highdphi.root");
  TH1D *fr = (TH1D*)f_->Get("fr");
  TFile *f_syserr= new TFile("factors/LL_sys_v1.root");
  TH1D *syserr = (TH1D*)f_syserr->Get("JERC");
  TH1D *prederr = (TH1D*)f_syserr->Get("JERC");
  TH1D *predsys = new TH1D("predsys","systematics",52,0,52);
  ///////////////////////////////////
  
  TString path="rootoutput/LL_closure/";
  TString path1=path;
  TString b="Run2_METdata";
  TString a="TTWGJ";
  
  if(year == "full_Run2")
    {
      filename  = path+a+"_CR_v18.root";
      filename1  = path+a+"_CR_v18.root";
    }
  else
    {
      filename= path+a+"_"+year+"_CR_v18.root";
      filename1= path+a+"_"+year+"_CR_v18.root";
      //      filename1= path+"Run"+year+"_METdata_CR_v18.root";
    }
  f2 = new TFile(filename1);  
  f1 = new TFile(filename);
  

  if(ExpvsPred)
    {
      
      png="png/LL_"+varName+"_"+year+"_closure.png";
      pdf="pdf/LL_"+varName+"_"+year+"_closure.pdf";
      //pdf= path+"/PDF/closure/"+varName+"_"+year+".png";
    }
  else if(SRvsCR)
    {
      png = path+"/PDF/TF/"+varName+"_"+year+".pdf";
      pdf= path+"/PDF/TF/"+varName+"_"+year+".png";
    }

  TCanvas *c1;

  TString varName1,varName2;
  if(ExpvsPred)  varName2=varName+"_elec1_closure";
  else if(SRvsCR) varName2=varName;
  varName1=varName+"_elec0";

  int rebin=1;
  if(varName=="AllSBins_v6_CD_EW_50bin"){
   gStyle->SetOptStat(0);
   c1 = new TCanvas("stackhist","stackhist",1600,1000);

   cr          = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec1");
   sr          = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec0");
   if(ExpvsPred)   pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
   if(SRvsCR)   pred_sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec1");

   pred_sr->GetYaxis()->SetTitle("Bin no.");     
   bin=51.5;
   xmin=1,xmax = 46,xmin_=1,xmax_=46;
   ymin=0 , ymax=1.99, ymin_=0.012 , ymax_=10000000, yset_=2000;
   title="closure test using optimized search bins";
   pred_sr->SetTitle(0);
   sr->SetBinError(14,pow(sr->GetBinError(14)*sr->GetBinError(14)+0.185*0.185,0.5));
   for(int i=1; i<46; i++)
     {

       //       predsys->SetBinError(i+1,pow(pow(pred_sr->GetBinError(i+1)/pred_sr->GetBinContent(i+1),2)+pow(syserr->GetBinError(i),2),0.5));
       //       if(i>=24 && i<29 ) predsys->SetBinError(i+1,4*syserr->GetBinError(i));

       //else predsys->SetBinError(i+1,2*syserr->GetBinError(i));
       predsys->SetBinError(i+1,pow(pow(fr->GetBinError(i+1)/fr->GetBinContent(i+1),2)+pow(2*syserr->GetBinError(i),2),0.5));
       //       predsys->SetBinError(i+1,2*syserr->GetBinError(i));
       predsys->SetBinContent(i+1,1);
       //    pred_sr->SetBinError(i+1,pow((pow(cr->GetBinContent(i+1)*fr->GetBinError(i+1),2) + pow(cr->GetBinError(i+1)*fr->GetBinContent(i+1),2)),0.5));
     }
   
  }
 else if(varName=="BestPhotonPt" || varName=="ElectronPt" || varName=="JetPt" || varName=="leadJetPt" || varName=="hadAk8jetPt")
    {
      c1 = new TCanvas("stackhist","stackhist",1000,600);
      cr          = (TH1D*)f1->Get(varName);
      sr          = (TH1D*)f1->Get(varName1);
      pred_sr     = (TH1D*)f2->Get(varName2);
      xmin_=0,xmax_=1000,xmin=0,xmax=1000;
      if(varName=="hadAk8jetPt") rebin=100;
      if(varName=="BestPhotonPt") {rebin=10;  title="p_{T}^{#gamma}";}
      else rebin=10;
      pred_sr->Rebin(rebin);
      sr->Rebin(rebin);
      ymin=0 , ymax=1.99, ymin_=0.5 , ymax_=10000;
      pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
      sr->GetXaxis()->SetRangeUser(xmin,xmax);
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
    ymin=0 , ymax=1.99, ymin_=0.5 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
  pred_sr->SetTitle(title);

    }
 else if( varName=="hadAk8Mass")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    xmin_=0,xmax_=300,xmin=0,xmax=300;
    rebin=30;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.5 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
    title="M_{lead Ak8 jet}";
    pred_sr->SetTitle(title);

    }
 else if(varName=="MET"||varName=="ST")
    {
    c1 = new TCanvas("stackhist","stackhist",1600,1000);
    cr          = (TH1D*)f2->Get(varName);
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
    cr->Rebin(rebin);
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=10000;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="closure test using "+ varName +" variable";
    if(varName=="MET") title="p_T^{miss}";
    if(varName=="ST") title="ST";

    pred_sr->SetTitle(title);

    }
 else if(varName=="BestPhotonPhi"||varName=="BestPhotonEta"||varName=="JetEta" || varName == "JetPhi" || varName=="leadJetPhi" || varName == "leadJetEta")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
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
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f1->Get(varName2);
    //    xmin_=250,xmax_=2000,xmin=250,xmax=2000;
    rebin=1;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    ymin=0 , ymax=1.99, ymin_=0.001 , ymax_=100;
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    title="p^{miss}_{T}";
  pred_sr->SetTitle(title);
    }
 else if(varName=="nJets" || varName=="nJets_EW" ||varName=="nJets_SP")
    {
    c1 = new TCanvas("stackhist","stackhist",1600,1000);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=2,xmax_=11,xmin=2,xmax=11;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->SetTitle(title);
  title="N_{jets}";
    }
 else if(varName=="nBTags" || varName=="nBTags_EW" || varName=="nBTags_SP"  )
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    xmin_=0,xmax_=8,xmin=0,xmax=8;
    rebin=1;
    ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=100000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
   pred_sr->SetTitle(title);
   title="N_{b-tag}";
   }
 else if(varName=="h_minDr_bestphoEle" || varName == "h_minDr_bestphoJets" || varName=="h_minDr_bestphoEle_EW" || varName == "h_minDr_bestphoJets_EW" ||varName=="h_minDr_bestphoEle_SP" || varName == "h_minDr_bestphoJets_SP" || varName=="dPhi_phojet1"||varName=="dPhi_METjet1" || varName=="h_mindr_lep_goodph" || varName=="h_mindr_genph_lep")
    {
    c1 = new TCanvas("stackhist","stackhist",1000,600);
    cr          = (TH1D*)f1->Get(varName);
    sr          = (TH1D*)f1->Get(varName1);
    pred_sr     = (TH1D*)f2->Get(varName2);
    // rebin=20;
    xmin_=0,xmax_=1,xmin=0,xmax=1;
    rebin=1;
    xmin_=-5,xmax_=5,xmin=-5,xmax=5;
     rebin=10;       
     ymin=0 , ymax=1.99, ymin_=0.2 , ymax_=1000;
    pred_sr->Rebin(rebin);
    sr->Rebin(rebin);
    pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
    sr->GetXaxis()->SetRangeUser(xmin,xmax);
    pred_sr->SetTitle(title);
    }

  sr->Print("all");
  /*
  for(int i=0;i<=53;i++) 
    { cout<<i<<" , CR : "<<cr->GetBinContent(i)<<"+-"<<cr->GetBinError(i)<<" , Pred : SR : "<<pred_sr->GetBinContent(i)<<" ,  SR : "<<sr->GetBinContent(i)<<"+-"<<sr->GetBinError(i)<<endl;} 
  */
  //  cout<<"==============="<<endl; 
  c1->cd();
  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  pad1->SetBottomMargin(0);
  pad1->SetBottomMargin(0.355);
  pad1->SetRightMargin(0.03);
  pad1->Draw();pad1->SetGridx();

  pad1->cd();

  pad1->SetLogy();
  pred_sr->SetTitle(0);
  pad1->SetGridx(0); pad1->SetGridy(0);

  pred_sr->GetXaxis()->SetRangeUser(xmin,xmax);
  sr->GetXaxis()->SetRangeUser(xmin,xmax);
  pred_sr->GetYaxis()->SetLabelSize(0.05);
  pred_sr->GetYaxis()->SetTitle("Events");
  pred_sr->GetYaxis()->SetTitleSize(0.05);
  pred_sr->GetYaxis()->SetTitleOffset(0.82);
  sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->GetYaxis()->SetRangeUser(ymin_,ymax_);
  pred_sr->SetMarkerStyle(20);
  pred_sr->SetMarkerSize(0.7);
  pred_sr->SetMarkerColor(kRed);
  pred_sr->SetLineColor(kRed);
  sr->SetMarkerStyle(20);
  sr->SetMarkerSize(0.7);
  sr->SetMarkerColor(kBlue);
  sr->SetLineColor(kBlue);

  
  //  pred_sr->SetLineStyle(kBlue);
  pred_sr->Draw("e1");
  sr->Draw("e1 sames");
 if(varName=="AllSBins_v6_CD_EW_50bin"){
  pred_sr->GetXaxis()->SetTickLength(0);
  TF1 *f2_=new TF1("f2_","x",1.5,46.5);
  TGaxis *A2 = new TGaxis(1,ymin_,46,ymin_,"f2_",45,"US");
  A2->SetTickSize(0.02);
  A2->Draw("B");
 }


   double chi=pred_sr->Integral();
  // double chi=pred_sr->Chi2Test(sr,"WW CHI2");
  int NDF=chi/pred_sr->Chi2Test(sr,"WW CHI2/NDF");
  double p=sr->Integral();
  //  double p=pred_sr->Chi2Test(sr,"WW p");
  textOnTop.SetTextSize(0.045);
  intLumiE.SetTextSize(0.04);
  textOnTop2.SetTextSize(0.04);
  //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");                                                                 
  //   textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation Supplementary}}");
  //  textOnTop.DrawLatexNDC(0.12,0.91,"work in progress"); 
  textOnTop.DrawLatexNDC(0.1,0.915,"CMS");
  textOnTop2.DrawLatexNDC(0.15,0.915," #it{#bf{Simulation}}");
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

  TLegend *legend = new TLegend(0.76,0.76,0.92,0.89);
  legend->SetNColumns(1);
  legend->SetBorderSize(0);
  TLegend *legend1 = new TLegend(0.1,0.82,0.45,0.9);
  //  legend1->SetHeader("with HEM veto","C");                               // option "C" allows to center the header                                      
  //  legend1->SetHeader(chi2,"C");
  // legend1->SetHeader(chi1,"C");
  //  legend1->SetHeader(p,"C");
  cout<<"Chi ===> "<<chi<<endl;
  cout<<"Chi1 ===> "<<chi1<<endl;
  legend1->SetTextSize(0.03);
  legend->SetTextSize(0.06);
  // legend1->Draw();
  if(data_pred)
    {
      if(ExpvsPred )
	{
	  if(lep=="LE")
	    {
	      legend->AddEntry(pred_sr,"Pred : TF x (1e + #gamma )","lp");
	      legend->AddEntry(sr,"Obs. : (1e + #gamma )","lp");
	    }
	  else if (lep=="LM")
	    {
	      legend->AddEntry(pred_sr,"Pred : TF x (1 #mu + #gamma )","lp");
	      legend->AddEntry(sr,"Obs. : (1 #mu + #gamma )","lp");
	    }
	  else if(lep=="LL")
	    {
	      legend->AddEntry(pred_sr,"Pred : TF x N^{MC}(1 l + #gamma )","lpe");
	      legend->AddEntry(sr,"Obs. : (1 l + #gamma )","lpe");
	    }
	}
      if(SRvsCR)
        {
          if(lep=="LE")
            {
              legend->AddEntry(pred_sr,"CR : (1e + #gamma )","lp");
              legend->AddEntry(sr,"SR : (0e + #gamma )","lp");
            }
          else if (lep=="LM")
            {
              legend->AddEntry(pred_sr,"CR : (1 #mu + #gamma )","lp");
              legend->AddEntry(sr,"SR : (0 #mu + #gamma )","lp");
            }
          else if(lep=="LL")
            {
              legend->AddEntry(pred_sr,"SR : had #tau  + #gamma ","lp");
              legend->AddEntry(sr,"SR : #mu  + #gamma ","lp");
	    }
        }

    }
  if(!data_pred)
    {
      if(ExpvsPred )
	{
	  if(lep=="LE")
	    {
	      legend->AddEntry(pred_sr,"Pred : TF x (1e + #gamma )","lp");
	      legend->AddEntry(sr,"Exp : (0e + #gamma )","lp");
	    }
	  else if (lep=="LM")
	    {
	      legend->AddEntry(pred_sr,"Pred : TF x (1 #mu + #gamma )","lp");
	      legend->AddEntry(sr,"Exp : (0 #mu + #gamma )","lp");
	    }
	  else if(lep=="LL")
	    {
	      // legend->AddEntry(pred_sr,"Pred : TF x (1 l + #gamma )","lp");
	      // legend->AddEntry(sr,"Exp : (0 l + #gamma )","lp");
	      //    legend->AddEntry(pred_sr,"Pred : TF x N^{MC}_{1l #gamma}","lp");
	      // legend->AddEntry(sr,"Exp : N^{MC}_{0l #gamma}","lp");
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
	    }
	  else if (lep=="LM")
	    {
	      legend->AddEntry(pred_sr,"CR : (1 #mu + #gamma )","lp");
	      legend->AddEntry(sr,"SR : (0 #mu + #gamma )","lp");
	    }
	  else if(lep=="LL")
	    {
	      legend->AddEntry(pred_sr,"CR : (1 l + #gamma )","lp");
	      legend->AddEntry(sr,"SR : (0 l + #gamma )","lp");
	    }
	}
    }
  /* else(LM){ */
      
  /*   }    */
  legend->SetTextSize(0.04);
  
  if(varName=="AllSBins_v6_CD_EW_50bin"  ){

    TLine *line1V6=new TLine( 8,ymin_,  8,10*yset_);
    TLine *line2V6=new TLine(14,ymin_, 14,10*yset_);
    TLine *line3V6=new TLine(19,ymin_, 19,10*yset_);
    TLine *line4V6=new TLine(24,ymin_, 24,10*yset_);
    TLine *line5V6=new TLine(29,ymin_, 29,10*yset_);
    TLine *line6V6=new TLine(34,ymin_, 34,10*yset_);
    TLine *line7V6=new TLine(40,ymin_, 40,10*yset_);
    
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

    /*
Tl.DrawLatex(3,2*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.5,2*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.1,2*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(20.0,2*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(25.0,2*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(30.0,2*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.DrawLatex(35,2*yset_,"V tag");
    Tl.DrawLatex(41,2*yset_,"H tag");
    */
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
  //  legend1->Draw();
   //   sr->Print("all");
   // pred_sr->Print("all");

   TH1D *h4 = (TH1D*)pred_sr->Clone("h4");
  TH1D *h3 = (TH1D*)sr->Clone("h3");

  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.35);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->SetRightMargin(0.03);
  pad2->cd();
  pad2->SetGridx(0);
  pad2->SetGridy(1);

  //  pad2->SetGrid(1);

  //  h3->GetYaxis()->SetRangeUser(0.5,1.5);
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
      if(lep=="LE")
	{
	  h3->SetMinimum(0);  // Define Y ..                                                                                                   
	  h3->SetMaximum(1); // .. range                                                                                                       
	}
      else
	{
	  h3->SetMinimum(0.01);  // Define Y ..                                                                                                   
	  h3->SetMaximum(1.99); // .. range                                                                                                         
	}
    }
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(0.6);
  // gStyle->SetOptStat(0);
  h3->Draw("ep");

  predsys->SetFillStyle(3244);
  predsys->SetMarkerColor(kGray+1);
  predsys->SetFillColor(kGray+1);

  if(varName.Contains("AllSBins_v6_CD_EW_50bin")){  predsys->Draw("E2 sames");

    h3->Draw("E0 sames");
  }

  h3->SetTitle(0);
  //  h3->GetXaxis()->SetTitleOffset(0.92);
   h3->GetXaxis()->SetTitle(title);
  h3->GetXaxis()->SetTitleSize(0.14);
  h3->GetXaxis()->SetLabelSize(0.14);

  //  if(ExpvsPred)  h3->GetYaxis()->SetTitle("Exp/Pred");
  if(ExpvsPred)  h3->GetYaxis()->SetTitle("#frac{Expectation}{Prediction}");
  else if(SRvsCR) h3->GetYaxis()->SetTitle("SR/CR");
  else if(data_pred) h3->GetYaxis()->SetTitle("#mu/had #tau");
  TLine *line;
  
  if(lep=="LE" && SRvsCR)
    line = new TLine(xmin_,0.5,xmax_,0.5);
  else
    line = new TLine(xmin_,1.0,xmax_,1.0);

  line->SetLineColor(1);
  line->SetLineStyle(1);
  line->SetLineWidth(1);
  line->Draw();

  

  h3->GetYaxis()->SetNdivisions(5);
  h3->GetYaxis()->SetTitleOffset(0.36);
  h3->GetYaxis()->SetTitleSize(0.12);
  h3->GetYaxis()->SetLabelSize(0.14);


  
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
  
  h3->Print("all");
  /*
  for(int i=bin0;i<=bin1;i++) 
    { cout<<TF->GetBinContent(i)<<" +- "<<->GetBinError(i)<<endl;} 
  */
  bin1=xmax-xmin;
  //  h3->GetXaxis()->CenterLabels(kTRUE);

  h3->LabelsDeflate("X");
  //  TGaxis *A1 = new TGaxis(1,0,46,0,"0",510,"M");
  // A1->Draw();

  
  TString temp2;
  //  pad2->SetTickx(0);
  if(varName=="AllSBins_v6_CD_EW_50bin"){

    pad2->cd();
    
    pad2->SetTickx(0);
    double k[8]={5,10,15,20,25,30,35,40};
    int i=0;
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
  TGaxis *A1 = new TGaxis(1,0.1,46,0.1,"f1_",45,"U");
  A1->SetLabelSize(0.1);
  A1->Draw("B");
  }
  c1->SaveAs(png);
  //double w=1600, h=900;
    c1->SetCanvasSize(1600,1000);
  //c1->SetWindowSize(w + (w - c1->GetWw()), h + (h - c1->GetWh()));
  //c1->SetWindowSize(00, 500);
  c1->SaveAs(pdf);
  //c1->SaveAs(png);
  //  c1->SetCanvasSize(1600,900);
  
}
