#include "functions.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/time.h>

using namespace std;

LCS_tuple B_Large;
double B_Large_Time;
LCS_tuple B_Med;
double B_Med_Time;
LCS_tuple B_Small;
double B_Small_Time;

LCS_tuple P_Large;
double P_Large_Time;
LCS_tuple P_Med;
double P_Med_Time;
LCS_tuple P_Small;
double P_Small_Time;

LCS_tuple SP_Large;
double SP_Large_Time;
LCS_tuple SP_Med;
double SP_Med_Time;
LCS_tuple SP_Small;
double SP_Small_Time;

LCS_tuple PB_Large;
double PB_Large_Time;
LCS_tuple PB_Med;
double PB_Med_Time;
LCS_tuple PB_Small;
double PB_Small_Time;

LCS_tuple PP_Large;
double PP_Large_Time;
LCS_tuple PP_Med;
double PP_Med_Time;
LCS_tuple PP_Small;
double PP_Small_Time;

LCS_tuple PSP_Large;
double PSP_Large_Time;
LCS_tuple PSP_Med;
double PSP_Med_Time;
LCS_tuple PSP_Small;
double PSP_Small_Time;

void printTuple(LCS_tuple data){
	cout << get<0>(data) << " " << get<1>(data) << " " << get<2>(data) << endl;
}

void printResults(){
	cout << "\nResults Format:\t LongestStringA LongestStringB LCS_Length\n\n";
	
	cout << "All Pairs LCS Base:\n";
	cout << "\tLarge Input: ";
	printTuple(B_Large);
	cout << "\tMedium Input: ";
	printTuple(B_Med);
	cout << "\tSmall Input: ";
	printTuple(B_Small);
	
	cout << "All Pairs LCS w/ Pruning:\n";
	cout << "\tLarge Input: ";
	printTuple(P_Large);
	cout << "\tMedium Input: ";
	printTuple(P_Med);
	cout << "\tSmall Input: ";
	printTuple(P_Small);
	
	cout << "All Pairs LCS Base w/ Sorting:\n";
	cout << "\tLarge Input: ";
	printTuple(SP_Large);
	cout << "\tMedium Input: ";
	printTuple(SP_Med);
	cout << "\tSmall Input: ";
	printTuple(SP_Small);
	
	cout << "All Pairs LCS Base w/ Preallocation:\n";
	cout << "\tLarge Input: ";
	printTuple(PB_Large);
	cout << "\tMedium Input: ";
	printTuple(PB_Med);
	cout << "\tSmall Input: ";
	printTuple(PB_Small);
	
	cout << "All Pairs LCS Base w/ Preallocation and Pruning:\n";
	cout << "\tLarge Input: ";
	printTuple(PP_Large);
	cout << "\tMedium Input: ";
	printTuple(PP_Med);
	cout << "\tSmall Input: ";
	printTuple(PP_Small);
	
	cout << "All Pairs LCS Base w/ Preallocation and Sorting:\n";
	cout << "\tLarge Input: ";
	printTuple(PSP_Large);
	cout << "\tMedium Input: ";
	printTuple(PSP_Med);
	cout << "\tSmall Input: ";
	printTuple(PSP_Small);
	
}

void printTimes(){
	cout << "\nInput Format:\nFunctionType:\n\tLargeTime\n\tMediumTime\n\tSmallTime\n\n";
	
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
	
	struct timeval timer;
	
	gettimeofday(&timer,NULL);
	B_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	B_Large = AllPairsLCS_b(S1L);
	gettimeofday(&timer,NULL);
	B_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - B_Large_Time;
	
	gettimeofday(&timer,NULL);
	B_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	B_Med = AllPairsLCS_b(S1M);
	gettimeofday(&timer,NULL);
	B_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - B_Med_Time;

	gettimeofday(&timer,NULL);
	B_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	B_Small = AllPairsLCS_b(S1S);
	gettimeofday(&timer,NULL);
	B_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - B_Small_Time;	

	//***********************************************

	gettimeofday(&timer,NULL);
	P_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	P_Large = AllPairsLCS_p(S2L);
	gettimeofday(&timer,NULL);
	P_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - P_Large_Time;

	gettimeofday(&timer,NULL);
	P_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	P_Med = AllPairsLCS_p(S2M);
	gettimeofday(&timer,NULL);
	P_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - P_Med_Time;
	
	gettimeofday(&timer,NULL);
	P_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	P_Small = AllPairsLCS_p(S2S);
	gettimeofday(&timer,NULL);
	P_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - P_Small_Time;

	//***********************************************

	gettimeofday(&timer,NULL);
	SP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	SP_Large = AllPairsLCS_s(S3L);
	gettimeofday(&timer,NULL);
	SP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - SP_Large_Time;

	gettimeofday(&timer,NULL);
	SP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	SP_Med = AllPairsLCS_s(S3M);
	gettimeofday(&timer,NULL);
	SP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - SP_Med_Time;

	gettimeofday(&timer,NULL);
	SP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	SP_Small = AllPairsLCS_s(S3S);
	gettimeofday(&timer,NULL);
	SP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - SP_Small_Time;	

	//***********************************************

	gettimeofday(&timer,NULL);
	PB_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PB_Large = AllPairsLCS_pab(S4L);
	gettimeofday(&timer,NULL);
	PB_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PB_Large_Time;

	gettimeofday(&timer,NULL);
	PB_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PB_Med = AllPairsLCS_pab(S4M);
	gettimeofday(&timer,NULL);
	PB_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PB_Med_Time;
	
	gettimeofday(&timer,NULL);
	PB_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PB_Small = AllPairsLCS_pab(S4S);
	gettimeofday(&timer,NULL);
	PB_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PB_Small_Time;

	//***********************************************
	
	gettimeofday(&timer,NULL);
	PP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PP_Large = AllPairsLCS_pap(S5L);
	gettimeofday(&timer,NULL);
	PP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PP_Large_Time;

	gettimeofday(&timer,NULL);
	PP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PP_Med = AllPairsLCS_pap(S5M);
	gettimeofday(&timer,NULL);
	PP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PP_Med_Time;

	gettimeofday(&timer,NULL);
	PP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PP_Small = AllPairsLCS_pap(S5S);
	gettimeofday(&timer,NULL);
	PP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PP_Small_Time;
	
	//***********************************************

	gettimeofday(&timer,NULL);
	PSP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0);	
	PSP_Large = AllPairsLCS_pas(S6L);
	gettimeofday(&timer,NULL);
	PSP_Large_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PSP_Large_Time;

	gettimeofday(&timer,NULL);
	PSP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PSP_Med = AllPairsLCS_pas(S6M);
	gettimeofday(&timer,NULL);
	PSP_Med_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PSP_Med_Time;

	gettimeofday(&timer,NULL);
	PSP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0);
	PSP_Small = AllPairsLCS_pas(S6S);
	gettimeofday(&timer,NULL);
	PSP_Small_Time = timer.tv_sec+(timer.tv_usec/1000000.0) - PSP_Small_Time;
	
	printTimes();
	printResults();
		
	return 0;
}

