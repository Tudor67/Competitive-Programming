class Solution {
private:
    unordered_map<string, vector<char>> candidates;
    
    void back(int level, string s, string nextS, int pos, bool& isValid){
        if(level == 0){
            isValid = true;
        }
        
        if(isValid){
            return;
        }
        
        if(pos == nextS.length()){
            back(level - 1, nextS, string((int)nextS.length() - 1, '#'), 0, isValid);
            return;
        }
        
        const int N = s.length();
        for(int i = pos; i < N - 1; ++i){
            string currentPair = s.substr(i, 2);
            if(candidates[currentPair].empty()){
                return;
            }
            for(char candidate: candidates[currentPair]){
                nextS[i] = candidate;
                back(level, s, nextS, i + 1, isValid);
            }
        }
    }
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        candidates.clear();
        for(const string& T: allowed){
            candidates[T.substr(0, 2)].push_back(T[2]);
        }
        
        bool isValid = false;
        const int N = bottom.length();
        string s = bottom;
        string nextS(N - 1, '#');
        back(N - 1, s, nextS, 0, isValid);
        
        return isValid;
    }
};