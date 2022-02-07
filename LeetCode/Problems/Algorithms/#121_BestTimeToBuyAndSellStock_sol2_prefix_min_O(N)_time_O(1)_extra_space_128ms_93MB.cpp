class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int minPrefixPrice = prices[0];
        for(int price: prices){
            minPrefixPrice = min(minPrefixPrice, price);
            answer = max(answer, price - minPrefixPrice);
        }
        return answer;
    }
};