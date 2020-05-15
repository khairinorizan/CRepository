/*
* Author: Muhammad Khairi Norizan
* Purpose: HW8 List Objects
* Language: C,C++
*/

#include <iostream>
#include "string.h"
#include <string>
using namespace std;

struct node{
	int data;
	struct node* next;
};

class list_builder {
    private:
    struct node **head;
    int listSize;

    public:
    list_builder(){
        head = (struct node**)malloc(sizeof(struct node) * 1);
        listSize = 0;
    };

    ~list_builder(){
    }

    struct node* getList(){
        return *head;
    };

    int getSize(){
        return listSize;
    };

    void setList(struct node *newList, int newSize){
        struct node *nList = newList;
        (*head) = nList;
        
        listSize = newSize;
    }

    list_builder& operator= (list_builder &list_b);

    void add_to_back(int value){
        if(listSize == 0){
            struct node *newNode = (struct node*)malloc(sizeof(struct node) * 1);
            newNode->data = value;
            newNode->next = 0;
            (*head) = newNode;
            listSize++;
        }else{
            struct node *curNode = (*head);

            while(curNode->next != 0){
                curNode = curNode->next;
            }

            struct node *newNode = (struct node*)malloc(sizeof(struct node) * 1);
            newNode->data = value;
            newNode->next = 0;
            curNode->next = newNode;

            listSize++;
        }

    };

    void add_to_front(int value){
        if(listSize == 0){
            struct node *newNode = (struct node*)malloc(sizeof(struct node) * 1);
            newNode->data = value;
            newNode->next = 0;
            (*head) = newNode;

            listSize++;
        }else{
            struct node *newNode = (struct node*)malloc(sizeof(struct node) * 1);
            newNode->data = value;
            newNode->next = (*head);
            (*head) = newNode;

            listSize++;
        }
    };

    void reset(){
        struct node *curNode = (*head);
        struct node *next;

        while(curNode != 0){
            next = curNode->next;
            delete curNode;
            curNode = next;
        }

        listSize = 0;
    };
};

class fixed_list{
    private:
    list_builder thisLB;
    int LBSize;

    public:
    fixed_list(list_builder &lb){
        thisLB.setList(lb.getList(), lb.getSize());
        LBSize = lb.getSize();
    };

    ~fixed_list(){
    }

    int size(){
        return LBSize;
    };

    list_builder getList_Builder(){
        return thisLB;
    }

    fixed_list operator[] (fixed_list &f_list);
};
ostream& operator<<(ostream& out,fixed_list f_list);