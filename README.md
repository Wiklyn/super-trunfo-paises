# Super Trunfo "Países"

Este projeto implementa funcionalidades exigidas por uma disciplina da
faculdade.

## Objetivos

### Registro de cartas

O programa deverá solicitar ao usuário que insira, uma a uma, as propriedades
das cartas. As seguintes propriedades serão solicitadas ao usuário:

- Estado, do tipo `char`.
- Código da carta, do tipo `char*`.
- Nome da cidade, do tipo `char*`.
- População, do tipo `long int`.
- Área, do tipo `float`, em pessoas/km?.
- PIB, do tipo `float`.
- Número de pontos turísticos, do tipo `int`.

Após receber os valores solicitados, o programa irá calcular as seguintes
propriedades extras:

- Densidade populacional, do tipo `float`, calculada como a razão entre
População e Área.
- PIB per capita, do tipo `float`, calculada como a razão entre PIB e População.
Essa propriedade deve ser exibida com zero casas decimais.
- Super poder, do tipo `float`, calculada como a soma do inverso da densidade
populacional com todas as outras propriedades de valores numéricos.

### Registro de duas cartas e comparação da propriedade "População"

O programa deverá solicitar ao usuário que insira, uma a uma, as propriedades
de duas cartas. Após receber os dados das duas cartas, o programa deverá
comparar os seus valores de "População" e exibir na tela o resultado da
comparação.

### Registro de duas cartas e comparação de uma propriedade numérica escolhida pelo usuário

O programa deverá solicitar ao usuário que insira, uma a uma, as propriedades
de duas cartas. Após receber os dados das duas cartas, o programa deverá
solicitar ao usuário a propriedade que deverá ser comparada. Então o programa
executa a comparação e exibe o resultado.

### Registro de duas cartas e comparação da soma de duas propriedades numéricas escolhidas pelo usuário

O programa deverá solicitar ao usuário que insira, uma a uma, as propriedades
de duas cartas. Após receber os dados das duas cartas, o programa deverá
solicitar ao usuário quais duas propriedades, uma a uma, deverão ser somadas e
ter o resultado das somas comparados. Então o programa executa a comparação e
exibe o resultado.

### Registro de duas cartas e comparação de todas as propriedades numéricas

O programa deverá solicitar ao usuário que insira, uma a uma, as propriedades
de duas cartas. Após receber os dados das duas cartas, o programa deverá
realizar a comparação de todas as propriedades numéricas, uma a uma, e exibir na
tela o resultado de cada uma das comparações.
