#include "fizzbuzz.hpp"


void fizzbuzz(std::vector<std::string> &input, VError *checkErr)
{
	bool isDevByThree;
	bool isDevByFive;
	VError checkErr2;

	for(long unsigned i = 0; i < input.size(); i++)
	{
		isDevByThree = isDevidedByThree(input[i], &checkErr2);
		if((checkErr2 != SUCCESS))
		{
			if(checkErr)
				*checkErr = checkErr2;
			return;
		}

		isDevByFive = isDevidedByFive(input[i]);

		if(isDevByThree && isDevByFive)
		{
			input[i] = "fizzbuzz";
		}
		else if(isDevByThree)
		{
			input[i] = "fizz";
		}
		else if(isDevByFive)
		{
			input[i] = "buzz";
		}
	}

	if(checkErr)
		*checkErr = SUCCESS;
}


bool isDevidedByThree(const std::string &str, VError *checkErr)
{
	unsigned long sum = 0;
	for(unsigned long i = 0; i < str.size(); i++)
	{
		if(str[i] < '0' || str[i] >'9')
		{
			if(checkErr)
				*checkErr = WRONG_INPUT_ERR;	
			
			return false;
		}

		sum += static_cast<unsigned long>(str[i]) - '0';

		if(sum == 9)
			sum = 0;
		
		if(sum >= 6)
			sum -= 6;

		if(sum >= 3)
			sum -= 3;	
	}

	if(checkErr)
		*checkErr = SUCCESS;


	if(!sum)
		return true;

	return false;
}


bool isDevidedByFive(const std::string &str, VError *checkErr)
{	
	for(unsigned long i = 0; i < str.size(); i++)
	{
		if(str[i] < '0' || str[i] >'9')
		{
			if(checkErr)
				*checkErr = WRONG_INPUT_ERR;	
			
			return false;
		}
	}

	if(checkErr)
		*checkErr = SUCCESS;

	char numb =str[str.size()-1];
	if(numb == '5' || numb == '0')
		return true;

	return false;
}


std::ostream &operator<<(std::ostream &os, const VError &err)
{
	if(err == WRONG_INPUT_ERR)
		os << "WRONG_INPUT_ERR";
	else
		os << "SUCCESS";

	return os;
}