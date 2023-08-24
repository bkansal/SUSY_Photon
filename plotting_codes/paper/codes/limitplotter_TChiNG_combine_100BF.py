#!/usr/bin/env python
from ROOT import *
from array import *
gROOT.SetBatch(True)
import sys, os
from os.path import isfile, join
import math

# ------------------------------
def SetHistoStyle( histo ) :
    histo.SetLineColor(2)
    histo.SetMarkerColor(1)
    histo.GetXaxis().SetTitleFont(42);
    histo.GetYaxis().SetTitleFont(42);
    histo.GetXaxis().SetTitleSize(0.05);
    histo.GetYaxis().SetTitleSize(0.05);
    histo.GetXaxis().SetTitleFont(42)
    histo.GetYaxis().SetTitleFont(42)
    histo.GetXaxis().SetLabelFont(42)
    histo.GetYaxis().SetLabelFont(42)
    histo.GetXaxis().SetTitleSize(0.032)
    histo.GetYaxis().SetTitleSize(0.032)
    histo.GetXaxis().SetTitleOffset(1.3)
    histo.GetYaxis().SetTitleOffset(1.3)
    histo.GetXaxis().SetLabelOffset(0.011)
    histo.GetYaxis().SetLabelOffset(0.011)
    histo.GetXaxis().SetLabelSize(0.032)
    histo.GetYaxis().SetLabelSize(0.032)
    histo.SetMarkerStyle(9)
    histo.SetMarkerColor(1)
    histo.SetFillColor(2)
    histo.SetFillStyle(1001)
    histo.SetTitle("")
    histo.GetYaxis().SetTitle("Count")
#    histo.GetYaxis().CenterTitle()
#    histo.GetXaxis().CenterTitle()
# ------------------------------

#print "\npython limitPlotter.py <path-to-dir-with-Combine-root-files>  <limitname>\n"

# Extract input arguments
# ------------------------------

inputfoldername=sys.argv[1]
limitname=sys.argv[2]


# Extract file names in target dir
# ------------------------------
filelist = [f for f in os.listdir(inputfoldername) if isfile(join(inputfoldername, f)) if ".root" in f]
#print filelist


