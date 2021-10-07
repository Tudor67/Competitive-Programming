class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    const int MAX_BITS;
    int terminalNodesOfSubtree;
    Trie* children[ALPHABET_SIZE];
    
    void update(Trie* node, int x, int bit, const int& VAL){
        if(bit >= 0){
            int edgeID = ((x >> bit) & 1);
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie(MAX_BITS);
            }
            update(node->children[edgeID], x, bit - 1, VAL);
        }
        node->terminalNodesOfSubtree += VAL;
    }
    
public:
    Trie(const int& MAX_BITS): MAX_BITS(MAX_BITS){
        terminalNodesOfSubtree = 0;
        for(int i = 0; i < Trie::ALPHABET_SIZE; ++i){
            children[i] = NULL;
        }
    }
    
    void insert(int x){
        update(this, x, MAX_BITS - 1, 1);
    }
    
    void erase(int x){
        update(this, x, MAX_BITS - 1, -1);
    }
    
    int findMaxComplement(int x){
        Trie* node = this;
        int maxComplement = 0;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            int edgeID = !((x >> bit) & 1);
            if(node->children[edgeID] != NULL && node->children[edgeID]->terminalNodesOfSubtree >= 1){
                node = node->children[edgeID];
                maxComplement = 2 * maxComplement + edgeID;
            }else{
                node = node->children[!edgeID];
                maxComplement = 2 * maxComplement + (!edgeID);
            }
        }
        return maxComplement;
    }
};

class Solution {
private:
    void dfs(int node, Trie& trie, vector<vector<int>>& children, unordered_map<int, vector<pair<int, int>>>& queryValIdxFor, vector<int>& results){
        trie.insert(node);
        
        if(queryValIdxFor.count(node)){
            for(const pair<int, int>& P: queryValIdxFor[node]){
                int queryVal = P.first;
                int queryIdx = P.second;
                int maxComplement = trie.findMaxComplement(queryVal);
                results[queryIdx] = maxComplement ^ queryVal;
            }
        }
        
        for(int child: children[node]){
            dfs(child, trie, children, queryValIdxFor, results);
        }
        
        trie.erase(node);
    }
    
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        const int N = parents.size();
        const int Q = queries.size();
        
        int root = -1;
        vector<vector<int>> children(N);
        for(int node = 0; node < N; ++node){
            if(parents[node] == -1){
                root = node;
            }else{
                children[parents[node]].push_back(node);
            }
        }
        
        vector<int> results(Q);
        unordered_map<int, vector<pair<int, int>>> queryValIdxFor;
        int maxVal = N - 1;
        for(int i = 0; i < Q; ++i){
            int queryNode = queries[i][0];
            int queryVal = queries[i][1];
            int queryIdx = i;
            queryValIdxFor[queryNode].push_back({queryVal, queryIdx});
            maxVal = max(maxVal, queryVal);
        }
        
        const int MAX_BITS = (int)floor(log2(maxVal)) + 1;
        
        Trie trie(MAX_BITS);
        dfs(root, trie, children, queryValIdxFor, results);
        
        return results;
    }
};