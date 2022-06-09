#include "CalCounter.hpp"
#include "TeFiEd.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>

/* Entry Class Functions ******************************************************/
//entry class objects
Entry EntryDate[5];

void Entry::getDateFromSystem() {
	//String buffer to hold date information
	std::string buffer;
	
	//Time now in secs since epoch
	time_t now = time(0);
	//UTC formatted tm struct generated from now
	std::tm *gmt_time = gmtime(&now);
	
	//Format the string = year-month-date  e.g. 2022-04-07 (7 april)
	//Year
	buffer.append(std::to_string(gmt_time->tm_year + 1900) + "-");
	//Month
	buffer.append(StringHandler::padIntToString(gmt_time->tm_mon + 1) + "-");
	//Day
	buffer.append(StringHandler::padIntToString(gmt_time->tm_mday));
	
	//Set the Entry date to buffer
	this->date = buffer;
}

uint32_t Entry::dateToInt() {	
	//Check the length of the string. It should ALWAYS be xxxx-xx-xx.
	//If it does not match this parrten then print an error and return 0.
	if(date.length() != 10) {
		std::cerr << "Error: dateToInt: Date string is not valid!" << std::endl;
		return 0;
	}

	//Copy date into a overwriteable string
	std::string str = this->date;
	
	//Remove the -'s from the string
	str.erase(str.begin() + 4);
	str.erase(str.begin() + 6);
	
	//Return the string in int form
	return  std::stoi(str);
}

//Compare Dates

/* CLI Class Function *********************************************************/
std::string CLI::getEntryFromUser() {
	//Declare the variables that will be filled later
	std::string item, calorie, count;
		
	try {
		//Return status
		int ret;
		
		/*** Item and validate ***/
		std::cout << "Food Item:\t";
		std::getline(std::cin, item);
		////
		ret = StringHandler::validateString(item);
		
		//Throw error
		if(ret != 0) throw std::runtime_error("Item input not valid.");
		
		/*** Calories and validate ***/
		std::cout << "Calories per:\t";
		std::getline(std::cin, calorie);
		////
		ret = StringHandler::validateNumeral(calorie);
		
		//Throw error
		if(ret != 0) throw std::runtime_error("Calorie input not valid.");
		
		/*** Amount of items ***/
		std::cout << "Amount of Item(s):\t";
		std::getline(std::cin, count);
		////
		ret = StringHandler::validateNumeral(count);
		
		//Throw error
		if(ret != 0) throw std::runtime_error("Count input not valid.");
				
	} //try
	
	/*** Catch errors ***/
	catch (const std::exception& errMsg) {
		std::cerr << "Error: getEntryFromUser: " << errMsg.what() <<
			" exiting." << std::endl;
    
    	return std::string();
    } //catch
	
	//Generate the output string to be placed into the file
	return StringHandler::generateEntryString(item, calorie, count);
}

/* String validation and manipulation *****************************************/
namespace StringHandler {
////
std::string padIntToString(int val) {
	std::string outStr;

	//If input is only single digit, add 0
	if(val < 10) outStr.append("0");
	//Append the digit converted to string post 0 pad
	outStr.append(std::to_string(val));
	
	//outStr.clear();
	return outStr;
}
////
int validateString(std::string &input) {
	//Make sure it doesn't contain a comma
	if(input.find(",") != std::string::npos) {
		std::cerr << "Error: validateString: String contains comma (,)"
			<< std::endl;
		//Fail
		return 1;
	}
	
	//If string is over a certain size, limit it. Continue after action
	if(input.length() > 30) {
		input.resize(30);
		//Print error but continue
		std::cerr << "Warn: validateString: String is over the limit length"
			<< std::endl;
	}
	
	//Success
	return 0;
}

int validateNumeral(std::string &input) {
	//Make sure there are no chars other than numerals in the string
	if(input.find_first_not_of("0123456789") != std::string::npos) {
		std::cerr << "Error: validateNumeral: String contains a non-digit char"
			<< std::endl;
		//Fail
		return 1;
	}
	
	//Success
	return 0;
}

std::string generateEntryString (
	std::string itemStr, std::string calStr, std::string countStr) {
	size_t subtotal;
	
	try {
		/*** Intager size tests ***/
		size_t intCalorie = std::stoi(calStr);
		//Sanity check number
		if(intCalorie > 2000) 
			throw std::runtime_error("Calorie value too high.");
		////
		size_t intCount = std::stoi(countStr);
		//Sanity check number
		if(intCount > 30)
			throw std::runtime_error("Count value too high.");
		
				
		//Calculate subtotal, then create the output string
		subtotal = intCalorie * intCount;
		//Check is subtotal makes sense
		if(subtotal > 60000) 
			throw std::runtime_error("Subtotal value too high.");
	} //try
	
	/*** Catch errors ***/
	catch (const std::exception& errMsg) {
		std::cerr << "Error: generateEntryString: " << errMsg.what() <<
			" exiting." << std::endl;
    
    	//return a blank string
    	return std::string();
    } //catch
    
    //Generate the output string
    std::string output;
    output.append(itemStr + ", " + calStr + ", " + countStr + ", ");
    output.append(std::to_string(subtotal));
    
    return output;
}

} //namespace StringHandler
