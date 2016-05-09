#define CATCH_CONFIG_MAIN
#include "unit_test.h"
#include "unit_test.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstdlib>



namespace NLXALE001{
using namespace std;
TEST_CASE("Testing operation overloading", "[Image]"){
	SECTION("++")
	{
		unsigned char* buffer = new unsigned char[6];
		buffer = {'0', '5', '100', '115', '25', '96'};
		Image a = new Image(3, 2, &buffer);

		Image::iterator beg = a.begin();

		REQUIRE(*(++beg) == '5');
		REQUIRE(a.width == 3);
		REQUIRE(a.height == 2);

	}
	SECTION("!=")
	{
		unsigned char* buffer1 = new unsigned char[6];
		buffer1 =  {'0', '5', '100', '115', '25', '96'};
		Image b = new Image(3, 2, &buffer1);
		unsigned char* buffer2 = new unsigned char[6];
		buffer2 =  {'0', '5', '100', '115', '25', '96'};
		Image c = new Image(3, 2, &buffer2);
		unsigned char* buffer3 = new unsigned char[6];
		buffer3 =  {'0', '50', '100', '115', '25', '96'};
		Image d = new Image(3, 2, &buffer3);

		REQUIRE((b!=c)==false);
		REQUIRE((b!=d)==true);
	}
	SECTION("+")
	{
		unsigned char* buffer4 new unsigned char[6];
		buffer4 =  = {'0', '5', '100', '115', '25', '96'};
		Image e = new Image(3, 2, &buffer4);
		unsigned char* buffer5 new unsigned char[6];
		buffer5 =  = {'40', '24', '65', '150', '25', '23'};
		Image f = new Image(3, 2, &buffer5);
		unsigned char* buffer6 = new unsigned char[6];
		buffer6 = {'40', '29', '165', '225', '50', '119'};
		Image g = new Image(3, 2, &buffer6);

		REQUIRE(((e+f)==g)==true);
	}
	SECTION("-")
	{
		unsigned char* buffer7 = new unsigned char[6];
		buffer7 =  {'0', '5', '100', '115', '25', '96'};
		Image h = new Image(3, 2, &buffer7);
		unsigned char* buffer8 = new unsigned char[6];
		buffer8 =  {'40', '24', '65', '150', '25', '23'};
		Image i = new Image(3, 2, &buffer8);
		unsigned char* buffer9 = new unsigned char[6];
		buffer9 =  {'0', '0', '35', '0', '0', '73'};
		Image j = new Image(3, 2, &buffer9);

		REQUIRE(((h-i)==j)==true);
	}
	SECTION("!")
	{
		unsigned char* buffer10 = new unsigned char[6];
		buffer10 =  {'0', '5', '100', '115', '25', '96'};
		Image k = new Image(3, 2, &buffer10);
		unsigned char* buffer11 = new unsigned char[6];
		buffer11 =  {'225', '220', '125', '110', '200', '129'};
		Image l = new Image(3, 2, &buffer11);

		REQUIRE(((!k)==l)==true);
	}
	SECTION("*")
	{
		unsigned char* buffer12 = new unsigned char[6];
		buffer12 =  {'0', '5', '100', '115', '25', '96'};
		Image m = new Image(3, 2, &buffer12);
		int n = 99;
		unsigned char* buffer13 = new unsigned char[6];
		buffer13 =  {'0', '0', '225', '225', '0', '0'};
		Image o = new Image(3, 2, &buffer13);
		

		REQUIRE(((m*n)==o)==true);
	}
	SECTION("/")
	{
		unsigned char* buffer14 = new unsigned char[6];
		buffer14 =  {'0', '5', '100', '115', '25', '96'};
		Image p = new Image(3, 2, &buffer14);
		unsigned char* buffer15 = new unsigned char[6];
		buffer15 =  {'0', '225', '0', '225', '225', '0'};
		Image q = new Image(3, 2, &buffer15);
		unsigned char* buffer16 = new unsigned char[6];
		buffer16 =  {'0', '5', '0', '115', '25', '0'};
		Image r = new Image(3, 2, &buffer16);

		REQUIRE(((p/q)==r)==true);
	}
}//end test
TEST_CASE("Testing multiple operations at once", "[Image]"){
	unsigned char* m1 = new unsigned char[6];
	m1 =  {'0', '5', '100', '115', '25', '96'};
	Image x = new Image(3, 2, &m1);
	unsigned char* u1 = new unsigned char[6];
	u1 =  {'211', '25', '0', '101', '225', '55'};
	Image y = new Image(3, 2, &u1);
	unsigned char* u2 = new unsigned char[6];
	u2 =  {'0', '5', '0', '115', '25', '0'};
	Image z = new Image(3, 2, &u2);
	unsigned char* u = new unsigned char[6];
	u =  {'0', '5', '0', '101', '25', '225'};
	Image w = new Image(3, 2, &u);

	REQUIRE((((((x*90)/y)+((!(x*90))/z)))==w)==true);
}//end test
}//end namespace