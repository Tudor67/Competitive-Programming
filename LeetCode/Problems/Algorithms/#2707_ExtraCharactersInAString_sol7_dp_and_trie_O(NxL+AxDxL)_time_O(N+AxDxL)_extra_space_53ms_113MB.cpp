class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
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
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }

    Trie* getNextNode(char c){
        int edgeID = c - FIRST_ELEM;
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
        const int D = dictionary.size();

        Trie trie;
        for(string& w: dictionary){
            trie.insert(w);
        }

        // dp[i]: min number of extra characters left over when we break up s[i .. N - 1] optimally
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            Trie* currNode = &trie;
            for(int j = i; j < N && currNode != nullptr; ++j){
                currNode = currNode->getNextNode(s[j]);
                if(currNode != nullptr && currNode->isTerminalNodeCheck()){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};