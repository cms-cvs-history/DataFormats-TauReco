#include "DataFormats/TauReco/interface/PFTauTransverseImpactParameter.h"
#include "TMatrixT.h"
#include "TMatrixTSym.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "TVectorT.h"
using namespace reco;

PFTauTransverseImpactParameter::PFTauTransverseImpactParameter(const Point& doca, double thedxy, double thedxy_error, const VertexRef& PV)
  : doca_(doca),
    dxy_(thedxy),
    dxy_error_(thedxy_error),
    PV_(PV),
    hasSV_(false)
{}

PFTauTransverseImpactParameter::PFTauTransverseImpactParameter(const Point& doca, double thedxy, double thedxy_error, const VertexRef& PV, 
							       const Point& theFlightLength, const CovMatrix& theFlightLenghtCov, const VertexRef& SV)
  : doca_(doca),
    dxy_(thedxy),
    dxy_error_(thedxy_error),
    PV_(PV),
    hasSV_(true),
    FlightLength_(theFlightLength),
    FlightLenghtCov_(theFlightLenghtCov),
    SV_(SV)
{}

PFTauTransverseImpactParameter* PFTauTransverseImpactParameter::clone() const
{
  return new PFTauTransverseImpactParameter(*this);
}

double PFTauTransverseImpactParameter::FlightLengthSig() const 
{
  if ( hasSV_ ){
    VertexDistance3D vtxdist;
    return vtxdist.distance(*PV_, *SV_).significance(); // transforms using the jacobian then computes distance/uncertainty 
  } else {
    return -999;
  }
}

TVector3 PFTauTransverseImpactParameter::FlightLength() const 
{
  return TVector3(FlightLength_.x(), FlightLength_.y(), FlightLength_.z());
}
