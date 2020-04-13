//
// Created by amir on 13.04.2020.
//
#include <string>

using std::string;

class bohr {
public:
    bohr();
    ~bohr();

    string add_symbols(const string& s); // add some symbols to existing query
    string new_query(const string& s); // create new query
    void add_word(const string& s);

private:
    struct node;
    string current_string_;
    node* root_, * current_vertex_;
};