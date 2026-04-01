/*
Use postorder from end and inorder partition to build the tree recursively.
  ⏱️ Complexity Analysis
Time Complexity: O(n^2)
Space Complexity: O(h)
  💻 Code Solution
*/
struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd)
        return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    if(inStart == inEnd)
        return root;

    int index;
    for(index = inStart; index <= inEnd; index++) {
        if(inorder[index] == val)
            break;
    }

    root->right = build(inorder, postorder, index + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}
