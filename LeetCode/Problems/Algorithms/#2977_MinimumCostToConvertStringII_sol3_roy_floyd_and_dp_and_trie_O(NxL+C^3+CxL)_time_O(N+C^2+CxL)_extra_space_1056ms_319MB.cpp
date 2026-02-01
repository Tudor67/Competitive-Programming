class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    int wordIndex;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        fill(begin(children), end(children), nullptr);
        wordIndex = -1;
    }

    ~Trie(){
        for(Trie* child: children){
            delete child;
        }
    }

    Trie(const Trie&) = delete;

    Trie& operator=(const Trie&) = delete;
    
    void insert(const string& WORD, const int WORD_INDEX){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordIndex = WORD_INDEX;
    }

    int getWordIndex(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                return -1;
            }
            node = node->children[edgeID];
        }
        return node->wordIndex;
    }

    int getWordIndex(){
        return wordIndex;
    }
    
    Trie* getNextTrieNode(char c){
        int edgeID = c - FIRST_ELEM;
        return children[edgeID];
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int N = source.length();
        const int C = cost.size();
        const long long INF = 1e16;

        Trie trie;
        int currWordIndex = 0;
        for(int i = 0; i < C; ++i){
            if(trie.getWordIndex(original[i]) == -1){
                trie.insert(original[i], currWordIndex);
                currWordIndex += 1;
            }
            if(trie.getWordIndex(changed[i]) == -1){
                trie.insert(changed[i], currWordIndex);
                currWordIndex += 1;
            }
        }

        // roy-floyd algorithm
        const int TOTAL_NODES = currWordIndex;
        vector<vector<long long>> minCost(TOTAL_NODES, vector<long long>(TOTAL_NODES, INF));
        for(int i = 0; i < TOTAL_NODES; ++i){
            minCost[i][i] = 0;
        }

        for(int i = 0; i < C; ++i){
            int a = trie.getWordIndex(original[i]);
            int b = trie.getWordIndex(changed[i]);
            long long abCost = cost[i];
            minCost[a][b] = min(minCost[a][b], abCost);
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
            Trie* s = &trie;
            Trie* t = &trie;
            for(int j = i; j < N; ++j){
                s = s->getNextTrieNode(source[j]);
                t = t->getNextTrieNode(target[j]);
                if(s == nullptr || t == nullptr){
                    break;
                }
                int a = s->getWordIndex();
                int b = t->getWordIndex();
                if(a >= 0 && b >= 0){
                    dp[i] = min(dp[i], minCost[a][b] + dp[j + 1]);
                }
            }
            if(source[i] == target[i]){
                dp[i] = min(dp[i], dp[i + 1]);
            }
        }

        if(dp[0] != INF){
            return dp[0];
        }

        return -1;
    }
};