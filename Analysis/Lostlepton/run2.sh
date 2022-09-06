#!/bin/bash

#path=LM/LM_eSFup
<<EOF

subdir=nominal_bsf                                                                                                                                                          
for i in LM LE
do
    path=$i/${subdir}/
    ./lostlepton_${i} Run2016_METdata_CR_v18.txt Run2016_METdata_CR_v18.root data_2016
    ./lostlepton_${i} Run2017_METdata_CR_v18.txt Run2017_METdata_CR_v18.root data_2017
    ./lostlepton_${i} Run2018_METdata_CR_v18.txt Run2018_METdata_CR_v18.root data_2018
    hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root                                                                                                                                                 
    cp *_v18.root ${path}/.
done
cd LL/${subdir}
hadd -f Run2016_METdata_CR_v18.root  ../../LE/${subdir}/Run2016_METdata_CR_v18.root ../../LM/${subdir}/Run2016_METdata_CR_v18.root
hadd -f Run2017_METdata_CR_v18.root ../../LE/${subdir}/Run2017_METdata_CR_v18.root ../../LM/${subdir}/Run2017_METdata_CR_v18.root
hadd -f Run2018_METdata_CR_v18.root ../../LE/${subdir}/Run2018_METdata_CR_v18.root ../../LM/${subdir}/Run2018_METdata_CR_v18.root
hadd -f Run2_METdata_CR_v18.root ../../LE/${subdir}/Run2_METdata_CR_v18.root    ../../LM/${subdir}/Run2_METdata_CR_v18.root

EOF
subdir=acc_id
for i in LE LM
do
    path=$i/${subdir}/
    mkdir ${path}
    rm TTWGJets_*_CR_v18.root
    rm TTJets_*_CR_v18.root
    rm TTWGJ_*_CR_v18.root
    rm *_CR_v18.root
    rm *_CR.root
    

    ./lostlepton_${i} runList_TTGJets_2016_CR_v18.txt TTGJets_2016_CR_v18.root TTG_v17_2016
    ./lostlepton_${i} runList_WGJets_2016_CR_v18.txt WGJets_2016_CR_v18.root WG_v17_2016
    hadd -f TTWGJets_2016_CR_v18.root TTGJets_2016_CR_v18.root WGJets_2016_CR_v18.root
    ./lostlepton_${i} runList_TTJets-inc_2016_CR_v18.txt TTJetsinc_2016_CR_v18.root TTJets2_v17_2016
    ./lostlepton_${i} runList_TTJets-HT_2016_CR_v18.txt TTJetsHT_2016_CR_v18.root TTJets_v17_2016
    ./lostlepton_${i} runList_WJets_2016_CR_v18.txt WJets_2016_CR_v18.root WJets_v17_2016
    ./lostlepton_${i} runList_ST_2016_CR_v18.txt ST_2016_CR_v18.root ST_v17_2016
    hadd -f TTJets_2016_CR_v18.root TTJetsHT_2016_CR_v18.root TTJetsinc_2016_CR_v18.root
    hadd -f TTWGJ_2016_CR_v18.root TTGJets_2016_CR_v18.root  WGJets_2016_CR_v18.root TTJets_2016_CR_v18.root WJets_2016_CR_v18.root ST_2016_CR_v18.root
    ./lostlepton_${i} Run2016_METdata_CR_v18.txt Run2016_METdata_CR_v18.root data_2016
    

    ./lostlepton_${i} runList_TTGJets_2017_CR_v18.txt TTGJets_2017_CR_v18.root TTG_v17_2017
    ./lostlepton_${i} runList_WGJets_2017_CR_v18.txt WGJets_2017_CR_v18.root WG_v17_2017
    hadd -f TTWGJets_2017_CR_v18.root TTGJets_2017_CR_v18.root WGJets_2017_CR_v18.root
    ./lostlepton_${i} runList_TTJets-inc_2017_CR_v18.txt TTJetsinc_2017_CR_v18.root TTJets2_v17_2017
    ./lostlepton_${i} runList_TTJets-HT_2017_CR_v18.txt TTJetsHT_2017_CR_v18.root TTJets_v17_2017
    ./lostlepton_${i} runList_WJets_2017_CR_v18.txt WJets_2017_CR_v18.root WJets_v17_2017
    ./lostlepton_${i} runList_ST_2017_CR_v18.txt ST_2017_CR_v18.root ST_v17_2017
    hadd -f TTJets_2017_CR_v18.root TTJetsHT_2017_CR_v18.root TTJetsinc_2017_CR_v18.root
    hadd -f TTWGJ_2017_CR_v18.root TTGJets_2017_CR_v18.root  WGJets_2017_CR_v18.root TTJets_2017_CR_v18.root WJets_2017_CR_v18.root ST_2017_CR_v18.root
    ./lostlepton_${i} Run2017_METdata_CR_v18.txt Run2017_METdata_CR_v18.root data_2017

    ./lostlepton_${i} runList_TTGJets_2018_CR_v18.txt TTGJets_2018_CR_v18.root TTG_v17_2018
    ./lostlepton_${i} runList_WGJets_2018_CR_v18.txt WGJets_2018_CR_v18.root WG_v17_2018
    hadd -f TTWGJets_2018_CR_v18.root TTGJets_2018_CR_v18.root WGJets_2018_CR_v18.root
    ./lostlepton_${i} runList_TTJets-inc_2018_CR_v18.txt TTJetsinc_2018_CR_v18.root TTJets2_v17_2018
    ./lostlepton_${i} runList_TTJets-HT_2018_CR_v18.txt TTJetsHT_2018_CR_v18.root TTJets_v17_2018
    ./lostlepton_${i} runList_WJets_2018_CR_v18.txt WJets_2018_CR_v18.root WJets_v17_2018
    ./lostlepton_${i} runList_ST_2018_CR_v18.txt ST_2018_CR_v18.root ST_v17_2018
    hadd -f TTJets_2018_CR_v18.root TTJetsHT_2018_CR_v18.root TTJetsinc_2018_CR_v18.root
    hadd -f TTWGJ_2018_CR_v18.root TTGJets_2018_CR_v18.root  WGJets_2018_CR_v18.root TTJets_2018_CR_v18.root WJets_2018_CR_v18.root ST_2018_CR_v18.root
    ./lostlepton_${i} Run2018_METdata_CR_v18.txt Run2018_METdata_CR_v18.root data_2018



    hadd -f TTJets_CR_v18.root TTJets_201*_CR_v18.root
    hadd -f TTGJets_CR_v18.root TTGJets_201*_CR_v18.root
    hadd -f WGJets_CR_v18.root WGJets_201*_CR_v18.root
    hadd -f WJets_CR_v18.root WJets_201*_CR_v18.root
    hadd -f ST_CR_v18.root ST_201*_CR_v18.root

    hadd -f TTWGJets_CR_v18.root TTWGJets_201*_CR_v18.root
    hadd -f TTWGJ_CR_v18.root TTWGJ_201*_CR_v18.root
    hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root


    cp *_v18.root ${path}/.

