#ifndef B1Analysis_h
#define B1Analysis_h 1
#include "globals.hh"

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include <vector>

//#include "g4root.hh"
#include "g4csv.hh"
//#include "g4xml.hh"


class B1Analysis 
{
public: 
	virtual ~B1Analysis(); 

	static B1Analysis* getInstance(); 
	static B1Analysis* instance; 

	void CloseFile(); 


	//TFile* ofFile; 
	//TTree* fTree; 

}; 
#endif
