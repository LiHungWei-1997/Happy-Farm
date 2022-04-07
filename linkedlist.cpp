#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

bool isEmpty(node *head);
void insertAsFistElement(node *&head, node *&last, int data);
void insert(node *&head, node *&last, int data);
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head){
    if(head == NULL)
        return true;
    else
        return false;
}

void insertAsFistElement(node *&head, node *&last, int data){
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    head = tmp;
    last = tmp;

}

void insert(node *&head, node *&last, int data){
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

void remove(node *&head, node *&last){
    if(isEmpty(head))
        cout<< "Empty link list!"<<endl;
    else if(head == last){
        delete head;
        head = NULL;
        last = NULL;
    }
    else{
        node *tmp = head;
        head = head->next;
        delete tmp;
    }

}
void showList(node *current){
    if(isEmpty(current))
        cout<<"the list is empty!"<<endl;
    else{
        while(current != NULL){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"NULL"<<endl;
    }
}

node* createListfromArr(int arr[], int n){
    for (int i=0; i<n; i++){
        if (n == 0)
            return NULL;
        node* head = NULL;
        node* last = NULL;
        for (int i=0; i<n; i++){
            insert(head, last, arr[i]);
        }
        return head;
    }
}

int main() {
    
    node *head = NULL;
    node *last = NULL;
    int data = 5;
    insertAsFistElement(head, last, 4);
    if (isEmpty(head))
        cout << "Empty!"<<endl;
    insert(head, last, data);
    showList(head);
    remove(head, last);
    showList(head);
    int arr[] = {5, 4, 3, 2, 1 ,0};
    node *nhead = createListfromArr(arr, 6);
    showList(nhead);

    return 0;
}