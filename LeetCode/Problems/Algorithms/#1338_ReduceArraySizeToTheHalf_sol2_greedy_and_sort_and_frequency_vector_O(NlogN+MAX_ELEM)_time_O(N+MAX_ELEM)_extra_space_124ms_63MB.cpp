class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        
        // Step 1: compute frequency of each element
        vector<int> freqOf(MAX_ELEM + 1, 0);
        for(int elem: arr){
            freqOf[elem] += 1;
        }
        
        // Step 2: store frequencies in a vector and sort it in non-increasing order
        vector<int> freqs;
        for(int elem = 0; elem <= MAX_ELEM; ++elem){
            if(freqOf[elem] > 0){
                freqs.push_back(freqOf[elem]);
            }
        }
        
        sort(freqs.rbegin(), freqs.rend());
        
        // Step 3: greedily remove max frequencies until remElems <= N / 2
        int remElems = N;
        int i = 0;
        while(i < (int)freqs.size() && remElems > N / 2){
            remElems -= freqs[i];
            i += 1;
        }
        
        return i;
    }
};