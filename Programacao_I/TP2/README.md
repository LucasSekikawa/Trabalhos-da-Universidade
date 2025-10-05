# **Visão Geral do Projeto**

Este projeto tem como objetivo principal a modificação e adaptação de um Tipo Abstrato de Dados (TAD) para números racionais na linguagem C. O foco é adaptar as funções para que recebam parâmetros por endereço (ponteiros). Essa técnica é utilizada para que o 
retorno da função possa ser usado para sinalizar um código de erro.

## Estrutura dos Arquivos

* racional.h: É o arquivo de cabeçalho (read only) que define a interface do TAD Racional. Ele contém os protótipos das funções que manipulam os números racionais. 

* racional.c: Contém a implementação das funções declaradas em racional.h. É neste arquivo que a lógica das operações com números racionais é desenvolvida.

* tp2.c: Contém a função main() que implementa o programa principal. Sua responsabilidade é gerenciar o vetor de racionais, ler os dados de entrada, eliminar os elementos inválidos, ordenar o vetor resultante e, por fim, calcular a soma de todos os elementos, imprimindo o resultado em cada etapa conforme o pseudo-código especificado.

* makefile: Arquivo responsável por automatizar o processo de compilação do projeto. Ele permite gerar o executável 
