#pragma once

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) : data(data), next(next) {}
};