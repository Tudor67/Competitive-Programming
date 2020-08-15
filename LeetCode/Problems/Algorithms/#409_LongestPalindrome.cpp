class Solution {
public:
    int longestPalindrome(string s) {
        const int FIRST_ELEM = 'A';
        const int LAST_ELEM = 'z';
        
        vector<int> cnt(LAST_ELEM + 1, 0);
        for(char c: s){
            cnt[c] += 1;
        }
        
        int even_sum = 0;
        int odd_cnt = 0;
        for(char c = FIRST_ELEM; c <= LAST_ELEM; ++c){
            even_sum += (cnt[c] - (cnt[c] % 2));
            odd_cnt += (cnt[c] % 2);
        }
        
        int answer = even_sum;
        if(odd_cnt > 0){
            answer += 1;
        }
        
        return answer;
    }
};