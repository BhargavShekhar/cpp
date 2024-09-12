#include <iostream>
#include <queue>
using namespace std;

struct Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildtree(Node *root)
{

    // building the root node
    int data;
    cout << "Enter data: ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return nullptr;

    // Left child node
    cout << "Enter left child node of " << data << endl;
    root->left = buildtree(root);

    // Right child node
    cout << "Enter right child node of " << data << endl;
    root->right = buildtree(root);
}

void levelOrderTraversel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(nullptr); // if there is a nullptr in a queue => a level has been traversed
            }
            
        }
        
        else
        { 
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = nullptr;

    root = buildtree(root);
    cout << endl
         << "Tree created !!" << endl;
    // input string -> 1 3 7 -1-1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversel(root);

    return 0;
}