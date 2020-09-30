class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int N = s.size();
        
        int maxLength = 0;
        for(int i = 0, j = 0, cost = 0; j < N; ++j){
            cost += abs(s[j] - t[j]);
            
            if(cost <= maxCost){
                maxLength = max(j - i + 1, maxLength);
            }
            
            while(i <= j && cost > maxCost){
                cost -= abs(s[i] - t[i]);
                i += 1;
            }
        }
        
        return maxLength;
    }
};