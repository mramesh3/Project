/*************************************************************************************************************************************
 *  Topic   : A simple program to connect ESP32 to a MQTT broker and publish and subscribe to the topic 
 *            house/light to turn the switch ON and OFF using an arduino

   Author   : Mahendri Ramesh 
***************************************************************************************************************************************/

#include <WiFi.h>
#include <PubSubClient.h>

//Wifi settings: 

const char *ssid      = "NETWORK NAME";
const char *password  = "PASSWORD";

//Device and topic settings:

const char *Topic                 = "house/light";
const char *ID                    = "light_switch";                     //device name/ID
const byte  Switch_pin_config     =  0;
IPAddress broker(50,0,0,107);                                          //IP address of MQTT broker 
WiFiClient w_c;                                                        //MQTT client 

PubSubClient client(w_c);                                              //to setup MQTT client

/****************************************************************************************************************************************
Establish connection to a WiFi Network*/

void setup_wifi() 
{
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  WiFi.begin((char*)ssid, (char*)password);                            // Establishes a connection to network

  while (WiFi.status() != WL_CONNECTED) 
  {                          
    delay(500);                                                        //waiting for connection
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

/***********************************************************************************************************************************
 * Callback function*/

void callback(char* topic, byte* message, unsigned int length) 
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print("Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {                                    // Prints the message
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
                                                                              
  if (String(topic) == "house/light") {                                                                        
    Serial.print("Changing output to ");
    if(messageTemp == "on"){                                            //checks for ON message in the topic and sets pin HIGH
      Serial.println("on");
      digitalWrite(13, HIGH);
    }
    else if(messageTemp == "off"){                                      // checks for OFF command in the topic and sets pin LOW
      Serial.println("off");
      digitalWrite(13, LOW);
    }
  }
}

/****************************************************************************************************************************************
Reconnect to client in case of disconnection*/

void reconnect() 
{
  while (!client.connected()) 
  {
    Serial.print("Connecting to MQTT broker...");
    if (client.connect(ID)) 
    {
      Serial.println("connected");
      Serial.print("Publishing to: ");
      Serial.println(Topic);
      Serial.println('\n');
      client.subscribe(Topic);

    } 
    else 
    {
      Serial.println(" try again in 5 seconds");
      delay(5000);                                                    //providing a delay before attempting reconnecting
    }
  }
}

/****************************************************************************************************************************************/
void setup() 
{
  Serial.begin(115200);                                               // Start serial communication at 115200 baud
                                     
  pinMode(13,OUTPUT);                                                 //Setting the PIN 13 as output  
  digitalWrite(13,HIGH);                                              // enable pull-up resistor (active low)
  delay(100);
  setup_wifi();                                                       // Connect to network
  client.setServer(broker, 1883);
  client.setCallback(callback);
}

void loop() 
{
  if (!client.connected())                                            // Reconnect if connection is lost
  {
    reconnect();
  }
  client.loop();
                                                                       

}

/**********************************************************************************************************************************************
***********************************************************END*********************************************************************************
**********************************************************************************************************************************************/
