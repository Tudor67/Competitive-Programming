class Solution {
private:
    int solve(const vector<int>& V, int k){
        map<int, int> count;
        for(int num: V){
            count[num] += 1;
        }

        // dp0: number of beautiful subsets excluding the current num
        // dp1: number of beautiful subsets including the current num
        int dp0 = 1;
        int dp1 = 0;
        int prevNum = count.begin()->first;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;

            int newDp0 = 0;
            int newDp1 = 0;
            if(prevNum + k == num){
                newDp0 = dp0 + dp1;
                newDp1 = dp0 * ((1 << numCount) - 1);
            }else{
                newDp0 = dp0 + dp1;
                newDp1 = (dp0 + dp1) * ((1 << numCount) - 1);
            }

            dp0 = newDp0;
            dp1 = newDp1;
            prevNum = num;
        }

        return dp0 + dp1;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, vector<int>> groups;
        for(int num: nums){
            groups[num % k].push_back(num);
        }

        int res = 1;
        for(const pair<int, vector<int>>& P: groups){
            res *= solve(P.second, k);
        }

        return res - 1;
    }
};