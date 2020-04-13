//
// Created by amir on 13.04.2020.
//
#include "bohr.h"

#include <iostream>
#include <iterator>
#include <unordered_map>

struct bohr::node {
    std::unordered_map <char, node*> next_;
    int max_next_id_, cnt_words_, max_words_;

    node(): max_next_id_(-1), cnt_words_(0), max_words_(0) {
    }
    ~node() {
        for (auto child: next_)
            delete(child.second);
    }

    node* move_by_string(const string& s) {
        node* cur = this;
        for (char c: s) {
            if (cur->next_.find(c) == cur->next_.end()) {
                cur = nullptr;
                break;
            }
            cur = cur->next_[c];
        }
        return cur;
    }

    void update_max() {
        max_words_ = cnt_words_;
        max_next_id_ = -1;
        for (auto it: next_) {
            if (max_words_ < it.second->max_words_) {
                max_next_id_ = it.first;
                max_words_ = it.second->max_words_;
            }
        }
    }

    void add_string(const string& s, int i) {
        if (i == s.length()) {
            ++cnt_words_;
            if (max_next_id_ == -1) {
                ++max_words_;
            } else if (max_words_ <= cnt_words_) {
                max_next_id_ = -1;
                max_words_ = cnt_words_;
            }
            return;
        }

        if (next_.find(s[i]) == next_.end()) {
            next_[s[i]] = new node();
        }
        next_[s[i]]->add_string(s, i + 1);
        update_max();
    }

    void get_popular(string& name) {
        if (max_next_id_ == -1)
            return;

        name.push_back(static_cast<char>(max_next_id_));
        next_[max_next_id_]->get_popular(name);
    }
};

bohr::bohr(): current_string_(""), root_(new node()), current_vertex_(nullptr) {
}

bohr::~bohr() {
    delete(root_);
}

string bohr::add_symbols(const string &s) {
    node* new_vertex = current_vertex_->move_by_string(s);
    if (!new_vertex) {
        std::cerr << "No words have been found by this clue\n";
        return "";
    }
    current_vertex_ = new_vertex;

    std::copy(s.begin(), s.end(), std::back_inserter(current_string_));
    string path_to_popular;
    current_vertex_->get_popular(path_to_popular);
    string answer = current_string_ + path_to_popular;
    return std::move(answer);
}

string bohr::new_query(const string &s) {
    current_vertex_ = root_;
    current_string_ = "";
    return add_symbols(s);
}

void bohr::add_word(const string& s) {
    root_->add_string(s, 0);
}
