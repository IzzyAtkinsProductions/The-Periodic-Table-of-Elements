#include "elements.h"

template<typename T>
void EraseIfZero(T arg, vec_str &vec, int idx){
	if(arg == 0)
		vec.erase(vec.begin() + idx); 
}
 
unsigned int GetIndexByArg(vec_str &data, std::string query){
	vec_str::iterator it;
 
	it = std::find(data.begin(), data.end(), query);

	if (it != data.end())
		return it - data.begin();   
}

std::string PrintInfo(
		std::string symbol,
		std::string name, 
		std::string standardState,
		std::string chemicalGroupBlock,
		short yearDiscovered,
		i8 &atomicNumber, 
		int &atomicRadius,
		float &atomicMass,
		float &ionizationenergy,
		float &electronAffinity,
		float &electronegativity,
		float &meltingPoint,
		float &boilingPoint,
		float &density
    ) { 

	std::string information;

	// These will get erased from the vector if the argument equals zero.
	std::string arg7 = "Atomic Radius: " + std::to_string(atomicRadius);
	std::string arg9 = "Ionization Energy: " + std::to_string(ionizationenergy);
	std::string arg10 = "Electron Affinity: " + std::to_string(electronAffinity);
	std::string arg11 = "Electronegativity: " + std::to_string(electronegativity);
	std::string arg13 = "Boiling Point: " + std::to_string(boilingPoint);
	std::string arg14 = "Density: " + std::to_string(density);

	vec_str info {
		"Symbol: " + symbol,
		"Name: " + name,
		"Standard State: " + standardState,
		"Chemical Group Block: " + chemicalGroupBlock,
		"Year Discoverd: " + std::to_string(yearDiscovered),
		"Atomic Number: " + std::to_string(atomicNumber),
		arg7, 
		"Atomic Mass: " + std::to_string(atomicMass),
		arg9,      
		arg10,
		arg11,
		"Melting Point: " + std::to_string(meltingPoint),
		arg13,
		arg14,
	};

	EraseIfZero(atomicRadius, info, GetIndexByArg(info, arg7));
	EraseIfZero(ionizationenergy, info, GetIndexByArg(info, arg9));
	EraseIfZero(electronAffinity, info, GetIndexByArg(info, arg10));
	EraseIfZero(electronegativity, info, GetIndexByArg(info, arg11));
	EraseIfZero(boilingPoint, info, GetIndexByArg(info, arg13));
	EraseIfZero(density, info, GetIndexByArg(info, arg14));
	
	for(std::string &el : info){
		std::cout << el <<  std::endl;
		information = el;
	}
	
	std::cout << std::endl;
	return information;
}

