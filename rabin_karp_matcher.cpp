#include <iostream>
#include <string>
#include <math.h>

using namespace std;


long long int pow(long long int d, int m, long long int q) {

    long long int h = 1;
    for(int i = 0; i < m; ++i) {
        h = (h * d) % q;
    }

    return h;
}


void rabin_karp_matcher(string T, string P, long long int q, long long int d) {
    int n = T.size();
    int m = P.size();
    long long int h = (long long int)pow(d, m - 1, q);

    long long int p = 0;
    long long int t = 0;

    for(int i = 0; i < m; ++i) {

        t = ((t * d) + (T[i] - '0')) % q;
        p = ((p * d) + (P[i] - '0')) % q;

    }


    for(int s = 0; s <= n - m; ++s) {

        if(t == p) {
            int i = 0;
            for(; i < m; ++i) {
                if((P[i] - '0') != (T[s + i] - '0'))  {
                    break;
                }
            }

            if(i == m) 
                cout << "Pattern found with shift " << s << endl;
        }

        if(s + 1 <= n - m) {
            t = ((d * (t - (h * (T[s] - '0')))) + (T[s + m] - '0')) % q;
            if(t < 0) {
                t += q;
            }
        }
    }

}

int main() {
    string T = "326314159265358926353453534464765654353466453456342433434343323223234453465426793";
    string P = "345353446476565435346645345634243343";
    long long int q = 100000007;
    long long int d = 10;
    rabin_karp_matcher(T, P, q, d);
    return 0;

}