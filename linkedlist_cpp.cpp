#include<iostream>
#include "stub.h"
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} NODE;
class Linkedlist
{
private:

public:
    NODE *start;
    Linkedlist();
    void insert(int);
    void insertNth(int, int);
    void display();
    void reverse();
    void reverse(NODE** p);
    int nthNodeFromLast(int);
    NODE* nthNodefromFirst(int);
    void deleteNodeofData(int);
    void deletedEveryNthNode(int);
    unsigned short int countNodes();
    void swapNthnodefromlastandfirst(int);
    int pop();
    void deletelist();
    void split(NODE*,NODE **firsthalf, NODE **secondhalf);
    void MergeSortUtil(NODE** head);
    void MergeSort();
    void sortedInsert(NODE *newNode);
    NODE* hasloop();
    void removeDuplicates();
    bool isEven();
    void pairwiseswap();
    void reverse_k_elements(int k);
    void seggregate();
    void reverse_k_elements_by_group(int k);
    NODE* reverse_k_elements_by_group_util(NODE*,int);
    bool isPalindrome();



};
Linkedlist::Linkedlist()
{
    start = NULL;
}
void Linkedlist::insert(int value)
{
    NODE *newnode=new NODE;
    newnode->data=value;
    newnode->next=NULL;
    if(NULL == start) {
        start = newnode;
    } else {
        NODE *temp=start;
        while(temp->next != NULL) {
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
void Linkedlist::display()
{
    NODE *temp=start;
    while(NULL != temp) {
        cout<<temp->data;
        temp=temp->next;
        if(temp != NULL) {
            cout<<"=>";
        }
    }
    //cout<<"NULL\n";
    cout<<"\n";

}
void Linkedlist::insertNth(int index, int input_data)
{
    int total_nodes = countNodes();
    NODE *temp = NULL;
    NODE *newnode = new NODE;
    newnode->data = input_data;
    if( index <= 0  || index > total_nodes) {
        cout<<"out of range"<<endl;
    } else if( index == 1) {
        temp= start;
        newnode->next = temp;
        start = newnode;
    } else {
        NODE *nodebeforeNthNode = nthNodefromFirst(index-1);
        temp = nodebeforeNthNode->next ;
        nodebeforeNthNode->next = newnode;
        newnode->next = temp;

    }
}
int Linkedlist::pop()
{
    if(NULL == start) {
        cout<<"Unable to Pop, Empty List"<<endl;
    }
    NODE* current  = start;
    start = current->next;
    int data = current->data;
    delete current;
    return data;
}

void Linkedlist::reverse()
{
    NODE *current=start;
    NODE *ToAttach = NULL;
    NODE *temp=NULL;
    while(current != NULL) {
        temp= current->next;
        current->next=ToAttach;
        ToAttach = current;
        current = temp;
    }
    start=ToAttach;
}


void Linkedlist::reverse(NODE** head_ref)
{
    struct node* first;
    struct node* rest;

    /* empty list */
    if (*head_ref == NULL)
        return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
        return;

    /* reverse the rest list and put the first element at the end */
    reverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head_ref = rest;
}
NODE* Linkedlist::nthNodefromFirst(int n)
{
    if(n <= 0) {
        return NULL;
    }
    int totalnodes = countNodes();
    if(n > totalnodes ) {
        return NULL;
    }
    unsigned int index = 1;

    NODE *current = start;
    while( index != n) {
        current = current->next;
        index++;
    }
    return current;

}
int Linkedlist::nthNodeFromLast(int n)
{
    NODE *ptr1 = start;
    NODE *ptr2 = start;
    int count =0;
    while(count < (n-1)) {
        count++;
        ptr1=ptr1->next;
    }
    while(NULL != ptr1->next) {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return (ptr2->data);
}
void Linkedlist::deleteNodeofData(int data)
{
    NODE *head = start;
    NODE *current = head;
    while(current!=NULL  && current->next!=NULL ) {
        if(current->next->data == data) {
            NODE* temp= current->next->next;
            delete (current->next);
            current->next = temp;
        }
        current = current->next ;


    }

}


void Linkedlist::deletedEveryNthNode(int n)
{
    int count =1;
    NODE *current = start;
    NODE *toDelete = NULL;
    while((current != NULL) && (current->next!=NULL)) {

        count +=(n-1);
        if(count % n == 0) {
            NODE* temp= current->next->next;
            delete (current->next);
            current->next = temp;
            count-=(n-1);
        }
        current=current->next;

    }
}
unsigned short int Linkedlist::countNodes()
{
    unsigned short int count = 0;
    NODE *temp = start;
    while(temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}

void Linkedlist::swapNthnodefromlastandfirst(int k)
{
    int total_nodes = countNodes();
    int n = total_nodes;
    if(k > total_nodes) {
        cout<<"\nNode to swap is outof range!!!!!!!\n";
        return;
    }
    if(2 *k -1 == total_nodes) {
        cout<<"\n No need to swap..Since the node is centre one\n";
        return ;
    }

    NODE *x = start;
    NODE *x_prev = NULL;
    for(int i=1; i<k; i++) {
        x_prev = x;
        x=x->next;
    }
    NODE *y= start;
    NODE *y_prev = NULL;

    for(int i=1; i<n-k+1; i++) {
        y_prev = y;
        y=y->next;
    }
    if(x_prev) {
        x_prev->next = y;
    }
    if(y_prev) {
        y_prev->next = x;
    }
    NODE *temp = x->next;
    x->next = y->next;
    y->next = temp;

    if( k == 1) {
        start = y;
    }
    if( k == n) {
        start = x;
    }
}
void Linkedlist::deletelist()
{
    if( NULL == start)
        return;
    NODE *current = start;
    NODE *temp;
    while(current) {
        temp = current->next;
        delete (current);
        current = temp;
    }
    start = NULL;

}

void Linkedlist::split(NODE* source,NODE **firsthalf, NODE **secondhalf)
{
    NODE* fast ;
    NODE* slow ;
    slow  = source;
    fast = slow->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *firsthalf = source;
    *secondhalf = slow->next;
    slow->next = NULL;
}
NODE* sortedmerge(NODE* firstlist, NODE* secondlist)
{
    NODE* result;
    if( firstlist == NULL) {
        result = secondlist;
    } else if( secondlist == NULL) {
        result = firstlist;
    } else {
        if( firstlist->data <= secondlist->data) {
            result = firstlist;
            result->next = sortedmerge(firstlist->next,secondlist);
        } else {
            result = secondlist;
            result->next = sortedmerge(firstlist,secondlist->next);
        }
    }

    return (result);

}

void Linkedlist::MergeSort()
{
    MergeSortUtil(&start);
}
void Linkedlist::MergeSortUtil(NODE** headref)
{
    NODE* head =*headref;
    NODE* a;
    NODE* b;

    if( head == NULL || head->next == NULL) {
        return;
    }

    split(head,&a,&b);
    MergeSortUtil(&a);
    MergeSortUtil(&b);
    *headref= sortedmerge(a,b);
}
void Linkedlist::sortedInsert(NODE *newNode)
{
    if( start == NULL) {
        start = newNode;
    } else if( start->next == NULL) {
        start->next = newNode;
    } else {
        MergeSort();
        NODE *current = start;
        while( current->next != NULL && current->next->data < newNode->data ) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}

void Append(Linkedlist **list1, Linkedlist **list2)
{
    NODE *first = (*list1)->start;
    NODE *a = first;
    NODE *b = (*list2)->start;
    while( a->next != NULL) {
        a = a->next;
    }
    a->next = b;
    b = NULL;

}
NODE* Linkedlist::hasloop()
{
    NODE *slow  = start;
    NODE *fast  = start;
    while( slow && fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if( fast == slow) {
            int count  = 1;
            while(fast->next != slow ) {
                count++; //Number of nodes in the Loop
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}



void Linkedlist::removeDuplicates()
{
    /*
    NODE* ptr1 = start;
    while(ptr1  && ptr1->next != NULL)
    {
        NODE* ptr2 = ptr1;
        while(ptr2->next != NULL)
        {
            if( ptr1->data == ptr2->next->data)
            {
                NODE* dup = ptr2->next->next;
                delete (ptr2->next);
                ptr2->next = dup;

            }
            else
            {
            ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    */
    unordered_set<int> hashtable;
    NODE* current = start;
    NODE* newlist = start;
    NODE* prev = nullptr;
    if(current == nullptr)
        return;
    while(current) {
        if(hashtable.find(current->data) == hashtable.end()) {
            hashtable.insert(current->data);
            prev = current;
        } else {
            prev->next = current->next;
            delete current;

        }
        current = prev->next;

    }
}

bool Linkedlist::isEven()
{
    if(start == NULL) {
        cout<<"Empty List\n";
    }

    NODE* current = start;
    while(current && current->next != NULL) {
        current = current->next;
    }
    if(!current) {
        return true;
    } else {
        return false;
    }


}
void swap(NODE* dest, NODE* source)
{
    dest->data = dest->data ^ source->data;
    source->data = dest->data ^ source->data;
    dest->data = dest->data ^ source->data;
}
void Linkedlist::pairwiseswap()
{
    NODE* current = start;
    while( current != NULL  && current->next != NULL) {
        swap(current->next,current);
        current= current->next->next;
    }
}
void MoveNode(NODE** dest, NODE** source)
{
    NODE* newnode = *source;
    *source = newnode->next;
    newnode->next = *dest;
    *dest = newnode;
}
void AlternateSplit(Linkedlist* firstlist, Linkedlist* secondlist)
{

    if( firstlist->start == NULL || firstlist->start->next == NULL) {
        return;
    }

    NODE* current = firstlist->start;
    while( current && current->next != NULL) {

        secondlist->insert(current->next->data);
        firstlist->deleteNodeofData(current->next->data);
        current = current->next;
    }
}


void ShuffleMerge(Linkedlist* firstlist, Linkedlist* secondlist)
{
    if( firstlist->start == NULL ) {
        return;
    }
    if(firstlist->start->next == NULL) {
        firstlist->start->next = secondlist->start;
        return ;
    }
    NODE* head  = firstlist->start;
    NODE* first = firstlist->start;
    NODE* first_next;
    NODE* second = secondlist->start;
    NODE* second_next ;
    while( first->next != NULL) {
        first_next = first->next;
        second_next = second->next;
        first->next = second;
        second->next = first_next;

        first = first_next;
        second = second_next;

    }

    first->next = second;
    firstlist->start = head;


}
NODE* getIntersectionnodeUtil(int difference, NODE* head1,NODE* head2)
{
    NODE* current1 = head1;
    NODE* current2 = head2;
    for(int i = 1; i <= difference ; ++i) {
        current1 = current1->next;
    }

    while( current1 !=  current2) {
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1;
}

NODE* findIntersectionNode(Linkedlist *firstlist, Linkedlist *secondlist)
{
    int list1_count  = firstlist->countNodes();
    int list2_count  = secondlist->countNodes();
    int diff;
    if( list1_count < list2_count) {
        diff = list2_count - list1_count;
        return(getIntersectionnodeUtil(diff,secondlist->start,firstlist->start));
    } else {
        diff = list1_count - list2_count;
        return(getIntersectionnodeUtil(diff,firstlist->start,secondlist->start));
    }

    return NULL;
}

void Linkedlist::reverse_k_elements(int k)
{
    int total_nodes = countNodes();
    if( k > total_nodes) {
        cout<<"Out of Range\n";
    }
    if(k == total_nodes) {
        reverse();
    } else {
        NODE* current = start;

    }
}

void Linkedlist::seggregate()
{

    NODE* l=start;
    NODE* evenNode;
    NODE* pre_evenNode;
    pre_evenNode=NULL;

    while(l!=NULL) {
        evenNode=l->next;
        if(l->next == NULL)
            break;
        l->next=l->next->next;
        evenNode->next=pre_evenNode;
        pre_evenNode=evenNode;
        l=l->next;
    }
    l->next=pre_evenNode;

}

NODE* Linkedlist::reverse_k_elements_by_group_util(NODE *head, int k)
{

    NODE* current = head;
    NODE* next = NULL;
    NODE* prev = NULL;
    int count = 0;
    while( current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if( next != NULL) {
        head->next = reverse_k_elements_by_group_util(next,k);
    }
    return prev;
}

void Linkedlist::reverse_k_elements_by_group(int k)
{
    int size = countNodes();
    if ( k <= size) {
        start = reverse_k_elements_by_group_util(start,k);
    }

}

bool Linkedlist::isPalindrome()
{
    bool result = false;
    if(start) {
        NODE* slowptr = start;
        NODE* fastptr = start;
        std::stack<int> mystack;

        while ( slowptr && fastptr && fastptr->next) {
            mystack.push(slowptr->data);
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        if(fastptr != nullptr) {
            slowptr = slowptr->next;
        }
        while(slowptr != nullptr) {
            int value = mystack.top();
            mystack.pop();
            if( slowptr->data != value) {
                return false;
            }
            slowptr = slowptr->next;

        }
        result = true;

    }
    return result;
}

int snsks()

{


    Linkedlist *list1=new Linkedlist;



    list1->insert(10);
    list1->insert(20);
    list1->insert(20);
    list1->insert(10);
    list1->display();
    if (list1->isPalindrome()) {
        std::cout << "Yes Palindrome\n";
    } else {
        std::cout << "Not a Palindrome\n";
    }

    /*
    if( list1->isEven())
    {
        cout<<"Even Nodes\n";
    }
    else
    {
        cout<<"Odd Nodes\n";
    }
    */
    /*
    list1->start->next->next->next =list2->start->next->next;

    NODE* intersection_point = findIntersectionNode(list1,list2);
    cout<<"Intersection Node:"<<intersection_point->data<<endl;
    */

    /*
    list->start->next->next->next->next = list->start;
    NODE* loopstartnode = list->hasloop();
    if( loopstartnode == NULL)
    {
        cout<<"No Loop\n";
    }
    else
    {
        cout<<"Loop Start Node:"<<loopstartnode->data<<"\n";
    }
    //sortedmerge(list1->start,list2->start);
    //ShuffleMerge(list1,list2);
    // list->display();
    //list1->insert(50);
    //list1->insert(60);
    //list1->insert(70);
    //list1->insert(80);



    //cout<<"List1:\n";
    //list1->display();
    //AlternateSplit(list1,list2);
    //cout<<"\nList2:\n";
    //list2->display();
    //MoveNode(&list2->start,&list1->start);
    //cout<<"List1:\n";
    //list1->display();
    //cout<<"\nList2:\n";
    //list2->display();


    //list->removeDuplicates();
    //list->display();
    //list->start->next->next->next = list->start  ;
    //if(list->hasloop())
    //{
    //	cout<<"Yes , It has Loop"<<endl;
    //}
    //else
    //{
    //	cout<<"No , It has no Loop"<<endl;
    //}

    //Linkedlist *list1=new Linkedlist;
    //Linkedlist *list2=new Linkedlist;

    //list1->insert(20);
    //list1->insert(10);
    //list2->insert(30);
    //list2->insert(40);
    //Append(&list1,&list2);
    //NODE *newone = new NODE;
    //newone->data = 35;
    //newone->next = NULL;
    //list->sortedInsert(newone);
    //list->MergeSort();

    //list1->display();
    //NODE *a, *b;
    //list->split(&a,&b);
    //Linkedlist *list1=new Linkedlist;
    //Linkedlist *list2=new Linkedlist;
    //list1->start= a;
    //list2->start= b;
    //cout<<"First List:"<<endl;
    //list1->display();
    //cout<<"Second List:"<<endl;
    //list2->display();
    //Linkedlist *merged = new Linkedlist;
    //merged->start = sortedmerge(list1->start,list2->start);
    //list->insertNth(3,55);
    //list->display();
    //cout<<list->pop()<<endl;
    //cout<<list->pop()<<endl;
    //cout<<list->pop()<<endl;
    //list->deletelist();
    //list->insert(30);
    //list->insert(40);
    //list->insert(50);
    //list->insert(60);
    //list->insert(70);
    //cout<<"\nTotal Nodes:"<<list->countNodes()<<endl;
    /*

    NODE *result = list->nthNodefromFirst(1);
    if(NULL!= result)
    {
    cout<<endl<<result->data<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    */
    //list->deletedEveryNthNode(3);
    //list->reverse();
    //list->deleteNode(30);
    //list->reverse(&list->start);
    //list->swapNthnodefromlastandfirst(1);
    //list->display();
    //cout<<list->nthNodeFromLast(3)<<endl;

    cout<<"\n";
    return 0;
}

