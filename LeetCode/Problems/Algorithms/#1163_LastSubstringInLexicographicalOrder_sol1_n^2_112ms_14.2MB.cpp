class Solution {
public:
    string lastSubstring(string s) {
        // Step 1: find non_overlapping substrings of type {max_elem, max_elem, ...,  max_elem} of max_length
        //         a substring is represented by {start_pos, end_pos}
        list<pair<int, int>> best_substrings;
        int last_end_pos = -1;
        int max_len = -1;
        char max_elem = *max_element(s.begin(), s.end());
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == max_elem && last_end_pos < i){
                int end_pos = i;
                while(end_pos + 1 < s.length() && s[end_pos + 1] == max_elem){
                    ++end_pos;
                }
                if(end_pos - i + 1 >= max_len){
                    if(end_pos - i + 1 > max_len){
                        max_len = end_pos - i + 1;
                        best_substrings.clear();
                    }
                    best_substrings.push_back({i, end_pos});
                    last_end_pos = end_pos;
                }
            }
        }
        
        // Step 2: repeat until a single best_substring remains
        while(best_substrings.size() >= 2){
            // find max_elem
            char max_elem = 0;
            for(const pair<int, int>& p: best_substrings){
                int end_pos = p.second;
                if(end_pos + 1 < s.length()){
                    max_elem = max(s[end_pos + 1], max_elem);
                }
            }
            
            // find substrings of form {max_elem, max_elem, ... , max_elem}
            // save the max_len of these substrings
            int max_len = -1;
            for(pair<int, int>& p: best_substrings){
                int start_pos = p.first;
                int end_pos = p.second;
                if(end_pos + 1 < s.length() && s[end_pos + 1] == max_elem){
                    end_pos = end_pos + 1;
                    while(end_pos + 1 < s.length() && s[end_pos + 1] == max_elem){
                        ++end_pos;
                    }
                    max_len = max(end_pos - start_pos + 1, max_len);
                    p.second = end_pos;
                }
            }
            
            // keep only substrings with max_len
            list<pair<int, int>>::iterator it = best_substrings.begin();
            while(it != best_substrings.end()){
                if(it->second - it->first + 1 == max_len){
                    ++it;
                }else{
                    it = best_substrings.erase(it);
                }
            }
        }
        
        int start_pos = best_substrings.begin()->first;
        return s.substr(start_pos);
    }
};