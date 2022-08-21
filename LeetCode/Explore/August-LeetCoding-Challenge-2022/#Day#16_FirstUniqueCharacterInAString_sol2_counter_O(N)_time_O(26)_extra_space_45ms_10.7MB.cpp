class Solution {
public:
    int firstUniqChar(string s) {
        const int N = s.length();
        
        vector<int> count(26);
        for(int i = 0; i < N; ++i){
            count[s[i] - 'a'] += 1;
        }
        
        for(int i = 0; i < N; ++i){
            if(count[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};