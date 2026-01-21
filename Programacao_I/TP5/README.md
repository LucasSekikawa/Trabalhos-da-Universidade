# Visão Geral do Projeto

O objetivo deste trabalho é a implementação de um Tipo Abstrato de Dado (TAD) para uma **Fila de Prioridades** utilizando uma lista encadeada simples. A fila deve ser **genérica**, armazenando ponteiros (`void *`) para qualquer tipo de dado. Os itens são mantidos ordenados de acordo com prioridades crescentes, uma estrutura fundamental para sistemas como a **Lista de Eventos Futuros (LEF)** em simulações.

## Estrutura dos Arquivos

* **fprio.h**: Arquivo de cabeçalho (read-only) que define a interface da Fila de Prioridades, contendo as estruturas e os protótipos das funções.
* **fprio.c**: Arquivo de implementação contendo a lógica para criação, inserção ordenada por prioridade, remoção do elemento de maior prioridade e destruição da fila.
* **testa-fprio.c**: Programa de teste (read-only) fornecido para validar a implementação através de diversos cenários de uso.
* **makefile**: Script para automação da compilação do executável `tp5`.

## Project Overview

This is the fifth practical assignment (TP5) for the **CI1001 - Programming 1** course at **UFPR**. The goal is to implement a **Priority Queue** Abstract Data Type (ADT) using a singly linked list. The queue is designed to be **generic**, utilizing `void *` pointers to store items of any data type. Elements are automatically kept in ascending order based on their assigned priority/key, which is a critical structure for managing a **Future Event List (LEF)** in simulation environments.

## File Structure

* **fprio.h**: Read-only header file defining the Priority Queue ADT interface, including data structures and function prototypes.
* **fprio.c**: The implementation file where the logic for queue initialization, prioritized insertion, element removal, and memory cleanup is developed.
* **testa-fprio.c**: Read-only test file used to verify the correct behavior of the library through a battery of tests.
* **makefile**: Automation script for compiling the project into the `tp5` executable.

## Compilation and Execution

The project must be compiled using the provided `makefile`.
