class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int prefix_sum = 0;
        map<int, int> cnt;
        cnt[0] = 1;
        for(int num: nums){
            prefix_sum += num;
            if(cnt.count(prefix_sum - k)){
                answer += cnt[prefix_sum - k];
            }
            cnt[prefix_sum] += 1;
        }
        return answer;
    }
};