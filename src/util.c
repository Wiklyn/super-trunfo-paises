#include "city.h"
#include "card.h"
#include "util.h"

bool is_valid_property(int property)
{
    return property >= PopulationSize && property <= TouristSitesCount;
}

bool is_valid_functionality(int functionality)
{
    return functionality >= RegisterCards
            && functionality <= CompareAllPropertiesStatically;
}
