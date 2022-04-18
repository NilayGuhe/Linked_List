#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *newnode;
struct node *temp;


void display()
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

void insertAtBeg()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter Data: " << endl;
    cin >> newnode->data;
    newnode->next = 0;

    newnode->next = head;
    head = newnode;
};

void insertAtEnd()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter Data: " << endl;
    cin >> newnode->data;
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
};

void insertAtPos(int count)
{
    int pos, i = 1;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter Data: " << endl;
    cin >> newnode->data;
    newnode->next = 0;

    cout<<"Enter the position where you want to insert : ";
    cin>>pos;
    if (pos <=0 || pos > count)
    {
        printf("Can't be modified \n");
    }
    else
    {
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
};

int main()
{

    head = 0;
    int choice;
    int count=0;
    int a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        cout << "Enter Data: " << endl;
        cin >> newnode->data;
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        cout << "Do you want to Continue: (0 or 1)?" << endl;
        cin >> choice;
    }
    temp = head;

    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    cout << "Total elements are: " << count << endl;
    display();

    cout << "Enter the operation you want to perform: " << endl;
    cout << "1-> Insert node at Beginning" << endl
         << "2-> Insert node at End" << endl
         << "3->Insert node at Position" << endl;
    cin >> a;

    switch (a)
    {
    case 1:
        insertAtBeg();
        display();
        break;

    case 2:
        insertAtEnd();
        display();
        break;

    case 3:
        insertAtPos(count);
        display();
        break;
    case 4:
        display();
        break;   

    default:
        cout<< "Invalid";
        break;
    }
    
    return 0;
}
