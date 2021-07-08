class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        
        // Step 1: compute frequency of each element
        vector<int> freqOfElem(MAX_ELEM + 1, 0);
        int maxFreqOfElem = 0;
        for(int elem: arr){
            freqOfElem[elem] += 1;
            maxFreqOfElem = max(freqOfElem[elem], maxFreqOfElem);
        }
        
        // Step 2: store frequencies of frequencies of elements in a vector
        vector<int> freqOfFreq(maxFreqOfElem + 1, 0);
        for(int elem = 0; elem <= MAX_ELEM; ++elem){
            if(freqOfElem[elem] > 0){
                freqOfFreq[freqOfElem[elem]] += 1;
            }
        }
        
        // Step 3: greedily remove max frequencies until remElems <= N / 2
        int remElems = N;
        int minOperations = 0;
        for(int freq = maxFreqOfElem; freq >= 1; --freq){
            while(freqOfFreq[freq] > 0 && remElems > N / 2){
                remElems -= freq;
                freqOfFreq[freq] -= 1;
                minOperations += 1;
            }
        }
        
        return minOperations;
    }
};