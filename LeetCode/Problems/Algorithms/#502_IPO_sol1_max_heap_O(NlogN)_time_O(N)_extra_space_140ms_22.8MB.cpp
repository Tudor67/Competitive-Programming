class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& profits, vector<int>& capital) {
        const int N = profits.size();
        
        vector<pair<int, int>> capitalProfit(N);
        for(int i = 0; i < N; ++i){
            capitalProfit[i] = {capital[i], profits[i]};
        }
        
        sort(capitalProfit.begin(), capitalProfit.end());
        
        priority_queue<int> maxHeap;
        int pos = 0;
        for(int step = 1; step <= k; ++step){
            while(pos < N && capitalProfit[pos].first <= W){
                maxHeap.push(capitalProfit[pos].second);
                pos += 1;
            }
            if(!maxHeap.empty()){
                W += maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return W;
    }
};