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
        length++;
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
            length++;
        }
    }

    void insert_back(int value){
        if (length == 0){
            insert_empty_list(value);
        }else{
            Node* new_node = new Node(value, head, tail);
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
            head->previous = tail;
            length++;
        }
    }

    void insert(int value, int position){
        if (length == 0){
            insert_empty_list(value);
        }else if (position == 0){
            insert_front(value);
        }else if (position == length)
        {
            insert_back(value);
        }else{
            Node* temp_node = head;
            int counter = 0;
            while (counter < position){
                temp_node = temp_node->next;
                counter++;
            }
            Node* new_node = new Node(value, temp_node, temp_node->previous);
            temp_node->previous->next = new_node;
            temp_node->previous = new_node;
            length++;
        }
    }

    int pop(int position){
        if (length == 0 || position >= length){
            throw out_of_range("List out of range");
        }
        Node* temp_node = head;
        for (int counter = 0; counter < position; counter++){
            temp_node = temp_node->next;
        }
        int value = temp_node->value;
        if (length == 1){
            delete temp_node;
            head = tail = nullptr;
        } else {
            temp_node->previous->next = temp_node->next;
            temp_node->next->previous = temp_node->previous;
            if (temp_node == head) head = temp_node->next;
            if (temp_node == tail) tail = temp_node->previous;
            delete temp_node;
        }
        length--;
        return value;
    }


    void display_forward(int cycles){
        for (int iterations=0; iterations < cycles; iterations++){
            Node* temp = head;
            int cycle_count = 0;
            while (cycle_count < length){
            cout << temp->value << "->";
            temp = temp->next;
            cycle_count++;
            }
        }
        cout << endl;
    }

    void display_backward(int cycles){
        for (int iteration=0; iteration < cycles; iteration++){
            Node* temp_node = tail;
            int cycle_count = 0;
            while (cycle_count < length){
                cout << temp_node->value << "->";
                temp_node = temp_node->previous;
                cycle_count++;
            }
        }
        cout << endl;
    }
};

int main(){

    CircularLinkedList list;
    list.insert(20,0);
    list.insert(10,0);
    list.insert(30,2);
    list.display_forward(2);
    list.display_backward(2);
    cout << list.pop(2)<<endl;
    list.display_forward(2);
    list.display_backward(2);

    return 0;

}