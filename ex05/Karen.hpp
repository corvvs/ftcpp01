#ifndef CPP01_EX05_KAREN_HPP_
# define CPP01_EX05_KAREN_HPP_

#include <iostream>
#include <string>

const std::size_t kKarenLogLevels = 4;

class Karen {
    public:
        void    complain(std::string level);

    private:
        void    nothing(void);
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        std::size_t find_index(
            const std::string& level,
            const std::size_t current_index
        );

        const static std::string    kLevelNames[];
        const static std::string    kDebugMessage_;
        const static std::string    kInfoMessage_;
        const static std::string    kWarningMessage_;
        const static std::string    kErrorMessage_;
};

#endif
