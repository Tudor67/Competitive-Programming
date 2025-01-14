class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int freq;
    unordered_map<int, Trie*> children;

public:
    Trie(){
        freq = 0;
    }

    ~Trie(){
        for(auto [edgeID, child]: children){
            delete child;
        }
    }

    void addPrefixSuffix(const string& S){
        Trie* node = this;
        for(int i = 0, j = (int)S.length() - 1; i < (int)S.length(); ++i, --j){
            int edgeID = (S[i] - FIRST_ELEM) * ALPHABET_SIZE + (S[j] - FIRST_ELEM);
            if(!node->children.count(edgeID)){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->freq += 1;
        }
    }

    int getFreq(const string& S){
        Trie* node = this;
        for(int i = 0, j = (int)S.length() - 1; i < (int)S.length(); ++i, --j){
            int edgeID = (S[i] - FIRST_ELEM) * ALPHABET_SIZE + (S[j] - FIRST_ELEM);
            if(!node->children.count(edgeID)){
                return 0;
            }
            node = node->children[edgeID];
        }
        return node->freq;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int N = words.size();

        Trie trie;
        int res = 0;
        for(int i = N - 1; i >= 0; --i){
            res += trie.getFreq(words[i]);
            trie.addPrefixSuffix(words[i]);
        }

        return res;
    }
};