#include "city.h"
#include "interface.h"

City* alocate_city()
{
    City *city = (City*) calloc(1, sizeof(City));
    
    if (city == NULL) {
        perror("Erro ao alocar memoria para a cidade em `get_city_data`\n");
        exit(EXIT_FAILURE);
    }

    return city;
}

void register_city(City* city, City* city_in_list)
{
    if (city == NULL) {
        fprintf(stderr, "Erro: ponteiro NULL `city` fornecido para `register_city`.\n");
        exit(EXIT_FAILURE);
    }
    
    if (city_in_list == NULL) {
        perror("Erro: ponteiro NULL `city_in_list` fornecido para `register_city`.\n");
        exit(EXIT_FAILURE);
    }

    city_in_list->state = city->state;

    city_in_list->card_code = calloc(3, sizeof(char));
    strcpy(city_in_list->card_code, city->card_code);

    city_in_list->city_name = calloc(
        (strlen(city->city_name) + 1), sizeof(char)
    );
    if (city_in_list->city_name == NULL) {
        perror("Erro ao alocar memoria para o nome da cidade em `register_city`.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(city_in_list->city_name, city->city_name);

    city_in_list->population_size = city->population_size;
    city_in_list->area = city->area;

    if (city->area != 0)
    {
        city_in_list->population_density = 
            (float)city->population_size / city->area;
    }
    else
    {
        city_in_list->population_density = 0.0;
    }

    city_in_list->gpd = city->gpd;

    if (city->population_size != 0)
    {
        city_in_list->gpd_pc = city->gpd / (float)city->population_size;
    } else
    {
        city_in_list->gpd_pc = 0.0;
    }

    city_in_list->tourist_sites_count = city->tourist_sites_count;

    city_in_list->super_power =
        (float)city_in_list->population_size
        + city_in_list->area
        + (float)1/city_in_list->population_density
        + city_in_list->gpd
        + city_in_list->gpd_pc
        + (float)city_in_list->tourist_sites_count;
}

void free_city(City** city_ref)
{
    if (city_ref == NULL)
        return;

    if (*city_ref == NULL)
        return;

    City *city = *city_ref;

    free(city->card_code);
    free(city->city_name);

    free(city);

    *city_ref = NULL;
}

void free_city_list(City** city_list, int registered_cities_count)
{
    for (int i = 0; i < registered_cities_count; i++) {
        if (city_list[i] != NULL)
            free_city(&city_list[i]);
    }
}

void alocate_cities_to_compare(City* city_list[2])
{
    for (int i = 0; i < 2; i++) {
        city_list[i] = NULL;
    }

    city_list[0] = alocate_city();
    city_list[1] = alocate_city();

    City *first_city = get_one_city_data("primeira");
    register_city(first_city, city_list[0]);

    puts("\nCarta registrada com sucesso.\n");

    City *second_city = get_one_city_data("segunda");
    register_city(second_city, city_list[1]);

    puts("\nCarta registrada com sucesso.");

    print_card_to_compare(city_list[0], 1);
    print_card_to_compare(city_list[1], 2);
}

void compare_population_size(City** city_list)
{
    puts("\nComparação de cartas\n");

    for (int i = 0; i < 2; i++)
    {
        printf(
            "Carta %d - Estado: %c, Código: %s, Populacao: %ld\n",
            i + 1,
            city_list[i]->state,
            city_list[i]->card_code,
            city_list[i]->population_size
        );
    }

    printf(
        "Resultado: Carta %d e a vencedora!",
        city_list[0]->population_size > city_list[1]->population_size ? 1 : 2
    );

    puts("");
}

void compare_one_long_int_property(
    long int first_city_value, long int second_city_value
)
{
    int winner;

    if (first_city_value > second_city_value)
        winner = 1;
    else
    {
        if (first_city_value < second_city_value)
            winner = 2;
        
        else
            winner = 0;
    }

    winner == 0
        ? printf("Houve um empate!")
        : printf("Resultado: Carta %d e a vencedora!", winner);
    
    puts("");
}

void compare_one_float_property(
    float first_city_value, float second_city_value
)
{
    int winner;

    if (first_city_value > second_city_value)
        winner = 1;
    else
    {
        if (first_city_value < second_city_value)
            winner = 2;
        
        else
            winner = 0;
    }

    winner == 0
        ? printf("Houve um empate!")
        : printf("Resultado: Carta %d e a vencedora!", winner);
    
    puts("");
}

void compare_population_density(
    float first_city_value, float second_city_value
)
{
    int winner;

    if (first_city_value > second_city_value)
        winner = 2;
    else
    {
        if (first_city_value < second_city_value)
            winner = 1;
        
        else
            winner = 0;
    }

    winner == 0
        ? printf("Houve um empate!")
        : printf("Resultado: Carta %d e a vencedora!", winner);
    
    puts("");
}

void compare_two_float_properties(
    float first_value_first_city, float second_value_first_city,
    float first_value_second_city, float second_value_second_city
)
{
    int winner;

    if (
        first_value_first_city + second_value_first_city >
        first_value_second_city + second_value_second_city
    )
        winner = 1;
    else
    {
        if (
            first_value_first_city + second_value_first_city <
            first_value_second_city + second_value_second_city
        )
            winner = 2;
        
        else
            winner = 0;
    }

    winner == 0
        ? printf("Houve um empate!")
        : printf("Resultado: Carta %d e a vencedora!", winner);
    
    puts("");
}

void compare_two_long_int_properties(
    long int first_value_first_city, long int second_value_first_city,
    long int first_value_second_city, long int second_value_second_city
)
{
    int winner;
    
    if (
        first_value_first_city + second_value_first_city >
        first_value_second_city + second_value_second_city
    )
        winner = 1;
    else
    {
        if (
            first_value_first_city + second_value_first_city <
            first_value_second_city + second_value_second_city
        )
            winner = 2;
        
        else
            winner = 0;
    }

    winner == 0
        ? printf("Houve um empate!")
        : printf("Resultado: Carta %d e a vencedora!", winner);
    
    puts("");
}

void compare_one_long_int_of_all_properties(
    long int first_property, long int second_property, char* property_name
)
{
    int winner = first_property == second_property
                    ? 0
                    : first_property > second_property
                        ? 1
                        : 2;
    
    printf("Qual carta tem maior %s? ", property_name);
    if (winner == 0)
    {
        printf(
            "Empate! As duas cartas possuem o mesmo valor de %s.", property_name
        );
    }
    else
    {
        printf(
            "%d. Portanto, a carta %d ganhou.",
            winner == 1 ? 1 : 0,
            winner == 1 ? 1 : 2
        );
    }
}

void compare_one_float_of_all_properties(
    float first_property, float second_property, char* property_name
)
{
    int winner = first_property == second_property
                    ? 0
                    : first_property > second_property
                        ? 1
                        : 2;
    
    printf("Qual carta tem maior %s? ", property_name);
    if (winner == 0)
    {
        printf(
            "Empate! As duas cartas possuem o mesmo valor de %s.", property_name
        );
    }
    else
    {
        printf(
            "%d. Portanto, a carta %d ganhou.",
            winner == 1 ? 1 : 0,
            winner == 1 ? 1 : 2
        );
    }
}

void compare_population_density_of_all_properties(
    float first_property, float second_property, char* property_name
)
{
    int winner = first_property == second_property
                    ? 0
                    : first_property > second_property
                        ? 1
                        : 2;
    
    printf("Qual carta tem maior %s? ", property_name);
    if (winner == 0)
    {
        printf(
            "Empate! As duas cartas possuem o mesmo valor de %s.", property_name
        );
    }
    else
    {
        printf(
            "%d. Portanto, a carta %d ganhou.",
            winner == 1 ? 0 : 1,
            winner == 1 ? 2 : 1
        );
    }
}
