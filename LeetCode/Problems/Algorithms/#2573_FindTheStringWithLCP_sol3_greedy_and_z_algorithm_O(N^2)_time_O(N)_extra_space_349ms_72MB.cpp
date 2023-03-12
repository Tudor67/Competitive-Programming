class Solution {
private:
    bool satisfiesLCP(const string& PS, vector<int>& z, vector<int>& lcp){
        const int L = PS.length();

        z.resize(L);
        fill(z.begin(), z.end(), 0);

        int l = 0;
        int r = 0;
        for(int i = 1; i < L; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < L && PS[z[i]] == PS[i + z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= r){
                l = i;
                r = i + z[i] - 1;
            }
        }

        return equal(lcp.rbegin(), lcp.rend(), z.rbegin());
    }

public:
    string findTheString(vector<vector<int>>& lcp) {
        const int N = lcp.size();

        // Step 1: try to build the result s
        string s(N, '*');
        char currentChar = 'a';
        for(int i = 0; i < N; ++i){
            if(!isalpha(s[i])){
                s[i] = currentChar;
                currentChar += 1;
            }

            if(s[i] > 'z'){
                return "";
            }

            for(int j = 0; j < N; ++j){
                if(lcp[i][j] > 0){
                    s[j] = s[i];
                }
            }
        }

        // Step 2: check if the result s is valid (satisfies all lcp values)
        string ps = s + "$" + s;
        vector<int> z;

        for(int i = 0; i < N; ++i){
            if(!satisfiesLCP(ps, z, lcp[i])){
                return "";
            }
            ps.erase(ps.begin());
        }

        return s;
    }
};