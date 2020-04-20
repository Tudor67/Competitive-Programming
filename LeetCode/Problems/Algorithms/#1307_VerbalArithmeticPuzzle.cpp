class Solution {
private:
    vector<string> words;
    string result;
    vector<vector<char>> unvis_distinct_chars;
    int distinct_chars_cnt;
    int max_level;
    vector<int> min_digit_for;
    vector<int> digit_for;
    vector<bool> vis_digit;
    bool is_solvable;
    
    void reverse_words(vector<string>& words){
        for(string& word: words){
            reverse(word.begin(), word.end());
        }
    }
    
    int get_left_max_level(){
        int max_level = -1;
        for(string& word: words){
            max_level = max((int)word.length(), max_level);
        }
        return max_level;
    }
    
    void create_unvis_distinct_chars(){
        vector<bool> vis(26, 0);
        max_level = max(get_left_max_level(), (int)result.length());
        distinct_chars_cnt = 0;
        unvis_distinct_chars.clear();
        unvis_distinct_chars.resize(max_level);
        
        for(int level = 0; level < max_level; ++level){
            for(string& word: words){
                if(level < word.length()){
                    char c = word[level];
                    if(!vis[c - 'A']){
                        unvis_distinct_chars[level].push_back(c);
                        vis[c - 'A'] = 1;
                        ++distinct_chars_cnt;
                    }
                }
            }
            
            if(level < result.length()){
                char c = result[level];
                if(!vis[c - 'A']){
                    unvis_distinct_chars[level].push_back(c);
                    vis[c - 'A'] = 1;
                    ++distinct_chars_cnt;
                }
            }
        }
    }
    
    void update_min_digit_for_each_char(){
        fill(min_digit_for.begin(), min_digit_for.end(), 0);
        for(string& word: words){
            min_digit_for[word.back() - 'A'] = 1;
        }
        min_digit_for[result.back() - 'A'] = 1;
    }
    
    int get_level_sum(int level){
        int level_sum = 0;
        for(string& word: words){
            if(level < word.length()){
                level_sum += digit_for[word[level] - 'A'];
            }
        }
        return level_sum;
    }
    
    void back(int level, int level_cnt, int total_cnt, int carry){
        if(is_solvable){
            return;
        }else if(total_cnt == distinct_chars_cnt){
            bool ok = 1;
            while(ok && level < max_level){
                int level_sum = get_level_sum(level);
                int expected_digit = (level < result.length() ? digit_for[result[level] - 'A'] : 0);
                if((carry + level_sum) % 10 == expected_digit){
                    carry = (carry + level_sum) / 10;
                    ++level;
                }else{
                    ok = 0;
                }
            }
            is_solvable |= (ok && (carry == 0));
        }else if(level < max_level && unvis_distinct_chars[level].empty()){
            int level_sum = get_level_sum(level);
            if(level < result.length() && (carry + level_sum) % 10 == digit_for[result[level] - 'A']){
                back(level + 1, 0, total_cnt, (carry + level_sum) / 10);
            }
        }else if(level < max_level){
            for(int i = level_cnt; i < (int)unvis_distinct_chars[level].size(); ++i){
                char c = unvis_distinct_chars[level][i];
                for(int digit = min_digit_for[c - 'A']; digit < 10; ++digit){
                    if(!vis_digit[digit]){
                        vis_digit[digit] = 1;
                        digit_for[c - 'A'] = digit;
                        
                        if(c != unvis_distinct_chars[level].back()){
                            back(level, level_cnt + 1, total_cnt + 1, carry);
                        }else{
                            int level_sum = get_level_sum(level);
                            if(level < result.length() && (carry + level_sum) % 10 == digit_for[result[level] - 'A']){
                                back(level + 1, 0, total_cnt + 1, (carry + level_sum) / 10);
                            }
                        }
                        
                        vis_digit[digit] = 0;
                    }
                }
            }
        }
    }

public:
    Solution(){
        min_digit_for.resize(26);
        digit_for.resize(26);
        vis_digit.resize(10);
    }
    
    bool isSolvable(vector<string>& words, string result) {
        // reverse words and result
        reverse_words(words);
        reverse(result.begin(), result.end());
        
        // initialization
        this->words = words;
        this->result = result;
        fill(digit_for.begin(), digit_for.end(), 0);
        fill(vis_digit.begin(), vis_digit.end(), 0);
        
        create_unvis_distinct_chars();
        update_min_digit_for_each_char();
        
        // solution
        is_solvable = 0;
        int left_max_level = get_left_max_level();
        if(left_max_level == result.length() || left_max_level + 1 == result.length()){
            back(0, 0, 0, 0);
        }
        
        reverse_words(words);
        return is_solvable;
    }
};