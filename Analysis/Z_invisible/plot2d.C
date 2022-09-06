void plot2d(TString varName, TString year, bool data, bool CR, bool SR)
{
  //      bool CR=true,SR=false, Pred=false;
  //  bool CR=false,SR=true, Pred=false;
  bool Pred=true;
  TFile *f1;
  TString path="./";
  //  path="./rootoutput/withphicut/";  
  path="rootoutput/withphicut_withoutHEMveto/";
  path="rootoutput/withphicut_withoutHEMveto_zmass60to120/";
  path="rootoutput/withphicut_zmass60to120/";
  path="rootoutput/withphicut_zmass60to120_btagSF_v2/";
  /* path="./rootoutput/withphicut_btagdiscut/"; */
  //  path="./rootoutput/withphicut_zmass60to120_btagSF/";
  TString filename;
  gStyle->SetPalette(1);
  TString pdf;
  gStyle->SetOptStat(0);
  TLegend *legend1 = new TLegend(0.1,0.82,0.4,0.9);
  legend1->SetHeader(year,"C");                               // option "C" allows to center the header
  TLegend *legend2 = new TLegend(0.6,0.82,0.9,0.9);
  //  legend2->SetHeader("Electrons in CR region","C");                               // option "C" allows to center the header
  if(CR) legend2->SetHeader("Z -> l^{+}l^{-} : CR","C");                               // option "C" allows to center the header
  else if(SR) legend2->SetHeader("Z -> #nu #nu : SR","C");
  else if(Pred)  legend2->SetHeader("FR X CR","C");
  legend2->SetTextSize(0.04);
  TCanvas *c1 = new TCanvas("stackhist","stackhist",1000,1000);
  c1->SetLogz();
  TLatex textOnTop,intLumiE;

  /* if(data) */
  /*   { */
  /*     //      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Preliminary}}"); */
  /*     pdf = path+"PDF/datavsMC/"+varName+"_"+year+"_data.pdf"; */
  /*     if(year=="full_Run2") */
  /* 	{ */
  /* 	  filename=path+"Run2_METdata_CR.root"; */
  /* 	  f1 = new TFile(filename); */
  /* 	} */
  /*     else */
  /* 	{ */
  /* 	  filename=path+"Run"+year+"_METdata_CR_v18.root"; */
  /* 	  f1 = new TFile(filename); */
  /* 	} */
  /*   } */
  /* else */
    {
      //      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Preliminary}}");

      pdf = path+"PDF/datavsMC/"+varName+"_"+year+"_MC.pdf";
      if(year=="full_Run2")
	{
	if(CR) filename=path+"ZJZGToLL_CR_v18.root";
	if(SR) filename=path+"ZJZGToNuNu_CR_v18.root";
	f1 = new TFile(filename);
	}
      else
	{
	  if(CR)	  filename=path+"ZJZGToLL_"+year+"_CR_v18.root";
	  if(SR)	  filename=path+"ZJZGToNuNu_"+year+"_CR_v18.root";
	  //if(SR)	  filename=path+"ZGToNuNuG_"+year+"_CR_v18.root";
	  f1 = new TFile(filename);
	}
    }


  
  TH2D *cr;
  TString varName1;
  cr = (TH2D*)f1->Get(varName);

  if(varName=="h2_btag_probwt")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      /* cr->GetYaxis()->SetRangeUser(0,5); */
      /* cr->GetXaxis()->SetRangeUser(0,600); */
      /* cr->GetYaxis()->SetRangeUser(0,1); */

      cr->GetXaxis()->SetTitle("Btag");
      cr->GetYaxis()->SetTitle("Prob.");
    }
  if(varName=="BestPhotonPt_jetmatchphoratio" || varName == "BestPhotonPt_jetphoratio")
    {
      cr->RebinY(5);
      cr->RebinX(5);
      cr->GetYaxis()->SetRangeUser(0,5);
      cr->GetXaxis()->SetRangeUser(0,600);
      cr->GetYaxis()->SetTitle("Jet Pt/ EM Object Pt");
      cr->GetXaxis()->SetTitle("EM Object Pt");
    }
  if(varName=="QMultlleadbJet")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      /* cr->GetYaxis()->SetRangeUser(0,5); */
      /* cr->GetXaxis()->SetRangeUser(0,600); */
      cr->GetYaxis()->SetRangeUser(0,1);

      cr->GetYaxis()->SetTitle("Btag discriminator");
      cr->GetXaxis()->SetTitle("Charged multiplicity around jet matched to the EM object");
    }
  if(varName=="METleadbJet")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      /* cr->GetYaxis()->SetRangeUser(0,5); */
      /* cr->GetXaxis()->SetRangeUser(0,600); */
      cr->GetYaxis()->SetRangeUser(0,1);

      cr->GetYaxis()->SetTitle("Btag discriminator");
      cr->GetXaxis()->SetTitle("MET");
    }

  if(varName=="ElectronEta_Phi" || varName=="leadElectronEta_Phi" || varName=="JetEta_Phi" || varName=="leadJetEta_Phi" || varName=="JetEta_Phi1" || varName=="JetEta_Phi2" || varName=="JetEta_Phi3" || varName=="JetEta_Phi4")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      cr->GetYaxis()->SetRangeUser(-5,5);
      cr->GetXaxis()->SetRangeUser(-3,3);
      cr->GetZaxis()->SetRangeUser(0.0001,10);
       cr->GetXaxis()->SetTitle("Eta");
      cr->GetYaxis()->SetTitle("Phi");
    }
  if(varName=="h2_Phivseta_jet1" || varName=="h2_Phivseta_jet2" || varName=="h2_Phivseta_jet3" || varName=="h2_Phivseta_jet4" )
    {
      cr->RebinY(10);
      cr->RebinX(10);
      cr->GetYaxis()->SetRangeUser(-3,3);
      cr->GetXaxis()->SetRangeUser(-5,5);
      cr->GetXaxis()->SetTitle("Phi");
      cr->GetYaxis()->SetTitle("Eta");
    }
  if(varName=="h2_dPhivseta_jet1" || varName=="h2_dPhivseta_jet2" || varName=="h2_dPhivseta_jet3" || varName=="h2_dPhivseta_jet4" )
    {
      cr->RebinY(10);
      cr->RebinX(10);
      cr->GetYaxis()->SetRangeUser(-3,3);
      cr->GetXaxis()->SetRangeUser(0,5);
      cr->GetXaxis()->SetTitle("dPhi(MET,JET)");
      cr->GetYaxis()->SetTitle("Eta");
    }
  else if(varName=="BestPhoEta_Pt" || varName=="leadJetEta_Pt" || varName=="JetEta_Pt" || varName=="2leadJetEta_Pt"|| varName=="JetEta_Pt1" || varName=="JetEta_Pt2" || varName=="JetEta_Pt3" || varName=="JetEta_Pt4")
    {
      cr->RebinY(2);
      cr->RebinX(2);
      //      cr->GetYaxis()->SetRangeUser(-5,5);
      //      cr->GetXaxis()->SetRangeUser(-3,3);
      cr->GetXaxis()->SetTitle("lead Jet Eta");
      cr->GetYaxis()->SetTitle("lead Jet Pt");
    }
  else if(varName=="leadElectronPt_Eta" )
    {
      /* cr->RebinY(10); */
      /* cr->RebinX(5); */
      
      cr->GetYaxis()->SetRangeUser(-3,3);                                                                                                             
      cr->GetXaxis()->SetRangeUser(100,700);                                                                                                             
      cr->GetXaxis()->SetTitle("e Pt");
      cr->GetYaxis()->SetTitle("e Eta");
    }

  else if(varName=="leadElectronPt_Phi" )
    {
      /* cr->RebinY(10); */
      /* cr->RebinX(5); */
      
      cr->GetYaxis()->SetRangeUser(-3,3);                                                                                                             
      cr->GetXaxis()->SetRangeUser(100,700);                                                                                                             
      cr->GetXaxis()->SetTitle("e Pt");
      cr->GetYaxis()->SetTitle("e Phi");
    }

  else if(varName=="BestPhotonPt_jetphoratio")
    {
      /* cr->RebinY(10); */
      /* cr->RebinX(5); */
      //      cr->GetYaxis()->SetRangeUser(-5,5);
      //      cr->GetXaxis()->SetRangeUser(-3,3);
      cr->GetXaxis()->SetTitle("Pt");
      cr->GetYaxis()->SetTitle("Pt");
    }
  else if(varName=="BestPhotonEta_Qmulti")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      //cr_2->RebinY(1);
      //cr_2->RebinX(1);
      /* cr->GetYaxis()->SetRangeUser(-3.5,3.5); */
      /* cr->GetXaxis()->SetRangeUser(0,1000); */
      //      cr->GetZaxis()->SetRangeUser(0,5);                                                                                                              
      cr->GetXaxis()->SetTitle("EM object Eta");
      cr->GetYaxis()->SetTitle("EM object Qmulti");
    }
  else if(varName=="BestPhotonEta_nJets")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      //    cr_2->RebinY(1);
      //cr_2->RebinX(1);
      /* cr->GetYaxis()->SetRangeUser(-3.5,3.5); */
      /* cr->GetXaxis()->SetRangeUser(0,1000); */
      //      cr->GetZaxis()->SetRangeUser(0,5);                                                                                                              
      cr->GetXaxis()->SetTitle("EM object Eta");
      cr->GetYaxis()->SetTitle("EM object nJets");
    }
  else if(varName=="HT5HT_dPhiMETj2" || varName=="HT5HT_dPhiMETj1" || varName=="HT5HT_dPhiMETj3" || varName=="HT5HT_dPhiMETj4")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      //    cr_2->RebinY(1);
      //cr_2->RebinX(1);
      cr->GetYaxis()->SetRangeUser(1,3);
      cr->GetXaxis()->SetRangeUser(0,3.5);
      cr->GetZaxis()->SetRangeUser(0.1,10000);                                                                                                              
      cr->GetYaxis()->SetTitle("HT5/HT");
      if(varName=="HT5HT_dPhiMETj1")      cr->GetXaxis()->SetTitle("dPhi(MET,jet1)");
      if(varName=="HT5HT_dPhiMETj2")      cr->GetXaxis()->SetTitle("dPhi(MET,jet2)");
      if(varName=="HT5HT_dPhiMETj3")      cr->GetXaxis()->SetTitle("dPhi(MET,jet3)");
      if(varName=="HT5HT_dPhiMETj4")      cr->GetXaxis()->SetTitle("dPhi(MET,jet4)");
    }
  else if(varName=="BestPhotonEta_MET")
    {
      cr->RebinY(5);
      cr->RebinX(2);
      /* cr->GetYaxis()->SetRangeUser(-3.5,3.5); */
      /* cr->GetXaxis()->SetRangeUser(0,1000); */
      //      cr->GetZaxis()->SetRangeUser(0,5);                                                                                                              
      cr->GetXaxis()->SetTitle("good #gamma Eta");
      cr->GetYaxis()->SetTitle("good #gamma MET");
    }
  else if(varName=="PhoPtQMultJet" || varName=="PhoPtQMultJet_v2")
    {
      /* cr->RebinY(5); */
      /* cr->RebinX(10); */
      //      cr->GetYaxis()->SetRangeUser(-5,5);
      //      cr->GetXaxis()->SetRangeUser(-3,3);
      cr->GetXaxis()->SetTitle("EM object Pt");
      cr->GetYaxis()->SetTitle("Qmultiplicity");
    }
  else if(varName=="PhoPtQMultJet_v3")
    {
      /* cr->RebinY(5); */
      /* cr->RebinX(10); */
      //      cr->GetYaxis()->SetRangeUser(-5,5);
      //      cr->GetXaxis()->SetRangeUser(-3,3);
      cr->GetYaxis()->SetRangeUser(0,30);
           cr->GetXaxis()->SetRangeUser(100,800);
      cr->GetXaxis()->SetTitle("EM object Pt");
      cr->GetYaxis()->SetTitle("Qmultiplicity");
    }
  else if(varName=="METQMultJet")
    {
      /* cr->RebinY(5); */
      /* cr->RebinX(10); */
      cr->GetYaxis()->SetRangeUser(0,30);
           cr->GetXaxis()->SetRangeUser(0,1200);
      cr->GetXaxis()->SetTitle("MET");
      cr->GetYaxis()->SetTitle("Qmultiplicity");
    }
  else if(varName=="nJetsMET")
    {
      /* cr->RebinY(1); */
      /* cr->RebinX(4); */
     cr->GetYaxis()->SetRangeUser(0,1000);
      cr->GetXaxis()->SetRangeUser(7,14);
      cr->GetXaxis()->SetTitle("nJets");
      cr->GetYaxis()->SetTitle("MET");
    }
  else if(varName=="PhoPtMET")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      cr->GetYaxis()->SetRangeUser(0,1000);
      cr->GetXaxis()->SetRangeUser(100,1000);
      cr->GetXaxis()->SetTitle("EM object Pt");
      cr->GetYaxis()->SetTitle("MET");
    }

  else if(varName=="PhoPtnJets")
    {
      cr->RebinY(1);
      cr->RebinX(1);
      cr->GetYaxis()->SetRangeUser(0,14);
      cr->GetXaxis()->SetRangeUser(100,1000);
      cr->GetXaxis()->SetTitle("EM object Pt");
      cr->GetYaxis()->SetTitle("nJets");
    }
  else if(varName=="nJetsQMultJet")
    {
       /* cr->RebinY(10); */

      /* cr->RebinX(2); */
      cr->GetYaxis()->SetRangeUser(0,50);
      cr->GetXaxis()->SetRangeUser(7,14);
      cr->GetXaxis()->SetTitle("nJets");
      cr->GetYaxis()->SetTitle("Qmultiplicity");
    }
  else if(varName=="nbjets_nJets")
    {
       /* cr->RebinY(10); */

      /* cr->RebinX(2); */
      cr->GetYaxis()->SetRangeUser(0,5);
      cr->GetXaxis()->SetRangeUser(0,14);
      cr->GetXaxis()->SetTitle("nJets");
      cr->GetYaxis()->SetTitle("BTags");
    }
  cr->SetTitle(0);
  cr->Draw("colz");
  legend1->Draw();
  legend2->Draw();
  textOnTop.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  int z=0;
  /* for(int i=1;i<=100;i++)                                                                                                                                   */
    /* {                                                                                                                                                     */
    /*   for(int j=1;j<=50;j++) */
    /* 	{ z++; */
    /* 	  if(cr->GetBinContent(i,j)>0) */
    /* 	    cout<<z<<": "<<cr->GetXaxis()->GetBinLowEdge(i)<<" - "<<cr->GetXaxis()->GetBinLowEdge(i+1)<<"  ::    "<<cr->GetYaxis()->GetBinLowEdge(j) */
    /* 	      <<" - "<<cr->GetYaxis()->GetBinLowEdge(j+1)<<"    ::   "<<cr->GetBinContent(i,j)<<endl;                                                                       */
    /* 	} */
    /* } */
  //  if(isPaper) textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Supplementary}}");

  cout<<cr->Integral()<<endl;

  if(data)
    {
      textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Preliminary}}");
    }
  else
    textOnTop.DrawLatexNDC(0.12,0.91,"CMS #it{#bf{Simulation Preliminary}}");

  
  if(year=="2016")
    intLumiE.DrawLatexNDC(0.75,0.91,"#bf{35.9 fb^{-1} (13 TeV)}");
  if(year=="2017")
    intLumiE.DrawLatexNDC(0.75,0.91,"#bf{41.5 fb^{-1} (13 TeV)}");
  if(year=="2018")
    intLumiE.DrawLatexNDC(0.75,0.91,"#bf{59.6 fb^{-1} (13 TeV)}");
  if(year=="full_Run2")
    intLumiE.DrawLatexNDC(0.75,0.91,"#bf{137 fb^{-1} (13 TeV)}");
               
  c1->SaveAs(pdf);
  
}
