#include "Karen.hpp"

const std::string Karen::kLevelNames[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
};

const KarenSayer Karen::kSayers[] = {
    &Karen::debug,
    &Karen::info,
    &Karen::warning,
    &Karen::error,
    &Karen::nothing
};

const std::string Karen::kDebugMessage_
    = "I am Karen, 6 years old.";
const std::string Karen::kInfoMessage_
    = "I am Karen, I'm on my way to your house.";
const std::string Karen::kWarningMessage_
    = "I am Karen, I'm in front of your house.";
const std::string Karen::kErrorMessage_
    = "I am Karen, I'm behind you now.";

void    Karen::complain(std::string level) {
    const std::size_t index = find_index(level, 0);
    KarenSayer sayer = Karen::kSayers[index];
    (this->*sayer)();
}

void    Karen::filter(const std::string& min_level) {
    const std::size_t index = find_index(min_level, 0);
    switch (index) {
        case 0:
            print_filter_item(0);
        case 1:
            print_filter_item(1);
        case 2:
            print_filter_item(2);
        case 3:
            print_filter_item(3);
            break;
        default:
            std::cout
                << "[ Probably complaining about insignificant problems ]"
                << std::endl;
    }
}

void    Karen::nothing(void) {}

void    Karen::debug(void) {
    std::cout << Karen::kDebugMessage_ << std::endl;
}

void    Karen::info(void) {
    std::cout << Karen::kInfoMessage_ << std::endl;
}

void    Karen::warning(void) {
    std::cout << Karen::kWarningMessage_ << std::endl;
}

void    Karen::error(void) {
    std::cout << Karen::kErrorMessage_ << std::endl;
}

void    Karen::print_filter_item(const std::size_t level_index) {
    std::cout
        << ("[ " + Karen::kLevelNames[level_index] + " ]")
        << std::endl;
    (this->*Karen::kSayers[level_index])();
    std::cout << std::endl;
}

std::size_t Karen::find_index(
    const std::string& level,
    const std::size_t current_index
) {
    return current_index >= kKarenLogLevels
        ? kKarenLogLevels
        : level == Karen::kLevelNames[current_index]
            ? current_index
            : find_index(level, current_index + 1);
}
