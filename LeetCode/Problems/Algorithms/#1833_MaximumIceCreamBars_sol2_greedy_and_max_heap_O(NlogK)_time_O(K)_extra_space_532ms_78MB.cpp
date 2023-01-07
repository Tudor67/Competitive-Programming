class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int N = costs.size();

        // remove the max (N - K) costs
        // K is the max number of ice cream bars we can buy
        priority_queue<int> maxHeap;
        for(int cost: costs){
            maxHeap.push(cost);
            coins -= cost;
            if(coins < 0){
                coins += maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};