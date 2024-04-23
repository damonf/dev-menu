#include "menu.hpp"
#include "menu_option.hpp"

#include <ranges>
#include <vector>
#include <string>
#include <optional>
#include <format>
#include <cstddef>
#include <cctype>
#include <algorithm>

namespace dev_menu {

namespace rg = std::ranges;
namespace vws = std::views;

Menu::Menu(const std::vector<MenuOption>& options, const std::string& search_string) {
    auto equals_ignore_case = [](char a, char b) {
        return std::tolower(a) == std::tolower(b);
    };

    auto options_view = options | vws::filter([=](const MenuOption& option) {
        return !option.get_name().starts_with("_") && (search_string.empty() ||
            !rg::search(option.get_name(), search_string, equals_ignore_case).empty());
    });

    options_.assign(options_view.begin(), options_view.end());
}

std::string Menu::get_display() const {
    std::string display;

    for (size_t i = 0; i < options_.size(); ++i) {
        display += std::format("{}. {}\n", i+1, options_[i].get_name());
    }

    return display;
}

std::optional<std::string> Menu::select_option(int option_idx) const {
    auto idx = option_idx - 1;
    if (idx < 0 || idx >= std::ssize(options_)) {
        return std::nullopt;
    }
    return options_[idx].get_path();
}

long Menu::num_options() const {
    return std::ssize(options_);
}

bool Menu::is_empty() const {
    return options_.empty();
}

} // namespace dev_menu
