#include "card.h"

#define MAX_CITIES 32

int main()
{
    show_functionalities_menu();

    int chosen_functionality = choose_functionality();

    switch (chosen_functionality)
    {
        case RegisterCards:
            register_cards(MAX_CITIES);
            break;

        case CompareOnePropertyStatically:
            run_one_fixed_property_comparison();
            break;

        case CompareOnePropertyDinamically:
            run_one_property_comparison();
            break;

        case CompareTwoPropertiesDinamically:
            run_two_properties_comparison();
            break;

        case CompareAllPropertiesStatically:
            run_all_properties_comparison();
            break;

        default:
            break;
    }
    
    return 0;
}
