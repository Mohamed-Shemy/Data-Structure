//
//  SList.hpp
//  LinkedLists
//  Xcode C++ Project
//  Created by Mohamed Shemy on 3/25/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef SList_hpp
#define SList_hpp


template<class T> struct Node
{
    T info;
    Node<T> *next;
};

template <class T> class SList
{
public:
    SList();
    ~SList();
    bool isFull();
    bool isEmpty();
    bool retrive(T&);
    void reset();
    void makeEmpty();
    void insert(T);
    void del(T);
    int  length();
    T next();
private:
    Node<T> *data;
    Node<T> *curpos;
    int len;
};

template<class T>
inline SList<T>::SList()
{
}

template<class T>
inline SList<T>::~SList()
{
}

template<class T>
inline bool SList<T>::isFull()
{
    return false;
}

template<class T>
inline bool SList<T>::isEmpty()
{
    return false;
}

template<class T>
inline bool SList<T>::retrive(T &)
{
    return false;
}

template<class T>
inline void SList<T>::reset()
{
}

template<class T>
inline void SList<T>::makeEmpty()
{
}

template<class T>
inline void SList<T>::insert(T)
{
}

template<class T>
inline void SList<T>::del(T)
{
}

template<class T>
inline int SList<T>::length()
{
    return 0;
}

template<class T>
inline T SList<T>::next()
{
    return T();
}


#endif /* SList_hpp */
