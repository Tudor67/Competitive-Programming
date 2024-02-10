class Solution {
private:
    int countDistinctPrimeFactors(int x){
        int primeFactors = 0;
        for(int i = 2; i * i <= x; ++i){
            if(x % i == 0){
                primeFactors += 1;
                while(x % i == 0){
                    x /= i;
                }
            }
        }

        if(x > 1){
            primeFactors += 1;
        }
        
        return primeFactors;
    }
    
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        a %= MODULO;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }
    
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long MODULO = 1e9 + 7;
        
        // Step 1: compute prime scores for each nums[i]
        vector<int> primeScores(N);
        for(int i = 0; i < N; ++i){
            primeScores[i] = countDistinctPrimeFactors(nums[i]);
        }
        
        // Step 2: compute prevGreaterOrEqual[i]: previous closest index j
        //                                        with the property primeScores[j] >= primeScores[i]
        vector<int> prevGreaterOrEqual(N, -1);
        stack<int> st;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && primeScores[i] >= primeScores[st.top()]){
                prevGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // Step 3: compute nextGreater[i]: next index j
        //                                 with the property primeScores[i] < primeScores[j]
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> nextGreater(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && primeScores[st.top()] < primeScores[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 4: create vector v with pairs {nums[i], number of subarrays with the highest prime score at index i}
        //         number of subarrays with the highest prime score at index i: validStartPoints * validEndPoints
        vector<pair<int, long long>> v(N);
        for(int i = 0; i < N; ++i){
            long long l = i - prevGreaterOrEqual[i];
            long long r = nextGreater[i] - i;
            long long subarraysCount = l * r;
            v[i] = {nums[i], subarraysCount};
        }
        
        // Step 5: sort vector v in descending order of nums[i]
        sort(v.rbegin(), v.rend());
        
        // Step 6: to maximize the result => process vector v in descending order of nums[i]
        //         fix the element nums[i] and the correspondig subarrays (with the highest prime score at index i)
        //         update the result with the contribution of nums[i]:
        //             res = (res * (nums[i] ^ min(k, subarraysCount))) % MODULO;
        //             k = k - min(k, subarraysCount);
        long long res = 1;
        for(const pair<int, long long>& P: v){
            long long num = P.first;
            long long subarraysCount = P.second;
            
            long long maxValidOps = min((long long)k, subarraysCount);
            k -= maxValidOps;
            
            res *= fastPow(num, maxValidOps, MODULO);
            res %= MODULO;
        }
        
        return res;
    }
};