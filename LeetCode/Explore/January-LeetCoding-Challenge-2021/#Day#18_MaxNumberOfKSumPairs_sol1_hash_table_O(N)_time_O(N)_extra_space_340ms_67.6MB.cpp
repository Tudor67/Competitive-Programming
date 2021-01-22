class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        int answer = 0;
        for(int num: nums){
            if(count[num] > 0){
                count[num] -= 1;
                if(count.count(k - num) && count[k - num] > 0){
                    answer += 1;
                    count[k - num] -= 1;
                }
            }
        }
        return answer;
    }
};