//Author: NLXALE001
//Project: C++ Assignment 4

#include "Image.h"
#include <math.h>

using namespace std;

namespace NLXALE001 {


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

	Image::Image(Image&& move): width(move.width), height(move.height){
		unsigned char* buffer = new unsigned char[width*height];
		for (int i=0; i<width*height; i++)
		{
			buffer[i]=move.data[i];
		}
		data.reset(buffer);

		move.width=0;
		move.height=0;
		move.data=nullptr;
	}

	Image::Image(int w, int h, unsigned char*buffer):width(w), height(h)
	{	data.reset(buffer);	}
	Image::~Image()	{	// destructor - define in .cpp file
		}//end for i
	

	bool Image::readImage(string im)
		{
				//open heqader and extract data
		string headerfile = im + ".pgm";
		ifstream infile (headerfile.c_str());
		if(!infile.is_open()){		//error handling
			cout << "Error, file not found" << endl;
			return false;
		}
	
		int numlines=1;//////////////////////////////check this cause not sure if account for the 255 not being counted in the for loop
		string line;
		getline(infile, line);
		while(line!="255")
		{
			numlines++;
			if (line.at(0)!='#' && line!="P5")/////////////////////////doesn't like this
			{
				istringstream iss(line);
	        	iss >> height;
	        	iss >> width;
	        	cout << height << endl;
	        	cout << width << endl;
			}
			getline(infile, line);
		}
		infile.close();

		ifstream binfile (headerfile.c_str(), ios::in|ios::binary);	

		//ostringstream oss;
		for (int i=0; i<numlines; i++)
		{
			getline(binfile, line);
			cout << line << endl;
		}
		//next thing should be first line of binary

		//oss << binfile.rdbuf();

		data.reset(new unsigned char[width*height]);
		skipws(binfile);

		binfile.read((char*)&data[0], width*height);

		binfile.close();


		return true;

	}
	
	void Image::saveFile(string outName)
	{
		string headerfile = outName + ".pgm";
		ofstream binfile (headerfile.c_str(), ios::out|ios::binary);

		binfile<<"P5"<<endl;
		binfile<<"# Image Processing Output File"<<endl;
		binfile<< height<< " "<< width<< endl;
		binfile<<"255"<<endl;
		
		unsigned char byte;
		for (auto i=this->begin(); i!=end(); ++i)
		{
			byte = *i;
			binfile.write((char*)&byte, 1);
		}
		binfile.close();
	}

	Image::iterator::iterator(unsigned char *p):ptr(p){}

    // define begin()/end() to get iterator to start and    
    // "one-past" end.    
    Image::iterator Image::begin(void)const { return iterator(&(data.get()[0]));}
	Image::iterator Image::end(void)const { return iterator(&(data.get()[width*height]));}
    //copy construct is public
    //iterator::iterator( const iterator & rhs) : ptr(rhs.ptr){}     
	// other methods for iterator       


}
