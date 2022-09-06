//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  4 01:48:45 2016 by ROOT version 6.06/01
// from TTree PreSelection/PreSelection
// found on file: root://cmseos.fnal.gov//store/user/vhegde/myProduction_V11/Spring16.WGToLNuG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_96_RA2AnalysisTree.root
//////////////////////////////////////////////////////////
#ifndef NtupleVariables_h
#define NtupleVariables_h

#include <TROOT.h>
#include <TChain.h>
#include <TLorentzVector.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

using namespace std;
class NtupleVariables : public TSelector {
 public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   ULong64_t       EvtNum;
   Bool_t          BadChargedCandidateFilter;
   Bool_t          BadPFMuonFilter;
   Int_t           BTags;
   Int_t           BTagsclean;
   Int_t           BTagsDeepCSV;
   Int_t           BTagsDeepCSVclean;
   Int_t           BTagsDeepCSVJECdown;
   Int_t           BTagsDeepCSVJECup;
   Int_t           BTagsDeepCSVJERdown;
   Int_t           BTagsDeepCSVJERup;
   Int_t           BTagsJECdown;
   Int_t           BTagsJECup;
   Int_t           BTagsJERdown;
   Int_t           BTagsJERup;
   Double_t        CaloMET;
   Double_t        CaloMETPhi;
   Double_t        CrossSection;
   Int_t           CSCTightHaloFilter;
   Int_t           ecalBadCalibFilter;
   Bool_t          ecalBadCalibReducedExtraFilter;
   Bool_t          ecalBadCalibReducedFilter;
   Int_t           EcalDeadCellBoundaryEnergyFilter;
   Int_t           EcalDeadCellTriggerPrimitiveFilter;
   Int_t           eeBadScFilter;
   vector<TLorentzVector> *Electrons;
   vector<int>     *Electrons_charge;
   vector<double>  *Electrons_iso;
   vector<bool>    *Electrons_mediumID;
   vector<double>  *Electrons_MTW;
   vector<bool>    *Electrons_passIso;
   vector<bool>    *Electrons_tightID;
   Double_t        fixedGridRhoFastjetAll;
   vector<TLorentzVector> *GenElectrons;
   Double_t        GenHT;
   vector<TLorentzVector> *GenJets;
   vector<TLorentzVector> *GenJetsAK8;
   vector<int>     *GenJetsAK8_multiplicity;
   vector<double>  *GenJetsAK8_softDropMass;
   Double_t        GenMET;
   Double_t        GenMETPhi;
   Double_t        GenMHT;
   Double_t        GenMHTPhi;
   vector<TLorentzVector> *GenMuons;
   vector<TLorentzVector> *GenParticles;
   vector<int>     *GenParticles_ParentId;
   vector<int>     *GenParticles_ParentIdx;
   vector<int>     *GenParticles_PdgId;
   vector<int>     *GenParticles_Status;
   vector<TLorentzVector> *GenTaus;
   vector<bool>    *GenTaus_had;
   Int_t           globalSuperTightHalo2016Filter;
   Int_t           globalTightHalo2016Filter;
   Bool_t          hasGenPromptPhoton;
   Int_t           HBHEIsoNoiseFilter;
   Int_t           HBHENoiseFilter;
   Double_t        HT;
   Double_t        HT5;
   Double_t        HT5JECdown;
   Double_t        HT5JECup;
   Double_t        HT5JERdown;
   Double_t        HT5JERup;
   Double_t        HTJECdown;
   Double_t        HTJECup;
   Double_t        HTJERdown;
   Double_t        HTJERup;
   Int_t           isoElectronTracks;
   Int_t           isoMuonTracks;
   Int_t           isoPionTracks;
   Bool_t          JetID;
   Bool_t          JetIDAK8;
   Bool_t          JetIDAK8JECdown;
   Bool_t          JetIDAK8JECup;
   Bool_t          JetIDAK8JERdown;
   Bool_t          JetIDAK8JERup;
   Bool_t          JetIDJECdown;
   Bool_t          JetIDJECup;
   Bool_t          JetIDJERdown;
   Bool_t          JetIDJERup;
   vector<TLorentzVector> *Jets;
   vector<double>  *Jets_axismajor;
   vector<double>  *Jets_axisminor;
   vector<double>  *Jets_bDiscriminatorCSV;
   vector<double>  *Jets_bJetTagDeepCSVBvsAll;
   vector<double>  *Jets_chargedEmEnergyFraction;
   vector<double>  *Jets_chargedHadronEnergyFraction;
   vector<int>     *Jets_chargedHadronMultiplicity;
   vector<int>     *Jets_chargedMultiplicity;
   vector<double>  *Jets_electronEnergyFraction;
   vector<int>     *Jets_electronMultiplicity;
   vector<int>     *Jets_hadronFlavor;
   vector<double>  *Jets_hfEMEnergyFraction;
   vector<double>  *Jets_hfHadronEnergyFraction;
   vector<bool>    *Jets_HTMask;
   vector<bool>    *Jets_ID;
   vector<double>  *Jets_jecFactor;
   vector<double>  *Jets_jecUnc;
   vector<double>  *Jets_jerFactor;
   vector<double>  *Jets_jerFactorDown;
   vector<double>  *Jets_jerFactorUp;
   vector<bool>    *Jets_LeptonMask;
   vector<bool>    *Jets_MHTMask;
   vector<int>     *Jets_multiplicity;
   vector<double>  *Jets_muonEnergyFraction;
   vector<int>     *Jets_muonMultiplicity;
   vector<double>  *Jets_neutralEmEnergyFraction;
   vector<double>  *Jets_neutralHadronEnergyFraction;
   vector<int>     *Jets_neutralHadronMultiplicity;
   vector<int>     *Jets_neutralMultiplicity;
   vector<int>     *Jets_origIndex;
   vector<int>     *Jets_partonFlavor;
   vector<double>  *Jets_photonEnergyFraction;
   vector<int>     *Jets_photonMultiplicity;
   vector<double>  *Jets_ptD;
   vector<double>  *Jets_qgLikelihood;
   vector<TLorentzVector> *JetsAK8;
   vector<double>  *JetsAK8_axismajor;
   vector<double>  *JetsAK8_axisminor;
   vector<double>  *JetsAK8_chargedEmEnergyFraction;
   vector<double>  *JetsAK8_chargedHadronEnergyFraction;
   vector<int>     *JetsAK8_chargedHadronMultiplicity;
   vector<int>     *JetsAK8_chargedMultiplicity;
   vector<double>  *JetsAK8_DeepMassDecorrelTagbbvsLight;
   vector<double>  *JetsAK8_DeepMassDecorrelTagHbbvsQCD;
   vector<double>  *JetsAK8_DeepMassDecorrelTagTvsQCD;
   vector<double>  *JetsAK8_DeepMassDecorrelTagWvsQCD;
   vector<double>  *JetsAK8_DeepMassDecorrelTagZbbvsQCD;
   vector<double>  *JetsAK8_DeepMassDecorrelTagZHbbvsQCD;
   vector<double>  *JetsAK8_DeepMassDecorrelTagZvsQCD;
   vector<double>  *JetsAK8_DeepTagHbbvsQCD;
   vector<double>  *JetsAK8_DeepTagTvsQCD;
   vector<double>  *JetsAK8_DeepTagWvsQCD;
   vector<double>  *JetsAK8_DeepTagZbbvsQCD;
   vector<double>  *JetsAK8_DeepTagZvsQCD;
   vector<double>  *JetsAK8_doubleBDiscriminator;
   vector<double>  *JetsAK8_ecfN2b1;
   vector<double>  *JetsAK8_ecfN2b2;
   vector<double>  *JetsAK8_ecfN3b1;
   vector<double>  *JetsAK8_ecfN3b2;
   vector<double>  *JetsAK8_electronEnergyFraction;
   vector<int>     *JetsAK8_electronMultiplicity;
   vector<double>  *JetsAK8_girth;
   vector<double>  *JetsAK8_hfEMEnergyFraction;
   vector<double>  *JetsAK8_hfHadronEnergyFraction;
   vector<bool>    *JetsAK8_ID;
   vector<bool>    *JetsAK8_isHV;
   vector<double>  *JetsAK8_jecFactor;
   vector<double>  *JetsAK8_jecUnc;
   vector<double>  *JetsAK8_jerFactor;
   vector<double>  *JetsAK8_jerFactorDown;
   vector<double>  *JetsAK8_jerFactorUp;
   vector<int>     *JetsAK8_multiplicity;
   vector<double>  *JetsAK8_muonEnergyFraction;
   vector<int>     *JetsAK8_muonMultiplicity;
   vector<double>  *JetsAK8_neutralEmEnergyFraction;
   vector<double>  *JetsAK8_neutralHadronEnergyFraction;
   vector<double>  *JetsAK8_neutralHadronMultiplicity;
   vector<double>  *JetsAK8_neutralMultiplicity;
   vector<double>  *JetsAK8_NsubjettinessTau1;
   vector<double>  *JetsAK8_NsubjettinessTau2;
   vector<double>  *JetsAK8_NsubjettinessTau3;
   vector<int>     *JetsAK8_NumBhadrons;
   vector<int>     *JetsAK8_NumChadrons;
   vector<int>     *JetsAK8_origIndex;
   vector<double>  *JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb;
   vector<double>  *JetsAK8_photonEnergyFraction;
   vector<double>  *JetsAK8_photonMultiplicity;
   vector<double>  *JetsAK8_ptD;
   vector<double>  *JetsAK8_softDropMass;
   vector<vector<TLorentzVector> > *JetsAK8_subjets;
   vector<vector<double> > *JetsAK8_subjets_axismajor;
   vector<vector<double> > *JetsAK8_subjets_axisminor;
   vector<vector<double> > *JetsAK8_subjets_bDiscriminatorCSV;
   vector<vector<double> > *JetsAK8_subjets_jecFactor;
   vector<vector<int> > *JetsAK8_subjets_multiplicity;
   vector<vector<double> > *JetsAK8_subjets_ptD;
   vector<double>  *JetsAK8JECdown_jerFactor;
   vector<int>     *JetsAK8JECdown_origIndex;
   vector<double>  *JetsAK8JECup_jerFactor;
   vector<int>     *JetsAK8JECup_origIndex;
   vector<int>     *JetsAK8JERdown_origIndex;
   vector<int>     *JetsAK8JERup_origIndex;
   vector<double>  *JetsJECdown_jerFactor;
   vector<int>     *JetsJECdown_origIndex;
   vector<double>  *JetsJECup_jerFactor;
   vector<int>     *JetsJECup_origIndex;
   vector<int>     *JetsJERdown_origIndex;
   vector<int>     *JetsJERup_origIndex;
   Double_t        madHT;
   Int_t           madMinDeltaRStatus;
   Double_t        madMinPhotonDeltaR;
   Double_t        MET;
   vector<double>  *METDown;
   Double_t        METPhi;
   vector<double>  *METPhiDown;
   vector<double>  *METPhiUp;
   Double_t        METSignificance;
   vector<double>  *METUp;
   Double_t        MHT;
   Double_t        MHTJECdown;
   Double_t        MHTJECup;
   Double_t        MHTJERdown;
   Double_t        MHTJERup;
   Double_t        MHTPhi;
   Double_t        MHTPhiJECdown;
   Double_t        MHTPhiJECup;
   Double_t        MHTPhiJERdown;
   Double_t        MHTPhiJERup;
   Double_t        MJJ_AK8;
   Double_t        Mmc_AK8;
   Double_t        MT_AK8;
   vector<TLorentzVector> *Muons;
   vector<int>     *Muons_charge;
   vector<double>  *Muons_iso;
   vector<bool>    *Muons_mediumID;
   vector<double>  *Muons_MTW;
   vector<bool>    *Muons_passIso;
   vector<bool>    *Muons_tightID;
   Int_t           nAllVertices;
   Int_t           NElectrons;
   Int_t           NJets;
   Int_t           NJetsISR;
   Int_t           NJetsISRJECdown;
   Int_t           NJetsISRJECup;
   Int_t           NJetsISRJERdown;
   Int_t           NJetsISRJERup;
   Int_t           NJetsJECdown;
   Int_t           NJetsJECup;
   Int_t           NJetsJERdown;
   Int_t           NJetsJERup;
   Int_t           NMuons;
   Double_t        NonPrefiringProb;
   Double_t        NonPrefiringProbDown;
   Double_t        NonPrefiringProbUp;
   Double_t        NumEvents;
   Int_t           NumInteractions;
   Int_t           NVtx;
   vector<float>   *PDFweights;
   Double_t        PFCaloMETRatio;
   vector<TLorentzVector> *Photons;
   vector<bool>    *Photons_electronFakes;
   vector<bool>    *Photons_fullID;
   vector<double>  *Photons_genMatched;
   vector<double>  *Photons_hadTowOverEM;
   vector<bool>    *Photons_hasPixelSeed;
   vector<double>  *Photons_isEB;
   vector<bool>    *Photons_nonPrompt;
   vector<double>  *Photons_passElectronVeto;
   vector<double>  *Photons_pfChargedIso;
   vector<double>  *Photons_pfChargedIsoRhoCorr;
   vector<double>  *Photons_pfGammaIso;
   vector<double>  *Photons_pfGammaIsoRhoCorr;
   vector<double>  *Photons_pfNeutralIso;
   vector<double>  *Photons_pfNeutralIsoRhoCorr;
   vector<double>  *Photons_sigmaIetaIeta;
   Int_t           PrimaryVertexFilter;
   vector<float>   *PSweights;
   Double_t        puSysDown;
   Double_t        puSysUp;
   Double_t        puWeight;
   vector<float>   *ScaleWeights;
   vector<double>  *SignalParameters;
   Double_t        SusyLSPMass;
   Double_t        SusyMotherMass;
   vector<TLorentzVector> *TAPElectronTracks;
   vector<double>  *TAPElectronTracks_dxypv;
   vector<bool>    *TAPElectronTracks_leptonMatch;
   vector<double>  *TAPElectronTracks_mT;
   vector<double>  *TAPElectronTracks_pfRelIso03chg;
   vector<double>  *TAPElectronTracks_trkiso;
   vector<TLorentzVector> *TAPMuonTracks;
   vector<double>  *TAPMuonTracks_dxypv;
   vector<bool>    *TAPMuonTracks_leptonMatch;
   vector<double>  *TAPMuonTracks_mT;
   vector<double>  *TAPMuonTracks_pfRelIso03chg;
   vector<double>  *TAPMuonTracks_trkiso;
   vector<TLorentzVector> *TAPPionTracks;
   vector<double>  *TAPPionTracks_dxypv;
   vector<bool>    *TAPPionTracks_leptonMatch;
   vector<double>  *TAPPionTracks_mT;
   vector<double>  *TAPPionTracks_pfRelIso03chg;
   vector<double>  *TAPPionTracks_trkiso;
   vector<int>     *TriggerPass;
   vector<int>     *TriggerPrescales;
   vector<int>     *TriggerVersion;
   Double_t        TrueNumInteractions;
   Double_t        Weight;
   vector<TLorentzVector> *ZCandidates;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_BadChargedCandidateFilter;   //!
   TBranch        *b_BadPFMuonFilter;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_BTagsclean;   //!
   TBranch        *b_BTagsDeepCSV;   //!
   TBranch        *b_BTagsDeepCSVclean;   //!
   TBranch        *b_BTagsDeepCSVJECdown;   //!
   TBranch        *b_BTagsDeepCSVJECup;   //!
   TBranch        *b_BTagsDeepCSVJERdown;   //!
   TBranch        *b_BTagsDeepCSVJERup;   //!
   TBranch        *b_BTagsJECdown;   //!
   TBranch        *b_BTagsJECup;   //!
   TBranch        *b_BTagsJERdown;   //!
   TBranch        *b_BTagsJERup;   //!
   TBranch        *b_CaloMET;   //!
   TBranch        *b_CaloMETPhi;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_CSCTightHaloFilter;   //!
   TBranch        *b_ecalBadCalibFilter;   //!
   TBranch        *b_ecalBadCalibReducedExtraFilter;   //!
   TBranch        *b_ecalBadCalibReducedFilter;   //!
   TBranch        *b_EcalDeadCellBoundaryEnergyFilter;   //!
   TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_eeBadScFilter;   //!
   TBranch        *b_Electrons;   //!
   TBranch        *b_Electrons_charge;   //!
   TBranch        *b_Electrons_iso;   //!
   TBranch        *b_Electrons_mediumID;   //!
   TBranch        *b_Electrons_MTW;   //!
   TBranch        *b_Electrons_passIso;   //!
   TBranch        *b_Electrons_tightID;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_GenElectrons;   //!
   TBranch        *b_GenHT;   //!
   TBranch        *b_GenJets;   //!
   TBranch        *b_GenJetsAK8;   //!
   TBranch        *b_GenJetsAK8_multiplicity;   //!
   TBranch        *b_GenJetsAK8_softDropMass;   //!
   TBranch        *b_GenMET;   //!
   TBranch        *b_GenMETPhi;   //!
   TBranch        *b_GenMHT;   //!
   TBranch        *b_GenMHTPhi;   //!
   TBranch        *b_GenMuons;   //!
   TBranch        *b_GenParticles;   //!
   TBranch        *b_GenParticles_ParentId;   //!
   TBranch        *b_GenParticles_ParentIdx;   //!
   TBranch        *b_GenParticles_PdgId;   //!
   TBranch        *b_GenParticles_Status;   //!
   TBranch        *b_GenTaus;   //!
   TBranch        *b_GenTaus_had;   //!
   TBranch        *b_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_globalTightHalo2016Filter;   //!
   TBranch        *b_hasGenPromptPhoton;   //!
   TBranch        *b_HBHEIsoNoiseFilter;   //!
   TBranch        *b_HBHENoiseFilter;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT5;   //!
   TBranch        *b_HT5JECdown;   //!
   TBranch        *b_HT5JECup;   //!
   TBranch        *b_HT5JERdown;   //!
   TBranch        *b_HT5JERup;   //!
   TBranch        *b_HTJECdown;   //!
   TBranch        *b_HTJECup;   //!
   TBranch        *b_HTJERdown;   //!
   TBranch        *b_HTJERup;   //!
   TBranch        *b_isoElectronTracks;   //!
   TBranch        *b_isoMuonTracks;   //!
   TBranch        *b_isoPionTracks;   //!
   TBranch        *b_JetID;   //!
   TBranch        *b_JetIDAK8;   //!
   TBranch        *b_JetIDAK8JECdown;   //!
   TBranch        *b_JetIDAK8JECup;   //!
   TBranch        *b_JetIDAK8JERdown;   //!
   TBranch        *b_JetIDAK8JERup;   //!
   TBranch        *b_JetIDJECdown;   //!
   TBranch        *b_JetIDJECup;   //!
   TBranch        *b_JetIDJERdown;   //!
   TBranch        *b_JetIDJERup;   //!
   TBranch        *b_Jets;   //!
   TBranch        *b_Jets_axismajor;   //!
   TBranch        *b_Jets_axisminor;   //!
   TBranch        *b_Jets_bDiscriminatorCSV;   //!
   TBranch        *b_Jets_bJetTagDeepCSVBvsAll;   //!
   TBranch        *b_Jets_chargedEmEnergyFraction;   //!
   TBranch        *b_Jets_chargedHadronEnergyFraction;   //!
   TBranch        *b_Jets_chargedHadronMultiplicity;   //!
   TBranch        *b_Jets_chargedMultiplicity;   //!
   TBranch        *b_Jets_electronEnergyFraction;   //!
   TBranch        *b_Jets_electronMultiplicity;   //!
   TBranch        *b_Jets_hadronFlavor;   //!
   TBranch        *b_Jets_hfEMEnergyFraction;   //!
   TBranch        *b_Jets_hfHadronEnergyFraction;   //!
   TBranch        *b_Jets_HTMask;   //!
   TBranch        *b_Jets_ID;   //!
   TBranch        *b_Jets_jecFactor;   //!
   TBranch        *b_Jets_jecUnc;   //!
   TBranch        *b_Jets_jerFactor;   //!
   TBranch        *b_Jets_jerFactorDown;   //!
   TBranch        *b_Jets_jerFactorUp;   //!
   TBranch        *b_Jets_LeptonMask;   //!
   TBranch        *b_Jets_MHTMask;   //!
   TBranch        *b_Jets_multiplicity;   //!
   TBranch        *b_Jets_muonEnergyFraction;   //!
   TBranch        *b_Jets_muonMultiplicity;   //!
   TBranch        *b_Jets_neutralEmEnergyFraction;   //!
   TBranch        *b_Jets_neutralHadronEnergyFraction;   //!
   TBranch        *b_Jets_neutralHadronMultiplicity;   //!
   TBranch        *b_Jets_neutralMultiplicity;   //!
   TBranch        *b_Jets_origIndex;   //!
   TBranch        *b_Jets_partonFlavor;   //!
   TBranch        *b_Jets_photonEnergyFraction;   //!
   TBranch        *b_Jets_photonMultiplicity;   //!
   TBranch        *b_Jets_ptD;   //!
   TBranch        *b_Jets_qgLikelihood;   //!
   TBranch        *b_JetsAK8;   //!
   TBranch        *b_JetsAK8_axismajor;   //!
   TBranch        *b_JetsAK8_axisminor;   //!
   TBranch        *b_JetsAK8_chargedEmEnergyFraction;   //!
   TBranch        *b_JetsAK8_chargedHadronEnergyFraction;   //!
   TBranch        *b_JetsAK8_chargedHadronMultiplicity;   //!
   TBranch        *b_JetsAK8_chargedMultiplicity;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagbbvsLight;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagHbbvsQCD;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagTvsQCD;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagWvsQCD;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagZbbvsQCD;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagZHbbvsQCD;   //!
   TBranch        *b_JetsAK8_DeepMassDecorrelTagZvsQCD;   //!
   TBranch        *b_JetsAK8_DeepTagHbbvsQCD;   //!
   TBranch        *b_JetsAK8_DeepTagTvsQCD;   //!
   TBranch        *b_JetsAK8_DeepTagWvsQCD;   //!
   TBranch        *b_JetsAK8_DeepTagZbbvsQCD;   //!
   TBranch        *b_JetsAK8_DeepTagZvsQCD;   //!
   TBranch        *b_JetsAK8_doubleBDiscriminator;   //!
   TBranch        *b_JetsAK8_ecfN2b1;   //!
   TBranch        *b_JetsAK8_ecfN2b2;   //!
   TBranch        *b_JetsAK8_ecfN3b1;   //!
   TBranch        *b_JetsAK8_ecfN3b2;   //!
   TBranch        *b_JetsAK8_electronEnergyFraction;   //!
   TBranch        *b_JetsAK8_electronMultiplicity;   //!
   TBranch        *b_JetsAK8_girth;   //!
   TBranch        *b_JetsAK8_hfEMEnergyFraction;   //!
   TBranch        *b_JetsAK8_hfHadronEnergyFraction;   //!
   TBranch        *b_JetsAK8_ID;   //!
   TBranch        *b_JetsAK8_isHV;   //!
   TBranch        *b_JetsAK8_jecFactor;   //!
   TBranch        *b_JetsAK8_jecUnc;   //!
   TBranch        *b_JetsAK8_jerFactor;   //!
   TBranch        *b_JetsAK8_jerFactorDown;   //!
   TBranch        *b_JetsAK8_jerFactorUp;   //!
   TBranch        *b_JetsAK8_multiplicity;   //!
   TBranch        *b_JetsAK8_muonEnergyFraction;   //!
   TBranch        *b_JetsAK8_muonMultiplicity;   //!
   TBranch        *b_JetsAK8_neutralEmEnergyFraction;   //!
   TBranch        *b_JetsAK8_neutralHadronEnergyFraction;   //!
   TBranch        *b_JetsAK8_neutralHadronMultiplicity;   //!
   TBranch        *b_JetsAK8_neutralMultiplicity;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau1;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau2;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau3;   //!
   TBranch        *b_JetsAK8_NumBhadrons;   //!
   TBranch        *b_JetsAK8_NumChadrons;   //!
   TBranch        *b_JetsAK8_origIndex;   //!
   TBranch        *b_JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb;   //!
   TBranch        *b_JetsAK8_photonEnergyFraction;   //!
   TBranch        *b_JetsAK8_photonMultiplicity;   //!
   TBranch        *b_JetsAK8_ptD;   //!
   TBranch        *b_JetsAK8_softDropMass;   //!
   TBranch        *b_JetsAK8_subjets;   //!
   TBranch        *b_JetsAK8_subjets_axismajor;   //!
   TBranch        *b_JetsAK8_subjets_axisminor;   //!
   TBranch        *b_JetsAK8_subjets_bDiscriminatorCSV;   //!
   TBranch        *b_JetsAK8_subjets_jecFactor;   //!
   TBranch        *b_JetsAK8_subjets_multiplicity;   //!
   TBranch        *b_JetsAK8_subjets_ptD;   //!
   TBranch        *b_JetsAK8JECdown_jerFactor;   //!
   TBranch        *b_JetsAK8JECdown_origIndex;   //!
   TBranch        *b_JetsAK8JECup_jerFactor;   //!
   TBranch        *b_JetsAK8JECup_origIndex;   //!
   TBranch        *b_JetsAK8JERdown_origIndex;   //!
   TBranch        *b_JetsAK8JERup_origIndex;   //!
   TBranch        *b_JetsJECdown_jerFactor;   //!
   TBranch        *b_JetsJECdown_origIndex;   //!
   TBranch        *b_JetsJECup_jerFactor;   //!
   TBranch        *b_JetsJECup_origIndex;   //!
   TBranch        *b_JetsJERdown_origIndex;   //!
   TBranch        *b_JetsJERup_origIndex;   //!
   TBranch        *b_madHT;   //!
   TBranch        *b_madMinDeltaRStatus;   //!
   TBranch        *b_madMinPhotonDeltaR;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METDown;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_METPhiDown;   //!
   TBranch        *b_METPhiUp;   //!
   TBranch        *b_METSignificance;   //!
   TBranch        *b_METUp;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MHTJECdown;   //!
   TBranch        *b_MHTJECup;   //!
   TBranch        *b_MHTJERdown;   //!
   TBranch        *b_MHTJERup;   //!
   TBranch        *b_MHTPhi;   //!
   TBranch        *b_MHTPhiJECdown;   //!
   TBranch        *b_MHTPhiJECup;   //!
   TBranch        *b_MHTPhiJERdown;   //!
   TBranch        *b_MHTPhiJERup;   //!
   TBranch        *b_MJJ_AK8;   //!
   TBranch        *b_Mmc_AK8;   //!
   TBranch        *b_MT_AK8;   //!
   TBranch        *b_Muons;   //!
   TBranch        *b_Muons_charge;   //!
   TBranch        *b_Muons_iso;   //!
   TBranch        *b_Muons_mediumID;   //!
   TBranch        *b_Muons_MTW;   //!
   TBranch        *b_Muons_passIso;   //!
   TBranch        *b_Muons_tightID;   //!
   TBranch        *b_nAllVertices;   //!
   TBranch        *b_NElectrons;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_NJetsISR;   //!
   TBranch        *b_NJetsISRJECdown;   //!
   TBranch        *b_NJetsISRJECup;   //!
   TBranch        *b_NJetsISRJERdown;   //!
   TBranch        *b_NJetsISRJERup;   //!
   TBranch        *b_NJetsJECdown;   //!
   TBranch        *b_NJetsJECup;   //!
   TBranch        *b_NJetsJERdown;   //!
   TBranch        *b_NJetsJERup;   //!
   TBranch        *b_NMuons;   //!
   TBranch        *b_NonPrefiringProb;   //!
   TBranch        *b_NonPrefiringProbDown;   //!
   TBranch        *b_NonPrefiringProbUp;   //!
   TBranch        *b_NumEvents;   //!
   TBranch        *b_NumInteractions;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_PDFweights;   //!
   TBranch        *b_PFCaloMETRatio;   //!
   TBranch        *b_Photons;   //!
   TBranch        *b_Photons_electronFakes;   //!
   TBranch        *b_Photons_fullID;   //!
   TBranch        *b_Photons_genMatched;   //!
   TBranch        *b_Photons_hadTowOverEM;   //!
   TBranch        *b_Photons_hasPixelSeed;   //!
   TBranch        *b_Photons_isEB;   //!
   TBranch        *b_Photons_nonPrompt;   //!
   TBranch        *b_Photons_passElectronVeto;   //!
   TBranch        *b_Photons_pfChargedIso;   //!
   TBranch        *b_Photons_pfChargedIsoRhoCorr;   //!
   TBranch        *b_Photons_pfGammaIso;   //!
   TBranch        *b_Photons_pfGammaIsoRhoCorr;   //!
   TBranch        *b_Photons_pfNeutralIso;   //!
   TBranch        *b_Photons_pfNeutralIsoRhoCorr;   //!
   TBranch        *b_Photons_sigmaIetaIeta;   //!
   TBranch        *b_PrimaryVertexFilter;   //!
   TBranch        *b_PSweights;   //!
   TBranch        *b_puSysDown;   //!
   TBranch        *b_puSysUp;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_ScaleWeights;   //!
   TBranch        *b_SignalParameters;   //!
   TBranch        *b_SusyLSPMass;   //!
   TBranch        *b_SusyMotherMass;   //!
   TBranch        *b_TAPElectronTracks;   //!
   TBranch        *b_TAPElectronTracks_dxypv;   //!
   TBranch        *b_TAPElectronTracks_leptonMatch;   //!
   TBranch        *b_TAPElectronTracks_mT;   //!
   TBranch        *b_TAPElectronTracks_pfRelIso03chg;   //!
   TBranch        *b_TAPElectronTracks_trkiso;   //!
   TBranch        *b_TAPMuonTracks;   //!
   TBranch        *b_TAPMuonTracks_dxypv;   //!
   TBranch        *b_TAPMuonTracks_leptonMatch;   //!
   TBranch        *b_TAPMuonTracks_mT;   //!
   TBranch        *b_TAPMuonTracks_pfRelIso03chg;   //!
   TBranch        *b_TAPMuonTracks_trkiso;   //!
   TBranch        *b_TAPPionTracks;   //!
   TBranch        *b_TAPPionTracks_dxypv;   //!
   TBranch        *b_TAPPionTracks_leptonMatch;   //!
   TBranch        *b_TAPPionTracks_mT;   //!
   TBranch        *b_TAPPionTracks_pfRelIso03chg;   //!
   TBranch        *b_TAPPionTracks_trkiso;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TriggerPrescales;   //!
   TBranch        *b_TriggerVersion;   //!
   TBranch        *b_TrueNumInteractions;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_ZCandidates;   //!
   
