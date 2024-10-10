#include "List.h"
#include "Node.h"
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class DoublyLinkedList : public List {
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addBetween(int num, Node* pred, Node* succ) {
        Node* n = new Node();
        n->elem = num;

        pred->next = n;
        succ->prev = n;
        n->next = succ;
        n->prev = pred;

        size++;
    }

    int removeNode(Node* n) {
        if (n == NULL) return -1; // Edge case for NULL node

        int ret = n->elem;
        Node* pred = n->prev;
        Node* succ = n->next;

        if (pred != NULL) pred->next = succ;
        else head = succ;

        if (succ != NULL) succ->prev = pred;
        else tail = pred;

        delete n;

        size--;
        return ret;
    }

    void add(int num) {
        Node* n = new Node();
        n->elem = num;

        if (!head) {
            head = n;
            tail = n;
            head->next = NULL;
            head->prev = NULL;
            size++;
            cout << "Number " << num << " has been added" << endl;
            return;
        }

        if (num < head->elem) {
            n->next = head;
            head->prev = n;
            head = n;
            size++;
            cout << "Number " << num << " has been added" << endl;
            return;
        }

        if (num > tail->elem) {
            n->prev = tail;
            tail->next = n;
            tail = n;
            n->next = NULL;
            size++;
            cout << "Number " << num << " has been added" << endl;
            return;
        }

        Node* curr = head;
        while (curr) {
            if (curr->elem > num) {
                addBetween(num, curr->prev, curr);
                cout << "Number " << num << " has been added" << endl;
                return;
            }
            curr = curr->next;
        }
    }

    void print() {
        Node* curr = head;
        cout << "Forward: ";
        while (curr) {
            cout << curr->elem;
            if (curr->next != NULL) {
                cout << " <-> ";
            }
            curr = curr->next;
        }
        cout << endl;

        curr = tail;
        cout << "Backward: ";
        while (curr) {
            cout << curr->elem;
            if (curr->prev != NULL) {
                cout << " <-> ";
            }
            curr = curr->prev;
        }
        cout << endl;
    }

    void combine(DoublyLinkedList* other) {
        if (other->size == 0) return; 

        Node* curr = other->head;
        while (curr != NULL) {
            Node* nextNode = curr->next; 
            add(curr->elem);       
            other->removeNode(curr);
            curr = nextNode;             
        }
        other->head = NULL;  
        other->tail = NULL;  
        other->size = 0;   
    }
};

