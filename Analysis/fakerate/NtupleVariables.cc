#define NtupleVariables_cxx

#include "NtupleVariables.h"
#include <TH2.h>
#include <TStyle.h>

double NtupleVariables::DeltaPhi(double phi1, double phi2) {
  double result = phi1 - phi2;
  while (result > M_PI)    result -= 2 * M_PI;
  while (result <= -M_PI)  result += 2 * M_PI;
  return result;
}

double NtupleVariables::DeltaR(double eta1, double phi1, double eta2, double phi2) {
  double deta = eta1 - eta2;
  double dphi = DeltaPhi(phi1, phi2);
  return std::sqrt(deta*deta + dphi*dphi);
}

void NtupleVariables::sortTLorVec(vector<TLorentzVector> *vec){
  TLorentzVector temp;
  for(int i=1;i<vec->size();i++){
    for(int j=i;j<vec->size();j++){
      if( (*vec)[i-1].Pt() < (*vec)[j].Pt() ){
	temp = (*vec)[i-1];
	(*vec)[i-1] = (*vec)[j];
	(*vec)[j] = temp;
      }
    }
  }
}

double NtupleVariables::MinDr(TLorentzVector v1,vector<TLorentzVector> v2)
{
  double dr = 60;
  for(int j=0;j<v2.size();j++)
    { if(dr>=v1.DeltaR(v2[j]))
	{ dr = v1.DeltaR(v2[j]);}
    }
  return dr;
}
double NtupleVariables::MinDr2(vector<TLorentzVector> v1,TLorentzVector v2)
{
  double dr = 60;
  for(int j=0;j<v1.size();j++)
    { if(dr>=v1[j].DeltaR(v2))
	{ dr = v1[j].DeltaR(v2);}
    }
  return dr;
}
