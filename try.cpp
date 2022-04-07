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

struct Data{
  int withFence;
  long long x;
  long long y;
};

Data vec;
vector<Data> vec1;
//Data tmp;

template <class T>
LinkedList<T>::LinkedList():length(0){
   first = NULL;
};

template <class T>
void LinkedList<T>::insert(T x, T y,T fence){
     Node<T>* tmp = new Data;
      Data data;
     tmp->data = (data.x, data.y);
     tmp->next = NULL;
     if(first == 0){
        first = tmp;
        return;
     }
     Node<T>* current = first;
     while(current -> next != 0){
        current = current -> next;
     }
     current->next = tmp;
}

template <class T>
void LinkedList<T>::deletion(T x, T y){
;
}

template <class T>
void LinkedList<T>::show(){
 ;
 }
//vector

bool sortsec(const Data& a, const Data& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void plant(long long x,long long y,int withFence){
    

    vec.x = x;
    vec.y = y;
    vec.withFence = withFence;
    vec1.push_back(vec);
    //cout << vec1.size();

}
void thief(long long x,long long y){
for (vector<Data>::iterator it = vec1.begin(); it != vec1.end(); it++) {
        Data tmp1 = *it;
        //it = find(vec1.begin(), vec1.end(), tmp1);
        if(tmp1.x == x && tmp1.y == y+1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x && tmp1.y == y-1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x+1 && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x-1 && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
}
}

void superThief(long long x,long long y){
 for (vector<Data>::iterator it = vec1.begin(); it != vec1.end(); it++) {
        Data tmp1 = *it;
        //it = find(vec1.begin(), vec1.end(), tmp1);
        if(tmp1.x == x && tmp1.y == y+1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x && tmp1.y == y-1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x+1 && tmp1.y == y+1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x+1 && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x+1 && tmp1.y == y-1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x-1 && tmp1.y == y-1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x-1 && tmp1.y == y &&tmp1.withFence == 0){
            vec1.erase(it);
        }
        if(tmp1.x == x-1 && tmp1.y == y+1 &&tmp1.withFence == 0){
            vec1.erase(it);
        }
}
}

void display(){
    int len;
    cout << "Display" << endl;
    len = vec1.size();
    sort(vec1.begin(),vec1.end(),sortsec);
    for (auto &a:vec1) cout << "(" << a.x << "," << a.y << ")" <<'\n';
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string operation;
        cin >> operation;

        if(operation == "PLANT"){
            long long x,y;
            int withFence;
            cin >> x >> y >> withFence;
            plant(x,y,withFence);
        }
        else if(operation == "THIEF"){
            long long x,y;
            cin >> x >> y;
            thief(x,y);
        }
        else if(operation == "SUPER_THIEF"){
            long long x,y;
            cin >> x >> y;
            superThief(x,y);
        }
        else if(operation == "DISPLAY"){
            display();
        }
        else{
            cout << "error" << "\n";
        }
    }
    return 0;
}