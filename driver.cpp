//Author: NLXALE001
//Project: C++ Assignment 4

#include "Image.h"

using namespace std;
using namespace NLXALE001;

int main(int argc, char* argv[]) {
	
	Image v;
	
	if(argc==5 && string(argv[1])=="-a")	{	//-d flag, send to add
		string first = string(argv[2]);
		string second = string(argv[3]);
		string outName = string(argv[4]);
		v.add(first, second, outName);
	}
	else if(argc==5 && string(argv[1])=="-s")	{	//-x flag, send to subtract
		string first = string(argv[2]);
		string second = string(argv[3]);
		string outName = string(argv[4]);
		v.sub(first, second, outName);
	}
	else if(argc==4 && string(argv[1])=="-i")	{	//-x flag, send to invert
		string first = string(argv[2]);
		string outName = string(argv[3]);
		v.invert(first, outName);
	}
	else if(argc==5 && string(argv[1])=="-l")	{	//-x flag, send to mask
		string first = string(argv[2]);
		string second = string(argv[3]);
		string outName = string(argv[4]);
		v.mask(first, second, outName);
	}
	else if(argc==5 && string(argv[1])=="-t")	{	//-x flag, send to threshold
		string first = string(argv[2]);
		istringstream iss2(argv[3]);
		int f;
		iss2 >> f;
		string outName = string(argv[4]);
		v.threshold(first, f, outName);
	}
	else {
		cout << "Invalid flags" << endl;
	}
	return 0;
}