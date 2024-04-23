#include "trim.hpp"
#include <algorithm>
#include <cctype>
#include <ranges>
#include <string>
#include <string_view>

namespace dev_menu {

namespace rg = std::ranges;
namespace vws = std::views;

[[nodiscard]] std::string trim(const std::string& str) {
    const std::string_view view{str};

    const auto *start = rg::find_if_not(view, isspace);
    auto end = rg::find_if_not(view | vws::reverse, isspace);

    return {start, end.base()};
}

} // namespace dev_menu

