/*
Algorithm works only if all the characters in the pattern are different
*/

#include <iostream>
#include <string>

using namespace std;

void optimized_naive_string_matcher(string text, string pattern) {

    int m = pattern.size();
    int n = text.size();
    int s = 0;
    int i = 0;

    while(s <= n - m) {
        
        for(i = 0; i < m; i++) {
            if(pattern[i] != text[s + i])
                break;
        }

        if(i == 0) {
            s = s + 1;
        } else if(i == m) {
            cout << "Pattern found in text with shift " << s << endl;
            s = s + m;
        } else {
            s = s + i;
        }
    }
}

int main() {
    string text = "abaaaabaaab";
    string pattern = "ab";

    optimized_naive_string_matcher(text, pattern);

    return 0;
}