class Solution {
public:
    int maximum69Number(int num) {
        vector<int> v;
        while(num > 0){
            v.push_back(num % 10);
            num /= 10;
        }
        
        reverse(v.begin(), v.end());
        
        for(int i = 0; i < (int)v.size(); ++i){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }
        
        int res = 0;
        for(int i = 0; i < (int)v.size(); ++i){
            res = res * 10 + v[i];
        }
        
        return res;
    }
};