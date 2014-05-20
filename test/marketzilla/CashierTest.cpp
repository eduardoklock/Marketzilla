#include <gtest/gtest.h>
#include <marketzilla/Cashier.h>

using marketzilla::Cashier;

class CashierTest : public testing::Test {
public:
    Cashier alice = Cashier("Alice", 1985);
    Cashier bob = Cashier("Robert", 42);
};

TEST_F(CashierTest, doCashierHasProperName)
{
    EXPECT_EQ("Alice", alice.name());
    EXPECT_EQ("Robert", bob.name());
}

TEST_F(CashierTest, checkSalaryCansistence)
{
    EXPECT_EQ(1985, alice.salary());
    EXPECT_EQ(42, bob.salary());
}