#!/bin/sh                                                                                                                         

ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Summer16v3.WGJets_MonoPhoton_PtG-* > runlist_WG_2016_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Summer16v3.WJets* > runlist_WJets_2016_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Summer16v3.TTGJets* > runlist_TTG_2016_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Summer16v3.TTJets_HT* > runlist_TTJets-HT_2016_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Summer16v3.TTJets_*Lept* > runlist_TTJets-inc_2016_CR_v18.txt



ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Fall17.WGJets_MonoPhoton_PtG-* > runlist_WG_2017_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Fall17.WJets* > runlist_WJets_2017_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Fall17.TTGJets* > runlist_TTG_2017_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Fall17.TTJets_HT* > runlist_TTJets-HT_2017_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Fall17.TTJets_*Lept* > runlist_TTJets-inc_2017_CR_v18.txt



ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Autumn18.WGJets_MonoPhoton_PtG-* > runlist_WG_2018_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Autumn18.WJets* > runlist_WJets_2018_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Autumn18.TTGJets* > runlist_TTG_2018_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Autumn18.TTJets_HT* > runlist_TTJets-HT_2018_CR_v18.txt
ls /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/fake_rate/CR_Autumn18.TTJets_*Lept* > runlist_TTJets-inc_2018_CR_v18.txt


sed -i "s#/eos/uscms/store/#root://cmseos.fnal.gov//store/#" *.txt
