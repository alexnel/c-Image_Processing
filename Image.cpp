//Author: NLXALE001
//Project: C++ Assignment 4

#include "Image.h"
#include <math.h>

namespace NLXALE001 {

using namespace std;

	Image::Image(string im)	{	// default constructor - define in .cpp
		readImage(im);
	}

	 //copy constructor
	Image::Image(const Image& copy):width(copy.width), height(copy.height){
		unsigned char* buffer = new unsigned char[width*height];
		for(int j =0; j< height*width; j++){
			buffer[j] = copy.data[j];
		}
		data.reset(buffer);
	}

	Image::~Image()	{	// destructor - define in .cpp file
		}//end for i
	}

	Image Image::readImage(string im)
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


		data.reset(new unsigned char[width*height]);

		binfile.read((char)&data[0], width*height);

		binfile.close();

	}
	// void Image::add(string im1, string im2, std::string outName)
	// {
	// 	data.reset(im1+im2);
	// }
	// void Image::sub(string im1, string im2, std::string outName)
	// {
	// 	data.reset(im1-im2);
	// }
	// void Image::invert(string im1, std::string outName)
	// {
	// 	data.reset(!im1);
	// }
	// void Image::mask(string im1, string im2, std::string outName)
	// {
	// 	data.reset(im1/im2);
	// }
	// void Image::threshold(string im1, int f, std::string outName)
	// {
	// 	data.reset(*im1);
	// }
	void Image::copy(const Image & rhs)
	{}
	void Image::saveFile(string outName)
	{
		string headerfile = outName + ".pgm";
		ofstream binfile (headerfile.c_str(), ios::in|ios::binary);

		binfile<<"P5"<<endl;
		binfile<<"# Image Processing Output File"<<endl;
		binfile<< height<< " "<< width<< endl;
		binfile<<"255"<<endl;
		int size = width*height;
		//binfile.write(*data, size);		///////////////////////////////////////////////////////////////////////////use iterator here
		binfile.close();
	}

    // define begin()/end() to get iterator to start and    
    // "one-past" end.    
    Image::iterator Image::begin(void)const { return iterator(&(data.get()[0]));}
	Image::iterator Image::end(void)const { return iterator(&(data.get()[width*height]));}

	Image::iterator::iterator(unsigned char *p):ptr(p){};
    //copy construct is public
    iterator::iterator( const iterator & rhs) : ptr(rhs.ptr){}       
    // define overloaded ops: *, ++, --, =       
    iterator::iterator & operator=(const iterator & rhs){}      
	// other methods for iterator       


}
