#!/bin/sh
#analyzeLightBSM 800 127 FastSim T5qqqqHg
executable=$1
infile=$2
outname=$3
datasetname=$4
hist=$5
file=$6
currDir=$(pwd)

######################################
# SETUP CMSSW STUFF...
######################################


echo "======== ${PWD} ==============="

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc630
scram p CMSSW CMSSW_10_2_21
cd CMSSW_10_2_21/src
# cmsenv
eval `scramv1 runtime -sh`
echo $CMSSW_RELEASE_BASE
cd $currDir
echo $currDir

#./$executable runFileList.txt ${outname} ${datasetname}
./$executable ${infile} ${outname} ${datasetname}

#rm runFileList.txt
# mv runFileList.txt tmp/runFileList.txt

#eos root://cmseos.fnal.gov mkdir /store/user/bkansal/myProduction/Analysis/rootoutput/${hist}

xrdcp -f ${outname} root://cmseos.fnal.gov//store/user/bkansal/myProduction/Analysis/bkg_estimation/SF/${hist}/${outname}
xrdcp -f ${file} root://cmseos.fnal.gov//store/user/bkansal/myProduction/Analysis/bkg_estimation/SF/${hist}/${file}
rm ${outName}
rm ${file}


rm *.txt
cd ${currDir}

