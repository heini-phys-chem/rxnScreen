#ifndef SRC_UTILS_HPP
#define SRC_UTILS_HPP
#define HAVE_EIGEN   

void addAtom(OpenBabel::OBMol &mol, int atomA, int atomB, int bondOrder, int Z) {
	/* deletes hydrogens, adds atom, adds hydrogens */
	OpenBabel::OBBuilder build;

	mol.DeleteHydrogens();
	mol.NewAtom()->SetAtomicNum(Z);
	build.Connect(mol,atomA,atomB,bondOrder);
	mol.AddHydrogens();
}

OpenBabel::OBMol read_xyz(std::string filename) {
	/* read in xyz file and return OBMol */
	OpenBabel::OBMol mol;
	OpenBabel::OBConversion conv;
	conv.SetInAndOutFormats("xyz", "xyz");

	std::ifstream ifs;
	ifs.open(filename.c_str());
	conv.Read(&mol, &ifs);
	ifs.close();

	return mol;
}

std::string write_xyz(OpenBabel::OBMol &mol, std::string filename, std::string atomLabel, int bondOrder) {
	/* writes OBMol to xyz file and returns outfile */
	OpenBabel::OBConversion conv;
	conv.SetInAndOutFormats("xyz", "xyz");
	std::string strg = filename.erase(filename.size() - 4); 
	std::string outfile = strg + "_" + atomLabel + "_" + std::to_string(bondOrder) + ".xyz";

	std::cout << outfile << std::endl;
	
	std::ofstream ofs(outfile);
	conv.Write(&mol, &ofs);

	return outfile;
}

void biatomics(OpenBabel::OBMol mol, std::vector<int> atomType, std::vector<std::string> atomLabel, std::string filename) {
	/* DOTO */
  for(unsigned i = 0; i < atomType.size(); i++ ) {
		if( atomType[i] == 6 ) {
			for(int bondOrder = 1; bondOrder <= 3; bondOrder++ ) {
				mol = read_xyz(filename);
				std::string outfile = filename;
    		addAtom(mol, 1, 2, bondOrder, atomType[i]);
				outfile = write_xyz(mol, outfile, atomLabel[i], bondOrder);
			}
		}

		if( atomType[i] == 7 ) {
			for(int bondOrder = 1; bondOrder <= 3; bondOrder++ ) {
				mol = read_xyz(filename);
				std::string outfile = filename;
    		addAtom(mol, 1, 2, bondOrder, atomType[i]);
				outfile = write_xyz(mol, outfile, atomLabel[i], bondOrder);
			}
		}

		if( atomType[i] == 8 ) {
			for(int bondOrder = 1; bondOrder <= 2; bondOrder++ ) {
				mol = read_xyz(filename);
				std::string outfile = filename;
    		addAtom(mol, 1, 2, bondOrder, atomType[i]);
				outfile = write_xyz(mol, outfile, atomLabel[i], bondOrder);
			}
		}
	}
}

#endif
