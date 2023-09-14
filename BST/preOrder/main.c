void preOrder(struct Node* root){
    if (root)
    {
        printf("%d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}