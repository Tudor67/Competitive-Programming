class Solution {
private:
    bool isStrictlyIncreasing(const vector<int>& NUMS){
        const int N = NUMS.size();
        for(int i = 1; i < N; ++i){
            if(NUMS[i - 1] >= NUMS[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int N = nums.size();
        
        if(isStrictlyIncreasing(nums)){
            return true;
        }
        
        vector<int> v;
        for(int i = 0; i < N; ++i){
            v.clear();
            for(int j = 0; j <= i - 1; ++j){
                v.push_back(nums[j]);
            }
            for(int j = i + 1; j < N; ++j){
                v.push_back(nums[j]);
            }
            if(isStrictlyIncreasing(v)){
                return true;
            }
        }
        
        return false;
    }
};