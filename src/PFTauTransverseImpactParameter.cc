#include "DataFormats/TauReco/interface/PFTauTransverseImpactParameter.h"
#include "TMatrixT.h"
#include "TMatrixTSym.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "TVectorT.h"
using namespace reco;

PFTauTransverseImpactParameter::PFTauTransverseImpactParameter(Point pca,double thedxy, double thedxy_error,VertexRef PV):
  pca_(pca),
  dxy_(thedxy),
  dxy_error_(thedxy_error),
  PV_(PV),
  hasSV_(false)
{
}

PFTauTransverseImpactParameter::PFTauTransverseImpactParameter(Point pca,double thedxy, double thedxy_error,VertexRef PV,
							       Point theFlightLength,VertexRef SV):
  pca_(pca),
  dxy_(thedxy),
  dxy_error_(thedxy_error),
  PV_(PV),
  hasSV_(true),
  FlightLength_(theFlightLength),
  SV_(SV)
{
}

PFTauTransverseImpactParameter* PFTauTransverseImpactParameter::clone() const{
  return new PFTauTransverseImpactParameter(*this);
}

double PFTauTransverseImpactParameter::FlightLengthSig(){
  if(hasSV_){
    VertexDistance3D vtxdist;
    return vtxdist.distance(*PV_, *SV_).significance(); // transforms using the jacobian then computes distance/uncertainty 
  }
  return -999;
}

TVector3 PFTauTransverseImpactParameter::FlightLength(){
  return TVector3(FlightLength_.x(),FlightLength_.y(),FlightLength_.z());
}

PFTauTransverseImpactParameter::CovMatrix PFTauTransverseImpactParameter::PrimaryVertexCov(){
  CovMatrix cov;
  for(int i=0;i<dimension;i++){
    for(int j=0;j<dimension;j++){
      cov(i,j)=PV_->covariance(i,j);
    }
  }
  return cov;
}

PFTauTransverseImpactParameter::CovMatrix PFTauTransverseImpactParameter::SecondaryVertexCov(){
  CovMatrix cov;
  if(!hasSV_) return cov;
  for(int i=0;i<dimension;i++){
    for(int j=0;j<dimension;j++){
      cov(i,j)=SV_->covariance(i,j);
    }
  }
  return cov;
}

PFTauTransverseImpactParameter::CovMatrix PFTauTransverseImpactParameter::FlightLenghtCov(){
  CovMatrix cov;
  CovMatrix sv=SecondaryVertexCov();
  CovMatrix pv=PrimaryVertexCov();
  for(int i=0;i<dimension;i++){
    for(int j=0;j<dimension;j++){
      cov(i,j)=sv(i,j)+pv(i,j);
    }
  }
  return cov;
}
