class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        int l = N + 1;
        int r = -1;
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    l = min(i, l);
                    r = max(j, r);
                }
            }
        }
        
        int answer = r - l + 1;
        if(answer <= 1){
            answer = 0;
        }
        
        return answer;
    }
};