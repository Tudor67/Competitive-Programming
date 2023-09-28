class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int N = s.length();

        vector<int> prefMask(N);
        prefMask[0] = 1 << (s[0] - 'a');
        for(int i = 1; i < N; ++i){
            prefMask[i] = prefMask[i - 1] | (1 << (s[i] - 'a'));
        }

        vector<int> suffMask(N);
        suffMask[N - 1] = 1 << (s[N - 1] - 'a');
        for(int i = N - 2; i >= 0; --i){
            suffMask[i] = (1 << (s[i] - 'a')) | suffMask[i + 1];
        }

        int uniqueChars = 0;
        for(int mask = prefMask[N - 1]; mask > 0; mask &= mask - 1){
            uniqueChars += 1;
        }

        string res(uniqueChars, '.');
        int visMask = 0;
        int startIndex = 0;

        for(int resIndex = 0; resIndex < uniqueChars; ++resIndex){
            char minValidChar = 'z' + 1;

            for(int i = startIndex; i < N; ++i){
                if(((visMask >> (s[i] - 'a')) & 1) == 0){
                    if((prefMask[i] & ~visMask & ~suffMask[i]) == 0){
                        if(minValidChar > s[i]){
                            minValidChar = s[i];
                            startIndex = i + 1;
                        }
                    }
                }
            }

            res[resIndex] = minValidChar;
            visMask |= (1 << (minValidChar - 'a'));
        }

        return res;
    }
};