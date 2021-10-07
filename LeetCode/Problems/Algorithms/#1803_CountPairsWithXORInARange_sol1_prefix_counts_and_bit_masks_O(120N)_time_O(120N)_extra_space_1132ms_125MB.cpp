class Solution {
private:
    static const int MAX_BITS = 15;
    
    string binaryRepresentationAsString(int x){
        return bitset<MAX_BITS>(x).to_string();
    }
    
    int countPairsLessOrEqual(const string& NUM_STR, const string& MAX_STR, unordered_map<string, int>& prefixCount){
        const int LENGTH = NUM_STR.length();
        int count = 0;
        string prefix;
        for(int j = 0; j < LENGTH; ++j){
            prefix += '#';
            if(MAX_STR[j] == '1'){
                prefix[j] = NUM_STR[j];
                if(prefixCount.count(prefix)){
                    count += prefixCount[prefix];
                }
            }
            prefix[j] = char('0' + (NUM_STR[j] - '0') ^ (MAX_STR[j] - '0'));
        }
        if(prefixCount.count(prefix)){
            count += prefixCount[prefix];
        }
        return count;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        const int N = nums.size();
        
        const string HIGH_STR = binaryRepresentationAsString(high);
        const string LOW_STR = binaryRepresentationAsString(low - 1);
        
        int pairsCount = 0;
        unordered_map<string, int> prefixCount;
        for(int i = N - 1; i >= 0; --i){
            const string NUM_STR = binaryRepresentationAsString(nums[i]);
            
            pairsCount += countPairsLessOrEqual(NUM_STR, HIGH_STR, prefixCount);
            pairsCount -= countPairsLessOrEqual(NUM_STR, LOW_STR, prefixCount);
            
            string prefix;
            for(char c: NUM_STR){
                prefix += c;
                prefixCount[prefix] += 1;
            }
        }
        
        return pairsCount;
    }
};