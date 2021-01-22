class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        int answer = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            if(count.count(k - num)){
                answer += min(count[num], count[k - num]);
            }
        }
        return answer / 2;
    }
};