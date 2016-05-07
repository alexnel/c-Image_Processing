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
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);

		Image::iterator beg = x.begin();

		REQUIRE(*(++beg) == '5');
		REQUIRE(x.width == 3);
		REQUIRE(x.height == 2);

	}
	SECTION("!=")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		unsigned char[] buffer2 = {'0', '5', '100', '115', '25', '96'};
		Image y = new Image(3, 2, &buffer2);
		unsigned char[] buffer3 = {'0', '50', '100', '115', '25', '96'};
		Image z = new Image(3, 2, &buffer3);

		REQUIRE((x!=y)==false);
		REQUIRE((x!=z)==true);
	}
	SECTION("+")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		unsigned char[] buffer2 = {'40', '24', '65', '150', '25', '23'};
		Image y = new Image(3, 2, &buffer2);
		unsigned char[] buffer3 = {'40', '29', '165', '225', '50', '119'};
		Image z = new Image(3, 2, &buffer3);

		REQUIRE(((x+y)==z)==true);
	}
	SECTION("-")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		unsigned char[] buffer2 = {'40', '24', '65', '150', '25', '23'};
		Image y = new Image(3, 2, &buffer2);
		unsigned char[] buffer3 = {'0', '0', '35', '0', '0', '73'};
		Image z = new Image(3, 2, &buffer3);

		REQUIRE(((x-y)==z)==true);
	}
	SECTION("!")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		unsigned char[] buffer2 = {'225', '220', '125', '110', '200', '129'};
		Image y = new Image(3, 2, &buffer2);

		REQUIRE(((!x)==y)==true);
	}
	SECTION("*")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		int f = 99;
		unsigned char[] buffer2 = {'0', '0', '225', '225', '0', '0'};
		Image y = new Image(3, 2, &buffer2);
		

		REQUIRE(((x*f)==y)==true);
	}
	SECTION("/")
	{
		unsigned char[] buffer = {'0', '5', '100', '115', '25', '96'};
		Image x = new Image(3, 2, &buffer);
		unsigned char[] buffer2 = {'0', '225', '0', '225', '225', '0'};
		Image y = new Image(3, 2, &buffer2);
		unsigned char[] buffer3 = {'0', '5', '0', '115', '25', '0'};
		Image z = new Image(3, 2, &buffer3);

		REQUIRE(((x/y)==z)==true);
	}
}//end test
TEST_CASE("Testing multiple operations at once", "[Image]"){
	unsigned char[] m1 = {'0', '5', '100', '115', '25', '96'};
	Image x = new Image(3, 2, &m1);
	unsigned char[] u1 = {'211', '25', '0', '101', '225', '55'};
	Image y = new Image(3, 2, &u1);
	unsigned char[] u2 = {'0', '5', '0', '115', '25', '0'};
	Image z = new Image(3, 2, &u2);
	unsigned char[] a = {'0', '5', '0', '101', '25', '225'};
	Image z = new Image(3, 2, &a);

	REQUIRE((((((m1*90)/u1)+((!(m1*90))/u2)))==a)==true);
}//end test
}//end namespace