//
//  AdvList.hpp
//  LinkedLists
//
//  Created by Mohamed Shemy on 4/5/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef AdvList_hpp
#define AdvList_hpp


#include <iostream>


template <typename T>
struct Node1
{
    T *info;
    Node1<T> *next;
};



template <typename T> class List
{
public:
    List();
    List(int);
    ~List();
    bool isEmpty();
    bool isFull();
    int  length();
    void add(T);
    bool del(T);
    bool get(int);
    void clear();
    void reset();
    void retrive(T&);
    T next();
private:
    int max;
    int len;
    int index;
    Node1<T> * pos;
    Node1<T> *data;
};

template<typename T>
inline List<T>::List()
{
    max = 10;
    len = 0;
    index = 0;
    pos = NULL;
    data = NULL;
}

template<typename T>
inline List<T>::List(int size)
{
    max = size;
    len = 0;
    index = 0;
    pos = NULL;
    data = NULL;
}

template<typename T>
inline List<T>::~List()
{
    clear();
}

template<typename T>
inline bool List<T>::isEmpty()
{
    return (data == NULL);
}

template<typename T>
inline bool List<T>::isFull()
{
    Node1<T> * tmp = new Node1<T>;
    if (tmp != NULL)
    {
        delete tmp;
        return false;
    }
    return true;
}

template<typename T>
inline int List<T>::length()
{
    return len;
}

template<typename T>
inline void List<T>::add(T item)
{
    if (index == 0)
    {
        Node1<T> *node1 = new Node1<T>;
        node1->info = new T[3];
        node1->info[index++] = item;
        node1->next = data;
        data = node1;
    }
    else
    {
        data->info[index++] = item;
    }
    if (index == max)
        index = 0;
    
    len++;
}

template<typename T>
inline bool List<T>::del(T item)
{
    return false;
}

template<typename T>
inline bool List<T>::get(int i)
{
    return false;
}

template<typename T>
inline void List<T>::clear()
{
    Node1<T> *tmp;
    
    while (data != NULL)
    {
        tmp = data;
        data = data->next;
        delete tmp;
    }
    len = 0;
    pos = NULL;
}

template<typename T>
inline void List<T>::reset()
{
    pos = NULL;
}

template<typename T>
inline void List<T>::retrive(T & item)
{
    
    
}

template<typename T>
inline T List<T>::next()
{
    return T();
}


#endif /* AdvList_hpp */
