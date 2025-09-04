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
            head = new Node(value, nullptr, nullptr);
        }else{
            Node* temp = head;
            head = new Node(value, temp, nullptr);
        }
    }

    void display_foward() {
        Node* temp = head;
        while (temp){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nulptr" << endl;
    }


};

int main() {
    DoublyLinkedList list;

    list.insert_front(10);
    list.insert_front(20);
    list.display_foward();

    return 0;
}