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

    int pop(int position) {
        Node* temp = head;
        int count = 0;
        while (temp) {
            if (count == position){
                int value = temp->value;
                if (temp == head) {
                    head = temp->next;
                    if (head) head->previous = nullptr;
                    else tail = nullptr;
                } else if (temp == tail) {
                    tail = temp->previous;
                    if (tail) tail->next = nullptr;
                    else head = nullptr;
                } else {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
                delete temp;
                return value;
            }
            temp = temp->next;
            count++;
        }
        throw out_of_range("List out of range");
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
    cout << list.pop(0);
    cout << list.pop(1);
    cout << list.pop(0);
    cout << list.pop(0);
    
    return 0;
}