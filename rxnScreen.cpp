#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <random>

#include <openbabel/atom.h>
#include <openbabel/babelconfig.h>
#include <openbabel/base.h>
#include <openbabel/builder.h>
#include <openbabel/math/vector3.h>
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <openbabel/forcefield.h>
#include <openbabel/obutil.h>
/*
#include <func.hpp>
#include <utils.cpp>
*/

void addAtom(OpenBabel::OBMol &mol, int atomA, int atomB, int bondOrder, int Z) {
	// declarations
	OpenBabel::OBBuilder build;

	// main
	mol.DeleteHydrogens();
	mol.NewAtom()->SetAtomicNum(Z);
	build.Connect(mol,atomA,atomB,bondOrder);
	mol.AddHydrogens();
}


int main(int argc, char *argv[])
{
	// check cmd line
	if ( argc < 2 ) {
		std::cout << "u little idiot!" << std::endl;
	}

	// read cmd line arguments
	std::string filename = argv[1];

	// OB declarations
	OpenBabel::OBMol mol;
	OpenBabel::OBConversion conv;
	std::vector<int> atomType = {6,7,8};
	
	// OB in/out put handling
	conv.SetInAndOutFormats("xyz", "xyz");
	
	std::ifstream ifs;

	// main
  for(int i = 0; (unsigned) i < atomType.size(); i++ ) {
		std::string outfile = "test_.xyz";
		ifs.open(filename.c_str());
		conv.Read(&mol, &ifs);
		ifs.close();

    addAtom(mol, 1, 2, 1, atomType[i]);

		outfile.insert(5,std::to_string(atomType[i]));
		std::ofstream ofs(outfile);
		conv.Write(&mol, &ofs);
	}
}
