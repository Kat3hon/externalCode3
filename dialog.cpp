#include "dialog.h"

template <typename T>
void getValue(T& value, std::istream& c) {
    c >> value;
    if (c.fail()) {
        c.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input argument.");
    }
    if (c.eof()) {
        c.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("End of file!");
    }
    return;
}

BigInt solve_opz(const std::string& str) {
    std::stringstream s(str);
    std::stack<BigInt> opz;
    BigInt value;
    char sign;
    while (!s.eof()) {
        try {
            while (s >> value)
                opz.push(value);
        }
        catch (const std::exception& ex) {
            s.clear();
            s.unget();
            s>>sign;
            if (!s.eof())
                s.get();
            if (opz.size() < 2) {
                throw std::runtime_error("The equation is not reverse polish notation. Too mush variables.");
            }
            BigInt right = opz.top();
            opz.pop();
            BigInt left = opz.top();
            opz.pop();
            switch (sign) {
                case '+':   opz.push(right + left); break;
                case '-':   opz.push(left - right); break;
                default: throw std::runtime_error("Undefined operator in reverse polish notation.");
            }
        }
    }
    if (opz.size() != 1)
        throw std::runtime_error("The equation is not reverse polish notation. Need one more operator.");
    return opz.top();
}

void erase_spaces(std::string& str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
}

void solve(std::string& str, std::ostream& c) {
    erase_spaces(str);
    ConvertToPN opn;
    opn.convert(str);
    c << solve_opz(opn.getStrOut());
}

void menu() {
    std::fstream inf;
    std::fstream outf;


    std::cout << "Choose input stream: console (0) or file (1)" << std::endl;
    size_t ans_i;
    getValue(ans_i, std::cin);
    std::cout << std::endl;

    std::string ans;
    if (ans_i == 1) {
        std::cout << "Input an input file name: ";
        std::string inp_file_name;
        getValue(inp_file_name, std::cin);
        std::cout << std::endl;
        inf.open(inp_file_name);
        if (!inf)
            throw std::runtime_error("Can not open input file.");
        inf >> ans;
    }
    else {
        std::cout << "Input an expression (it only can constist '+', '-', '(' or ')'):" << std::endl;
        getValue(ans, std::cin);
    }

    std::cout << std::endl << "Choose output stream console (0) or file (1):" << std::endl;
    size_t ans_o;
    getValue(ans_o, std::cin);
    std::cout << std::endl;

    if (ans_o == 1) {
        std::cout << "Input an output file name: ";
        std::string out_file_name;
        getValue(out_file_name, std::cin);
        std::cout << std::endl;
        outf.open(out_file_name);
        solve(ans, outf);
    }
    else solve(ans, std::cout);

    inf.close();
    outf.close();
    std::cout << std::endl;
}


