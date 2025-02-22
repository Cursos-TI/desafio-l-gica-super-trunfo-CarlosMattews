# Jogo de Comparacao de Cartas de Cidades

Este programa permite cadastrar e comparar cartas contendo informações sobre cidades. As cartas possuem atributos como população, área, PIB, densidade populacional e PIB per capita. O jogador escolhe dois atributos para comparar e determina qual cidade vence.

## Como Compilar e Executar o Programa

### Requisitos:
- Compilador C (como `gcc`)
- Terminal para execução

### Compilação:
Abra o terminal e execute o seguinte comando:
```sh
gcc -o logicaSuperTrunfo logicaSuperTrunfo.c
```

### Execução:
Após compilar, execute o programa com:
```sh
./logicaSuperTrunfo
```

## Como Usar
1. O programa solicita os dados para cadastrar duas cartas de cidades.
2. O jogador escolhe dois atributos para comparar entre as cidades.
3. O programa calcula e exibe os valores dos atributos escolhidos para ambas as cidades.
4. A cidade com a maior soma dos atributos escolhidos é declarada vencedora.

## Atributos Disponíveis para Comparacão
1. População
2. Área (km²)
3. PIB (em milhões)
4. Densidade Populacional (população / área)
5. PIB per Capita (PIB / população)

## Exemplo de Uso

### Entrada do Usuário:
```
Cadastro da Carta 1:
Digite o estado: SP
Digite o código da carta: 001
Digite o nome da cidade: São Paulo
Digite a população: 12300000
Digite a área (km²): 1521.11
Digite o PIB (em milhões): 699000
Digite o número de pontos turísticos: 50

Cadastro da Carta 2:
Digite o estado: RJ
Digite o código da carta: 002
Digite o nome da cidade: Rio de Janeiro
Digite a população: 6748000
Digite a área (km²): 1200.27
Digite o PIB (em milhões): 364000
Digite o número de pontos turísticos: 80

Escolha um atributo:
1. População
2. Área
3. PIB
4. Densidade Populacional
5. PIB per Capita
Escolha uma opção: 1

Escolha um atributo:
1. População
2. Área
3. PIB
4. Densidade Populacional
5. PIB per Capita
Escolha uma opção: 3
```

### Saída Esperada:
```
Comparacao de cartas:
População: 12300000.00 vs 6748000.00
PIB: 699000.00 vs 364000.00

Soma dos atributos:
São Paulo: 123699000.00
Rio de Janeiro: 6753648000.00

Vencedor: Rio de Janeiro!
```

## Autor
Carlos Mateus

