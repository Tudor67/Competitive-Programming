class Solution {
private:
    bool areAnagrams(const vector<int>& COUNT1, const vector<int>& COUNT2, const char& MIN_CHAR, const char& MAX_CHAR){
        for(char c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(COUNT1[c] != COUNT2[c]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        const int N = s.length();
        const int M = p.length();
        const char MIN_CHAR = 'a';
        const char MAX_CHAR = 'z';
        
        vector<int> pCount(MAX_CHAR + 1);
        for(char c: p){
            pCount[c] += 1;
        }
        
        vector<int> answer;
        vector<int> wCount(MAX_CHAR + 1);
        for(int i = 0; i < N; ++i){
            wCount[s[i]] += 1;
            if(i >= M){
                wCount[s[i - M]] -= 1;
            }
            if(i >= M - 1){
                if(areAnagrams(wCount, pCount, MIN_CHAR, MAX_CHAR)){
                    answer.push_back(i - M + 1);
                }
            }
        }
        
        return answer;
    }
};