//
// Created by Alessandro on 08.04.2021.
//

#ifndef POO2_LABO2_SQUADRON_LINKEDLIST_H
#define POO2_LABO2_SQUADRON_LINKEDLIST_H
#include <iostream>

using namespace std;
#include <cassert>

template <typename T>
struct Node
{
    T element;
    Node* next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    size_t size{0};

public:
    class Iterator;
    LinkedList();
    void insertAtStart(T const element);
    void insertAtEnd(T const element);
    bool contains(T const element) const;
    //void reverse();
    void deleteAllOccurancesOf(T const element);
    size_t getSize();
    Iterator begin() const;
    Iterator end() const;
    ~LinkedList();


};


template <typename T>
class LinkedList<T>::Iterator
{
private:
    Node<T> *curr;
    friend class LinkedList<T>;
public:
    Iterator()
    {
        curr = nullptr;
    }

    Iterator(LinkedList<T>::Iterator const& that)
    {

        this->curr = that.curr;
    }

    Iterator(LinkedList<T> const& list)
    {
        curr = list.head;
    }

    T& operator*()
    {
        assert(this->curr != nullptr);
        return this->curr->element;
    }

    bool operator!=(LinkedList<T>::Iterator that)const
    {
        return (this->curr != that.curr);

    }
    bool operator==(Iterator const& that) const
    {
        return (this->curr == that.curr);
    }

    Iterator& operator++()
    {
        assert(this->curr != nullptr);

        this->curr = curr->next;
        return *this;

    }
    LinkedList<T>::Iterator operator++(int)
    {
        assert(this->curr != nullptr);
        Iterator newIterator(*this);

        this->curr = curr->next;
        return newIterator;
    }
};




template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const
{
    LinkedList<T>::Iterator it(*this);
    return it;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const
{
    Iterator it;
    it.curr = nullptr;
    return it;

}

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
}

template <typename T>
void LinkedList<T>::insertAtStart(T const element)
{
    //case 1: head is empty;
    if (this->head == nullptr)
    {
        this->head = new Node<T>();
        this->head->element = element;
        this->head->next = nullptr;
        ++size;
        return;
    }

    Node<T> *newHead = new Node<T>();
    newHead->element = element;
    newHead->next = this->head;
    this->head = newHead;
    ++size;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T const element)
{
    //case 1: head is empty;
    if (this->head == nullptr)
    {
        this->head = new Node<T>();
        this->head->element = element;
        this->head->next = nullptr;
        ++size;
        return;
    }

    Node<T> *curr = this->head;
    while (curr->next != nullptr)
        curr = curr->next;

    //create new node
    Node<T> *newTailNode = new Node<T>;
    newTailNode->element = element;
    newTailNode->next = nullptr;
    curr->next = newTailNode;
    ++size;
}


template <typename T>
bool LinkedList<T>::contains(T const element) const
{
    Node<T> *curr = this->head;
    while (curr != nullptr)
    {
        if (curr->element == element)
            return true;
        curr = curr->next;
    }

    return false;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *curr = this->head;
    while (curr != nullptr)
    {
        Node<T> *deleteNode = curr;
        curr = curr->next;
        delete deleteNode;
    }

}

template <typename T>
void LinkedList<T>::deleteAllOccurancesOf(T const element)
{
    // Store head node
    Node<T> *tmp = head;

    while (head->element == element)
    {
        head = head->next;
    }
    while (tmp->next != NULL)
    {
        if (tmp->next->element == element)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
//    return head;

    /*
    Node<T> *ptr = this->head;
    Node<T> *prv = nullptr;
    Node<T> *temp;
    while (ptr != nullptr)
    {
        if (ptr->element == element)
        {

            if (prv == nullptr)
            {
                temp = ptr->next;
                delete ptr;
                ptr = temp;
                prv = nullptr;
                --size;
            }

            else
            {
                temp = ptr->next;
                delete ptr;
                ptr = temp;
                prv->next = ptr;
                --size;
            }
        }

        else
        {
            prv = ptr;
            ptr = ptr->next;
        }
    }*/
}

template<typename T>
size_t LinkedList<T>::getSize() {
    return size;
}
/*
template <typename T>
void LinkedList<T>::reverse()
{
    if (this->head == nullptr)
        return;

    Node<T> *curr = this->head,
            *prev = nullptr,
            *next = curr->next;

    while (next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }

    this->head = curr;
    this->head->next = prev;

}*/

#endif //POO2_LABO2_SQUADRON_LINKEDLIST_H
