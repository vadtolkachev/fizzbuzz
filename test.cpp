#include "fizzbuzz.hpp"
#include <iostream>


int main()
{
	std::vector<std::string> v = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	VError checkErr;
	fizzbuzz(v, &checkErr);
	if(checkErr != SUCCESS)
		printf("checkErr = %d\n", checkErr);


	for(unsigned long i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}