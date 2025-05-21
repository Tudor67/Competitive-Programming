class Solution {
private:
    int computeHammingDistance(const string& A, const string& B){
        if(A.length() != B.length()){
            return INT_MAX;
        }

        int distance = 0;
        for(int i = 0; i < (int)A.length(); ++i){
            distance += (int)(A[i] != B[i]);
        }

        return distance;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int N = words.size();

        // maxLen[i]: max length of a valid subsequence ending with words[i]
        vector<int> maxLen(N);
        vector<int> prev(N);

        for(int i = 0; i < N; ++i){
            maxLen[i] = 1;
            prev[i] = -1;
            for(int j = 0; j < i; ++j){
                if(groups[j] != groups[i] &&
                   maxLen[j] + 1 > maxLen[i] &&
                   computeHammingDistance(words[j], words[i]) == 1){
                    maxLen[i] = maxLen[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int i = max_element(maxLen.begin(), maxLen.end()) - maxLen.begin();
        vector<string> res(maxLen[i]);

        while(i >= 0){
            res[maxLen[i] - 1] = words[i];
            i = prev[i];
        }

        return res;
    }
};