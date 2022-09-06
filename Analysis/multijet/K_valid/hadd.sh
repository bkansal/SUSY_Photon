#!/bin/bash


hadd -f Run2_METdata.root Run201*_METdata.root
hadd -f ZGZJ_NuNuG_2016_v18.root ZJetsToNuNu_2016_v18.root ZGJetsToNuNuG_2016_v18.root
hadd -f ZGZJ_NuNuG_2017_v18.root ZJetsToNuNu_2017_v18.root ZGJetsToNuNuG_2017_v18.root
hadd -f ZGZJ_NuNuG_2018_v18.root ZJetsToNuNu_2018_v18.root ZGJetsToNuNuG_2018_v18.root
hadd -f ZGZJ_NuNuG_v18.root ZJetsToNuNu_201*_v18.root ZGJetsToNuNuG_201*_v18.root
hadd -f ZJetsToNuNu_v18.root ZJetsToNuNu_201*_v18.root

hadd -f QCD_v18.root QCD_201*_v18.root
hadd -f GJets_v18.root GJets_201*_v18.root
hadd -f GJetsQCD_2016_v18.root QCD_2016_v18.root GJets_2016_v18.root
hadd -f GJetsQCD_2017_v18.root QCD_2017_v18.root GJets_2017_v18.root
hadd -f GJetsQCD_2018_v18.root QCD_2018_v18.root GJets_2018_v18.root
hadd -f GJetsQCD_new_v18.root GJetsQCD_201*_v18.root 

hadd -f WJetsToLNu_v18.root WJetsToLNu_*_v18.root
hadd -f WGJetsToLNuG_v18.root WGJetsToLNuG_*_v18.root
hadd -f TTJetsHT_2016_v18.root TTJetsHT1_2016_v18.root TTJetsHT2_2016_v18.root
hadd -f TTJetsHT_2017_v18.root TTJetsHT1_2017_v18.root TTJetsHT2_2017_v18.root
hadd -f TTJetsHT_2018_v18.root TTJetsHT1_2018_v18.root TTJetsHT2_2018_v18.root
hadd -f TTJetsHT_v18.root TTJetsHT_201*_v18.root
hadd -f ST_CR_v18.root ST_201*_CR_v18.root
hadd -f TTGJets_v18.root TTGJets_201*_v18.root
hadd -f Run2016_MC.root TTGJets_2016_v18.root TTJetsHT1_2016_v18.root TTJetsHT2_2017_v18.root WGJetsToLNuG_2016_v18.root WJetsToLNu_2016_v18.root GJetsQCD_2016_v18.root ZGZJ_NuNuG_2016_v18.root
hadd -f Run2017_MC.root TTGJets_2017_v18.root TTJetsHT1_2017_v18.root TTJetsHT2_2017_v18.root WGJetsToLNuG_2017_v18.root WJetsToLNu_2017_v18.root GJetsQCD_2017_v18.root ZGZJ_NuNuG_2017_v18.root
hadd -f Run2018_MC.root TTGJets_2018_v18.root TTJetsHT1_2018_v18.root TTJetsHT2_2018_v18.root WGJetsToLNuG_2018_v18.root WJetsToLNu_2018_v18.root GJetsQCD_2018_v18.root ZGZJ_NuNuG_2018_v18.root
hadd -f Run2_MC.root TTGJets_v18.root TTJetsHT_v18.root WGJetsToLNuG_v18.root WJetsToLNu_v18.root GJetsQCD_new_v18.root ZGZJ_NuNuG_v18.root ST_CR_v18.root
hadd -f Run2_MC_v2.root TTJetsHT_v18.root ST_CR_v18.root WJetsToLNu_v18.root QCD_v18.root ZJetsToNuNu_201*_v18.root
hadd -f EWK_2016.root TTGJets_2016_v18.root TTJetsHT_2016_v18.root WJetsToLNu_2016_v18.root WGJetsToLNuG_2016_v18.root ZGZJ_NuNuG_2016_v18.root 
hadd -f EWK_2017.root TTGJets_2017_v18.root TTJetsHT_2017_v18.root WJetsToLNu_2017_v18.root WGJetsToLNuG_2017_v18.root ZGZJ_NuNuG_2017_v18.root
hadd -f EWK_2018.root TTGJets_2018_v18.root TTJetsHT_2018_v18.root WJetsToLNu_2018_v18.root WGJetsToLNuG_2018_v18.root ZGZJ_NuNuG_2018_v18.root
hadd -f EWK.root TTGJets_v18.root TTJetsHT_v18.root WJetsToLNu_v18.root WGJetsToLNuG_v18.root ZGZJ_NuNuG_v18.root

hadd -f EWK_2016_v2.root  TTJetsHT_2016_v18.root WJetsToLNu_2016_v18.root ZJetsToNuNu_2016_v18.root
hadd -f EWK_2017_v2.root  TTJetsHT_2017_v18.root WJetsToLNu_2017_v18.root ZJetsToNuNu_2017_v18.root
hadd -f EWK_2018_v2.root TTJetsHT_2018_v18.root WJetsToLNu_2018_v18.root ZJetsToNuNu_2018_v18.root
hadd -f EWK_v2.root TTJetsHT_v18.root WJetsToLNu_v18.root ZJetsToNuNu_201*_v18.root
