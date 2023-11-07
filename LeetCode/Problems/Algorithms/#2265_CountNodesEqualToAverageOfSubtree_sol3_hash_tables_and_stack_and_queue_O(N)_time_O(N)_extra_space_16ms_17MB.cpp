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
    int averageOfSubtree(TreeNode* root) {
        // Step 1: store the parent of each node (using a hash table `parent`)
        //         store the number of direct children of a node (using a hash table `childrenCount`)
        //         store the leaves in a queue `q`
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> childrenCount;
        queue<TreeNode*> q;

        stack<TreeNode*> st;
        if(root != nullptr){
            st.push(root);
        }

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node->right != nullptr){
                st.push(node->right);
                parent[node->right] = node;
                childrenCount[node] += 1;
            }
            if(node->left != nullptr){
                st.push(node->left);
                parent[node->left] = node;
                childrenCount[node] += 1;
            }

            if(node->left == nullptr && node->right == nullptr){
                q.push(node);
            }
        }

        // Step 2: compute the sum and size of each subtree (using a hash table `sumOf` and `sizeOf`)
        //         by traversing the tree from leaves to root node (similar to topological sort)
        //         update the result `res` when the average of the subtree is equal with the value of the subtree root
        int res = 0;
        unordered_map<TreeNode*, int> sumOf;
        unordered_map<TreeNode*, int> sizeOf;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            sumOf[node] += node->val;
            sizeOf[node] += 1;

            if(sumOf[node] / sizeOf[node] == node->val){
                res += 1;
            }

            if(parent.count(node)){
                sumOf[parent[node]] += sumOf[node];
                sizeOf[parent[node]] += sizeOf[node];
                childrenCount[parent[node]] -= 1;
                if(childrenCount[parent[node]] == 0){
                    q.push(parent[node]);
                }
            }
        }

        return res;
    }
};