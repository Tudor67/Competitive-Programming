class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (m + n);
        int targetSum = totalSum - accumulate(rolls.begin(), rolls.end(), 0);

        if(targetSum < n || 6 * n < targetSum){
            return {};
        }

        vector<int> res(n, targetSum / n);
        int rem = targetSum % n;
        for(int i = 0; i < rem; ++i){
            res[i] += 1;
        }

        return res;
    }
};