# **Visão Geral do Projeto**

Este projeto tem como objetivo principal a modificação e adaptação de um Tipo Abstrato de Dados (TAD) para números racionais na linguagem C. O foco é adaptar as funções para que recebam parâmetros por endereço (ponteiros). Essa técnica é utilizada para que o 
retorno da função possa ser usado para sinalizar um código de erro.

## Estrutura dos Arquivos

* racional.h: É o arquivo de cabeçalho (read only) que define a interface do TAD Racional. Ele contém os protótipos das funções que manipulam os números racionais. 

* racional.c: Contém a implementação das funções declaradas em racional.h. É neste arquivo que a lógica das operações com números racionais é desenvolvida.

* tp2.c: Contém a função main() que implementa o programa principal. Sua responsabilidade é gerenciar o vetor de racionais, ler os dados de entrada, eliminar os elementos inválidos, ordenar o vetor resultante e, por fim, calcular a soma de todos os elementos, imprimindo o resultado em cada etapa conforme o pseudo-código especificado.

* makefile: Arquivo responsável por automatizar o processo de compilação do projeto. Ele permite gerar o executável
  
* entrada*.txt: Estes arquivos contêm dados de teste pré-definidos usados para verificar a saída do programa. O programa é testado usando redirecionamento de entrada (./tp2 < entrada1.txt) para simular a leitura dos números racionais.

---


# **Project Overview**

This project's main goal is to use and modify an Abstract Data Type (ADT) for rational numbers in C language. The ideia is to adapt the functions to receive parameters for reference (pointers). This technic is used so that the funcition's return value can signal an error code.

## File Structure

* racional.h: This is the read-only header that defines the interface for the rational ADT. It contains the prototypes of the functions that manipulate the rational numbers.

* racioanl.c: Contains the implementation of the functions declared in racional.h. It's in this file that the logic for operations with rational numbers is developed.

* tp2.c: Contains the main() function that implements the primary program. Its responsability is to manage the array of rationals, read the input data, remove invalid elements, sort the array, and, finally, calculate the sum of all elements, printing the result at each stage according to the specified pseudo-code.
* makefile: File responsible for automating the project's the compilation process. It allows the code to be compiled simply and optimally, generating the executable.
* entrada*.txt: These files contain pre-defined test data used to check the program's output. The program is tested using input redirection (./tp2 < entrada1.txt) to simulate user input for the rational numbers.
