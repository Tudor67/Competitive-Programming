class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>> v(4, vector<int>(2));
        for(int i = 0; i < arr1.size(); ++i){
            for(int mask = 0; mask < 4; ++mask){
                int sign1 = (mask & 1 ? 1 : -1);
                int sign2 = ((mask >> 1) & 1 ? 1 : -1);
                int val = arr1[i] + sign1 * arr2[i] + sign2 * i;
                if(i == 0){
                    v[mask][0] = val;
                    v[mask][1] = val;
                }else{
                    v[mask][0] = min(val, v[mask][0]);
                    v[mask][1] = max(val, v[mask][1]);
                }
            }
        }
        
        int answer = 0;
        for(int mask = 0; mask < 4; ++mask){
            answer = max(v[mask][1] - v[mask][0], answer);
        }
        
        return answer;
    }
};