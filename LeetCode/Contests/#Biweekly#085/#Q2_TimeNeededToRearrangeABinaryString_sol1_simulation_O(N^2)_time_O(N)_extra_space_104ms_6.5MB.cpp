class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        const int N = s.length();
        
        for(int step = 1; step <= N; ++step){
            int i = 1;
            bool updated = false;
            while(i < N){
                if(s[i - 1] == '0' && s[i] == '1'){
                    s[i - 1] = '1';
                    s[i] = '0';
                    i += 2;
                    updated = true;
                }else{
                    i += 1;
                }
            }
            if(!updated){
                return step - 1;
            }
        }
        
        return -1;
    }
};