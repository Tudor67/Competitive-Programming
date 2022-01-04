class Trie{
private:
    static const hash<string> STR_HASH_OBJ;
    static const long long MODULO = 1e9 + 7;
    map<string, Trie*> children;
    
    void computeSubtreeRepr(Trie* node, unordered_map<Trie*, int>& subtreeRepr){
        string childrenTreeStr;
        for(const pair<string, Trie*>& P: node->children){
            const string& CHILD_STR = P.first;
            Trie* child = P.second;
            computeSubtreeRepr(child, subtreeRepr);
            childrenTreeStr += "(" + CHILD_STR + "$" + to_string(subtreeRepr[child]) + ")";
        }
        subtreeRepr[node] = STR_HASH_OBJ(childrenTreeStr) % MODULO;
    }
    
    void collectUniqueFolders(Trie* node, vector<string>& path, unordered_map<Trie*, int>& subtreeRepr,
                              unordered_map<int, int>& reprCount, vector<vector<string>>& uniqueFolders){
        for(const pair<string, Trie*>& P: node->children){
            const string& CHILD_STR = P.first;
            Trie* child = P.second;
            if(reprCount[subtreeRepr[child]] == 1 || child->children.empty()){
                path.push_back(CHILD_STR);
                uniqueFolders.push_back(path);
                collectUniqueFolders(child, path, subtreeRepr, reprCount, uniqueFolders);
                path.pop_back();
            }
        }
    }
    
public:
    void insert(const vector<string>& WORDS){
        Trie* node = this;
        for(const string& WORD: WORDS){
            if(!node->children.count(WORD)){
                node->children[WORD] = new Trie();
            }
            node = node->children[WORD];
        }
    }
    
    void computeSubtreeRepr(unordered_map<Trie*, int>& subtreeRepr){
        subtreeRepr.clear();
        computeSubtreeRepr(this, subtreeRepr);
    }
    
    void collectUniqueFolders(unordered_map<Trie*, int>& subtreeRepr,
                              unordered_map<int, int>& reprCount, vector<vector<string>>& uniqueFolders){
        vector<string> path;
        collectUniqueFolders(this, path, subtreeRepr, reprCount, uniqueFolders);
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;
        for(const vector<string>& PATH: paths){
            trie.insert(PATH);
        }
        
        unordered_map<Trie*, int> subtreeRepr;
        trie.computeSubtreeRepr(subtreeRepr);
        
        unordered_map<int, int> reprCount;
        for(const pair<Trie*, int>& P: subtreeRepr){
            int repr = P.second;
            reprCount[repr] += 1;
        }
        
        vector<vector<string>> uniqueFolders;
        trie.collectUniqueFolders(subtreeRepr, reprCount, uniqueFolders);
        
        return uniqueFolders;
    }
};