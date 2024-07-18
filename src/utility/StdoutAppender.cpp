#include "nevermore/Logger.h"

#include <iostream>

namespace sf {

void StdoutLogAppender::write(const std::string& message)
{
    std::cout << message << '\n';
}

} // namespace sf
