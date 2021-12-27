//
// Created by lzjlxebr on 11/30/21.
// Note: The returned array must be malloced, assume caller calls free().
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traversal(struct TreeNode* root, int* returnSize, int* result) {
    if (root == NULL) return;

    traversal(root->left, returnSize, result);
    result[(*returnSize)++] = root->val;
    traversal(root->right, returnSize, result);
}

// inorder: left, root, right
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int * result = malloc(sizeof(int) * 100);
    traversal(root, returnSize, result);
    return result;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    root->val = val;
    root->left = NULL;
    root->right = NULL;

    return root;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int returnSize = 0;
    int *result = inorderTraversal(root, &returnSize);
    printf("returnSize: %d\n", returnSize);
    return 0;
}
