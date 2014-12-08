#include "functions.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

LCS_tuple B_Large;
int B_Large_Time;
LCS_tuple B_Med;
int B_Med_Time;
LCS_tuple B_Small;
int B_Small_Time;

LCS_tuple P_Large;
int P_Large_Time;
LCS_tuple P_Med;
int P_Med_Time;
LCS_tuple P_Small;
int P_Small_Time;

LCS_tuple SP_Large;
int SP_Large_Time;
LCS_tuple SP_Med;
int SP_Med_Time;
LCS_tuple SP_Small;
int SP_Small_Time;

LCS_tuple PB_Large;
int PB_Large_Time;
LCS_tuple PB_Med;
int PB_Med_Time;
LCS_tuple PB_Small;
int PB_Small_Time;

LCS_tuple PP_Large;
int PP_Large_Time;
LCS_tuple PP_Med;
int PP_Med_Time;
LCS_tuple PP_Small;
int PP_Small_Time;

LCS_tuple PSP_Large;
int PSP_Large_Time;
LCS_tuple PSP_Med;
int PSP_Med_Time;
LCS_tuple PSP_Small;
int PSP_Small_Time;



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

	auto S1L = largeVector;
	auto S1M = medVector;
	auto S1S = smallVector;
	auto S2L = largeVector;
	auto S2M = medVector;
	auto S2S = smallVector;
	auto S3L = largeVector;
	auto S3M = medVector;
	auto S3S = smallVector;
	auto S4L = largeVector;
	auto S4M = medVector;
	auto S4S = smallVector;
	auto S5L = largeVector;
	auto S5M = medVector;
	auto S5S = smallVector;
	auto S6L = largeVector;
	auto S6M = medVector;
	auto S6S = smallVector;
	
	B_Large = AllPairsLCS_b(largeVector);
	
	
		
	return 0;
}

