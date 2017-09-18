/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//------------------------------------------------------------------------------

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//------------------------------------------------------------------------------

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//------------------------------------------------------------------------------

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4double fractionmass, density1, density2, density3;
  G4String name1, name2, name3;
  G4int ncomponents1, ncomponents2, ncomponents3; 
  // Envelope parameters
  

  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = true;

  G4Element* si = nist->FindOrBuildElement("Si");
  G4Element* o = nist->FindOrBuildElement("O");
  G4Element* al = nist->FindOrBuildElement("Al");
  G4Element* k = nist->FindOrBuildElement("K");

  //---------------------- Quartz --------------------------
  density1 = 2.62*g/cm3;
  G4Material* Quartz = new G4Material(name1 = "Quartz", density1, ncomponents1=2);
  Quartz->AddElement(si, fractionmass = 47*perCent);
  Quartz->AddElement(o, fractionmass = 53*perCent);

  //--------------------- Feldspar -------------------------
  density2 = 2.56*g/cm3;
  G4Material* Feldspar = new G4Material(name2 = "Feldspar", density2, ncomponents2=4);
  Feldspar->AddElement(o, fractionmass = 46*perCent);
  Feldspar->AddElement(k, fractionmass = 14*perCent);
  Feldspar->AddElement(al, fractionmass = 10*perCent);
  Feldspar->AddElement(si, fractionmass = 30*perCent);

  //--------------------- Rock -----------------------------
  density3 = 2.33*g/cm3;
  G4Material* Rock = new G4Material(name3="Rock", density3, ncomponents3=2);
  Rock->AddMaterial(Feldspar, fractionmass=17*perCent);
  Rock->AddMaterial(Quartz, fractionmass=83*perCent);

  // World
 
  //Rock World size:
  G4double world_sizeXY = 1000*m;
  G4double world_sizeZ  = 1000*m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR"); 
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       world_sizeXY, world_sizeXY, world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  //Rock
  G4Box* RockBox =
    new G4Box("RockBox",                    //its name
       100*m ,100*m , 100*m); //its size

  G4LogicalVolume* logicRB =
    new G4LogicalVolume(RockBox,            //its solid
                        Rock,             //its material
                        "RockBox");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0, 0, 0),         //at (0,0,0)
                    logicRB,                //its logical volume
                    "RockBox",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking 

  return physWorld;
}

//------------------------------------------------------------------------------
