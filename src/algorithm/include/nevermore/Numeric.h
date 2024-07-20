#ifndef NEVERMORE_ALGORITHM_NUMERIC_H
#define NEVERMORE_ALGORITHM_NUMERIC_H

#include <concepts>

namespace sf {

template<typename Integral>
    requires std::is_integral_v<Integral>
consteval Integral factorial(Integral n)
{
    Integral res = 1;
    while (n >= 1)
        res *= n--;

    return res;
}


namespace recursive {

template<typename Integral>
    requires std::is_integral_v<Integral>
consteval Integral factorial(Integral n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

} // namespace sf::recursive

} // namespace sf

#endif // NEVERMORE_ALGORITHM_NUMERIC_H
