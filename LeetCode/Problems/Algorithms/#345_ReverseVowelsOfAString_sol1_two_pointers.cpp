class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        
        for(int i = 0, j = (int)s.length() - 1; i < j;){
            if(vowels.count(s[i]) && vowels.count(s[j])){
                swap(s[i], s[j]);
                i += 1;
                j -= 1;
            }else{
                i += !vowels.count(s[i]);
                j -= !vowels.count(s[j]);
            }
        }
        
        return s;
    }
};