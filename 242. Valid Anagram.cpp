class Solution {
public:
    bool isAnagram(string s, string t) {
        // If sizes are not equal, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Use a single map to count character frequencies
        unordered_map<char, int> charCount;

        // Count characters in `s` and decrement for `t`
        for (int i = 0; i < s.size(); i++) {
            charCount[s[i]]++; // Increment count for `s[i]`
            charCount[t[i]]--; // Decrement count for `t[i]`
        }

        // Check if all counts are zero
        for (const auto& pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
