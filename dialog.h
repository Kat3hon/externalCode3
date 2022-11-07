#pragma once
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "BigInt/BigInt.h"
#include "PN/PN.h"
#include <algorithm>
#include <memory>

void menu();

template <typename T>
void getValue(T& value, std::istream& c);
void solve(std::string& str, std::ostream& c);