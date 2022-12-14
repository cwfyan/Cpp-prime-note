//
// Created by wfy on 2022/12/10.
//

#ifndef SRC_EMPLOYEE_H
#define SRC_EMPLOYEE_H
#include <iostream>
#include <string>

class Employee {
public:
    static size_t number;

    Employee():name(),employee_number(++number) {}
    Employee(const std::string &Name) :name(Name),employee_number(++number){}
    Employee(const Employee &employee) :name(employee.name),employee_number(++number){}
    Employee & operator = (const Employee &employee) ;

    std::string  get_name() const  ;
    size_t get_num() const ;
private:
    std::string name;
    size_t employee_number;
};


#endif //SRC_EMPLOYEE_H
