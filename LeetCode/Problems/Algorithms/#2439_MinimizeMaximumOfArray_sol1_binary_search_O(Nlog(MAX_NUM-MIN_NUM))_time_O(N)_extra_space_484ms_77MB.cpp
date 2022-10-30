class Solution {
private:
    bool isPossible(vector<long long>& nums, const long long& THRESHOLD){
        const int N = nums.size();
        for(int i = N - 1; i >= 1; --i){
            if(nums[i] > THRESHOLD){
                nums[i - 1] += (nums[i] - THRESHOLD);
            }
        }
        return (nums[0] <= THRESHOLD);
    }
    
public:
    int minimizeArrayValue(vector<int>& nums) {
        const int N = nums.size();
        
        vector<long long> numsCopy(N);
        
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        while(l != r){
            long long mid = (l + r) / 2;
            copy(nums.begin(), nums.end(), numsCopy.begin());
            if(isPossible(numsCopy, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};