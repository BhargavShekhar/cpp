#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

Node* buildBST(Node* root, int data) {
    // base case
    if(!root) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = buildBST(root->left, data);
    }
    else {
        root->right = buildBST(root->right, data);  
    }

    return root;
}

Node* createBST() {
    int data;
    cout << "Enter node data " << endl;
    cin >> data;

    Node* root = nullptr;

    while(data != -1) {
        root = buildBST(root, data);
        cout << "Enter node data " << endl;
        cin >> data;
    }

    return root;
}

/*  --> driver code ends here */

bool isPresent(Node* root, int target) {
    while(root) {
        if(root->data == target) return true;
        else if(root->data > target) root = root->left;
        else root = root->right;
    }
    return false;
}

int main()
{
     // input 100 50 200 70 20 250 150 -1
    Node* root = createBST();

    /* --> solution: */
    int target = 450;
    bool ans = isPresent(root, target);

    if(ans) cout << "Element Present" << endl;
    else cout << "Element not Present" << endl;
    
    return 0;
}