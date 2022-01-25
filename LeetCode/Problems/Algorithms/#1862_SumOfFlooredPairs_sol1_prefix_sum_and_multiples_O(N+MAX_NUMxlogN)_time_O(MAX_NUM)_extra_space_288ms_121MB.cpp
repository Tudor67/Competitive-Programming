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
        
        vector<int> prefCount(MAX_NUM + 1);
        for(int num = 1; num <= MAX_NUM; ++num){
            prefCount[num] = prefCount[num - 1] + count[num];
        }
        
        int answer = 0;
        for(int num = 1; num <= MAX_NUM; ++num){
            if(count[num] > 0){
                for(int multiple = num; multiple <= MAX_NUM; multiple += num){
                    int multipleRangeCount = prefCount[min(multiple + num - 1, MAX_NUM)] - prefCount[multiple - 1];
                    int multipleContrib = ((multiple / num) * 1LL * multipleRangeCount) % MODULO;
                    answer += (multipleContrib * 1LL * count[num]) % MODULO;
                    answer %= MODULO;
                }
            }
        }
        
        return answer;
    }
};