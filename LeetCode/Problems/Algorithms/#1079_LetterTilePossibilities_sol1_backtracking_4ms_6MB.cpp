class Solution {
private:
    void back(int k, const int& n, vector<int>& cnt, const vector<int>& initial_cnt, int& ans){
        if(k < n){
            for(int i = 0; i < 26; ++i){
                if(cnt[i] > 0){
                    ++ans;
                    --cnt[i];
                    back(k + 1, n, cnt, initial_cnt, ans);
                    ++cnt[i];
                }
            }
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        vector<int> initial_cnt(26, 0);
        for(char c: tiles){
            ++initial_cnt[c - 'A'];
        }
        
        vector<int> cnt = initial_cnt;
        int n = tiles.length();
        int ans = 0;
        
        back(0, n, cnt, initial_cnt, ans);
        
        return ans;
    }
};