#pragma once
#include "BigInt/BigInt.h"
#include "PN/PN.h"

template <typename T>
void getValue(T& value, std::istream& c);
void solve(std::string& str, std::ostream& c);
BigInt solve_opz(const std::string& str);

void menu();