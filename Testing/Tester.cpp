#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Tester.h"

using namespace std;


/*discover if non-hex character are present*/
int findForbiddenChar(string inputString)
{
	if (inputString.find('g', 0) != std::string::npos || inputString.find('G', 0) != std::string::npos ||
		inputString.find('h', 0) != std::string::npos || inputString.find('H', 0) != std::string::npos ||
		inputString.find('i', 0) != std::string::npos || inputString.find('I', 0) != std::string::npos ||
		inputString.find('j', 0) != std::string::npos || inputString.find('J', 0) != std::string::npos ||
		inputString.find('k', 0) != std::string::npos || inputString.find('K', 0) != std::string::npos ||
		inputString.find('l', 0) != std::string::npos || inputString.find('L', 0) != std::string::npos ||
		inputString.find('m', 0) != std::string::npos || inputString.find('M', 0) != std::string::npos ||
		inputString.find('n', 0) != std::string::npos || inputString.find('N', 0) != std::string::npos ||
		inputString.find('o', 0) != std::string::npos || inputString.find('O', 0) != std::string::npos ||
		inputString.find('p', 0) != std::string::npos || inputString.find('P', 0) != std::string::npos ||
		inputString.find('q', 0) != std::string::npos || inputString.find('Q', 0) != std::string::npos ||
		inputString.find('r', 0) != std::string::npos || inputString.find('R', 0) != std::string::npos ||
		inputString.find('s', 0) != std::string::npos || inputString.find('S', 0) != std::string::npos ||
		inputString.find('t', 0) != std::string::npos || inputString.find('T', 0) != std::string::npos ||
		inputString.find('u', 0) != std::string::npos || inputString.find('U', 0) != std::string::npos ||
		inputString.find('v', 0) != std::string::npos || inputString.find('V', 0) != std::string::npos ||
		inputString.find('w', 0) != std::string::npos || inputString.find('W', 0) != std::string::npos ||
		inputString.find('z', 0) != std::string::npos || inputString.find('Z', 0) != std::string::npos ||
		inputString.find('y', 0) != std::string::npos || inputString.find('Y', 0) != std::string::npos ||
		inputString.find('!', 0) != std::string::npos || inputString.find('"', 0) != std::string::npos ||
		inputString.find('£', 0) != std::string::npos || inputString.find('$', 0) != std::string::npos ||
		inputString.find('%', 0) != std::string::npos || inputString.find('&', 0) != std::string::npos ||
		inputString.find('/', 0) != std::string::npos || inputString.find('(', 0) != std::string::npos ||
		inputString.find(')', 0) != std::string::npos || inputString.find('=', 0) != std::string::npos ||
		inputString.find('\'', 0) != std::string::npos || inputString.find('?', 0) != std::string::npos ||
		inputString.find('^', 0) != std::string::npos || inputString.find('ì', 0) != std::string::npos ||
		inputString.find('è', 0) != std::string::npos || inputString.find('é', 0) != std::string::npos ||
		inputString.find('[', 0) != std::string::npos || inputString.find(']', 0) != std::string::npos ||
		inputString.find('{', 0) != std::string::npos || inputString.find('}', 0) != std::string::npos ||
		inputString.find('ò', 0) != std::string::npos || inputString.find('ç', 0) != std::string::npos ||
		inputString.find('@', 0) != std::string::npos || inputString.find('à', 0) != std::string::npos ||
		inputString.find('°', 0) != std::string::npos || inputString.find('#', 0) != std::string::npos ||
		inputString.find('ù', 0) != std::string::npos || inputString.find('§', 0) != std::string::npos ||
		inputString.find(',', 0) != std::string::npos || inputString.find(';', 0) != std::string::npos ||
		inputString.find('.', 0) != std::string::npos || inputString.find(':', 0) != std::string::npos ||
		inputString.find('-', 0) != std::string::npos || inputString.find('_', 0) != std::string::npos ||
		inputString.find('*', 0) != std::string::npos || inputString.find('+', 0) != std::string::npos ||
		inputString.find('\\', 0) != std::string::npos || inputString.find('|', 0) != std::string::npos)
	{
		/*a non-hex char was found*/
		return -1;
	}
			
	/*return without error*/
	return 1;
}


Tester::Tester()
{
	/*turn is the position of an input in the input file.
	  it starts from 1*/
	turn = 1;

	/*set the file name*/
	nameofInputStream = "input.txt";
	/* open the input file */
	openAStream("input");

	/*now the input file is open*/
	cout << "opening input file...  DONE" << endl;
}


Tester::~Tester()
{
	/* I close the file */
	inputStream.close();
	cout << "\n\nclosing input file...  DONE" << endl;

	cout << "Premere un tasto per continuare\n\n";
	getchar();
	exit(0);
}


string Tester::getAnInputLine()
{
	string inputBuffer;

	if (!inputStream.eof())
	{
		/*if the input file is not empty, then I read a line*/
		getline(inputStream, inputBuffer);
	}
	else
	{
		/*otherwise I terminate*/
		cout << "input.txt -> EOF\n" << endl;
		cout << "Premere un tasto per continuare\n\n";
		getchar();
		return "-1";
	}

	return inputBuffer;
}


