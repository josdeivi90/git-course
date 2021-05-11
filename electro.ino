#include <WiFi.h>

//-------------------Servidor Web en puerto 80--------------------

WiFiServer server(89);

//------------------ Credenciales------------------------------

const char* ssid  = "TIGO-9C78";
const char* password  = "2NB144203778";

//------------------ Variables Globales
int contconexion = 0;

String header;

String estadoSalida = "off";

const int salida = 2;

//-------------------------HTML ---------------------

String pagina = "<!DOCTYPE html>"
"<html>"
"<head>"
"<meta charset='utf-8'/>"
"<title>Electrocardiografo UIS<title/>"
"header {"
    "background: green;"
  "}"
"<head/>"
"<body>"
"<center>"
"<h1>Electrocardiografo UIS</h1>"
"<p><a href='/on'><button style='height:50px;width:100px'>ON<button/></a></p>"
"<p><a href='/off'><button style='height:50px;width:100px'>OFF<button/></a></p>"
"</center>"
"</body>"
"</html>";

//----------------------setup-----------------
void setup() {
  Serial.begin(115200);
  Serial.println("");

  pinMode(salida, OUTPUT);
  digitalWrite(salida,LOW);

  //conexio WIFI
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED and contconexion<50){
    ++contconexion;
    delay(500);
    Serial.print(".");
    }

   if (contconexion <50 )
   {
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
    server.begin();
   }
   else{
       Serial.println("");
       Serial.println("Error de conexion");
   }
}  

}

void loop() {
  // put your main code here, to run repeatedly:

}