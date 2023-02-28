class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int N = profits.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitingCapitalProfit;
        priority_queue<int> availableProfits;
        for(int i = 0; i < N; ++i){
            waitingCapitalProfit.push({capital[i], profits[i]});
        }
        
        int currentCapital = w;
        for(int i = 1; i <= k; ++i){
            while(!waitingCapitalProfit.empty() && waitingCapitalProfit.top().first <= currentCapital){
                availableProfits.push(waitingCapitalProfit.top().second);
                waitingCapitalProfit.pop();
            }
            if(!availableProfits.empty()){
                currentCapital += availableProfits.top();
                availableProfits.pop();
            }
        }

        return currentCapital;
    }
};