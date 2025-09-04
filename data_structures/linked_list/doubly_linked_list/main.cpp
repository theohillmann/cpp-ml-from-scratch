#include "node.h"
#include <iostream>

using namespace std;

class DoublyLinkedList {
private:
    Node* head;
    Node* tail; 

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}

    void insert_front(int value) {
        if (!head){
            head = tail = new Node(value, nullptr, nullptr);
        }else{
            Node* temp = head;
            head = new Node(value, temp, nullptr);
            temp->previous = head;
        }
    }

    void insert_back(int value){
        if (!head){
            head = tail = new Node(value, nullptr, nullptr);
        }else{
            Node* temp = tail;
            tail = new Node(value, nullptr, temp);
            temp->next = tail;
        }
    }

    void display_foward() {
        Node* temp = head;
        while (temp){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void display_backward() {
        Node* temp = tail;
        while (temp){
            cout <<temp->value << "->";
            temp = temp->previous;
        }
        cout << "nullptr" << endl;
    }


};

int main() {
    DoublyLinkedList list;

    list.insert_front(10);
    list.insert_front(20);
    list.insert_back(30);
    list.display_foward();
    list.display_backward();

    return 0;
}