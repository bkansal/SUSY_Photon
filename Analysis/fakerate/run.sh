#!/bin/sh

rm *CR.root
rm *CR_v18.root
./fakerate runlist_TTG_2016_CR_v18.txt TTGJets_2016_CR_v18.root TTG_v17_2016
./fakerate runlist_WG_2016_CR_v18.txt WGJets_2016_CR_v18.root WG_v17_2016
hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root 
./fakerate runlist_TTJets-inc_2016_CR_v18.txt TTJetsinc_2016_CR_v18.root TTJets2_v17_2016
./fakerate runlist_TTJets-HT_2016_CR_v18.txt TTJetsHT_2016_CR_v18.root TTJets_v17_2016
./fakerate runlist_ST_2016_CR_v18.txt ST_2016_CR_v18.root ST_v17_2016
./fakerate runlist_WJets_2016_CR_v18.txt WJets_2016_CR_v18.root WJets_v17_2016
hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
hadd -f TTWGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTWGJets_2016_CR_v18.root WJets_2016_CR_v18.root ST_2016_CR_v18.root

