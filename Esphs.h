#ifndef __Esp_h
#define __Esp_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <limits.h>

class Esp{

    public: 

        Esp();
        void espNode();
        void reset();
        void setMode(int m);
        void setAP(String n, String p, int c, int e);     
        void setClient(String n, String p);
        int getMode();
        void multiCon(int m);
        void httpBegin(String t, String h, int p);
        void httpEnd();
        void httpSet(int l);
        void httpSend(String req);
        
        String POST(String host, String url, String data);
        String GET(String host, String url, String data);

     
    private:
    	
        int mode=0;
        
        struct lan{

            String name;
            int channel;
            int encrypt;
            String mac;
            String ip;
            String password;

        }ap,client;

};


#endif
