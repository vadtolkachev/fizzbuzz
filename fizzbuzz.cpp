#include "fizzbuzz.hpp"


void fizzbuzz(std::vector<std::string> &input, VError *checkErr)
{

	for(long unsigned i = 0; i < input.size(); i++)
	{
		VError checkErr2;
		bool isDevByThree = isDevideByThree(input[i], &checkErr2);
		if((checkErr2 != SUCCESS))
		{
			if(checkErr)
				*checkErr = checkErr2;
			return;
		}

		bool isDevByFive = isDevideByFive(input[i], &checkErr2);
		if((checkErr2 != SUCCESS))
		{
			if(checkErr)
				*checkErr = checkErr2;
			return;
		}

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


bool isDevideByThree(const std::string &str, VError *checkErr)
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

		sum *= 10;
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


bool isDevideByFive(const std::string &str, VError *checkErr)
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

		sum *= 10;
		sum += static_cast<unsigned long>(str[i]) - '0';
		
		if(sum >= 5)
			sum -= 5;
	}

	if(checkErr)
		*checkErr = SUCCESS;

	if(!sum)
		return true;

	return false;
}