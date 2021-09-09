class Solution { 
public:
    int arrayNesting(vector<int>& nums) {
        const int N = nums.size();
        
        int maxLength = 0;
        for(int startPos = 0; startPos < N; ++startPos){
            if(nums[startPos] >= 0){
                int length = 0;
                int k = startPos;
                while(nums[k] >= 0){
                    length += 1;
                    int kPrev = k;
                    k = nums[k];
                    nums[kPrev] -= N;
                }
                maxLength = max(maxLength, length);
            }
        }
        
        for(int i = 0; i < N; ++i){
            nums[i] += N;
        }
        
        return maxLength;
    }
};