class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int prefSum = 0;
        unordered_map<int, int> count;
        for(int num: nums){
            count[prefSum] += 1;
            prefSum += num;
            if(count.count(prefSum - k)){
                answer += count[prefSum - k];
            }
        }
        return answer;
    }
};