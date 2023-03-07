class Solution {
private:
    void zAlgorithm(const string& S, vector<int>& z){
        const int L = S.length();

        z.assign(L, 0);
        int l = 0;
        int r = 0;
        for(int i = 1; i < L; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < L && S[z[i]] == S[i + z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        string ps = needle + "$" + haystack;

        vector<int> z;
        zAlgorithm(ps, z);

        for(int i = (int)needle.length() + 1; i < (int)z.size(); ++i){
            if(z[i] == (int)needle.length()){
                return i - (int)needle.length() - 1;
            }
        }

        return -1;
    }
};