class Solution {
private:
    bool isValid(const string& S, vector<int>& count, const int& WINDOW_SIZE){
        const int N = S.length();
        
        fill(count.begin(), count.end(), 0);
        
        int duplicates = 0;
        for(int i = 0; i < N; ++i){
            count[S[i]] += 1;
            duplicates += (int)(count[S[i]] == 2);
            if(i >= WINDOW_SIZE){
                count[S[i - WINDOW_SIZE]] -= 1;
                duplicates -= (int)(count[S[i - WINDOW_SIZE]] == 1);
            }
            if(i >= WINDOW_SIZE - 1 && duplicates == 0){
                return true;
            }
        }
        
        return false;
    }
    
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.length();
        
        int l = 0;
        int r = min(128, N);
        vector<int> count(128);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(s, count, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};