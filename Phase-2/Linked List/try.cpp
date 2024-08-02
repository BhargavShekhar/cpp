#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Destructor
    ~Node() {
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
    }
};

void print(Node* &head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

Node* getMid(Node* &head) {
    Node* fast = head->next;
    Node* slow = head;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node* reverseHalf(Node* temp) {
    // Base Case
    if (temp == nullptr || temp->next == nullptr) {
        return temp;
    }

    // Finding tail
    Node* tail = temp;
    Node* prevTail = nullptr;

    while (tail->next != nullptr) {
        prevTail = tail;
        tail = tail->next;
    }

    // Reverse the second half
    Node* current = temp;
    Node* prev = nullptr;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Connect the reversed second half to the first half
    prevTail->next = prev;

    return temp;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 1);

    print(head);

    Node* mid = getMid(head);
    cout << "Mid is: " << mid->data << endl;

    // Check if the list has at least two elements before calling reverseHalf
    // if (head != nullptr && head->next != nullptr) {
    //     head = reverseHalf(mid);
    //     print(head);
    // }

    Node* temp = reverseHalf(mid);
    print(head);

    return 0;
}
