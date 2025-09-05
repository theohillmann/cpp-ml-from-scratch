#include "node.h"
#include <iostream>

using namespace std;

class CircularLinkedList{

private:
    Node* head;
    Node* tail;
    int length = 0;


    void insert_empty_list(int value){
        Node* new_node = new Node(value, tail, head);
        head = tail = new_node;
        head->next = tail;
        tail->previous = head;
    }

public:

    CircularLinkedList(): head(nullptr), tail(nullptr) {}

    void insert_front(int value){
        if (length == 0){
            insert_empty_list(value);
        }else{
            Node* new_node = new Node(value, head, tail);
            head->previous = new_node;
            tail->next = new_node;
            head = new_node;

        }
        length++;
    }

    void insert_back(int value){
        if (length == 0){
            insert_empty_list(value);
        }else{
            Node* new_node = new Node(value, head, tail);
            tail->next = new_node;
            tail = new_node;
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
    list.insert_back(30);
    list.display_forward(10);

    return 0;    

}