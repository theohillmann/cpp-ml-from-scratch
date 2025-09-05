#include "node.h"
#include <iostream>

using namespace std;

class CircularLinkedList{

private:
    Node* head;
    Node* tail;
    int length = 0;

public:

    CircularLinkedList(): head(nullptr), tail(nullptr) {}

    void insert_front(int value){
        if (length == 0){
            Node* new_node = new Node(value, tail, head);
            head = tail = new_node;
            head->next = tail;
            tail->previous = head;
        }else{
            Node* new_node = new Node(value, head, tail);
            head->previous = new_node;
            tail->next = new_node;
            head = new_node;

        }
        length++;
    }


    void display_forward(int cicle){
        Node* temp = head;
        int cicle_count = 0;
        while (cicle_count < cicle){
            cout << temp->value<<"->";
            temp = temp->next;
            cicle_count ++;
        }
    }

};

int main(){

    CircularLinkedList list;
    list.insert_front(20);
    list.insert_front(10);
    list.display_forward(5);

    return 0;    

}