class Solution {
public:
    string decodeCiphertext(string encodedText, int ROWS) {
        const int N = encodedText.length();
        const int COLS = N / ROWS;

        string originalText;
        originalText.reserve(N);

        for(int startCol = 0; startCol < COLS; ++startCol){
            for(int row = 0, col = startCol; row < ROWS && col < COLS; ++row, ++col){
                int index = row * COLS + col;
                originalText.push_back(encodedText[index]);
            }
        }

        while(!originalText.empty() && originalText.back() == ' '){
            originalText.pop_back();
        }

        return originalText;
    }
};