done



mkdir LL/${subdir}
cd LL/${subdir}

hadd -f Run2016_METdata_CR_v18.root  ../../LE/${subdir}/Run2016_METdata_CR_v18.root ../../LM/${subdir}/Run2016_METdata_CR_v18.root
hadd -f Run2017_METdata_CR_v18.root ../../LE/${subdir}/Run2017_METdata_CR_v18.root ../../LM/${subdir}/Run2017_METdata_CR_v18.root
hadd -f Run2018_METdata_CR_v18.root ../../LE/${subdir}/Run2018_METdata_CR_v18.root ../../LM/${subdir}/Run2018_METdata_CR_v18.root
hadd -f Run2_METdata_CR_v18.root ../../LE/${subdir}/Run2_METdata_CR_v18.root    ../../LM/${subdir}/Run2_METdata_CR_v18.root   
hadd -f TTGJets_2016_CR_v18.root ../../LE/${subdir}/TTGJets_2016_CR_v18.root    ../../LM/${subdir}/TTGJets_2016_CR_v18.root   
hadd -f TTGJets_2017_CR_v18.root ../../LE/${subdir}/TTGJets_2017_CR_v18.root    ../../LM/${subdir}/TTGJets_2017_CR_v18.root   
hadd -f TTGJets_2018_CR_v18.root ../../LE/${subdir}/TTGJets_2018_CR_v18.root    ../../LM/${subdir}/TTGJets_2018_CR_v18.root   
hadd -f TTGJets_CR_v18.root ../../LE/${subdir}/TTGJets_CR_v18.root    ../../LM/${subdir}/TTGJets_CR_v18.root          
hadd -f TTJets_2016_CR_v18.root ../../LE/${subdir}/TTJets_2016_CR_v18.root     ../../LM/${subdir}/TTJets_2016_CR_v18.root    
hadd -f TTJets_2017_CR_v18.root ../../LE/${subdir}/TTJets_2017_CR_v18.root     ../../LM/${subdir}/TTJets_2017_CR_v18.root    
hadd -f TTJets_2018_CR_v18.root ../../LE/${subdir}/TTJets_2018_CR_v18.root     ../../LM/${subdir}/TTJets_2018_CR_v18.root    
hadd -f TTJets_CR_v18.root ../../LE/${subdir}/TTJets_CR_v18.root    ../../LM/${subdir}/TTJets_CR_v18.root          
hadd -f TTWGJ_2016_CR_v18.root ../../LE/${subdir}/TTWGJ_2016_CR_v18.root      ../../LM/${subdir}/TTWGJ_2016_CR_v18.root     
hadd -f TTWGJ_2017_CR_v18.root ../../LE/${subdir}/TTWGJ_2017_CR_v18.root      ../../LM/${subdir}/TTWGJ_2017_CR_v18.root     
hadd -f TTWGJ_2018_CR_v18.root ../../LE/${subdir}/TTWGJ_2018_CR_v18.root      ../../LM/${subdir}/TTWGJ_2018_CR_v18.root     
hadd -f TTWGJ_CR_v18.root ../../LE/${subdir}/TTWGJ_CR_v18.root    ../../LM/${subdir}/TTWGJ_CR_v18.root          
hadd -f TTWGJets_2016_CR_v18.root ../../LE/${subdir}/TTWGJets_2016_CR_v18.root   ../../LM/${subdir}/TTWGJets_2016_CR_v18.root  
hadd -f TTWGJets_2017_CR_v18.root ../../LE/${subdir}/TTWGJets_2017_CR_v18.root   ../../LM/${subdir}/TTWGJets_2017_CR_v18.root  
hadd -f TTWGJets_2018_CR_v18.root ../../LE/${subdir}/TTWGJets_2018_CR_v18.root   ../../LM/${subdir}/TTWGJets_2018_CR_v18.root  
hadd -f TTWGJets_CR_v18.root ../../LE/${subdir}/TTWGJets_CR_v18.root        ../../LM/${subdir}/TTWGJets_CR_v18.root       
hadd -f WGJets_2016_CR_v18.root ../../LE/${subdir}/WGJets_2016_CR_v18.root     ../../LM/${subdir}/WGJets_2016_CR_v18.root    
hadd -f WGJets_2017_CR_v18.root ../../LE/${subdir}/WGJets_2017_CR_v18.root     ../../LM/${subdir}/WGJets_2017_CR_v18.root    
hadd -f WGJets_2018_CR_v18.root ../../LE/${subdir}/WGJets_2018_CR_v18.root     ../../LM/${subdir}/WGJets_2018_CR_v18.root    
hadd -f WGJets_CR_v18.root ../../LE/${subdir}/WGJets_CR_v18.root    ../../LM/${subdir}/WGJets_CR_v18.root          
hadd -f WJets_2016_CR_v18.root ../../LE/${subdir}/WJets_2016_CR_v18.root      ../../LM/${subdir}/WJets_2016_CR_v18.root     
hadd -f WJets_2017_CR_v18.root ../../LE/${subdir}/WJets_2017_CR_v18.root      ../../LM/${subdir}/WJets_2017_CR_v18.root     
hadd -f WJets_2018_CR_v18.root ../../LE/${subdir}/WJets_2018_CR_v18.root      ../../LM/${subdir}/WJets_2018_CR_v18.root     
hadd -f WJets_CR_v18.root            ../../LE/${subdir}/WJets_CR_v18.root           ../../LM/${subdir}/WJets_CR_v18.root          
hadd -f ST_2016_CR_v18.root ../../LE/${subdir}/ST_2016_CR_v18.root      ../../LM/${subdir}/ST_2016_CR_v18.root     
hadd -f ST_2017_CR_v18.root ../../LE/${subdir}/ST_2017_CR_v18.root      ../../LM/${subdir}/ST_2017_CR_v18.root     
hadd -f ST_2018_CR_v18.root ../../LE/${subdir}/ST_2018_CR_v18.root      ../../LM/${subdir}/ST_2018_CR_v18.root     
hadd -f ST_CR_v18.root            ../../LE/${subdir}/ST_CR_v18.root           ../../LM/${subdir}/ST_CR_v18.root          
