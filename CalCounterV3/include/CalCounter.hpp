/* 
	CalCounter main functions
	
	Version 0.01
	Written by ADBeta
	Last Modified 07 Apr 2022
*/
#ifndef CALCOUNTER_H
#define CALCOUNTER_H

#include <string>
#include <cstdint>

//Internal data structure
class Entry {
	public:
	//Functions
	//Sets the date variable from todays date, via time_t
	void setDateFromTime();
	
	//Sets the date variable from the date string on a line
	std::string setDateFromLine(size_t);

	//Compare Dates
	
	//Variables
	std::string date;
	
	
	private:

}; //class Entry
extern Entry EntryDate[5];

//Specifically CLI Functions
class CLI {
	public:
	//Very simple error handler. Execptions are overkill for the level of error
	//that can occur. This function may orphan some data, but it tries not to
	void exitOnError(std::string);
	
	void getEntryFromUser();
	
	private:

}; //class CLI

//Non-Class functions
namespace CalCounter {
	//Pads a number below 10 with a leading 0. allows up to 4 digit long numbers
	std::string zeroPad(int val);

	//Gets the current date and converts it into internal date format
	std::string getDate();

	//Converts the internal date format into a number for comparison between dates
	//Must be 32bits wide!
	uint32_t dateToInt(const std::string);
} //namespace CalCo

#endif
