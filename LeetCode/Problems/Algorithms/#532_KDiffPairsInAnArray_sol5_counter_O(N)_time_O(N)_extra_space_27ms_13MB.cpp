class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        int answer = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            count[num] -= 1;
            if(count.count(num - k) && count[num - k] > 0){
                answer += 1;
            }
            count[num] += 1;
        }
        
        return answer;
    }
};