class Solution {
private:
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        a %= MODULO;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            n >>= 1;
            a = (a * a) % MODULO;
        }
        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MODULO = 1'000'000'007;

        // Step 1: compute scores
        vector<int> distinctPrimes(MAX_NUM + 1);
        for(int i = 2; i <= MAX_NUM; ++i){
            if(distinctPrimes[i] == 0){
                distinctPrimes[i] = 1;
                for(int j = i + i; j <= MAX_NUM; j += i){
                    distinctPrimes[j] += 1;
                }
            }
        }

        vector<int> scores(N);
        for(int i = 0; i < N; ++i){
            scores[i] = distinctPrimes[nums[i]];
        }

        // Step 2: compute prevGreaterOrEqual and nextGreater for scores using monostacks
        stack<int> st;
        vector<int> nextGreater(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && scores[st.top()] < scores[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> prevGreaterOrEqual(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && scores[i] >= scores[st.top()]){
                prevGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 3: counting
        vector<long long> distinctSubarrays(MAX_NUM + 1);
        for(int i = 0; i < N; ++i){
            long long lSize = i - prevGreaterOrEqual[i];
            long long rSize = nextGreater[i] - i;
            distinctSubarrays[nums[i]] += (lSize * rSize);
        }

        long long res = 1;
        for(int num = MAX_NUM; num >= 1; --num){
            long long take = min((long long)k, distinctSubarrays[num]);
            res *= fastPow(num, take, MODULO) % MODULO;
            res %= MODULO;
            k -= take;
        }

        return res;
    }
};