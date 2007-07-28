#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/TauReco/interface/Tau.h"
#include "DataFormats/TauReco/interface/TauDiscriminatorByIsolation.h"

#include <vector>
#include <map>

namespace {
  namespace {
    std::vector<reco::Tau> v1;
    edm::Wrapper<std::vector<reco::Tau> > c1;
    edm::Ref<std::vector<reco::Tau> > r1;
    edm::RefProd<std::vector<reco::Tau> > rp1;
    edm::RefVector<std::vector<reco::Tau> > rv1;
    edm::reftobase::Holder<reco::Candidate, reco::TauRef> rb1;

    reco::TauDiscriminatorByIsolation                                          tdi;
    std::pair<reco::Tau,double>                                                tdi_p;
    edm::Wrapper<reco::TauDiscriminatorByIsolation>                            tdi_wc;
  }
}
