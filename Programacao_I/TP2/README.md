Visão Geral do Projeto

Este projeto tem como objetivo principal a 

modificação e adaptação de um Tipo Abstrato de Dados (TAD) para números racionais na linguagem C.

O foco é adaptar as funções para que recebam parâmetros 

por endereço (ponteiros). Essa técnica é utilizada para que o 

retorno da função possa ser usado para sinalizar um código de erro.

Estrutura dos Arquivos

Os arquivos fornecidos e implementados para a solução do TAD Racional são:

racional.h: É o arquivo de cabeçalho (read only) que define a interface do TAD Racional. Ele contém os protótipos das funções que manipulam os números racionais. 

Não deve ser alterado.

racional.c: Contém a implementação das funções declaradas em racional.h. É neste arquivo que a lógica das operações com números racionais é desenvolvida.

tp2.c: O arquivo principal que contém a função main(). Ele implementa o pseudo-código do trabalho, que inclui leitura, eliminação de inválidos, ordenação e soma de racionais.

makefile: Arquivo responsável por automatizar o processo de compilação do projeto. Ele permite gerar o executável 
