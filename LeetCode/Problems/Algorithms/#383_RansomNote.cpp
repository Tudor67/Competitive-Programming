class Solution {
private:
    vector<int> get_char_cnt(const string& s){
        vector<int> cnt(26, 0);
        for(char c: s){
            ++cnt[c - 'a'];
        }
        return cnt;
    }
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransom_cnt = get_char_cnt(ransomNote);
        vector<int> magazine_cnt = get_char_cnt(magazine);
        for(int i = 0; i < 26; ++i){
            if(ransom_cnt[i] > magazine_cnt[i]){
                return false;
            }
        }
        return true;
    }
};