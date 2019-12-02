#pragma once
#include<fstream>
#include<iostream>
const int MAX_CHARS = 100;
enum InType { ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW };
class String
{
public:
    String(void);
    void MakeEmpty();
    void GetString(bool skip, char charsAllowed);
    void GetStringFile(bool skip, char charsAllowed, std::ifstream& inFile);
    int  CompareTo(String&str_com);
    void PrintToScreen(bool newLine);
    void PrintToFile(bool newLine, std::ofstream& outFile);
    int  LengthIs();
    void CopyString(String& newString);
    
    
private:
    char letters[MAX_CHARS + 1];
};