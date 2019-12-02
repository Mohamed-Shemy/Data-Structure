//
//  String.cpp
//  String
//
//  Created by Mohamed Shemy on 3/7/16.
//  Copyright © 2016 Mac OS X El Capitan. All rights reserved.
//

#include "String.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

//--------------->|
void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
void GetTilNew(bool skip, char letters[], std::ifstream& inFile);

void String::GetStringFile(bool skip, char charsAllowed, std::ifstream& inFile)
{
    switch (charsAllowed)
    {
        case ALPHA_NUM: GetAlphaNum(skip, letters, inFile);	break;
        case ALPHA: GetAlpha(skip, letters, inFile);		    break;
        case NON_WHITE: GetNonWhite(skip, letters, inFile);	break;
        case NOT_NEW: GetTilNew(skip, letters, inFile);  		break;
    }
}
void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
{
    using namespace std;
    char letter;
    int count = 0;
    if (skip)
    {
        inFile.get(letter);
        while (!isalnum(letter) && inFile)
            inFile.get(letter);
    }
    else
        inFile.get(letter);
    if (!inFile || !isalnum(letter))
        letters[0] = '\0';
    else
    {
        do
        {
            letters[count] = letter;
            count++;
            inFile.get(letter);
        } while (isalnum(letter) && inFile && (count < MAX_CHARS));
        letters[count] = '\0';
        if (count == MAX_CHARS && isalnum(letter))
            do
            {
                inFile.get(letter);
            } while (isalnum(letter) && inFile);
    }
}
void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
{
    using namespace std;
    char letter;
    int count = 0;
    if (skip)
    {
        inFile.get(letter);
        while ((letter == '\n') && inFile)
            inFile.get(letter);
    }
    else
        inFile.get(letter);
    if (!inFile || letter == '\n')
        letters[0] = '\0';
    else
    {
        do
        {
            letters[count] = letter;
            count++;
            inFile.get(letter);
        } while ((letter != '\n') && inFile && (count < MAX_CHARS));
        letters[count] = '\0';
        if (count == MAX_CHARS && letter != '\n')
            do
            {
                inFile.get(letter);
            } while ((letter != '\n') && inFile);
    }
}
void GetAlpha(bool skip, char letters[], std::ifstream& inFile)
{
    using namespace std;
    char letter;
    int count = 0;
    if (skip)
    {
        inFile.get(letter);
        while (!isalpha(letter) && inFile)
            inFile.get(letter);
    }
    else
        inFile.get(letter);
    if (!inFile || !isalpha(letter))
        letters[0] = '\0';
    else
    {
        do
        {
            letters[count] = letter;
            count++;
            inFile.get(letter);
        } while (isalpha(letter) && inFile && (count < MAX_CHARS));
        letters[count] = '\0';
        if (count == MAX_CHARS && isalpha(letter))
            do
            {
                inFile.get(letter);
            } while (isalpha(letter) && inFile);
    }
}
void GetNonWhite(bool skip, char letters[], std::ifstream& inFile)
{
    //iswspace
    using namespace std;
    char letter;
    int count = 0;
    if (skip)
    {
        inFile.get(letter);
        while (!iswspace(letter) && inFile)
            inFile.get(letter);
    }
    else
        inFile.get(letter);
    if (!inFile || !iswspace(letter))
        letters[0] = '\0';
    else
    {
        do
        {
            letters[count] = letter;
            count++;
            inFile.get(letter);
        } while (iswspace(letter) && inFile && (count < MAX_CHARS));
        letters[count] = '\0';
        if (count == MAX_CHARS && iswspace(letter))
            do
            {
                inFile.get(letter);
            } while (iswspace(letter) && inFile);
    }
}
//--------------->|

void String::MakeEmpty()
{
    letters[0] = 0;
}
void String::PrintToScreen(bool newLine)
{
    using namespace std;
    if (newLine)
        cout << endl;
    cout << letters;
}
void String::PrintToFile(bool newLine, std::ofstream& outFile)
{
    using namespace std;
    if (newLine)
        outFile << endl;
    outFile << letters;
}
void String::CopyString(String& newString)
{
    int i = 0;
    for (i = 0; i < LengthIs(); i++)
        newString.letters[i] = letters[i];
    newString.letters[i] = '\0';
}
int  String::LengthIs()
{
    int i = 0;
    while (letters[i] != 0)
        i++;
    return i;
}
int String::CompareTo(String&str_com)
{
    int stat = 0;
    int i = 0;
    while (i != LengthIs())
    {
        if (letters[i] != str_com.letters[i])
        {
            if (letters[i] < str_com.letters[i])
                stat = 1;
            else
                stat = -1;
            break;
        }
        else
            stat = 0;
        i++;
    }
    return stat;
}

String::String(void)
{
    MakeEmpty();
}