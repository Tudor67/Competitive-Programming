class Solution {
private:
    vector<int> getPrefMax(string s){
        const int N = s.length();
        
        // r[i]: max radius r[i] such that s[i - r[i] .. i + r[i]] is palindrome
        vector<int> r(N, 0);
        int x = 0;
        int y = 0;
        for(int i = 0; i < N; ++i){
            if(i <= y){
                r[i] = min(r[x + y - i], y - i);
            }
            while(0 <= i - r[i] - 1 && i + r[i] + 1 < N && s[i - r[i] - 1] == s[i + r[i] + 1]){
                r[i] += 1;
            }
            if(i + r[i] > y){
                x = i - r[i];
                y = i + r[i];
            }
        }
        
        // maxLen[i]: length of the longest odd palindrome that ends at index i
        vector<int> maxLen(N, 1);
        for(int i = 1; i < N; ++i){
            maxLen[i + r[i]] = max(maxLen[i + r[i]], 2 * r[i] + 1);
        }
        
        for(int i = N - 2; i >= 0; --i){
            maxLen[i] = max(maxLen[i], maxLen[i + 1] - 2);
        }
        
        // prefMax[i]: length of the longest odd palindrome in s[0 .. i]
        vector<int> prefMax(N, 1);
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], maxLen[i]);
        }
        
        return prefMax;
    }
    
public:
    long long maxProduct(string s) {
        const int N = s.length();
        
        // prefMax[i]: length of the longest odd palindrome in s[0 .. i]
        vector<int> prefMax = getPrefMax(s);
        
        // suffMax[i]: length of the longest odd palindrome in s[i .. N - 1]
        vector<int> suffMax = getPrefMax(string(s.rbegin(), s.rend()));
        reverse(suffMax.begin(), suffMax.end());
        
        long long maxProd = 1;
        for(int i = 0; i + 1 < N; ++i){
            long long prod = prefMax[i] * 1LL * suffMax[i + 1];
            maxProd = max(maxProd, prod);
        }
        
        return maxProd;
    }
};