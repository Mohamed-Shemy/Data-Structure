//
//  Tree.cpp
//  FileCompression
//
//  Created by Mohamed Shemy on 4/8/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#include <stdio.h>
#include "Tree.hpp"


template <typename T>
Tree<T>::Tree(void)
{
    root = NULL;
}

template <typename T>
bool Tree<T>::IsEmpty ( ) const
{
    return (root == NULL);
}

template <typename T>
bool   Tree<T>::IsFull ( ) const
{
    
    Node<T>* node =new Node<T>;
    if(node==NULL)
        return true ;
    delete node;
    return false;
}

template <typename T>
void Tree<T>::InsertItem ( T  item )
{
    InsertItemHelper ( root,item );
    
}

template <typename T>
void Tree<T>::InsertItemHelper ( Node<T>*&  ptr, T  item )
{
    if (ptr==NULL)
    {
        ptr = new Node<T>;
        ptr->left = NULL;
        ptr->right=NULL;
        ptr->info = item;
        
    }
    else  if ( item < ptr->info)
        InsertItemHelper ( ptr->left,  item );
    else
        InsertItemHelper ( ptr->right,  item );
}


template <typename T>
int Tree<T>::NumberOfNodes ( ) const
{
    return NumberOfNodesHelper(root);
}

template <typename T>
void Tree<T>::DeleteItem (T item , bool &found )
{
    found = DeleteItemHelper(root , item);
}


template <typename T>
bool Tree<T>::DeleteItemHelper ( Node<T>*&  ptr, T  item )
{
    if(ptr == NULL)
        return false;
    if(item < ptr->info)
        DeleteItemHelper(ptr->left , item);
    else if(item > ptr->info)
        DeleteItemHelper(ptr->right , item);
    else
    {
        DeleteNode(ptr);
        return true;
    }
}

template <typename T>
void Tree<T>::DeleteNode(Node<T>*& tree)
{
    T data;
    Node<T>* tempPtr;
    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        Node<T> *tmpleft = tree->left;
        while (tmpleft->right != NULL)
            tmpleft = tmpleft->right;
        data = tmpleft->info;
        tree->info = data;
        DeleteItemHelper(tree->left, data); // Delete predecessor node.
    }
}


template <typename T>
int Tree<T>::NumberOfNodesHelper ( Node<T>*  ptr ) const
{
    if(ptr==NULL)
        return 0;
    else
        return  NumberOfNodesHelper(ptr->left)+NumberOfNodesHelper(ptr->right)+1;
}


template <typename T>
void    Tree<T>::RetrieveItem ( T& item,  bool& found )
{
    Node<T>* current = root;
    
    while (1)
    {
        if(current==NULL)  {found = false;return; }
        else if(item > current->info)
            current = current ->right;
        else if(item < current->info)
            current = current ->left;
        else {found = true; return;}
    }
}

template <typename T>
Tree<T>::~Tree(void)
{
}

