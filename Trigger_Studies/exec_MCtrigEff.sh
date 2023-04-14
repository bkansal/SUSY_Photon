#!/bin/bash
rm *_v18.root
subdir=MC_trgeff

for i in single_elec #LM_muo LM_hadtau
do
    path=rootoutput/${subdir}/
    rm -rf ${path}
    mkdir ${path}
    rm TTWGJets_*_CR_v18.root
    rm TTJets_*_CR_v18.root
    rm TTWGJ_*_CR_v18.root
    rm *_CR_v18.root
    rm *_CR.root

    for year in 2016 2017 2018
    do

	./${i} runList_TTGJets_${year}_CR_v18.txt TTGJets_${year}_CR_v18.root TTG_v17_${year}
	./${i} runList_TTJets-inc_${year}_CR_v18.txt TTJetsinc_${year}_CR_v18.root TTJets2_v17_${year}
	./${i} runList_TTJets-HT_${year}_CR_v18.txt TTJetsHT_${year}_CR_v18.root TTJets_v17_${year}


        ./${i} runList_WGJets_${year}_CR_v18.txt WGJets_${year}_CR_v18.root WG_v17_${year}
	./${i} runList_WJets_${year}_CR_v18.txt WJets_${year}_CR_v18.root WJets_v17_${year}

	./${i} runList_ST_${year}_CR_v18.txt ST_${year}_CR_v18.root ST_v17_${year}

        ./${i} runlist_ZJetsToNuNu_${year}_v18.txt ZJets_${year}_CR_v18.root ZJets_v17_${year}
        ./${i} runlist_ZGTo2NuG_nlo_${year}_v18.txt ZGJets_${year}_CR_v18.root ZG_v17_${year}


	./${i} runList_QCD_${year}_CR_v18.txt QCD_${year}_CR_v18.root QCD_v17_${year}
	./${i} runList_GJets_${year}_CR_v18.txt GJets_${year}_CR_v18.root GJets_v17_${year}

	hadd -f TTGJ_${year}_CR_v18.root TTJetsHT_${year}_CR_v18.root TTJetsinc_${year}_CR_v18.root TTGJets_${year}_CR_v18.root
        hadd -f WGJ_${year}_CR_v18.root WGJets_${year}_CR_v18.root WJets_${year}_CR_v18.root
	hadd -f ZGJ_${year}_CR_v18.root ZJets_${year}_CR_v18.root ZGJets_${year}_CR_v18.root
	hadd -f QCDGJets_${year}_CR_v18.root QCD_${year}_CR_v18.root GJets_${year}_CR_v18.root

        hadd -f MET_${year}_CR_v18.root TTGJ_${year}_CR_v18.root WGJ_${year}_CR_v18.root ZGJ_${year}_CR_v18.root
	hadd -f MC_${year}_CR_v18.root TTGJ_${year}_CR_v18.root WGJ_${year}_CR_v18.root ZGJ_${year}_CR_v18.root QCDGJets_${year}_CR_v18.root 
    done

    mv *_CR_v18.root ${path}/.
done
