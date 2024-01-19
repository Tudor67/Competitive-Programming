class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        const int N = nums.size();

        int deltaSum = 0;
        vector<int> delta(N + 1);

        for(int i = 0; i < N; ++i){
            deltaSum += delta[i];
            int currentValue = nums[i] - deltaSum;

            if(currentValue > 0){
                deltaSum += currentValue;
                if(i + k <= N){
                    delta[i + k] -= currentValue;
                }else{
                    return false;
                }
            }

            if(currentValue < 0){
                return false;
            }
        }
        
        return true;
    }
};