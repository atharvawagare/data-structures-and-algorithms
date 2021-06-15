#include<iostream>
#include<stdlib.h>
using namespace std;

// Some global variables
int cnt;

struct Node{
    int roll;
    char name[50];
    struct Node* next;
};
// Here is the function to delete at location-----------------------------------------------------------------------------------
struct Node* deleteAtLocation(struct Node *head){
    int loc, pos=1;
    struct Node *prev_node, *temp;

    temp=head;

    cout<<"Enter Location > ";
    cin>>loc;

    if(loc>cnt){
        cout<<endl<<endl<<"Location "<<loc<<" Cannot be greater than Count "<<cnt;
    }
    else{
        if(loc==1){
            cout<<endl<<endl<<"Student "<<head->name<<" with Roll No "<<head->roll<<" is successfully deleted"<<endl;
            
            head=head->next;
        }
        else{
            while(loc!=pos){
                prev_node=temp;
                temp=temp->next;
                pos+=1;
            }
            cout<<endl<<endl<<"Student "<<temp->name<<" with Roll No "<<temp->roll<<" is successfully deleted"<<endl;

            prev_node->next=temp->next;
        }
        cnt-=1;
    }

    return head;
}
// deletelocation function ends here--------------------------------------------------------------------------------------------

// Here is the function to reverse the linked list------------------------------------------------------------------------------
struct Node* reverseLinkedList(struct Node *head){
    struct Node *prev_node, *current_node, *next_node;
    prev_node=0;
    current_node=next_node=head;

    while(next_node!=0){
        next_node=next_node->next;
        current_node->next=prev_node;
        prev_node=current_node;
        current_node=next_node;
    }

    head=prev_node;

    return head;
}
// reverse function ends here-----------------------------------------------------------------------------------------------

// Here is the function to delete node at end-----------------------------------------------------------------------------------
struct Node* deleteAtEnd(struct Node *head, struct Node *New_Node){

    cout<<"Student "<<New_Node->name<<" with Roll No "<<New_Node->roll<<" is successfully deleted"<<endl;

    struct Node *node, *prev_node;
    node=head;

    while(node->next!=0){
        prev_node=node;
        node=node->next;
    }

    prev_node->next=0;
    return prev_node;

}
// deleteend function ends here-----------------------------------------------------------------------------------------------

// Here is the function to delete node at begining------------------------------------------------------------------------------
struct Node* deleteAtStart(struct Node *head){

    cout<<"Student "<<head->name<<" with Roll No "<<head->roll<<" is successfully deleted"<<endl;

    head=head->next;

    cnt-=1;
    return head;

}
// deletestart function ends here-----------------------------------------------------------------------------------------------

// Here is the function to insert node at begining------------------------------------------------------------------------------
struct Node* insertAtStart(struct Node *head){

    struct Node *New_Node;
    New_Node=(struct Node*)malloc(sizeof(struct Node));

    cout<<endl<<"Enter Roll No (Integer Value) ";
    cin>>New_Node->roll;

    cout<<"Enter Name (String) ";
    cin>>New_Node->name;

    New_Node->next=head;
    
    cnt+=1;
    return New_Node;

}
// insertstart function ends here-----------------------------------------------------------------------------------------------

// Here is the function to insert node at given location------------------------------------------------------------------------
struct Node* insertAtLocation(struct Node *head){
    
    int loc, pos=1;
    struct Node *New_Node, *temp;

    New_Node=(struct Node*)malloc(sizeof(struct Node));
    temp=head;

    cout<<"Enter Location > ";
    cin>>loc;

    if(loc>cnt){
        cout<<endl<<endl<<"Location "<<loc<<" Cannot be greater than Count "<<cnt;
    }
    else{

        if(loc==1){

            cout<<endl<<"Enter Roll No (Integer Value) ";
            cin>>New_Node->roll;

            cout<<"Enter Name (String) ";
            cin>>New_Node->name;

            New_Node->next=head;
            head=New_Node;
        }
        else{
            while(loc-1!=pos){
            temp=temp->next;
            pos+=1;
            }

            cout<<endl<<"Enter Roll No (Integer Value) ";
            cin>>New_Node->roll;

            cout<<"Enter Name (String) ";
            cin>>New_Node->name;

            New_Node->next=temp->next;
            temp->next=New_Node;
        }
        cnt+=1;
    }

    return head;
}
// insertlocation function ends here--------------------------------------------------------------------------------------------

// Here is the function for Linked List Traversal-------------------------------------------------------------------------------
void traverseLinkedList(struct Node *head){

    struct Node *node;

    node=head;
    while(node!=0){

        cout<<endl<<endl;
        cout<<"Name : "<<node->name<<endl;
        cout<<"Roll No : "<<node->roll<<endl;

        node=node->next;
    }
}
// Traversing function ends here------------------------------------------------------------------------------------------------

// Here is the function for adding a new node-----------------------------------------------------------------------------------
struct Node* addNode(struct Node *Old_Node){

    struct Node *New_Node;

    New_Node=(struct Node*)malloc(sizeof(struct Node));

    cout<<endl<<"Enter Roll No (Integer Value) ";
    cin>>New_Node->roll;

    cout<<"Enter Name (String) ";
    cin>>New_Node->name;

    Old_Node->next=New_Node;

    New_Node->next=0;

    cnt+=1;
    return New_Node;
}
// addNode function ends here---------------------------------------------------------------------------------------------------

int main(){

    struct Node *New_Node, *head;
    int choice;
    
    cout<<"Hello...! Please Create First the Linked List"<<endl;

    New_Node=(struct Node*)malloc(sizeof(struct Node));

    head=New_Node;

    cout<<endl<<"Enter Roll No (Integer Value) ";
    cin>>New_Node->roll;

    cout<<"Enter Name (String) ";
    cin>>New_Node->name;

    cnt+=1;
    New_Node->next=0;

    while(true){
        cout<<endl<<endl<<"Select the option as follows"<<endl;
        cout<<"1. Add Node"<<endl;
        cout<<"2. Traverse Linked List"<<endl;
        cout<<"3. Insert Node at Begining"<<endl;
        cout<<"4. Insert Node at Given Location"<<endl;
        cout<<"5. Delete Node at Begining"<<endl;
        cout<<"6. Delete Node at End"<<endl;
        cout<<"7. Delete Node at Given Location"<<endl;
        cout<<"8. Get Count"<<endl;
        cout<<"9. Reverse Linked List"<<endl;
        cout<<"10. Exit"<<endl;

        cout<<"Give Your Choice > ";
        cin>>choice;

        switch(choice){

            case 1:
                New_Node=addNode(New_Node);
                break;

            case 2:
                traverseLinkedList(head);
                break;

            case 3:
                head=insertAtStart(head);
                break;

            case 4:
                head=insertAtLocation(head);
                break;

            case 5:
                head=deleteAtStart(head);
                break;

            case 6:
                New_Node=deleteAtEnd(head, New_Node);
                break;

            case 7:
                head=deleteAtLocation(head);
                break;

            case 8:
                cout<<endl<<endl<<"Total Nodes are "<<cnt;
                break;

            case 9:
                head=reverseLinkedList(head);
                break;

            case 10:
                exit(0);
                break;

            default:
                cout<<"Wrong Input"<<endl;
        }
    }

    return 0;
}
