class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        int answer = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        
        for(int p1 = 0; answer != target && p1 < N - 2; ++p1){
            int p2 = p1 + 1;
            int p3 = N - 1;
            while(p2 < p3){
                int sum = nums[p1] + nums[p2] + nums[p3];
                if(abs(target - sum) < abs(target - answer)){
                    answer = sum;
                }
                if(sum < target){
                    p2 += 1;
                }else{
                    p3 -= 1;
                }
            }
        }
        
        return answer;
    }
};