#include "nevermore/StdoutAppender.h"

#include <iostream>

namespace sf {

void StdoutAppender::write(const std::string& message)
{
    std::cout << message << '\n';
}

} // namespace sf
