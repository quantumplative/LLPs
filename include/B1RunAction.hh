/// \file B1RunAction.hh
/// \brief Definition of the B1RunAction class

#ifndef B1RunAction_h
#define B1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include <vector>

class G4Run;
class G4LogicalVolume;

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume 
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.

class B1RunAction : public G4UserRunAction
{
  public:
    B1RunAction();
    virtual ~B1RunAction();

    virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

    TFile* ofFile = new TFile("test101.root");
    TTree* gst = (TTree*) ofFile->Get("gst");         
};

//------------------------------------------------------------------------------

#endif

