#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int longestPathUtil(struct Node* root, int* maxLen) {
    if (root == NULL)
        return 0;
    int left = longestPathUtil(root->left, maxLen);
    int right = longestPathUtil(root->right, maxLen);
    int leftPath = 0, rightPath = 0;
    if (root->left && root->left->data == root->data)
        leftPath = left + 1;
    if (root->right && root->right->data == root->data)
        rightPath = right + 1;
    if (leftPath + rightPath > *maxLen)
        *maxLen = leftPath + rightPath;
    return (leftPath > rightPath) ? leftPath : rightPath;
}
int longestUnivaluePath(struct Node* root) {
    int maxLen = 0;
    longestPathUtil(root, &maxLen);
    return maxLen;
}
int main() {
    /*
            5
           / \
          4   5
         / \   \
        4   4   5
    */

    struct Node* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);

    int result = longestUnivaluePath(root);
    printf("Longest Univalue Path Length: %d\n", result);

    return 0;
}
