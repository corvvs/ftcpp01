#include "Karen.hpp"

typedef void (Karen::*KarenSayer)(void);

const std::string Karen::kLevelNames[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
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
    KarenSayer available_sayers[] = {
        &Karen::debug,
        &Karen::info,
        &Karen::warning,
        &Karen::error,
        &Karen::nothing
    };
    const std::size_t index = find_index(level, 0);
    KarenSayer sayer = available_sayers[index];
    (this->*sayer)();
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
