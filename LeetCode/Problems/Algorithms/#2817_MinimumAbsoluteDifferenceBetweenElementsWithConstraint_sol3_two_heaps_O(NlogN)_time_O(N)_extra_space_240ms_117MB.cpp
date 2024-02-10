class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int N = nums.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (nums[lhs] < nums[rhs]);
             });

        int res = INT_MAX;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i: p){
            maxHeap.push(i);
            minHeap.push(i);
            while(!maxHeap.empty() && maxHeap.top() - i >= x){
                res = min(res, nums[i] - nums[maxHeap.top()]);
                maxHeap.pop();
            }
            while(!minHeap.empty() && i - minHeap.top() >= x){
                res = min(res, nums[i] - nums[minHeap.top()]);
                minHeap.pop();
            }
        }
        
        return res;
    }
};