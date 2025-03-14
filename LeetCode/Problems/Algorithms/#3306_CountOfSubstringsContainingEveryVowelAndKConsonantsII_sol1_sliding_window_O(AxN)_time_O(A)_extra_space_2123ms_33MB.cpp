class Solution {
private:
    unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char letter){
        return (VOWELS.find(letter) != VOWELS.end());
    }

    bool isConsonant(char letter){
        return !isVowel(letter);
    }

    int countConsonants(unordered_map<char, int>& freq){
        int consonants = 0;
        for(auto& [letter, letterFreq]: freq){
            if(isConsonant(letter)){
                consonants += letterFreq;
            }
        }
        return consonants;
    }

    bool containsAllVowels(unordered_map<char, int>& freq){
        for(char letter: VOWELS){
            if(freq[letter] == 0){
                return false;
            }
        }
        return true;
    }

    long long f(string& word, int k){
        const int N = word.length();

        // res = the number of substrings of word that contain every vowel at least once
        //                                                     and more than k consonants
        long long res = 0;
        unordered_map<char, int> freq;

        bool foundValidWindow = false;
        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[word[r]] += 1;
            while(countConsonants(freq) > k && containsAllVowels(freq)){
                foundValidWindow = true;
                freq[word[l]] -= 1;
                l += 1;
            }
            if(foundValidWindow){
                res += l;
            }
        }

        return res;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return f(word, k - 1) - f(word, k);
    }
};