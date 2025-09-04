class Node {
public:
    int value;
    Node* next;
    Node* previus;

    Node(int value, Node* next, Node *previus): value(value), next(next), previus(previus) {}
};