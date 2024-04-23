#include "arg_parser.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <span>
#include <string>

namespace dev_menu {

namespace rg = std::ranges;
namespace vws = std::views;

ArgParser::ArgParser(int argc, const char** argv) {
    const std::span<const char*> args{argv, static_cast<size_t>(argc)};
    rg::copy_if(args, std::back_inserter(args_),
                         [](const char* arg) { return arg != nullptr; });
}

bool ArgParser::is_valid() const {

    if (args_.size() > 4) {
        return false;
    }

    auto options_view =
        args_ | vws::filter(
                    [](const std::string& arg) { return arg[0] == '-'; });

    auto options_count = rg::distance(options_view);

    if (options_count > 1) {
        return false;
    }

    if (options_count == 1 && *begin(options_view) != path_option_) {
        return false;
    }

    return true;
}

const std::string& ArgParser::get_search_string() const {
    if (args_.size() > 1 && args_[1][0] != '-') {
        return args_[1];
    }
    return empty_string_;
}

const std::string& ArgParser::get_path() const {
    auto it = rg::find(args_, path_option_);
    if (it != args_.end() && ++it != args_.end()) {
        return *it;
    }
    return empty_string_;
}

} // namespace dev_menu
