#include <iostream>
#include <string>
#include "function.h"

using namespace std;

struct node
{
    int withFence;
    long long x;
    long long y;
    node* next;
};

template <class T>
LinkedList<T>::LinkedList() : length(0)
{
    first = NULL;
};

bool isEmpty(node *first){
    if(first == NULL)
        return true;
    else
        return false;
}

template <class T>
void LinkedList<T>::insert(T x, T y, T fence)
{
    if (isEmpty(head))
        insertAsFistElement(head, last, data);
    else{
        node *tmp = new node;
        tmp->data = data;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

template <class T>
void LinkedList<T>::deletion(T x, T y)
{
    return 0;
}

template <class T>
void LinkedList<T>::show()
{
    return 0;
}