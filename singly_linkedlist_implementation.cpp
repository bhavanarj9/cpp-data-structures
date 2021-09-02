#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class Linkedlist{
    public:
    node *head;

    Linkedlist(){
        head = NULL;
    }
    ~Linkedlist(){};

    void insert(int newdata){
        node* newnode = new node();
        newnode->data = newdata;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
        }
        else{
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp ->next = newnode;

        }
    }

    void display(){
        if(head == NULL){
            cout<<"Empty list"<<endl;
        }

        else{
            node *n = head;
            while(n!= NULL){
                cout<<n->data<<" ";
                n=n->next;
            }
            cout<<endl;
        }
    }

    void insertatbeginning(int newdata){
        node* newnode = new node();
        newnode->data = newdata;
        newnode->next = head;
        head = newnode;
    }

    void insertatend(int newdata){
        node* newnode = new node();
        newnode->data=newdata;
        newnode->next=NULL;
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void insertposition(int newdata, int pos){
        
        node* newnode = new node();
        newnode->data = newdata;
        newnode->next = NULL;

        if(pos<1){
            cout<<"Invalid position "<<endl;
        }
        else if(pos == 1){
            newnode->next = head;
            head = newnode;
        }
        else{
            node *temp = head;
           for(int i=1;i<pos-1;i++){
               if(temp != NULL){
                   temp = temp->next;
               }
           }

           if(temp != NULL){
               newnode->next=temp->next;
               temp->next = newnode;
           }

           else{
               cout<<" Previous node is null"<<endl;
           }

        }

    
    }

    void deleteatbeginning(){
        node *temp = new node();
        temp= head;
        head=head->next;
        delete temp;
    }

    void deleteatend(){
        node *temp,*prevnode;
        temp = head;

        while(temp->next != NULL){
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = NULL;
        delete temp;
    }

    void deleteatpos(int pos){
        int i = 1;
        node *temp, *nextnode;
        temp = head;

        while(i<pos -1){
            temp=temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        delete nextnode;
    }

    void getlenght(){
        int i=0;
        node *temp;
        temp = head;
        
        while(temp != 0){
            i++;
            temp = temp->next;
        }
        cout<<"Lenght of linkedlist is "<<i<<endl;
    }

    void reverselist(){
        node *temp = head;
        node *prevnode = NULL;
        node *nextnode = NULL;

        while(temp != NULL){
            head = temp;
            nextnode=temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = nextnode;
        }

    }

};
    
int main(){

    Linkedlist *list = new Linkedlist();

    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);
    list->insert(5);
    list->insertatbeginning(9);
    list->insertatend(11);
    list->insertposition(55,6);
    list->display();

    cout<<"Reversed list is "<<endl;
    list->reverselist();
   

    list->display();
    list->getlenght();
    list->deleteatbeginning();
    list->deleteatpos(4);
    list->deleteatend();

    

    cout<<"the linked list is "<<endl;
    list->display();

    delete list;
    return 0;
    
}
