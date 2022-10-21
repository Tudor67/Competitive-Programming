class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    int count;
    int subtreeMaxCount;
    Trie* children[ALPHABET_SIZE];
    
    void add(Trie* node, const string& WORD, int pos){
        const int L = WORD.length();
        if(pos + 1 < L){
            int edgeID = WORD[pos + 1] - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            add(node->children[edgeID], WORD, pos + 1);
            node->subtreeMaxCount = max(node->subtreeMaxCount, node->children[edgeID]->subtreeMaxCount);
        }else{
            node->count += 1;
            node->subtreeMaxCount = max(node->subtreeMaxCount, node->count);
        }
    }
    
    void extractAndRemoveTopWord(Trie* node, string& word, bool& found){
        if(found){
            // stop the search
        }else if(node->count == node->subtreeMaxCount){
            found = true;
            node->count = 0;
        }else{
            for(int edgeID = 0; !found && edgeID < ALPHABET_SIZE; ++edgeID){
                if(node->children[edgeID] != nullptr && node->subtreeMaxCount == node->children[edgeID]->subtreeMaxCount){
                    word.push_back(FIRST_CHAR + edgeID);
                    extractAndRemoveTopWord(node->children[edgeID], word, found);
                }
            }
        }
        // update node->subtreeMaxCount when coming back to the trie root
        node->subtreeMaxCount = node->count;
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            if(node->children[edgeID] != nullptr){
                node->subtreeMaxCount = max(node->subtreeMaxCount, node->children[edgeID]->subtreeMaxCount);
            }
        }
    }
    
public:
    Trie(){
        count = 0;
        subtreeMaxCount = 0;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void add(const string& WORD){
        add(this, WORD, -1);
    }
    
    void extractAndRemoveTopKWords(int k, vector<string>& res){
        for(int i = 1; i <= k; ++i){
            string word;
            bool found = false;
            extractAndRemoveTopWord(this, word, found);
            res.push_back(word);
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        for(const string& WORD: words){
            trie.add(WORD);
        }
        
        vector<string> res;
        trie.extractAndRemoveTopKWords(k, res);
        
        return res;
    }
};