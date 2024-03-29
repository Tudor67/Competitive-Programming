class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> minIndexOf(MAX_NUM + 1, N);

        for(int i = 0; i < N; ++i){
            int num = nums[i];
            minIndexOf[num] = min(minIndexOf[num], i);
            
            for(int prevNum = 0; prevNum <= MAX_NUM; ++prevNum){
                if(i - minIndexOf[prevNum] >= indexDifference && abs(num - prevNum) >= valueDifference){
                    return {i, minIndexOf[prevNum]};
                }
            }
        }

        return {-1, -1};
    }
};