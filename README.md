# Controle de Servomotor por PWM 

## Sumário

1. 🎯 Objetivos
2. 🛠️ Descrição do Projeto
3. 🚀 Funcionalidades do Projeto
   - 3.1 Configuração do PWM
   - 3.2 Controle de Posição do Servomotor
   - 3.3 Movimentação Contínua
   - 3.4 Experimento com LED RGB
4. ✅ Requisitos do Projeto
5. 🖥️ Configuração do Ambiente
   - 5.1 Instalações Necessárias
6. 🗁 Estrutura do Código
7. 📸 Demonstração do Projeto

## 1. 🎯 Objetivos

- Implementar o controle de um servomotor utilizando PWM no microcontrolador RP2040.
- Configurar a GPIO 22 para gerar sinais PWM com frequência de 50Hz.
- Ajustar o ciclo de trabalho do PWM para controlar os ângulos do servomotor (0°, 90° e 180°).
- Criar uma rotina para movimentação suave do servomotor.
- Realizar um experimento adicional utilizando um LED RGB na GPIO 12.

## 2. 🛠️ Descrição do Projeto

Este projeto foi desenvolvido utilizando a placa **Raspberry Pi Pico W** e os seguintes componentes:

- **Microcontrolador RP2040**
- **Servomotor (micro servo padrão do Wokwi)**
- **LED RGB (GPIO 12)**

A simulação foi realizada no **Wokwi Simulator** e o desenvolvimento no **VS Code** com o **Pico SDK**.

## 3. 🚀 Funcionalidades do Projeto

### 3.1 Configuração do PWM
- A GPIO 22 foi configurada para operar com uma frequência de 50Hz (período de 20ms).

### 3.2 Controle de Posição do Servomotor
- **180°**: PWM com ciclo ativo de **2.400µs** (0,12%). Aguarda **5 segundos**.
- **90°**: PWM com ciclo ativo de **1.470µs** (0,0735%). Aguarda **5 segundos**.
- **0°**: PWM com ciclo ativo de **500µs** (0,025%). Aguarda **5 segundos**.

### 3.3 Movimentação Contínua
- Implementação de uma rotina para movimentação do servomotor entre **0° e 180°**.
- O incremento do ciclo ativo ocorre em **passos de 5µs**, com **atraso de 10ms** para suavizar o movimento.

### 3.4 Experimento com LED RGB
- Utiliza-se a ferramenta **BitDogLab** para testar o código com o **LED RGB na GPIO 12**.
- O comportamento do LED é analisado e documentado.

## 4. ✅ Requisitos do Projeto

- Utilização da biblioteca **Pico SDK** para controle do PWM.
- Simulação do circuito no **Wokwi**.
- Versionamento do código no **GitHub**.
- Implementação de testes básicos.
- Inclusão de um arquivo **README.md** com instruções detalhadas.
- Criação de um **vídeo demonstrativo** da solução.

## 5. 🖥️ Configuração do Ambiente

### 5.1 Instalações Necessárias
- **Pico SDK** instalado.
- **ARM GNU Toolchain**.
- **Visual Studio Code** com extensões:
  - C/C++
  - CMake
  - CMake Tools
  - Raspberry Pi Pico
  - Wokwi Simulator
- **GitHub** para versionamento.

## 6. 🗁 Estrutura do Código

O projeto está organizado da seguinte forma:

- **tarefa2-aula-sincrona-06-02-pwm.c** - Arquivo principal contendo a lógica de controle do servomotor.
- **CMakeLists.txt** - Configuração do build para o Pico SDK.
- **wokwi.toml** - Arquivo de configuração do Wokwi Simulator.
- **diagram.json** - Configuração do layout da simulação.
- **README.md** - Documentação do projeto.

## 7. 📸 Demonstração do Projeto

- **Repositório GitHub**: [Clique aqui](https://github.com/demyshow/tarefa2-aula-sincrona-06-02-pwm)
- **Vídeo de Demonstração**: [Clique aqui](https://drive.google.com/file/d/1XMrPsKvHHQmTYi8pY7kAJD-gizaD0Ok1/view?usp=sharing)

### Instruções para Compilação e Execução

```sh
# Clone o repositório
 git clone https://github.com/demyshow/tarefa2-aula-sincrona-06-02-pwm.git

# Extraia nesta estrutura de projeto
 C:\tarefa2-aula-sincrona-06-02-pwm\tarefa2-aula-sincrona-06-02-pwm

# Compile o código usando o Pico SDK
 mkdir build
 cd build
 cmake ..
 make

# Execute no Raspberry Pi Pico ou no simulador Wokwi
```

Este README fornece uma visão detalhada do projeto, garantindo que qualquer interessado possa replicá-lo de forma clara e objetiva.

