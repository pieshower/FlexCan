

#include <Arduino.h>
#include "FlexCAN_util.hpp"


CAN_message_t msg;

uint8_t buf[] = {0x34, 0x10, 0xff, 0xab, 0x24, 0x40, 0x100, 0x29};
    


void setup()
{

    Serial1.begin(9600);

    load_can(msg, 0x10, false, buf);

    pinMode(25, INPUT);

    pinMode(13, OUTPUT);

    //while(!Serial1);

}

void loop()
{

    if (digitalRead(25) == 1)
    {

        digitalWrite(13, HIGH);

        for (uint8_t i = 0; i < sizeof((int)buf); i++)
        {

            Serial1.print(buf[i]);

        }

    } else digitalWrite(13, LOW);

    

}