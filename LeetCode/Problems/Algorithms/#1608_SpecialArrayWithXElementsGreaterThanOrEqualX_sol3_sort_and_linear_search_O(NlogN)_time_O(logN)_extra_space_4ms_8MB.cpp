class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        for(int x = 1; x <= N; ++x){
            while(i < N && nums[i] < x){
                i += 1;
            }
            int count = N - i;
            if(x == count){
                return x;
            }
        }
        
        return -1;
    }
};