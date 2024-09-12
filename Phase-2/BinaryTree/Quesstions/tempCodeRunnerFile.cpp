int main()
{
    // input -> 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    Node* root = nullptr;
    root = buildTree(root);

    cout << "Tree created !!" << endl;

    cout << endl;

    cout << "Level order traversal of the tree is " << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "Right to left Level order traversal of the tree is " << endl;
    rightTOLeft_levelOrdertraersal(root);

    cout << endl;

    cout << "Zig Zag Level order traversal of the tree is " << endl;
    zigzag_levelOrderTraversal(root);
    
    return 0;
}