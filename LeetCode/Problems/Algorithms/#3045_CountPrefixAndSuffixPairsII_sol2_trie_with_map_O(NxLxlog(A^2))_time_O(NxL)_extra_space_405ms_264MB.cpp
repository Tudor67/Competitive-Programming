class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    int wordCount;
    map<int, Trie*> children;

public:
    Trie(){
        wordCount = 0;
    }
    /*
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE * ALPHABET_SIZE; ++edgeID){
            if(children.count(edgeID)){
                delete children[edgeID];
            }
        }
    }
    */
    void prefixSuffixInsert(const string& S){
        const int S_LEN = S.length();
        Trie* node = this;
        for(int i = 0; i < S_LEN; ++i){
            int j = S_LEN - 1 - i;
            int edgeID = (S[i] - FIRST_CHAR) * ALPHABET_SIZE + (S[j] - FIRST_CHAR);
            if(!node->children.count(edgeID)){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordCount += 1;
    }

    int countPrefixSuffixMatches(const string& S){
        const int S_LEN = S.length();
        int matches = 0;
        Trie* node = this;
        for(int i = 0; i < S_LEN; ++i){
            int j = S_LEN - 1 - i;
            int edgeID = (S[i] - FIRST_CHAR) * ALPHABET_SIZE + (S[j] - FIRST_CHAR);
            if(!node->children.count(edgeID)){
                break;
            }
            node = node->children[edgeID];
            matches += node->wordCount;
        }
        return matches;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long res = 0;
        Trie trie;
        for(const string& WORD: words){
            res += trie.countPrefixSuffixMatches(WORD);
            trie.prefixSuffixInsert(WORD);
        }
        return res;
    }
};