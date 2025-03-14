class Solution {
private:
    const int ALPHABET_SIZE = 26;
    const int FIRST_CHAR = 'a';
    const string VOWELS = "aeiou";

    int countVowels(vector<int>& freq){
        int totalVowels = 0;
        for(char vowel: VOWELS){
            totalVowels += freq[vowel - FIRST_CHAR];
        }
        return totalVowels;
    }

    bool containsAllVowels(vector<int>& freq){
        for(char vowel: VOWELS){
            if(freq[vowel - FIRST_CHAR] == 0){
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
        vector<int> freq(ALPHABET_SIZE);

        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[word[r] - FIRST_CHAR] += 1;
            while(r - l + 1 - countVowels(freq) > k && containsAllVowels(freq)){
                freq[word[l] - FIRST_CHAR] -= 1;
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