#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}

void IntList::push_front(int val)
{
   if (!head) 
   {
      head = new IntNode(val);
   } 
    else 
   {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream& operator<<(ostream &out, const IntList &list)
{
    IntNode* curr = list.head;
    return out << curr;
}

bool IntList::exists(int val) const 
{
    return exists(head, val);
}

bool IntList::exists(IntNode *curr, int val) const
{
    if(curr == nullptr)
    {
        return false;
    }
    else
    {
        if(curr->data == val)
        {
        return true;
        }
        else
        {
        return exists(curr->next, val);
        }
    }
}
    
ostream & operator<<(ostream &out, IntNode* curr) 
{
if(curr == nullptr)
{
    return out;
}
if(curr->next == nullptr)
{
    out << curr->data;
    return out << curr->next;
}
else
{
    out << curr->data;
    return out << " " << curr->next;
}
}
