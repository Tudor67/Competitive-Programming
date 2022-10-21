class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(const string& WORD: words){
            count[WORD] += 1;
        }
        
        auto comp = [&](const string& LHS_WORD, const string& RHS_WORD){
            return (count[LHS_WORD] > count[RHS_WORD]) ||
                   (count[LHS_WORD] == count[RHS_WORD] && LHS_WORD < RHS_WORD);
        };
        
        priority_queue<string, vector<string>, decltype(comp)> minHeap(comp);
        for(const pair<string, int>& P: count){
            const string& WORD = P.first;
            minHeap.push(WORD);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        vector<string> res(k);
        for(int i = k - 1; i >= 0; --i){
            res[i] = minHeap.top();
            minHeap.pop();
        }
        
        return res;
    }
};