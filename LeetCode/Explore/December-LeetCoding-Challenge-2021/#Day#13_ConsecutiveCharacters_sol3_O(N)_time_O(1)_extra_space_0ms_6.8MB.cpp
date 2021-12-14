class Solution {
public:
    int maxPower(string s) {
        const int N = s.length();
        
        int cons = 1;
        int maxCons = 1;
        for(int i = 1; i < N; ++i){
            if(s[i - 1] == s[i]){
                cons += 1;
                maxCons = max(maxCons, cons);
            }else{
                cons = 1;
            }
        }
        
        return maxCons;
    }
};