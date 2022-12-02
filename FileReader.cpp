/***************************************************************
Student Name: Michael Whitten
File Name: FileReader.cpp
Assignment number: Project 5
Reads in values from file and reads them into variables
***************************************************************/
#include "FileReader.hpp"

FileReader::FileReader()
{
}

void FileReader::readFile(std::string file)
{
    inFile.open(file);
    if (inFile.is_open())
    {
        inFile >> s1;
        inFile >> s2;
        inFile.close();
        inFile.clear();
    }
}

void FileReader::readFileTwo(std::string file)
{
    inFile.open(file);
    if (inFile.is_open())
    {
        inFile >> numStrings;

        stringArray = new std::string[numStrings];

        for (int i = 0; i<numStrings; i++){
            inFile >> stringArray[i];
            // std::cout << "String " << i << ": " << stringArray[i] << std::endl;
        }
        inFile.close();
        inFile.clear();
    }
}

int FileReader::getNumStrings(){
    return numStrings;
}

std::string* FileReader::getStringArray() {
    return stringArray;
}

std::string FileReader::getS1()
{
    return s1;
}
std::string FileReader::getS2()
{
    return s2;
}
