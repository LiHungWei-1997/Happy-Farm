#include "function.h"
#include <iostream>
#include <string>
#include <set>
#include <math.h>
#include <vector>
//#include <vector>
#include <algorithm>
//#include <utility>

using namespace std;

struct Data
{
    long long x;
    long long y;
    int withFence;
};

Data vec;
vector<Data> vec_plant;
// Data tmp;

/*
template <class T>
LinkedList<T>::LinkedList():length(0){
   first = NULL;
};

template <class T>
void LinkedList<T>::insert(T x, T y,T fence){
;
}

template <class T>
void LinkedList<T>::deletion(T x, T y){
;
}

template <class T>
void LinkedList<T>::show(){
 ;
 }
 */

// plant

void plant(long long x, long long y, int withFence)
{
    vec.x = x;
    vec.y = y;
    vec.withFence = withFence;
    vec_plant.push_back(vec);
}

void thief(long long x, long long y)
{
    for (vector<Data>::iterator plant = vec_plant.begin(); plant != vec_plant.end(); plant++)
    {
        Data tmp = *plant;

        if (tmp.withFence == 0) // delete plant 0
        {
            if (tmp.x == x)
            {
                if (tmp.y == y || tmp.y == (y - 1) || tmp.y == (y + 1))
                {
                    vec_plant.erase(plant);
                }
            }
            if (tmp.y == y)
            {
                if (tmp.x == (x - 1) || tmp.x == (x + 1))
                {
                    vec_plant.erase(plant);
                }
            }
        }
    }
}

void superThief(long long x, long long y)
{
    for (vector<Data>::iterator plant = vec_plant.begin(); plant != vec_plant.end(); plant++)
    {
        Data tmp = *plant;

        if (tmp.withFence == 0) // delete plant 0
        {
            if (tmp.x == (x + 1))
            {
                if (tmp.y == y || tmp.y == (y - 1) || tmp.y == (y + 1))
                {
                    vec_plant.erase(plant);
                }
            }
            if (tmp.x == x)
            {
                if (tmp.y == y || tmp.y == (y - 1) || tmp.y == (y + 1))
                {
                    vec_plant.erase(plant);
                }
            }
            if (tmp.x == (x - 1))
            {
                if (tmp.y == y || tmp.y == (y - 1) || tmp.y == (y + 1))
                {
                    vec_plant.erase(plant);
                }
            }
        }
    }
}

bool plant_sort(const Data &a, const Data &b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

void display()
{
    int len;
    len = vec_plant.size();
    cout << "Display" << endl;
    sort(vec_plant.begin(), vec_plant.end(), plant_sort);
    for (int i = 0; i < len; i++)
    {
        cout << "(" << vec_plant[i].x << "," << vec_plant[i].y << ")" << endl;
    }
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

template <class T>
void LinkedList<T>::deletion(T x, T y)
{
    Node<T> *current = first;
    Node<T> *previous = 0;
    while (current != 0)
    {                            // Traversal
        previous = current;      // 如果current指向NULL
        current = current->next; // 或是current->data == x
    }
    if (current->fence == 0) // delete plant without fence
    {
        if (current->x == x & current->y == y)
        {
            if (current == first) // delete first
            {
                first = current->next;
                delete current;
                current = 0;
            }
            else
            {
                previous->next = current->next;
                delete current;
                current = 0;
            }
            // break;
        }
    }
}

template <class T>
void LinkedList<T>::deletion(T x, T y)
{
    Node<T> *current = first;
    Node<T> *previous = 0;

    while (current != 0)
    {
        if (current->fence == 0) // delete plant without fence
        {
            if (current->x == x & current->y == y)
            {
                if (current == first) // delete first
                {
                    first = current->next;
                    delete current;
                    current = 0;
                }
                else
                {
                    previous->next = current->next;
                    delete current;
                    current = 0;
                }
                break;
            }
        }
        previous = current;
        current = current->next;
    }
}