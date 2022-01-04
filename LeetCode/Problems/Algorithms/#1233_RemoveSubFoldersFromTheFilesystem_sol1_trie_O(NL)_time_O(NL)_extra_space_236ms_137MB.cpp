class Trie{
private:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_ELEM = 'a';
    static const int SPECIAL_ELEM = '/';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    void collectFolderNames(Trie* node, string& st, vector<string>& folderNames){
        if(node == NULL){
            return;
        }else if(node->isTerminalNode){
            folderNames.push_back(st);
            folderNames.back().pop_back();
        }else{
            for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
                char c = (edgeID == ALPHABET_SIZE - 1 ? SPECIAL_ELEM : char(edgeID + FIRST_ELEM));
                st.push_back(c);
                collectFolderNames(node->children[edgeID], st, folderNames);
                st.pop_back();
            }
        }
    }
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = (c == SPECIAL_ELEM ? ALPHABET_SIZE - 1 : c - FIRST_ELEM);
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            if(c == SPECIAL_ELEM && node->isTerminalNode){
                return;
            }
        }
        node->isTerminalNode = true;
    }
    
    void collectFolderNames(vector<string>& folderNames){
        string st;
        folderNames.clear();
        collectFolderNames(this, st, folderNames);
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for(string word: folder){
            word += '/';
            trie.insert(word);
        }
        
        vector<string> folderNames;
        trie.collectFolderNames(folderNames);
        
        return folderNames;
    }
};