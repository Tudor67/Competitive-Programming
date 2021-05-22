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
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            long long midCost = getCost(nums, mid);
            long long nextMidCost = getCost(nums, mid + 1);
            if(midCost == nextMidCost){
                l = mid;
                r = mid;
            }else if(midCost < nextMidCost){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return getCost(nums, r);
    }
};