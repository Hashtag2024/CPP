#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* tree;

    BST() {
        tree = NULL;
    }

    void createTree(Node** tree, int item);
    int totalNodes(Node* tree);
    void removeTree(Node** tree);
    void findSmallestNode(Node* tree);
    void findLargestNode(Node* tree);
    void deleteNode(int item);
};

void BST::createTree(Node** tree, int item) {
    if (*tree == NULL) {
        *tree = new Node;
        (*tree)->data = item;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else {
        if ((*tree)->data > item)
            createTree(&((*tree)->left), item);
        else
            createTree(&((*tree)->right), item);
    }
}

int BST::totalNodes(Node* tree) {
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

void BST::removeTree(Node** tree) {
    if (*tree != NULL) {
        removeTree(&((*tree)->left));
        removeTree(&((*tree)->right));
        delete (*tree);
    }
}

void BST::findSmallestNode(Node* tree) {
    if (tree == NULL || tree->left == NULL)
        cout << "Smallest Node: " << tree->data << endl;
    else
        findSmallestNode(tree->left);
}

void BST::findLargestNode(Node* tree) {
    if (tree == NULL || tree->right == NULL)
        cout << "Largest Node: " << tree->data << endl;
    else
        findLargestNode(tree->right);
}

Node* findInSuccessor(Node* curr) {
    Node* succ = curr->right;
    while (succ->left != NULL)
        succ = succ->left;
    return succ;
}

void BST::deleteNode(int item) {
    Node* curr = tree;
    Node* succ, * pred;
    int flag = 0, delcase;

    while (curr != NULL && flag != 1) {
        if (item < curr->data) {
            pred = curr;
            curr = curr->left;
        } else if (item > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Item does not exist: No deletion" << endl;
        return;
    }

    if (curr->left == NULL && curr->right == NULL)
        delcase = 1;
    else if (curr->left != NULL && curr->right != NULL)
        delcase = 3;
    else
        delcase = 2;

    if (delcase == 1) {
        if (pred->left == curr)
            pred->left = NULL;
        else
            pred->right = NULL;
        delete curr;
    } else if (delcase == 2) {
        if (pred->left == curr)
            pred->left = (curr->left != NULL) ? curr->left : curr->right;
        else
            pred->right = (curr->left != NULL) ? curr->left : curr->right;
        delete curr;
    } else if (delcase == 3) {
        succ = findInSuccessor(curr);
        int item1 = succ->data;
        deleteNode(item1);
        curr->data = item1;
    }
}

int main() {
    BST obj;
    int choice, total, n, item;

    while (1) {
        cout << "Binary Search Tree Operations" << endl;
        cout << "1. Create Tree" << endl;
        cout << "2. Total Nodes" << endl;
        cout << "3. Remove Tree" << endl;
        cout << "4. Find Smallest Node" << endl;
        cout << "5. Find Largest Node" << endl;
        cout << "6. Delete Node" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter how many nodes you want to enter: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter Value: ";
                    cin >> item;
                    obj.createTree(&(obj.tree), item);
                }
                break;
            case 2:
                total = obj.totalNodes(obj.tree);
                cout << "Total Nodes: " << total << endl;
                break;
            case 3:
                obj.removeTree(&(obj.tree));
                cout << "Tree is removed from memory" << endl;
                break;
            case 4:
                obj.findSmallestNode(obj.tree);
                break;
            case 5:
                obj.findLargestNode(obj.tree);
                break;
            case 6:
                cout << "Enter value: ";
                cin >> item;
                obj.deleteNode(item);
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}

