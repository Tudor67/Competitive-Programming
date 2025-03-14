class Solution {
private:
    const string VOWELS = "aeiou";

    int countVowels(unordered_map<char, int>& freq){
        int totalVowels = 0;
        for(char vowel: VOWELS){
            totalVowels += freq[vowel];
        }
        return totalVowels;
    }

    bool containsAllVowels(unordered_map<char, int>& freq){
        for(char vowel: VOWELS){
            if(freq[vowel] == 0){
                return false;
            }
        }
        return true;
    }

    long long f(string& word, int k){
        const int N = word.length();

        // res = the number of substrings of word that contain
        //       every vowel at least once and more than k consonants
        long long res = 0;
        unordered_map<char, int> freq;

        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[word[r]] += 1;
            while(r - l + 1 - countVowels(freq) > k && containsAllVowels(freq)){
                freq[word[l]] -= 1;
                l += 1;
            }
            res += l;
        }

        return res;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return f(word, k - 1) - f(word, k);
    }
};