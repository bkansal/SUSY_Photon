#!/bin/bash

rm rootoutput/*.root
#Run2016_MET_data.txt
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T5qqqqHg_2100_200_2016_v17.txt rootoutput/T5qqqqHg_2100_200_FastSim_2016_v17.root FastSim_T5qqqqHg_2016             
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T5qqqqHg_2100_2000_2016_v17.txt rootoutput/T5qqqqHg_2000_2100_FastSim_2016_v17.root FastSim_T5qqqqHg_2016            

#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T5ttttZg_2200_200_2016_v17.txt rootoutput/T5ttttZg_2200_200_FastSim_2016_v17.root FastSim_T5ttttZg_2016
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T5ttttZg_2200_2100_2016_v17.txt rootoutput/T5ttttZg_2200_2100_FastSim_2016_v17.root FastSim_T5ttttZg_2016

#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T6ttZg_1300_200_2016_v17.txt rootoutput/T6ttZg_1300_200_FastSim_2016_v17.root FastSim_T6ttZg_2016
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_T6ttZg_1300_1200_2016_v17.txt rootoutput/T6ttZg_1300_1200_FastSim_2016_v17.root FastSim_T6ttZg_2016

#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_TChiNg_0_900_v17.txt rootoutput/TChiNg_0_900_FastSim_v17.root FastSim_TChiNG_2016
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_TChiNg_0_1000_v17.txt rootoutput/TChiNg_0_1000_FastSim_v17.root FastSim_TChiNG_2016                                 
#./analyzeLightBSM unskimmed_SR_v17/runList_unskimmed_TChiNg_0_1200_v17.txt rootoutput/TChiNg_0_1200_FastSim_v17.root FastSim_TChiNG_2016                                  
<<EOF
gluinoMass=2250
sample=T5qqqqHg
for nlspMass in 1000 
do 
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Summer16v3_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" > runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Fall17_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Autumn18_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2016_v18.root FastSim_${sample}_2016
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2017_v18.root FastSim_${sample}_2017
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2018_v18.root FastSim_${sample}_2018
    hadd -f rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_v18.root rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_201*_v18.root 
done

gluinoMass=1300
sample=T6ttZg
for nlspMass in 200 600 1200 
do
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Summer16v3_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" > runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Fall17_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Autumn18_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2016_v18.root FastSim_${sample}_2016
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2017_v18.root FastSim_${sample}_2017
    ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2018_v18.root FastSim_${sample}_2018
    hadd -f rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_v18.root rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_201*_v18.root
done


<<EOF
gluinoMass=2250
for sample in T5bbbbZg T5qqqqHg
do
    for nlspMass in 200 1600 2100 2150
    do
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Summer16v3_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" > runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Fall17_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Autumn18_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2016_v18.root FastSim_${sample}_2016
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2017_v18.root FastSim_${sample}_2017
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2018_v18.root FastSim_${sample}_2018
        hadd -f rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_v18.root rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_201*_v18.root
    done
done


gluinoMass=0
for sample in TChiWG TChiNG
do
    for nlspMass in 500 600 1000 1200 
    do
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Summer16v3_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" > runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Fall17_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt
        echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/${sample}/Autumn18_${sample}_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2016_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2016_v18.root FastSim_${sample}_2016
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2017_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2017_v18.root FastSim_${sample}_2017
        ./analyzeLightBSM runList_unskimmed_${sample}_${gluinoMass}_${nlspMass}_2018_v18.txt rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_2018_v18.root FastSim_${sample}_2018
	hadd -f rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_v18.root rootoutput/${sample}_${gluinoMass}_${nlspMass}_FastSim_201*_v18.root
    done
done




gluinoMass=0
for nlspMass in 800 1000 1200
do
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiWG/Summer16v3_TChiWG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiWg_${gluinoMass}_${nlspMass}_2016_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiWG/Fall17_TChiWG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiWg_${gluinoMass}_${nlspMass}_2017_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiWG/Autumn18_TChiWG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiWg_${gluinoMass}_${nlspMass}_2018_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiNG/Summer16v3_TChiNG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiNg_${gluinoMass}_${nlspMass}_2016_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiNG/Fall17_TChiNG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiNg_${gluinoMass}_${nlspMass}_2017_v18.txt
    echo "root://cmseos.fnal.gov//store/group/lpcsusyhad/SusyPhotonMET/Run2ProductionV18/signals/unskimmed_SortedSignalscans/scan/TChiNG/Autumn18_TChiNG_${gluinoMass}_${nlspMass}_unSkimmed.root" >runList_unskimmed_TChiNg_${gluinoMass}_${nlspMass}_2018_v18.txt

done
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2016_v18.txt rootoutput/TChiNg_0_1000_2016_FastSim_v18.root FastSim_TChiNG_2016
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2017_v18.txt rootoutput/TChiNg_0_1000_2017_FastSim_v18.root FastSim_TChiNG_2017
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2018_v18.txt rootoutput/TChiNg_0_1000_2018_FastSim_v18.root FastSim_TChiNG_2018
hadd -f rootoutput/TChiNg_0_1000_FastSim_v18.root rootoutput/TChiNg_0_1000_201*_FastSim_v18.root
EOF
./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_2100_2016_v18.txt rootoutput/T5bbbbZg_2200_2100_FastSim_2016_v18.root FastSim_T5bbbbZg_2016
./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_200_2016_v18.txt rootoutput/T5bbbbZg_2200_200_FastSim_2016_v18.root FastSim_T5bbbbZg_2016
./analyzeLightBSM runList_unskimmed_TChiWg_0_800_2016_v18.txt rootoutput/TChiWg_0_800_2016_FastSim_v18.root FastSim_TChiWG_2016                          
./analyzeLightBSM runList_unskimmed_TChiWg_0_1000_2016_v18.txt rootoutput/TChiWg_0_1000_2016_FastSim_v18.root FastSim_TChiWG_2016
./analyzeLightBSM runList_unskimmed_TChiWg_0_1200_2016_v18.txt rootoutput/TChiWg_0_1200_2016_FastSim_v18.root FastSim_TChiWG_2016                        
./analyzeLightBSM runList_unskimmed_TChiNg_0_800_2016_v18.txt rootoutput/TChiNg_0_800_2016_FastSim_v18.root FastSim_TChiNG_2016
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2016_v18.txt rootoutput/TChiNg_0_1000_2016_FastSim_v18.root FastSim_TChiNG_2016
./analyzeLightBSM runList_unskimmed_TChiNg_0_1200_2016_v18.txt rootoutput/TChiNg_0_1200_2016_FastSim_v18.root FastSim_TChiNG_2016
         

./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_2100_2017_v18.txt rootoutput/T5bbbbZg_2200_2100_FastSim_2017_v18.root FastSim_T5bbbbZg_2017
./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_200_2017_v18.txt rootoutput/T5bbbbZg_2200_200_FastSim_2017_v18.root FastSim_T5bbbbZg_2017
./analyzeLightBSM runList_unskimmed_TChiWg_0_800_2017_v18.txt rootoutput/TChiWg_0_800_2017_FastSim_v18.root FastSim_TChiWG_2017
./analyzeLightBSM runList_unskimmed_TChiWg_0_1000_2017_v18.txt rootoutput/TChiWg_0_1000_2017_FastSim_v18.root FastSim_TChiWG_2017
./analyzeLightBSM runList_unskimmed_TChiWg_0_1200_2017_v18.txt rootoutput/TChiWg_0_1200_2017_FastSim_v18.root FastSim_TChiWG_2017
./analyzeLightBSM runList_unskimmed_TChiNg_0_800_2017_v18.txt rootoutput/TChiNg_0_800_2017_FastSim_v18.root FastSim_TChiNG_2017
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2017_v18.txt rootoutput/TChiNg_0_1000_2017_FastSim_v18.root FastSim_TChiNG_2017
./analyzeLightBSM runList_unskimmed_TChiNg_0_1200_2017_v18.txt rootoutput/TChiNg_0_1200_2017_FastSim_v18.root FastSim_TChiNG_2017


./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_2100_2018_v18.txt rootoutput/T5bbbbZg_2200_2100_FastSim_2018_v18.root FastSim_T5bbbbZg_2018
./analyzeLightBSM runList_unskimmed_T5bbbbZg_2200_200_2018_v18.txt rootoutput/T5bbbbZg_2200_200_FastSim_2018_v18.root FastSim_T5bbbbZg_2018
./analyzeLightBSM runList_unskimmed_TChiWg_0_800_2018_v18.txt rootoutput/TChiWg_0_800_2018_FastSim_v18.root FastSim_TChiWG_2018
./analyzeLightBSM runList_unskimmed_TChiWg_0_1000_2018_v18.txt rootoutput/TChiWg_0_1000_2018_FastSim_v18.root FastSim_TChiWG_2018
./analyzeLightBSM runList_unskimmed_TChiWg_0_1200_2018_v18.txt rootoutput/TChiWg_0_1200_2018_FastSim_v18.root FastSim_TChiWG_2018
./analyzeLightBSM runList_unskimmed_TChiNg_0_800_2018_v18.txt rootoutput/TChiNg_0_800_2018_FastSim_v18.root FastSim_TChiNG_2018
./analyzeLightBSM runList_unskimmed_TChiNg_0_1000_2018_v18.txt rootoutput/TChiNg_0_1000_2018_FastSim_v18.root FastSim_TChiNG_2018
./analyzeLightBSM runList_unskimmed_TChiNg_0_1200_2018_v18.txt rootoutput/TChiNg_0_1200_2018_FastSim_v18.root FastSim_TChiNG_2018

hadd -f rootoutput/T5bbbbZg_2200_2100_FastSim_v18.root rootoutput/T5bbbbZg_2200_2100_FastSim_201*_v18.root
hadd -f rootoutput/T5bbbbZg_2200_200_FastSim_v18.root rootoutput/T5bbbbZg_2200_200_FastSim_201*_v18.root
hadd -f rootoutput/TChiWg_0_800_FastSim_v18.root rootoutput/TChiWg_0_800_201*_FastSim_v18.root
hadd -f rootoutput/TChiWg_0_1000_FastSim_v18.root rootoutput/TChiWg_0_1000_201*_FastSim_v18.root
hadd -f rootoutput/TChiWg_0_1200_FastSim_v18.root rootoutput/TChiWg_0_1200_201*_FastSim_v18.root
hadd -f rootoutput/TChiNg_0_800_FastSim_v18.root rootoutput/TChiNg_0_800_201*_FastSim_v18.root
hadd -f rootoutput/TChiNg_0_1000_FastSim_v18.root rootoutput/TChiNg_0_1000_201*_FastSim_v18.root
hadd -f rootoutput/TChiNg_0_1200_FastSim_v18.root rootoutput/TChiNg_0_1200_201*_FastSim_v18.root



./analyzeLightBSM Run2016_MET_data.txt rootoutput/Run2016_METdata.root data_2016
./analyzeLightBSM Run2017_MET_data.txt rootoutput/Run2017_METdata.root data_2017
./analyzeLightBSM Run2018_MET_data.txt rootoutput/Run2018_METdata.root data_2018
hadd -f rootoutput/Run2_METdata.root rootoutput/Run201*_METdata.root

#./analyzeLightBSM runlist_ZGTo2NuG_nlo_2016_v18.txt rootoutput/ZGJetsToNuNuG_2016_v18.root ZG_v17_2016

./analyzeLightBSM runlist_ZJetsToNuNu_2016_v18.txt rootoutput/ZJetsToNuNu_2016_v18.root ZJets_v17_2016
./analyzeLightBSM runlist_ZJetsToNuNu_2017_v18.txt rootoutput/ZJetsToNuNu_2017_v18.root ZJets_v17_2017
./analyzeLightBSM runlist_ZJetsToNuNu_2018_v18.txt rootoutput/ZJetsToNuNu_2018_v18.root ZJets_v17_2018

./analyzeLightBSM runlist_ZGTo2NuG_nlo_2016_v18.txt rootoutput/ZGJetsToNuNuG_2016_v18.root ZG_v17_2016
./analyzeLightBSM runlist_ZGTo2NuG_nlo_2017_v18.txt rootoutput/ZGJetsToNuNuG_2017_v18.root ZG_v17_2017
./analyzeLightBSM runlist_ZGTo2NuG_nlo_2018_v18.txt rootoutput/ZGJetsToNuNuG_2018_v18.root ZG_v17_2018

hadd -f rootoutput/ZGZJ_NuNuG_2016_v18.root rootoutput/ZJetsToNuNu_2016_v18.root rootoutput/ZGJetsToNuNuG_2016_v18.root
hadd -f rootoutput/ZGZJ_NuNuG_2017_v18.root rootoutput/ZJetsToNuNu_2017_v18.root rootoutput/ZGJetsToNuNuG_2017_v18.root
hadd -f rootoutput/ZGZJ_NuNuG_2018_v18.root rootoutput/ZJetsToNuNu_2018_v18.root rootoutput/ZGJetsToNuNuG_2018_v18.root
hadd -f rootoutput/ZGZJ_NuNuG_v18.root rootoutput/ZJetsToNuNu_201*_v18.root rootoutput/ZGJetsToNuNuG_201*_v18.root

#runlist_ZGToNuNuG_2016_v18
./analyzeLightBSM runlist_QCD_2016_v18.txt rootoutput/QCD_2016_v18.root QCD_v17_2016
./analyzeLightBSM runlist_QCD_2017_v18.txt rootoutput/QCD_2017_v18.root QCD_v17_2017
./analyzeLightBSM runlist_QCD_2018_v18.txt rootoutput/QCD_2018_v18.root QCD_v17_2018

./analyzeLightBSM runlist_GJets_DR_2016_v18.txt rootoutput/GJets_2016_v18.root GJetsDR_v17_2016
./analyzeLightBSM runlist_GJets_DR_2017_v18.txt rootoutput/GJets_2017_v18.root GJetsDR_v17_2017
./analyzeLightBSM runlist_GJets_DR_2018_v18.txt rootoutput/GJets_2018_v18.root GJetsDR_v17_2018
hadd -f rootoutput/GJetsQCD_2016_v18.root rootoutput/QCD_2016_v18.root rootoutput/GJets_2016_v18.root
hadd -f rootoutput/GJetsQCD_2017_v18.root rootoutput/QCD_2017_v18.root rootoutput/GJets_2017_v18.root
hadd -f rootoutput/GJetsQCD_2018_v18.root rootoutput/QCD_2018_v18.root rootoutput/GJets_2018_v18.root
hadd -f rootoutput/GJetsQCD_new_v18.root rootoutput/GJetsQCD_201*_v18.root 

./analyzeLightBSM runlist_WJets_2016_v18.txt rootoutput/WJetsToLNu_2016_v18.root WJets_v17_2016
./analyzeLightBSM runlist_WJets_2017_v18.txt rootoutput/WJetsToLNu_2017_v18.root WJets_v17_2017
./analyzeLightBSM runlist_WJets_2018_v18.txt rootoutput/WJetsToLNu_2018_v18.root WJets_v17_2018
hadd -f rootoutput/WJetsToLNu_v18.root rootoutput/WJetsToLNu_*_v18.root

./analyzeLightBSM runlist_WG_2016_v18.txt rootoutput/WGJetsToLNuG_2016_v18.root WG_v17_2016
./analyzeLightBSM runlist_WG_2017_v18.txt rootoutput/WGJetsToLNuG_2017_v18.root WG_v17_2017
./analyzeLightBSM runlist_WG_2018_v18.txt rootoutput/WGJetsToLNuG_2018_v18.root WG_v17_2018
hadd -f rootoutput/WGJetsToLNuG_v18.root rootoutput/WGJetsToLNuG_*_v18.root
hadd -f rootoutput/WGJ_v18.root rootoutput/WGJetsToLNuG_v18.root rootoutput/WJetsToLNu_v18.root
hadd -f rootoutput/WGJ_2016_v18.root rootoutput/WGJetsToLNuG_2016_v18.root rootoutput/WJetsToLNu_2016_v18.root
hadd -f rootoutput/WGJ_2017_v18.root rootoutput/WGJetsToLNuG_2017_v18.root rootoutput/WJetsToLNu_2017_v18.root
hadd -f rootoutput/WGJ_2018_v18.root rootoutput/WGJetsToLNuG_2018_v18.root rootoutput/WJetsToLNu_2018_v18.root

./analyzeLightBSM runlist_TTJets_HT_2016_v18.txt rootoutput/TTJetsHT1_2016_v18.root TTJets_v17_2016
./analyzeLightBSM runlist_TTJets_HT_2017_v18.txt rootoutput/TTJetsHT1_2017_v18.root TTJets_v17_2017
./analyzeLightBSM runlist_TTJets_HT_2018_v18.txt rootoutput/TTJetsHT1_2018_v18.root TTJets_v17_2018
./analyzeLightBSM runlist_TTJets_inc_2016_v18.txt rootoutput/TTJetsHT2_2016_v18.root TTJets2_v17_2016
./analyzeLightBSM runlist_TTJets_inc_2017_v18.txt rootoutput/TTJetsHT2_2017_v18.root TTJets2_v17_2017
./analyzeLightBSM runlist_TTJets_inc_2018_v18.txt rootoutput/TTJetsHT2_2018_v18.root TTJets2_v17_2018
hadd -f rootoutput/TTJetsHT_2016_v18.root rootoutput/TTJetsHT1_2016_v18.root rootoutput/TTJetsHT2_2016_v18.root
hadd -f rootoutput/TTJetsHT_2017_v18.root rootoutput/TTJetsHT1_2017_v18.root rootoutput/TTJetsHT2_2017_v18.root
hadd -f rootoutput/TTJetsHT_2018_v18.root rootoutput/TTJetsHT1_2018_v18.root rootoutput/TTJetsHT2_2018_v18.root
hadd -f rootoutput/TTJetsHT_v18.root rootoutput/TTJetsHT_201*_v18.root
./analyzeLightBSM runlist_ST_2016_CR_v18.txt rootoutput/ST_2016_CR_v18.root ST_v17_2016
./analyzeLightBSM runlist_ST_2017_CR_v18.txt rootoutput/ST_2017_CR_v18.root ST_v17_2017
./analyzeLightBSM runlist_ST_2018_CR_v18.txt rootoutput/ST_2018_CR_v18.root ST_v17_2018

./analyzeLightBSM runlist_TTG_2016_v18.txt rootoutput/TTGJets_2016_v18.root  TTG_v17_2016
./analyzeLightBSM runlist_TTG_2017_v18.txt rootoutput/TTGJets_2017_v18.root  TTG_v17_2017
./analyzeLightBSM runlist_TTG_2018_v18.txt rootoutput/TTGJets_2018_v18.root  TTG_v17_2018
hadd -f rootoutput/TTGJets_v18.root rootoutput/TTGJets_*_v18.root
hadd -f rootoutput/TTGJ_v18.root rootoutput/TTGJets_v18.root rootoutput/TTJetsHT_v18.root rootoutput/ST_*_CR_v18.root
hadd -f rootoutput/TTGJ_2016_v18.root rootoutput/TTGJets_2016_v18.root rootoutput/TTJetsHT_2016_v18.root rootoutput/ST_2016_CR_v18.root
hadd -f rootoutput/TTGJ_2017_v18.root rootoutput/TTGJets_2017_v18.root rootoutput/TTJetsHT_2017_v18.root rootoutput/ST_2017_CR_v18.root
hadd -f rootoutput/TTGJ_2018_v18.root rootoutput/TTGJets_2018_v18.root rootoutput/TTJetsHT_2018_v18.root rootoutput/ST_2018_CR_v18.root


hadd -f rootoutput/Run2016_MC.root rootoutput/TTGJets_2016_v18.root rootoutput/TTJetsHT1_2016_v18.root rootoutput/TTJetsHT2_2017_v18.root rootoutput/WGJetsToLNuG_2016_v18.root rootoutput/WJetsToLNu_2016_v18.root rootoutput/GJetsQCD_2016_v18.root rootoutput/ZGZJ_NuNuG_2016_v18.root
hadd -f rootoutput/Run2017_MC.root rootoutput/TTGJets_2017_v18.root rootoutput/TTJetsHT1_2017_v18.root rootoutput/TTJetsHT2_2017_v18.root rootoutput/WGJetsToLNuG_2017_v18.root rootoutput/WJetsToLNu_2017_v18.root rootoutput/GJetsQCD_2017_v18.root rootoutput/ZGZJ_NuNuG_2017_v18.root
hadd -f rootoutput/Run2018_MC.root rootoutput/TTGJets_2018_v18.root rootoutput/TTJetsHT1_2018_v18.root rootoutput/TTJetsHT2_2018_v18.root rootoutput/WGJetsToLNuG_2018_v18.root rootoutput/WJetsToLNu_2018_v18.root rootoutput/GJetsQCD_2018_v18.root rootoutput/ZGZJ_NuNuG_2018_v18.root
hadd -f rootoutput/Run2_MC.root rootoutput/TTGJ_v18.root rootoutput/WGJetsToLNuG_v18.root rootoutput/WJetsToLNu_v18.root rootoutput/GJetsQCD_new_v18.root rootoutput/ZGZJ_NuNuG_v18.root


