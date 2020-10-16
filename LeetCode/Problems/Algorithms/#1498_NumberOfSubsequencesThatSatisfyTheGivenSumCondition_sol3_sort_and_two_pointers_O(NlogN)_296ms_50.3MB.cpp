class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MODULO = (1e9) + 7;
        
        vector<int> p2(nums.size() + 1);
        p2[0] = 1;
        for(int i = 1; i < p2.size(); ++i){
            p2[i] = (p2[i - 1] * 2) % MODULO;
        }
        
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int i = 0;
        int j = (int)nums.size() - 1;
        while(i <= j){
            if(nums[i] + nums[j] > target){
                j -= 1;
            }else{
                answer = (answer + p2[j - i]) % MODULO;
                i += 1;
            }
        }
        
        return answer;
    }
};