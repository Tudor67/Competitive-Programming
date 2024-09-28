class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int count;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        count = 0;
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
            node->count += 1;
        }
    }

    int getPrefixesContrib(const string& S){
        int contrib = 0;
        Trie* node = this;
        for(char c: S){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                break;
            }
            node = node->children[edgeID];
            contrib += node->count;
        }
        return contrib;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int N = words.size();

        Trie trie;
        for(int i = 0; i < N; ++i){
            trie.insert(words[i]);
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = trie.getPrefixesContrib(words[i]);
        }

        return res;
    }
};