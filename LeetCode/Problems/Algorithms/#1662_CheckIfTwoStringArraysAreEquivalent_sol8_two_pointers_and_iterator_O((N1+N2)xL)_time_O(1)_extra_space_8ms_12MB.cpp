class CharIterator{
private:
    const vector<string>& WORDS;
    const int N;
    int i;
    int j;

public:
    CharIterator(const vector<string>& WORDS): WORDS(WORDS), N(WORDS.size()){
        i = 0;
        j = 0;
    }

    bool hasNext(){
        while(i < N && j >= (int)WORDS[i].length()){
            i += 1;
            j = 0;
        }
        return (i < N);
    }

    char next(){
        if(hasNext()){
            char c = WORDS[i][j];
            j += 1;
            return c;
        }
        return -1;
    }
};

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        CharIterator it1(word1);
        CharIterator it2(word2);

        while(it1.hasNext() && it2.hasNext()){
            if(it1.next() != it2.next()){
                return false;
            }
        }

        return !it1.hasNext() && !it2.hasNext();
    }
};