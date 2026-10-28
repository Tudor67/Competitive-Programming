class Solution {
public:
    int minOperations(string s) {
        const int MIN_CHAR = *min_element(s.begin(), s.end());
        const int MAX_CHAR = *max_element(s.begin(), s.end());

        if(is_sorted(s.begin(), s.end())){
            return 0;
        }

        if((int)s.length() == 2){
            return -1;
        }

        if((s.front() == MAX_CHAR && *min_element(s.begin(), s.end() - 1) != MIN_CHAR) &&
           (s.back() == MIN_CHAR && *max_element(s.begin() + 1, s.end()) != MAX_CHAR)){
            return 3;
        }

        if(s.front() != MIN_CHAR && s.back() != MAX_CHAR){
            return 2;
        }

        return 1;
    }
};