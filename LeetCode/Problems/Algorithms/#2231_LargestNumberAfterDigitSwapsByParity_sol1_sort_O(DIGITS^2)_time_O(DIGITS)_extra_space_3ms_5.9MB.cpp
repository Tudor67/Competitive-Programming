class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        const int N = s.length();
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(s[i] % 2 == s[j] % 2){
                    if(s[i] < s[j]){
                        swap(s[i], s[j]);
                    }
                }
            }
        }
        
        return stoi(s);
    }
};