 NtupleVariables(TTree * /*tree*/ =0) : fChain(0) { }
   ~NtupleVariables() { }
   void    Init(TTree *tree, string);
   Bool_t  Notify();
   Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   double  DeltaPhi(double, double);
   double  DeltaR(double eta1, double phi1, double eta2, double phi2);
   void    sortTLorVec(vector<TLorentzVector> *);   
   double  MinDr(TLorentzVector, vector<TLorentzVector>);
  double  MinDr2(vector<TLorentzVector>,TLorentzVector);
};

#endif
#ifdef NtupleVariables_cxx
void NtupleVariables::Init(TTree *tree, string nameData)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

   // Set object pointer
   // Set object pointer
   Electrons = 0;
   Electrons_charge = 0;
   Electrons_iso = 0;
   Electrons_mediumID = 0;
   Electrons_MTW = 0;
   Electrons_passIso = 0;
   Electrons_tightID = 0;
   GenElectrons = 0;
   GenJets = 0;
   GenJetsAK8 = 0;
   GenJetsAK8_multiplicity = 0;
   GenJetsAK8_softDropMass = 0;
   GenMuons = 0;
   GenParticles = 0;
   GenParticles_ParentId = 0;
   GenParticles_ParentIdx = 0;
   GenParticles_PdgId = 0;
   GenParticles_Status = 0;
   GenTaus = 0;
   GenTaus_had = 0;
   Jets = 0;
   Jets_axismajor = 0;
   Jets_axisminor = 0;
   Jets_bDiscriminatorCSV = 0;
   Jets_bJetTagDeepCSVBvsAll = 0;
   Jets_chargedEmEnergyFraction = 0;
   Jets_chargedHadronEnergyFraction = 0;
   Jets_chargedHadronMultiplicity = 0;
   Jets_chargedMultiplicity = 0;
   Jets_electronEnergyFraction = 0;
   Jets_electronMultiplicity = 0;
   Jets_hadronFlavor = 0;
   Jets_hfEMEnergyFraction = 0;
   Jets_hfHadronEnergyFraction = 0;
   Jets_HTMask = 0;
   Jets_ID = 0;
   Jets_jecFactor = 0;
   Jets_jecUnc = 0;
   Jets_jerFactor = 0;
   Jets_jerFactorDown = 0;
   Jets_jerFactorUp = 0;
   Jets_LeptonMask = 0;
   Jets_MHTMask = 0;
   Jets_multiplicity = 0;
   Jets_muonEnergyFraction = 0;
   Jets_muonMultiplicity = 0;
   Jets_neutralEmEnergyFraction = 0;
   Jets_neutralHadronEnergyFraction = 0;
   Jets_neutralHadronMultiplicity = 0;
   Jets_neutralMultiplicity = 0;
   Jets_origIndex = 0;
   Jets_partonFlavor = 0;
   Jets_photonEnergyFraction = 0;
   Jets_photonMultiplicity = 0;
   Jets_ptD = 0;
   Jets_qgLikelihood = 0;
   JetsAK8 = 0;
   JetsAK8_axismajor = 0;
   JetsAK8_axisminor = 0;
   JetsAK8_chargedEmEnergyFraction = 0;
   JetsAK8_chargedHadronEnergyFraction = 0;
   JetsAK8_chargedHadronMultiplicity = 0;
   JetsAK8_chargedMultiplicity = 0;
   JetsAK8_DeepMassDecorrelTagbbvsLight = 0;
   JetsAK8_DeepMassDecorrelTagHbbvsQCD = 0;
   JetsAK8_DeepMassDecorrelTagTvsQCD = 0;
   JetsAK8_DeepMassDecorrelTagWvsQCD = 0;
   JetsAK8_DeepMassDecorrelTagZbbvsQCD = 0;
   JetsAK8_DeepMassDecorrelTagZHbbvsQCD = 0;
   JetsAK8_DeepMassDecorrelTagZvsQCD = 0;
   JetsAK8_DeepTagHbbvsQCD = 0;
   JetsAK8_DeepTagTvsQCD = 0;
   JetsAK8_DeepTagWvsQCD = 0;
   JetsAK8_DeepTagZbbvsQCD = 0;
   JetsAK8_DeepTagZvsQCD = 0;
   JetsAK8_doubleBDiscriminator = 0;
   JetsAK8_ecfN2b1 = 0;
   JetsAK8_ecfN2b2 = 0;
   JetsAK8_ecfN3b1 = 0;
   JetsAK8_ecfN3b2 = 0;
   JetsAK8_electronEnergyFraction = 0;
   JetsAK8_electronMultiplicity = 0;
   JetsAK8_girth = 0;
   JetsAK8_hfEMEnergyFraction = 0;
   JetsAK8_hfHadronEnergyFraction = 0;
   JetsAK8_ID = 0;
   JetsAK8_isHV = 0;
   JetsAK8_jecFactor = 0;
   JetsAK8_jecUnc = 0;
   JetsAK8_jerFactor = 0;
   JetsAK8_jerFactorDown = 0;
   JetsAK8_jerFactorUp = 0;
   JetsAK8_multiplicity = 0;
   JetsAK8_muonEnergyFraction = 0;
   JetsAK8_muonMultiplicity = 0;
   JetsAK8_neutralEmEnergyFraction = 0;
   JetsAK8_neutralHadronEnergyFraction = 0;
   JetsAK8_neutralHadronMultiplicity = 0;
   JetsAK8_neutralMultiplicity = 0;
   JetsAK8_NsubjettinessTau1 = 0;
   JetsAK8_NsubjettinessTau2 = 0;
   JetsAK8_NsubjettinessTau3 = 0;
   JetsAK8_NumBhadrons = 0;
   JetsAK8_NumChadrons = 0;
   JetsAK8_origIndex = 0;
   JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb = 0;
   JetsAK8_photonEnergyFraction = 0;
   JetsAK8_photonMultiplicity = 0;
   JetsAK8_ptD = 0;
   JetsAK8_softDropMass = 0;
   JetsAK8_subjets = 0;
   JetsAK8_subjets_axismajor = 0;
   JetsAK8_subjets_axisminor = 0;
   JetsAK8_subjets_bDiscriminatorCSV = 0;
   JetsAK8_subjets_jecFactor = 0;
   JetsAK8_subjets_multiplicity = 0;
   JetsAK8_subjets_ptD = 0;
   JetsAK8JECdown_jerFactor = 0;
   JetsAK8JECdown_origIndex = 0;
   JetsAK8JECup_jerFactor = 0;
   JetsAK8JECup_origIndex = 0;
   JetsAK8JERdown_origIndex = 0;
   JetsAK8JERup_origIndex = 0;
   JetsJECdown_jerFactor = 0;
   JetsJECdown_origIndex = 0;
   JetsJECup_jerFactor = 0;
   JetsJECup_origIndex = 0;
   JetsJERdown_origIndex = 0;
   JetsJERup_origIndex = 0;
   METDown = 0;
   METPhiDown = 0;
   METPhiUp = 0;
   METUp = 0;
   Muons = 0;
   Muons_charge = 0;
   Muons_iso = 0;
   Muons_mediumID = 0;
   Muons_MTW = 0;
   Muons_passIso = 0;
   Muons_tightID = 0;
   PDFweights = 0;
   Photons = 0;
   Photons_electronFakes = 0;
   Photons_fullID = 0;
   Photons_genMatched = 0;
   Photons_hadTowOverEM = 0;
   Photons_hasPixelSeed = 0;
   Photons_isEB = 0;
   Photons_nonPrompt = 0;
   Photons_passElectronVeto = 0;
   Photons_pfChargedIso = 0;
   Photons_pfChargedIsoRhoCorr = 0;
   Photons_pfGammaIso = 0;
   Photons_pfGammaIsoRhoCorr = 0;
   Photons_pfNeutralIso = 0;
   Photons_pfNeutralIsoRhoCorr = 0;
   Photons_sigmaIetaIeta = 0;
   PSweights = 0;
   ScaleWeights = 0;
   SignalParameters = 0;
   TAPElectronTracks = 0;
   TAPElectronTracks_dxypv = 0;
   TAPElectronTracks_leptonMatch = 0;
   TAPElectronTracks_mT = 0;
   TAPElectronTracks_pfRelIso03chg = 0;
   TAPElectronTracks_trkiso = 0;
   TAPMuonTracks = 0;
   TAPMuonTracks_dxypv = 0;
   TAPMuonTracks_leptonMatch = 0;
   TAPMuonTracks_mT = 0;
   TAPMuonTracks_pfRelIso03chg = 0;
   TAPMuonTracks_trkiso = 0;
   TAPPionTracks = 0;
   TAPPionTracks_dxypv = 0;
   TAPPionTracks_leptonMatch = 0;
   TAPPionTracks_mT = 0;
   TAPPionTracks_pfRelIso03chg = 0;
   TAPPionTracks_trkiso = 0;
   TriggerPass = 0;
   TriggerPrescales = 0;
   TriggerVersion = 0;
   ZCandidates = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("BadChargedCandidateFilter", &BadChargedCandidateFilter, &b_BadChargedCandidateFilter);
   fChain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("BTagsclean", &BTagsclean, &b_BTagsclean);
   fChain->SetBranchAddress("BTagsDeepCSV", &BTagsDeepCSV, &b_BTagsDeepCSV);
   fChain->SetBranchAddress("BTagsDeepCSVclean", &BTagsDeepCSVclean, &b_BTagsDeepCSVclean);
   fChain->SetBranchAddress("BTagsDeepCSVJECdown", &BTagsDeepCSVJECdown, &b_BTagsDeepCSVJECdown);
   fChain->SetBranchAddress("BTagsDeepCSVJECup", &BTagsDeepCSVJECup, &b_BTagsDeepCSVJECup);
   fChain->SetBranchAddress("BTagsDeepCSVJERdown", &BTagsDeepCSVJERdown, &b_BTagsDeepCSVJERdown);
   fChain->SetBranchAddress("BTagsDeepCSVJERup", &BTagsDeepCSVJERup, &b_BTagsDeepCSVJERup);
   fChain->SetBranchAddress("BTagsJECdown", &BTagsJECdown, &b_BTagsJECdown);
   fChain->SetBranchAddress("BTagsJECup", &BTagsJECup, &b_BTagsJECup);
   fChain->SetBranchAddress("BTagsJERdown", &BTagsJERdown, &b_BTagsJERdown);
   fChain->SetBranchAddress("BTagsJERup", &BTagsJERup, &b_BTagsJERup);
   fChain->SetBranchAddress("CaloMET", &CaloMET, &b_CaloMET);
   fChain->SetBranchAddress("CaloMETPhi", &CaloMETPhi, &b_CaloMETPhi);
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
   fChain->SetBranchAddress("ecalBadCalibFilter", &ecalBadCalibFilter, &b_ecalBadCalibFilter);
   fChain->SetBranchAddress("ecalBadCalibReducedExtraFilter", &ecalBadCalibReducedExtraFilter, &b_ecalBadCalibReducedExtraFilter);
   fChain->SetBranchAddress("ecalBadCalibReducedFilter", &ecalBadCalibReducedFilter, &b_ecalBadCalibReducedFilter);
   fChain->SetBranchAddress("EcalDeadCellBoundaryEnergyFilter", &EcalDeadCellBoundaryEnergyFilter, &b_EcalDeadCellBoundaryEnergyFilter);
   fChain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("eeBadScFilter", &eeBadScFilter, &b_eeBadScFilter);
   fChain->SetBranchAddress("Electrons", &Electrons, &b_Electrons);
   fChain->SetBranchAddress("Electrons_charge", &Electrons_charge, &b_Electrons_charge);
   fChain->SetBranchAddress("Electrons_iso", &Electrons_iso, &b_Electrons_iso);
   fChain->SetBranchAddress("Electrons_mediumID", &Electrons_mediumID, &b_Electrons_mediumID);
   fChain->SetBranchAddress("Electrons_MTW", &Electrons_MTW, &b_Electrons_MTW);
   fChain->SetBranchAddress("Electrons_passIso", &Electrons_passIso, &b_Electrons_passIso);
   fChain->SetBranchAddress("Electrons_tightID", &Electrons_tightID, &b_Electrons_tightID);
   fChain->SetBranchAddress("fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("GenElectrons", &GenElectrons, &b_GenElectrons);
   fChain->SetBranchAddress("GenHT", &GenHT, &b_GenHT);
   fChain->SetBranchAddress("GenJets", &GenJets, &b_GenJets);
   fChain->SetBranchAddress("GenJetsAK8", &GenJetsAK8, &b_GenJetsAK8);
   fChain->SetBranchAddress("GenJetsAK8_multiplicity", &GenJetsAK8_multiplicity, &b_GenJetsAK8_multiplicity);
   fChain->SetBranchAddress("GenJetsAK8_softDropMass", &GenJetsAK8_softDropMass, &b_GenJetsAK8_softDropMass);
   fChain->SetBranchAddress("GenMET", &GenMET, &b_GenMET);
   fChain->SetBranchAddress("GenMETPhi", &GenMETPhi, &b_GenMETPhi);
   fChain->SetBranchAddress("GenMHT", &GenMHT, &b_GenMHT);
   fChain->SetBranchAddress("GenMHTPhi", &GenMHTPhi, &b_GenMHTPhi);
   fChain->SetBranchAddress("GenMuons", &GenMuons, &b_GenMuons);
   fChain->SetBranchAddress("GenParticles", &GenParticles, &b_GenParticles);
   fChain->SetBranchAddress("GenParticles_ParentId", &GenParticles_ParentId, &b_GenParticles_ParentId);
   fChain->SetBranchAddress("GenParticles_ParentIdx", &GenParticles_ParentIdx, &b_GenParticles_ParentIdx);
   fChain->SetBranchAddress("GenParticles_PdgId", &GenParticles_PdgId, &b_GenParticles_PdgId);
   fChain->SetBranchAddress("GenParticles_Status", &GenParticles_Status, &b_GenParticles_Status);
   fChain->SetBranchAddress("GenTaus", &GenTaus, &b_GenTaus);
   fChain->SetBranchAddress("GenTaus_had", &GenTaus_had, &b_GenTaus_had);
   fChain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
   fChain->SetBranchAddress("globalTightHalo2016Filter", &globalTightHalo2016Filter, &b_globalTightHalo2016Filter);
   fChain->SetBranchAddress("hasGenPromptPhoton", &hasGenPromptPhoton, &b_hasGenPromptPhoton);
   fChain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT5", &HT5, &b_HT5);
   fChain->SetBranchAddress("HT5JECdown", &HT5JECdown, &b_HT5JECdown);
   fChain->SetBranchAddress("HT5JECup", &HT5JECup, &b_HT5JECup);
   fChain->SetBranchAddress("HT5JERdown", &HT5JERdown, &b_HT5JERdown);
   fChain->SetBranchAddress("HT5JERup", &HT5JERup, &b_HT5JERup);
   fChain->SetBranchAddress("HTJECdown", &HTJECdown, &b_HTJECdown);
   fChain->SetBranchAddress("HTJECup", &HTJECup, &b_HTJECup);
   fChain->SetBranchAddress("HTJERdown", &HTJERdown, &b_HTJERdown);
   fChain->SetBranchAddress("HTJERup", &HTJERup, &b_HTJERup);
   fChain->SetBranchAddress("isoElectronTracks", &isoElectronTracks, &b_isoElectronTracks);
   fChain->SetBranchAddress("isoMuonTracks", &isoMuonTracks, &b_isoMuonTracks);
   fChain->SetBranchAddress("isoPionTracks", &isoPionTracks, &b_isoPionTracks);
   fChain->SetBranchAddress("JetID", &JetID, &b_JetID);
   fChain->SetBranchAddress("JetIDAK8", &JetIDAK8, &b_JetIDAK8);
   fChain->SetBranchAddress("JetIDAK8JECdown", &JetIDAK8JECdown, &b_JetIDAK8JECdown);
   fChain->SetBranchAddress("JetIDAK8JECup", &JetIDAK8JECup, &b_JetIDAK8JECup);
   fChain->SetBranchAddress("JetIDAK8JERdown", &JetIDAK8JERdown, &b_JetIDAK8JERdown);
   fChain->SetBranchAddress("JetIDAK8JERup", &JetIDAK8JERup, &b_JetIDAK8JERup);
   fChain->SetBranchAddress("JetIDJECdown", &JetIDJECdown, &b_JetIDJECdown);
   fChain->SetBranchAddress("JetIDJECup", &JetIDJECup, &b_JetIDJECup);
   fChain->SetBranchAddress("JetIDJERdown", &JetIDJERdown, &b_JetIDJERdown);
   fChain->SetBranchAddress("JetIDJERup", &JetIDJERup, &b_JetIDJERup);
   fChain->SetBranchAddress("Jets", &Jets, &b_Jets);
   fChain->SetBranchAddress("Jets_axismajor", &Jets_axismajor, &b_Jets_axismajor);
   fChain->SetBranchAddress("Jets_axisminor", &Jets_axisminor, &b_Jets_axisminor);
   fChain->SetBranchAddress("Jets_bDiscriminatorCSV", &Jets_bDiscriminatorCSV, &b_Jets_bDiscriminatorCSV);
   fChain->SetBranchAddress("Jets_bJetTagDeepCSVBvsAll", &Jets_bJetTagDeepCSVBvsAll, &b_Jets_bJetTagDeepCSVBvsAll);
   fChain->SetBranchAddress("Jets_chargedEmEnergyFraction", &Jets_chargedEmEnergyFraction, &b_Jets_chargedEmEnergyFraction);
   fChain->SetBranchAddress("Jets_chargedHadronEnergyFraction", &Jets_chargedHadronEnergyFraction, &b_Jets_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("Jets_chargedHadronMultiplicity", &Jets_chargedHadronMultiplicity, &b_Jets_chargedHadronMultiplicity);
   fChain->SetBranchAddress("Jets_chargedMultiplicity", &Jets_chargedMultiplicity, &b_Jets_chargedMultiplicity);
   fChain->SetBranchAddress("Jets_electronEnergyFraction", &Jets_electronEnergyFraction, &b_Jets_electronEnergyFraction);
   fChain->SetBranchAddress("Jets_electronMultiplicity", &Jets_electronMultiplicity, &b_Jets_electronMultiplicity);
   fChain->SetBranchAddress("Jets_hadronFlavor", &Jets_hadronFlavor, &b_Jets_hadronFlavor);
   fChain->SetBranchAddress("Jets_hfEMEnergyFraction", &Jets_hfEMEnergyFraction, &b_Jets_hfEMEnergyFraction);
   fChain->SetBranchAddress("Jets_hfHadronEnergyFraction", &Jets_hfHadronEnergyFraction, &b_Jets_hfHadronEnergyFraction);
   fChain->SetBranchAddress("Jets_HTMask", &Jets_HTMask, &b_Jets_HTMask);
   fChain->SetBranchAddress("Jets_ID", &Jets_ID, &b_Jets_ID);
   fChain->SetBranchAddress("Jets_jecFactor", &Jets_jecFactor, &b_Jets_jecFactor);
   fChain->SetBranchAddress("Jets_jecUnc", &Jets_jecUnc, &b_Jets_jecUnc);
   fChain->SetBranchAddress("Jets_jerFactor", &Jets_jerFactor, &b_Jets_jerFactor);
   fChain->SetBranchAddress("Jets_jerFactorDown", &Jets_jerFactorDown, &b_Jets_jerFactorDown);
   fChain->SetBranchAddress("Jets_jerFactorUp", &Jets_jerFactorUp, &b_Jets_jerFactorUp);
   fChain->SetBranchAddress("Jets_LeptonMask", &Jets_LeptonMask, &b_Jets_LeptonMask);
   fChain->SetBranchAddress("Jets_MHTMask", &Jets_MHTMask, &b_Jets_MHTMask);
   fChain->SetBranchAddress("Jets_multiplicity", &Jets_multiplicity, &b_Jets_multiplicity);
   fChain->SetBranchAddress("Jets_muonEnergyFraction", &Jets_muonEnergyFraction, &b_Jets_muonEnergyFraction);
   fChain->SetBranchAddress("Jets_muonMultiplicity", &Jets_muonMultiplicity, &b_Jets_muonMultiplicity);
   fChain->SetBranchAddress("Jets_neutralEmEnergyFraction", &Jets_neutralEmEnergyFraction, &b_Jets_neutralEmEnergyFraction);
   fChain->SetBranchAddress("Jets_neutralHadronEnergyFraction", &Jets_neutralHadronEnergyFraction, &b_Jets_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("Jets_neutralHadronMultiplicity", &Jets_neutralHadronMultiplicity, &b_Jets_neutralHadronMultiplicity);
   fChain->SetBranchAddress("Jets_neutralMultiplicity", &Jets_neutralMultiplicity, &b_Jets_neutralMultiplicity);
   fChain->SetBranchAddress("Jets_origIndex", &Jets_origIndex, &b_Jets_origIndex);
   fChain->SetBranchAddress("Jets_partonFlavor", &Jets_partonFlavor, &b_Jets_partonFlavor);
   fChain->SetBranchAddress("Jets_photonEnergyFraction", &Jets_photonEnergyFraction, &b_Jets_photonEnergyFraction);
   fChain->SetBranchAddress("Jets_photonMultiplicity", &Jets_photonMultiplicity, &b_Jets_photonMultiplicity);
   fChain->SetBranchAddress("Jets_ptD", &Jets_ptD, &b_Jets_ptD);
   fChain->SetBranchAddress("Jets_qgLikelihood", &Jets_qgLikelihood, &b_Jets_qgLikelihood);
   fChain->SetBranchAddress("JetsAK8", &JetsAK8, &b_JetsAK8);
   fChain->SetBranchAddress("JetsAK8_axismajor", &JetsAK8_axismajor, &b_JetsAK8_axismajor);
   fChain->SetBranchAddress("JetsAK8_axisminor", &JetsAK8_axisminor, &b_JetsAK8_axisminor);
   fChain->SetBranchAddress("JetsAK8_chargedEmEnergyFraction", &JetsAK8_chargedEmEnergyFraction, &b_JetsAK8_chargedEmEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_chargedHadronEnergyFraction", &JetsAK8_chargedHadronEnergyFraction, &b_JetsAK8_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_chargedHadronMultiplicity", &JetsAK8_chargedHadronMultiplicity, &b_JetsAK8_chargedHadronMultiplicity);
   fChain->SetBranchAddress("JetsAK8_chargedMultiplicity", &JetsAK8_chargedMultiplicity, &b_JetsAK8_chargedMultiplicity);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagbbvsLight", &JetsAK8_DeepMassDecorrelTagbbvsLight, &b_JetsAK8_DeepMassDecorrelTagbbvsLight);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagHbbvsQCD", &JetsAK8_DeepMassDecorrelTagHbbvsQCD, &b_JetsAK8_DeepMassDecorrelTagHbbvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagTvsQCD", &JetsAK8_DeepMassDecorrelTagTvsQCD, &b_JetsAK8_DeepMassDecorrelTagTvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagWvsQCD", &JetsAK8_DeepMassDecorrelTagWvsQCD, &b_JetsAK8_DeepMassDecorrelTagWvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagZbbvsQCD", &JetsAK8_DeepMassDecorrelTagZbbvsQCD, &b_JetsAK8_DeepMassDecorrelTagZbbvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagZHbbvsQCD", &JetsAK8_DeepMassDecorrelTagZHbbvsQCD, &b_JetsAK8_DeepMassDecorrelTagZHbbvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepMassDecorrelTagZvsQCD", &JetsAK8_DeepMassDecorrelTagZvsQCD, &b_JetsAK8_DeepMassDecorrelTagZvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepTagHbbvsQCD", &JetsAK8_DeepTagHbbvsQCD, &b_JetsAK8_DeepTagHbbvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepTagTvsQCD", &JetsAK8_DeepTagTvsQCD, &b_JetsAK8_DeepTagTvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepTagWvsQCD", &JetsAK8_DeepTagWvsQCD, &b_JetsAK8_DeepTagWvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepTagZbbvsQCD", &JetsAK8_DeepTagZbbvsQCD, &b_JetsAK8_DeepTagZbbvsQCD);
   fChain->SetBranchAddress("JetsAK8_DeepTagZvsQCD", &JetsAK8_DeepTagZvsQCD, &b_JetsAK8_DeepTagZvsQCD);
   fChain->SetBranchAddress("JetsAK8_doubleBDiscriminator", &JetsAK8_doubleBDiscriminator, &b_JetsAK8_doubleBDiscriminator);
   fChain->SetBranchAddress("JetsAK8_ecfN2b1", &JetsAK8_ecfN2b1, &b_JetsAK8_ecfN2b1);
   fChain->SetBranchAddress("JetsAK8_ecfN2b2", &JetsAK8_ecfN2b2, &b_JetsAK8_ecfN2b2);
   fChain->SetBranchAddress("JetsAK8_ecfN3b1", &JetsAK8_ecfN3b1, &b_JetsAK8_ecfN3b1);
   fChain->SetBranchAddress("JetsAK8_ecfN3b2", &JetsAK8_ecfN3b2, &b_JetsAK8_ecfN3b2);
   fChain->SetBranchAddress("JetsAK8_electronEnergyFraction", &JetsAK8_electronEnergyFraction, &b_JetsAK8_electronEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_electronMultiplicity", &JetsAK8_electronMultiplicity, &b_JetsAK8_electronMultiplicity);
   fChain->SetBranchAddress("JetsAK8_girth", &JetsAK8_girth, &b_JetsAK8_girth);
   fChain->SetBranchAddress("JetsAK8_hfEMEnergyFraction", &JetsAK8_hfEMEnergyFraction, &b_JetsAK8_hfEMEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_hfHadronEnergyFraction", &JetsAK8_hfHadronEnergyFraction, &b_JetsAK8_hfHadronEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_ID", &JetsAK8_ID, &b_JetsAK8_ID);
   fChain->SetBranchAddress("JetsAK8_isHV", &JetsAK8_isHV, &b_JetsAK8_isHV);
   fChain->SetBranchAddress("JetsAK8_jecFactor", &JetsAK8_jecFactor, &b_JetsAK8_jecFactor);
   fChain->SetBranchAddress("JetsAK8_jecUnc", &JetsAK8_jecUnc, &b_JetsAK8_jecUnc);
   fChain->SetBranchAddress("JetsAK8_jerFactor", &JetsAK8_jerFactor, &b_JetsAK8_jerFactor);
   fChain->SetBranchAddress("JetsAK8_jerFactorDown", &JetsAK8_jerFactorDown, &b_JetsAK8_jerFactorDown);
   fChain->SetBranchAddress("JetsAK8_jerFactorUp", &JetsAK8_jerFactorUp, &b_JetsAK8_jerFactorUp);
   fChain->SetBranchAddress("JetsAK8_multiplicity", &JetsAK8_multiplicity, &b_JetsAK8_multiplicity);
   fChain->SetBranchAddress("JetsAK8_muonEnergyFraction", &JetsAK8_muonEnergyFraction, &b_JetsAK8_muonEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_muonMultiplicity", &JetsAK8_muonMultiplicity, &b_JetsAK8_muonMultiplicity);
   fChain->SetBranchAddress("JetsAK8_neutralEmEnergyFraction", &JetsAK8_neutralEmEnergyFraction, &b_JetsAK8_neutralEmEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_neutralHadronEnergyFraction", &JetsAK8_neutralHadronEnergyFraction, &b_JetsAK8_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_neutralHadronMultiplicity", &JetsAK8_neutralHadronMultiplicity, &b_JetsAK8_neutralHadronMultiplicity);
   fChain->SetBranchAddress("JetsAK8_neutralMultiplicity", &JetsAK8_neutralMultiplicity, &b_JetsAK8_neutralMultiplicity);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau1", &JetsAK8_NsubjettinessTau1, &b_JetsAK8_NsubjettinessTau1);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau2", &JetsAK8_NsubjettinessTau2, &b_JetsAK8_NsubjettinessTau2);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau3", &JetsAK8_NsubjettinessTau3, &b_JetsAK8_NsubjettinessTau3);
   fChain->SetBranchAddress("JetsAK8_NumBhadrons", &JetsAK8_NumBhadrons, &b_JetsAK8_NumBhadrons);
   fChain->SetBranchAddress("JetsAK8_NumChadrons", &JetsAK8_NumChadrons, &b_JetsAK8_NumChadrons);
   fChain->SetBranchAddress("JetsAK8_origIndex", &JetsAK8_origIndex, &b_JetsAK8_origIndex);
   fChain->SetBranchAddress("JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb", &JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb, &b_JetsAK8_pfMassIndependentDeepDoubleBvLJetTagsProbHbb);
   fChain->SetBranchAddress("JetsAK8_photonEnergyFraction", &JetsAK8_photonEnergyFraction, &b_JetsAK8_photonEnergyFraction);
   fChain->SetBranchAddress("JetsAK8_photonMultiplicity", &JetsAK8_photonMultiplicity, &b_JetsAK8_photonMultiplicity);
   fChain->SetBranchAddress("JetsAK8_ptD", &JetsAK8_ptD, &b_JetsAK8_ptD);
   fChain->SetBranchAddress("JetsAK8_softDropMass", &JetsAK8_softDropMass, &b_JetsAK8_softDropMass);
   fChain->SetBranchAddress("JetsAK8_subjets", &JetsAK8_subjets, &b_JetsAK8_subjets);
   fChain->SetBranchAddress("JetsAK8_subjets_axismajor", &JetsAK8_subjets_axismajor, &b_JetsAK8_subjets_axismajor);
   fChain->SetBranchAddress("JetsAK8_subjets_axisminor", &JetsAK8_subjets_axisminor, &b_JetsAK8_subjets_axisminor);
   fChain->SetBranchAddress("JetsAK8_subjets_bDiscriminatorCSV", &JetsAK8_subjets_bDiscriminatorCSV, &b_JetsAK8_subjets_bDiscriminatorCSV);
   fChain->SetBranchAddress("JetsAK8_subjets_jecFactor", &JetsAK8_subjets_jecFactor, &b_JetsAK8_subjets_jecFactor);
   fChain->SetBranchAddress("JetsAK8_subjets_multiplicity", &JetsAK8_subjets_multiplicity, &b_JetsAK8_subjets_multiplicity);
   fChain->SetBranchAddress("JetsAK8_subjets_ptD", &JetsAK8_subjets_ptD, &b_JetsAK8_subjets_ptD);
   fChain->SetBranchAddress("JetsAK8JECdown_jerFactor", &JetsAK8JECdown_jerFactor, &b_JetsAK8JECdown_jerFactor);
   fChain->SetBranchAddress("JetsAK8JECdown_origIndex", &JetsAK8JECdown_origIndex, &b_JetsAK8JECdown_origIndex);
   fChain->SetBranchAddress("JetsAK8JECup_jerFactor", &JetsAK8JECup_jerFactor, &b_JetsAK8JECup_jerFactor);
   fChain->SetBranchAddress("JetsAK8JECup_origIndex", &JetsAK8JECup_origIndex, &b_JetsAK8JECup_origIndex);
   fChain->SetBranchAddress("JetsAK8JERdown_origIndex", &JetsAK8JERdown_origIndex, &b_JetsAK8JERdown_origIndex);
   fChain->SetBranchAddress("JetsAK8JERup_origIndex", &JetsAK8JERup_origIndex, &b_JetsAK8JERup_origIndex);
   fChain->SetBranchAddress("JetsJECdown_jerFactor", &JetsJECdown_jerFactor, &b_JetsJECdown_jerFactor);
   fChain->SetBranchAddress("JetsJECdown_origIndex", &JetsJECdown_origIndex, &b_JetsJECdown_origIndex);
   fChain->SetBranchAddress("JetsJECup_jerFactor", &JetsJECup_jerFactor, &b_JetsJECup_jerFactor);
   fChain->SetBranchAddress("JetsJECup_origIndex", &JetsJECup_origIndex, &b_JetsJECup_origIndex);
   fChain->SetBranchAddress("JetsJERdown_origIndex", &JetsJERdown_origIndex, &b_JetsJERdown_origIndex);
   fChain->SetBranchAddress("JetsJERup_origIndex", &JetsJERup_origIndex, &b_JetsJERup_origIndex);
   fChain->SetBranchAddress("madHT", &madHT, &b_madHT);
   fChain->SetBranchAddress("madMinDeltaRStatus", &madMinDeltaRStatus, &b_madMinDeltaRStatus);
   fChain->SetBranchAddress("madMinPhotonDeltaR", &madMinPhotonDeltaR, &b_madMinPhotonDeltaR);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METDown", &METDown, &b_METDown);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("METPhiDown", &METPhiDown, &b_METPhiDown);
   fChain->SetBranchAddress("METPhiUp", &METPhiUp, &b_METPhiUp);
   fChain->SetBranchAddress("METSignificance", &METSignificance, &b_METSignificance);
   fChain->SetBranchAddress("METUp", &METUp, &b_METUp);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHTJECdown", &MHTJECdown, &b_MHTJECdown);
   fChain->SetBranchAddress("MHTJECup", &MHTJECup, &b_MHTJECup);
   fChain->SetBranchAddress("MHTJERdown", &MHTJERdown, &b_MHTJERdown);
   fChain->SetBranchAddress("MHTJERup", &MHTJERup, &b_MHTJERup);
   fChain->SetBranchAddress("MHTPhi", &MHTPhi, &b_MHTPhi);
   fChain->SetBranchAddress("MHTPhiJECdown", &MHTPhiJECdown, &b_MHTPhiJECdown);
   fChain->SetBranchAddress("MHTPhiJECup", &MHTPhiJECup, &b_MHTPhiJECup);
   fChain->SetBranchAddress("MHTPhiJERdown", &MHTPhiJERdown, &b_MHTPhiJERdown);
   fChain->SetBranchAddress("MHTPhiJERup", &MHTPhiJERup, &b_MHTPhiJERup);
   fChain->SetBranchAddress("MJJ_AK8", &MJJ_AK8, &b_MJJ_AK8);
   fChain->SetBranchAddress("Mmc_AK8", &Mmc_AK8, &b_Mmc_AK8);
   fChain->SetBranchAddress("MT_AK8", &MT_AK8, &b_MT_AK8);
   fChain->SetBranchAddress("Muons", &Muons, &b_Muons);
   fChain->SetBranchAddress("Muons_charge", &Muons_charge, &b_Muons_charge);
   fChain->SetBranchAddress("Muons_iso", &Muons_iso, &b_Muons_iso);
   fChain->SetBranchAddress("Muons_mediumID", &Muons_mediumID, &b_Muons_mediumID);
   fChain->SetBranchAddress("Muons_MTW", &Muons_MTW, &b_Muons_MTW);
   fChain->SetBranchAddress("Muons_passIso", &Muons_passIso, &b_Muons_passIso);
   fChain->SetBranchAddress("Muons_tightID", &Muons_tightID, &b_Muons_tightID);
   fChain->SetBranchAddress("nAllVertices", &nAllVertices, &b_nAllVertices);
   fChain->SetBranchAddress("NElectrons", &NElectrons, &b_NElectrons);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("NJetsISR", &NJetsISR, &b_NJetsISR);
   fChain->SetBranchAddress("NJetsISRJECdown", &NJetsISRJECdown, &b_NJetsISRJECdown);
   fChain->SetBranchAddress("NJetsISRJECup", &NJetsISRJECup, &b_NJetsISRJECup);
   fChain->SetBranchAddress("NJetsISRJERdown", &NJetsISRJERdown, &b_NJetsISRJERdown);
   fChain->SetBranchAddress("NJetsISRJERup", &NJetsISRJERup, &b_NJetsISRJERup);
   fChain->SetBranchAddress("NJetsJECdown", &NJetsJECdown, &b_NJetsJECdown);
   fChain->SetBranchAddress("NJetsJECup", &NJetsJECup, &b_NJetsJECup);
   fChain->SetBranchAddress("NJetsJERdown", &NJetsJERdown, &b_NJetsJERdown);
   fChain->SetBranchAddress("NJetsJERup", &NJetsJERup, &b_NJetsJERup);
   fChain->SetBranchAddress("NMuons", &NMuons, &b_NMuons);
   fChain->SetBranchAddress("NonPrefiringProb", &NonPrefiringProb, &b_NonPrefiringProb);
   fChain->SetBranchAddress("NonPrefiringProbDown", &NonPrefiringProbDown, &b_NonPrefiringProbDown);
   fChain->SetBranchAddress("NonPrefiringProbUp", &NonPrefiringProbUp, &b_NonPrefiringProbUp);
   fChain->SetBranchAddress("NumEvents", &NumEvents, &b_NumEvents);
   fChain->SetBranchAddress("NumInteractions", &NumInteractions, &b_NumInteractions);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("PDFweights", &PDFweights, &b_PDFweights);
   fChain->SetBranchAddress("PFCaloMETRatio", &PFCaloMETRatio, &b_PFCaloMETRatio);
   fChain->SetBranchAddress("Photons", &Photons, &b_Photons);
   fChain->SetBranchAddress("Photons_electronFakes", &Photons_electronFakes, &b_Photons_electronFakes);
   fChain->SetBranchAddress("Photons_fullID", &Photons_fullID, &b_Photons_fullID);
   fChain->SetBranchAddress("Photons_genMatched", &Photons_genMatched, &b_Photons_genMatched);
   fChain->SetBranchAddress("Photons_hadTowOverEM", &Photons_hadTowOverEM, &b_Photons_hadTowOverEM);
   fChain->SetBranchAddress("Photons_hasPixelSeed", &Photons_hasPixelSeed, &b_Photons_hasPixelSeed);
   fChain->SetBranchAddress("Photons_isEB", &Photons_isEB, &b_Photons_isEB);
   fChain->SetBranchAddress("Photons_nonPrompt", &Photons_nonPrompt, &b_Photons_nonPrompt);
   fChain->SetBranchAddress("Photons_passElectronVeto", &Photons_passElectronVeto, &b_Photons_passElectronVeto);
   fChain->SetBranchAddress("Photons_pfChargedIso", &Photons_pfChargedIso, &b_Photons_pfChargedIso);
   fChain->SetBranchAddress("Photons_pfChargedIsoRhoCorr", &Photons_pfChargedIsoRhoCorr, &b_Photons_pfChargedIsoRhoCorr);
   fChain->SetBranchAddress("Photons_pfGammaIso", &Photons_pfGammaIso, &b_Photons_pfGammaIso);
   fChain->SetBranchAddress("Photons_pfGammaIsoRhoCorr", &Photons_pfGammaIsoRhoCorr, &b_Photons_pfGammaIsoRhoCorr);
   fChain->SetBranchAddress("Photons_pfNeutralIso", &Photons_pfNeutralIso, &b_Photons_pfNeutralIso);
   fChain->SetBranchAddress("Photons_pfNeutralIsoRhoCorr", &Photons_pfNeutralIsoRhoCorr, &b_Photons_pfNeutralIsoRhoCorr);
   fChain->SetBranchAddress("Photons_sigmaIetaIeta", &Photons_sigmaIetaIeta, &b_Photons_sigmaIetaIeta);
   fChain->SetBranchAddress("PrimaryVertexFilter", &PrimaryVertexFilter, &b_PrimaryVertexFilter);
   fChain->SetBranchAddress("PSweights", &PSweights, &b_PSweights);
   fChain->SetBranchAddress("puSysDown", &puSysDown, &b_puSysDown);
   fChain->SetBranchAddress("puSysUp", &puSysUp, &b_puSysUp);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("ScaleWeights", &ScaleWeights, &b_ScaleWeights);
   fChain->SetBranchAddress("SignalParameters", &SignalParameters, &b_SignalParameters);
   fChain->SetBranchAddress("SusyLSPMass", &SusyLSPMass, &b_SusyLSPMass);
   fChain->SetBranchAddress("SusyMotherMass", &SusyMotherMass, &b_SusyMotherMass);
   fChain->SetBranchAddress("TAPElectronTracks", &TAPElectronTracks, &b_TAPElectronTracks);
   fChain->SetBranchAddress("TAPElectronTracks_dxypv", &TAPElectronTracks_dxypv, &b_TAPElectronTracks_dxypv);
   fChain->SetBranchAddress("TAPElectronTracks_leptonMatch", &TAPElectronTracks_leptonMatch, &b_TAPElectronTracks_leptonMatch);
   fChain->SetBranchAddress("TAPElectronTracks_mT", &TAPElectronTracks_mT, &b_TAPElectronTracks_mT);
   fChain->SetBranchAddress("TAPElectronTracks_pfRelIso03chg", &TAPElectronTracks_pfRelIso03chg, &b_TAPElectronTracks_pfRelIso03chg);
   fChain->SetBranchAddress("TAPElectronTracks_trkiso", &TAPElectronTracks_trkiso, &b_TAPElectronTracks_trkiso);
   fChain->SetBranchAddress("TAPMuonTracks", &TAPMuonTracks, &b_TAPMuonTracks);
   fChain->SetBranchAddress("TAPMuonTracks_dxypv", &TAPMuonTracks_dxypv, &b_TAPMuonTracks_dxypv);
   fChain->SetBranchAddress("TAPMuonTracks_leptonMatch", &TAPMuonTracks_leptonMatch, &b_TAPMuonTracks_leptonMatch);
   fChain->SetBranchAddress("TAPMuonTracks_mT", &TAPMuonTracks_mT, &b_TAPMuonTracks_mT);
   fChain->SetBranchAddress("TAPMuonTracks_pfRelIso03chg", &TAPMuonTracks_pfRelIso03chg, &b_TAPMuonTracks_pfRelIso03chg);
   fChain->SetBranchAddress("TAPMuonTracks_trkiso", &TAPMuonTracks_trkiso, &b_TAPMuonTracks_trkiso);
   fChain->SetBranchAddress("TAPPionTracks", &TAPPionTracks, &b_TAPPionTracks);
   fChain->SetBranchAddress("TAPPionTracks_dxypv", &TAPPionTracks_dxypv, &b_TAPPionTracks_dxypv);
   fChain->SetBranchAddress("TAPPionTracks_leptonMatch", &TAPPionTracks_leptonMatch, &b_TAPPionTracks_leptonMatch);
   fChain->SetBranchAddress("TAPPionTracks_mT", &TAPPionTracks_mT, &b_TAPPionTracks_mT);
   fChain->SetBranchAddress("TAPPionTracks_pfRelIso03chg", &TAPPionTracks_pfRelIso03chg, &b_TAPPionTracks_pfRelIso03chg);
   fChain->SetBranchAddress("TAPPionTracks_trkiso", &TAPPionTracks_trkiso, &b_TAPPionTracks_trkiso);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
   fChain->SetBranchAddress("TriggerVersion", &TriggerVersion, &b_TriggerVersion);
   fChain->SetBranchAddress("TrueNumInteractions", &TrueNumInteractions, &b_TrueNumInteractions);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("ZCandidates", &ZCandidates, &b_ZCandidates);
   Notify();
}

Bool_t NtupleVariables::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef temp_cxx
