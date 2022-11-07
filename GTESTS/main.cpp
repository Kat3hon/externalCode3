#include <gtest/gtest.h>
#include "..\dialog.h"

TEST (solver, good) {
    int ans = 8+9-(2+3)+12;
    std::string str = "8+9-(2+3)+1231231512-125125";
    ConvertToPN pn;
    pn.convert(str);
    solve(str, std::cout);
    ASSERT_EQ("+24", str);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}