class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        const int N = nums.size();

        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        while((int)maxHeap.size() >= 3 && sum <= 2 * maxHeap.top()){
            sum -= maxHeap.top();
            maxHeap.pop();
        }

        if((int)maxHeap.size() >= 3){
            return sum;
        }

        return -1;
    }
};