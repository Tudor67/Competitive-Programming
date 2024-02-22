class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int N = s1.length();

        vector<pair<int, char>> v1(N);
        vector<pair<int, char>> v2(N);
        for(int i = 0; i < N; ++i){
            v1[i] = {i % 2, s1[i]};
            v2[i] = {i % 2, s2[i]};
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return (v1 == v2);
    }
};