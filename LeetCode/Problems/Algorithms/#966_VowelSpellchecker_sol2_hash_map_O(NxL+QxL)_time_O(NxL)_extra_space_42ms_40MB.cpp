class Solution {
private:
    static bool isVowel(char c){
        static const string VOWELS = "aeiou";
        return (VOWELS.find(tolower(c)) != string::npos);
    }

    static string getLowerForm(string s){
        string lowerForm = s;
        for(char& c: lowerForm){
            c = tolower(c);
        }
        return lowerForm;
    }

    static string getVowelForm(string s){
        string vowelForm = s;
        for(char& c: vowelForm){
            c = tolower(c);
            if(isVowel(c)){
                c = '*';
            }
        }
        return vowelForm;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        const int N = wordlist.size();
        const int Q = queries.size();

        unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowerToOriginal;
        unordered_map<string, string> vowelToOriginal;

        for(string& word: wordlist){
            string lowerForm = getLowerForm(word);
            if(!lowerToOriginal.count(lowerForm)){
                lowerToOriginal[lowerForm] = word;
            }

            string vowelForm = getVowelForm(word);
            if(!vowelToOriginal.count(vowelForm)){
                vowelToOriginal[vowelForm] = word;
            }
        }

        vector<string> answer(Q);
        for(int i = 0; i < Q; ++i){
            string lowerForm = getLowerForm(queries[i]);
            string vowelForm = getVowelForm(queries[i]);
            if(wordSet.count(queries[i])){
                answer[i] = queries[i];
            }else if(lowerToOriginal.count(lowerForm)){
                answer[i] = lowerToOriginal[lowerForm];
            }else if(vowelToOriginal.count(vowelForm)){
                answer[i] = vowelToOriginal[vowelForm];
            }
        }

        return answer;
    }
};