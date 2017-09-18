/// \file B1EventAction.cc
/// \brief Implementation of the B1EventAction class

#include "B1EventAction.hh"
#include "B1Run.hh"
#include "B1Analysis.hh" 

#include "G4Event.hh"
#include "G4RunManager.hh"

//------------------------------------------------------------------------------

B1Analysis* B1Analysis::instance = 0; 


//ofFile(0); 

//B1AnalysisManager::B1AnalysisManager() : 

//fFile(0) , fTree(0)
//{;}

B1EventAction::B1EventAction()
: G4UserEventAction(),
  fEdep(0.)
{} 

//------------------------------------------------------------------------------

B1EventAction::~B1EventAction()
{}

//------------------------------------------------------------------------------

void B1EventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.;
}

//------------------------------------------------------------------------------

void B1EventAction::EndOfEventAction(const G4Event*)
{   
  // accumulate statistics in B1Run
  B1Run* run 
    = static_cast<B1Run*>(
        G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->AddEdep(fEdep);
}

//------------------------------------------------------------------------------
