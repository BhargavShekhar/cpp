#include<iostream>
#include<queue>
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

void printBinaryTree(Node* root) {
    queue<Node*> levels;
    levels.push(root);
    levels.push(nullptr);

    while(!levels.empty()) {
        Node* temp = levels.front();
        levels.pop();

        if(!temp) {
            cout << endl;
            if(!levels.empty()) levels.push(nullptr);
        }
        else {
            cout << temp->data << " ";
            if(temp->left) levels.push(temp->left);
            if(temp->right) levels.push(temp->right);
        }
    }
}

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

int getMinElem(Node* root) {
    // base case
    if(root->left == nullptr) return root->data;

    int elem = getMinElem(root->left);
    return elem;
}

int getMaxElem(Node* root) {
    // base case
    if(!root->right) return root->data;

    int elem = getMaxElem(root->right);
    return elem;
}

void inorderTraversal(Node* root, vector<int> &sortedElem) {
    // base case
    if(!root) return;

    inorderTraversal(root->left, sortedElem);
    sortedElem.push_back(root->data);
    inorderTraversal(root->right, sortedElem);
}

int main()
{
    // input 100 50 200 70 20 250 150 -1
    Node* root = createBST();

    cout << endl;

    printBinaryTree(root);

    cout << endl;

    /* --> solution: */

    int minElem = getMinElem(root); // O(height)
    int maxElem = getMaxElem(root);

    cout << "Min element of given Binary Search Tree is " << minElem << endl;
    cout << "Max element of given Binary Search Tree is " << maxElem << endl;

    vector<int> sortedElem;

    inorderTraversal(root, sortedElem);

    cout << "Sorted Elements of given Binary Search Tree is: " << endl;
    for(auto elem:sortedElem) {
        cout << elem << " ";
    }   cout << endl;
    
    return 0;
}