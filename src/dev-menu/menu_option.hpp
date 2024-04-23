#ifndef MENU_OPTION_HPP
#define MENU_OPTION_HPP

#include <string>
#include <string_view>

namespace dev_menu {

class MenuOption {
  public:
    explicit MenuOption(std::string_view path);

    [[nodiscard]] const std::string& get_name() const { return name_; }
    [[nodiscard]] const std::string& get_path() const { return path_; }

  private:
    std::string name_;
    std::string path_;
};

}

#endif // MENU_OPTION_HPP
