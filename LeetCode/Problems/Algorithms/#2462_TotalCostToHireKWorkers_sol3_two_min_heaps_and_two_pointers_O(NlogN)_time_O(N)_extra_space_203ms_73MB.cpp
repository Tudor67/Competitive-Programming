class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int N = costs.size();

        long long res = 0;
        int leftIndex = -1;
        int rightIndex = N;
        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        for(int step = 1; step <= k; ++step){
            while(leftIndex + 1 < rightIndex && (int)leftHeap.size() < candidates){
                leftIndex += 1;
                leftHeap.push(costs[leftIndex]);
            }
            while(leftIndex < rightIndex - 1 && (int)rightHeap.size() < candidates){
                rightIndex -= 1;
                rightHeap.push(costs[rightIndex]);
            }

            if(rightHeap.empty() || (!leftHeap.empty() && leftHeap.top() <= rightHeap.top())){
                res += leftHeap.top();
                leftHeap.pop();
            }else{
                res += rightHeap.top();
                rightHeap.pop();
            }
        }

        return res;
    }
};