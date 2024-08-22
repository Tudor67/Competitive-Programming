class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(1);

        for(int step = 1; step <= n - 1; ++step){
            int num = minHeap.top();
            minHeap.pop();

            while(!minHeap.empty() && num == minHeap.top()){
                minHeap.pop();
            }

            for(int p: {2, 3, 5}){
                if(num <= INT_MAX / p){
                    minHeap.push(p * num);
                }
            }
        }

        return minHeap.top();
    }
};