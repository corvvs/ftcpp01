#ifndef CPP01_EX06_KAREN_HPP_
# define CPP01_EX06_KAREN_HPP_

#include <iostream>
#include <string>

const std::size_t kKarenLogLevels = 4;

class Karen;
typedef void (Karen::*KarenSayer)(void);

class Karen {
    public:
        void    complain(std::string level);
        void    filter(const std::string& min_level);

    private:
        void    nothing(void);
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        void    print_filter_item(const std::size_t level_index);
        std::size_t find_index(
            const std::string& level,
            const std::size_t current_index
        );

        const static std::string    kLevelNames[];
        const static KarenSayer     kSayers[];
        const static std::string    kDebugMessage_;
        const static std::string    kInfoMessage_;
        const static std::string    kWarningMessage_;
        const static std::string    kErrorMessage_;
};

#endif
