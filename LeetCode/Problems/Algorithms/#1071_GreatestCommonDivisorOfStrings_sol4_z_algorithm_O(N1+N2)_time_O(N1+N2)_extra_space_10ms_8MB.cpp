class Solution {
private:
    void zAlgorithm(const string& S, vector<int>& z){
        const int N = S.length();

        int a = 0;
        int b = 0;
        z.assign(N, 0);
        for(int i = 1; i < N; ++i){
            if(i <= b){
                z[i] = min(z[i - a], b - i + 1);
            }
            while(i + z[i] < N && S[i + z[i]] == S[z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= b){
                a = i;
                b = i + z[i] - 1;
            }
        }
    }

public:
    string gcdOfStrings(string str1, string str2) {
        const int N1 = str1.length();
        const int N2 = str2.length();

        vector<int> z1;
        vector<int> z2;

        zAlgorithm(str1, z1); z1.push_back(0);
        zAlgorithm(str2, z2); z2.push_back(0);

        int maxLen = 0;
        for(int i = 1; i <= min(N1, N2) && (i == min(N1, N2) || str1[i] == str2[i]); ++i){
            if(N1 % i == 0 && N2 % i == 0){
                if(i + z1[i] == N1 && i + z2[i] == N2){
                    maxLen = i;
                }
            }
        }

        return str1.substr(0, maxLen);
    }
};