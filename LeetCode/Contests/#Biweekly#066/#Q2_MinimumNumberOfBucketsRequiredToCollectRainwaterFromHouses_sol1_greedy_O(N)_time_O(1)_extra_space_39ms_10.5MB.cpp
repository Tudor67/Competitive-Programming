class Solution {
public:
    int minimumBuckets(string s) {
        const int N = s.length();
        
        for(int i = 1; i + 1 < N; ++i){
            if(s[i - 1] == 'H' && s[i] == '.' && s[i + 1] == 'H'){
                s[i - 1] = '#';
                s[i] = 'B';
                s[i + 1] = '#';
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0 && s[i - 1] == 'H' && s[i] == '.'){
                s[i - 1] = '#';
                s[i] = 'B';
            }
            if(i + 1 < N && s[i] == '.' && s[i + 1] == 'H'){
                s[i] = 'B';
                s[i + 1] = '#';
            }
        }
        
        if(count(s.begin(), s.end(), 'H') >= 1){
            return -1;
        }
        
        return count(s.begin(), s.end(), 'B');
    }
};