#include "UsList.hpp"

UsList::UsList(void)
{
    length = 0;
    curPos = 0;
}

void UsList::clear()
{
    letters[0] = 0;
    length = 0;
    curPos = 0;
}

bool UsList::isFull()
{
    return (length == MAX_ITEM - 1);
}

bool UsList::isEmpty()
{
    return (length == 0);
}

void UsList::insert(char newItem)
{
    letters[length++] = newItem;
}

bool UsList::remove(char item)
{
    for(int i = 0 ; i < length ; i++)
    {
        if(item == letters[i])
        {
            letters[i] = letters[length - 1];
            length --;
            return true;
        }
    }
    return false;
}

void UsList::reset()
{
    curPos = 0;
}

char UsList::next()
{
    return letters[curPos++];
}

int  UsList::Length()
{
    return length;
}
