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
#include <memory>

namespace NLXALE001 {


class Image
{
private:
	int width, height;
	std::unique_ptr<unsigned char[]> data;
public:

    Image(std::string im);	// default constructor - define in .cpp
    Image(const Image & copy);
	~Image();	// destructor - define in .cpp file

	Image readFile(std::string im);
	// void add(std::string im1, std::string im2, std::string outName);
	// void sub(std::string im1, std::string im2, std::string outName);
	// void invert(std::string im1, std::string outName);
	// void mask(std::string im1, std::string im2, std::string outName);
	// void threshold(std::string im1, int f, std::string outName);
	void copy(const Image & rhs);
	void saveFile(std::string outName);

	class iterator
	{
	private:
		unsigned char *ptr;
		// construct only via Image class (begin/end)
		iterator(u_char *p) : ptr(p) {}
	public:
		iterator(iterator&& comp)
		{
			ptr = comp.ptr;
			comp = nullptr;
		}
		~iterator(){	ptr = nullptr;	}
	    //copy construct is public
	    iterator( const iterator & rhs) : ptr(rhs.ptr){};        
	    // define overloaded ops: *, ++, --, =       
	    iterator & operator=(const iterator & rhs);       
   		// other methods for iterator   


	    bool operator!=(const iterator& comp) 
		{
			return(ptr != comp.ptr);
		}
		const iterator& operator++()
		{
			++ptr;
			return *this;
		}
		unsigned char& operator*()
			{
			return *ptr;
		}	


    };    
       
    Image operator+(const Image & comp)
	{
		Image curr(*this);

		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();
		Image::iterator comp_beg = comp.begin();
		Image::iterator comp_end = comp.end();

		while ( curr_beg != curr_end) {
			int sum = (*curr_beg + *comp_beg);
			if(sum > 255)
			{
				*curr_beg = 255;
			}
			else
			{
				*curr_beg =  sum;
			}
			++curr_beg;
			++comp_beg;
		}

		return curr; 
	}

	Image operator-(const Image & comp)
	{
		Image curr(*this);

		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();
		Image::iterator comp_beg = comp.begin();
		Image::iterator comp_end = comp.end();

		while ( curr_beg != curr_end) {
			int sum = (*curr_beg - *comp_beg);
			if(sum <0)
			{
				*curr_beg = 0;
			}
			else
			{
				*curr_beg =  sum;
			}
			++curr_beg;
			++comp_beg;
		}

		return curr; 
		
	}
	Image operator!()
	{
		Image curr(*this);

		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();

		while ( curr_beg != curr_end) 
		{
			*curr_beg =  255 - *curr_beg;
			
			++curr_beg;
		}

		return curr;  
	}
	Image operator/(const Image & comp)
	{
		Image curr(*this);

		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();
		Image::iterator comp_beg = comp.begin();
		Image::iterator comp_end = comp.end();

		while ( curr_beg != curr_end) {
			if(*comp_beg!=255)
			{
				*curr_beg = 0;
			}
			++curr_beg;
			++comp_beg;
		}

		return curr; 
	}
	Image operator*(const int f)
	{
		Image curr(*this);

		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();

		while ( curr_beg != curr_end) {
			if(*curr_beg>f)
			{
				*curr_beg = 255;
			}
			else
			{
				*curr_beg =  0;
			}
			++curr_beg;
		}

		return curr; 
	} 

	
	// define begin()/end() to get iterator to start and    
   	// "one-past" end. 
	iterator begin(void)const;
	iterator end(void)const; 

};

}
#endif

