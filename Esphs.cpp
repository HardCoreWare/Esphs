#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Esphs.h"

Esp::Esp(){

}

//----------------------------------------------------------------------------------------------------------------------

void Esp::reset(){

    Serial3.println("AT+RST");
  
}

//----------------------------------------------------------------------------------------------

void Esp::setMode(int m){

    Serial3.println("AT+CWMODE="+String(m,DEC));
    
}

//-------------------------------------------------------------------------------------------------------------------------

void Esp::espNode(){

    if(Serial3.available()){
      
    String r=Serial3.readStringUntil('\n');
    
        Serial.println(r); 
    }

    else{ }

    if(Serial.available()){
      
    String r=Serial.readStringUntil('\n');
    
        Serial3.println(r);  
    }

    else { }

}

//-------------------------------------------------------------------------------------------------------------------------------

void Esp::setAP(String n, String p, int c, int e){

    Serial3.println("AT+CWSAP="+n+","+p+","+String(c,DEC)+","+String(e,DEC));
    
}

//-----------------------------------------------------------------------------------------------------------------

void Esp::setClient(String n, String p){

char c='"';

    Serial3.println("AT+JWSAP="+String(c)+n+String(c)+","+String(c)+p+String(c));
    
}

//-------------------------------------------------------------------------------------------------------------------

void Esp::multiCon(int m){
	
	
    Serial.println("AT+CIPMUX="+String(m));
    
		
}

//----------------------------------------------------------------------------------------------------------------------------

void Esp::httpBegin(String t, String h, int p){

    char c ='"';
	
	Serial3.println("AT+CIPSTART="+String(c)+t+String(c)+","+String(c)+h+String(c)+","+String(p));
	
	
}

//---------------------------------------------------------------------------------------------------------------------------------------

void Esp::httpSet(int l){
	
Serial3.println("AT+CIPSEND="+String(l,DEC));
	
}

String Esp::POST(String host, String url, String data){

String req =  "POST " + url + " HTTP/1.0"+"\r\n"+

"Host: " + host + "\r\n" +

"Accept: *" + "/" + "*" + "\r\n" +

"Content-Length: " + String(data.length()) + "\r\n" +

"Content-Type: application/x-www-form-urlencoded" + "\r\n" + "\r\n" 

+ data; 

return req;

}

//----------------------------------------------------------------------------------------------------------------------------

void Esp::httpEnd(){
	
	Serial3.println("AT+CIPCLOSE");
	
	
}

//----------------------------------------------------------------------------------------------------------------------------

void Esp::httpSend(String req){
	
	Serial3.println(req);
	
	
}

String Esp::GET(String host, String url, String data){

String req =  "GET " + url + " HTTP/1.0"+"\r\n"+

"Host: " + host + "\r\n" +

"Accept: *" + "/" + "*" + "\r\n" +

"Content-Length: " + String(data.length()) + "\r\n" +

"Content-Type: application/x-www-form-urlencoded" + "\r\n" + "\r\n" 

+ data; 

return req;

}
	







