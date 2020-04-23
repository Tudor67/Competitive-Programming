class Solution {
public:
    static bool max_freq_min_order(const pair<int, string>& lhs, const pair<int, string>& rhs){
        if(lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)){
            return true;
        }
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: compute word - freq: ~O(NL), L - max length of the words
        unordered_map<string, int> word_freq;
        for(const string& word: words){
            ++word_freq[word];
        }
        
        // Step 2: compute freq - word: ~O(N)
        vector<pair<int, string>> freq_word;
        for(const pair<string, int>& p: word_freq){
            freq_word.push_back({p.second, p.first});
        }
        
        // Step 3: nth element to put the top k frequent words in range [0, k - 1]: ~O(N)
        nth_element(freq_word.begin(), freq_word.begin() + k, freq_word.end(), max_freq_min_order);
        
        // Step 4: sort the top k frequent words: ~O(KLlogK), L - max length of the words
        sort(freq_word.begin(), freq_word.begin() + k, max_freq_min_order);
        
        // Step 4: save solution
        vector<string> answer(k);
        for(int i = 0; i < k; ++i){
            answer[i] = freq_word[i].second;
        }
        
        return answer;
    }
};