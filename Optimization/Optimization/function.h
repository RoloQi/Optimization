#pragma once
#include <vector>
#define vecD std::vector<double>
#include <string>
#include <iostream>
#include <sstream>
const char NUM[] = "0123456789.";
class function
{
public:
	function();
	function(std::string);
private:
	bool intervalSet;
	double lowerBound, upperBound;
	std::stringstream buffer;
	vecD constant_factor;
	vecD x_expo;
	vecD y_expo;
public:
	int dimension;
	virtual double operator()(vecD);
	void df(vecD & x, vecD & deriv);
	void setInterval(double l,double u);
	std::string str() {
		buffer.clear();
		if (this->dimension == 1) {
			for (int index = 0; index < x_expo.size(); index++) {
				buffer << " ( " << constant_factor[index] << " * x^(" << x_expo[index] << ") ) ";
				if (index != x_expo.size() - 1)
					buffer << "+";
			}
			buffer << "\r\n";
		}
		else if (this->dimension == 2) {
			for (int index = 0; index < x_expo.size(); index++) {
				buffer << " ( " << constant_factor[index] << " * x^(" << x_expo[index] << ") * y^(" << y_expo[index] << ") ) ";
				if (index != x_expo.size() - 1)
					buffer << "+";
			}
			buffer << "\r\n";
		}
		return buffer.str();
	}

	bool isNumirical(std::string str) {
		for (int index = 0; index < str.size(); index++) {
			if (!isNumiricalChar(str[index]))
				return false;
		}
		return true;
	}
	bool isNumiricalChar(char ch) {
		for (int index = 0; index < 11; index++) {
			if (NUM[index] == ch)
				return true;
		}
		return false;
	}
	//the following method split and cut was introduced by Guo Yongming,\
	since they are basic method our code may looks like each other
	std::vector<std::string> split(std::string str, std::string source)
	{
		std::vector<std::string> result;
		int start = 0, end = 0;

		for (size_t i = 0; i < str.size(); i++)
		{
			if (Cut(str[i], source))
			{
				end = i;
				std::string temp = str.substr(start, end - start);
				result.push_back(temp);
				start = i + 1;
			}
		}
		result.push_back(str.substr(start, str.size() - start));
		return result;
	}
	bool Cut(char ch, std::string source) {
		for (int i = 0; i < source.size(); i++) {
			if (ch == source[i])
				return true;
		}
		return false;
	}
};
