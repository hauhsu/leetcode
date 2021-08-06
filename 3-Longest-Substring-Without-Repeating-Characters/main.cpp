#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
        vector<int> last_appearance(256, -1);
        int maxLen = 0, start_idx = 0;
        for (int i = 0; i != s.length(); i++) {
            char c = s[i];
            if (last_appearance[c] >= start_idx) {
                // if last apperrance is in current examing substring
                // start from the next char of last appearance
                start_idx = last_appearance[c] + 1;
            }
            last_appearance[c] = i;
            maxLen = max(maxLen, i - start_idx + 1);
        }
        return maxLen;
    }
};

int main()
{
  auto sol = Solution();
  cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << sol.lengthOfLongestSubstring("aaaaa") << endl;
  cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
  cout << sol.lengthOfLongestSubstring("") << endl;
  return 0;
}
