class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_CHAR = 'a';
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

    void insert(const string& WORD){
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

    bool isTerminalNodeCheck(){
        return isTerminalNode;
    }

    Trie* getNextNode(char c){
        int edgeID = c - FIRST_CHAR;
        return children[edgeID];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.length();
        const int W = wordDict.size();

        Trie trieRoot;
        for(const string& WORD: wordDict){
            trieRoot.insert(WORD);
        }

        // isPossible[i]: true, if is possible to segment s[i .. N - 1]
        //                false, otherwise
        vector<bool> isPossible(N + 1, false);
        isPossible[N] = true;

        for(int i = N - 1; i >= 0; --i){
            Trie* currentNode = &trieRoot;
            for(int j = i; j < N && currentNode != nullptr; ++j){
                currentNode = currentNode->getNextNode(s[j]);
                if(isPossible[j + 1] && currentNode != nullptr && currentNode->isTerminalNodeCheck()){
                    isPossible[i] = true;
                    break;
                }
            }
        }

        return isPossible[0];
    }
};