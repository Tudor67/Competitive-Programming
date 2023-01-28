class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void insertWord(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }

    void insertAllWords(const vector<string>& WORDS){
        for(const string& WORD: WORDS){
            insertWord(WORD);
        }
    }

    bool hasChild(char c){
        int edgeID = c - FIRST_CHAR;
        return (children[edgeID] != nullptr);
    }

    Trie* getChild(char c){
        int edgeID = c - FIRST_CHAR;
        return children[edgeID];
    }

    bool isTerminalNodeCheck(){
        return isTerminalNode;
    }
};

class Solution {
private:
    bool isConcatentationOfAtLeastTwoWords(const string& WORD, Trie* trieRoot){
        const int L = WORD.length();

        vector<int> dp(L);
        for(int i = 0; i < L; ++i){
            if(i == 0 || dp[i - 1] >= 1){
                Trie* trieCurrentNode = trieRoot;
                for(int j = i; j < L && trieCurrentNode->hasChild(WORD[j]); ++j){
                    trieCurrentNode = trieCurrentNode->getChild(WORD[j]);
                    if(trieCurrentNode->isTerminalNodeCheck()){
                        dp[j] = max(dp[j], (i == 0 ? 1 : dp[i - 1] + 1));
                    }
                }
            }
            if(dp[L - 1] >= 2){
                return true;
            }
        }

        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        const int N = words.size();

        Trie trie;
        trie.insertAllWords(words);

        vector<string> res;
        for(const string& WORD: words){
            if(isConcatentationOfAtLeastTwoWords(WORD, &trie)){
                res.push_back(WORD);
            }
        }

        return res;
    }
};