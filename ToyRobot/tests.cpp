#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Robot.h>


class RobotTests : public testing::Test {
    protected:
        RobotTests() {}

        ~RobotTests() {}

        void SetUp() override {
            EXPECT_EQ(robotTest.IsRobotInitialized(), false);
        }

        void TearDown() override {}

        Robot robotTest;
};


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(RobotTests, CanTestCompleteProcess) {
    robotTest.startProcess();
}

TEST_F(RobotTests, CanTestSetInitialized) {
    robotTest.setIsRobotInitialized(true);
    EXPECT_EQ(robotTest.IsRobotInitialized(), true);

    robotTest.setIsRobotInitialized(false);
    EXPECT_EQ(robotTest.IsRobotInitialized(), false);
}
