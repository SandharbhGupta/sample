#include<bits/stdc++.h>
using namespace std;

struct Node{   
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};


Node* convertToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
Node* RemoveHead(Node* head){
    Node* temp = head;
    head=temp->next;
    delete temp;

    return head;
}
Node* Removetail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next !=nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;

    return head;
}

Node* RemoveK(Node* head,int k){
    if(head==NULL) return head;

    // if first element delete
    if(k==1){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    int cnt=0;
    Node* temp =head;
    Node* prev = NULL;

    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* RemoveEl(Node* head,int value){
    if(head==NULL) return head;
    if(head->data==value){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        if(temp->data==value){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;
}

// Insertion

Node* insertAtHead(Node* head,int value){
    Node* temp = new Node(value,head);
    return temp;
}

Node* insertAtTail(Node* head,int value){
    if(head == NULL){
        return new Node(value);
    }

    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(value);
    temp->next=newNode;

    return head;
}

Node* insertAtPosition(Node* head,int value,int k){
    if(head==NULL){
        if(k==1){
            return new Node(value,head);
        }else{
            return head;
        }
    }

    if(k==1){
            return new Node(value,head);
        }
    int cnt =0;
    Node* temp = head;

    while(temp){
        cnt++;
        if(cnt==k-1){
            Node* newNode = new Node(value,temp->next);
            temp->next=newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head,int el,int value){
    if(head==NULL){
        return NULL;
    }
    if(head->data==value){
        return new Node(el,head);
    }

    Node* temp=head;
    while(temp->next!=NULL){

        if(temp->next->data==value){
            Node* newNode = new Node(el,temp->next);
            temp->next=newNode;
            break;
        }

        temp=temp->next;
    } 

    return head;
}
int main ()
{
    vector<int> arr={2,3,4,6,10};
    // Node* y = new Node(arr[4],nullptr);
    // cout<<y->data;

    Node* head = convertToLinkedList(arr);
    // cout<<head->data;
    
    //remove Head

    // head=RemoveHead(head);
    // print(head);

    // head=Removetail(head);
    // print(head);

    // At specific position
    // head=RemoveK(head,4);
    // print(head);

    // head = RemoveEl(head,2);
    // print(head);

    // Insertion

    // head=insertAtHead(head,19);
    // print(head);

    // head=insertAtTail(head,18);
    // print(head);

    // head = insertAtPosition(head,30,6);
    // print(head);

    head=insertBeforeValue(head,50,2);//Insert 50 before 4
    print(head);
return 0;
}