#include <iostream>
#include <string>

using namespace std;

void naive_string_matcher(string text, string pattern) {

    int m = pattern.size();
    int n = text.size();

    for(int s = 0; s <= n - m; ++s) {
        int j = 0;
        for(; j < m; ++j) {
            if(pattern[j] != text[s + j])
                break;
        }

        if(j == m)
            cout <<"Patter found in text with shift " << s << endl;
    }
}

int main() {
    string text = "aaaaaaaaaa";
    string pattern = "aa";

    naive_string_matcher(text, pattern);

    return 0;
}