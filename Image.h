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

    Image(std::string im);	// default constructor
    Image(const Image & copy);
    Image(int w, int h, unsigned char*buffer);
    Image(Image&& move);
	~Image();	// destructor

	//overloading operators:
	Image& operator=(const Image& rhs)
	{
		if (this == &rhs)
			{	return *this;	}
		if (data!=nullptr)
			{	data = nullptr;	}
		int l = rhs.width*rhs.height;
		unsigned char* buffer = new unsigned char[l];

		for (int i=0; i<l; i++)
			{	buffer[i] = rhs.data[i];	}
		data.reset(buffer);
		return *this;
	}
	Image& operator=(Image&& rhs)
	{
		if (this == &rhs)
			{	return *this;	}
		if (data!=nullptr)
			{	data = nullptr;	}
		int l = rhs.width*rhs.height;
		unsigned char* buffer = new unsigned char[l];

		for (int i=0; i<l; i++)
			{	buffer[i] = rhs.data[i];	}
		data.reset(buffer);
		rhs.height=0;
		rhs.width=0;
		rhs.data=nullptr;
		return *this;
	}
	bool readImage(std::string im);
	void saveFile(std::string outName);

	class iterator
	{
	private:
		unsigned char *ptr;
		// construct only via Image class (begin/end)
		friend class Image;

		iterator(unsigned char *p);
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
		iterator & operator=(const iterator & rhs)
		{
			if(this!=&rhs)
			{
				ptr = rhs.ptr;
			}
			return *this;
		} 
		iterator & operator=(iterator && rhs)//move
		{
			if (this!=&rhs)
			{
				ptr = rhs.ptr;
			}
			rhs = nullptr;
			return *this;
		}


    };  

    //used for unit testing
    bool operator==(const Image& comp) 
		{
			Image curr(*this);

			Image::iterator curr_beg = curr.begin();
			Image::iterator curr_end = curr.end();
			Image::iterator comp_beg = comp.begin();
			Image::iterator comp_end = comp.end();

			while ( curr_beg != curr_end) {
				if(*curr_beg==*comp_beg)
				{
					++curr_beg;
					++comp_beg;
				}
				else
				{
					return false;
				}
			}

			return true; 
		}
	//used for adding images together
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
	//subtracting one image from the other
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
	//inverts an image
	Image operator!()
	{
		Image curr(*this);
		Image::iterator curr_beg = curr.begin();
		Image::iterator curr_end = curr.end();

		while ( curr_beg != curr_end) 
		{
			int j =  255 - *curr_beg;
			*curr_beg = j;

			++curr_beg;
		}

		return curr;  
	}
	//masks an image with another
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
	//creates masks using a threshold value
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

