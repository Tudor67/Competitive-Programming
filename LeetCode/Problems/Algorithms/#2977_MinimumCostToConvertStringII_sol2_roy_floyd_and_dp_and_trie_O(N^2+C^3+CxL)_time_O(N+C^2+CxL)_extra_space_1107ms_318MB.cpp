class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    int wordID;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        wordID = -1;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void insert(const string& WORD, int wordID){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordID = wordID;
    }

    int getWordID(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                return -1;
            }
            node = node->children[edgeID];
        }
        return node->wordID;
    }

    int getWordID(){
        return this->wordID;
    }

    Trie* getNextTrieNode(char c){
        int edgeID = c - FIRST_CHAR;
        return this->children[edgeID];
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int N = source.length();
        const int C = changed.size();
        const long long INF = 1e16;

        Trie trie;
        int currentWordID = -1;
        for(int i = 0; i < C; ++i){
            if(trie.getWordID(original[i]) == -1){
                currentWordID += 1;
                trie.insert(original[i], currentWordID);
            }
            if(trie.getWordID(changed[i]) == -1){
                currentWordID += 1;
                trie.insert(changed[i], currentWordID);
            }
        }

        // Roy-Floyd Algorithm
        // minCost[trie.getWordID(originalStr)][trie.getWordID(changedStr)]: min cost to convert
        //                                                                   originalStr to changedStr
        const int TOTAL_NODES = currentWordID + 1;
        vector<vector<long long>> minCost(TOTAL_NODES, vector<long long>(TOTAL_NODES, INF));
        for(int i = 0; i < C; ++i){
            int a = trie.getWordID(original[i]);
            int b = trie.getWordID(changed[i]);
            minCost[a][b] = min(minCost[a][b], (long long)cost[i]);
        }

        for(int i = 0; i < TOTAL_NODES; ++i){
            minCost[i][i] = 0;
        }

        for(int k = 0; k < TOTAL_NODES; ++k){
            for(int i = 0; i < TOTAL_NODES; ++i){
                for(int j = 0; j < TOTAL_NODES; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        // dp[i]: min cost to convert source[i .. N - 1] to target[i .. N - 1]
        vector<long long> dp(N + 1, INF);
        dp[N] = 0;

        for(int i = N - 1; i >= 0; --i){
            Trie* aNode = &trie;
            Trie* bNode = &trie;
            for(int j = i; j < N && aNode != nullptr && bNode != nullptr; ++j){
                aNode = aNode->getNextTrieNode(source[j]);
                bNode = bNode->getNextTrieNode(target[j]);
                if(aNode != nullptr && bNode != nullptr && aNode->getWordID() != -1 && bNode->getWordID() != -1){
                    dp[i] = min(dp[i], minCost[aNode->getWordID()][bNode->getWordID()] + dp[j + 1]);
                }
            }
            for(int j = i; j < N && source[j] == target[j]; ++j){
                dp[i] = min(dp[i], dp[j + 1]);
            }
        }

        if(dp[0] == INF){
            dp[0] = -1;
        }

        return dp[0];
    }
};