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
    cout<<endl<<endl;
};

void reverse()
{
    struct node *nextnode;
    struct node *prevnode = 0;
    nextnode =  temp = head;

    while (temp != 0)
    {
        nextnode = temp->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    head = prevnode;
    
    display();
};
int main()
{
    head = 0;
    int choice;
    int count = 0;
    int a;
    while (choice)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter Data: ";
        cin >> newnode->data;
        newnode->next = 0;

        if (head == 0)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Do you want to continue (0 or 1) ? ";
        cin >> choice;
    }
    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    cout << "Total elements in the List are: " << count << endl;
    display();
    reverse();

    return 0;
}