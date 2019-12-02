//
//  Tree.hpp
//  FileCompression
//
//  Created by Mohamed Shemy on 4/8/16.
//  Copyright © 2016 SHEMY. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp
#include<iostream>
template <typename T>
struct Node
{
    T  info;   		     // Data member
    Node<T>*  left;     // Pointer to left child
    Node<T>*  right;   // Pointer to right child
};

template <typename T>
class Tree
{
public:
    Tree(void);
    ~Tree(void);
    bool IsEmpty ( ) const;
    bool IsFull ( ) const;
    int  NumberOfNodes ( ) const;
    void InsertItem ( T  item );
    void DeleteItem (T  item , bool &found);
    void RetrieveItem ( T& item,  bool& found );
    void PrintTree ()  const;
private:
    void InsertItemHelper ( Node<T>*&  ptr, T  item );
    bool DeleteItemHelper(Node<T>*&  ptr, T  item);
    void DeleteNode(Node<T>*& tree);
    int NumberOfNodesHelper ( Node<T>*  ptr ) const;
    Node<T>*  root;
};



// ------------------------------>|

#endif /* Tree_hpp */
