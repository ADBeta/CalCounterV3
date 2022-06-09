#include "CalCounter.hpp"
#include "TeFiEd.h"
#include <iostream>

TeFiEd calFile("testfile.txt"); //IO file name and handler
CLI CLI; //Command line handler

/* Command line options handling **********************************************/
//Returns argc position of command if it is found in argv
size_t commandExists() {

}



int main(int argc, char *argv[]) {
	
	EntryDate[0].getDateFromSystem();
	std::cout << EntryDate[0].date << std::endl;
	std::cout << "int ver: " << EntryDate[0].dateToInt() << std::endl;
	
	calFile.VERBOSE=true;
	//open and read in the text file
	//calFile.read();
	
	//Read user input and calculate subtotal
	std::cout << CLI.getEntryFromUser() << std::endl;
	
	//Print all lines in the file	
	for(size_t x = 1; x <= calFile.lines(); x++) {
		std::cout << calFile.getLine(x) << std::endl;
	}
	
	calFile.flush();

	return 0;
}
