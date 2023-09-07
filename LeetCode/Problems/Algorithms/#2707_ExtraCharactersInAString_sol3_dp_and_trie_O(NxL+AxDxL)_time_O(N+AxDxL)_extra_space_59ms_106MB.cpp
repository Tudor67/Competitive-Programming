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

    Trie* getNextNode(char c){
        int edgeID = c - FIRST_CHAR;
        return children[edgeID];
    }

    bool isTerminalNodeCheck(){
        return isTerminalNode;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();

        Trie trie;
        for(const string& WORD: dictionary){
            trie.insert(WORD);
        }

        // dp[i]: min cost for s[i ..]
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            Trie* currentNode = &trie;
            for(int j = i; j < N && currentNode != nullptr; ++j){
                currentNode = currentNode->getNextNode(s[j]);
                if(currentNode != nullptr && currentNode->isTerminalNodeCheck()){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};