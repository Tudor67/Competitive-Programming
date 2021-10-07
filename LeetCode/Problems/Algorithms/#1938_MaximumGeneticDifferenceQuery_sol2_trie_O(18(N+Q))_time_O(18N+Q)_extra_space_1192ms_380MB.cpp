class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    static const int FIRST_ELEM = '0';
    int terminalNodesOfSubtree;
    Trie* children[ALPHABET_SIZE];
    
    void update(Trie* node, const string& WORD, int idx, const int& VAL){
        if(idx < (int)WORD.length()){
            int edgeID = WORD[idx] - Trie::FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            update(node->children[edgeID], WORD, idx + 1, VAL);
        }
        node->terminalNodesOfSubtree += VAL;
    }
    
public:
    Trie(){
        terminalNodesOfSubtree = 0;
        for(int i = 0; i < Trie::ALPHABET_SIZE; ++i){
            children[i] = NULL;
        }
    }
    
    void insert(const string& WORD){
        update(this, WORD, 0, 1);
    }
    
    void erase(const string& WORD){
        update(this, WORD, 0, -1);
    }
    
    string findMaxComplement(const string& WORD){
        Trie* node = this;
        string maxComplement;
        for(char c: WORD){
            int edgeID = !(c - Trie::FIRST_ELEM);
            if(node->children[edgeID] != NULL && node->children[edgeID]->terminalNodesOfSubtree >= 1){
                node = node->children[edgeID];
                maxComplement += char(edgeID + Trie::FIRST_ELEM);
            }else{
                node = node->children[!edgeID];
                maxComplement += char(!edgeID + Trie::FIRST_ELEM);
            }
        }
        return maxComplement;
    }
};

class Solution {
private:
    string binaryRepresentationAsString(int x){
        return bitset<18>(x).to_string();
    }
    
    void dfs(int node, Trie& trie, vector<vector<int>>& children, unordered_map<int, vector<pair<int, int>>>& queryValIdxFor, vector<int>& results){
        trie.insert(binaryRepresentationAsString(node));
        
        if(queryValIdxFor.count(node)){
            for(const pair<int, int>& P: queryValIdxFor[node]){
                int queryVal = P.first;
                int queryIdx = P.second;
                string maxComplementStr = trie.findMaxComplement(binaryRepresentationAsString(queryVal));
                int maxComplement = stoi(maxComplementStr, NULL, 2);
                results[queryIdx] = maxComplement ^ queryVal;
            }
        }
        
        for(int child: children[node]){
            dfs(child, trie, children, queryValIdxFor, results);
        }
        
        trie.erase(binaryRepresentationAsString(node));
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
        for(int i = 0; i < Q; ++i){
            int queryNode = queries[i][0];
            int queryVal = queries[i][1];
            int queryIdx = i;
            queryValIdxFor[queryNode].push_back({queryVal, queryIdx});
        }
        
        Trie trie;
        dfs(root, trie, children, queryValIdxFor, results);
        
        return results;
    }
};