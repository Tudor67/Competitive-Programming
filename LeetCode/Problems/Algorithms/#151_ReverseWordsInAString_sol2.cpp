class Solution {
public:
    string reverseWords(string s) {
        // Step 1: reverse s
        for(int i = 0, j = (int)s.length() - 1; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
        
        // Step 2: split words and reverse each word
        s += " ";
        int last_pos = 0;
        int i = 0;
        int j = 0;
        
        while(true){
            for(; i < s.length() && s[i] == ' '; ++i);
            for(j = i; j < s.length() && s[j] != ' '; ++j);
            
            if(i == s.length()){
                break;
            }
            
            int word_len = (j - i);
            for(int k = last_pos; k < last_pos + word_len; ++k){
                s[k] = s[i + k - last_pos];
            }
            
            for(int k = last_pos; k < last_pos + word_len / 2; ++k){
                swap(s[k], s[last_pos + word_len - (k + 1 - last_pos)]);
            }
            
            last_pos += word_len;
            s[last_pos] = ' ';
            last_pos += 1;
            i = j;
        }
        
        // Step 3: remove trailing spaces
        s.resize(max(0, last_pos - 1));
        
        return s;
    }
};