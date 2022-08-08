class Solution {
public:
    int fillCups(vector<int>& amount) {
        vector<int> v = amount;
        sort(v.begin(), v.end());
        
        int res = 0;
        if(v[0] + v[1] <= v[2]){
            res = v[2];
        }else{
            res = v[2] + (v[0] + v[1] - v[2] + 1) / 2;
        }
        
        return res;
    }
};