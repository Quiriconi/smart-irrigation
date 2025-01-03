/**
 * @file  main.c
 * @brief Simples sistema de irrigação IoT
 *
 * @warning Projeto utilizando os recursos nativos da Espressif e outras contribuições (Github)
 * @todo Funções de inicialização, leitura, acionamento e envio de dados para nuvem usando Wi-Fi com MQTT
 * @copyright Smart-Irrigation - Luca Quiriconi 2025
*/

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
/*******************************************************************
*   CONFIGS
*******************************************************************/
 
/*******************************************************************
*   DEFINES
*******************************************************************/
#define ESP_BAUD_RATE 115200
/*******************************************************************
*   TYPEDEFS
*******************************************************************/
 
/*******************************************************************
*   GLOBAL VARIABLES
*******************************************************************/
 int broker_port = 1883;

/*******************************************************************
*   CONSTANTS
*******************************************************************/
const char* ssid = "Yasmim&Luca";
const char* pass = "Mortadela1";
const char* broker_mqtt = "xxxx"; 

/*******************************************************************
*   LOCAL PROTOTYPES
*******************************************************************/

WiFiClient espClient;
PubSubClient MQTT(espClient);

/**
 * @fn init_wifi(void)
 * @brief função para incilizar a camada de conectividade Wi-Fi no ESP32
 * @param void
 * @return void
 * @remarks Inicializa Wi-Fi nativo no dispositivo 
*/
void init_wifi();

/**
 * @fn reconnect_wifi(void)
 * @brief Função para reconectar o dispositivo na rede local Wi-Fi
 * @param void
 * @return void
*/
void reconnect_wifi();

/**
 * @fn init_serial(void)
 * @brief Função para incializar a comunicação serial UART do dispositivo
 * @param void
 * @return void
*/
void init_serial();

void setup() 
{
  init_serial();
  init_wifi();
  
}

void loop() 
{


}

/**
 * @fn init_serial(void)
 * @brief Função para incializar a comunicação serial UART do dispositivo
 * @param void
 * @return void
*/
void init_serial()
{
    Serial.begin(ESP_BAUD_RATE);
}

/**
 * @fn init_wifi(void)
 * @brief função para incilizar a camada de conectividade Wi-Fi no ESP32
 * @param void
 * @return void
 * @remarks Inicializa Wi-Fi nativo no dispositivo 
*/
void init_wifi()
{
    delay(10);
    Serial.print("Conectando-se na rede: ");
    Serial.println(ssid);
    Serial.println("Aguarde");
    reconnect_wifi();
}

/**
 * @fn init_wifi(void)
 * @brief Função para reconectar o dispositivo na rede local Wi-Fi
 * @param void
 * @return void
*/
void reconnect_wifi()
{
    if (WiFi.status() == WL_CONNECTED)
        return;
         
    WiFi.begin(ssid, pass);
     
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(100);
        Serial.print(".");
    }
   
    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(ssid);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
}