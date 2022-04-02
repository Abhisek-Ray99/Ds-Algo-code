// using BFS

int minDepth(TreeNode *root){
    if(root == NULL) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()){
        depth += 1;
        int size = q.size();
        for(int start=0; start<size; start++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return depth;
}




// using DFS

int minDepth(TreeNode *root){
    if(root == NULL) return 0;
    int leftT = 1+minDepth(root->left);
    int rightT = 1+minDepth(root->right);
    return max(leftT, rightT);
}
