# GS-EcoPowerIOT

# Projeto EcoPower - Monitoramento de Energia

## Descrição
Este projeto utiliza o ESP32 para monitoramento de consumo de energia em tempo real. O ESP32 coleta dados simulados de corrente e tensão e envia os valores para um broker MQTT.

## Estrutura do Projeto
- **wifi-scan.ino**: Código principal do ESP32, que conecta ao Wi-Fi e ao Broker MQTT.
- **README.md**: Instruções e detalhes sobre o projeto.
- **Outros arquivos**: Arquivos de configuração do MQTT e informações adicionais.

## Como Configurar
1. **Configuração do Wi-Fi**: Substitua as credenciais de Wi-Fi no código pelo seu SSID e senha.
2. **Broker MQTT**: O projeto utiliza o broker público "broker.hivemq.com". Se preferir, use seu próprio broker.
3. **Simulação**: O projeto pode ser simulado utilizando o Wokwi. [Link para a simulação no Wokwi].

## Dependências
- Biblioteca `PubSubClient` para comunicação MQTT.
- Biblioteca `WiFi.h` para gerenciamento de conexão Wi-Fi.

## Como Rodar
1. Abra o código no Arduino IDE.
2. Configure as credenciais de Wi-Fi.
3. Faça upload do código para o ESP32.
4. Monitore os dados via MQTT com ferramentas como MQTT Explorer ou um cliente MQTT de sua preferência.

## Impacto Esperado
- **Ecológico**: Otimização do consumo de energia e redução da pegada de carbono.
- **Social**: Incentivo ao consumo consciente e educação sobre o uso eficiente de energia.
- **Econômico**: Economia nas contas de energia e redução do desperdício.

