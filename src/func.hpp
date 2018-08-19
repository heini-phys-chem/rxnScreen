#include <stdio.h> 
#include <iostream>
#include <string.h>
#include <sstream>

OpenBabel::OBMol read_xyz(std::string filename);

std::string write_xyz(OpenBabel::OBMol &mol, std::string filename, std::string atomLabel, int bondOrder);

void biatomics(OpenBabel::OBMol mol, std::vector<int> atomType, std::vector<std::string> atomLabel);

void addAtom(OpenBabel::OBMol &mol, int atomA, int atomB, int bondOrder, int Z);
