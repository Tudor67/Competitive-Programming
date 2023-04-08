class Solution {
private:
    long long stoll(string& s, int i, int j){
        long long num = 0;
        while(i <= j){
            num = num * 10 + (s[i] - '0');
            i += 1;
        }
        return num;
    }
    
public:
    int splitNum(int num) {
        long long res = num;
        
        string s = to_string(num);
        sort(s.begin(), s.end());
        const int L = s.length();
        
        do{
            for(int i = 0; i + 1 < L; ++i){
                long long a = stoll(s, 0, i);
                long long b = stoll(s, i + 1, L - 1);
                res = min(res, a + b);
            }
        }while(next_permutation(s.begin(), s.end()));

        return res;
    }
};