#include <iostream>
using namespace std;
void linked_list()
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp;
    head = 0;
    int choice;
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
            temp = temp->next;
        }

        cout << "Do you want to Continue: (0 or 1)?" << endl;
        cin >> choice;
    }
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    linked_list();
    return 0;
}