#include <iostream>
using namespace std;
class Node {
    public :
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void InsertAtLast(Node* &head, int d){
    Node * tail = new Node(d);
    tail -> next = NULL;
    head ->next = tail;
    
}
void InsertAtBegin(Node* &head, int d){
    Node * tmp = new Node(d);
    tmp -> next = head;
    head  = tmp;
}

void insertAtPosition(Node* &head, int position, int d){
    if(position==1){
        InsertAtBegin(head, d);
        return;
    }
    Node* tmp = head;
    int cnt=1;
    while(cnt < position-1){
        tmp = tmp->next;
        cnt++;
    }
    Node* inser = new Node(d);
    inser -> next = tmp -> next;
    tmp -> next = inser;
}

void traverse(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}


Node* kthReverse(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    //Reversing first kth group of Node
    int count=0;
    while(curr != NULL && count<k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(curr!=NULL) {
        head -> next = kthReverse(forward, k);
    }
    return prev;
}

int main(){
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node* head = node1;
    cout << "Insert 10 as a head : "<<endl;
    traverse(head);

    InsertAtLast(head,12);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);

    InsertAtBegin(head,13);
    cout << "Insert 13 At Left Side : "<<endl;
    traverse(head);

    cout << "After Inserted at 3rd Position : "<<endl;
    insertAtPosition(head, 3, 11);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head, 1, 14);
    traverse(head);
    
    cout<<"Kth Traverse Node : ";
    traverse(kthReverse(head, 3));
    
    

 
}