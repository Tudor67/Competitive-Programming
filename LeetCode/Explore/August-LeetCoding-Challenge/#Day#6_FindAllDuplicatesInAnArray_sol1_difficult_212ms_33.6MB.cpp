class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N; ++i){
            int pos = 1 + (nums[i] - 1) % N;
            nums[pos - 1] += N;
        }
        
        vector<int> answer;
        for(int pos = 1; pos <= N; ++pos){
            if(nums[pos - 1] >= 2 * N + 1){
                answer.push_back(pos);
            }
        }
        
        return answer;
    }
};