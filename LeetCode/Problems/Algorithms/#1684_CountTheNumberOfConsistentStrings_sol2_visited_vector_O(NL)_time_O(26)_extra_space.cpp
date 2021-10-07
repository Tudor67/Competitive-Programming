class Solution {
private:
    int isValid(const string& WORD, const vector<bool>& vis){
        for(char c: WORD){
            if(!vis[c - 'a']){
                return false;
            }
        }
        return true;
    }
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> vis(26, false);
        for(char c: allowed){
            vis[c - 'a'] = true;
        }
        
        int count = 0;
        for(const string& WORD: words){
            if(isValid(WORD, vis)){
                count += 1;
            }
        }
        
        return count;
    }
};