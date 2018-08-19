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

#include "func.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {
	// tubl check
	if ( argc < 2 ) {
		std::cout << "u fking idiot! u need more input files" << std::endl;
	}

	// read cmd line arguments
	std::string filename = argv[1];

	// declarations
	OpenBabel::OBMol mol;
	std::vector<int> atomType = {6,7,8};
	std::vector<std::string> atomLabel = {"C","N","O"};

	// read in xyz file
	mol = read_xyz(filename);
	
	// first substitution
	biatomics(mol, atomType, atomLabel, filename);
}
