//
// Created by wfy on 2022/11/26.
//

#ifndef SRC_SALES_DATA_H
#define SRC_SALES_DATA_H


#include "string"
#include "iostream"
class Sales_data {

    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream & read(std::istream &, Sales_data &);
    friend std::ostream & print(std::ostream &, const Sales_data &);

public:

    Sales_data() = default ;
    explicit Sales_data(const std::string &s, size_t n, double p):bookNo(s),units_sold(n), revenue(n*p){}
    Sales_data(const std::string &s) :Sales_data(s,0,0){}
    Sales_data(std::istream &is):Sales_data() { }

    std::string isbn() const { return bookNo; };

    Sales_data& combine(Sales_data &rhs) const {

    }

private:
    std::string bookNo;
    size_t units_sold = 0;
    double revenue = 0;

    static int ACCOUNT;
};


Sales_data add(const Sales_data &, const Sales_data &);

std::istream & read(std::istream &, Sales_data &);

std::ostream & print(std::ostream &, const Sales_data &);


#endif //SRC_SALES_DATA_H
