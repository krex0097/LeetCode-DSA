/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    pair<int,int> postOrder(TreeNode*root){
        if(!root)return {0,0};
        auto [lsum,lcnt]=root->left? postOrder(root->left):pair<int,int>{0,0};
        auto[rsum,rcnt] =root->right? postOrder(root->right):pair<int,int>{0,0};
        int sum= lsum+rsum+root->val, num= lcnt+rcnt+1;
        if(root->val==sum/num)cnt++;
        return {sum,num};
    }
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return cnt;
    }
};