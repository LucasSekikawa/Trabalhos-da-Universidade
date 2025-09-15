Visão Geral do Projeto

Este projeto, referente ao trabalho prático de CH001, tem como objetivo a implementação de um Tipo Abstrato de Dados (TAD) para números racionais na linguagem C. O trabalho é dividido em módulos, enfatizando a separação entre a interface (definição do TAD) e a implementação.

Estrutura dos Arquivos

    racional.h: Este é o arquivo de cabeçalho que define a interface do TAD Racional. Ele contém as definições de estruturas e os protótipos das funções que manipulam os dados, mas não a sua implementação. Não deve ser modificado.

    racional.c: Contém a implementação das funções declaradas em racional.h. É neste arquivo que a lógica para operações com números racionais é desenvolvida.

    tp1.c: O arquivo principal que contém a função main(). Ele usa o TAD Racional (definido em racional.h e implementado em racional.c) para realizar as operações propostas no trabalho.

    Makefile: Arquivo responsável por automatizar o processo de compilação do projeto. Ele permite compilar o código de forma simples e otimizada, gerando o executável tp1.
