#ifndef __TinyGPSPlus_h
#define __TinyGPSPlus_h

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
        boolean reset();
        boolean setMode(int m);
        boolean setAP(String n, String p, int c, int e);     
        boolean setClient(String n, String p);
        int getMode();
     
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
