class Solution {
private:
    void zAlgorithm(const string& A, const string& B, vector<int>& z){
        const int A_LEN = A.length();
        const int B_LEN = B.length();

        const string S = A + "$" + B;
        const int N = S.length();

        z.resize(N);
        fill(z.begin(), z.end(), 0);
        
        int l = 0;
        int r = 0;
        for(int i = 1; i < N; ++i){
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while(i + z[i] < N && S[z[i]] == S[i + z[i]]){
                ++z[i];
            }
            if(r < i + z[i] - 1){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

public:
    string minimumString(string a, string b, string c) {
        string res = a + b + c;

        vector<string> v = {a, b, c};

        vector<int> p(3);
        iota(p.begin(), p.end(), 0);
        do{
            a = v[p[0]];
            b = v[p[1]];
            c = v[p[2]];

            // Step 1: initialize string s with string a
            //         if b is not a substring of s then:
            //            concatenate string s with the shortest suffix of b
            //            such that the resulting string s contains a suffix equal to b
            string s = a;
            vector<int> z;
            zAlgorithm(b, s, z);
            if(*max_element(z.begin(), z.end()) < b.length()){
                for(int i = 0; i <= (int)z.size(); ++i){
                    if(i == (int)z.size() || i + z[i] == (int)z.size()){
                        int len = (i == (int)z.size() ? 0 : z[i]);
                        s += b.substr(len);
                        break;
                    }
                }
            }

            // Step 2: use string s from Step 1
            //         if c is not a substring of s then:
            //            concatenate it with the shortest suffix of c
            //            such that the resulting string s contains a suffix equal to c
            zAlgorithm(c, s, z);
            if(*max_element(z.begin(), z.end()) < c.length()){
                for(int i = 0; i <= (int)z.size(); ++i){
                    if(i == (int)z.size() || i + z[i] == (int)z.size()){
                        int len = (i == (int)z.size() ? 0 : z[i]);
                        s += c.substr(len);
                        break;
                    }
                }
            }

            // Step 3: update the result if s is lexicographically smaller than res
            if(s.size() < res.size() || (s.size() == res.size() && s < res)){
                res = s;
            }
        }while(next_permutation(p.begin(), p.end()));

        return res;
    }
};