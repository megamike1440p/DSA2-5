/***************************************************************
Student Name: Michael Whitten
File Name: Subsequence.hpp
Assignment number: Project 5
Calculates LCSs and similarity
***************************************************************/
#ifndef SUBSEQUENCE_HPP
#define SUBSEQUENCE_HPP
#include <iostream>

class Subsequence
{
private:
    std::string lcs;
    int **cArray;
    int m;
    int n;
    int row;
    int col;
    std::string s1;
    std::string s2;

public:
    int **LCS(std::string s1, std::string s2);
    void arrayToString();
    std::string getLcs(int i, int j);
    void printLcs();
    char getSimilarity(std::string s1, std::string s2);
};

#endif