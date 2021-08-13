#include "../all.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (auto &c: s) {
            char expect = '\0';
            switch(c) {
                case ')':
                    expect = '(';
                    break;
                case ']':
                    expect = '[';
                    break;
                case '}':
                    expect = '{';
                    break;
                default:
                    tmp.push(c);
            }
            if (expect) {
                if (tmp.empty() || tmp.top() != expect)
                    return false;
                else
                    tmp.pop();
            }
        }
        return tmp.empty();
    }
};


int main(int argc, char *argv[])
{
  auto sol = Solution();
  cout << sol.isValid("()") << endl; // true
  cout << sol.isValid("(") << endl; //false
  cout << sol.isValid("]") << endl; //false
  cout << sol.isValid("([{}])") << endl; //true
  return 0;
}
