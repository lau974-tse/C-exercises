#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* men_sensor)
    {
        if (men_sensor != nullptr)
        {
            return true;
        }
        return false;
    }
int activity_counter(pillar_men_sensor* men_sensor,int capacity)
    {
        int resultat = 0;
        for (int i = 0; i<capacity; i++)
            {
                resultat+=(men_sensor + i)->activity;
            }
        return resultat;
    }
bool alarm_control(pillar_men_sensor* men_sensor)
    {
        if (men_sensor == nullptr)
        {
            return false;
        }
        if (men_sensor->activity>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
bool uv_alarm(pillar_men_sensor* men_sensor)
    {
        if (men_sensor == nullptr)
        {
            return false;
        }
        int uv_index = uv_light_heuristic(&men_sensor->data);
        if (uv_index>men_sensor->activity)
        {
            return true;
        }
        return false;
    }

}  // namespace speedywagon
