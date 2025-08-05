# Alimentador Automático para Animais com ESP32

Este projeto consiste no desenvolvimento de um **alimentador automático para animais de estimação**, controlado por um microcontrolador **ESP32**. A alimentação é liberada automaticamente sempre que o sensor infravermelho detectar a presença do animal, respeitando um intervalo mínimo de tempo entre ativações para evitar excesso de alimentação.

## 🛠 Funcionalidades

- Detecção de presença por **sensor infravermelho** (IR)
- Ação de liberação de ração através de **servo motor**
- Controle de intervalo mínimo entre ativações (**5 minutos**)
- Número configurável de rotações do servo motor
- Sistema ideal para protótipos de alimentadores automáticos

## ⚙️ Componentes Utilizados

- ESP32 DevKit
- Sensor Infravermelho (IR)
- Servo motor (compatível com PWM)
- Jumpers e protoboard (ou circuito integrado)
- Fonte de alimentação adequada para o servo

## 📁 Estrutura do Projeto

- `Alimentador_Paula.ino`: Código principal com toda a lógica de controle do alimentador.

## 📦 Instalação

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```

2. Abra o arquivo `Alimentador_Paula.ino` no **Arduino IDE**.

3. Instale a biblioteca necessária:
   - `ESP32Servo` (pode ser instalada diretamente pela Arduino IDE)

4. Faça o upload para sua placa **ESP32**.

## 📋 Como Funciona

1. Ao energizar o sistema, o ESP32 inicia a leitura do sensor IR.
2. Se a presença de um animal for detectada, o código verifica se já se passaram 5 minutos desde a última liberação.
3. Se sim, o servo motor gira um número específico de vezes, liberando uma quantidade predeterminada de ração.
4. O tempo da última ativação é atualizado e o sistema aguarda a próxima aproximação.

## 📌 Observações

- A quantidade de ração liberada pode ser ajustada modificando a constante `ROTACAO` no código.
- Certifique-se de fornecer alimentação suficiente para o servo motor.

## 📜 Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.

---

Desenvolvido para fins acadêmicos e prototipagem. Ideal para estudantes e makers interessados em automação para pets.
