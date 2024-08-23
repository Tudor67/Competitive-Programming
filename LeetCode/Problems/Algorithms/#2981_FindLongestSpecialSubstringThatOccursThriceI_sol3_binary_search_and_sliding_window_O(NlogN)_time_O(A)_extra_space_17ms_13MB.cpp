class Solution {
private:
    bool isPossible(string& s, int len){
        const int N = s.length();

        unordered_map<char, int> freq;
        int i = 0;
        for(int j = 0; j < N; ++j){
            while(s[i] != s[j]){
                i += 1;
            }
            if(j - i + 1 >= len){
                freq[s[j]] += 1;
            }
            if(freq[s[j]] >= 3){
                return true;
            }
        }

        return false;
    }
    
public:
    int maximumLength(string s) {
        const int N = s.length();

        int l = 0;
        int r = N - 2;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(s, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        if(isPossible(s, r)){
            return r;
        }
        
        return -1;
    }
};