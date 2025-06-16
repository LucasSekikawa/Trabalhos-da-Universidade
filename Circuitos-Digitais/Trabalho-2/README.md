# Simulação de Seta de Carro com Máquina de Estados

## Descrição do Projeto

Este projeto tem como objetivo simular o funcionamento do sistema de seta (pisca) de um carro, conforme encontrado em veículos reais, utilizando uma máquina de estados finita (FSM), podendo ser do tipo **Moore** ou **Mealy**.

### Comportamento Esperado

- Se o motorista **der um toque rápido** no botão da seta (esquerda ou direita), a respectiva seta **pisca exatamente 3 vezes**.
- Se o motorista **mantiver o botão pressionado por mais de um ciclo**, a seta correspondente deve **piscar continuamente**, até que o botão seja solto.

> **Nota:** Não é necessário considerar o caso em que os dois botões (esquerda e direita) são pressionados ao mesmo tempo, pois isso não ocorre em veículos reais.

##  Implementação

A lógica foi implementada por meio de uma máquina de estados finita (FSM), controlando os sinais das setas com base no estado atual e nas entradas dos botões.

- O sistema detecta toques curtos e longos usando lógica de temporização e controle de borda.
- O número de piscadas foi controlado por contadores de estado.
- Foram utilizados **flip-flops JK** para armazenamento de estados e lógica combinacional para transições.

## Ferramentas

- Simulador [Digital](https://github.com/hneemann/Digital)
- Projeto desenvolvido com flip-flops e lógica digital




----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Car Turn Signal Simulation Using a Finite State Machine

## Project Description

This project simulates the behavior of a car's turn signal system, commonly found in real vehicles, using a finite state machine (FSM), which can be either of the **Moore** or **Mealy** type.

### Expected Behavior

- If the driver **briefly taps** the turn signal button (left or right), the corresponding turn signal **blinks exactly 3 times**.
- If the driver **holds the button for more than one cycle**, the turn signal **keeps blinking continuously** until the button is released.

> **Note:** It is not necessary to handle the case where both turn signal buttons (left and right) are pressed at the same time, as this is not possible in real vehicles.

## Implementation

The logic was implemented using a finite state machine (FSM) to control the blink behavior based on the current state and the button inputs.

- Short vs. long presses are detected through timing logic and edge detection.
- The number of blinks is managed using state-based counters.
- **JK flip-flops** were used for state storage, along with combinational logic for state transitions.

## Tools

- [Digital Simulator](https://github.com/hneemann/Digital)
- Project developed using flip-flops and digital logic


