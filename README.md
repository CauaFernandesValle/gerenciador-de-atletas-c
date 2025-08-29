Gerenciador de Atletas em C

Projeto acadêmico para a disciplina Estrutura de Dados
Este repositório contém o código-fonte de uma aplicação de console desenvolvida em Linguagem C. O objetivo do programa é gerenciar dados de treino de atletas, permitindo o cadastro, a listagem e a ordenação com base em múltiplos critérios.

O projeto demonstra a aplicação de conceitos essenciais da programação estruturada, incluindo o uso de structs para modelagem de dados, alocação dinâmica de memória para armazenamento flexível e a implementação de algoritmos de ordenação para a manipulação eficiente dos registros.

Funcionalidades
Inclusão Dinâmica de Atletas: O programa permite que o usuário adicione novos registros de atletas em tempo de execução. Os dados de cada atleta (nome, matrícula e tempo de treino) são armazenados em um vetor de structs que cresce dinamicamente conforme a necessidade.

Exibição com Múltiplos Critérios: Os dados dos atletas podem ser visualizados de diferentes formas:

Ordem de Inclusão: Exibe os atletas na sequência em que foram cadastrados.

Ordem Alfabética: Apresenta uma lista ordenada alfabeticamente pelo nome, com a matrícula como critério de desempate.

Ranking por Tempo: Classifica os atletas do maior para o menor tempo de treino, também utilizando a matrícula para desempate.

Filtragem de Dados: Oferece uma funcionalidade para exibir apenas os atletas cujo tempo de treino seja superior a um limite em minutos informado pelo usuário.

Gerenciamento Eficiente de Memória: Para as operações de ordenação, o programa utiliza um array de ponteiros, evitando a duplicação desnecessária de dados e tornando as trocas de posição mais rápidas e eficientes. Toda a memória alocada dinamicamente é liberada ao final da execução.

Tecnologias e Técnicas Aplicadas
O projeto foi desenvolvido inteiramente em Linguagem C, utilizando as bibliotecas padrão stdio.h, stdlib.h e string.h.

As técnicas aplicadas incluem a alocação dinâmica de memória com malloc e realloc, manipulação de ponteiros e ponteiros para ponteiros, uso de structs para a modelagem de dados, a implementação do algoritmo de ordenação Selection Sort e a manipulação de entrada e saída (I/O) do console.