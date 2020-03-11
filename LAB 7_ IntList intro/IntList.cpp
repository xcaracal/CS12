#include "IntList.h"

using namespace std;

IntList::IntList() 
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    while(head){
        IntNode* next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;
}

void IntList::push_front(int value)
{
    IntNode* newNode = new IntNode(value);
   
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    } 
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front()
{
    if(head != nullptr)
    {
        IntNode* frontNode;
        if(head->next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
        }
        else
        {
        frontNode = head->next;
        frontNode->next = head->next->next;
        delete head;
        head =  frontNode;
        }
    }
}

bool IntList::empty() const
{
    return (head == nullptr && tail == nullptr);
}

const int& IntList::front() const 
{
    if(head != nullptr)
    {    
        return head->data;
    }
    else
    {
       throw out_of_range("IntVector::at_range_check"); 
    }
}

const int& IntList::back() const 
{
    if(tail != nullptr)
    {
        return tail->data;
    }
    else
    {
        throw out_of_range("IntVector::at_range_check"); 
    }
}

ostream& operator<<(ostream& out, const IntList& list)
{
    IntNode* curr = list.head;
    bool first = true;
    while(curr != nullptr)
    {
        if(first)
        {
        out << curr->data;
        first = false;
        curr = curr->next;
        }
        else
        {
        out << " ";
        out << curr->data;
        curr = curr->next;
        }
    }
    return out;
}