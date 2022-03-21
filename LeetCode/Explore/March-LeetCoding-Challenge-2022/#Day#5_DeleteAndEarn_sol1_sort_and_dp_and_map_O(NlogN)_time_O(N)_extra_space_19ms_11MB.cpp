class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> contrib;
        for(int num: nums){
            contrib[num] += num;
        }
        
        map<int, int> dp0;
        map<int, int> dp1;
        int prevNum = -1;
        int maxPoints = 0;
        for(const pair<int, int>& P: contrib){
            int num = P.first;
            if(prevNum == num - 1){
                dp0[num] = max(dp0[num - 1], dp1[num - 1]);
                dp1[num] = dp0[num - 1] + contrib[num];
            }else{
                dp0[num] = max(dp0[prevNum], dp1[prevNum]);
                dp1[num] = max(dp0[prevNum], dp1[prevNum]) + contrib[num];
            }
            prevNum = num;
            maxPoints = max(maxPoints, max(dp0[num], dp1[num]));
        }
        
        return maxPoints;
    }
};