//
// Created by wfy on 2022/12/10.
//

#include "Employee.h"

size_t Employee::number = 0;

Employee & Employee::operator=(const Employee &employee) {
    name = employee.name;
    return *this;
}

std::string Employee::get_name() const { return name; }
size_t Employee::get_num() const { return employee_number; }