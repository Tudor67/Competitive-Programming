class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> numCnt;
        for(int num: nums){
            numCnt[num] += 1;
        }
        
        int answer = 0;
        for(const pair<int, int>& P: numCnt){
            int num = P.first;
            int cnt = P.second;
            numCnt[num] -= 1;
            if(numCnt.count(num - k) && numCnt[num - k] > 0){
                answer += 1;
            }
            numCnt[num] += 1;
        }
        
        return answer;
    }
};