class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int N = happiness.size();
        
        long long res = 0;
        priority_queue<int> maxHeap(happiness.begin(), happiness.end());
        for(int i = 0; i < k; ++i){
            res += max(0, maxHeap.top() - i);
            maxHeap.pop();
        }
        
        return res;
    }
};