class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // Step 0: numbers <= n are the same as numbers < n + 1
        n += 1;
        
        // Step 1: compute prefix count
        vector<int> prefCount(10, 0);
        for(string digitStr: digits){
            prefCount[digitStr[0] - '0'] += 1;
        }
        
        for(int digit = 1; digit <= 9; ++digit){
            prefCount[digit] += prefCount[digit - 1];
        }
        
        // Step 2: convert n to nStr
        string nStr = to_string(n);
        reverse(nStr.begin(), nStr.end());
        
        // Step 3: compute how many numbers of length i can be generated with given digits, where i < nStr.length()
        //         digits.size() ^ 1 + digits.size() ^ 2 + ... + digits.size() ^ (nStr.length() - 1)
        int answer = 0;
        for(int i = 1; i < nStr.length(); ++i){
            answer += pow(digits.size(), i);
        }
        
        // Step 3: compute how many numbers of length nStr.length() and values less than nStr can be generated with given digits
        for(int i = (int)nStr.length() - 1; i >= 0; --i){
            int digit = nStr[i] - '0';
            if(digit >= 1){
                answer += prefCount[digit - 1] * pow(digits.size(), i);
            }
            if(find(digits.begin(), digits.end(), nStr.substr(i, 1)) == digits.end()){
                break;
            }
        }
        
        return answer;
    }
};