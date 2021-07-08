class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        
        // Step 1: sort arr
        sort(arr.begin(), arr.end());
        
        // Step 2: compute frequencies of elements
        vector<int> freqs;
        int freq = 1;
        for(int i = 1; i <= N; ++i){
            if(i == N || arr[i - 1] != arr[i]){
                freqs.push_back(freq);
                freq = 1;
            }else{
                freq += 1;
            }
        }
        
        // Step 3: sort frequencies in non-increasing order
        sort(freqs.rbegin(), freqs.rend());
        
        // Step 4: greedily remove max frequencies until remElems <= N / 2
        int remElems = N;
        int i = 0;
        while(i < (int)freqs.size() && remElems > N / 2){
            remElems -= freqs[i];
            i += 1;
        }
        
        return i;
    }
};