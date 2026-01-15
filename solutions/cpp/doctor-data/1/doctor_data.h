#pragma once
#include <string>

namespace star_map {

enum class System {
    BetaHydri,
    Sol,
    AlphaCentauri,
    DeltaEridani,
    EpsilonEridani,
    Omicron2Eridani
};

}

namespace heaven {

class Vessel {
public:
    Vessel(std::string name, int generation);
    Vessel(std::string name, int generation, star_map::System system);

    Vessel replicate(std::string new_name);

    void make_buster();
    bool shoot_buster();
    std::string name_;
    
public:
    int generation;
    star_map::System current_system;
    int busters{0};


};

std::string get_older_bob(const Vessel& v1, const Vessel& v2);
bool in_the_same_system(const Vessel& v1, const Vessel& v2);

}
