class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         if (words.empty() || s.empty()) return {};
    
    int word_len = words[0].size();            // Length of each word
    int num_words = words.size();             // Number of words
    int concat_len = word_len * num_words;    // Total length of concatenated substring
    unordered_map<string, int> word_count;    // Map to store frequency of words

    // Populate word frequency map
    for (const string& word : words) {
        word_count[word]++;
    }

    vector<int> result;

    // Loop through each possible starting index in the first `word_len` range
    for (int i = 0; i < word_len; i++) {
        int left = i;                         // Start of the sliding window
        int right = i;                        // End of the sliding window
        unordered_map<string, int> current_count;  // Map to count words in the current window

        while (right + word_len <= s.size()) {
            string word = s.substr(right, word_len); // Extract the word from `s`
            right += word_len;

            if (word_count.find(word) != word_count.end()) { // Word exists in `words`
                current_count[word]++;

                // If a word's count exceeds the allowed frequency, shrink the window
                while (current_count[word] > word_count[word]) {
                    string left_word = s.substr(left, word_len);
                    current_count[left_word]--;
                    left += word_len;
                }

                // If the window size matches the concatenated length, it's a valid start
                if (right - left == concat_len) {
                    result.push_back(left);
                }
            } else {
                // Reset the window if an invalid word is found
                current_count.clear();
                left = right;
            }
        }
    }

    return result;
    }
};