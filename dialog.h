#pragma once
#include "BigInt/BigInt.h"
#include "PN/PN.h"

template <typename T>
void getValue(T& value, std::istream& c);
BigInt solve(std::string& str, std::ostream& c);
BigInt solve_opz(const std::string& str);
void erase_spaces(std::string& str);

void menu();