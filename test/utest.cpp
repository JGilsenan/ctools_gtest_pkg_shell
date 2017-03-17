#include "gtest/gtest.h"

#include "tdd_lidar_demo/tdd_lidar_demo.h"


TEST(TestTddLidarDemo, emptyTest)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
