/***************************************************************
Student Name: Michael Whitten
File Name: test.cpp
Assignment number: Project 5
test/main method. Reads twostrings and calculates LCS then reads
multiStrings and calculates similarity 
(outputs similarity results, but does not output table to house them)
***************************************************************/
#include <iostream>
#include "FileReader.hpp"
#include "Subsequence.hpp"
using namespace std;
int main()
{
    cout << "Commencing tests" << endl;
    FileReader reader;
    std::cout << "reading twoStrings and calculating LCS" << std::endl;
    reader.readFile("twoStrings.txt");
    Subsequence sub;
    // cout << "String 1 = " << reader.getS1() << endl;
    // cout << "String 2 = " << reader.getS2() << endl;
    cout << endl;
    sub.LCS(reader.getS1(), reader.getS2());
    // cout << "array contents: " << endl;
    // sub.arrayToString();
    sub.printLcs();

    std::cout << "reading multiStrings and calculating similarity" << std::endl;

    reader.readFileTwo("multiStrings.txt");
    sub.getSimilarity(reader.getS1(), reader.getS2());

    for (int i = 0; i < reader.getNumStrings(); i++)
    {
        std::cout.width(i+1);
        for (int j = i + 1; j < reader.getNumStrings(); j++)
        {
            std::cout << sub.getSimilarity(reader.getStringArray()[i], reader.getStringArray()[j]);
        }
        std::cout << std::endl;
    }
}