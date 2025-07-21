class Trie{
private:
    map<string, Trie*> children;
    string subtree;

    void dfs1(Trie* node, unordered_map<string, int>& freq){
        node->subtree.clear();
        for(const auto& [s, child]: node->children){
            dfs1(child, freq);
            node->subtree += "(" + s + "#" + child->subtree + ")";
        }
        freq[node->subtree] += 1;
    }

    void dfs2(Trie* node, unordered_map<string, int>& freq, vector<string>& path, vector<vector<string>>& uniqueFolders){
        for(const auto& [s, child]: node->children){
            if(freq[child->subtree] == 1 || child->children.empty()){
                path.push_back(s);
                uniqueFolders.push_back(path);
                dfs2(child, freq, path, uniqueFolders);
                path.pop_back();
            }
        }
    }

public:
    Trie(){

    }

    ~Trie(){
        for(const auto& [s, child]: children){
            delete child;
        }
    }

    void add(const vector<string>& PATH){
        Trie* node = this;
        for(const string& S: PATH){
            if(!node->children.count(S)){
                node->children[S] = new Trie();
            }
            node = node->children[S];
        }
    }

    vector<vector<string>> getUniqueFolders(){
        unordered_map<string, int> freq;
        dfs1(this, freq);

        vector<string> path;
        vector<vector<string>> uniqueFolders;
        dfs2(this, freq, path, uniqueFolders);

        return uniqueFolders;
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;
        for(const vector<string>& PATH: paths){
            trie.add(PATH);
        }
        return trie.getUniqueFolders();
    }
};