/*
Perform a check on the value input.
Return 0 if a value on 1024 bit is retrieved, otherwise return -1
*/
int Tester::checkInput(string inputString)
{
	if (inputString.size() > 256)
		return -1;

	if (findForbiddenChar (inputString) < 0)
		return -1;

	return 0;
}


/*convert frm hex notation to bits*/
string Tester::hexToBits(string inputhex)
{	
	static char inputbits[1024];
	int i, index;
	char c;


	while (inputhex.size() < 256)
	{
		inputhex = '0' + inputhex;
	}

	i = 1023;
	index =255;
	do
	{
		c=  *inputhex.substr(index, 1).c_str();
		
		switch (c)
		{
		case '0': 
			inputbits[i - 3]= '0';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '0';
			inputbits[i] = '0';
			break;
		case '1': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '0';
			inputbits[i] = '1';
			break;
		case '2': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '1';
			inputbits[i] = '0';
			break;
		case '3': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '1';
			inputbits[i] = '1';
			break;
		case '4':
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '0';
			inputbits[i] = '0';
			break;
		case '5': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '0';
			inputbits[i] = '1';
			break;
		case '6': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '1';
			inputbits[i] = '0';
			break;
		case '7': 
			inputbits[i - 3] = '0';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '1';
			inputbits[i] = '1';
			break;
		case '8': 
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '0';
			inputbits[i] = '0';
			break;
		case '9': 
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '0';
			inputbits[i] = '1';
			break;
		case 'A': case 'a':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '1';
			inputbits[i] = '0';
			break;
		case 'B': case 'b':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '0';
			inputbits[i - 1] = '1';
			inputbits[i] = '1';
			break;
		case 'C': case 'c':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '0';
			inputbits[i] = '0';
			break;
		case 'D': case 'd':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '0';
			inputbits[i] = '1';
			break;
		case 'E': case 'e':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '1';
			inputbits[i] = '0';
			break;
		case 'F': case 'f':
			inputbits[i - 3] = '1';
			inputbits[i - 2] = '1';
			inputbits[i - 1] = '1';
			inputbits[i] = '1';
			break;
		}

		i=i-4;
		index --;
	} while (i >0);

	string ret(inputbits);
	return ret;
}


bitset<1024> Tester::computeOutputBitSet(bitset<1024> inputBitSet)
{
	bitset<1024> outputBitSet;
	int index;
	bool val;

	for (int i = 0; i < 1024; i++)
	{
		index = i * 3;
		index += 45;
		while (index >= 1024)
		{
			index -= 1024;
		}

		/*value of the i-th bit in input*/
		val = inputBitSet.test(i);
		/*set the index-th bit of the output*/
		outputBitSet.set(index, val);
		
	}
	return outputBitSet;
}


void Tester::wroteAResponse(bitset<1024> inputBitSet, bitset<1024> outputBitSet)
{
	bool value;
	char textVal;
	string s;

	s= to_string(turn);

	nameofOutputStream = "output-"+s+".txt";
	nameofTestStream = "interleaver_test-" + s + ".vhdl";

	cout << "\n\n\nOutput file name : " << nameofOutputStream << endl;
	cout << "Test file name : " << nameofTestStream << endl;

	/*open the output stream*/
	openAStream("output");
	/*open the test stream*/
	openAStream("tester");
	/*the output file is now opened*/
	cout << "opening output file...  DONE" << endl;
	/*the output file is now opened*/
	cout << "opening test file...  DONE" << endl;

	for (int i = 1023; i >= 0; i--)
	{
		value = inputBitSet.test(i);
		if (value == true)
			textVal = '1';
		else
			textVal = '0';

		outputStream << "input[" << i << "]\t" << value<<"\t\t\t";

		value = outputBitSet.test(i);
		if (value == true)
			textVal = '1';
		else
			textVal = '0';
		outputStream << "output[" << i << "]\t" << value << "\t\t\t" << endl;

	}

	cout << "\nWriting in output.txt...   DONE" << endl;
	/*save the test code*/
	storeATest(inputBitSet, outputBitSet);

	/*i close this output file*/
	outputStream.close();
	cout << "closing "<<nameofOutputStream<<"...  DONE" << endl;
	/*i close this test file*/
	testStream.close();
	cout << "closing " << nameofTestStream << "...  DONE\n\n" << endl;
	

	/*ready to store the next value!*/
	turn++;
}

void Tester::openAStream(string type)
{
	if (type.compare("input") == 0)
	{
		/*open the input stream*/
		inputStream.open(nameofInputStream);
		if (!inputStream.is_open())
		{
			perror("unable to open input file");
			cout << "Premere un tasto per continuare\n\n";
			getchar();
			exit(1);
		}
		return;
	}

	if (type.compare("output") == 0)
	{
		outputStream.open(nameofOutputStream, ios::trunc);
		if (!outputStream.is_open())
		{
			perror("unable to open the output file");
			cout << "Premere un tasto per continuare\n\n";
			getchar();
			exit(1);
		}
		return;
	}
		
	if (type.compare("tester") == 0)
	{
		testStream.open(nameofTestStream, ios::trunc);
		if (!testStream.is_open())
		{
			perror("unable to open the test file");
			cout << "Premere un tasto per continuare\n\n";
			getchar();
			exit(1);
		}
		return;
	}
}


