class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start_s = 0; // Pointer for s
        int start_t = 0; // Pointer for t

        // If s is empty, it's always a subsequence
        if (s.empty()) return true;

        // Traverse t while looking for characters of s
        while (start_t < t.length()) {
            // If characters match, move pointer in s
            if (t[start_t] == s[start_s]) {
                start_s++;
                // If all characters of s are matched, return true
                if (start_s == s.length()) return true;
            }
            // Always move pointer in t
            start_t++;
        }

        // If we exit the loop and not all of s was matched
        return false;
    }
};
