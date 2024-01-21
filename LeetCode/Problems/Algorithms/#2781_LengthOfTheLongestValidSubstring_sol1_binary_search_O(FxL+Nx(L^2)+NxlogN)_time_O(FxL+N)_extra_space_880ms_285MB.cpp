class Solution {
private:
    bool isValid(vector<int>& minForbEnd, const int TARGET_LENGTH){
        const int N = minForbEnd.size();

        deque<int> dq;
        for(int i = 0; i < N; ++i){
            while(!dq.empty() && minForbEnd[dq.back()] >= minForbEnd[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            while(!dq.empty() && dq.front() <= i - TARGET_LENGTH){
                dq.pop_front();
            }
            if(i >= TARGET_LENGTH - 1){
                if(minForbEnd[dq.front()] > i){
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        const int N = word.length();
        const int F = forbidden.size();
        const int MAX_FORBIDDEN_LENGTH = 10;
        
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        vector<int> minForbEnd(N, N + 5);

        string s;
        for(int i = 0; i < N; ++i){
            s.clear();
            for(int len = 1; len <= MAX_FORBIDDEN_LENGTH && i + len - 1 < N; ++len){
                s.push_back(word[i + len - 1]);
                if(forbiddenSet.count(s)){
                    minForbEnd[i] = i + len - 1;
                    break;
                }
            }
        }

        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(minForbEnd, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};