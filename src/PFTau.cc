#include "DataFormats/TauReco/interface/PFTau.h"

PFTau::PFTau(){
  PFCandidateRef pfLead;
  TrackRef tmp;
  leadPFChargedHadrCand_=pfLead;
  leadPFChargedHadrCandsignedSipt_=NAN;
  
  PFCandidateRefVector pfTmp;
  selectedSignalPFChargedHadrCands_=pfTmp;
  selectedSignalPFNeutrHadrCands_=pfTmp;
  selectedSignalPFGammaCands_=pfTmp;

  selectedIsolationPFChargedHadrCands_=pfTmp;
  selectedIsolationPFNeutrHadrCands_=pfTmp;
  selectedIsolationPFGammaCands_=pfTmp;

  isolationPFChargedHadrCandsPtSum_=NAN;
  isolationPFGammaCandsEtSum_=NAN;
  maximumHCALPFClusterEt_=NAN;


  emFraction_ = NAN;
  hcalTotOverPLead_ = NAN;
  hcalMaxOverPLead_ = NAN;
  hcal3x3OverPLead_ = NAN;
  ecalStripSumEOverPLead_= NAN;
  bremsRecoveryEOverPLead_ = NAN;
  electronPreIDTrack_ = tmp;
  electronPreIDOutput_ = NAN;
  electronPreIDDecision_= NAN;
}

PFTau::PFTau(Charge q,const LorentzVector& p4,const Point& vtx) : BaseTau(q,p4,vtx){
  PFCandidateRef pfLead;
  TrackRef tmp;
  leadPFChargedHadrCand_=pfLead;
  leadPFChargedHadrCandsignedSipt_=NAN;
  
  PFCandidateRefVector pfTmp;
  selectedSignalPFChargedHadrCands_=pfTmp;
  selectedSignalPFNeutrHadrCands_=pfTmp;
  selectedSignalPFGammaCands_=pfTmp;

  selectedIsolationPFChargedHadrCands_=pfTmp;
  selectedIsolationPFNeutrHadrCands_=pfTmp;
  selectedIsolationPFGammaCands_=pfTmp;

  isolationPFChargedHadrCandsPtSum_=NAN;
  isolationPFGammaCandsEtSum_=NAN;
  maximumHCALPFClusterEt_=NAN;

  emFraction_ = NAN;
  hcalTotOverPLead_ = NAN;
  hcalMaxOverPLead_ = NAN;
  hcal3x3OverPLead_ = NAN;
  ecalStripSumEOverPLead_= NAN;
  bremsRecoveryEOverPLead_ = NAN;
  electronPreIDTrack_ = tmp;
  electronPreIDOutput_ = NAN;
  electronPreIDDecision_= NAN;
}

PFTau* PFTau::clone()const{return new PFTau(*this);}

const PFTauTagInfoRef& PFTau::pfTauTagInfoRef()const{return PFTauTagInfoRef_;}
void PFTau::setpfTauTagInfoRef(const PFTauTagInfoRef x) {PFTauTagInfoRef_=x;}
    
const PFCandidateRef& PFTau::leadPFChargedHadrCand()const {return leadPFChargedHadrCand_;}   
void PFTau::setleadPFChargedHadrCand(const PFCandidateRef& myLead) { leadPFChargedHadrCand_=myLead;}   
float PFTau::leadPFChargedHadrCandsignedSipt()const{return leadPFChargedHadrCandsignedSipt_;}
void PFTau::setleadPFChargedHadrCandsignedSipt(const float& x){leadPFChargedHadrCandsignedSipt_=x;}

const PFCandidateRefVector& PFTau::signalPFCands()const {return selectedSignalPFCands_;}
void PFTau::setsignalPFCands(const PFCandidateRefVector& myParts)  { selectedSignalPFCands_ = myParts;}
const PFCandidateRefVector& PFTau::signalPFChargedHadrCands()const {return selectedSignalPFChargedHadrCands_;}
void PFTau::setsignalPFChargedHadrCands(const PFCandidateRefVector& myParts)  { selectedSignalPFChargedHadrCands_ = myParts;}
const PFCandidateRefVector& PFTau::signalPFNeutrHadrCands()const {return selectedSignalPFNeutrHadrCands_;}
void PFTau::setsignalPFNeutrHadrCands(const PFCandidateRefVector& myParts)  { selectedSignalPFNeutrHadrCands_ = myParts;}
const PFCandidateRefVector& PFTau::signalPFGammaCands()const {return selectedSignalPFGammaCands_;}
void PFTau::setsignalPFGammaCands(const PFCandidateRefVector& myParts)  { selectedSignalPFGammaCands_ = myParts;}

