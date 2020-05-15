/*
* Author: Muhammad Khairi Norizan
* Purpose: HW8 List Objects
* Language: C,C++
*/

#include <iostream>
#include "string.h"
#include "list.hh"
using namespace std;

list_builder &list_builder::operator=(list_builder &list_b)
{
    setList(list_b.getList(), list_b.getSize());

    return *this;
}

ostream &operator<<(ostream &out, fixed_list fixed_List)
{
    list_builder lb = fixed_List.getList_Builder();

    if (fixed_List.size() == 0)
    {
        out << "[]";
    }
    else
    {
        struct node *list = lb.getList();
        out << "[";
        for (int i = 0; i < fixed_List.size() - 1; i++)
        {
            out << list->data << ",";
            list = list->next;
        }
        out << list->data << "]";
    }

    return out;
}