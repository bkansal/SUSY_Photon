#!/bin/sh                                                                                                                                                                   

rm *CR.root
rm *CR_v18.root


#./fakerate runlist_TTG_2016_CR_v18.txt TTGJets_2016_CR_v18.root TTG_v17_2016
#./fakerate runlist_WG_2016_CR_v18.txt WGJets_2016_CR_v18.root WG_v17_2016
#hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root
#./fakerate runlist_TTJets-inc_2016_CR_v18.txt TTJetsinc_2016_CR_v18.root TTJets2_v17_2016
#./fakerate runlist_TTJets-HT_2016_CR_v18.txt TTJetsHT_2016_CR_v18.root TTJets_v17_2016
#./fakerate runlist_WJets_2016_CR_v18.txt WJets_2016_CR_v18.root WJets_v17_2016
#./fakerate runlist_DYJets_2016_CR_v18.txt DYJets_2016_CR_v18.root DYJets_v17_2016
#hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
#hadd -f TTWGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTWGJets_2016_CR_v18.root WJets_2016_CR_v18.root
#hadd -f TTWDY_2016_CR_v18.root TTWGJ_2016_CR_v18.root DYJets_2016_CR_v18.root
#./fakerate  Run2016_CR_v18.txt Run2016_CR_v18.root data_v18_2016



#./fakerate runlist_DYJets_2016_CR_v18.txt DYJets_2016_CR_v18.root DYJets_v17_2016
#./fakerate  Run2016_CR_v18.txt Run2016_CR_v18.root data_v18_2016

./fakerate runlist_DYJets_2017_CR_v18.txt DYJets_2017_CR_v18.root DYJets_v17_2017
./fakerate  Run2017_CR_v18.txt Run2017_CR_v18.root data_v18_2017

./fakerate runlist_DYJets_2018_CR_v18.txt DYJets_2018_CR_v18.root DYJets_v17_2018
./fakerate  Run2018_CR_v18.txt Run2018_CR_v18.root data_v18_2018
