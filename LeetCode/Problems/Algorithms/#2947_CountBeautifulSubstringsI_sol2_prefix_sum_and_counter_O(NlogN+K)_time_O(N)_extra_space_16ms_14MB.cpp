class Solution {
private:
    bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(c) != string::npos);
    }
    
public:
    int beautifulSubstrings(string s, int k) {
        const int N = s.length();

        int minPeriod = k;
        for(int i = 1; i <= k; ++i){
            if((i * i) % k == 0){
                minPeriod = i;
                break;
            }
        }
        
        int res = 0;
        int prefBalance = 0;
        int prefVowels = 0;
        map<pair<int, int>, int> freq;
        freq[{0, 0}] = 1;

        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                prefBalance += 1;
                prefVowels += 1;
            }else{
                prefBalance -= 1;
            }
            res += freq[{prefBalance, prefVowels % minPeriod}];
            freq[{prefBalance, prefVowels % minPeriod}] += 1;
        }
        
        return res;
    }
};