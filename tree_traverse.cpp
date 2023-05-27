// tree traversal inorder, preorder, postorder

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    bool isEmpty()
    {
        if (root == NULL)
            return true;
        else
            return false;
    }
    void insertNode(Node *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value inserted as root node" << endl;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (new_node->data == temp->data)
                {
                    cout << "Value already exists, insert another value" << endl;
                    return;
                }
                else if ((new_node->data < temp->data) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    new_node->parent = temp;
                    cout << "Value inserted to the left" << endl;
                    break;
                }
                else if (new_node->data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((new_node->data > temp->data) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    new_node->parent = temp;
                    cout << "Value inserted to the right" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print2DUtil(Node *root, int space)
    {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += 5;

        // Process right child first
        print2DUtil(root->right, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << root->data << "\n";

        // Process left child
        print2DUtil(root->left, space);
    }

    void print2D(Node *root)
    {
        // Pass initial space count as 0
        print2DUtil(root, 0);
    }

    void printPreorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    void printInorder(Node *root)
    {
        if (root == NULL)
            return;

        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }

    void printPostorder(Node *root)
    {
        if (root == NULL)
            return;

        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
    }
    
    Node *searchNode(int value)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (value == temp->data)
                {
                    return temp;
                }
                else if (value < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
};

