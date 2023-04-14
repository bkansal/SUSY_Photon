#!/bin/sh

executable=$1
inputFileTag=$2
outputFileTag=$3
#commitHash=$4
datasetName=$4
currDir=$(pwd)
######################################
# SETUP CMSSW STUFF...
######################################
echo "======== ${PWD} ==============="

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
scram p CMSSW CMSSW_10_2_21
cd CMSSW_10_2_21/src
# cmsenv                                                                                                                          
eval `scramv1 runtime -sh`
echo $CMSSW_RELEASE_BASE
cd $currDir
echo $currDir

######################################
# SETUP PRIVATE STUFF...
######################################
echo "ls"
pwd
#cd -
#cd $currDir
echo "RUNNING ANALYSIS"
pwd
./$executable $inputFileTag $outputFileTag $datasetName
echo "processed. ls"
ls
echo "COPYING OUTPUT"

#xrdcp -f $outputFileTag root://cmseos.fnal.gov//store/user/bkansal/GMSB_skims_TreesV18/trigger_studies/lowdphi/Kvalid/
#xrdcp -f $outputFileTag root://cmseos.fnal.gov//store/user/bkansal/GMSB_skims_TreesV18/trigger_studies/lowdphi/using_elec/
#xrdcp -f $outputFileTag root://cmseos.fnal.gov//store/user/bkansal/GMSB_skims_TreesV18/trigger_studies/highdphi/using_elec/
xrdcp -f $outputFileTag root://cmseos.fnal.gov//store/user/bkansal/GMSB_skims_TreesV18/trigger_studies/lowdphi_v2/using_elec/
#xrdcp -f $datasetName'_'$outputFileTag root://cmseos.fnal.gov//store/user/vhegde/GMSB_skims_ST_RA2b_TreesV12/TriggerStudies/
#rm $datasetName'_'$outputFileTag
