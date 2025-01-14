class Solution {
public:
    string minWindow(string s, string t) {
          if (s.empty() || t.empty()) return "";

    unordered_map<char, int> t_count; // Frequency map for characters in t
    for (char c : t) {
        t_count[c]++;
    }

    unordered_map<char, int> window_count; // Frequency map for characters in current window
    int required = t_count.size();        // Number of unique characters in t
    int formed = 0;                       // Number of characters that meet the required frequency
    int left = 0, right = 0;              // Sliding window pointers
    int min_len = INT_MAX;                // Minimum length of valid substring
    int start_idx = 0;                    // Start index of the minimum window

    while (right < s.size()) {
        // Expand the window by adding the character at the right pointer
        char c = s[right];
        window_count[c]++;
        if (t_count.find(c) != t_count.end() && window_count[c] == t_count[c]) {
            formed++;
        }

        // Try to contract the window while it satisfies the condition
        while (left <= right && formed == required) {
            // Update the result if the current window is smaller
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }

            // Remove the character at the left pointer from the window
            char left_char = s[left];
            window_count[left_char]--;
            if (t_count.find(left_char) != t_count.end() && window_count[left_char] < t_count[left_char]) {
                formed--;
            }
            left++;
        }

        // Move the right pointer to expand the window
        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};