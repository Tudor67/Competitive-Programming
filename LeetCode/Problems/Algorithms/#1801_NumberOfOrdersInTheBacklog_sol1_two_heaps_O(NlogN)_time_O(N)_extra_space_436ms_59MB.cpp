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
                while(amount >= 1 && !sellMinHeap.empty() && sellMinHeap.top().first <= price){
                    PII sellPair = sellMinHeap.top();
                    sellMinHeap.pop();
                    
                    int take = min(sellPair.second, amount);
                    sellPair.second -= take;
                    amount -= take;
                    
                    if(sellPair.second >= 1){
                        sellMinHeap.push(sellPair);
                    }
                }
                
                if(amount >= 1){
                    buyMaxHeap.emplace(price, amount);
                }
            }else{
                while(amount >= 1 && !buyMaxHeap.empty() && price <= buyMaxHeap.top().first){
                    PII buyPair = buyMaxHeap.top();
                    buyMaxHeap.pop();
                    
                    int take = min(buyPair.second, amount);
                    buyPair.second -= take;
                    amount -= take;
                    
                    if(buyPair.second >= 1){
                        buyMaxHeap.push(buyPair);
                    }
                }
                
                if(amount >= 1){
                    sellMinHeap.emplace(price, amount);
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