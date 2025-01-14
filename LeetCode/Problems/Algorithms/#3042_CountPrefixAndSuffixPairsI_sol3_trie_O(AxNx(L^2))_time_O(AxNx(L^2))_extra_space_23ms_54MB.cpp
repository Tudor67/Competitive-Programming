class Trie{
private:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_ELEM = 'a';
    static const int SPECIAL_CHAR = '#';
    int freq;
    Trie* children[ALPHABET_SIZE];

    int getEdgeID(char c){
        if(c == SPECIAL_CHAR){
            return ALPHABET_SIZE - 1;
        }
        return c - FIRST_ELEM;
    }

public:
    Trie(){
        freq = 0;
        fill(begin(children), end(children), nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void add(const string& S){
        Trie* node = this;
        bool visSpecialChar = false;
        for(char c: S){
            int edgeID = getEdgeID(c);
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            if(visSpecialChar){
                node->freq += 1;
            }
            if(c == SPECIAL_CHAR){
                visSpecialChar = true;
            }
        }
    }

    int getFreq(const string& S){
        Trie* node = this;
        for(char c: S){
            int edgeID = getEdgeID(c);
            if(node->children[edgeID] == nullptr){
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
            res += trie.getFreq(words[i] + "#" + string(words[i].rbegin(), words[i].rend()));
            for(int len = 1; len <= (int)words[i].length(); ++len){
                string prefRevSuff = words[i].substr(0, len) + "#" + string(words[i].rbegin(), words[i].rend());
                trie.add(prefRevSuff);
            }
        }

        return res;
    }
};