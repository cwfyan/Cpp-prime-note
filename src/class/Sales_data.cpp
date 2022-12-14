//
// Created by wfy on 2022/11/26.
//

#include "Sales_data.h"

int Sales_data::ACCOUNT = 10;

Sales_data add(const Sales_data &salesData1, const Sales_data &salesData2){

}

std::istream & read(std::istream &is, Sales_data &salesData){
    double price = 0; //单价
    is >> salesData.bookNo >> salesData.units_sold >>price;
    salesData.revenue = salesData.units_sold*price;

    return is;
}

std::ostream & print(std::ostream &os, const Sales_data &salesData){
    os << salesData.bookNo << " " <<
    salesData.units_sold << " " <<
    salesData.revenue<<std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &salesData) {
    out << salesData.isbn() << " " <<salesData.units_sold << " " <<salesData.revenue <<std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Sales_data &salesData) {
    double price = 0; //单价
    Sales_data temp = salesData;
    in >> salesData.bookNo >> salesData.units_sold >>price;
    if (in) {
        salesData.revenue = salesData.units_sold*price;
    }else {
        salesData = temp;
    }
    return in;
}
