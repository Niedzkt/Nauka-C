void postOrder(struct Node* root){
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
    
}