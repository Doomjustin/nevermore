#include <cstdlib>

#include "nevermore/Logger.h"

int main(int argc, char* argv[])
{
    SF_ERROR("error message {}", 1);
    return EXIT_SUCCESS;
}