void Tester::storeATest(bitset<1024> inputBitSet, bitset<1024> outputBitSet)
{
	int i;

	testStream	<<"------------------------------------------------------------------------------ -\n"
				<<"--Interleaver - TestBench\n"
				<<"--\n"
				<<"--File name : " << nameofTestStream << ".vhdl\n"
				<<"-- \n"
				<<"--Library : IEEE\n"
				<<"--Author: Chiara Caiazza\n" << endl;
	
	testStream	<< "\nLIBRARY IEEE;\n"
				<<"USE IEEE.STD_LOGIC_1164.ALL;\n"
				<<"USE IEEE.STD_LOGIC_ARITH.ALL;\n"
				<<"USE IEEE.STD_LOGIC_UNSIGNED.ALL;\n"
				<<"USE ieee.numeric_std.ALL;\n " << endl;
	
	testStream	<< "ENTITY interleaver_test IS\n\nEND interleaver_test;\n" << endl;


	testStream	<< "ARCHITECTURE interleaver_test_arch OF interleaver_test IS\n"
				<< "\tCOMPONENT interleaver IS" << endl;
		
	testStream	<< "\t\tport(\tclk : in std_logic;\t\t\t\t\t--Processing clock\n"
				<< "\t\t\t\treset : in  std_logic;\t\t\t\t--Asynchronous active high reset\n"
				<< "\t\t\t\tbit_in : in std_logic;\t\t\t\t--input bit\n"
				<< "\t\t\t\tbit_out : out std_logic\t\t\t\t--outputbit\n"
				<< "\t\t);\n"
				<< "\tEND COMPONENT interleaver;";

	testStream << "\n\n\n\t--CONSTANT" << endl;
	testStream << "\tCONSTANT clock_period : TIME := 200 ns;\n"
				<< "\tCONSTANT len : INTEGER := 2049;\n" << endl;

	testStream	<< "\n\t--INPUT SIGNALS" << endl;
	testStream	<< "\tSIGNAL clock : std_logic := '0';\n"
				<< "\tSIGNAL rst : std_logic := '1';\n"
				<< "\tSIGNAL bit_input : std_logic := '0';" << endl;

	testStream	<< "\n\n\t--OUTPUT SIGNALS" << endl;
	testStream	<< "\tSIGNAL bit_output : std_logic := 'Z';\n\n"
				<< "\tSIGNAL clock_cycle : INTEGER;\n"
				<< "\tSIGNAL testing: Boolean :=True;\n" << endl;
		
	testStream	<< "\tBEGIN\n"
				<< "\t\tI: interleaver PORT MAP(clk => clock, reset => rst, bit_in => bit_input, bit_out =>bit_output);\n"<<endl;

	testStream	<< "--Generates clk\n"
				<< "\t\tclock <=NOT clock AFTER clock_period/2 WHEN testing ELSE '0';\n" << endl;

	testStream	<< "\t\t--Runs simulation for len cycles\n"
				<< "\t\tproc_test: PROCESS(clock)\n"
				<< "\t\t\tVARIABLE count: INTEGER:= 0;\n"
				<< "\t\t\tBEGIN\n"
				<< "\t\t\t\tclock_cycle <= (count+1)/2;\n"
				<< "\t\t\t\tCASE count IS" << endl;

	testStream	<< "\t\t\t\t\t-- reset \n"
				<<"\t\t\t\t\tWHEN\t0\t=>\trst<='1';\n"
				<< "\n\t\t\t\t\t-- starting input\n"
				<< "\t\t\t\t\tWHEN\t" << 1 << "\t=>\tbit_input<='" << inputBitSet[0] << "';rst<='0';" << endl;
	for ( i = 2; i < 1025; i++)
	{
		testStream << "\t\t\t\t\tWHEN\t" << i << "\t=>\tbit_input<='" << inputBitSet[i-1] << "';" << endl;
	}
	testStream	<< "\n\t\t\t\t\t-- starting output\n" << endl;
	for (i = 1025; i < 2049; i++)
	{
		testStream << "\t\t\t\t\tWHEN\t" << i << "\t=>\tbit_input<='Z';" << endl;
	}
	
	testStream	<< "\t\t\t\t\tWHEN\tlen \t=>\ttesting<=False;\n"
				<< "\t\t\t\t\tWHEN\tOTHERS\t=>\tNULL;\n"
				<< "\t\t\t\tEND CASE;\n"
				<<"\t\t\t\tif clock = '1' and clock'event then \n" 
				<<"\t\t\t\t\tcount:= count + 1;\n"
				<<"\t\t\t\tEND IF;\n\n"
				<< "\t\tEND PROCESS proc_test;\n"
				<< "END interleaver_test_arch;";
}