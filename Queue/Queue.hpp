//
//  Queue.hpp
//  Stack and Queue
//  Xcode C++ Project
//  Created by Mohamed Shemy on 3/20/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp


template<typename T> class Queue
{
public:
    Queue();
    Queue(int max);
    ~Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void Enqueue(T);
    T Dequeue();
private:
    T *info;
    int max , f , r;
};

template<typename T> Queue<T>::Queue()
{
    max = 100;
    info = new T[max + 1];
    f = r = max - 1;
}

template<typename T> Queue<T>::Queue(int size)
{
    max = size;
    info = new T[max + 1];
    f = r = max - 1;
}

template<typename T> Queue<T>::~Queue()
{
    delete [] info;
}

template<typename T> void Queue<T>::makeEmpty()
{
    f = r = max - 1;
}

template<typename T> bool Queue<T>::isEmpty()
{
    return (f == r);
}

template<typename T> bool Queue<T>::isFull()
{
    return ((r + 1) % max == f);
}

template<typename T> void Queue<T>::Enqueue(T newItem)
{
    r = (r + 1) % max;
    info[r] = newItem;
}

template<typename T> T Queue<T>::Dequeue()
{
    f = (f + 1) % max;
    return info[f];
}










#endif /* Queue_hpp */





























