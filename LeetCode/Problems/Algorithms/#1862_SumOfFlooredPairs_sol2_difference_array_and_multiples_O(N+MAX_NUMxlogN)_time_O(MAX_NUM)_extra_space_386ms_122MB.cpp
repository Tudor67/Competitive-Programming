class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MODULO = 1e9 + 7;
        
        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            count[num] += 1;
        }
        
        vector<int> diff(MAX_NUM + 1);
        for(int num = 1; num <= MAX_NUM; ++num){
            if(count[num] > 0){
                for(int multiple = num; multiple <= MAX_NUM; multiple += num){
                    int w = (count[num] * 1LL * (multiple / num)) % MODULO;
                    diff[multiple] += w;
                    diff[multiple] %= MODULO;
                    if(multiple + num <= MAX_NUM){
                        diff[multiple + num] -= w;
                        diff[multiple + num] += MODULO;
                        diff[multiple + num] %= MODULO;
                    }
                }
            }
        }
        
        int answer = 0;
        int w = 0;
        for(int num = 1; num <= MAX_NUM; ++num){
            w += diff[num];
            w %= MODULO;
            answer += (w * 1LL * count[num]) % MODULO;
            answer %= MODULO;
        }
        
        return answer;
    }
};