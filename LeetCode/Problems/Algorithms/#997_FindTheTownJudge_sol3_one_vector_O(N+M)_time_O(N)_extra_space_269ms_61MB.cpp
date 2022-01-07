class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // diff[i] = inDegree[i] - outDegree[i]
        vector<int> diff(n + 1);
        
        for(const vector<int>& T: trust){
            diff[T[1]] += 1;
            diff[T[0]] -= 1;
        }
        
        int townJudge = -1;
        for(int i = 1; i <= n; ++i){
            if(diff[i] == n - 1){
                townJudge = i;
                break;
            }
        }
        
        return townJudge;
    }
};