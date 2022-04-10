#include "function.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList;
template <class T>
class Node;

template <class T>
Node<T>::Node(T x, T y, T fence) : x(x), y(y), fence(fence) {}

// compare function (not be used)
template <class T>
T Node<T>::compare(T x, T y)
{
    Node<T> *current;
    if ((y == current->y & x > current->x) || y > current->y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
LinkedList<T>::LinkedList() : length(0)
{
    first = NULL;
};

template <class T>
void LinkedList<T>::insert(T x, T y, T fence)
{
    Node<T> *newNode = new Node<T>(x, y, fence); // Set new memory

    if (first == 0) // If list doen't have node, let newNode be first
    {
        first = newNode;
    }

    Node<T> *current = first;
    Node<T> *previous = 0;
    while (current != 0) // Traversal
    {
        if ((y == current->y & x > current->x) || y > current->y)
        {
            previous = current;
            current = current->next;
        }
        else
        {
            break;
        }
    }
    if (y == current->y & x == current->x)
    {
        if (fence == 1)
        {
            current->fence = 1;
        }
    }
    else
    {
        if (previous == 0) // insert on first location
        {
            first = newNode;
            newNode->next = current;
        }
        else
        {
            previous->next = newNode;
            newNode->next = current;
        }
    }

    if (previous == 0) // insert on first location
    {
        first = newNode;
    }
    else
    {
        previous->next = newNode;
    }
}

template <class T>
void LinkedList<T>::deletion(T x, T y)
{
    Node<T> *current = first;
    Node<T> *previous = 0;

    while (current != 0) // Traversal
    {
        if (current->x == x & current->y == y)
        {
            break;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    if (current != 0)
    {
        if (current->fence == 0) // delete plant without fence
        {
            if (current == first) // delete first
            {
                first = current->next;
                // delete current; (time limit)
            }
            else
            {
                previous->next = current->next;
                // delete current; (time limit)
            }
        }
    }
}

template <class T>
void LinkedList<T>::show()
{
    Node<T> *current = first; // use pointer to make *current move in list
    cout << "Display" << endl;

    while (current != 0) // Traversal
    {
        cout << "(" << current->x << "," << current->y << ")" << endl;
        current = current->next;
    }
}

LinkedList<long long> farm;
/**  solving function  **/
void plant(long long x, long long y, int withFence)
{
    farm.insert(x, y, withFence);
}

void thief(long long x, long long y)
{
    farm.deletion(x, y);
    farm.deletion(x, y - 1);
    farm.deletion(x, y + 1);
    farm.deletion(x - 1, y);
    farm.deletion(x + 1, y);
}

void superThief(long long x, long long y)
{
    farm.deletion(x - 1, y - 1);
    farm.deletion(x - 1, y);
    farm.deletion(x - 1, y + 1);
    farm.deletion(x, y - 1);
    farm.deletion(x, y);
    farm.deletion(x, y + 1);
    farm.deletion(x + 1, y - 1);
    farm.deletion(x + 1, y);
    farm.deletion(x + 1, y + 1);
}

void display()
{
    farm.show();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("./output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        string operation;
        cin >> operation;

        if (operation == "PLANT")
        {
            long long x, y;
            int withFence;
            cin >> x >> y >> withFence;
            plant(x, y, withFence);
        }
        else if (operation == "THIEF")
        {
            long long x, y;
            cin >> x >> y;
            thief(x, y);
        }
        else if (operation == "SUPER_THIEF")
        {
            long long x, y;
            cin >> x >> y;
            superThief(x, y);
        }
        else if (operation == "DISPLAY")
        {
            display();
        }
        else
        {
            cout << "error"
                 << "\n";
        }
    }
    return 0;
}