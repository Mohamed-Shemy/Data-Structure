//
//  Stack.hpp
//  Stack and Queue
//  Xcode C++ Project
//  Created by Mohamed Shemy on 3/20/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp


template<typename T>class Stack
{
public:
    Stack();
    Stack(int size);
    ~Stack();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void push(T newItem);
    void pop();
    int  length();
    T top();
private:
    T *info;
    int max = 100;
    int t;
};

template<typename T> Stack<T>::Stack()
{
    info = new T[max];
    t = 0;
}

template<typename T> Stack<T>::Stack(int size)
{
    max = size;
    info = new T[max];
    t = 0;
}

template<typename T> Stack<T>::~Stack()
{
    //delete [] info;
}

template<typename T> void Stack<T>::makeEmpty()
{
    t = 0;
}

template<typename T> bool Stack<T>::isEmpty()
{
    return (t == 0);
}

template<typename T> bool Stack<T>::isFull()
{
    return (t == max);
}

template<typename T> void Stack<T>::push(T newItem)
{
    info[t++] = newItem;
}

template<typename T> void Stack<T>::pop()
{
    t--;
}

template<typename T> T Stack<T>::top()
{
    return info[t];
}

template<typename T> int Stack<T>::length()
{
    return t;
}
















#endif /* Stack_hpp */
