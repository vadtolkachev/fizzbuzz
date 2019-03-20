#pragma once
#include <string>
#include <vector>

enum VError
{
	SUCCESS,
	WRONG_INPUT_ERR
};


void fizzbuzz(std::vector<std::string> &input, VError *checkErr = nullptr);
bool isDevideByThree(const std::string &str, VError *checkErr = nullptr);
bool isDevideByFive(const std::string &str, VError *checkErr = nullptr);