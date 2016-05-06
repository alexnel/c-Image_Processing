//Author: NLXALE001
//Project: C++ Assignment 4

/**
*.h file:
*/
#ifndef IMAGE_H
#define IMAGE_H
//any includes here 
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

namespace NLXALE001 {

using namespace std;

class Image
{
private:
	int width, height;
	unique_ptr<unsigned char[]> data;
public:

    Image();	// default constructor - define in .cpp
	~Image();	// destructor - define in .cpp file

	std::unique_ptr<unsigned char[]> readFile(string im);
	void add(string im1, string im2, std::string outName);
	void sub(string im1, string im2, std::string outName);
	void invert(string im1, std::string outName);
	void mask(string im1, string im2, std::string outName);
	void threshold(string im1, string im2, std::string outName);
	void Image::copy(const Image & rhs);

	// define begin()/end() to get iterator to start and    
    // "one-past" end. 
	iterator begin(void); 

	class iterator
	{
	private:
		unsigned char *ptr;
		// construct only via Image class (begin/end)
		iterator(u_char *p) : ptr(p) {}
	public:
	    //copy construct is public
	    iterator( const iterator & rhs) : ptr(rhs.ptr);        
	    // define overloaded ops: *, ++, --, =       
	    iterator & operator=(const iterator & rhs);       
   		// other methods for iterator   
    };    
       
   unique_ptr<unsigned char[]> & operator+(unique_ptr<unsigned char[]> & lhs, const unique_ptr<unsigned char[]> & rhs)
	{

		return result; 
	}

	unique_ptr<unsigned char[]> & operator-(unique_ptr<unsigned char[]> & lhs, const unique_ptr<unsigned char[]> & rhs)
	{

		return result; 
	}
	unique_ptr<unsigned char[]> & operator!(unique_ptr<unsigned char[]> & lhs)
	{

		return result; 
	}
	unique_ptr<unsigned char[]> & operator/(unique_ptr<unsigned char[]> & lhs, const unique_ptr<unsigned char[]> & rhs)
	{

		return result; 
	}
	unique_ptr<unsigned char[]> & operator*(unique_ptr<unsigned char[]> & lhs, const int f)
	{

		return result; 
	} 

};

}
#endif

