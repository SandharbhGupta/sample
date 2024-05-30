#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* conver2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* temp = head;
    head=head->next;
    temp->next=NULL;
    head->back=NULL;
    delete temp;
    return head;

}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }

    Node* prev = temp->back;
    prev->next=NULL;
    temp->back=NULL;
    delete(temp);

    return head;
}

Node* deleteKthEl(Node *head,int k){
    if(head==NULL){
        return NULL;
    }
    int count  = 0;
    Node* temp = head;
    while(temp->next!=NULL){
        count++;
        if(count == k) break;
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
    }
    if(prev==NULL){
        return deleteHead(head);
        
    }
    else if(front==NULL){
        return deleteTail(head);
         
    }
    else{
        prev->next=front;
        front->back=prev;

        temp->next=temp->back=nullptr;
        delete(temp);
    }
    return head;
}

void deleteNode(Node* temp){

    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = NULL;
        temp->back=NULL;
        delete(temp);
    }

    prev->next=front;
    front->back=prev;

    temp->next=temp->back=NULL;
}

Node* insertBeforeHead(Node* head,int val){
    if(head==NULL){
        return NULL;
    }
    Node* front = head->next;
    Node* newNode = new Node(val,front,nullptr);
    newNode->next=head;
    head->back=newNode;

    return newNode;
}

Node* insertBeforeTail(Node* head,int val){
    if(head==NULL) return NULL;

    Node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }

    Node* prev = tail->back;
    
    Node* newNode= new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;

    return head;
}

Node* insertBeforeKthEl(Node* head,int k,int val){
    int cnt =0;
    Node* temp = head;

    while(temp->next!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }

    if(k==1){
        return insertBeforeHead(head,val);
    }

    Node* prev = temp->back;

    Node* newNode = new Node(val,temp,prev);
    prev->next=newNode;


    return head;
}

void insertBeforeNode(Node* node,int val){

    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back=newNode;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main ()
{
    vector<int> arr = {12,3,5,7};
    Node* head = conver2DLL(arr);
    // print(head);
    
    //Deletion..........

    // head = deleteHead(head);
    // print(head);

    // head = deleteTail(head);
    // print(head);

    // head = deleteKthEl(head,4);
    // print(head);

    // deleteNode(head->next);
    // print(head);

    // Insertion..........
    
    // head = insertBeforeHead(head,10);
    // print(head);

    // head=insertBeforeTail(head,15);
    // print(head);

    // head = insertBeforeKthEl(head,3,25);
    // print(head);

    insertBeforeNode(head->next,110);
    print(head);

return 0;
}