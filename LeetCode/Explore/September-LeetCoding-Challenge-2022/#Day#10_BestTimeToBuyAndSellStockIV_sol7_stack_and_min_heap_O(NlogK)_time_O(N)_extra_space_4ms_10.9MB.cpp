class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        
        stack<pair<int, int>> st;
        vector<int> profits;
        
        int v = -1;
        int p = -1;
        while(p < N){
            v = p + 1;
            while(v + 1 < N && prices[v] >= prices[v + 1]){
                v += 1;
            }
            
            p = v;
            while(p + 1 < N && prices[p] <= prices[p + 1]){
                p += 1;
            }
            
            if(v == p){
                break;
            }
            
            while(!st.empty() && prices[st.top().first] >= prices[v]){
                profits.push_back(prices[st.top().second] - prices[st.top().first]);
                st.pop();
            }
            
            while(!st.empty() && prices[st.top().second] <= prices[p]){
                profits.push_back(prices[st.top().second] - prices[v]);
                v = st.top().first;
                st.pop();
            }
            
            st.emplace(v, p);
        }
        
        while(!st.empty()){
            int v = st.top().first;
            int p = st.top().second;
            st.pop();
            
            profits.push_back(prices[p] - prices[v]);
        }
        
        int maxProfit = 0;
        if((int)profits.size() <= k){
            maxProfit = accumulate(profits.begin(), profits.end(), 0);
        }else{
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int profit: profits){
                minHeap.push(profit);
                if((int)minHeap.size() > k){
                    minHeap.pop();
                }
            }
            
            while(!minHeap.empty()){
                int profit = minHeap.top();
                minHeap.pop();

                maxProfit += profit;
            }
        }
        
        return maxProfit;
    }
};