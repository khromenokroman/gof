#include <iostream>
#include <string_view>

class Logger
{
public:
    static Logger &get()
    {
        static Logger logger;
        return logger;
    }

    void debug(std::string_view const & str){
        std::cout << "[DEBUG]: " << str << std::endl;
    }
    
    void info(std::string_view const & str){
        std::cout << "[INFO]: " << str << std::endl;
    }
    
    void warn(std::string_view const & str){
        std::cout << "[WARN]: " << str<< std::endl;
    }
private:
    Logger() = default;
    ~Logger() = default;
};

int main()
{
    auto& logger = Logger::get();

    logger.debug("Hello");
    logger.info("Hello");
    logger.warn("Hello");
    return 0;
}