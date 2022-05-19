#include "CalCounter.hpp"
#include "TeFiEd.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>

/***   Entry Class Functions   ***/
//entry class objects
Entry EntryDate[5];

void Entry::setDateFromTime() {
	this->date = CalCounter::getDate();
}

//TODO
std::string Entry::setDateFromLine(size_t line) {

	//Copy text from line into buffer
	
	//Remove 'date: ' from the buffer
	
	//Return buffer
	return "";
}

//Compare Dates

/***   CLI Class Function   ***/

void CLI::getEntryFromUser() {
	//Allocate strings
	std::string item, output;
	
	//Allocate ints that will be used
	int count, calorie, subtotal;

	//Get input from user
	std::cout << "Calories per item: ";
	std::cin >> calorie;
	
	std::cout << "Amount of items: ";
	std::cin >> count;
	
	//TODO try catch exceptions
	
	//If count or calorie are invalid (not ints), error out
	if(!count || !calorie) exitOnError("Value input was not a valid intager");
	
	std::cout << calorie << "\n";
	std::cout << count << "\n";
	
	/* Sanitize and logic check the user input */
	if(count > 99);
	if(calorie > 9999);
	
	//Calculate subtotal, then create the output string
	subtotal = calorie * count;
	
	std::cout << "subtotal: " << subtotal << std::endl;
	
	//Check if count and calorie are intager only 
	//Limit the item string to 30 chars
	
	//Limit the count and calorie strings to 5 chars each

}

/***   Classless Functions   ***/
namespace CalCounter {

std::string zeroPad(int val) {
	//Using sprintf because it is the easiest way to pad.
	//Try to detect a possible overflow and protect against it
	if(val > 9999) {
		return "";
	}
	
	//Buffer size is 5, incase a 4 digit year value (eg 1990) is passed
	char buf[5];

	if(val < 10) {
		//Add a zero to the buffer, then the number
	} else {
		//Convert to string, to buffer
	}

	return buf;
}

std::string getDate() {
	//String buffer to hold date information
	std::string buffer;
	
	//Time now in secs since epoch
	time_t now = time(0);
	//UTC formatted tm struct generated from now
	std::tm *gmt_time = gmtime(&now);
	
	//Format the string = year-month-date  e.g. 2022-04-07 (7 april)
	buffer += std::to_string(gmt_time->tm_year + 1900) + "-" +
		zeroPad(gmt_time->tm_mon + 1) + "-" + zeroPad(gmt_time->tm_mday);
	
	return buffer;
}

uint32_t dateToInt(const std::string date) {
	//Copy date into non const
	std::string str = date;
	
	//Remove the -'s from the string
	str.erase(str.begin() + 4);
	str.erase(str.begin() + 6);
	
	//Return the string in int form
	return  std::stoi(str);
}

} //namespace CalCo
