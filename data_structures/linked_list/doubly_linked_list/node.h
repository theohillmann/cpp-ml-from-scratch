class Node {
public:
    int value;
    Node* next;
    Node* previous;

    Node(int value, Node* next, Node* previous): value(value), next(next), previous (previous) {}
};