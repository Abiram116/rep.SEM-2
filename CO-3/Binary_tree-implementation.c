#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the given tree (used in deletion)
struct TreeNode* findMinimum(struct TreeNode* node) {
    struct TreeNode* current = node;
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }

    // Recursive calls for ancestors of node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMinimum(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Visit the root
        preorderTraversal(root->left); // Traverse the left subtree
        preorderTraversal(root->right); // Traverse the right subtree
    }
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left); // Traverse the left subtree
        postorderTraversal(root->right); // Traverse the right subtree
        printf("%d ", root->data); // Visit the root
    }
}

int main() {
    struct TreeNode* root = NULL;
    
    // Inserting nodes into the binary tree
    root = insertNode(root, 42);
    insertNode(root, 26);
    insertNode(root, 16);
    insertNode(root, 48);
    insertNode(root, 45);
    insertNode(root, 28);
    //insertNode(root, 80);
    
    
    //inorder
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");
    
    //preorder 
    printf("Preorder traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");
    
    //postorder
    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");
    
    //deletion of node
    int  key=45;
    root = deleteNode(root, key);
    printf("Node with value %d deleted.\n", key);

    printf("\nInorder traversal of the binary tree after deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}