
#include "ProjectConfig.h"
#include "my_lib.h"
#include <iostream>

#include "cxxopts.hpp"
#include "loguru.hpp"

int main(int argc, char **argv)
{
    cout_hello_world();
    print_linalg_vector();
    print_boost_version();
    /*    loguru::init(argc, argv);

    loguru::add_file("everything.log", loguru::Append, loguru::Verbosity_MAX);
    loguru::add_file("info.log", loguru::Append, loguru::Verbosity_INFO);
    loguru::add_file("warning.log", loguru::Append, loguru::Verbosity_WARNING);
    loguru::add_file("error.log", loguru::Append, loguru::Verbosity_ERROR);

    LOG_F(INFO, "This is an info log!");
    LOG_F(WARNING, "This is a warning log!");
    LOG_F(ERROR, "This is an error log!");
*/
    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    options.add_options()("d,debug", "Enable debugging") // a bool parameter
        ("i,integer", "Int param",
         cxxopts::value<int>())("f,file", "File name",
                                cxxopts::value<std::string>())("v,verbose", "Verbose output",
                                                               cxxopts::value<bool>()->default_value("false"));

    auto result = options.parse(argc, argv);

    if (result.count("debug"))
    {
        bool debug = result["debug"].as<bool>();
        std::cout << debug << std::endl;
    }

    if (result.count("integer"))
    {
        int integer = result["integer"].as<int>();
        std::cout << integer << std::endl;
    }
    if (result.count("file"))
    {
        std::string file = result["file"].as<std::string>();
        std::cout << file << std::endl;
    }
    if (result.count("verbose"))
    {
        bool verbose = result["verbose"].as<bool>();
        std::cout << verbose << std::endl;
    }


    return 0;
}
