/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode*target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map <TreeNode*,TreeNode*> parent_track;
       markParents(root,parent_track,target);

       unordered_map<TreeNode*,bool>vis;
       vis[target]=true;
       queue<TreeNode*> q;
       q.push(target);
       int curr_level=0;
       while(!q.empty()){
        int size=q.size();
        if(curr_level==k)break;
        curr_level++;
        for(int i = 0 ; i < size ; i++){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
            if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            if(parent_track[curr] && !vis[parent_track[curr]]){
                q.push(parent_track[curr]);
                vis[parent_track[curr]]=true;
            }
        }
       }
       vector<int> result;
       while(!q.empty()){
         TreeNode*node=q.front();
         q.pop();
         result.push_back(node->val);
       }
       return result;
    }
};