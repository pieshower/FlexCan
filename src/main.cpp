

#include <Arduino.h>
#include "FlexCAN_util.hpp"



uint8_t buf[] = {0, 10, 0, 0, 0, 0, 0, 10};
    
void heartBeat();

void setup()
{

    pinMode(13, OUTPUT);
    pinMode(25, INPUT);

    init_can();

    load_can(0x10, false, buf);

}

void loop()
{

    if (digitalRead(25) == 1)
    {

        //CANevents();
        //load_can(0x10, false, buf);

    }

    //CANevents();

    //load_can(0x10, false, buf);

    heartBeat();
    
}

void heartBeat()
{

    digitalWrite(13, HIGH);

    delay(1000);

    digitalWrite(13, LOW);

    delay(1000);

}