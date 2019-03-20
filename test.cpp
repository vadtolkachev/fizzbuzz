#include "fizzbuzz.hpp"
#include "unittest.hpp"
#include <iostream>


int main()
{
	VError checkErr;

	std::vector<std::string> vec1 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "15"};
	std::vector<std::string> ans1 = {"1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "fizzbuzz"};
	std::vector<std::string> vec2 = {"qwe", "5"};
	std::vector<std::string> vec3 = {"1001325235000213412340010",
		"2000000501000000010000000000003",
		"1000000200001000000000000000000000001" };
        std::vector<std::string> ans3  = {"buzz", "fizz", 
        	"1000000200001000000000000000000000001"};

	fizzbuzz(vec1, &checkErr);
	UNITTEST(checkErr, ==, SUCCESS);
	for(unsigned long i = 0; i < vec1.size(); i++)
	{
		UNITTEST(vec1[i], ==, ans1[i]);
	}

	fizzbuzz(vec2, &checkErr);
	UNITTEST(checkErr, ==, WRONG_INPUT_ERR);

	isDevidedByFive(vec2[0], &checkErr);	
	UNITTEST(checkErr, ==, WRONG_INPUT_ERR);

	isDevidedByFive(vec2[1], &checkErr);	
	UNITTEST(checkErr, ==, SUCCESS);

	fizzbuzz(vec3, &checkErr);
	UNITTEST(checkErr, ==, SUCCESS);
	for(unsigned long i = 0; i < vec3.size(); i++)
	{
		UNITTEST(vec3[i], ==, ans3[i]);
	}


	return 0;
}