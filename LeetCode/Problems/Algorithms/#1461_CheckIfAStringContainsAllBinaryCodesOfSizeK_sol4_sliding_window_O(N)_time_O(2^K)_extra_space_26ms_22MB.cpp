class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.length();

        if(N - k + 1 < (1 << k)){
            return false;
        }

        vector<bool> vis(1 << k, false);

        int num = 0;
        for(int i = 0; i < N; ++i){
            num = (num << 1) | (s[i] - '0');
            if(i >= k){
                num = num - (1 << k) * (s[i - k] - '0');
            }
            if(i >= k - 1){
                vis[num] = true;
            }
        }

        return (count(vis.begin(), vis.end(), true) == (1 << k));
    }
};