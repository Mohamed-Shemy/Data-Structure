//
//  LCQueue.hpp
//  AdvQueue
//
//  Created by Mohamed Shemy on 4/1/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef LCQueue_hpp
#define LCQueue_hpp

#include <iostream>

class full_queue {};
class empty_queue {};

struct Node
{
    T info;
    Node<T> *next;
};

template <typename T> class LCQueue
{
public:
    LCQueue();
    ~LCQueue();
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    void Enqueue(T);
    T Dequeue();
private:
    Node<T> *f;
    Node<T> *r;
};

template<typename T> inline LCQueue<T>::LCQueue()
{
    f = r = NULL;
}

template<typename T> inline LCQueue<T>::~LCQueue()
{
    makeEmpty();
}

template<typename T>  bool LCQueue<T>::isEmpty()
{
    return (f == NULL && r == NULL);
}

template<typename T> inline bool LCQueue<T>::isFull()
{
    Node<T> * test = new Node<T>;
    if (test != NULL)
    {
        delete test;
        return false;
    }
    return true;
}

template<typename T> inline void LCQueue<T>::makeEmpty()
{
    Node<T> *node;
    
    while (f != r)
    {
        node = f;
        f = f->next;
        delete node;
    }
    r = NULL;
}

template<typename T> inline void LCQueue<T>::Enqueue(T item)
{
    if (isFull())
        throw full_queue();
    else
    {
        Node<T> *node = new Node<T>;
        node->info = item;
        node->next = NULL;
        if (r == NULL)
            f = node;
        else
            r->next = node;
        r = node;
        r->next = f;
    }
}

template<typename T> inline T LCQueue<T>::Dequeue()
{
    if (isEmpty())
        throw "empty_queue_exception!\n";
    else
    {
        T item;
        bool ok = (f == r);
        Node<T> *node;
        node = f;
        item = f->info;
        f = f->next;
        r->next = f;
        delete node;
        if (ok)
            r = f = NULL;
        return item;
    }
}


#endif /* LCQueue_hpp */
