#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;

    void print_reverse(Node<T>* head);

public:

    int nodes;

    List()
    {
        head=NULL;
        tail=NULL;
    };

    T front()
    {
        return head -> data;
    };

    T back()
    {
        return tail -> data;
    };

    void push_front(T value){
        Node<T> *temp=new Node<T>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    };

    void push_back(T value){
        Node<T> *temp=new Node<T>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    };

    void pop_front()
    {
        Node<T>* temp=head;
        if(!head)
        {
            throw "Lista vacia\n";
        }
        else if(nodes==1)
        {
            delete head;
        }
        else
        {
            head = temp->next;
            delete temp;
        }
        nodes --;
    };

    void pop_back()
    {
        auto *temp=head;
        while(temp->next != tail)
        {
            temp=temp->next;
        }

        tail = temp;
        temp = temp->next;
        delete temp;
        nodes--;
    };

    T get(int position)
    {
        try
        {
            if(position<=nodes && position>0)
            {
                if(position==0)
                {
                    return head -> data;
                }
                else if(position==nodes-1)
                {
                    return tail->data;
                }
                else
                {
                    Node<T> *temp = head;
                    while (position--) {
                        temp = temp->next;
                    }
                    return temp->data;
                }
            }else{throw position;}
        }
        catch(int position)
        {
            cout << "\nSegmentation fault. Tried to access non-exisiting index " << position << endl;
        }

    };

    void concat(List<T> &other);
    bool empty();
    int size();

    void print()
    {
        Node<T>* temp = head;
        while(temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    };

    void print_reverse();
    void clear();
    Iterator<T> begin();
    Iterator<T> end();

    ~List();
};
#endif