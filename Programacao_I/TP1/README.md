# **Visão Geral do Projeto**

Este projeto tem como objetivo a implementação de um Tipo Abstrato de Dados (TAD) para números racionais na linguagem C. O trabalho é dividido em módulos, enfatizando a separação entre a interface (definição do TAD) e a implementação.

## Estrutura dos Arquivos

* racional.h: Este é o arquivo de cabeçalho que define a interface do TAD Racional. Ele contém as definições de estruturas e os protótipos das funções que manipulam os dados, mas não a sua implementação.

* racional.c: Contém a implementação das funções declaradas em racional.h. É neste arquivo que a lógica para operações com números racionais é desenvolvida.

* tp1.c: O arquivo principal que contém a função main(). Ele usa o TAD Racional (definido em racional.h e implementado em racional.c) para realizar as operações propostas no trabalho.

* Makefile: Arquivo responsável por automatizar o processo de compilação do projeto. Ele permite compilar o código de forma simples e otimizada, gerando o executável tp1.

---

# **Project Overview**

This project involves implementing an Abstract Data Type (ADT) for rational numbers in the C programming language. The main goal is to practice modular programming by separating the ADT's interface from its implementation.

## File Structure

* racional.h: This is the header file that defines the Rational ADT's interface. It contains the structure definitions and function prototypes, but no implementation. 

* racional.c: This file provides the implementation for the functions declared in racional.h. This is where the core logic for all rational number operations is developed.

* tp1.c: This is the main file containing the main() function. It uses the Rational ADT to perform the required operations.

* Makefile: A utility file that automates the compilation of the project, simplifying the process of building the tp1 executable.
