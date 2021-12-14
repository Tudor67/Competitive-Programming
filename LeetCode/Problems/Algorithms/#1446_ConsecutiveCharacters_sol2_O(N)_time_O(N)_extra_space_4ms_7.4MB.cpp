class Solution {
public:
    int maxPower(string s) {
        const int N = s.length();
        
        vector<int> p(N);
        for(int i = 0; i < N; ++i){
            if(i > 0 && s[i - 1] == s[i]){
                p[i] = p[i - 1] + 1;
            }else{
                p[i] = 1;
            }
        }
        
        return *max_element(p.begin(), p.end());
    }
};