//
//  LStack.hpp
//  LStack
//  Xcode C++ Project
//  Created by Mohamed Shemy on 3/22/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef LStack_hpp
#define LStack_hpp

class full_stack{};
class empty_stack{};

template <typename T>
struct Node
{
    T *info;
    Node *next;
};

template <typename T>
class LStack
{
public:
    LStack();
    ~LStack();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void push(T);
    T pop();
private:
    Node<T> *node;
};

template <typename T> inline LStack<T>::LStack()
{
    node = NULL;
}

template <typename T> inline LStack<T>::~LStack()
{
    makeEmpty();
}

template <typename T> inline void LStack<T>::makeEmpty()
{
    Node *tmp;
    
    while(node != NULL)
    {
        tmp = node;
        node = node->next;
        delete tmp;
    }
}

template <typename T> inline bool LStack<T>::isEmpty()
{
    return (node == NULL);
}

template <typename T> inline bool LStack<T>::isFull()
{
    Node *full = new Node;
    if(full == NULL)
        return true;
    else
    {
        delete full;
        return false;
    }
}

template <typename T> inline void LStack<T>::push(T item)
{
    if(!isFull()
    {
        Node *loc = new Node;
        loc->info = item;
        loc->next = node;
        node = loc;
    }
    else
       throw full_stack();
}

template <typename T> inline T LStack<T>::pop()
{
    if(isEmpty())
        throw empty_stack();
    else
    {
        Node *tmp;
        tmp = node;
        T item = node->info;
        node = node->next;
        delete tmp;
        return item;
    }
}
















#endif /* LStack_hpp */
