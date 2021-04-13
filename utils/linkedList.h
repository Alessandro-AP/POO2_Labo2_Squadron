/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : linkedList.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_LINKEDLIST_H
#define POO2_LABO2_SQUADRON_LINKEDLIST_H

#include <iostream>
#include <cassert>

template<typename T>
struct Node {
    T element;
    Node* next;
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:

    class Iterator {
    private:
        Node<T>* curr;
        friend class LinkedList<T>;

    public:

        Iterator() {
            curr = nullptr;
        }

        Iterator(const Iterator& other) {
            curr = other.curr;
        }

        Iterator(const LinkedList<T>& list) {
            curr = list.head;
        }

        T& operator*() const {
            assert(this->curr != nullptr);
            return this->curr->element;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other) ;
        }

        bool operator==(const Iterator& other) const {
            return this->curr == other.curr ;
        }

        Iterator& operator++() {
            assert(this->curr != nullptr);
            this->curr = curr->next;
            return *this;
        }

    };

    LinkedList();
    ~LinkedList();

    void insertAtEnd(const T& element);

    bool contains(const T& element) const;

    bool isEmpty() const;

    void remove(const T& element);

    Iterator begin() const;

    Iterator end() const;

    void swap(LinkedList<T>& other);
};

template<typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = this->head;
    while (curr != nullptr) {
        Node<T>* deleteNode = curr;
        curr = curr->next;
        delete deleteNode;
    }
}

template<typename T>
void LinkedList<T>::insertAtEnd(const T& element) {
    // 1. allocate node
    Node<T>* new_node = new Node<T>();

    // Used in step 5
    Node<T>* last = head;

    // 2. Put in the data
    new_node->element = element;

    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = NULL;

    // 4. If the Linked List is empty,
    // then make the new node as head
    if (head == NULL)
    {
        head = new_node;
    }
    else { // 5. Else traverse till the last node

        while (last->next != NULL)
            last = last->next;

        // 6. Change the next of last node
        last->next = new_node;
    }
}


template<typename T>
bool LinkedList<T>::contains(const T& element) const {
    Node<T>* curr = this->head;
    while (curr != nullptr) {
        if (curr->element == element)
            return true;
        curr = curr->next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T& element) {
    // Store head node
    Node<T>* temp = head;
    Node<T>* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->element == element) {
        head = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

        // Else Search for the key to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next' */
    else {
        while (temp != NULL && temp->element != element) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::swap(LinkedList<T>& other) {
    std::swap(head, other.head);
}


template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return Iterator(*this);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return Iterator();
}

#endif //POO2_LABO2_SQUADRON_LINKEDLIST_H
