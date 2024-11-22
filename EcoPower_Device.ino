#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SimulacaoSSID";
const char* password = "SimulacaoSenha";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "ecoapp/energy";

WiFiClient espClient;
PubSubClient client(espClient);

const int currentSensorPin = 34;
const int voltageSensorPin = 35;
const int ledPin = 2;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.println("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Conectado ao Wi-Fi!");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  connectMQTT();
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  float current = analogRead(currentSensorPin) / 4095.0 * 30.0;
  float voltage = analogRead(voltageSensorPin) / 4095.0 * 220.0;
  float power = current * voltage;

  char message[100];
  sprintf(message, "{\"current\": %.2f, \"voltage\": %.2f, \"power\": %.2f}", current, voltage, power);

  Serial.print("Enviando dados MQTT: ");
  Serial.println(message);
  client.publish(mqttTopic, message);

  if (power > 100.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(5000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.println(topic);

  Serial.print("Payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void connectMQTT() {
  Serial.println("Conectando ao Broker MQTT...");
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado ao Broker MQTT!");
    } else {
      Serial.print("Falha na conexão. Estado: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}
