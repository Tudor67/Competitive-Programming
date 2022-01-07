class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1);
        vector<int> outDegree(n + 1);
        
        for(const vector<int>& T: trust){
            inDegree[T[1]] += 1;
            outDegree[T[0]] += 1;
        }
        
        int townJudge = -1;
        for(int i = 1; i <= n; ++i){
            if(inDegree[i] == n - 1 && outDegree[i] == 0){
                townJudge = i;
                break;
            }
        }
        
        return townJudge;
    }
};