class Solution {
private:
    bool isPossible(vector<int>& nums, const long long& THRESHOLD){
        const int N = nums.size();
        long long excess = 0;
        for(int i = N - 1; i >= 1; --i){
            if(nums[i] + excess > THRESHOLD){
                excess = (nums[i] + excess - THRESHOLD);
            }else{
                excess = 0;
            }
        }
        return (nums[0] + excess <= THRESHOLD);
    }
    
public:
    int minimizeArrayValue(vector<int>& nums) {
        const int N = nums.size();
        
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        while(l != r){
            long long mid = (l + r) / 2;
            if(isPossible(nums, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};