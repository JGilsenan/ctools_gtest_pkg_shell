#include <string>

class Soundex {

public:
  std::string encode(const std::string& word) const {
    return "";
  }

};


#include "gmock/gmock.h"
#include "tdd_cpp_examples/main.h"


TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
	Soundex soundex;

	auto encoded = soundex.encode("A");

	ASSERT_THAT(encoded, testing::Eq("A"));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
