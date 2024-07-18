#include "nevermore/Converter.h"

#include <string>
#include <array>

namespace sf {

struct ArabicToRomanMapping{
    unsigned arabic_number;
    std::string roman_numeral;
};

std::string convert_arabic_to_roman_numeral(unsigned arabic_number)
{
    static std::array<ArabicToRomanMapping, 13> arabic_to_roman_mappings =
        {
            ArabicToRomanMapping{ 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" }
        };

    std::string roman_numeral{};

    for (const auto& [arabic_number_unit, roman_numeral_digit]: arabic_to_roman_mappings) {
        while (arabic_number >= arabic_number_unit) {
            roman_numeral += roman_numeral_digit;
            arabic_number -= arabic_number_unit;
        }
    }

    return roman_numeral;
}

} // namespace sf