# Signal cross sections
# ------------------------------
# Full higgsino xsec
signalmasscrosssection = [ 
    (300    ,0.284855),
    (350    ,0.153841),
    (400    ,0.0887325),
    (450    ,0.0537702),   
    (500    ,0.0338387),
    (550    ,0.0219868),
    (600    ,0.0146677),
    (650    ,0.00996406),
    (700    ,0.00689981),
    (750    ,0.0048731),
    (800    ,0.00346143),
    (850    ,0.0024923),
    (900    ,0.00180616),
    (950    ,0.00132692),
    (1000   ,0.000968853),
    (1050   ,0.000731306),
    (1100   ,0.000538005),
    (1150   ,0.000405108),
    (1200   ,0.000299347),
    (1250   ,0.000240471),
    (1300   ,0.000160765),
    (1350   ,0.000111174),
    (1400   ,0.0000780263),
    (1450   ,0.0000696962)
]
theorycrosssection2 = [ 
(300,0.0509994),
(350,0.0273286),
(400,0.0156691),
(450,0.00944017),
(500,0.00590757),
(550,0.0038167),
(600,0.00253015),
(650,0.00171418),
(700,0.00118113),
(750,0.000826366),
(800,0.000586211),
(850,0.000420556),
(900,0.000305935),
(950,0.00022285),
(1000,0.00016428),
(1050,0.000121865),
(1100,9.12469e-05),
(1150,6.84561e-05),
(1200,5.16263e-05),
(1250,3.91587e-05),
(1300,2.99353e-05),
(1350,2.28072e-05),
(1400,1.75031e-05),
(1450,1.34572e-05)
]
theorycrosssectionunc2 = [
(300,0.00292105),
(350,0.00166094),
(400,0.00100609),
(450,0.000636781),
(500,0.000413476),
(550,0.000275884),
(600,0.000190847),
(650,0.000132968),
(700,9.40638e-05),
(750,6.7662e-05),
(800,5.05623e-05),
(850,3.60593e-05),
(900,2.79147e-05),
(950,2.04919e-05),
(1000,1.5677e-05),
(1050,1.17916e-05),
(1100,8.7975e-06),
(1150,7.09167e-06),
(1200,5.29162e-06),
(1250,4.10133e-06),
(1300,3.22793e-06),
(1350,2.49572e-06),
(1400,1.95389e-06),
(1450,1.4916e-06)
]

   
theorycrosssection = [ 
    (300    ,0.284855),
    (350    ,0.153841),
    (400    ,0.0887325),
    (450    ,0.0537702),
    (500    ,0.0338387),
    (550    ,0.0219868),
    (600    ,0.0146677),
    (650    ,0.00996406),
    (700    ,0.00689981),
    (750    ,0.0048731),
    (800    ,0.00346143),
    (850    ,0.0024923),
    (900    ,0.00180616),
    (950    ,0.00132692),
    (1000   ,0.000968853),
    (1050   ,0.000731306),
    (1100   ,0.000538005),
    (1150   ,0.000405108),
    (1200   ,0.000299347),
    (1250   ,0.000240471),
    (1300   ,0.000160765),
    (1350   ,0.000111174),
    (1400   ,0.0000780263),
    (1450   ,0.0000696962)
]
theorycrosssectionunc = [ 
    (300    ,  0.0167172),
    (350    ,  0.00985502),
    (400    ,  0.00618924),
    (450    ,  0.00402376), 
    (500    ,  0.0027158),
    (550    ,  0.00186729),
    (600    ,  0.00132111),
    (650    ,  0.000937269),
    (700    ,  0.000678178),
    (750    ,  0.000493209),
    (800    ,  0.000372511),
    (850    ,  0.000274194),
    (900    ,  0.000204818),
    (950    ,  0.000155285),
    (1000   ,  0.000122278),
    (1050   ,  0.0000866612),
    (1100   ,  0.0000721461),
    (1150   ,  0.0000488588),
    (1200   ,  0.0000486751),
    (1250   ,  0.0000286811),
    (1300   ,  0.0000196493),
    (1350   ,  0.0000197535),
    (1400   ,  0.00000926313),
    (1450   ,  0.0000138617)
]
theorycrosssection3 = [
(300,0.234202),
(350,0.126696),
(400,0.0731865),
(450,0.0444224),
(500,0.0279892),
(550,0.0182049),
(600,0.0121587),
(650,0.00826334),
(700,0.00572751),
(750,0.00405177),
(800,0.00287881),
(850,0.00207473),
(900,0.00150243),
(950,0.00110487),
(1000,0.000804953),
(1050,0.000609746),
(1100,0.000447184),
(1150,0.000336811),
(1200,0.00024783),
(1250,0.000201364),
(1300,0.00013096),
(1350,8.83857e-05),
(1400,6.03779e-05),
(1450,5.61146e-05)
]
theorycrosssectionunc3 = [ 
(300,0.0145142),
(350,0.00862132),
(400,0.00542976),
(450,0.00353506),
(500,0.00239047),
(550,0.00164638),
(600,0.00116532),
(650,0.000827719),
(700,0.000600042),
(750,0.000436591),
(800,0.000331891),
(850,0.000244575),
(900,0.000181724),
(950,0.000138294),
(1000,0.000109211),
(1050,7.69897e-05),
(1100,6.47999e-05),
(1150,4.31526e-05),
(1200,4.44897e-05),
(1250,2.54728e-05),
(1300,1.72061e-05),
(1350,1.81248e-05),
(1400,8.11659e-06),
(1450,1.307e-05)
]

theorymass = [ 
    (300 , 300),
    (350 , 350),
    (400 , 400),
    (450 , 450),
    (500 , 500),
    (550 , 550),
    (600 , 600),
    (650 , 650),
    (700 , 700),
    (750 , 750),
    (800 , 800),
    (850 , 850),
    (900 , 900),
    (950 , 950),
    (1000 , 1000),
    (1050 , 1050),
    (1100 , 1100),
    (1150 , 1150),
    (1200 , 1200),
    (1250 , 1250),
    (1300 , 1300),
    (1350 , 1350),
    (1400 , 1400),
    (1450 , 1450)
]

# Extract r-values from Combine output root files
# ------------------------------
m2sigmaexparray=[]
m1sigmaexparray=[]
meanexparray=[]
p1sigmaexparray=[]
p2sigmaexparray=[]
obsarray=[]
massarray=[]
masserrorarray=[]
#print
for filename in filelist:
    #print  filename
    infile=TFile(inputfoldername+"/"+filename,"READ")
