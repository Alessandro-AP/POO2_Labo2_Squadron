/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : linkedList.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_LINKEDLIST_H
#define POO2_LABO2_SQUADRON_LINKEDLIST_H

#include <iostream>
#include <cassert>

/**
 * Maillon de la liste simplement chaînée
 */
template<typename T>
struct Node {
    T element;
    Node* next;
};

/**
 * Structure partiel de la liste simplement chaînée
 */
template<typename T>
class LinkedList {
private:
    /** Tête de la liste */
    Node<T>* head;

public:
    /**
     *  Classe représentant L'iterateur de la liste
     */
    class Iterator {
    private:
        /** Iterateur courant */
        Node<T>* curr;

    public:

        /**
         * Constructeur de la classe Iterator
         */
        Iterator() {
            curr = nullptr;
        }

        /**
         * Constructeur par copie avec un iterateur
         * @param other iterateur
         */
        Iterator(const Iterator& other) {
            curr = other.curr;
        }

        /**
         * Constructeur par copie avec un node
         * @param other node
         */
        explicit Iterator(Node<T>* node) {
            curr = node;
        }

        /**
         * Surcharge de l'opérateur de déréférencement
         * @return l'element stockée contenu dans le maillon referencé par l'iterateur
         */
        T& operator*() const {
            assert(this->curr != nullptr);
            return this->curr->element;
        }

        /**
         * Surcharge de l'opérateur "!="
         *
         * @param other iterateur à comparer
         * @return true si l'iterateur est different, sinon false
         */
        bool operator!=(const Iterator& other) const {
            return !(*this == other) ;
        }

        /**
         * Surcharge de l'opérateur "=="
         *
         * @param other iterateur à comparer
         * @return true si l'iterateur est le même, sinon false
         */
        bool operator==(const Iterator& other) const {
            return this->curr == other.curr ;
        }

        /**
         * Surcharge de l'opérateur "++" préfixée
         *
         * @return le prochain iterateur
         */
        Iterator& operator++() {
            assert(this->curr != nullptr);
            this->curr = curr->next;
            return *this;
        }

    };

    /**
     * Constructeur de la classe LinkedList
     */
    LinkedList();

    /**
     * Destructeur de la classe LinkedList
     */
    ~LinkedList();

    /**
     * Insertion à la fin de la liste
     *
     * @param element à inserer
     */
    void insertAtEnd(const T& element);

    /**
     * Vérifié si un élément est présent ou non dans la liste
     *
     * @param element à rechercher
     * @return true si l'element est trouvé, sinon false
     */
    bool contains(const T& element) const;

    /**
     * Vérifié si la liste est vide
     *
     * @return true si la liste est vide, sinon false
     */
    bool isEmpty() const;

    /**
     * Supprime un element de la liste
     *
     * @param element à supprimer
     */
    void remove(const T& element);

    /**
     * Iterateur sur la tête de la liste
     *
     * @return un iterateur sur le debut de la liste
     */
    Iterator begin() const;

    /**
     * Iterateur sur la fin de la liste
     *
     * @return un iterateur sur la fin de la liste
     */
    Iterator end() const;

    /**
     * Fonction permettant d'echanger deux linkedList
     *
     * @param other à echanger
     */
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

    Node<T>* new_node = new Node<T>();

    Node<T>* last = head;

    new_node->element = element;

    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else {

        while (last->next != NULL)
            last = last->next;

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
    Node<T>* temp = head;
    Node<T>* prev = NULL;

    if (temp != NULL && temp->element == element) {
        head = temp->next;
        delete temp;
        return;
    }
    else {
        while (temp != NULL && temp->element != element) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

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
    return Iterator(head);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return Iterator();
}

#endif //POO2_LABO2_SQUADRON_LINKEDLIST_H