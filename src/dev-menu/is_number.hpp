#ifndef IS_NUMBER_HPP
#define IS_NUMBER_HPP

#include <algorithm>
#include <string>

namespace dev_menu {

namespace rg = std::ranges;

[[nodiscard]] inline bool is_number(const std::string& s) {
    return !s.empty() && rg::all_of(s, ::isdigit);
}

} // namespace dev_menu

#endif // IS_NUMBER_HPP
