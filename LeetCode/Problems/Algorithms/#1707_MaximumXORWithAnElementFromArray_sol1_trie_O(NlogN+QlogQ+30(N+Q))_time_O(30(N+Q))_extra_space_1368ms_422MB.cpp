class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    static const int FIRST_ELEM = '0';
    bool isTerminalNode;
    vector<Trie*> children;
    
public:
    Trie(){
        isTerminalNode = false;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void add(const string& WORD){
        Trie* node = this;
        for(int c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    string getMaxComplement(const string& X){
        Trie* node = this;
        string maxComplement;
        for(int i = 0; i < (int)X.length(); ++i){
            int selectedEdgeID = -1;
            int complementEdgeID = (X[i] - FIRST_ELEM) ^ 1;
            if(node->children[complementEdgeID]){
                selectedEdgeID = complementEdgeID;
            }else if(node->children[complementEdgeID ^ 1]){
                selectedEdgeID = complementEdgeID ^ 1;
            }
            if(selectedEdgeID >= 0){
                maxComplement.push_back(FIRST_ELEM + selectedEdgeID);
                node = node->children[selectedEdgeID];
            }else{
                maxComplement.clear();
                break;
            }
        }
        return maxComplement;
    }
};

class Solution {
private:
    static bool increasingM(const tuple<int, int, int>& LHS, const tuple<int, int, int>& RHS){
        return (get<2>(LHS) < get<2>(RHS));
    }
    
    string getBinaryRepresentation30(int num){
        return bitset<30>(num).to_string();
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        
        vector<int> numsSorted = nums;
        vector<tuple<int, int, int>> queriesSorted(Q);
        for(int i = 0; i < Q; ++i){
            queriesSorted[i] = {i, queries[i][0], queries[i][1]};
        }
        
        sort(numsSorted.begin(), numsSorted.end());
        sort(queriesSorted.begin(), queriesSorted.end(), increasingM);
        
        vector<int> answer(Q, -1);
        Trie trie;
        for(int i = 0, j = 0; j < Q; ++j){
            int queryIdx, x, m;
            tie(queryIdx, x, m) = queriesSorted[j];
            while(i < N && numsSorted[i] <= m){
                trie.add(getBinaryRepresentation30(numsSorted[i]));
                i += 1;
            }
            string maxComplementBinaryRepresentation = trie.getMaxComplement(getBinaryRepresentation30(x));
            if(!maxComplementBinaryRepresentation.empty()){
                int maxComplement = stoll(maxComplementBinaryRepresentation, NULL, 2);
                answer[queryIdx] = x ^ maxComplement;
            }
        }
        
        return answer;
    }
};