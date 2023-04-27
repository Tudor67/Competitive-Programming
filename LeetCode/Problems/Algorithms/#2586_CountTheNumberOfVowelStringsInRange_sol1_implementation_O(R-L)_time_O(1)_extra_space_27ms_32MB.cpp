class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for(int i = left; i <= right; ++i){
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                res += 1;
            }
        }
        return res;
    }
};