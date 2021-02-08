class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        int answer = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            if(count.count(num + 1)){
                int nextNum = num + 1;
                int nextNumCount = count[nextNum];
                answer = max(numCount + nextNumCount, answer);
            }
        }
        
        return answer;
    }
};