#include "functions.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

LCS_tuple B_Large;
unsigned long B_Large_Time;
LCS_tuple B_Med;
unsigned long B_Med_Time;
LCS_tuple B_Small;
unsigned long B_Small_Time;

LCS_tuple P_Large;
unsigned long P_Large_Time;
LCS_tuple P_Med;
unsigned long P_Med_Time;
LCS_tuple P_Small;
unsigned long P_Small_Time;

LCS_tuple SP_Large;
unsigned long SP_Large_Time;
LCS_tuple SP_Med;
unsigned long SP_Med_Time;
LCS_tuple SP_Small;
unsigned long SP_Small_Time;

LCS_tuple PB_Large;
unsigned long PB_Large_Time;
LCS_tuple PB_Med;
unsigned long PB_Med_Time;
LCS_tuple PB_Small;
unsigned long PB_Small_Time;

LCS_tuple PP_Large;
unsigned long PP_Large_Time;
LCS_tuple PP_Med;
unsigned long PP_Med_Time;
LCS_tuple PP_Small;
unsigned long PP_Small_Time;

LCS_tuple PSP_Large;
unsigned long PSP_Large_Time;
LCS_tuple PSP_Med;
unsigned long PSP_Med_Time;
LCS_tuple PSP_Small;
unsigned long PSP_Small_Time;

void printTimes(){
	cout << "Format:\nFunctionType:\n\tLargeTime\n\tMediumTime\n\tSmallTime\n\n";
	
	cout << "All Pairs LCS Base:\n";
	cout << "\t" << B_Large_Time << endl;
	cout << "\t" << B_Med_Time << endl;
	cout << "\t" << B_Small_Time << endl;
	
	cout << "All Pairs LCS w/ Pruning:\n";
	cout << "\t" << P_Large_Time << endl;
	cout << "\t" << P_Med_Time << endl;
	cout << "\t" << P_Small_Time << endl;
	
	cout << "All Pairs LCS w/ Sorting:\n";
	cout << "\t" << SP_Large_Time << endl;
	cout << "\t" << SP_Med_Time << endl;
	cout << "\t" << SP_Small_Time << endl;
	
	cout << "All Pairs LCS w/ Preallocation:\n";
	cout << "\t" << PB_Large_Time << endl;
	cout << "\t" << PB_Med_Time << endl;
	cout << "\t" << PB_Small_Time << endl;
	
	cout << "All Pairs LCS w/ Preallocation and Pruning:\n";
	cout << "\t" << PP_Large_Time << endl;
	cout << "\t" << PP_Med_Time << endl;
	cout << "\t" << PP_Small_Time << endl;

	cout << "All Pairs LCS w/ Preallocation and Sorting:\n";
	cout << "\t" << PSP_Large_Time << endl;
	cout << "\t" << PSP_Med_Time << endl;
	cout << "\t" << PSP_Small_Time << endl;
}

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
	
	B_Large_Time = time(0);
	B_Large = AllPairsLCS_b(S1L);
	B_Large_Time = time(0) - B_Large_Time;
	
	B_Med_Time = time(0);
	B_Med = AllPairsLCS_b(S1M);
	B_Med_Time = time(0) - B_Med_Time;

	B_Small_Time = time(0);
	B_Small = AllPairsLCS_b(S1S);
	B_Small_Time = time(0) - B_Small_Time;	

	//***********************************************

	P_Large_Time = time(0);
	P_Large = AllPairsLCS_p(S2L);
	P_Large_Time = time(0) - P_Large_Time;

	P_Med_Time = time(0);
	P_Med = AllPairsLCS_p(S2M);
	P_Med_Time = time(0) - P_Med_Time;
	
	P_Small_Time = time(0);
	P_Small = AllPairsLCS_p(S2S);
	P_Small_Time = time(0) - P_Small_Time;

	//***********************************************

	SP_Large_Time = time(0);
	SP_Large = AllPairsLCS_s(S3L);
	SP_Large_Time = time(0) - SP_Large_Time;

	SP_Med_Time = time(0);
	SP_Med = AllPairsLCS_s(S3M);
	SP_Med_Time = time(0) - SP_Med_Time;

	SP_Small_Time = time(0);
	SP_Small = AllPairsLCS_s(S3S);
	SP_Small_Time = time(0) - SP_Small_Time;	

	//***********************************************

	PB_Large_Time = time(0);
	PB_Large = AllPairsLCS_pab(S4L);
	PB_Large_Time = time(0) - PB_Large_Time;

	PB_Med_Time = time(0);
	PB_Med = AllPairsLCS_pab(S4M);
	PB_Med_Time = time(0) - PB_Med_Time;
	
	PB_Small_Time = time(0);
	PB_Small = AllPairsLCS_pab(S4S);
	PB_Small_Time = time(0) - PB_Small_Time;

	//***********************************************
	
	PP_Large_Time = time(0);
	PP_Large = AllPairsLCS_pap(S5L);
	PP_Large_Time = time(0) - PP_Large_Time;

	PP_Med_Time = time(0);
	PP_Med = AllPairsLCS_pap(S5M);
	PP_Med_Time = time(0) - PP_Med_Time;

	PP_Small_Time = time(0);
	PP_Small = AllPairsLCS_pap(S5S);
	PP_Small_Time = time(0) - PP_Small_Time;
	
	//***********************************************

	PSP_Large_Time = time(0);	
	PSP_Large = AllPairsLCS_pas(S6L);
	PSP_Large_Time = time(0) - PSP_Large_Time;

	PSP_Med_Time = time(0);
	PSP_Med = AllPairsLCS_pas(S6M);
	PSP_Med_Time = time(0) - PSP_Med_Time;

	PSP_Small_Time = time(0);
	PSP_Small = AllPairsLCS_pas(S6S);
	PSP_Small_Time = time(0) - PSP_Small_Time;
	
	printTimes();
		
	return 0;
}

