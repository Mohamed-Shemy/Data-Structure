#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T *info;
	Node<T> *next;
	int pos;
};


template <typename T>
class Queue
{
public:
	Queue();
	Queue(int max);
	~Queue();
	bool isEmpty();
	bool isFull();
	void makeEmpty();
	void Enqueue(T);
	T Dequeue();
private:
	int MAX;
	int index;
	Node<T> *f;
	Node<T> *r;
};

template<typename T>
inline Queue<T>::Queue()
{
	MAX = 10;
	index = 0;
	f = NULL;
	r = NULL;
}

template<typename T>
inline Queue<T>::Queue(int max)
{
	MAX = max;
	index = 0;
	f = NULL;
	r = NULL;
}

template<typename T>
inline Queue<T>::~Queue()
{
	makeEmpty();
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	return ((f == NULL) && (r == NULL));
}

template<typename T>
inline bool Queue<T>::isFull()
{
	Node<T> *node = new Node<T>;
	if (node == NULL)
		return true;
	delete node;
	return false;
}

template<typename T>
inline void Queue<T>::makeEmpty()
{
	Node<T> *node;
	while (f != r)
	{
		node = f;
		f = f->next;
		delete node;
	}
	delete f;
	f = NULL;
	r = NULL;
}

template<typename T>
inline void Queue<T>::Enqueue(T item)
{
	if (index == 0)
	{
		Node<T> *node = new Node<T>;
		node->info = new T[MAX];
		node->pos = MAX;
		node->info[index++] = item;
		if (f == NULL)
		{
			r = node;
			f = r;
		}
		else
		{
			r->next = node;
			r = node;
		}
		r->next = f;
	}
	else
		r->info[index++] = item;
	r->pos--;
	if (index == MAX)
		index = 0;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
	T item;
	if (f == f->next)
		 if (f->pos == MAX - 1)
		{
			item = f->info[MAX - 1];
			delete f;
			f = NULL;
			r = NULL;
		}
		else
			item = f->info[f->pos++];
	else
		if (f->pos == MAX - 1)
		{
			Node<T> *tmp = f;
			item = f->info[f->pos++];
			f = f->next;
			r->next = f;
			delete tmp;
		}
		else
			item = f->info[f->pos++];
	return item;
}
