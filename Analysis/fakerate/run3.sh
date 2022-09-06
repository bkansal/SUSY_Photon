#!/bin/sh

rm *CR.root
rm *CR_v18.root

./fakerate Run2016_METdata.txt Run2016_METdata_CR_v18.root data_2016
./fakerate Run2017_METdata.txt Run2017_METdata_CR_v18.root data_2017
./fakerate Run2018_METdata.txt Run2018_METdata_CR_v18.root data_2018
hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root


./fakerate runlist_TTG_2016_CR_v18.txt TTGJets_2016_CR_v18.root TTG_v17_2016
./fakerate runlist_WG_2016_CR_v18.txt WGJets_2016_CR_v18.root WG_v17_2016
hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root 
./fakerate runlist_TTJets-inc_2016_CR_v18.txt TTJetsinc_2016_CR_v18.root TTJets2_v17_2016
./fakerate runlist_TTJets-HT_2016_CR_v18.txt TTJetsHT_2016_CR_v18.root TTJets_v17_2016
./fakerate runlist_ST_2016_CR_v18.txt ST_2016_CR_v18.root ST_v17_2016
./fakerate runlist_WJets_2016_CR_v18.txt WJets_2016_CR_v18.root WJets_v17_2016
hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
hadd -f TTWGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTWGJets_2016_CR_v18.root WJets_2016_CR_v18.root ST_2016_CR_v18.root

./fakerate runlist_TTG_2017_CR_v18.txt TTGJets_2017_CR_v18.root TTG_v17_2017
./fakerate runlist_WG_2017_CR_v18.txt WGJets_2017_CR_v18.root WG_v17_2017
hadd -f TTWGJets_2017_CR_v18.root TTGJets_2017_CR_v18.root WGJets_2017_CR_v18.root
./fakerate runlist_TTJets-inc_2017_CR_v18.txt TTJetsinc_2017_CR_v18.root TTJets2_v17_2017
./fakerate runlist_TTJets-HT_2017_CR_v18.txt TTJetsHT_2017_CR_v18.root TTJets_v17_2017
./fakerate runlist_ST_2017_CR_v18.txt ST_2017_CR_v18.root ST_v17_2017
./fakerate runlist_WJets_2017_CR_v18.txt WJets_2017_CR_v18.root WJets_v17_2017
hadd -f TTJets_2017_CR_v18.root TTJetsHT_2017_CR_v18.root TTJetsinc_2017_CR_v18.root
hadd -f TTWGJ_2017_CR_v18.root TTJets_2017_CR_v18.root TTWGJets_2017_CR_v18.root WJets_2017_CR_v18.root ST_2017_CR_v18.root




./fakerate runlist_TTG_2018_CR_v18.txt TTGJets_2018_CR_v18.root TTG_v17_2018
./fakerate runlist_WG_2018_CR_v18.txt WGJets_2018_CR_v18.root WG_v17_2018
hadd -f TTWGJets_2018_CR_v18.root TTGJets_2018_CR_v18.root WGJets_2018_CR_v18.root
./fakerate runlist_TTJets-inc_2018_CR_v18.txt TTJetsinc_2018_CR_v18.root TTJets2_v17_2018
./fakerate runlist_TTJets-HT_2018_CR_v18.txt TTJetsHT_2018_CR_v18.root TTJets_v17_2018
./fakerate runlist_WJets_2018_CR_v18.txt WJets_2018_CR_v18.root WJets_v17_2018
./fakerate runlist_ST_2018_CR_v18.txt ST_2018_CR_v18.root ST_v17_2018
hadd -f TTJets_2018_CR_v18.root TTJetsHT_2018_CR_v18.root TTJetsinc_2018_CR_v18.root
hadd -f TTWGJ_2018_CR_v18.root TTJets_2018_CR_v18.root TTWGJets_2018_CR_v18.root WJets_2018_CR_v18.root ST_2018_CR_v18.root

hadd -f TTJets_CR_v18.root TTJets_201*_CR_v18.root
hadd -f WJets_CR_v18.root WJets_201*_CR_v18.root
hadd -f ST_CR_v18.root ST_201*_CR_v18.root
hadd -f TTGJets_CR_v18.root TTGJets_201*_CR_v18.root
hadd -f WGJets_CR_v18.root WGJets_201*_CR_v18.root
hadd -f TTWGJ_CR_v18.root TTWGJ_201*_CR_v18.root
#hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root


