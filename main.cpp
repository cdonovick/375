#include "functions.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

LCS_tuple B_Large;
LCS_tuple B_Med;
LCS_tuple B_Small;

LCS_tuple P_Large;
LCS_tuple P_Med;
LCS_tuple P_Small;

LCS_tuple SP_Large;
LCS_tuple SP_Med;
LCS_tuple SP_Small;

LCS_tuple PB_Large;
LCS_tuple PB_Med;
LCS_tuple PB_Small;

LCS_tuple PP_Large;
LCS_tuple PP_Med;
LCS_tuple PP_Small;

LCS_tuple PSP_Large;
LCS_tuple PSP_Med;
LCS_tuple PSP_Small;

int main(int argc, char **argv) {
	if(argc != 4){
		cout << "Use The Following Formatting:\n";
		cout << "./submission largeInput.txt medInput.txt smallInput.txt\n";
		exit(0);
	}
	ifstream largeIn;
	ifstream medIn;
	ifstream smallIn;
	
	vector<string> largeVector;
	vector<string> medVector;
	vector<string> smallVector;
	
	largeIn.open(argv[1]);
	medIn.open(argv[2]);
	smallIn.open(argv[3]);
	
	string temp;
	
	while(largeIn >> temp){
		largeVector.push_back(temp);
	}
	while(medIn >> temp){
		medVector.push_back(temp);
	}
	while(smallIn >> temp){
		smallVector.push_back(temp);
	}
		
	return 0;
}

