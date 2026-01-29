#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& human, std::string artifact_name)
    {
        human.possession=std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts (std::unique_ptr<artifact>& item1, std::unique_ptr<artifact>& item2)
    {
        std::unique_ptr<artifact> exchange=std::move(item1);
        item1=std::move(item2);
        item2=std::move(exchange);
    }

    void manifest_power(human& human, std::string power_name)
    {
        auto new_power= std::make_shared<power>(power_name);
        human.own_power=new_power;
    }

    void use_power(human& caster, human& target)
    {
        target.influenced_by=caster.own_power;
    }

    int power_intensity(human& human)
    {
        if (human.own_power == nullptr)
        {
            return 0;
        }
        int result=human.own_power.use_count();
        return result;
    }
    
}  // namespace troy
