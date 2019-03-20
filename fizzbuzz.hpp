#pragma once
#include <string>
#include <vector>
#include <iostream>

enum VError
{
	SUCCESS,
	WRONG_INPUT_ERR
};


void fizzbuzz(std::vector<std::string> &input, VError *checkErr = nullptr);
bool isDevidedByThree(const std::string &str, VError *checkErr = nullptr);
bool isDevidedByFive(const std::string &str, VError *checkErr = nullptr);