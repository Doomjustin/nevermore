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

template<typename Integral>
    requires std::is_integral_v<Integral>
consteval Integral fibonacci(Integral n)
{
    if (n <= 1) return n;

    Integral res = 1;
    Integral last_res = 0;

    while (n > 1) {
        auto tmp = last_res;
        last_res = res;
        res += tmp;
        --n;
    }

    return res;
}

namespace recursive {

template<typename Integral>
    requires std::is_integral_v<Integral>
consteval Integral factorial(Integral n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

template<typename Integral>
    requires std::is_integral_v<Integral>
consteval Integral fibonacci(Integral n)
{
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

} // namespace sf::recursive

} // namespace sf

#endif // NEVERMORE_ALGORITHM_NUMERIC_H
