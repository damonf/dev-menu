#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <string>
#include <vector>

namespace dev_menu {

class ArgParser {
  public:
    ArgParser(int argc, const char** argv);

    [[nodiscard]] bool is_valid() const;
    [[nodiscard]] const std::string& get_search_string() const;
    [[nodiscard]] const std::string& get_path() const;

  private:
    std::vector<std::string> args_{};
    constexpr const static std::string empty_string_{};
    constexpr const static std::string path_option_{"-d"};
};

} // namespace dev_menu

#endif // ARG_PARSER_HPP