#    infile.ls()
    #print
    tr=infile.Get("limit")
#    tr.Show(0)
    for ie,event in enumerate(tr):
        #print event.quantileExpected
        #print round(event.quantileExpected,2)
        if ie==0 and round(event.quantileExpected,2) == 0.03 : m2sigmaexparray.append((round(10000*event.mh,0),event.limit))
        if ie==1 and round(event.quantileExpected,2) == 0.16 : m1sigmaexparray.append((round(10000*event.mh,0),event.limit))
        if ie==2 and round(event.quantileExpected,2) == 0.5  : meanexparray.append((round(10000*event.mh,0),event.limit))
        if ie==3 and round(event.quantileExpected,2) == 0.84 : p1sigmaexparray.append((round(10000*event.mh,0),event.limit))
        if ie==4 and round(event.quantileExpected,2) == 0.98 : p2sigmaexparray.append((round(10000*event.mh,0),event.limit))
        if ie==5 and round(event.quantileExpected,2) == -1.0 : obsarray.append((round(10000*event.mh,0),event.limit))
        if ie==5 and round(event.quantileExpected,2) == -1.0 : masserrorarray.append(0.0)
#print
#print
print ("got limits into array")
#for ii in m2sigmaexparray:
#    print ii

# Create r-value limit arrays
# ------------------------------
signalcrosssectionsorted = [ x[1] for x in sorted(signalmasscrosssection, key=lambda tup: tup[0]) ]
theorycrosssectionsorted2 = [ x[1] for x in sorted(theorycrosssection2, key=lambda tup: tup[0]) ]
theorycrosssectionuncsorted2 = [ x[1] for x in sorted(theorycrosssectionunc2, key=lambda tup: tup[0]) ]
theorycrosssectionsorted3 = [ x[1] for x in sorted(theorycrosssection3, key=lambda tup: tup[0]) ]
theorycrosssectionuncsorted3 = [ x[1] for x in sorted(theorycrosssectionunc3, key=lambda tup: tup[0]) ]
theorycrosssectionsorted = [ x[1] for x in sorted(theorycrosssection, key=lambda tup: tup[0]) ]
theorycrosssectionuncsorted = [ x[1] for x in sorted(theorycrosssectionunc, key=lambda tup: tup[0]) ]
theorymasssorted      = [ x[1] for x in sorted(theorymass,      key=lambda tup: tup[0]) ]
obsarraysorted        = [ x[1] for x in sorted(obsarray,        key=lambda tup: tup[0]) ]
m2sigmaexparraysorted = [ x[1] for x in sorted(m2sigmaexparray, key=lambda tup: tup[0]) ]
m1sigmaexparraysorted = [ x[1] for x in sorted(m1sigmaexparray, key=lambda tup: tup[0]) ]
meanexparraysorted    = [ x[1] for x in sorted(meanexparray,    key=lambda tup: tup[0]) ]
massarraysorted       = [ x[0] for x in sorted(meanexparray,    key=lambda tup: tup[0]) ]
massarraysortedV2     = [ x[0] for x in sorted(signalmasscrosssection,    key=lambda tup: tup[0]) ]
p1sigmaexparraysorted = [ x[1] for x in sorted(p1sigmaexparray, key=lambda tup: tup[0]) ]
p2sigmaexparraysorted = [ x[1] for x in sorted(p2sigmaexparray, key=lambda tup: tup[0]) ]
#print "**Before signal cross-section normalization**"
#print "signalcrosssectionsorted : ",signalcrosssectionsorted
#print "          obsarraysorted : ",obsarraysorted
#print "   m2sigmaexparraysorted : ",m2sigmaexparraysorted
#print "   m1sigmaexparraysorted : ",m1sigmaexparraysorted
#print "      meanexparraysorted : ",meanexparraysorted
#print "   p1sigmaexparraysorted : ",p1sigmaexparraysorted
#print "   p2sigmaexparraysorted : ",p2sigmaexparraysorted
#print "         massarraysorted : ",massarraysorted
#print "Th. XSec massarraysorted : ",massarraysortedV2
#print


for imass in massarraysorted:
    if imass not in massarraysortedV2 : 
        print ("\nERROR: input limit mass ",str(imass)," is not included in the signal cross-section array!")
        print ("available signal masses: ",massarraysortedV2)
        print ("..exiting!\n")
        exit(1)


