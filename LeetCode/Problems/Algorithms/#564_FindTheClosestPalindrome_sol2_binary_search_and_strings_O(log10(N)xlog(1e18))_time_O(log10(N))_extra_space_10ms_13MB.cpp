class Solution {
private:
    long long mirrorFirstHalf(long long num){
        string s = to_string(num);
        copy(s.begin(), s.end(), s.rbegin());
        return stoll(s);
    }

    long long prevPalindrome(long long num){
        long long l = 0;
        long long r = num;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(mirrorFirstHalf(mid) < num){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return mirrorFirstHalf(r);
    }

    long long nextPalindrome(long long num){
        long long l = num;
        long long r = 1e18;
        while(l != r){
            long long mid = (l + r) / 2;
            if(mirrorFirstHalf(mid) <= num){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return mirrorFirstHalf(r);
    }

public:
    string nearestPalindromic(string numStr) {
        long long num = stoll(numStr);
        long long a = prevPalindrome(num);
        long long b = nextPalindrome(num);
        if(num - a <= b - num){
            return to_string(a);
        }
        return to_string(b);
    }
};