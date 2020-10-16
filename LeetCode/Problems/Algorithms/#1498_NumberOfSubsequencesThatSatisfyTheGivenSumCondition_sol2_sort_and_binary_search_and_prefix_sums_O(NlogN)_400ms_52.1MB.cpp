class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MODULO = (1e9) + 7;
        
        vector<int> prefSumP2(nums.size() + 1);
        vector<int> p2(nums.size() + 1);
        p2[0] = 1;
        prefSumP2[0] = 1;
        for(int i = 1; i < p2.size(); ++i){
            p2[i] = (p2[i - 1] * 2) % MODULO;
            prefSumP2[i] = (prefSumP2[i - 1] + p2[i]) % MODULO;
        }
        
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        for(int i = 1; i < nums.size() && nums[i] < target; ++i){
            int j = upper_bound(nums.begin(), nums.begin() + i + 1, target - nums[i]) - nums.begin() - 1;
            
            answer += (i == j);
            answer %= MODULO;
            
            j = min(j, i - 1);
            if(i >= 2){
                int sum = prefSumP2[i - 2] - (i - j - 2 >= 0 ? prefSumP2[i - j - 2] : 0);
                sum = (sum + MODULO) % MODULO;
                answer += sum;
                answer %= MODULO;
            }
        }
        
        return answer;
    }
};