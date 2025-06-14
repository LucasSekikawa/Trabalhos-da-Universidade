# Trabalho 1 – ALU (Unidade Lógica e Aritmética)

Este trabalho consiste na implementação de um circuito para uma ALU (Unidade Lógica e Aritmética) capaz de realizar quatro operações com dois operandos de 6 bits: **soma, subtração, comparação e multiplicação**.

## Funcionalidades

- **Entradas:**
  - 'A' (6 bits)
  - 'B' (6 bits)
  - 'O' (2 bits) → código da operação

- **Saídas:**
  - 'S' (resultado, 6 ou 8 bits dependendo da operação)
  - 'F' (1 bit) → indica overflow ou erro na multiplicação

## 🔧 Operações suportadas

| Código 'O' | Operação     | Descrição                                                                 |
|------------|--------------|---------------------------------------------------------------------------|
| '00'       | Soma         | S = A + B (com overflow indicado por F)                                   |
| '01'       | Subtração    | S = A − B                                                                 |
| '10'       | Comparação   | S = 000001 se A = B, ou S = 000000 se A ≠ B                               |
| '11'       | Multiplicação| Usa apenas os 4 primeiros bits de A e B; se bits 4 ou 5 forem 1 → F = 1   |

Para multiplicação, o resultado `S` possui **8 bits** e a operação só considera números **naturais (sem sinal)**.

## Restrições

- Somente **portas lógicas simples** permitidas: AND, OR, NOT, NAND, NOR, XOR e XNOR.
- Valores negativos devem estar representados em **complemento de 2**.
- Multiplicações com bits altos ativados devem ser sinalizadas com `F = 1`.





------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Assignment 1 – ALU (Arithmetic Logic Unit)

This assignment consists of implementing a circuit for an ALU (Arithmetic Logic Unit) capable of performing four operations with two 6-bit operands: **addition, subtraction, comparison, and multiplication**.

## Features

- **Inputs:**
  - 'A' (6 bits)
  - 'B' (6 bits)
  - 'O' (2 bits) → operation selector

- **Outputs:**
  - 'S' (result, 6 or 8 bits depending on the operation)
  - 'F' (1 bit) → indicates overflow or error during multiplication

## 🔧 Supported Operations

| Code 'O' | Operation    | Description                                                                 |
|----------|--------------|-----------------------------------------------------------------------------|
| '00'     | Addition     | S = A + B (with overflow indicated by F)                                   |
| '01'     | Subtraction  | S = A − B                                                                   |
| '10'     | Comparison   | S = 000001 if A = B, or S = 000000 if A ≠ B                                 |
| '11'     | Multiplication | Uses only the lower 4 bits of A and B; if bits 4 or 5 are set → F = 1     |

> For multiplication, the output `S` has **8 bits** and only **non-negative (unsigned)** numbers are allowed.

##  Constraints

- Only **basic logic gates** are allowed: AND, OR, NOT, NAND, NOR, XOR, and XNOR.
- Negative values must be represented using **two’s complement**.
- Multiplications where the higher bits are set must trigger `F = 1` to signal an error.
