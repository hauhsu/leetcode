#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      auto len = s.length();
      auto maxLen = 1;
      auto maxIdx = 0;
      for (int i = 0; i < len-1; i++) {
        // abcba
        for (int j = 1; i-j >= 0 && i+j < len; j++) {
          if (s[i-j] == s[i+j]) {
            if (2*j+1 > maxLen) {
              maxLen = 2*j+1;
              maxIdx = i-j;
            }
          } else {
            break;
          }
        }
        // abba
        for (int j = 1; i-j+1 >= 0 && i+j < len; j++) {
          if (s[i-j+1] == s[i+j]) {
            if (2*j > maxLen) {
              maxLen = 2*j;
              maxIdx = i-j+1;
            }
          } else {
            break;
          }
        }
      }
      return s.substr(maxIdx, maxLen);
    }
};

int main(int argc, char *argv[])
{
  auto sol = Solution();
  cout << sol.longestPalindrome("babad") << endl;
  //"bb"
  cout << sol.longestPalindrome("bb") << endl;
  //"bb"
  cout << sol.longestPalindrome("cbbd") << endl;
  cout << sol.longestPalindrome("ac") << endl;
  
  //"lbabl"
  cout << sol.longestPalindrome("lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc") << endl;
  //"vbjbv"
  cout << sol.longestPalindrome("lejyqjcpluiggwlmnumqpxljlcwdsirzwlygexejhvojztcztectzrepsvwssiixfmpbzshpilmojehqyqpzdylxptsbvkgatzdlzphohntysrbrcdgeaiypmaaqilthipjbckkfbxtkreohabrjpmelxidlwdajmkndsdbbaypcemrwlhwbwaljacijjmsaqembgtdcskejplifnuztlmvasbqcyzmvczpkimpbbwxdtviptzaenkbddaauyvqppagvqfpednnckooxzcpuudckakutqyknuqrxjgfdtsxsoztjkqvfvelrklforpjnrbvyyvxigjhkjmxcphjzzilvbjbvwiwnnkbmboiqamgoimujtswdqesighoxsprhnsceshotakvmoxqkqjvbpqucvafiuqwmrlfjpjijbctfupywkbawquchbclgvhxbanybret") << endl;
  return 0;

}
