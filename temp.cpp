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

bool Image::readImages(std::string baseName)	{
	
	//open heqader and extract data
	string headerfile = baseName + ".data";
	ifstream infile (headerfile.c_str());
	string line;
	if(!infile.is_open()){		//error handling
		cout << "Error, file not found" << endl;
		return false;
	}
	if(infile.is_open()){		//set width, height and number of images
	
		infile >> width;
		infile >> height;
		infile >> num;
	
	}

	
	for (int j = 0; j<num; j++)		//populate vector wqith arrays
	{
		stringstream ss;
    		ss << j;
		
   		string str;
    		ss >> str;
		
		string filename = baseName + str + ".raw";	
		ifstream file (filename.c_str(), ios::binary);
		
		if(!file.is_open()){
			cout << "Error, file not found" << endl;
			return false;
		}

		unsigned char ** arr;
		arr = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			arr[i] = new unsigned char[width];
			
			file.read((char *)arr[i], width);
		}
		
		slices.push_back(arr);
		
	}//end for j
		return true;
	}
	
	// compute difference map and write out;  define in .cpp
	void Image::diffmap(int sliceI, int sliceJ, std::string output_prefix)	{
		
		string outname = output_prefix + ".raw";

		ofstream out(outname.c_str());	
		
		//create array and populate it with diffs, wirte to file
		unsigned char ** array;
		array = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			array[i] = new unsigned char[width];
			
			for (int j = 0; j < width; j++) {
				array[i][j] = (unsigned char)(fabs((float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j])/2);
			}
			
			out.write((char *)array[i], width);
		}
		
		out.close();
		
		for (int j = 0; j<height; j++) {
			delete [] array[j];
		}//end for j
		delete [] array;

	}

	// extract slice sliceId and write to output - define in .cpp
	void Image::extract(int sliceId, std::string output_prefix)	{
		string outname = output_prefix + ".raw";

		ofstream out(outname.c_str());	
		//write slice to file		
		for (int i = 0; i < height; ++i) {			
			out.write((char *)slices[sliceId][i], width);
		}
		
		out.close();
	}

	// number of bytes uses to store image data bytes
	//and pointers (ignore vector<> container, dims etc)
	void Image::ImageSize(void)	{	// define in .cpp
	
		int bytes = width*height*num*1 + height*num*8 + num*8; //arraysize*charsize + pointers + double pointers
		cout << "Number of images: " << num << endl;
		cout << "Number of bytes required: " << bytes << endl;
		
	}


	void Image::extra(int row, std::string output_prefix)	{
		string outname = output_prefix + ".raw";

		ofstream out(outname.c_str());	
		//write row of each image to file
		for (int i = 0; i<num; i++) {
			out.write((char *)slices[i][row], width);
		}
		
		out.close();
		
		
		
	}