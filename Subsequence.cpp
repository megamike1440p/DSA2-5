/***************************************************************
Student Name: Michael Whitten
File Name: Subsequence.cpp
Assignment number: Project 5
Calculates LCSs and similarity
***************************************************************/

#include <iostream>
#include "Subsequence.hpp"

int **Subsequence::LCS(std::string s1, std::string s2)
{
    lcs = "";
    this->s1 = s1;
    this->s2 = s2;
    lcs = "";
    m = s1.length();
    n = s2.length();
    std::cout << "m: " << m << std::endl
              << "n: " << n << std::endl;
    // init array
    cArray = new int *[m + 1];
    for (int r = 0; r <= m; r++)
    {
        cArray[r] = new int[n + 1];
    } // end array init

    // row/col 0 = 0
    for (int i = 0; i <= m; i++)
    {
        cArray[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        cArray[0][j] = 0;
    } // end row/col 0 = 0

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1.at(i - 1) == s2.at(j - 1))
            {
                cArray[i][j] = cArray[i - 1][j - 1] + 1;
            }
            else if (cArray[i - 1][j] >= cArray[i][j - 1])
            {
                cArray[i][j] = cArray[i - 1][j];
            }
            else
            {
                cArray[i][j] = cArray[i][j - 1];
            }
        }
    }
    return cArray;
}

std::string Subsequence::getLcs(int i, int j)
{
    // std::cout << "LCS[" << i << "][" << j << "]" << std::endl;
    if (i > 0 && j > 0)
    {
        if (cArray[i][j] == cArray[i - 1][j])
        {
            // std::cout << "LCS[" << i - 1 << "][" << j << "]" << std::endl;
            getLcs(i - 1, j);
        }
        else if (cArray[i][j] == cArray[i][j - 1] && cArray[i][j] > cArray[i - 1][j])
        {
            // std::cout << "LCS[" << i << "][" << j - 1 << "]" << std::endl;
            getLcs(i, j - 1);
        }
        else if (cArray[i][j] > cArray[i][j - 1] && cArray[i][j] > cArray[i - 1][j])
        {
            // lcs += s1.at(i - 1);
            lcs.insert(0, 1, s1.at(i-1));
            // std::cout << "adding " << s1.at(i - 1) << " to sequence" << std::endl;
            // std::cout << "LCS[" << i - 1 << "][" << j - 1 << "]" << std::endl;
            getLcs(i - 1, j - 1);
        }
    }
    return lcs;
}

    char Subsequence::getSimilarity(std::string s1, std::string s2){
            double lcsComparison;
            double stringComparison;
            double result;
            char similarity;
            std::string lString = s1;
            std::string sString = s2;

        if (s1.length() > s2.length()){
            lString = s1;
            sString = s2;
        }
        else if (s1.length() < s2.length()){
            lString = s2;
            sString = s1;
        }
        else{
            stringComparison = 1;
        }
        stringComparison = (double)sString.length()/lString.length();
        // std::cout << stringComparison << "\n";
        lcsComparison = (double)getLcs(m,n).length()/sString.length();
        // std::cout << lcsComparison << "\n";


        if(stringComparison > .9 && lcsComparison  > .9){
            return 'H';
        }
        else if (stringComparison > .8 && lcsComparison  > .8){
            return 'M';
        }
        else if (stringComparison > .6 && lcsComparison  > .5){
            return 'L';
        }
        else {
            return 'D';
        }
    }

void Subsequence::printLcs()
{
    std::cout << "lcs: " << getLcs(m, n) << std::endl;
    std::cout << "lcs length: " << getLcs(m, n).length()/2 << std::endl;
}


void Subsequence::arrayToString()
{
    for (int r = 0; r <= m; r++)
    {
        for (int c = 0; c <= n; c++)
        {
            std::cout << cArray[r][c] << " ";
        }
        std::cout << std::endl;
    }
}