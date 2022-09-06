#!/bin/sh

rm *CR.root
rm *CR_v18.root
./fakerate runlist_TTG_2016_CR_v18.txt TTGJets_2016_CR_v18.root TTG_v17_2016
./fakerate runlist_WG_2016_CR_v18.txt WGJets_2016_CR_v18.root WG_v17_2016
hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root 
./fakerate runlist_TTJets-inc_2016_CR_v18.txt TTJetsinc_2016_CR_v18.root TTJets2_v17_2016
./fakerate runlist_TTJets-HT_2016_CR_v18.txt TTJetsHT_2016_CR_v18.root TTJets_v17_2016
./fakerate runlist_WJets_2016_CR_v18.txt WJets_2016_CR_v18.root WJets_v17_2016
hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
hadd -f TTWGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTWGJets_2016_CR_v18.root WJets_2016_CR_v18.root
hadd -f TTGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTGJets_2016_CR_v18.root
hadd -f WGJ_2016_CR_v18.root WJets_2016_CR_v18.root WGJets_2016_CR_v18.root
./fakerate runlist_ZGJets_2016_CR_v18.txt ZGJets_2016_CR_v18.root ZGToLLG_v17_2016
./fakerate runlist_DYJets_2016_CR_v18.txt DYJets_2016_CR_v18.root DYJets_v17_2016
hadd -f ZGJ_2016_CR_v18.root ZGJets_2016_CR_v18.root DYJets_2016_CR_v18.root                                               
hadd -f TTWDY_2016_CR_v18.root TTWGJ_2016_CR_v18.root DYJets_2016_CR_v18.root
hadd -f TTWDYG_2016_CR_v18.root TTWGJ_2016_CR_v18.root ZGJ_2016_CR_v18.root
./fakerate  Run2016_CR_v18.txt Run2016_CR_v18.root data_v18_2016


./fakerate runlist_TTG_2017_CR_v18.txt TTGJets_2017_CR_v18.root TTG_v17_2017
./fakerate runlist_WG_2017_CR_v18.txt WGJets_2017_CR_v18.root WG_v17_2017
hadd -f TTWGJets_2017_CR_v18.root TTGJets_2017_CR_v18.root WGJets_2017_CR_v18.root
./fakerate runlist_TTJets-inc_2017_CR_v18.txt TTJetsinc_2017_CR_v18.root TTJets2_v17_2017
./fakerate runlist_TTJets-HT_2017_CR_v18.txt TTJetsHT_2017_CR_v18.root TTJets_v17_2017
./fakerate runlist_WJets_2017_CR_v18.txt WJets_2017_CR_v18.root WJets_v17_2017
./fakerate runlist_DYJets_2017_CR_v18.txt DYJets_2017_CR_v18.root DYJets_v17_2017
hadd -f TTJets_2017_CR_v18.root TTJetsHT_2017_CR_v18.root TTJetsinc_2017_CR_v18.root
hadd -f TTWGJ_2017_CR_v18.root TTJets_2017_CR_v18.root TTWGJets_2017_CR_v18.root WJets_2017_CR_v18.root
./fakerate runlist_ZGJets_2017_CR_v18.txt ZGJets_2017_CR_v18.root ZGToLLG_v17_2017
hadd -f TTWDY_2017_CR_v18.root TTWGJ_2017_CR_v18.root DYJets_2017_CR_v18.root
./fakerate  Run2017_CR_v18.txt Run2017_CR_v18.root data_v18_2017
hadd -f TTGJ_2017_CR_v18.root TTJets_2017_CR_v18.root TTGJets_2017_CR_v18.root
hadd -f WGJ_2017_CR_v18.root WJets_2017_CR_v18.root WGJets_2017_CR_v18.root
hadd -f ZGJ_2017_CR_v18.root ZGJets_2017_CR_v18.root DYJets_2017_CR_v18.root
hadd -f TTWDYG_2017_CR_v18.root TTWGJ_2017_CR_v18.root ZGJ_2017_CR_v18.root


./fakerate runlist_TTG_2018_CR_v18.txt TTGJets_2018_CR_v18.root TTG_v17_2018
./fakerate runlist_WG_2018_CR_v18.txt WGJets_2018_CR_v18.root WG_v17_2018
hadd -f TTWGJets_2018_CR_v18.root TTGJets_2018_CR_v18.root WGJets_2018_CR_v18.root
./fakerate runlist_TTJets-inc_2018_CR_v18.txt TTJetsinc_2018_CR_v18.root TTJets2_v17_2018
./fakerate runlist_TTJets-HT_2018_CR_v18.txt TTJetsHT_2018_CR_v18.root TTJets_v17_2018
./fakerate runlist_WJets_2018_CR_v18.txt WJets_2018_CR_v18.root WJets_v17_2018
./fakerate runlist_ZGJets_2018_CR_v18.txt ZGJets_2018_CR_v18.root ZGToLLG_v17_2018
./fakerate runlist_DYJets_2018_CR_v18.txt DYJets_2018_CR_v18.root DYJets_v17_2018
hadd -f TTJets_2018_CR_v18.root TTJetsHT_2018_CR_v18.root TTJetsinc_2018_CR_v18.root
hadd -f TTWGJ_2018_CR_v18.root TTJets_2018_CR_v18.root TTWGJets_2018_CR_v18.root WJets_2018_CR_v18.root
hadd -f TTWDY_2018_CR_v18.root TTWGJ_2018_CR_v18.root DYJets_2018_CR_v18.root
./fakerate  Run2018_CR_v18.txt Run2018_CR_v18.root data_v18_2018
hadd -f TTGJ_2018_CR_v18.root TTJets_2018_CR_v18.root TTGJets_2018_CR_v18.root
hadd -f WGJ_2018_CR_v18.root WJets_2018_CR_v18.root WGJets_2018_CR_v18.root
hadd -f ZGJ_2018_CR_v18.root ZGJets_2018_CR_v18.root DYJets_2018_CR_v18.root
hadd -f TTWDYG_2018_CR_v18.root TTWGJ_2018_CR_v18.root ZGJ_2018_CR_v18.root


#fakerate runlist_TTG_2018_CR_v18.txt TTGJets_2018_CR_v18.root TTG_v17_2018
#fakerate runlist_WG_2018_CR_v18.txt WGJets_2018_CR_v18.root WG_v17_2018
#hadd -f TTWGJets_2018_CR_v18.root TTGJets_2018_CR_v18.root WGJets_2018_CR_v18.root
#fakerate runlist_TTJets-inc_2018_CR_v18.txt TTJetsinc_2018_CR_v18.root TTJets2_v17_2018
#fakerate runlist_TTJets-HT_2018_CR_v18.txt TTJetsHT_2018_CR_v18.root TTJets_v17_2018
#fakerate runlist_WJets_2018_CR_v18.txt WJets_2018_CR_v18.root WJets_v17_2018
#fakerate runlist_DYJets_2018_CR_v18.txt DYJets_2018_CR_v18.root DYJets_v17_2018
#hadd -f TTJets_2018_CR_v18.root TTJetsHT_2018_CR_v18.root TTJetsinc_2018_CR_v18.root
#hadd -f TTWGJ_2018_CR_v18.root TTJets_2018_CR_v18.root TTWGJets_2018_CR_v18.root WJets_2018_CR_v18.root
#hadd -f TTWDY_2018_CR_v18.root TTWGJ_2018_CR_v18.root DYJets_2018_CR_v18.root
#fakerate  Run2018_CR_v18.txt Run2018_CR_v18.root data_v18_2018

