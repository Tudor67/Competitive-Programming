class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        
        const int N = nums.size();
        int l = N + 1;
        int r = -1;
        for(int i = 0; i < N; ++i){
            if(sorted_nums[i] != nums[i]){
                l = min(i, l);
                r = max(i, r);
            }
        }
        
        int answer = r - l + 1;
        if(answer <= 1){
            answer = 0;
        }
        
        return answer;
    }
};