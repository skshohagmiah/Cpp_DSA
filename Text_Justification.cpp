class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            // Step 1: Calculate how many words fit in this line
            int lineLength = words[i].length();
            int j = i + 1;
            while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            // Step 2: Calculate spaces
            int spaces = maxWidth - lineLength;
            int numWords = j - i;
            
            // Step 3: Build the line
            string line;
            
            // Last line or single word: left justify
            if (j == words.size() || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            }
            // Middle lines: distribute spaces evenly
            else {
                int spacesBetweenWords = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);
                
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spacesToAdd = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spacesToAdd, ' ') + words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};