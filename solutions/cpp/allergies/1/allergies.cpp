#include "allergies.h"

#include <unordered_map>

namespace allergies {

// Table de correspondance allergène → valeur binaire
static const std::unordered_map<std::string, unsigned int> allergen_values{
    {"eggs", 1},
    {"peanuts", 2},
    {"shellfish", 4},
    {"strawberries", 8},
    {"tomatoes", 16},
    {"chocolate", 32},
    {"pollen", 64},
    {"cats", 128}
};

allergy_test::allergy_test(unsigned int score)
    : score_(score)
{
}

bool allergy_test::is_allergic_to(const std::string& allergen) const
{
    auto it = allergen_values.find(allergen);
    if (it == allergen_values.end()) {
        return false;  // allergène inconnu
    }

    return (score_ & it->second) != 0;
}

std::unordered_set<std::string> allergy_test::get_allergies() const
{
    std::unordered_set<std::string> result;

    for (const auto& [name, value] : allergen_values) {
        if ((score_ & value) != 0) {
            result.emplace(name);
        }
    }

    return result;
}

}  // namespace allergies
