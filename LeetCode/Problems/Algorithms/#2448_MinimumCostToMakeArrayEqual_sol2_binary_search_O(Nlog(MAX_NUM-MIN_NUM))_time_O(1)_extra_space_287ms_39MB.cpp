class Solution {
private:
    long long computeTotalCost(vector<int>& nums, vector<int>& cost, const int& X){
        const int N = nums.size();
        long long totalCost = 0;
        for(int i = 0; i < N; ++i){
            totalCost += abs(nums[i] - X) * 1LL * cost[i];
        }
        return totalCost;
    }
    
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeTotalCost(nums, cost, mid) <= computeTotalCost(nums, cost, mid + 1)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return computeTotalCost(nums, cost, r);
    }
};