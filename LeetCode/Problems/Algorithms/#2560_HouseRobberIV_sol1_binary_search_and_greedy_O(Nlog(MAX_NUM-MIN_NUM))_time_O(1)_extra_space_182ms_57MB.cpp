class Solution {
private:
    bool isValid(vector<int>& nums, int k, const int& CAPABILITY){
        const int N = nums.size();
        
        int prevTakenIndex = -2;
        for(int i = 0; i < N && k >= 1; ++i){
            if(nums[i] <= CAPABILITY && prevTakenIndex + 1 < i){
                k -= 1;
                prevTakenIndex = i;
            }
        }
        
        return (k == 0);
    }
    
public:
    int minCapability(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(nums, k, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};