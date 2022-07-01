class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        const int N = s.length();
        const int MIN_CHAR = 'a';
        const int MAX_CHAR = 'z';
        
        vector<int> count(MAX_CHAR + 1);
        for(char c: s){
            count[c] += 1;
        }
        
        string chars;
        for(int c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(count[c] >= 1){
                chars += c;
            }
        }
        
        string res;
        int consecutive = 0;
        for(int step = 0; step < N; ++step){
            int i = (int)chars.length() - 1;
            if(!res.empty() && !chars.empty() && res.back() == chars.back() && consecutive == repeatLimit){
                i -= 1;
            }
            
            if(i >= 0){
                if(res.empty() || res.back() == chars[i]){
                    consecutive += 1;
                }else{
                    consecutive = 1;
                }
                res += chars[i];
                count[chars[i]] -= 1;
                if(count[chars[i]] == 0){
                    chars.erase(chars.begin() + i);
                    consecutive = 0;
                }
            }else{
                break;
            }
        }
        
        return res;
    }
};