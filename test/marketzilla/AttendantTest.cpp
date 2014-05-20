#include <gtest/gtest.h>
#include <marketzilla/Attendant.h>

using marketzilla::Attendant;

class AttendantTest : public testing::Test {
public:
    Attendant alice = Attendant("Alice", 1985);
    Attendant bob = Attendant("Robert", 42);
};

TEST_F(AttendantTest, doAttendantHasProperName)
{
    EXPECT_EQ("Alice", alice.name());
    EXPECT_EQ("Robert", bob.name());
}

TEST_F(AttendantTest, checkSalaryCansistence)
{
    EXPECT_EQ(1985, alice.salary());
    EXPECT_EQ(42, bob.salary());
}