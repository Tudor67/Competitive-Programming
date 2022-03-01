class Solution {
private:
    void nextNum(const string& S, int& i, const int& N, int& num){
        num = 0;
        while(i < N && S[i] != '.'){
            num = num * 10 + (S[i] - '0');
            ++i;
        }
        if(i < N){
            ++i;
        }
    }
    
public:
    int compareVersion(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        
        int i1 = 0;
        int i2 = 0;
        int num1 = 0;
        int num2 = 0;
        while(i1 < N1 || i2 < N2){
            nextNum(s1, i1, N1, num1);
            nextNum(s2, i2, N2, num2);
            if(num1 < num2){
                return -1;
            }else if(num1 > num2){
                return 1;
            }
        }
        
        return 0;
    }
};