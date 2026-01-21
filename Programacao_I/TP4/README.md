# Visão Geral do Projeto

O objetivo central deste trabalho é a implementação completa de um Tipo Abstrato de Dados (TAD) para uma **Lista Encadeada**. O projeto foca na consolidação de conceitos fundamentais como alocação dinâmica de memória, manipulação rigorosa de ponteiros e o uso da ferramenta **Valgrind** para garantir a integridade do programa, assegurando que não ocorram vazamentos de memória (memory leaks) ou acessos inválidos.

## Estrutura dos Arquivos

* **lista.h**: Arquivo de cabeçalho que define a interface do TAD Lista, contendo as estruturas de dados e os protótipos de todas as funções de manipulação.
* **lista.c**: Arquivo de implementação onde reside a lógica de criação, inserção, remoção, busca e destruição da lista encadeada.
* **tp4.c**: Programa de teste principal utilizado para validar as funções da biblioteca e verificar o comportamento da lista em diferentes cenários.
* **makefile**: Script de automação para compilação do executável seguindo os parâmetros rígidos de flags exigidos.
* **testa.sh**: Script de teste automatizado que compara a saída do programa com os resultados esperados e realiza a análise de memória.

## Project Overview

This is the fourth practical assignment (TP4) for the **CI1001 - Programming 1** course at **UFPR**. The main objective is to implement a **Linked List** Abstract Data Type (ADT). The project emphasizes core computer science concepts such as dynamic memory allocation, complex pointer manipulation, and the professional use of **Valgrind** to ensure a robust implementation free of memory leaks or invalid memory accesses.

## File Structure

* **lista.h**: The header file defining the List ADT interface, including data structures and all function prototypes.
* **lista.c**: The implementation file containing the core logic for linked list operations such as initialization, insertion, deletion, searching, and memory cleanup.
* **tp4.c**: The main test program used to validate the library functions and verify the list's behavior under various conditions.
* **makefile**: A script to automate the compilation process, ensuring the project is built with the mandatory compiler flags.
* **testa.sh**: A shell script for automated testing that compares program output against expected results and performs memory analysis.

## Compilation and Execution

The project must be compiled using the provided `makefile`.
