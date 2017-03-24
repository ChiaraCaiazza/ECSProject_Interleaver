#include <string>
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Tester
{
	private:
		ifstream inputStream;
		ofstream outputStream;
		ofstream testStream;
		string nameofInputStream;
		string nameofOutputStream;
		string nameofTestStream;
		int turn;
		void storeATest(bitset<1024>, bitset<1024>);
		void openAStream(string);
	public:
		Tester();
		~Tester();
		string getAnInputLine();
		int checkInput(string);
		string hexToBits(string);
		bitset<1024> computeOutputBitSet(bitset<1024>);
		void wroteAResponse(bitset<1024>, bitset<1024>);
		
};