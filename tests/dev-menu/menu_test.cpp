#include "menu_option.hpp"
#include "menu.hpp"

#include <catch2/catch_test_macros.hpp>

#include <string>
#include <vector>


namespace {

    namespace dm = dev_menu;

}

namespace dm_tests {

TEST_CASE("menu tests", "[menu]") {

    SECTION("test get_display returns display for empty search string") {

        const std::vector<dm::MenuOption> options{dm::MenuOption("/base/path1"), dm::MenuOption("/base/path2")};

        const dm::Menu menu{options};

        auto menu_options = menu.get_display();

        REQUIRE(menu_options == "1. path1\n2. path2\n");
    }

    SECTION("test get_display returns display filtered by search string") {

        const std::vector<dm::MenuOption> options{dm::MenuOption("/base/path1"), dm::MenuOption("/base/path2")};

        const dm::Menu menu{options, "path2"};

        auto menu_options = menu.get_display();

        REQUIRE(menu_options == "1. path2\n");
    }

    SECTION("test get_display filters paths begining with underscore") {

        const std::vector<dm::MenuOption> options{dm::MenuOption("/base/path1"), dm::MenuOption("/base/_path2")};

        const dm::Menu menu{options};

        auto menu_options = menu.get_display();

        REQUIRE(menu_options == "1. path1\n");
    }

    SECTION("test select_option gets the path") {

        const std::vector<dm::MenuOption> options{dm::MenuOption("/base/path1"), dm::MenuOption("/base/path2")};

        const dm::Menu menu{options};

        auto menu_options = menu.get_display();

        REQUIRE(menu_options == "1. path1\n2. path2\n");

        auto path1 = menu.select_option(1);

        REQUIRE(path1.has_value());
        REQUIRE(path1.value() == "/base/path1"); // NOLINT
        
        auto path2 = menu.select_option(2);

        REQUIRE(path2.has_value());
        REQUIRE(path2.value() == "/base/path2"); // NOLINT
    }

    SECTION("test select_option returns nullopt for invalid option") {

        const std::vector<dm::MenuOption> options{dm::MenuOption("/base/path1"), dm::MenuOption("/base/path2")};

        const dm::Menu menu{options};

        auto no_path = menu.select_option(3);

        REQUIRE(!no_path.has_value());
    }

    SECTION("test is_empty returns true for empty menu") {

        const std::vector<dm::MenuOption> options{};

        const dm::Menu menu{options};

        auto is_empty = menu.is_empty();

        REQUIRE(is_empty);
    }
}

}
