#include <iostream>
#include <string>
#include <math.h>

using namespace std;


void rabin_karp_matcher(string T, string P, long long unsigned int q, long long unsigned int d) {
    int n = T.size();
    int m = P.size();
    long long unsigned int h = (long long unsigned int)(pow(d, m - 1)) % q;

    long long unsigned int p = 0;
    long long unsigned int t = 0;


    for(int i = 0; i < m; ++i) {

        //cout << i << " " << m << " -----" << endl;

        t = ((t * d) + (T[i] - '0')) % q;
        p = ((p * d) + (P[i] - '0')) % q;

        //cout << t << " " << p << endl;


    }

    //cout << t << " " << p << endl;

    for(int s = 0; s <= n - m; ++s) {

        if(t == p) {
            int i = 0;
            for(; i < m; ++i) {
                if((P[i] - '0') != (T[s + i] - '0')) 
                    break;
            }

            if(i == m) 
                cout << "Pattern found with shift " << s << endl;
        }

        if(s + 1 <= n - m) {
            t = ((d * (t - (h * (T[s] - '0')))) + (T[s + m] - '0')) % q;
        }
    }

}

int main() {
    string T = "11111111111111111111111111111111111111";
    string P = "11";
    long long unsigned int q = 1000000007;
    long long unsigned int d = 10;
    rabin_karp_matcher(T, P, q, d);
    return 0;

}