# Create cross-section normalized limit arrays
# ------------------------------
obsarraysorted        = [a*b for a,b in zip(signalcrosssectionsorted,obsarraysorted)]
m2sigmaexparraysorted = [a*b for a,b in zip(signalcrosssectionsorted,m2sigmaexparraysorted)]
m1sigmaexparraysorted = [a*b for a,b in zip(signalcrosssectionsorted,m1sigmaexparraysorted)]
meanexparraysorted    = [a*b for a,b in zip(signalcrosssectionsorted,meanexparraysorted)]
p1sigmaexparraysorted = [a*b for a,b in zip(signalcrosssectionsorted,p1sigmaexparraysorted)]
p2sigmaexparraysorted = [a*b for a,b in zip(signalcrosssectionsorted,p2sigmaexparraysorted)]
#print "**After signal cross-section normalization**"
#print "signalcrosssectionsorted : ",signalcrosssectionsorted
#print "          obsarraysorted : ",obsarraysorted
#print "   m2sigmaexparraysorted : ",m2sigmaexparraysorted
#print "   m1sigmaexparraysorted : ",m1sigmaexparraysorted
#print "      meanexparraysorted : ",meanexparraysorted
#print "   p1sigmaexparraysorted : ",p1sigmaexparraysorted
#print "   p2sigmaexparraysorted : ",p2sigmaexparraysorted
#print "         massarraysorted : ",massarraysorted
#print

# Create bands for +/- 1 and 2 sigma & theory xsec uncertainty
# ------------------------------
m2bandmeanexpsorted=[]
m1bandmeanexpsorted=[]
p1bandmeanexpsorted=[]
p2bandmeanexpsorted=[]
expLimit = 0
obsLimit = 0
for im,mass in enumerate(massarraysorted) :
    m2bandmeanexpsorted.append( meanexparraysorted[im]-m2sigmaexparraysorted[im])
    m1bandmeanexpsorted.append( meanexparraysorted[im]-m1sigmaexparraysorted[im])
    p1bandmeanexpsorted.append(-meanexparraysorted[im]+p1sigmaexparraysorted[im])
    p2bandmeanexpsorted.append(-meanexparraysorted[im]+p2sigmaexparraysorted[im])
    
    # Calculate limit (obs. & exp.) automatically
    # ------------------------------
    if im+1 < len(massarraysorted) :
        # log y = a*x+b --> because of using log scale !!!
#        print "    delta massarraysorted : ",massarraysorted[im]
#        print "    delta massarraysorted : ",massarraysorted[im]-massarraysorted[im+1]
        aExp = (TMath.Log(meanexparraysorted[im])-TMath.Log(meanexparraysorted[im+1]))/(massarraysorted[im]-massarraysorted[im+1])
        #aExp = (TMath.Log(meanexparraysorted[im])-TMath.Log(meanexparraysorted[im+1]))/50
#        aObs = (TMath.Log(obsarraysorted[im])-TMath.Log(obsarraysorted[im+1]))/50
        aObs = (TMath.Log(obsarraysorted[im])-TMath.Log(obsarraysorted[im+1]))/(massarraysorted[im]-massarraysorted[im+1])
        aTheo = (TMath.Log(signalcrosssectionsorted[im])-TMath.Log(signalcrosssectionsorted[im+1]))/(massarraysorted[im]-massarraysorted[im+1])
