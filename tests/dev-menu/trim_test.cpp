#include "trim.hpp"

#include <catch2/catch_test_macros.hpp>

#include <string>


namespace {

    namespace dm = dev_menu;

}

namespace dm_tests {

TEST_CASE("trim tests", "[trim]") {

    SECTION("test trimms whitespace") {

        auto trimmed = dm::trim("  \ttest   ");

        REQUIRE(trimmed == "test");
    }

}

}
