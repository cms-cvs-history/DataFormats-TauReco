#ifndef DataFormats_TauReco_PFTauTransverseImpactParameter_h
#define DataFormats_TauReco_PFTauTransverseImpactParameter_h

/* class PFTauTransverseImpactParameter
 * 
 * Stores information on the impact paramters and flight length of the hadronic decay of a tau lepton
 *

 * author: Ian M. Nugent
 */

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Math/interface/Error.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "TVector3.h"

namespace reco {
  class PFTauTransverseImpactParameter 
  {    
    enum { dimension = 3 };
    enum { covarianceSize = dimension * ( dimension + 1 ) / 2 };
    typedef math::Error<dimension>::type CovMatrix;
    typedef math::XYZPoint Point;

  public:
    PFTauTransverseImpactParameter(){}
    /// constructor from values
    PFTauTransverseImpactParameter(const Point&, double, double, const VertexRef&);
    PFTauTransverseImpactParameter(const Point&, double, double, const VertexRef&, const Point&, const CovMatrix&, const VertexRef&);
      
    virtual ~PFTauTransverseImpactParameter(){}
    PFTauTransverseImpactParameter* clone() const;

    const Point& DOCA() const { return doca_; }
    double dxy() const { return dxy_; }
    double dxy_error() const { return dxy_error_; }
    double dxy_Sig() const 
    {
      if ( dxy_error_ != 0 ) return dxy_/dxy_error_; 
      else return 0; 
    }
    const VertexRef& PrimaryVertex() const { return PV_; }
    bool hasSecondaryVertex() const { return hasSV_; }
    TVector3 FlightLength() const;
    double FlightLengthSig() const;
    const CovMatrix& FlightLenghtCov() const { return FlightLenghtCov_; }
    const VertexRef& SecondaryVertex() const { return SV_; }
    
  private:
    Point     doca_;
    double    dxy_;
    double    dxy_error_;
    VertexRef PV_;
    bool      hasSV_;
    Point     FlightLength_;
    CovMatrix FlightLenghtCov_;
    VertexRef SV_;    
   };
}

#endif
