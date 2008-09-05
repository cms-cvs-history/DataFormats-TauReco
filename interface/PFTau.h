#ifndef DataFormats_TauReco_PFTau_h
#define DataFormats_TauReco_PFTau_h

/* class PFTau
 * the object of this class is created by RecoTauTag/RecoTau PFRecoTauProducer EDProducer starting from the PFTauTagInfo object,
 *                          is a hadronic tau-jet candidate -built from a jet made employing a particle flow technique- that analysts manipulate;
 * authors: Simone Gennai (simone.gennai@cern.ch), Ludovic Houchu (Ludovic.Houchu@cern.ch)
 * created: Jun 21 2007,
 * revised: Sep 12 2007
 */
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/TauReco/interface/BaseTau.h"
#include "DataFormats/TauReco/interface/PFTauFwd.h"
#include "DataFormats/TauReco/interface/PFTauTagInfo.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"

#include <limits>

using namespace reco;

namespace reco {
  class PFTau : public BaseTau {
  public:
    PFTau();
    PFTau(Charge q,const LorentzVector &,const Point & = Point( 0, 0, 0 ) );
    virtual ~PFTau(){}
    PFTau* clone()const;
    
    const PFTauTagInfoRef& pfTauTagInfoRef()const;
    void setpfTauTagInfoRef(const PFTauTagInfoRef);
    
    const PFCandidateRef& leadPFChargedHadrCand()const; 
    void setleadPFChargedHadrCand(const PFCandidateRef&);
    // signed transverse impact parameter significance of the Track constituting the leading charged hadron PFCandidate 
    float leadPFChargedHadrCandsignedSipt()const;
    void setleadPFChargedHadrCandsignedSipt(const float&);
    
    // XXX PFCandidates which passed quality cuts and are inside a tracker/ECAL/HCAL signal cone around leading charged hadron PFCandidate
    const PFCandidateRefVector& signalPFCands()const;
    void setsignalPFCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& signalPFChargedHadrCands()const;
    void setsignalPFChargedHadrCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& signalPFNeutrHadrCands()const;
    void setsignalPFNeutrHadrCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& signalPFGammaCands()const;
    void setsignalPFGammaCands(const PFCandidateRefVector&);
    
    // XXX PFCandidates which passed quality cuts and are inside a tracker/ECAL/HCAL isolation annulus around leading charged hadron PFCandidate
    const PFCandidateRefVector& isolationPFCands()const;
    void setisolationPFCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& isolationPFChargedHadrCands()const;
    void setisolationPFChargedHadrCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& isolationPFNeutrHadrCands()const;
    void setisolationPFNeutrHadrCands(const PFCandidateRefVector&);
    const PFCandidateRefVector& isolationPFGammaCands()const;
    void setisolationPFGammaCands(const PFCandidateRefVector&);

    // sum of Pt of the charged hadr. PFCandidates inside a tracker isolation annulus around leading charged hadron PFCandidate ; NaN if no leading charged hadron PFCandidate
    float isolationPFChargedHadrCandsPtSum()const;
    void setisolationPFChargedHadrCandsPtSum(const float&);
   
    // sum of Et of the gamma PFCandidates inside an ECAL isolation annulus around leading charged hadron PFCandidate ; NaN if no leading charged hadron PFCandidate 
    float isolationPFGammaCandsEtSum()const;
    void setisolationPFGammaCandsEtSum(const float&);
    
    // Et of the highest Et HCAL PFCluster  
    float maximumHCALPFClusterEt()const;
    void setmaximumHCALPFClusterEt(const float&);    

    //Electron rejection
    float emFraction() const; // Ecal/Hcal Cluster Energy 
    float hcalTotOverPLead() const; // total Hcal Cluster E / leadPFChargedHadron P
    float hcalMaxOverPLead() const; // max. Hcal Cluster E / leadPFChargedHadron P
    float hcal3x3OverPLead() const; // Hcal Cluster E in R<0.184 around Ecal impact point of leading track / leadPFChargedHadron P
    float ecalStripSumEOverPLead() const; // Simple BremsRecovery Sum E / leadPFChargedHadron P
    float bremsRecoveryEOverPLead() const; // BremsRecovery Sum E / leadPFChargedHadron P
    reco::TrackRef electronPreIDTrack() const; // Ref to KF track from Electron PreID
    float electronPreIDOutput() const; // BDT output from Electron PreID
    bool electronPreIDDecision() const; // Decision from Electron PreID

    void setemFraction(const float&);
    void sethcalTotOverPLead(const float&);
    void sethcalMaxOverPLead(const float&);
    void sethcal3x3OverPLead(const float&);
    void setecalStripSumEOverPLead(const float&);
    void setbremsRecoveryEOverPLead(const float&);
    void setelectronPreIDTrack(const reco::TrackRef&);
    void setelectronPreIDOutput(const float&);
    void setelectronPreIDDecision(const bool&);
    // 
// For Muon Rejection
    bool    hasMuonReference()const; // check if muon ref exists
    float   caloComp()const;
    float   segComp()const;
    bool    muonDecision()const;
    void setCaloComp(const float&);
    void setSegComp(const float&);
    void setMuonDecision(const bool&);
//

  private:
    // check overlap with another candidate
    virtual bool overlap(const Candidate&)const;
    PFTauTagInfoRef PFTauTagInfoRef_;
    PFCandidateRef leadPFChargedHadrCand_;
    float leadPFChargedHadrCandsignedSipt_;
    PFCandidateRefVector selectedSignalPFCands_, selectedSignalPFChargedHadrCands_, selectedSignalPFNeutrHadrCands_, selectedSignalPFGammaCands_;
    PFCandidateRefVector selectedIsolationPFCands_, selectedIsolationPFChargedHadrCands_, selectedIsolationPFNeutrHadrCands_, selectedIsolationPFGammaCands_;
    float isolationPFChargedHadrCandsPtSum_;
    float isolationPFGammaCandsEtSum_;
    float maximumHCALPFClusterEt_;

    float emFraction_;
    float hcalTotOverPLead_;
    float hcalMaxOverPLead_;
    float hcal3x3OverPLead_;
    float ecalStripSumEOverPLead_;
    float bremsRecoveryEOverPLead_;
    reco::TrackRef electronPreIDTrack_;
    float electronPreIDOutput_;
    bool electronPreIDDecision_;

    float caloComp_;
    float segComp_;
    bool muonDecision_;
  };
}
#endif
