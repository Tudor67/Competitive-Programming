class Solution {
public:
    int maximumLength(string s) {
        const int N = s.length();
        const int A = 26;

        vector<priority_queue<int, vector<int>, greater<int>>> minHeaps(A);

        int i = 0;
        while(i < N){
            int j = i;
            while(j < N && s[i] == s[j]){
                j += 1;
            }
            int len = j - i;
            minHeaps[s[i] - 'a'].push(len);
            if((int)minHeaps[s[i] - 'a'].size() > 3){
                minHeaps[s[i] - 'a'].pop();
            }
            i = j;
        }

        int maxLen = 0;
        for(int i = 0; i < A; ++i){
            vector<int> v(3);
            while(!minHeaps[i].empty()){
                v[3 - (int)minHeaps[i].size()] = minHeaps[i].top();
                minHeaps[i].pop();
            }

            if(v[0] == v[1] && v[1] == v[2]){
                maxLen = max(maxLen, v[2]);
            }
            if(v[1] + 1 >= v[2]){
                maxLen = max(maxLen, v[2] - 1);
            }
            maxLen = max(maxLen, v[2] - 2);
        }

        if(maxLen <= 0){
            maxLen = -1;
        }

        return maxLen;
    }
};