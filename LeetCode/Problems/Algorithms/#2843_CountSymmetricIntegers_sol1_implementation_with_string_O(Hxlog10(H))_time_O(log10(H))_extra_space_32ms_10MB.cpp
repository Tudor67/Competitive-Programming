class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; ++i){
            string s = to_string(i);
            const int L = s.length();
            if(L % 2 == 0 &&
               accumulate(s.begin(), s.begin() + L / 2, 0) ==
               accumulate(s.begin() + L / 2, s.end(), 0)){
                res += 1;
            }
        }
        return res;
    }
};