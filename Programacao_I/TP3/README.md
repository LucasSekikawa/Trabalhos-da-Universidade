# Rational Numbers ADT (Dynamic Allocation) - University Project

Este projeto é o terceiro trabalho prático (TP3) desenvolvido para a disciplina **CI1001 - Programação 1** na **UFPR**, sob a orientação do **Professor Marcos Castilho**.

## Visão Geral do Projeto

O objetivo principal deste trabalho é evoluir o Tipo Abstrato de Dados (TAD) para números racionais desenvolvido anteriormente, focando agora na prática de **alocação dinâmica de memória**. A principal mudança é que as funções do TAD passam a retornar ponteiros para structs alocadas dinamicamente, em vez das structs propriamente ditas. O programa deve gerenciar um vetor de ponteiros, realizar a eliminação de valores inválidos, ordenar os elementos e calcular a soma total, garantindo a liberação correta de toda a memória alocada para evitar vazamentos (memory leaks).

## Estrutura dos Arquivos

* **racional.h**: Arquivo de cabeçalho (read-only) que define a interface do TAD Racional, contendo os protótipos das funções adaptadas para o uso de ponteiros.
* **racional.c**: Contém a implementação da lógica das funções declaradas em `racional.h`, incluindo a alocação e desalocação dinâmica de cada número racional.
* **tp3.c**: Programa principal que implementa a lógica de gerenciamento do vetor de ponteiros, leitura de dados, ordenação e exibição dos resultados conforme o fluxo definido.
* **makefile**: Script para automatizar a compilação do projeto com as flags necessárias.
* **testa.sh**: Script shell fornecido para realizar testes automatizados de lógica e verificar vazamentos de memória usando a ferramenta **Valgrind**.
* **testes/**: Diretório contendo arquivos de entrada e saída esperada para validação do programa.

## Project Overview

The primary goal of this project is to evolve the Rational Numbers Abstract Data Type (ADT) developed in previous assignments, now focusing on **dynamic memory allocation**. The main change is that the ADT functions now return pointers to dynamically allocated structs rather than the structs themselves. The program must manage an array of pointers, eliminate invalid values, sort elements, and calculate a total sum, ensuring proper deallocation of all memory to prevent leaks.

## File Structure

* **racional.h**: The read-only header file defining the Rational ADT interface, containing function prototypes adapted for pointer usage.
* **racional.c**: Contains the implementation of the functions declared in `racional.h`, including the dynamic allocation and deallocation of each rational number.
* **tp3.c**: The main program file that implements the logic for managing the pointer array, data input, sorting, and displaying results according to the specified flow.
* **makefile**: A script to automate the project's compilation process with the required flags.
* **testa.sh**: A shell script provided to perform automated logic tests and verify memory leaks using the **Valgrind** tool.
* **testes/**: A directory containing input and expected output files for program validation.

## Compilation and Execution

The project must be compiled using the provided `makefile`. 
