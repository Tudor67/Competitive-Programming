class Solution {
private:
    int countMostFreqSubstr(string& s, int substrTargetLen){
        int maxFreq = 0;
        unordered_map<char, int> charFreq;
        unordered_map<char, int> substrFreq;

        int l = 0;
        for(int r = 0; r < (int)s.length(); ++r){
            charFreq[s[r]] += 1;
            while((int)charFreq.size() >= 2){
                charFreq[s[l]] -= 1;
                if(charFreq[s[l]] == 0){
                    charFreq.erase(s[l]);
                }
                l += 1;
            }

            if(r - l + 1 >= substrTargetLen){
                substrFreq[s[r]] += 1;
                maxFreq = max(maxFreq, substrFreq[s[r]]);
            }
        }

        return maxFreq;
    }

public:
    int maximumLength(string s) {
        const int N = s.length();

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countMostFreqSubstr(s, mid) >= 3){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        if(countMostFreqSubstr(s, r) >= 3){
            return r;
        }

        return -1;
    }
};