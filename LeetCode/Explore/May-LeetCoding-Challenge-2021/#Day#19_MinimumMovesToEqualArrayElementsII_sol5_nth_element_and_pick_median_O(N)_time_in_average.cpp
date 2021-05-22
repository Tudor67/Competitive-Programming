class Solution {
private:
    long long getCost(vector<int>& nums, const int& TARGET){
        long long cost = 0;
        for(int num: nums){
            cost += abs(TARGET - num);
        }
        return cost;
    }
    
public:
    int minMoves2(vector<int>& nums) {
        const int N = nums.size();
        nth_element(nums.begin(), nums.begin() + N / 2, nums.end());
        return getCost(nums, nums[N / 2]);
    }
};