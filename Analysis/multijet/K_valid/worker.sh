#!/bin/sh
#analyzeLightBSM 800 127 FastSim T5qqqqHg
executable=$1
infile=$2
outname=$3
datasetname=$4
hist=$5
currDir=$(pwd)

######################################
# SETUP CMSSW STUFF...
######################################


echo "======== ${PWD} ==============="
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
cmsrel CMSSW_10_2_13
cd CMSSW_10_2_13/src
cmsenv
eval `scramv1 runtime -sh`
echo $CMSSW_RELEASE_BASE
cd $currDir
echo $currDir

rm -rf btag
mkdir btag
tar -xvf btag.tar btag/
make clean
make
#./$executable runFileList.txt ${outname} ${datasetname}
./$executable ${infile} ${outname} ${datasetname}

#rm runFileList.txt
# mv runFileList.txt tmp/runFileList.txt

#eos root://cmseos.fnal.gov mkdir /store/user/bkansal/myProduction/Analysis/rootoutput/${hist}

xrdcp -f ${outname} root://cmseos.fnal.gov//store/user/bkansal/myProduction/Analysis/rootoutput/${hist}/
xrdcp -f hadd.sh root://cmseos.fnal.gov//store/user/bkansal/myProduction/Analysis/rootoutput/${hist}/

rm ${outName}


#rm *.txt
cd ${currDir}

