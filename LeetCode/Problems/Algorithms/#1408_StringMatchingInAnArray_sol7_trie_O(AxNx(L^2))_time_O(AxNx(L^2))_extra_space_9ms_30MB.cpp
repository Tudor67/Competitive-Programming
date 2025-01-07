class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int freq;
    Trie* children[ALPHABET_SIZE];

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

    void add(const string& S, const int START_INDEX){
        Trie* node = this;
        for(int i = START_INDEX; i < (int)S.length(); ++i){
            int edgeID = S[i] - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->freq += 1;
        }
    }

    int getFreq(const string& S){
        Trie* node = this;
        for(int i = 0; i < (int)S.length(); ++i){
            int edgeID = S[i] - FIRST_ELEM;
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
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();

        Trie trie;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < (int)words[i].length(); ++j){
                trie.add(words[i], j);
            }
        }

        vector<string> res;
        for(int i = 0; i < N; ++i){
            if(trie.getFreq(words[i]) >= 2){
                res.push_back(words[i]);
            }
        }

        return res;
    }
};