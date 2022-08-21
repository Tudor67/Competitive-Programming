class Solution {
private:
    const char SPECIAL_CHAR = '*';
    
    bool isMatching(string& stamp, string& target, int startIdx){
        const int S_LEN = stamp.length();
        for(int i = 0; i < S_LEN; ++i){
            if(stamp[i] != target[startIdx + i] && target[startIdx + i] != SPECIAL_CHAR){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        const int S_LEN = stamp.length();
        const int T_LEN = target.length();
        
        vector<int> indices;
        
        bool updated = true;
        while(updated){
            updated = false;
            for(int i = 0; i + S_LEN - 1 < T_LEN; ++i){
                int specialChars = count(target.begin() + i, target.begin() + i + S_LEN, SPECIAL_CHAR);
                if(specialChars < S_LEN && isMatching(stamp, target, i)){
                    updated = true;
                    indices.push_back(i);
                    fill(target.begin() + i, target.begin() + i + S_LEN, SPECIAL_CHAR);
                }
            }
        }
        
        reverse(indices.begin(), indices.end());
        
        int specialChars = count(target.begin(), target.end(), SPECIAL_CHAR);
        if(specialChars != T_LEN){
            indices.clear();
        }
        
        return indices;
    }
};