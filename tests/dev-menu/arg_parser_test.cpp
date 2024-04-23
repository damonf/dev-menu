#include "arg_parser.hpp"

#include <array>

#include <catch2/catch_test_macros.hpp>

using dev_menu::ArgParser;

namespace dev_menu_tests {

TEST_CASE("arg_parser tests", "[arg_parser]") {

    SECTION("test is_valid returns true for valid args") {

        const auto argc = 4;
        std::array<const char*, argc> args = {"./arg_parser_test", "searchstr", "-d", "path"};

        const ArgParser arg_parser{
            argc 
            , args.data()
        };

        REQUIRE(arg_parser.is_valid());
    }

    SECTION("test is_valid returns false for invalid option") {

        const auto argc = 3;
        std::array<const char*, argc> args = {"./arg_parser_test", "searchstr", "-x"};

        const ArgParser arg_parser{
            argc
            , args.data()
        };

        REQUIRE(arg_parser.is_valid() == false);
    }

    SECTION("test is_valid returns false for too many args") {

        const auto argc = 5;
        std::array<const char*, argc> args = {"./arg_parser_test", "searchstr", "a", "b", "c"};

        const ArgParser arg_parser{
            argc
            , args.data()
        };

        REQUIRE(arg_parser.is_valid() == false);
    }

    SECTION("test get_path returns the path") {

        const auto argc = 4;
        std::array<const char*, argc> args = {"./arg_parser_test", "searchstr", "-d", "path"};

        const ArgParser arg_parser{
            argc
            , args.data()
        };

        REQUIRE(arg_parser.get_path() == "path");
    }

    SECTION("test get_path returns the path") {

        const auto argc = 4;
        std::array<const char*, argc> args = {"./arg_parser_test", "searchstr", "-d", "path"};

        const ArgParser arg_parser{
            argc
            , args.data()
        };

        REQUIRE(arg_parser.get_search_string() == "searchstr");
    }
}

}
