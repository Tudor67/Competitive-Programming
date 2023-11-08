class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int N = prices.size();

        priority_queue<int> maxHeap;
        for(int price: prices){
            maxHeap.push(price);
            if((int)maxHeap.size() > 2){
                maxHeap.pop();
            }
        }

        int p2 = maxHeap.top(); maxHeap.pop();
        int p1 = maxHeap.top(); maxHeap.pop();
        int diff = money - (p1 + p2);
        if(diff >= 0){
            return diff;
        }

        return money;
    }
};