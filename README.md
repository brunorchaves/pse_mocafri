# 🌡️🖪 MoCaFri – Monitoramento de Temperatura e Porta com Arduino IoT Cloud + Telegram

Este projeto implementa um sistema de monitoramento de **temperatura** e **estado de porta** utilizando a **Arduino IoT Cloud** e envio de **notificações via Telegram**.

---

## 📌 Funcionalidades

- 📡 Envio de dados de temperatura e estado da porta para a [Arduino IoT Cloud](https://create.arduino.cc/cloud).
- 🌡️ Leitura da temperatura via sensor **DS18B20**.
- 🖪 Verificação se a porta está aberta por tempo excessivo.
- 🔔 Envio automático de **alertas via Telegram** em caso de:
  - Temperatura fora do intervalo permitido;
  - Porta aberta por tempo superior ao limite.
- 🔦 Pisca-LED a cada segundo como indicador de funcionamento.

---

## 🛠️ Hardware Utilizado

- Placa compatível com Arduino + Wi-Fi (ex: ESP8266, MKR WiFi 1010, etc.)
- Sensor de temperatura **DS18B20**
- Micro switch para detecção da porta
- LED indicador
- Conexão com a Internet

---

## 📁 Estrutura do Projeto

```
PSE_MOCAFRI/
├── MoCaFri_scketch/
│   ├── MoCaFri_scketch.ino        # Código principal
│   ├── arduino_secrets.h          # Define Wi-Fi, Bot Token e Chat ID
│   ├── thingProperties.h          # Definições da Arduino IoT Cloud
│   └── sketch.json                # Metadados do projeto
├── README.md                      # Este arquivo
└── ReadMe.adoc                    # Alternativa em AsciiDoc
```

---

## ⚙️ Como Funciona

1. A função `loop()`:
   - Atualiza os dados na IoT Cloud.
   - Verifica se a porta está aberta e há quanto tempo.
   - Lê a temperatura do sensor.
   - Gera alertas via Telegram caso:
     - Porta fique aberta mais do que `MAX_DOOR_TIME_SEC`;
     - Temperatura ultrapasse os limites definidos (`MIN_TEMPERATURE`, `MAX_TEMPERATURE`).

2. O LED pisca a cada segundo como indicador de vida do sistema.

3. O arquivo `arduino_secrets.h` deve conter:
   ```cpp
   #define SECRET_SSID "SEU_WIFI"
   #define SECRET_PASS "SENHA_WIFI"
   #define BOT_TOKEN    "SEU_TOKEN_DO_BOT"
   #define CHAT_ID      "SEU_CHAT_ID"
   ```

---

## 🧺as Variáveis da IoT Cloud

- `temperatura` (somente leitura): mostra a temperatura atual em °C.
- `portaAberta` (somente leitura): indica se a porta está aberta (`true`) ou fechada (`false`).

---

## 📲 Integração com Telegram

Certifique-se de:

- Criar um bot no Telegram com o [@BotFather](https://t.me/BotFather);
- Obter o `BOT_TOKEN` e `CHAT_ID`;
- Adicionar o certificado `TELEGRAM_CERTIFICATE_ROOT` se necessário para HTTPS.

---

## 👨‍💻 Autores

**Bruno Ribeiro Chaves**  
**André ---**
**Alysson ---**

Departamento de Engenharia Elétrica – UFMG  
2025