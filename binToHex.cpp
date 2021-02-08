//Filename: binToHex.cpp
//Author: Jino Enriquez
//Class: CISP 440
//Last Date Modified: 1/20/2021


#include <iostream> //cin and cout
#include <string> //Used to generate hex values
#include <algorithm> //For reverse() function

using namespace std;

//////////////////////////////////
//     Function Prototypes		//
//////////////////////////////////
int convertBinToDec(string);
string convertDecToHex(int);


//////////////////////////////////
//          main()				//
//////////////////////////////////
int main()
{
    string binary_number = "10001001";
    //cin >> binary_number;
	cout << binary_number << "B in hexadecimal is: ";
    int decimal_value = convertBinToDec(binary_number);
	//Function call to convert decimal to hexadecimal
	string hex_value = convertDecToHex(decimal_value);
    cout << hex_value << endl;
	cout << decimal_value << endl;
    return 0;
}


//////////////////////////////////////////////////////
//  Binary to Decimal Converter:					//
//  Takes the binary representation of a value and  //
//	converts the value to its decimal form			//
//////////////////////////////////////////////////////

int convertBinToDec(string binary_value)
{
	int decimal_number = 0;
	bool negate_int = false;
    int last_digit = 0;
    if (binary_value[0] == '1')
    {
        negate_int = true;
    }
	if(binary_value[1] == '1')
	{
		decimal_number += 64;
	}
	if(binary_value[2] == '1')
	{
		decimal_number += 32;
	}
	if(binary_value[3] == '1')
	{
		decimal_number += 16;
	}
	if(binary_value[4] == '1')
	{
		decimal_number += 8;
	}
	if(binary_value[5] == '1')
	{
		decimal_number += 4;
	}
	if(binary_value[6] == '1')
	{
		decimal_number += 2;
	}
	if(binary_value[7] == '1')
	{
		decimal_number += 1;
	}
	if(negate_int)
	{
		decimal_number *= -1;
	}
	//cout << decimal_number << endl;
	return decimal_number;
}


//////////////////////////////////////////////////
//	Decimal to Hexadecimal Converter:           //
//	Takes the decimal representation of a value //
//	and converts the value to its hexadecimal   //
//	form										//
//////////////////////////////////////////////////
string convertDecToHex(int dec_value)
{
	bool negative_int = false;
	if (dec_value < 0)
	{
		negative_int = true;
		dec_value *= -1;
	}
	string hexadecimal = "";
	int remainder = 0;
    while (dec_value != 0)
    {
    	remainder = (dec_value % 16);
    	string str_remainder = to_string(remainder);
		//cout << str_remainder << endl;
    	if (str_remainder == "10")
    	{
    		str_remainder = "A";
		}
		if (str_remainder == "11")
    	{
    		str_remainder = "B";
		}
		if (str_remainder == "12")
    	{
    		str_remainder = "C";
		}
		if (str_remainder == "13")
    	{
    		str_remainder = "D";
		}
		if (str_remainder == "14")
    	{
    		str_remainder = "E";
		}
		if (str_remainder == "15")
    	{
    		str_remainder = "F";
		}
		hexadecimal.append(str_remainder);
    	dec_value = (dec_value / 16);
	}
	reverse(hexadecimal.begin(), hexadecimal.end());
	if (negative_int)
	{
		 hexadecimal.insert(0, "-");
	}
	return hexadecimal;
}