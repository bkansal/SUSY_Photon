#!/bin/bash
rm *_v18.root
subdir=closure
for i in LE LM
do
    path=$i/${subdir}/
    mkdir ${path}
    rm TTWGJets_*_CR_v18.root
    rm TTJets_*_CR_v18.root
    rm TTWGJ_*_CR_v18.root
    rm *_CR_v18.root
    rm *_CR.root

    for year in 2016 2017 2018
    do
	./lostlepton_${i} runList_TTGJets_${year}_CR_v18.txt TTGJets_${year}_CR_v18.root TTG_v17_${year}
	./lostlepton_${i} runList_WGJets_${year}_CR_v18.txt WGJets_${year}_CR_v18.root WG_v17_${year}
	hadd -f TTWGJets_${year}_CR_v18.root TTGJets_${year}_CR_v18.root WGJets_${year}_CR_v18.root
	./lostlepton_${i} runList_TTJets-inc_${year}_CR_v18.txt TTJetsinc_${year}_CR_v18.root TTJets2_v17_${year}
	./lostlepton_${i} runList_TTJets-HT_${year}_CR_v18.txt TTJetsHT_${year}_CR_v18.root TTJets_v17_${year}
	./lostlepton_${i} runList_WJets_${year}_CR_v18.txt WJets_${year}_CR_v18.root WJets_v17_${year}
	./lostlepton_${i} runList_ST_${year}_CR_v18.txt ST_${year}_CR_v18.root ST_v17_${year}
	hadd -f TTJets_${year}_CR_v18.root TTJetsHT_${year}_CR_v18.root TTJetsinc_${year}_CR_v18.root
	hadd -f TTWGJ_${year}_CR_v18.root TTGJets_${year}_CR_v18.root  WGJets_${year}_CR_v18.root TTJets_${year}_CR_v18.root WJets_${year}_CR_v18.root ST_${year}_CR_v18.root
    done
    cp *_CR_v18.root ${path}/.
done


mkdir LL/${subdir}
cd LL/${subdir}

for i in TTGJets WGJets TTWGJets TTJets WJets ST TTWGJ
do
    for year in 2016 2017 2018
    do
	hadd -f ${i}_${year}_CR_v18.root ../../LE/${subdir}/${i}_${year}_CR_v18.root ../../LM/${subdir}/${i}_${year}_CR_v18.root
    done
    hadd -f ${i}_CR_v18.root ${i}_201*_CR_v18.root 
done
