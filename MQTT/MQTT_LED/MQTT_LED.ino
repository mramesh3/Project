/*************************************************************************************************************************************
 *  Topic   : A simple program to connect ESP32 to a MQTT broker and monitor the status of the switch

   Author   : Mahendri Ramesh 
***************************************************************************************************************************************/

#include <WiFi.h>
#include <PubSubClient.h>

//Wifi settings: 

const char *ssid      = " ";
const char *password  = " ";

//Device and topic settings:

const char *Topic                 = "house/light";
const char *ID                    = "light_switch";                     //device name/ID
const byte  Switch_pin_config     =  0;
IPAddress broker(XX,X,X,XXX);                                          //IP address of MQTT broker 
WiFiClient w_c;                                                        //MQTT client 

PubSubClient client(w_c);                                              //to setup MQTT client

/****************************************************************************************************************************************
Establish connection to a WiFi Network*/

void setup_wifi() 
{
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);                                         // Establishes a connection to network

  while (WiFi.status() != WL_CONNECTED) 
  {                          
    delay(500);                                                       //waiting for connection
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

/****************************************************************************************************************************************
Reconnect to client in case of disconneection*/

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
  pinMode(Switch_pin_config,INPUT);                                   // Configure Switch_pin_config as an input
  digitalWrite(Switch_pin_config,HIGH);                               // enable pull-up resistor (active low)
  delay(100);
  setup_wifi();                                                       // Connect to network
  client.setServer(broker, 1883);
}

void loop() 
{
  if (!client.connected())                                            // Reconnect if connection is lost
  {
    reconnect();
  }
  client.loop();
                                                                       
  if(digitalRead(Switch_pin_config) == 0)                             // if the switch is being pressed
  {
    state = !state; 
    if(state == 1)                                                    // ON condition
     {
      client.publish(Topic, "on");
      Serial.println((String)Topic + " => on");
    }
    else                                                              // OFF condition
    {
      client.publish(Topic, "off");
      Serial.println((String)Topic + " => off");
    }

    while(digitalRead(Switch_pin_config) == 0)                        // Waits for the release of the switch
    {
     
      yield(); 
      delay(50);
    }
  }

}

/**********************************************************************************************************************************************
***********************************************************END*********************************************************************************
**********************************************************************************************************************************************/
