#!/bin/sh                                                                                                                                                                  

<<EOF 
./lostlepton_LE Run2016_METdata_CR_v18.txt Run2016_METdata_CR_v18.root data_2016
./lostlepton_LE Run2017_METdata_CR_v18.txt Run2017_METdata_CR_v18.root data_2017
./lostlepton_LE Run2018_METdata_CR_v18.txt Run2018_METdata_CR_v18.root data_2018
hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root
cp Run2*_METdata_CR_v18.root /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/lostlepton/LE/withJECup//.
./lostlepton_LM Run2016_METdata_CR_v18.txt Run2016_METdata_CR_v18.root data_2016                                                                                          
./lostlepton_LM Run2017_METdata_CR_v18.txt Run2017_METdata_CR_v18.root data_2017                                                                                          
./lostlepton_LM Run2018_METdata_CR_v18.txt Run2018_METdata_CR_v18.root data_2018                                                                                          
hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root                                                                                                              
cp Run2*_METdata_CR_v18.root /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/lostlepton/LM/withJECup//.                     
EOF
#####-=]=========== hadd =============
lep=LE
for lep in LM
do
    ./cleaUpBatchFiles.sh
    currdir=${pwd}

    path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/lostlepton/${lep}/withJECup/
    ./lostlepton_${lep} Run2016_METdata_CR_v18.txt Run2016_METdata_CR_v18.root data_2016
    ./lostlepton_${lep} Run2017_METdata_CR_v18.txt Run2017_METdata_CR_v18.root data_2017
    ./lostlepton_${lep} Run2018_METdata_CR_v18.txt Run2018_METdata_CR_v18.root data_2018
    hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root
    cp Run2*_METdata_CR_v18.root ${path}/.
<<EOF
done
EOF

    cd ${path}
    
    hadd -f ST_2016_CR_v18.root Summer16v3.ST_*.root 
    hadd -f TTJets_2016_CR_v18.root Summer16v3.TTJets_*.root 
    hadd -f WJets_2016_CR_v18.root Summer16v3.WJets*.root
    hadd -f TTGJets_2016_CR_v18.root Summer16v3.TTGJets*.root
    hadd -f WGJets_2016_CR_v18.root Summer16v3.WGJets*.root
    hadd -f TTWGJets_2016_CR_v18.root Summer16v3.TTGJets_*.root Summer16v3.WGJets_*.root
    hadd -f TTWGJ_2016_CR_v18.root TTWGJets_2016_CR_v18.root TTJets_2016_CR_v18.root WJets_2016_CR_v18.root ST_2016_CR_v18.root
    
    hadd -f ST_2017_CR_v18.root Fall17.ST_*.root 
    hadd -f TTJets_2017_CR_v18.root Fall17.TTJets_*.root
    hadd -f WJets_2017_CR_v18.root Fall17.WJets*.root
    hadd -f TTGJets_2017_CR_v18.root Fall17.TTGJets*.root
    hadd -f WGJets_2017_CR_v18.root Fall17.WGJets*.root
    hadd -f TTWGJets_2017_CR_v18.root Fall17.TTGJets_*.root Fall17.WGJets_*.root
    hadd -f TTWGJ_2017_CR_v18.root TTWGJets_2017_CR_v18.root TTJets_2017_CR_v18.root WJets_2017_CR_v18.root ST_2017_CR_v18.root
    
    hadd -f ST_2018_CR_v18.root Autumn18.ST_*.root
    hadd -f TTJets_2018_CR_v18.root Autumn18.TTJets_*.root
    hadd -f WJets_2018_CR_v18.root Autumn18.WJets*.root
    hadd -f TTGJets_2018_CR_v18.root Autumn18.TTGJets*.root
    hadd -f WGJets_2018_CR_v18.root Autumn18.WGJets*.root
    hadd -f TTWGJets_2018_CR_v18.root Autumn18.TTGJets_*.root Autumn18.WGJets_*.root
    hadd -f TTWGJ_2018_CR_v18.root TTWGJets_2018_CR_v18.root TTJets_2018_CR_v18.root WJets_2018_CR_v18.root ST_2018_CR_v18.root

    hadd -f TTJets_CR_v18.root TTJets_201*_CR_v18.root
    hadd -f TTGJets_CR_v18.root TTGJets_201*_CR_v18.root
    hadd -f WGJets_CR_v18.root WGJets_201*_CR_v18.root
    hadd -f WJets_CR_v18.root WJets_201*_CR_v18.root
    hadd -f ST_CR_v18.root ST_201*_CR_v18.root

    hadd -f TTWGJets_CR_v18.root TTWGJets_201*_CR_v18.root
    hadd -f TTWGJ_CR_v18.root TTWGJ_201*_CR_v18.root


    rm -rf Summer16v3.*.root
    rm -rf Fall17.*.root
    rm -rf Autumn18.*.root

    cd ${currdir}

done



