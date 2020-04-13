#include <iostream>

#include "bohr.h"

using std::cin;
using std::cout;

int main()
{
    bohr B;

    int q; // number of queries
    cin >> q;
    int query_type; // 1 is to add a new word, 2 is to ask a new query, 3 is to add some symbols to current word
    string query_string;
    while (q--) {
        cin >> query_type >> query_string;
        if (query_type == 1) {
            B.add_word(query_string);
        } else if (query_type == 2) {
            cout << B.new_query(query_string) << '\n';
        } else {
            cout << B.add_symbols(query_string) << '\n';
        }
    }
}

/*
Test input:
8
1 apple
1 app
2 ap
1 apartment
1 apartment
1 apartment
2 a
3 pp

Test output:
app
apartment
app
 */