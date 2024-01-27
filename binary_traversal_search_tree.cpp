#include<iostream>
#include<conio.h>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

class BST {
public:
    node* tree;

    BST() {
        tree = NULL;
    }

    void insertNodeTree(node** tree, int item);
    void preorder(node* tree);
    void inorder(node* tree);
    void postorder(node* tree);
};

// Create tree
void BST::insertNodeTree(node** tree, int item) {
    if (*tree == NULL) {
        *tree = new node;
        (*tree)->data = item;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else {
        if ((*tree)->data > item)
            insertNodeTree(&((*tree)->left), item);
        else
            insertNodeTree(&((*tree)->right), item);
    }
}

// Display - Preorder (Root-Left-Right)
void BST::preorder(node* tree) {
    if (tree != NULL) {
        cout << " " << tree->data;
        preorder(tree->left);
        preorder(tree->right);
    }
}

// Display - Inorder (Left-Root-Right)
void BST::inorder(node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        cout << " " << tree->data;
        inorder(tree->right);
    }
}

// Display - Postorder (Left-Right-Root)
void BST::postorder(node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        cout << " " << tree->data;
    }
}

int main() {
    BST obj;
    int choice, n, item;

    while (1) {
        cout << "\n***BINARY SEARCH TREE Operations***\n";
        cout << "1. Create Tree \n";
        cout << "2. Traversal \n";
        cout << "3. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n Creating Tree";
            cout << " How many nodes do you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter Value: ";
                cin >> item;
                obj.insertNodeTree(&(obj.tree), item);
            }
            break;

        case 2:
            cout << "\n Inorder Traversal :";
            obj.inorder(obj.tree);
            cout << "\n Preorder Traversal :";
            obj.preorder(obj.tree);
            cout << "\n Postorder Traversal :";
            obj.postorder(obj.tree);
            getch();
            break;

        case 3:
            exit(1);
            break;
        }
    }

    return 0;
}

