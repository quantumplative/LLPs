/// \file B1Run.hh
/// \brief Definition of the B1Run class

#ifndef B1Run_h
#define B1Run_h 1

#include "G4Run.hh"
#include "globals.hh"

class G4Event;

/// Run class
///

class B1Run : public G4Run
{
  public:
    B1Run();
    virtual ~B1Run();

    // method from the base class
    virtual void Merge(const G4Run*);
    
    void AddEdep (G4double edep); 

    // get methods
    G4double GetEdep()  const { return fEdep; }
    G4double GetEdep2() const { return fEdep2; }

  private:
    G4double  fEdep;
    G4double  fEdep2;
};

//------------------------------------------------------------------------------

#endif

