/***************************************************************
Student Name: Michael Whitten
File Name: FileReader.hpp
Assignment number: Project 5
Reads in values from file and reads them into variables
***************************************************************/
#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>

class FileReader{
    private:
        std::ifstream inFile;
        std::ofstream outFile;
        std::string s1;
        std::string s2;
        int numStrings;
        std::string* stringArray;

    public:
        FileReader();
        void readFile(std::string file);
        std::string getS1();
        std::string getS2();
        void readFileTwo(std::string file);
        std::string* getStringArray();
        int getNumStrings();
};

#endif