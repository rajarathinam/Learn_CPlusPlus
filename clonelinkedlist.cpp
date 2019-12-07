#include "stub.h"



Node* cloneList(Node* head)
{
    if(nullptr == head)
    {
        return nullptr;
    }
    if( nullptr == head->next)
    {
        return head;


    }

    // 1. Clone the list - random&next pointers are null by default
    Node* current = head;
    Node* temp = nullptr;
    while(current)
    {
        temp = current->next;
        current->next = new Node(current->data);
        current->next->next = temp;
        current = temp;
    }

    //Step 2
    current = head;
    while (current) {
        if( current->next)
        {
            current->next->random = current->random ? current->random->next : current->random;
        }
        current = current->next ? current->next->next : current->next;

    }

    //Step3
    Node* original = head;
    Node* copy = head->next;

        // save the start of copied linked list
        temp = copy;

        // now separate the original list and copied list
        while (original && copy)
        {
            original->next =
             original->next? original->next->next : original->next;

            copy->next = copy->next?copy->next->next:copy->next;
            original = original->next;
            copy = copy->next;
        }

        return temp;


}
void printList(Node* head)
{
     std::cout << "\n =========================== \n";
    if(nullptr == head)
    {
       cout << "\nEmpty List";
    }
    Node* current = head;
    while(current)
    {
        cout << "\nCurrent : " << current->data  << "  Random: " << (current->random ? current->random->data : 0);
        current = current->next;
    }
}


int aadc()
{


     std::string_view s("Raha");
     std::cout << sizeof(s) << std::endl;

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->random = head->next->next;
    head->next->random = head->next;
    printList(head);
    Node* clonedlisthead = cloneList(head);
    printList(clonedlisthead);


    cout << "\n";
    return 0;
}
