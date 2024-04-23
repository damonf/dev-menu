#ifndef MENU_HPP
#define MENU_HPP

#include "menu_option.hpp"

#include <optional>
#include <string>
#include <vector>

namespace dev_menu {

class Menu {
  public:
    Menu(const std::vector<MenuOption>& options, const std::string& search_string = "");

    [[nodiscard]] std::string get_display() const;
    [[nodiscard]] std::optional<std::string>
    select_option(int option_idx) const;
    [[nodiscard]] long num_options() const;
    [[nodiscard]] bool is_empty() const;

private:
    std::vector<MenuOption> options_;
};

} // namespace dev_menu

#endif // MENU_HPP
