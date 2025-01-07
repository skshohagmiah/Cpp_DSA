class Solution {
public:
    string reverseWords(string s) {
        // Resultant string
        string result;
        
        // Right trim the string
        int right = s.length() - 1;
        while (right >= 0 && s[right] == ' ') right--;
        
        // Process word by word from right to left
        int wordEnd = right;
        
        while (wordEnd >= 0) {
            // Skip spaces between words
            while (wordEnd >= 0 && s[wordEnd] == ' ') wordEnd--;
            if (wordEnd < 0) break;
            
            // Find the start of the word
            int wordStart = wordEnd;
            while (wordStart >= 0 && s[wordStart] != ' ') wordStart--;
            
            // Add space before adding new word (except for first word)
            if (!result.empty()) result += ' ';
            
            // Append the word to result
            result.append(s.substr(wordStart + 1, wordEnd - wordStart));
            
            // Move to the end of next word
            wordEnd = wordStart;
        }
        
        return result;
    }
};