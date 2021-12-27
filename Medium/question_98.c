//
// Created by lzjlxebr on 11/30/21.
//

#include <stdbool.h>
#include <stddef.h>
#include <printf.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool traversal(struct TreeNode* root, int rootVal) {
    if (root->left != NULL) {
        if (root->left->val < root->val) {
            if (!traversal(root->left, rootVal)) return false;
        } else {
            return false;
        }
    } else {
        if (root->val > rootVal) return false;
    }

    if (root->right != NULL) {
        if (root->right->val > root->val) {
            if (!traversal(root->left, rootVal)) return false;
        } else {
            return false;
        }
    } else {
        if (root->val < rootVal) return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root) {
    return traversal(root, root->val);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    root->val = val;
    root->left = NULL;
    root->right = NULL;

    return root;
}

int main() {
    /*
                          5
                     3          8
                 2      4    7     9

                 [5,4,6,null,null,3,7]

                          5
                       4       6
                             3   7
     */

    struct TreeNode* left1 = newNode(4);
//    left1->left = newNode(2);
//    left1->right = newNode(4);

    struct TreeNode* right1 = newNode(6);
    right1->left = newNode(3);
    right1->right = newNode(7);


    struct TreeNode* root = newNode(5);
    root->left = left1;
    root->right = right1;

    int result = isValidBST(root);
    printf("returnSize: %d\n", result);
    return 0;
}

