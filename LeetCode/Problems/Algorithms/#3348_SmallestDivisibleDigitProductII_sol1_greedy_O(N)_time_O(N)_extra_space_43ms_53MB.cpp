class Solution {
private:
    pair<bool, string> decompose(long long t, int targetLength){
        string s;
        s.reserve(targetLength);

        for(int digit = 9; digit >= 2; --digit){
            while(t % digit == 0 && s.length() < targetLength){
                s += char('0' + digit);
                t /= digit;
            }
        }
        
        s.resize(targetLength, '1');
        reverse(s.begin(), s.end());

        if(t == 1){
            return {true, s};
        }

        return {false, ""};
    }

public:
    string smallestNumber(string s, long long t) {
        const int N = s.length();
        const size_t POS_OF_FIRST_ZERO = s.find('0');

        long long temp = t;
        string tDecomposition;
        for(int digit = 9; digit >= 2; --digit){
            while(temp % digit == 0){
                tDecomposition += char('0' + digit);
                temp /= digit;
            }
        }

        reverse(tDecomposition.begin(), tDecomposition.end());

        // Case 1: t cannot be represented by any product of the digits [2 .. 9]
        if(temp > 1){
            return "-1";
        }

        // Case 2: min-length representation of t requires more than N digits
        if((int)tDecomposition.length() > N){
            return tDecomposition;
        }

        // suffixNeed[i]: factor of t not covered by s[0 .. i - 1]
        //                that s[i .. N - 1] still needs to cover
        vector<long long> suffixNeed(N + 1);
        suffixNeed[0] = t;
        for(int i = 1; i <= N; ++i){
            suffixNeed[i] = suffixNeed[i - 1] / gcd(suffixNeed[i - 1], s[i - 1] - '0');
        }

        // Case 3: s itself is valid
        if(suffixNeed[N] == 1 && POS_OF_FIRST_ZERO == string::npos){
            return s;
        }

        int startPos = (POS_OF_FIRST_ZERO == string::npos ? N - 1 : POS_OF_FIRST_ZERO);
        for(int i = startPos; i >= 0; --i){
            for(int digit = s[i] - '0' + 1; digit <= 9; ++digit){
                long long currSuffixNeed = suffixNeed[i] / gcd(suffixNeed[i], digit);
                auto [isPossible, suffix] = decompose(currSuffixNeed, N - 1 - i);
                if(isPossible){
                    // Case 4: increase s[i] and minimize the remaining suffix
                    return s.substr(0, i) + char('0' + digit) + suffix;
                }
            }
        }

        // Case 5: no valid N-digit number exists
        //         return the minimum (N + 1)-digit number
        return decompose(t, N + 1).second;
    }
};