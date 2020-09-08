class Solution {
public:
    bool wordPattern(string pattern, string str) {
        const int MAX_CHAR = 128;
        
        bool is_valid = true;
        vector<string> mp(MAX_CHAR);
        int word_idx = 0;
        for(int start_pos = 0; is_valid && start_pos < str.length(); ++start_pos){
            // find the end_pos of current word
            int end_pos = str.find(' ', start_pos);
            if(end_pos == string::npos){
                end_pos = str.length();
            }
            // check if the current word follows the pattern
            string word = str.substr(start_pos, end_pos - start_pos);
            if(mp[pattern[word_idx]].empty()){
                mp[pattern[word_idx]] = word;
            }else{
                is_valid &= (mp[pattern[word_idx]] == word);
            }
            // move to the next word
            word_idx += 1;
            start_pos = end_pos;
        }
        
        // check if mp['a'] != mp['b'] != mp['c'] != ... != mp['z']
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = c1 + 1; c2 <= 'z'; ++c2){
                if(!mp[c1].empty() && !mp[c2].empty() && mp[c1] == mp[c2]){
                    is_valid = false;
                }
            }
        }
        
        // check if the size of the pattern is equal to the number of words
        if(pattern.length() != word_idx){
            is_valid = false;
        }
        
        return is_valid;
    }
};