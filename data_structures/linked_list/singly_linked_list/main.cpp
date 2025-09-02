#include "../node.h"
#include <iostream>

using namespace std;

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList(): head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value, nullptr);
        if (!head){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;

        }
    }

    int pop_front(){
        if (!head){
            throw std::out_of_range("List is empty");
        }
        int value = head->data;
        Node* temp = head;
        head = temp->next;
        if (!head){
            tail = nullptr;
        }
        delete temp;
        return value;

    }

    int pop_back(){
        if (!head){
            throw std::out_of_range("List is empty");
        }
        int value = tail->data;
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else{
            Node* current = head;
            while(current->next != tail){
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        return value;
    }


    void display() const {
        const Node* current = head;

        while (current){
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

};

int main() {
    SinglyLinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_back(40);
    list.push_front(30);
    std::cout << "List:\n";
    list.display();

    std::cout << "Remove beginning: " << list.pop_front() << "\n";
    list.display();

    std::cout << "Remove end: " << list.pop_back() << "\n";
    list.display();

    std::cout << "Remove beginning: " << list.pop_front() << "\n";
    list.display();

    std::cout << "Remove end: " << list.pop_back() << "\n";
    list.display();

    try {
        list.pop_front();
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    try {
        list.pop_back();
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}