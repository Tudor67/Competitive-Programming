class Solution {
private:
    bool isPossible(string& s, int pos, int targetVisMask){
        const int N = s.length();
        
        int visMask = 0;
        while(pos < N){
            visMask |= (1 << (s[pos] - 'a'));
            pos += 1;
        }
        
        for(char c = 'a'; c <= 'z'; ++c){
            if((targetVisMask & (1 << (c - 'a'))) && !((visMask & (1 << (c - 'a'))))){
                return false;
            }
        }
        
        return true;
    }
    
public:
    string removeDuplicateLetters(string s) {
        int targetVisMask = 0;
        for(char c: s){
            targetVisMask |= (1 << (c - 'a'));
        }
        
        const int UNIQUE_CHARS = __builtin_popcount((unsigned int)targetVisMask);
        string res(UNIQUE_CHARS, '.');
        int minPos = 0;
        for(int i = 0; i < UNIQUE_CHARS; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(!(targetVisMask & (1 << (c - 'a')))){
                    continue;
                }
                size_t pos = s.find(c, minPos);
                if(pos != string::npos && isPossible(s, pos, targetVisMask)){
                    res[i] = c;
                    targetVisMask -= (1 << (c - 'a'));
                    minPos = pos + 1;
                    break;
                }
            }
        }
        
        return res;
    }
};