/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int stoi(string& data, int pos){
        int val = 0;
        for(; pos < data.length() && isdigit(data[pos]); ++pos){
            val = 10 * val + (data[pos] - '0');
        }
        return val;
    }
    
    void encode(TreeNode* root, string& data){
        if(root == NULL){
            data += "N";
        }else{
            data += to_string(root->val);
            data += "L";
            encode(root->left, data);
            data += "R";
            encode(root->right, data);
        }
    }
    
    TreeNode* decode(string& data, int& pos){
        if(data[pos] == 'N'){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(data, pos));
        pos = data.find('L', pos) + 1;
        root->left = decode(data, pos);
        pos = data.find('R', pos) + 1;
        root->right = decode(data, pos);
        return root;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        encode(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return decode(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;