#include "table.h"

PeriodicTable* GetBlockObject(std::string query){
    for(int i = 0; i < ARRAY_SIZE(elements); ++i){
        if(query == elements[i].symbol){
            return &elements[i];
        }
    }
}

void DisplayAll(){
    for(int i = 0; i < ARRAY_SIZE(elements); i++){
        PrintInfo(
            elements[i].symbol, 
            elements[i].name, 
            elements[i].standardState,
            elements[i].chemicalGroupBlock,
            elements[i].yearDiscovered,
            elements[i].atomicNumber,
            elements[i].atomicRadius,
            elements[i].atomicMass,
            elements[i].ionizationenergy,
            elements[i].electronAffinity,
            elements[i].electronegativity,
            elements[i].meltingPoint, 
            elements[i].boilingPoint,
            elements[i].density
        );
    }
}

void PeriodicTable::DisplayInfo(){
	PrintInfo(
		symbol, 
		name, 
		standardState,
		chemicalGroupBlock,
		yearDiscovered,
		atomicNumber,
		atomicRadius,
		atomicMass,
		ionizationenergy,
		electronAffinity,
		electronegativity,
		meltingPoint,
		boilingPoint,
		density
	);
}

void PeriodicTable::DrawAsciiBlock(){
	std::string atomicMaassLen = std::to_string(atomicMass);
	int atomicMaassStrLen = atomicMaassLen.length() - 2;

	std::cout << "-----------------" << std::endl; 
	std::cout << "|" << std::setw(2) << int(atomicNumber) << std::showpoint << std::setprecision(atomicMaassStrLen) << std::setw(11) << this->atomicMass << std::setw(3) <<"|" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|" << std::setw(7) << symbol << std::setw(9) <<"|" << std::endl;
	std::cout << "|" << std::setw(10) << name << std::right  << std::setw(6) << "|" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "-----------------" << std::endl;
}

std::string GetElement(std::string query){
	std::unordered_map<std::string, std::string> el;

	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		el[elements[i].symbol] = elements[i].name;
	}

	for(auto &pair : el){
    	std::string key = pair.first;
        std::string value = pair.second;

        if(query == key)
            return value;
    }
}
     
void PrintName(){
	std::unordered_map<std::string, std::string> GetElement;

	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		GetElement["$" + std::to_string(elements[i].atomicNumber)] = elements[i].name;
    }

	for(const auto& pair : GetElement){   
        std::string key = pair.first;
        std::string value = pair.second;
        FindAndReplaceAll(mappedNumberedTable, key, value);
    }
	
    std::cout << mappedNumberedTable << "\n";              
}

void PrintTable(){
	std::string input;
	std::cout << "Enter Name or Symbol\n";
	std::cin >> input;
	system("cls");

    if(input == "symbol")
        std::cout << elementSymbols << std::endl;
    else if(input == "name")
    	PrintName();
}

void DisplaySlideshow(){
    std::string elementBlocks[elementAmt] = {HBlock, HeBlock, LiBlock}; 
    
    while(true){ 
        for (int i  = 0; i < elementAmt; i++){
            std::cout << elementBlocks[i] << std::endl;

            Sleep(1000);
            system("cls"); 
        }
		
		std::cout << tableBlocks;
        int input;
        std::cout << "Press 9 to exit\n";
        std::cin >> input;
        system("cls");

        if(input = 9){
            break;
        }
    } 
}

void GetElementFacts(std::string element = ""){
    str_vec_umap elementFacts = {
        {"Hydrogen", hydrogenFacts}, {"Helium", heliumnFacts},     
    };
    
    str_vec_umap::iterator it; 
        
    for(it = elementFacts.begin(); it != elementFacts.end(); ++it){
        std::string key = (*it).first;
        std::vector<std::string> value = (*it).second;
        
        auto result = [&]() { 
            std::cout << key << ": ";
            for (unsigned j = 0; j < value.size(); j++){ 
                std::cout << value[j] << " ";
            }
            std::cout << "\n" << std::endl; 
        };  

        if(element == key){
            result();
		} 
        else if(element == ""){
            result();
        }
    }
} 

unsigned char GetAtomicNumber(const char* query){
	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		if(elements[i].symbol == query)
			return elements[i].atomicNumber;
	}
}

std::string FilterElements(Fields field, std::string query){
	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		std::string item;

		switch(field){
			case NAME: {
				item = elements[i].name;
				break;
			}
			
			case SYMBOL: {
				item = elements[i].symbol;
				break;
			}
			
			case ATOMIC_NUMBER: {
				item = std::to_string(elements[i].atomicNumber);
				break;
			}
			
			case STANDARD_STATE: {
				item = elements[i].standardState;
				break;
			}

			case CHEMIICAL_GROUP_BLOCK: {
				item = elements[i].chemicalGroupBlock; 
				break;
			}

			default:
				break;
		}
		 
		if(item == query){
			std::string result = elements[i].name;
			std::cout << result << std::endl; 
			return result;
		}
	}
}

void Filter(std::string query){
	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		if(query == elements[i].symbol || query == elements[i].name || query == std::to_string(elements[i].atomicNumber)){
			std::cout << "\n";
			PrintInfo(
				elements[i].symbol, 
				elements[i].name, 
				elements[i].standardState,
				elements[i].chemicalGroupBlock,
				elements[i].yearDiscovered,
				elements[i].atomicNumber,
				elements[i].atomicRadius,
				elements[i].atomicMass,
				elements[i].ionizationenergy,
				elements[i].electronAffinity,
				elements[i].electronegativity,
				elements[i].meltingPoint, 
				elements[i].boilingPoint,
				elements[i].density
        	);
		}
	}
}
    
void WriteCSV(){
	std::ofstream csvFile;
	csvFile.open("Table of Elements.csv");

	for(int i = 0; i < ARRAY_SIZE(elementFields); i++){
		csvFile << elementFields[i] << ",";
	}
  
	for(int i = 0; i < ARRAY_SIZE(elements); i++){
 
		std::string discovered = elements[i].yearDiscovered == ANCIENT ? "Ancient" : std::to_string(elements[i].yearDiscovered); 

		csvFile << int(elements[i].atomicNumber) << "," 
				<< elements[i].symbol << "," 
				<< elements[i].name << "," 
				<< elements[i].standardState << "," 
				<< elements[i].chemicalGroupBlock << "," 
				<< elements[i].atomicRadius << "," 
				<< elements[i].atomicMass << "," 
				<< elements[i].ionizationenergy << ","
				<< elements[i].electronegativity << ","
				<< elements[i].electronAffinity << ","
				<< elements[i].meltingPoint << ","
				<< elements[i].boilingPoint << ","
				<< discovered << "\n";
	}

	csvFile.close();
}

void GetChemGroupAmount(std::string chemGroup){
	int count = 0;

	for(int i = 0; i < ARRAY_SIZE(elements); i++){
		if(elements[i].chemicalGroupBlock ==  chemGroup){
			count++;
		}
	}
	std::cout <<  chemGroup << ": " << count << std::endl;
}

void ChemGroupAmount(){
	for(int i = 0; i < ARRAY_SIZE(chemicalGroups); i++){
		GetChemGroupAmount(chemicalGroups[i]);
	}
}
