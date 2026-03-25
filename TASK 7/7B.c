#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to count paths starting from a node
int countFromNode(struct Node* root, int targetSum) {
    if (root == NULL)
        return 0;

    int count = 0;

    if (root->data == targetSum)
        count++;

    count += countFromNode(root->left, targetSum - root->data);
    count += countFromNode(root->right, targetSum - root->data);

    return count;
}

// Function to count total paths in the tree
int countPaths(struct Node* root, int targetSum) {
    if (root == NULL)
        return 0;

    // Count paths starting from current node
    int pathsFromRoot = countFromNode(root, targetSum);

    // Count paths in left and right subtrees
    int leftPaths = countPaths(root->left, targetSum);
    int rightPaths = countPaths(root->right, targetSum);

    return pathsFromRoot + leftPaths + rightPaths;
}

// Driver code
int main() {
    /*
            10
           /  \
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2   1
    */

    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(-3);
    root->left->left = newNode(3);
    root->left->right = newNode(2);
    root->right->right = newNode(11);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(-2);
    root->left->right->right = newNode(1);

    int targetSum = 8;

    int result = countPaths(root, targetSum);
    printf("Number of paths with sum %d: %d\n", targetSum, result);

    return 0;
}
