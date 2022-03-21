class Solution {
private:
    bool isPossible(string& s, int pos, vector<bool>& targetVis, vector<bool>& vis){
        const int N = s.length();
        
        fill(vis.begin(), vis.end(), false);
        
        while(pos < N){
            vis[s[pos] - 'a'] = true;
            pos += 1;
        }
        
        for(char c = 'a'; c <= 'z'; ++c){
            if(targetVis[c - 'a'] && !vis[c - 'a']){
                return false;
            }
        }
        
        return true;
    }
    
public:
    string removeDuplicateLetters(string s) {
        const int A = 26;
        
        vector<bool> targetVis(A, false);
        for(char c: s){
            targetVis[c - 'a'] = true;
        }
        
        const int UNIQUE_CHARS = count(targetVis.begin(), targetVis.end(), true);
        string res(UNIQUE_CHARS, '.');
        int minPos = 0;
        vector<bool> vis(A);
        for(int i = 0; i < UNIQUE_CHARS; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(!targetVis[c - 'a']){
                    continue;
                }
                size_t pos = s.find(c, minPos);
                if(pos != string::npos && isPossible(s, pos, targetVis, vis)){
                    res[i] = c;
                    targetVis[c - 'a'] = false;
                    minPos = pos + 1;
                    break;
                }
            }
        }
        
        return res;
    }
};