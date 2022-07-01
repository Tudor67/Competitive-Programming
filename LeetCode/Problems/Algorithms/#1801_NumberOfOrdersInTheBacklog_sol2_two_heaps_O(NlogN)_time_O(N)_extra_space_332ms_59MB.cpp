class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MODULO = 1e9 + 7;
        const int BUY = 0;
        const int SELL = 1;
        const int N = orders.size();
        
        // (price, amount)
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, less<PII>> buyMaxHeap;
        priority_queue<PII, vector<PII>, greater<PII>> sellMinHeap;
        
        for(const vector<int>& ORDER: orders){
            int price = ORDER[0];
            int amount = ORDER[1];
            int orderType = ORDER[2];
            
            if(orderType == BUY){
                buyMaxHeap.emplace(price, amount);
            }else{
                sellMinHeap.emplace(price, amount);
            }
            
            while(!buyMaxHeap.empty() && !sellMinHeap.empty() && sellMinHeap.top().first <= buyMaxHeap.top().first){
                PII sellPair = sellMinHeap.top(); sellMinHeap.pop();
                PII buyPair = buyMaxHeap.top(); buyMaxHeap.pop();
                
                int minAmount = min(sellPair.second, buyPair.second);
                sellPair.second -= minAmount;
                buyPair.second -= minAmount;
                
                if(sellPair.second >= 1){
                    sellMinHeap.push(sellPair);
                }
                if(buyPair.second >= 1){
                    buyMaxHeap.push(buyPair);
                }
            }
        }
        
        int res = 0;
        while(!buyMaxHeap.empty()){
            res = (res + buyMaxHeap.top().second) % MODULO;
            buyMaxHeap.pop();
        }
        
        while(!sellMinHeap.empty()){
            res = (res + sellMinHeap.top().second) % MODULO;
            sellMinHeap.pop();
        }
        
        return res;
    }
};