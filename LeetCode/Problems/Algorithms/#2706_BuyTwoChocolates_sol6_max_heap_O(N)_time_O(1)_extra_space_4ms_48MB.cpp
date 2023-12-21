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

        int sum = 0;
        while(!maxHeap.empty()){
            sum += maxHeap.top();
            maxHeap.pop();
        }

        if(sum <= money){
            return money - sum;
        }

        return money;
    }
};