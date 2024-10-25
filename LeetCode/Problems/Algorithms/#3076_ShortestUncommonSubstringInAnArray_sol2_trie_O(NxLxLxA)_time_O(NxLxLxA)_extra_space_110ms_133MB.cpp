class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int wordCount;
    Trie* children[ALPHABET_SIZE];

    void addSubstringsStartingAt(const string& S, int contrib, int startIndex){
        Trie* node = this;
        for(int i = startIndex; i < (int)S.length(); ++i){
            int edgeID = S[i] - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->wordCount += contrib;
        }
    }

    void updateShortestUncommonStartingAt(const string& S, int startIndex, string& res){
        Trie* node = this;
        for(int i = startIndex; i < (int)S.length(); ++i){
            int edgeID = S[i] - FIRST_ELEM;
            node = node->children[edgeID];
            if(node->wordCount == 0){
                string substr = S.substr(startIndex, i - startIndex + 1);
                if((res.empty()) ||
                   (res.length() > substr.length()) ||
                   (res.length() == substr.length() && res > substr)){
                    res = substr;
                }
                break;
            }
        }
    }

public:
    Trie(){
        wordCount = 0;
        fill(begin(children), end(children), nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void addAllSubstrings(const string& S, int contrib){
        for(int i = 0; i < (int)S.length(); ++i){
            addSubstringsStartingAt(S, contrib, i);
        }
    }

    string searchShortestUncommon(const string& S){
        string res;
        for(int i = 0; i < (int)S.length(); ++i){
            updateShortestUncommonStartingAt(S, i, res);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        const int N = arr.size();

        Trie trie;
        for(int i = 0; i < N; ++i){
            trie.addAllSubstrings(arr[i], 1);
        }

        vector<string> res(N);
        for(int i = 0; i < N; ++i){
            trie.addAllSubstrings(arr[i], -1);
            res[i] = trie.searchShortestUncommon(arr[i]);
            trie.addAllSubstrings(arr[i], 1);
        }

        return res;
    }
};