#        aTheo = (TMath.Log(signalcrosssectionsorted[im])-TMath.Log(signalcrosssectionsorted[im+1]))/50
        bExp = TMath.Log(meanexparraysorted[im])-aExp*massarraysorted[im]
        bObs = TMath.Log(obsarraysorted[im])-aObs*massarraysorted[im]
        bTheo = TMath.Log(signalcrosssectionsorted[im])-aTheo*massarraysorted[im]
        
        canTF=TCanvas("canTF","canTF",0,0,700,700); canTF.cd()
        lineExp = TF1("lineExp","TMath::Exp([0]*x+[1])-TMath::Exp([2]*x+[3])",massarraysorted[im],massarraysorted[im+1])
        lineExp.SetParameter(0,aExp)
        lineExp.SetParameter(1,bExp)
        lineExp.SetParameter(2,aTheo)
        lineExp.SetParameter(3,bTheo)
        lineExp.Draw()
        lineExp.SetNpx(int(massarraysorted[len(massarraysorted)-1]-massarraysorted[0]))
        if lineExp.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1]) <= massarraysorted[im+1] and lineExp.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1]) >= massarraysorted[im] : expLimit = lineExp.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1])
        
        lineObs = TF1("lineObs","TMath::Exp([0]*x+[1])-TMath::Exp([2]*x+[3])",massarraysorted[im],massarraysorted[im+1])
        lineObs.SetParameter(0,aObs)
        lineObs.SetParameter(1,bObs)
        lineObs.SetParameter(2,aTheo)
        lineObs.SetParameter(3,bTheo)
        lineObs.Draw()
        lineObs.SetNpx(int(massarraysorted[len(massarraysorted)-1]-massarraysorted[0]))
        if lineObs.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1]) <= massarraysorted[im+1] and lineObs.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1]) >= massarraysorted[im] : obsLimit = lineObs.GetX(0,massarraysorted[0],massarraysorted[len(massarraysorted)-1])
        canTF.Close()
        
print ("next: create canvas")        
    

# Create output canvas
# ------------------------------
can=TCanvas("can1","can1",0,0,700,700); can.cd()
gStyle.SetOptStat(0)
can.SetLeftMargin(0.15); can.SetRightMargin(0.10); can.SetTopMargin(0.07); can.SetBottomMargin(0.13)
can.SetTickx(1); can.SetTicky(1); can.SetLogy(0)


# Create limit curves
# ------------------------------
theorycurve             = TGraphErrors ( len(theorycrosssectionsorted), array('d',theorymasssorted), array('d',theorycrosssectionsorted) )
for im,mass in enumerate(theorymasssorted) :
    theorycurve.SetPointError(im,0,theorycrosssectionuncsorted[im])

theorycurve2             = TGraphErrors ( len(theorycrosssectionsorted2), array('d',theorymasssorted), array('d',theorycrosssectionsorted2) )
for im,mass in enumerate(theorymasssorted) :
    theorycurve2.SetPointError(im,0,theorycrosssectionuncsorted2[im])

theorycurve3             = TGraphErrors ( len(theorycrosssectionsorted3), array('d',theorymasssorted), array('d',theorycrosssectionsorted3) )
for im,mass in enumerate(theorymasssorted) :
    theorycurve3.SetPointError(im,0,theorycrosssectionuncsorted3[im])

observedlimit           = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',obsarraysorted) )
m2sigmaexpectedlimit    = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',m2sigmaexparraysorted) )
m1sigmaexpectedlimit    = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',m1sigmaexparraysorted) )
expectedlimit           = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',meanexparraysorted)    )
expected1sigmalimitarea = TGraphAsymmErrors( len(massarraysorted), array('d',massarraysorted), array('d',meanexparraysorted), array('d',masserrorarray), array('d',masserrorarray), array('d',m1bandmeanexpsorted), array('d',p1bandmeanexpsorted)   )
expected2sigmalimitarea = TGraphAsymmErrors( len(massarraysorted), array('d',massarraysorted), array('d',meanexparraysorted), array('d',masserrorarray), array('d',masserrorarray), array('d',m2bandmeanexpsorted), array('d',p2bandmeanexpsorted)   )
p1sigmaexpectedlimit    = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',p1sigmaexparraysorted) )
p2sigmaexpectedlimit    = TGraph( len(massarraysorted), array('d',massarraysorted), array('d',p2sigmaexparraysorted) )

# Create canvas
# ------------------------------
can.cd(); can.SetLogy(1)
can.SetLeftMargin(0.16)
can.SetRightMargin(0.08)
can.SetTopMargin(0.07)
can.SetBottomMargin(0.13)

# Create legends
# ------------------------------
#legend2 = TLegend(0.52,0.78,0.83,0.9)
#333333legend2 = TLegend(0.52,0.78,0.83,0.83)
legend2 = TLegend(0.52,0.8,0.8,0.9)
#legend1 = TLegend(0.3,0.16,0.5,0.2)
#legend2 = TLegend(0.42,0.85,0.83,0.9)
#legend2.SetFillColor(0); legend2.SetLineColor(0); legend2.SetFillColor(0); legend2.SetFillStyle(0)
#legend2.SetTextSize(0.032); legend2.SetTextFont(42); legend2.SetTextAlign(12)
#legend2 = TLegend(0.52,0.73,0.8,0.9)
legend2.SetFillColor(0); legend2.SetLineColor(0); legend2.SetFillColor(0); legend2.SetFillStyle(0)
legend2.SetTextSize(0.032); legend2.SetTextFont(42); legend2.SetTextAlign(12)

