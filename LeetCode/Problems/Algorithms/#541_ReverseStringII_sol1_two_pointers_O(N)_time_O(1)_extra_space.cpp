class Solution {
private:
    void reverse(string& s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    
public:
    string reverseStr(string s, int k) {
        const int N = s.length();
        for(int i = 0; i < N; i += 2 * k){
            reverse(s, i, min(i + k, N) - 1);
        }
        return s;
    }
};