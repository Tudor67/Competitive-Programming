class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    bool isTerminalNode;
    vector<Trie*> children;
    
    void addPrefixSuggestions(Trie* node, const int& SUGGESTIONS_PER_PREFIX,
                              string& suggestion, vector<string>& suggestions){
        if((int)suggestions.size() < SUGGESTIONS_PER_PREFIX){
            if(node->isTerminalNode){
                suggestions.push_back(suggestion);
            }
            for(int edgeID = 0; edgeID < ALPHABET_SIZE && (int)suggestions.size() < SUGGESTIONS_PER_PREFIX; ++edgeID){
                if(node->children[edgeID] != NULL){
                    suggestion.push_back(char(edgeID + Trie::FIRST_ELEM));
                    addPrefixSuggestions(node->children[edgeID], SUGGESTIONS_PER_PREFIX, suggestion, suggestions);
                    suggestion.pop_back();
                }
            }
        }
    }
    
public:
    Trie(){
        isTerminalNode = false;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - Trie::FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    vector<vector<string>> getPrefixSuggestions(const string& SEARCH_WORD, const int& SUGGESTIONS_PER_PREFIX){
        const int L = SEARCH_WORD.length();
        vector<vector<string>> allSuggestions(L);
        Trie* node = this;
        for(int i = 0; i < L; ++i){
            int edgeID = SEARCH_WORD[i] - Trie::FIRST_ELEM;
            node = node->children[edgeID];
            if(node == NULL){
                break;
            }else{
                string suggestion = SEARCH_WORD.substr(0, i + 1);
                addPrefixSuggestions(node, SUGGESTIONS_PER_PREFIX, suggestion, allSuggestions[i]);
            }
        }
        return allSuggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(const string& PRODUCT: products){
            trie.insert(PRODUCT);
        }
        return trie.getPrefixSuggestions(searchWord, 3);
    }
};