legend2.SetHeader("Cross sections for:")
legend2.AddEntry(theorycurve2,"#tilde{#chi}_{1}^{0}#tilde{#chi}_{2}^{0}","FL")


#legend1 = TLegend(0.19,0.18,0.5,0.2)
#legend1.SetFillColor(0);
#legend1.SetBorderSize(0)
#legend1.SetTextSize(0.032);
#legend1_ = TLegend(0.3,0.24,0.5,0.26)
#legend1_.SetFillColor(0);
#legend1_.SetBorderSize(0)
#legend1_.SetTextSize(0.032);
legend1 = TLegend(0.19,0.18,0.5,0.2)
legend1.SetFillColor(0); legend2.SetLineColor(0); legend2.SetFillColor(0); legend2.SetFillStyle(0)
legend1.SetBorderSize(0);
legend1.SetTextSize(0.032); legend2.SetTextFont(42); legend2.SetTextAlign(12)
legend1_ = TLegend(0.12,0.24,0.42,0.26)
legend1_.SetFillColor(0);
legend1_.SetBorderSize(0);
legend1_.SetTextSize(0.032);

#legend1.AddEntry(theorycurve,"#sigma_{EWKino} with unc.","FL")
#legend1.SetHeader("pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{2}^{0}/#tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{+/-} ,  #tilde{#chi}_{2}^{0}/#tilde{#chi}_{1}^{+/-} #rightarrow #gamma/W^{#pm} #tilde{G}","C")
#legend1.SetHeader("pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{+/-}/#tilde{#chi}_{1}^{0}#tilde{#chi}_{2}^{0}/#tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1/2}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma (H/Z) #tilde{G}","C")   
#legend1.SetHeader("pp #rightarrow #tilde{#chi}_{1}^{0}#tilde{#chi}_{2}^{0} , #tilde{#chi}_{1}^{0} #rightarrow H/Z #tilde{G}, #tilde{#chi}_{2}^{0} #rightarrow #gamma #tilde{G}","C")
legend1_.SetHeader("pp #rightarrow #tilde{#chi}_{1}^{0}#tilde{#chi}_{2}^{0} ","C")   
#legend1.SetHeader("#tilde{#chi}_{1}^{0} #rightarrow H/Z #tilde{G} , #tilde{#chi}_{2}^{0} #rightarrow #gamma #tilde{G}","C")
legend1.SetHeader("#it{B}(#tilde{#chi}_{2}^{0}#rightarrow #gamma #tilde{G}) = #it{B}(#tilde{#chi}_{1}^{0}#rightarrow H/Z #tilde{G}) = 100%")

#legend = TLegend(0.52,0.6,0.63,0.8)
legend = TLegend(0.52,0.56,0.83,0.76)
legend.SetFillColor(0); legend.SetLineColor(0); legend.SetFillColor(0); legend.SetFillStyle(0)
legend.SetTextSize(0.031); legend.SetTextFont(42); legend.SetTextAlign(12)
legend.SetHeader("95% CL upper limits")
legend.AddEntry(observedlimit,"Observed","PL")
legend.AddEntry(expectedlimit,"Expected","PL")
legend.AddEntry(expected1sigmalimitarea,"Expected #pm 1 #sigma_{experiment}","F")
legend.AddEntry(expected2sigmalimitarea,"Expected #pm 2 #sigma_{experiment}","F")


# Create labels
# ------------------------------
cmslabel      = TLatex(); cmslabel.SetTextFont(61);      cmslabel.SetTextAlign(11);      cmslabel.SetNDC();      cmslabel.SetTextSize(0.032)
cmsextralabel = TLatex(); cmsextralabel.SetTextFont(52); cmsextralabel.SetTextAlign(11); cmsextralabel.SetNDC(); cmsextralabel.SetTextSize(0)
lumilabel     = TLatex(); lumilabel.SetTextFont(42);     lumilabel.SetTextAlign(31);     lumilabel.SetNDC();     lumilabel.SetTextSize(0.032)


