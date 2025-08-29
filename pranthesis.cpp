#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balance_paranthesis(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s1 = "{}()[]";
    string s2 = "{}([)]";
    string s3 = "{([])}";

    cout << bool(balance_paranthesis(s1)) << "\n"; // 1
    cout << bool(balance_paranthesis(s2))<< "\n"; // 0
    cout << bool(balance_paranthesis(s3)) << "\n"; // 1
    return 0;
}
