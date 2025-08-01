class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = log2(MAX_NUM + 1);

        vector<int> answer(N);
        vector<int> minPos(MAX_BIT + 1);
        for(int i = N - 1; i >= 0; --i){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((nums[i] >> bit) & 1){
                    minPos[bit] = i;
                }
            }
            answer[i] = 1;
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                answer[i] = max(answer[i], minPos[bit] - i + 1);
            }
        }

        return answer;
    }
};