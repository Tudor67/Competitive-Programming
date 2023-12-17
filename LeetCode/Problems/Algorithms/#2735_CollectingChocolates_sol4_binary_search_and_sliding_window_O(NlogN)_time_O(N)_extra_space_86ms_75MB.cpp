class Solution {
private:
    long long computeMinCost(vector<int>& nums, long long x, long long operations){
        const int N = nums.size();

        long long minCost = x * operations;

        deque<int> dq;
        for(int i = 0; i < N + operations; ++i){
            while(!dq.empty() && nums[dq.back() % N] >= nums[i % N]){
                dq.pop_back();
            }
            dq.push_back(i);
            while(!dq.empty() && i - dq.front() > operations){
                dq.pop_front();
            }
            if(i >= operations){
                minCost += nums[dq.front() % N];
            }
        }

        return minCost;
    }

public:
    long long minCost(vector<int>& nums, int x) {
        const int N = nums.size();

        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeMinCost(nums, x, mid) <= computeMinCost(nums, x, mid + 1)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return computeMinCost(nums, x, r);
    }
};