//
// Created by wfy on 2022/12/9.
//

#include "QueryResult.h"

void print(std::ostream & out, const QueryResult & result) {
    out <<"elememt occurs " << result.st->size() <<"times" <<std::endl;

    for (auto x : *result.st) {
        std::cout << "(line " << x << ") " << result.file->at(x) <<std::endl;
    }
}
std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const { return file; }

std::set<int>::const_iterator QueryResult::begin() const {
    return st->cend();
}
std::set<int>::const_iterator QueryResult::end() const {
    return st->cbegin();
}