/* 
	Calorie Counter Members.
	
	
	Version 0.5.6
	ADBeta 09 Jun 2022
*/
#ifndef CALCOUNTER_H
#define CALCOUNTER_H

#include <string>
#include <cstdint>

/* Entry class. holds data for each entry chunk in the file *******************/
class Entry {
	public:

	/*** Entry handling ***/
	void addEntryToFile(std::string);

	/*** Date ***/
	//Sets the date variable from todays date, via time_t
	void getDateFromSystem();

	//Convert the date string into an int and store it, and return it
	uint32_t dateToInt();
	
	//Compare Dates
	
	/*** Member Variables ***/
	std::string date;
	
	
	private:

}; //class Entry
extern Entry EntryDate[5];

/* Specifically CLI Functions *************************************************/
class CLI {
	public:
	//Gets entry data from the user via getline/cin and return it
	std::string getEntryFromUser();
	
	private:

}; //class CLI

/* String Validation and manipulation *****************************************/
namespace StringHandler {
	//Pads a number below 10 with a leading 0 and return it as a string
	std::string padIntToString(int);
	///////////////////////////////////////
	//Validates a string for item name.
	int validateString(std::string &);
	//Validate an intager passed as a string.
	int validateNumeral(std::string &);
	//Create a string from item, calorie and count to put in the text file
	//item, calorie, count
	std::string generateEntryString(std::string, std::string, std::string);
}
#endif
