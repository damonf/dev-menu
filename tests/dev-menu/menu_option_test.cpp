#include "menu_option.hpp"

#include <catch2/catch_test_macros.hpp>

namespace {

    namespace dm = dev_menu;

}

namespace dm_tests {

TEST_CASE("menu_option tests", "[menu_option]") {

    SECTION("test creates option") {

        const dm::MenuOption option{"/base/path"};

        REQUIRE(option.get_path() == "/base/path");
        REQUIRE(option.get_name() == "path");
    }

    SECTION("test throws if path does not contain /") {

        REQUIRE_THROWS([](){
            const dm::MenuOption option{"path"};
        }());
    }

}

}
