#include <gtest/gtest.h>
#include "..\dialog.h"

TEST (solver, good) {
    BigInt a("1234567"), b("123000"), c("12345"), d("51221");
    BigInt result = a+b-(c+d);
    std::string str = "1234567+123000 - (12345 + 51221)";
    ConvertToPN pn;
    pn.convert(str);
    BigInt res = solve(str, std::cout);
    ASSERT_EQ(result, res);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}