# Draw & save output 
# ------------------------------
hFrame = TH1D("","",1,300,1450)
hFrame.Draw("HIST")
SetHistoStyle(hFrame)
hFrame.GetXaxis().SetTitleSize(0.035)
hFrame.GetYaxis().SetRangeUser(0.000005,10.)
hFrame.GetYaxis().SetTitle("Cross section (pb)")
hFrame.GetYaxis().SetTitleOffset(1.7)
hFrame.GetXaxis().SetTitle("m_{NLSP} (GeV)")
hFrame.GetXaxis().SetTitleSize(0.035)
hFrame.GetXaxis().SetLabelSize(0.032)
hFrame.GetXaxis().SetTitleFont(42);
hFrame.GetXaxis().SetTitleOffset(1.4)

#hFrame.GetXaxis().SetLabelSize(0.02)
expectedlimit.SetLineStyle(3)
expectedlimit.SetLineWidth(2)
observedlimit.SetMarkerStyle(9)
observedlimit.SetLineStyle(7)
observedlimit.SetLineWidth(3)
expected1sigmalimitarea.SetFillColor(kGreen+1)
expected1sigmalimitarea.SetLineColor(kGreen+1)
expected1sigmalimitarea.SetFillStyle(1001)
expected2sigmalimitarea.SetFillColor(kOrange)
expected2sigmalimitarea.SetLineColor(kOrange)
expected2sigmalimitarea.SetFillStyle(1001)
theorycurve.SetFillColor(kRed-9)
theorycurve.SetFillStyle(1001)
theorycurve.SetLineColor(kRed+1)
theorycurve.SetLineWidth(2)
theorycurve2.SetFillColor(kBlue-9)
theorycurve2.SetFillStyle(1001)
theorycurve2.SetLineColor(kBlue+1)
theorycurve2.SetLineWidth(2)
theorycurve3.SetFillColor(kMagenta-9)
theorycurve3.SetFillStyle(1001)
theorycurve3.SetLineColor(kMagenta+1)
theorycurve3.SetLineWidth(2)

expected2sigmalimitarea.Draw("3same")
expected1sigmalimitarea.Draw("3same")

#m1sigmaexpectedlimit.Draw("Lsame")
#p1sigmaexpectedlimit.Draw("Lsame")
#m2sigmaexpectedlimit.Draw("Lsame")
#p2sigmaexpectedlimit.Draw("Lsame")

#theorycurve.Draw("3same")
#theorycurve.Draw("LXsame")
theorycurve2.Draw("3same")
theorycurve2.Draw("LXsame")
#theorycurve3.Draw("3same")
#theorycurve3.Draw("LXsame")
expectedlimit.Draw("PLsame")
observedlimit.Draw("PLsame")
legend2.Draw()
legend.Draw()
legend1.Draw()
legend1_.Draw()

#cmslabel.DrawLatex(0.16,0.942,"CMS")
cmslabel.DrawLatexNDC(0.16,0.942,"CMS");
cmsextralabel.DrawLatex(0.23,0.942,"Preliminary")
lumilabel.DrawLatex(0.92,0.942,"137 fb^{-1} (13 TeV)")
gPad.RedrawAxis()
outFile = TFile("rootoutput/signals/limitPlotter_TChiNGnn.root","recreate")
outFile.cd()
theorycurve.Write("sigmatheory")
expectedlimit.Write("exp")
observedlimit.Write("obs")
m1sigmaexpectedlimit.Write("exp16pc")
p1sigmaexpectedlimit.Write("exp84pc")
can.SaveAs("pdf/"+limitname+".pdf")
can.SaveAs("png/"+limitname+".png")

#print can.SaveAs("limitPlotter_"+limitname+".pdf")


if expLimit <= massarraysorted[0] or expLimit >= massarraysorted[len(massarraysorted)-1] : print ("No expected limit calculation possible!")
elif expLimit != 0 : 
    print ("Expected Limit: %.0f GeV" % expLimit)
if obsLimit <= massarraysorted[0] or obsLimit >= massarraysorted[len(massarraysorted)-1] : print ("No observed limit calculation possible!")
elif obsLimit != 0 : 
    print ("Observed Limit: %.0f GeV" % obsLimit)