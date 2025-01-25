class Solution {
public:
   bool isIsomorphic(string s, string t) {
    // If strings have different lengths, they can't be isomorphic
    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, char> mapS, mapT; // To store the character mappings
    
    // Iterate through both strings character by character
    for (int i = 0; i < s.length(); i++) {
        // If character in s is already mapped to a different character in t, it's invalid
        if (mapS.find(s[i]) != mapS.end() && mapS[s[i]] != t[i]) {
            return false;
        }
        
        // If character in t is already mapped to a different character in s, it's invalid
        if (mapT.find(t[i]) != mapT.end() && mapT[t[i]] != s[i]) {
            return false;
        }
        
        // Map character from s to t, and t to s
        mapS[s[i]] = t[i];
        mapT[t[i]] = s[i];
    }

    return true; // If no issues, the strings are isomorphic
}

int main() {
    string s = "egg";
    string t = "add";

    if (isIsomorphic(s, t)) {
        cout << "\"" << s << "\" and \"" << t << "\" are isomorphic.\n";
    } else {
        cout << "\"" << s << "\" and \"" << t << "\" are NOT isomorphic.\n";
    }

    return 0;
}
};