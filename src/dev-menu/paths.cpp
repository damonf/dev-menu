#include "paths.hpp"

#include <filesystem>
#include <string>
#include <vector>

namespace dev_menu {

std::vector<std::string> get_paths(const std::string& dir) {
    const std::filesystem::path base_path(dir);

    if (!is_directory(base_path)) {
        return {};
    }

    std::vector<std::string> paths;

    for (const auto& e : std::filesystem::directory_iterator{base_path}) {
        if (e.is_directory()) {
            paths.push_back(e.path());
        }
    }

    return paths;
}

} // namespace dev_menu
