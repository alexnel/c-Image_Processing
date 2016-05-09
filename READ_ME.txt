NLXALE001
Alex Nel

To build file:
Run 'make' from terminal in given directory

To run file:
run from terminal:
	./imageops [input parameters] <output filename>
where 	[input parameters] are:
	for adding two images:
		'-a [im1] [im2]'
	for subtracting two images:
		'-s [im1] [im2]'
	for inverting an image:
		'-i [im1]'
	for masking an image:
		'-m [im1] [im2]'
	for creating a mask by thresholding an image:
		'-t [im1] [f]'

		where	[im1] and [im2] are the prefixes for te images you want to manipulate
				[f] is the integer value you want to threshold an image at

where 	<output filename> is  the  the prefix of the file to which you want to write the outputted image to, e.g. 'output' if you want the image to be written to 'output.pmg'

e.g. ./imageops -i daytime nighttime		will invert the image daytime.pmg and store it in nighttime.pmg



Images must be placed in the root directory, not in a different file.

My program is made up of three files: driver.cpp, Image.cpp and Image.h

Operation overloading can be found in the .h file.

Unit testing has been done and can be run from the test subdirectory. This can be run but will produce pages of errors...
