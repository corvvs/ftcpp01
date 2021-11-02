#include "Karen.hpp"

typedef void (Karen::*KarenSayer)(void);

const std::string Karen::kLevelNames[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
};

const std::string Karen::kDebugMessage_
    = "debug!!";
const std::string Karen::kInfoMessage_
    = "info!!";
const std::string Karen::kWarningMessage_
    = "warning!!";
const std::string Karen::kErrorMessage_
    = "We are the Borg. You will be assimilated. Resistance is futile.";

void    Karen::complain(std::string level) {
    KarenSayer available_sayers[] = {
        &Karen::debug,
        &Karen::info,
        &Karen::warning,
        &Karen::error,
    };
    KarenSayer sayer = NULL;
    for (std::size_t i = 0; i < kKarenLogLevels; i += 1) {
        std::string target_level = Karen::kLevelNames[i];
        if (level == target_level) {
            sayer = available_sayers[i];
            break;
        }
    }
    if (sayer) {
        (this->*sayer)();
    }
}

void    Karen::filter(std::string min_level) {
    bool found = false;
    for (std::size_t i = 0; i < kKarenLogLevels; i += 1) {
        std::string target_level = Karen::kLevelNames[i];
        if (!found && min_level == target_level) {
            found = true;
        }
        if (found) {
            std::cout
                << ("[ " + target_level + " ]")
                << std::endl;
            complain(target_level);
            std::cout << std::endl;
        }
    }
    if (!found) {
        std::cout
            << "[ Probably complaining about insignificant problems ]"
            << std::endl;
    }
}


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
