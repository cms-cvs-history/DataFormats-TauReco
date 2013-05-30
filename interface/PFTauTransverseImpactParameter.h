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
   class PFTauTransverseImpactParameter {
     enum { dimension = 3 };
     enum { covarianceSize = dimension * ( dimension + 1 ) / 2 };
     typedef math::Error<dimension>::type CovMatrix;
     typedef math::XYZPoint Point;

   public:
      PFTauTransverseImpactParameter(){}
      /// constructor from values
      PFTauTransverseImpactParameter(Point pca,double thedxy, double thedxy_error,VertexRef PV);
      PFTauTransverseImpactParameter(Point pca,double thedxy, double thedxy_error,VertexRef PV,Point theFlightLength,
				     VertexRef SV);

      virtual ~PFTauTransverseImpactParameter(){}
      PFTauTransverseImpactParameter* clone() const;

      Point     PCA(){return pca_;}
      double    dxy(){return dxy_;}
      double    dxy_error(){return dxy_error_;}
      double    dxy_Sig(){if(dxy_error_!=0)return dxy_/dxy_error_;return 0;}
      VertexRef PrimaryVertex(){return PV_;}
      CovMatrix PrimaryVertexCov();
      bool      hasSecondaryVertex(){return hasSV_;}
      TVector3  FlightLength();
      double    FlightLengthSig();
      CovMatrix FlightLenghtCov();
      VertexRef SecondaryVertex(){return SV_;}
      CovMatrix SecondaryVertexCov();

   private:
      Point      pca_;
      double     dxy_;
      double     dxy_error_;
      VertexRef  PV_;
      bool       hasSV_;
      Point      FlightLength_;
      VertexRef  SV_;

   };
}

#endif
