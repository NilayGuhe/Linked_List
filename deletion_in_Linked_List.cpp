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
    cout << endl
         << endl;
};

//Deletion of node from beginning
void deleteAtBeg()
{

    temp = head;
    head = head->next;
    delete (temp);
};

//Deletion of node from End
void deleteAtEnd()
{
    temp = head;
    struct node *prevnode;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
        delete (temp);
    }
    else
    {
        prevnode->next = 0;
    }
    delete (temp);
};

//Deletion of node from certain position
void deleteAtPos()
{
    temp = head;
    int i = 1;
    int position;
    struct node *nextnode;
    cout << "Enter the position from where you want to delete the node: " << endl;
    cin >> position;

    if (position == 1)
    {
        deleteAtBeg();
    }
    else
    {
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        delete (nextnode);
    }
};
int main()
{

    head = 0;
    int choice = 1;
    int count = 0;
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
    cout << "1-> Delete node at Beginning" << endl
         << "2-> Delete node at End" << endl
         << "3-> Delete node at Position" << endl;
    cin >> a;

    switch (a)
    {
    case 1:
        deleteAtBeg();
        display();
        break;

    case 2:
        deleteAtEnd();
        display();
        break;

    case 3:
        deleteAtPos();
        display();
        break;

    default:
        break;
    }
    return 0;
}