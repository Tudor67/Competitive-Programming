class Solution {
public:
    int firstUniqChar(string s) {
        const int N = s.length();
        const int A = 26;

        queue<int> q;
        vector<int> freq(A);
        for(int i = 0; i < N; ++i){
            freq[s[i] - 'a'] += 1;
            if(freq[s[i] - 'a'] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(freq[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};