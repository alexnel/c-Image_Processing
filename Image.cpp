//Author: NLXALE001
//Project: C++ Assignment 4

#include "Image.h"
#include <math.h>

namespace NLXALE001 {

using namespace std;

	Image::Image()	{	// default constructor - define in .cpp
	
	}
	Image::~Image()	{	// destructor - define in .cpp file
		for (int i = 0; i<num; i++) {
			for (int j = 0; j<height; j++) {
				delete [] slices[i][j];
			}//end for j
			delete [] slices[i];
		}//end for i
	}

	unique_ptr<unsigned char[]> Image::readImage(string im)
	{
			//open heqader and extract data
	string headerfile = im + ".pgm";
	ifstream infile (headerfile.c_str());
	string line;
	if(!infile.is_open()){		//error handling
		cout << "Error, file not found" << endl;
		return 0;
	}
	
	int numlines=1;////////////////////////////////check this cause not sure if account for the 255 not being counted in the for loop
	int rows;
	int width;
	string line;
	getline(infile, line);

	while(line!="255")
	{
		numlines++;
		if (line[0]!="#")
		{
			istringstream iss(line);
        	iss >> rows;
        	iss >> width;
		}
		getline(infile, line);
	}
	infile.close();

	ifstream binfile (headerfile.c_str(), ios::in|ios::binary|ios::ate);

	for (int i=0; i<numlines; i++)
	{
		getline(binfile, line);
	}
	//next thing should be first line of binary


	unsigned char * arr = new unsigned char[height];

	for (int i = 0; i < height; ++i) {
		arr[i] = new unsigned char[width];
		
		file.read((char *)arr[i], width);
	}
	
	slices.push_back(arr);


	
	
	}
	void Image::add(string im1, string im2, std::string outName)
	{}
	void Image::sub(string im1, string im2, std::string outName)
	{}
	void Image::invert(string im1, std::string outName)
	{}
	void Image::mask(string im1, string im2, std::string outName)
	{}
	void Image::threshold(string im1, int f, std::string outName)
	{}
	void Image::copy(const Image & rhs)
	{}


    // define begin()/end() to get iterator to start and    
    // "one-past" end.    
    iterator Image::begin(void) { return iterator(data.get());}


    //copy construct is public
    iterator::iterator( const iterator & rhs) : ptr(rhs.ptr){}       
    // define overloaded ops: *, ++, --, =       
    iterator::iterator & operator=(const iterator & rhs){}      
	// other methods for iterator       


}
