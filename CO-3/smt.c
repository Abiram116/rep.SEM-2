#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
struct node* root = NULL, *t; 
 
struct node* newnode(int ele) { 
    struct node* p = (struct node*)malloc(sizeof(struct node)); 
    p->data = ele; 
    p->left = NULL; 
    p->right = NULL; 
    return p; 
} 
 
struct node* insert(struct node* root, int ele) { 
    if (root == NULL) 
        return newnode(ele); 
    else if (ele < root->data) 
        root->left = insert(root->left, ele); 
    else if (ele > root->data) 
        root->right = insert(root->right, ele); 
    return root; 
}
 
struct node* search(struct node* root, int ele){ 
    if(root==NULL||root->data==ele) return root; 
    else if(ele>root->data) return search(root->right, ele); 
    else return search(root->left, ele); 
} 
 
struct node* findmin(struct node* root) { 
    if (root->left == NULL) 
        return root; 
    return findmin(root->left); 
} 
 
struct node* deletemin(struct node* root) { 
    if (root->left == NULL) 
        return root->right; 
    root->left = deletemin(root->left); 
    return root; 
} 
 
struct node* delete(struct node* root, int ele) { 
    if (root == NULL) 
        return NULL; 
    if (ele < root->data) 
        root->left = delete(root->left, ele); 
    else if (ele > root->data) 
        root->right = delete(root->right, ele); 
    else { 
        if (root->left == NULL && root->right == NULL) { 
            free(root); 
            return NULL; 
        } else if (root->left == NULL) { 
            struct node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct node* temp = root->left; 
            free(root); 
            return temp; 
        } else { 
            struct node* temp = findmin(root->right); 
            root->data = temp->data; 
            root->right = deletemin(root->right); 
        } 
    } 
    return root; 
} 
 
void inorder(struct node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
void preorder(struct node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
 
void postorder(struct node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
int main() { 
    int choice, ele; 
    printf("\n\t1. Insert\n\t2. Delete\n\t3. Inorder\n\t4. Preorder\n\t5. Postorder\n\t6. Searching\n\t7.Exit\n"); 
    do { 
        printf("\nEnter the choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("\nEnter the element to be inserted: "); 
                scanf("%d", &ele); 
                root = insert(root, ele); 
                break; 
            case 2: 
                printf("\nEnter the element to be deleted: "); 
                scanf("%d", &ele); 
                root = delete(root, ele); 
                break; 
            case 3: 
                printf("\nInorder traversal: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("\nPreorder traversal: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 5: 
                printf("\nPostorder traversal: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 6:  
                printf("Enter the element to be searched: "); 
                scanf("%d",&ele); 
                t = search(root, ele); 
                if(t==NULL) printf("Element is not found\n"); 
                else printf("Element is found\n"); 
                break; 
            case 7: 
                printf("Exiting...\n"); 
                exit(EXIT_SUCCESS);//return 0; 
            default: 
                printf("Invalid choice.");
                } 
    } while (choice != 7);  
}