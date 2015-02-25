#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void open_input(ifstream &, string Input_File);
void open_output(ofstream &, string Output_File);
void print_output (ofstream &, long double* next);
void error(int errorNumber);

int N, CONSTANT=10;

int main()
{
	ifstream in_stream;        
    ofstream out_stream;
	
	string Input_File = "nayeem.in"; 
	string Output_File = "nayeem.out"; 
	
	open_input(in_stream, Input_File);
	open_output(out_stream, Output_File);
	
	string line;
	getline(in_stream,line);
	istringstream iss(line);
	iss >> N;
	
	if ( N < 1 ) {
		cout << "Error # 3: N value given is less than 1" << endl;
		system ("PAUSE");
		error(3);
		exit(1);
	
	} else {
			
	int M=CONSTANT*N;
	
	cout << "First " << M << " terms of Fibonacci series are :- " << endl;
		
	int c; long double first = 0, second = 1, next[M];
	
	for ( c = 0 ; c < M ; c++ )
	{
		if ( c <= 1 )
			next[c] = c;
		else
		{
			next[c] = first + second;
			first = second;
			second = next[c];
		}
	}
		
	print_output (out_stream, next);	
	
	in_stream.close();
	out_stream.close();
	
	return 0;	
		
	}
}


void print_output(ofstream & out_stream, long double* next) { 
	
	int R = N, C = CONSTANT; 
	int k = 0; long double twoArray[C][R];
	

	for ( int i  = 0; i < R; i++ ) { 
		
		for ( int j = 0; j < C; j++ ) {
			twoArray[i][j] = next [k];
			k++;
			cout << setfill(' ') << setw(1) << "|" << setw(15) << left << twoArray[i][j] << setw(1) << "\t";
			out_stream << setfill(' ') << setw(1) << "|" << setw(15) << left << twoArray[i][j] << "\t";
		}
		cout << endl;
		out_stream << endl;		
	}
	
	return; //finish void function with no return value
}

void open_input(ifstream & infile, string Input_File) {
	
	infile.open (Input_File.c_str());

	if (infile.fail()) //exit program if input file unable to be opened
	{
        cout << "Error # 1: Failed opening input file: " << Input_File << ", exiting program:\n";
        system ("PAUSE");
		error(1);
        exit(1);
	}
	
	return; //finish void function with no return value
}
	

void open_output(ofstream & outfile, string Output_File) {
	
	outfile.open (Output_File.c_str());
	
	if (outfile.fail()) //exit program if output file unable to be opened
	{
        cout << "Error # 2: Failed opening Output_File: " << Output_File << ", exiting program:\n";
        system ("PAUSE");
		error(2);
        exit(1);
	}
	
	return; //finish void function with no return value
}

void error(int errorNumber){
	
	ofstream ErrorFile;
	ErrorFile.open("nayeem.err");
	
    switch (errorNumber) {
		case 1 :
			ErrorFile << "Error # 1: Input file does not exist" <<endl;
			break;
    }
	
	switch (errorNumber) {
		case 2 :
			ErrorFile << "Error # 2: Output file does not exist" <<endl;
			break;
    }
	
	switch (errorNumber) {
		case 3 :
			ErrorFile << "Error # 3: N value less than 1" <<endl;
			break;
    }
		
	return; //finish void function with no return value	
}
