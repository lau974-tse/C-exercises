#include "doctor_data.h"

namespace heaven {

// Constructeur avec système par défaut
Vessel::Vessel(std::string name, int gen)
    : name_(name), generation(gen), current_system(star_map::System::Sol)
{
}

// Constructeur avec système explicite
Vessel::Vessel(std::string name, int gen, star_map::System system)
    : name_(name), generation(gen), current_system(system)
{
}

// Réplication
Vessel Vessel::replicate(std::string new_name)
{
    return Vessel(new_name, generation + 1, current_system);
}

// Fabrique un buster
void Vessel::make_buster()
{
    ++busters;
}

// Tire un buster
bool Vessel::shoot_buster()
{
    if (busters > 0) {
        --busters;
        return true;
    }
    return false;
}

// Retourne le nom du plus ancien
std::string get_older_bob(const Vessel& v1, const Vessel& v2)
{
    if (v1.generation <= v2.generation) {
        return v1.name_;
    }
    return v2.name_;
}

// Même système ?
bool in_the_same_system(const Vessel& v1, const Vessel& v2)
{
    return v1.current_system == v2.current_system;
}

}
