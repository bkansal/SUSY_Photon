#!/bin/sh

hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root 
hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
hadd -f TTWGJ_2016_CR_v18.root TTJets_2016_CR_v18.root TTWGJets_2016_CR_v18.root WJets_2016_CR_v18.root
hadd -f TTWDY_2016_CR_v18.root TTWGJ_2016_CR_v18.root DYJets_2016_CR_v18.root

hadd -f TTWGJets_2017_CR_v18.root TTGJets_2017_CR_v18.root WGJets_2017_CR_v18.root 
hadd -f TTJets_2017_CR_v18.root TTJetsHT_2017_CR_v18.root TTJetsinc_2017_CR_v18.root
hadd -f TTWGJ_2017_CR_v18.root TTJets_2017_CR_v18.root TTWGJets_2017_CR_v18.root WJets_2017_CR_v18.root
hadd -f TTWDY_2017_CR_v18.root TTWGJ_2017_CR_v18.root DYJets_2017_CR_v18.root

hadd -f TTWGJets_2018_CR_v18.root TTGJets_2018_CR_v18.root WGJets_2018_CR_v18.root 
hadd -f TTJets_2018_CR_v18.root TTJetsHT_2018_CR_v18.root TTJetsinc_2018_CR_v18.root
hadd -f TTWGJ_2018_CR_v18.root TTJets_2018_CR_v18.root TTWGJets_2018_CR_v18.root WJets_2018_CR_v18.root
hadd -f TTWDY_2018_CR_v18.root TTWGJ_2018_CR_v18.root DYJets_2018_CR_v18.root

hadd -f TTWGJ_CR_v18.root TTWGJ_201*_CR_v18.root
hadd -f TTJets_CR_v18.root TTJets_201*_CR_v18.root
hadd -f TTGJets_CR_v18.root TTGJets_201*_CR_v18.root
hadd -f WJets_CR_v18.root WJets_201*_CR_v18.root
hadd -f WGJets_CR_v18.root WGJets_201*_CR_v18.root


hadd -f Run2_CR_v18.root Run201*_CR_v18.root 



