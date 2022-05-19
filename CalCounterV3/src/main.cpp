#include "CalCounter.hpp"
#include "TeFiEd.h"
#include <iostream>

TeFiEd calFile("testfile.txt");
CLI CLI;

using namespace CalCounter;

int main(void) {
	/*
	EntryDate[0].setDateFromTime();
	std::cout << EntryDate[0].date << std::endl;
	std::cout << "int ver: " << dateToInt(getDate()) << std::endl;
	*/
	calFile.VERBOSE=true;
	//open and read in the text file
	calFile.read();
	
	//Read user input and calculate subtotal
	CLI.getEntryFromUser();
	
	for(size_t x = 1; x <= calFile.lines(); x++) {
		std::cout << calFile.getLine(x) << std::endl;
	}
	
	calFile.flush();

	return 0;
}
