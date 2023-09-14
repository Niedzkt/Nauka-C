void inOrder(struct Node* root){
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}