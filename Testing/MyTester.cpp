#include <string>
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <cstdlib>
#include <cstdio>


#include "Tester.h"

using namespace std;



int main(int argc, char *argv[])
{
	bitset<1024> outputBitSet;
	string inputBuffer, inputbit;
	Tester tester ;

	for (;;)
	{

		inputBuffer = "";

		inputBuffer = tester.getAnInputLine();
		if (inputBuffer == "-1")
			return 1;

		/*check the input value*/
		if (tester.checkInput(inputBuffer) < 0)
		{
			cout << "The input value in input.txt is not a valid one!" << endl;
			cout << "Premere un tasto per continuare\n\n";
			getchar();
			return 1;
		}

		cout << "input value (" << inputBuffer.size() << " hex char):			" << inputBuffer << endl;

		inputbit = tester.hexToBits(inputBuffer);
		bitset<1024> inputBitSet(inputbit);
		cout << "\n\nThis is my  input bitset (" << inputBitSet.size() << " bits):		" << inputBitSet << endl;

		outputBitSet = tester.computeOutputBitSet(inputBitSet);
		cout << "\n\nThis is my  output bitset (" << outputBitSet.size() << " bits):		" << outputBitSet << endl;

		tester.wroteAResponse(inputBitSet, outputBitSet);
		cout << "Premere un tasto per continuare\n\n\n\n";
		getchar();
	}
	return 0;
}


