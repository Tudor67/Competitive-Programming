class Solution {
private:
    int countSubseq(string& subseq, string& s){
        int count = 0;
        int ptr = 0;
        for(char c: s){
            if(c == subseq[ptr]){
                ptr += 1;
            }
            if(ptr == (int)subseq.length()){
                count += 1;
                ptr = 0;
            }
        }
        return count;
    }

    void back(string& subseq, vector<int>& freqOf, string& s, int k, string& res){
        if(res.length() == s.length() / k){
            return;
        }
        if(res.length() < subseq.length()){
            res = subseq;
        }
        for(char c = 'z'; c >= 'a'; --c){
            if(freqOf[c - 'a'] < k){
                continue;
            }
            freqOf[c - 'a'] -= k;
            subseq.push_back(c);
            if(countSubseq(subseq, s) >= k){
                back(subseq, freqOf, s, k, res);
            }
            subseq.pop_back();
            freqOf[c - 'a'] += k;
        }
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        const int N = s.length();
        const int A = 26;

        vector<int> freqOf(A);
        for(char c: s){
            freqOf[c - 'a'] += 1;
        }

        string res;
        string subseq;
        back(subseq, freqOf, s, k, res);

        return res;
    }
};