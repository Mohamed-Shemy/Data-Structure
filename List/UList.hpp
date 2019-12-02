//
//  UList.hpp
//  LinkedLists
//  Xcode C++ Project
//  Created by Mohamed Shemy on 3/25/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef UList_hpp
#define UList_hpp

template <class T> class UList
{
public:
    UList();
    ~UList();
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
inline UList<T>::UList()
{
}

template<class T>
inline UList<T>::~UList()
{
}

template<class T>
inline bool UList<T>::isFull()
{
    return false;
}

template<class T>
inline bool UList<T>::isEmpty()
{
    return false;
}

template<class T>
inline bool UList<T>::retrive(T &)
{
    return false;
}

template<class T>
inline void UList<T>::reset()
{
}

template<class T>
inline void UList<T>::makeEmpty()
{
}

template<class T>
inline void UList<T>::insert(T)
{
}

template<class T>
inline void UList<T>::del(T)
{
}

template<class T>
inline int UList<T>::length()
{
    return 0;
}

template<class T>
inline T UList<T>::next()
{
    return T();
}


#endif /* UList_hpp */
