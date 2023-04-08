class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        const int L = s.length();

        int a = 0;
        int b = 0;
        for(int i = 0; i < L; ++i){
            if(i % 2 == 0){
                a = a * 10 + (s[i] - '0');
            }else{
                b = b * 10 + (s[i] - '0');
            }
        }

        return a + b;
    }
};