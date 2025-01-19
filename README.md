# Controle de Pinos GPIO com BitDogLab

## Sumário
- [Descrição](#descrição)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Componentes Utilizados](#componentes-utilizados)
- [Objetivos](#objetivos)
- [Passos para Implementação](#passos-para-implementação)
- [Instruções de Uso](#instruções-de-uso)
- [Testes](#testes)
  - [1. Acionamento Individual dos LEDs](#1-acionamento-individual-dos-leds)
  - [2. Acionamento de Todos os LEDs Simultaneamente](#2-acionamento-de-todos-os-leds-simultaneamente)
  - [3. Desligamento dos LEDs](#3-desligamento-dos-leds)
  - [4. Acionamento do Buzzer](#4-acionamento-do-buzzer)
- [Vídeo Ensaio](#vídeo-ensaio)
- [Formação da Equipe](#formação-da-equipe)
- [Licença](#licença)


## Descrição

Este projeto utiliza a ferramenta educacional **BitDogLab** para o controle de pinos GPIO de um microcontrolador **RP2040**. O sistema permite o acionamento de LEDs RGB e um buzzer por meio de comandos enviados pela interface serial UART.

## Funcionalidades Implementadas

1. Controle de LEDs RGB:
   - **Comando 'G'**: Liga o LED verde (GPIO 11).
   - **Comando 'B'**: Liga o LED azul (GPIO 12).
   - **Comando 'R'**: Liga o LED vermelho (GPIO 13).
   - **Comando 'W'**: Liga todos os LEDs (branco).
   - **Comando 'O'**: Desliga todos os LEDs.

2. Controle do Buzzer:
   - **Comando 'Z'**: Ativa o buzzer por 2 segundos.

3. Gerenciamento do Sistema:
   - **Comando 'Q'**: Reinicia o sistema para habilitar o modo de gravação.

## Componentes Utilizados

- **Ferramenta Educacional BitDogLab (versão 6.3)**.
- **Microcontrolador RP2040** (Raspberry Pi Pico ou similar).
- **LED RGB** conectado aos GPIOs 11, 12 e 13.
- **Buzzer** conectado ao GPIO 21.
- **Computador pessoal** para envio de comandos via terminal.
- **Software de Emulação de Terminal** (e.g., PuTTY).


## Objetivos

1. Acionar os LEDs RGB individualmente ou simultaneamente.
2. Emitir sinal sonoro através do buzzer.
3. Implementar comunicação UART para controle via terminal.

## Passos para Implementação

1. **Configuração do Ambiente de Desenvolvimento**:
   - Instale o VS Code e o **Pico SDK**.

2. **Configuração dos GPIOs**:
   - Inicialize os GPIOs para LEDs e buzzer.
   - Configure o PWM para controle do buzzer.

3. **Leitura de Comandos UART**:
   - Desenvolva a rotina para interpretar comandos recebidos via UART.

4. **Controle de Periféricos**:
   - Programe funções para ligar/desligar LEDs e acionar o buzzer.

5. **Versionamento**:
   - Crie um repositório no GitHub e configure os branches para cada integrante da equipe.

## Instruções de Uso

1. **Clonar o Repositório**:
   ```bash
   git clone https://github.com/ferreiiratech/embarcatech-subgrupo-06-u4-microcontroladores-atividade-2.git
   ```

2. **Compilar e Carregar o Código**:
   No VS Code, configure o ambiente e compile o projeto com os comandos:
     ```bash
     cmake -G Ninja ..
     ninja
     ```

3. **Interação com o Sistema**:
   - Conecte a placa ao computador.
   - Envie comandos via terminal para controlar os LEDs e o buzzer.

## Testes

### 1. Acionamento Individual dos LEDs

**Descrição**: Verificar o funcionamento individual dos LEDs RGB.  
**Passos**:  
- Envie o comando `G` para ligar o LED verde.  
- Envie o comando `B` para ligar o LED azul.  
- Envie o comando `R` para ligar o LED vermelho.  
**Resultado Esperado**: Cada LED deve acender conforme o comando recebido.

### 2. Acionamento de Todos os LEDs Simultaneamente

**Descrição**: Verificar o funcionamento dos LEDs RGB em conjunto.  
**Passos**:  
- Envie o comando `W` para acender todos os LEDs.  
**Resultado Esperado**: Todos os LEDs devem acender, formando uma luz branca.

### 3. Desligamento dos LEDs

**Descrição**: Verificar se todos os LEDs podem ser desligados.  
**Passos**:  
- Envie o comando `O` para desligar todos os LEDs.  
**Resultado Esperado**: Todos os LEDs devem apagar.

### 4. Acionamento do Buzzer

**Descrição**: Verificar se o buzzer emite som corretamente.  
**Passos**:  
- Envie o comando `Z` para ativar o buzzer.  
**Resultado Esperado**: O buzzer deve emitir som por 2 segundos.

## Vídeo Ensaio

O vídeo demonstrando o funcionamento do projeto pode ser acessado [aqui]().

## Formação da Equipe

- **Líder do Projeto**: [Seu Nome]  
- **Desenvolvedores**:  
  - Yasmin Cordeiro de Souza Meira
  - [Nome 2]  
  - [Nome 3]  


## Licença

Este projeto está licenciado sob a licença MIT.

