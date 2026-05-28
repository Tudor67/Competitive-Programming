class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    pair<int, int> minLenIdx;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        minLenIdx = {INT_MAX, INT_MAX};
        fill(begin(children), end(children), nullptr);
    }

    ~Trie(){
        for(Trie* child: children){
            delete child;
        }
    }

    void insert(const string& WORD, const pair<int, int>& LEN_IDX){
        Trie* node = this;
        node->minLenIdx = min(node->minLenIdx, LEN_IDX);
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->minLenIdx = min(node->minLenIdx, LEN_IDX);
        }
    }

    int getIndexOfLongestCommonPrefix(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                break;
            }
            node = node->children[edgeID];
        }
        return node->minLenIdx.second;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        const int N = wordsContainer.size();
        const int Q = wordsQuery.size();

        Trie trie;
        for(int i = 0; i < N; ++i){
            string revWord(wordsContainer[i].rbegin(), wordsContainer[i].rend());
            trie.insert(revWord, {revWord.length(), i});
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            string revWordQuery(wordsQuery[i].rbegin(), wordsQuery[i].rend());
            res[i] = trie.getIndexOfLongestCommonPrefix(revWordQuery);
        }

        return res;
    }
};