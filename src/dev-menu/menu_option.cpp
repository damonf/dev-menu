#include "menu_option.hpp"

#include <stdexcept>
#include <string>
#include <string_view>

namespace dev_menu {

MenuOption::MenuOption(std::string_view path) {
    auto idx = path.find_last_of('/');
    if (idx == std::string::npos || idx == path.size() - 1) {
        throw std::invalid_argument("invalid path");
    }

    name_ = path.substr(idx + 1);
    path_ = path;
}

} // namespace dev_menu
