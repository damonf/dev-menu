#include "arg_parser.hpp"
#include "paths.hpp"
#include "menu_option.hpp"
#include "menu.hpp"
#include "is_number.hpp"
#include "trim.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>
#include <ranges>
#include <string>
#include <vector>

namespace {

    namespace vws = std::views;
    namespace dm = dev_menu;
    const char* const EnvVar = "DEV_MENU_PATH";

}

std::optional<std::string> show_menu(const dm::Menu& menu);
bool select_option(const dm::Menu& menu, int option_idx);
std::string get_dir(const std::string& option);

int main(int argc, const char *argv[]) {

    try {

        const dm::ArgParser arg_parser(argc, argv);

        if (!arg_parser.is_valid()) {
            std::cerr << "Usage: [search_string] [-d path]\n";
            return EXIT_FAILURE;
        }

        const auto& search_string = arg_parser.get_search_string();
        const auto& option = arg_parser.get_path();
        const auto dir = get_dir(option);

        std::vector<std::string> paths = dm::get_paths(dir);

        auto options = paths | vws::transform([](std::string& path) {
            return dm::MenuOption{path};
        });

        auto menuOptions = std::vector<dm::MenuOption>{options.begin(), options.end()};
        auto menu = dm::Menu{menuOptions, search_string};

        while (true) {
            auto search = show_menu(menu);
            if (!search.has_value()) {
                break;
            }
            menu = dm::Menu{menuOptions, search.value()};
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }
}

// Returns a new search string if the user entered one,
// otherwise returns nullopt (time to exit)
std::optional<std::string> show_menu(const dm::Menu& menu) {
    if (menu.is_empty()) {
        std::cout << "<Empty>\n";
    }
    else {
        if (menu.num_options() == 1) {
            if (select_option(menu, 1)) {
                return std::nullopt;
            }
        }

        auto display = menu.get_display();
        std::cout << display;
    }

    std::string input;
    std::getline(std::cin, input);
    auto trimmed = dm::trim(input);

    if (trimmed == ".exit" || trimmed == ".e") {
        return std::nullopt;
    }

    if (dm::is_number(trimmed)) {
        const int option_idx = std::stoi(trimmed);
        if (select_option(menu, option_idx)) {
            return std::nullopt;
        }
    }

    return trimmed;
}

bool select_option(const dm::Menu& menu, int option_idx) {
    auto path = menu.select_option(option_idx);

    if (path.has_value()) {
        // Write selected path to stderr
        std::cerr << path.value() << '\n';
        return true;
    }

    return false;
}

std::string get_dir(const std::string& option) {

    std::string dir = ".";

    if (!option.empty()) {
        dir = option;
    }
    else {
        const char* const env_dir = std::getenv(EnvVar); // NOLINT
        if (env_dir != nullptr) {
            dir = env_dir;
        }
    }

    return dir;
}
