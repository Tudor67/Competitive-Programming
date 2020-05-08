class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> cnt(256, 0);
        for(char c: S){
            ++cnt[c];
        }
        
        int answer = 0;
        for(char c: J){
            answer += cnt[c];
        }
        
        return answer;
    }
};