const PFCandidateRefVector& PFTau::isolationPFCands()const {return selectedIsolationPFCands_;}
void PFTau::setisolationPFCands(const PFCandidateRefVector& myParts)  { selectedIsolationPFCands_ = myParts;}
const PFCandidateRefVector& PFTau::isolationPFChargedHadrCands()const {return selectedIsolationPFChargedHadrCands_;}
void PFTau::setisolationPFChargedHadrCands(const PFCandidateRefVector& myParts)  { selectedIsolationPFChargedHadrCands_ = myParts;}
const PFCandidateRefVector& PFTau::isolationPFNeutrHadrCands()const {return selectedIsolationPFNeutrHadrCands_;}
void PFTau::setisolationPFNeutrHadrCands(const PFCandidateRefVector& myParts)  { selectedIsolationPFNeutrHadrCands_ = myParts;}
const PFCandidateRefVector& PFTau::isolationPFGammaCands()const {return selectedIsolationPFGammaCands_;}
void PFTau::setisolationPFGammaCands(const PFCandidateRefVector& myParts)  { selectedIsolationPFGammaCands_ = myParts;}

float PFTau::isolationPFChargedHadrCandsPtSum()const{return isolationPFChargedHadrCandsPtSum_;}
void PFTau::setisolationPFChargedHadrCandsPtSum(const float& x){isolationPFChargedHadrCandsPtSum_=x;}

float PFTau::isolationPFGammaCandsEtSum()const{return isolationPFGammaCandsEtSum_;}
void PFTau::setisolationPFGammaCandsEtSum(const float& x){isolationPFGammaCandsEtSum_=x;}

float PFTau::maximumHCALPFClusterEt()const{return maximumHCALPFClusterEt_;}
void PFTau::setmaximumHCALPFClusterEt(const float& x){maximumHCALPFClusterEt_=x;}

float PFTau::emFraction() const {return emFraction_;}
float PFTau::hcalTotOverPLead() const {return hcalTotOverPLead_;}
float PFTau::hcalMaxOverPLead() const {return hcalMaxOverPLead_;}
float PFTau::hcal3x3OverPLead() const {return hcal3x3OverPLead_;}
float PFTau::ecalStripSumEOverPLead() const {return ecalStripSumEOverPLead_;}
float PFTau::bremsRecoveryEOverPLead() const {return bremsRecoveryEOverPLead_;}
reco::TrackRef PFTau::electronPreIDTrack() const {return electronPreIDTrack_;}
float PFTau::electronPreIDOutput() const {return electronPreIDOutput_;}
bool PFTau::electronPreIDDecision() const {return electronPreIDDecision_;}

void PFTau::setemFraction(const float& x) {emFraction_ = x;}
void PFTau::sethcalTotOverPLead(const float& x) {hcalTotOverPLead_ = x;}
void PFTau::sethcalMaxOverPLead(const float& x) {hcalMaxOverPLead_ = x;}
void PFTau::sethcal3x3OverPLead(const float& x) {hcal3x3OverPLead_ = x;}
void PFTau::setecalStripSumEOverPLead(const float& x) {ecalStripSumEOverPLead_ = x;}
void PFTau::setbremsRecoveryEOverPLead(const float& x) {bremsRecoveryEOverPLead_ = x;}
void PFTau::setelectronPreIDTrack(const reco::TrackRef& x) {electronPreIDTrack_ = x;}
void PFTau::setelectronPreIDOutput(const float& x) {electronPreIDOutput_ = x;}
void PFTau::setelectronPreIDDecision(const bool& x) {electronPreIDDecision_ = x;}

bool PFTau::overlap(const Candidate& theCand)const{
  const RecoCandidate* theRecoCand=dynamic_cast<const RecoCandidate *>(&theCand);
  return (theRecoCand!=0 && (checkOverlap(track(),theRecoCand->track())));
}
