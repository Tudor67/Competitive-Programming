class Solution {
private:
    const int MODULO = (1e9) + 7;
    
    int pow2(int n){
        long long a = 2;
        int p = 1;
        while(n > 0){
            if(n & 1){
                p = (p * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n /= 2;
        }
        return p;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        for(int i = 1; i < nums.size() && nums[i] < target; ++i){
            int j = upper_bound(nums.begin(), nums.begin() + i + 1, target - nums[i]) - nums.begin() - 1;
            
            answer += (i == j);
            answer %= MODULO;
            for(int k = min(j, i - 1); k >= 1; --k){
                answer += pow2(i - k - 1);
                answer %= MODULO;
            }
        }
        
        return answer;
    }
};