class Solution {
public:
    string orderlyQueue(string s, int k) {
        string smallestS = s;
        if(k == 1){
            const int N = s.length();
            for(int i = 0; i < N; ++i){
                string currentS = s.substr(i) + s.substr(0, i);
                smallestS = min(smallestS, currentS);
            }
        }else{
            sort(smallestS.begin(), smallestS.end());
        }
        return smallestS;
    }
};