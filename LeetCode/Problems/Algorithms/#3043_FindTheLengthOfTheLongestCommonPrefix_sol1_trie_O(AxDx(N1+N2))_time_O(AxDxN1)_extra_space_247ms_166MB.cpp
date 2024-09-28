class Trie{
private:
    static const int ALPHABET_SIZE = 10;
    static const int FIRST_ELEM = '0';
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void insert(const string& S){
        Trie* node = this;
        for(char c: S){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
    }

    int computeMaxCommonPrefixLength(const string& S){
        int maxLen = 0;
        Trie* node = this;
        for(char c: S){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                break;
            }
            node = node->children[edgeID];
            maxLen += 1;
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int num: arr1){
            string s = to_string(num);
            trie.insert(s);
        }

        int maxCommonPrefixLength = 0;
        for(int num: arr2){
            string s = to_string(num);
            maxCommonPrefixLength = max(maxCommonPrefixLength, trie.computeMaxCommonPrefixLength(s));
        }

        return maxCommonPrefixLength;
    }
};