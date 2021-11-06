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
    };
    KarenSayer sayer = &Karen::nothing;
    for (std::size_t i = 0; i < kKarenLogLevels; i += 1) {
        std::string target_level = Karen::kLevelNames[i];
        if (level == target_level) {
            sayer = available_sayers[i];
            break;
        }
    }
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
