#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ctools_gtest_pkg_shell/main.h"


TEST(PackageShellTestPlaceholder, emptyTest)
{
	EXPECT_EQ(1, 1);
}

TEST(PackageShellTestPlaceholder, emptyTestTwo)
{
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
