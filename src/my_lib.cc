#include "boost/version.hpp"
#include <iostream>
#include <stdio.h>

#include "my_lib.h"

/**
 * @brief Couts Hello World to the Console
 *
 */
void cout_hello_world()
{
    std::cout << "Hello World!" << std::endl;
}

/**
 * @brief prints a float 3d Vector in the Console
 *
 * @return a float 3d Vector
 */
linalg::aliases::float3 print_linalg_vector()
{
    linalg::aliases::float3 my_float3{1, 2, 3};
    std::cout << "Vec: (" << my_float3[0] << "," << my_float3[1] << "," << my_float3[2] << ")" << std::endl;

    return my_float3;
}

/**
 * @brief couts the BOOST_Library Version
 *
 * @return bool
 */
bool print_boost_version()
{
    std::cout << BOOST_VERSION << std::endl;

    return true;
}
