
#include "FlexCAN_util.hpp"
#include "KS6eCAN.hpp"



FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> Inverter_CAN_;



void init_can()
{
    // inverter can must send & receive, 6rx MB and 2tx MB
    Inverter_CAN_.begin();
    Inverter_CAN_.setBaudRate(250000);

    Inverter_CAN_.setMaxMB(NUM_TX_MAILBOXES + NUM_RX_MAILBOXES);

    for (int i = 0; i < NUM_RX_MAILBOXES; i++)
    {

        Inverter_CAN_.setMB((FLEXCAN_MAILBOX)i, RX);

    }

    for (int i = NUM_RX_MAILBOXES; i < (NUM_TX_MAILBOXES + NUM_RX_MAILBOXES); i++)
    {

        Inverter_CAN_.setMB((FLEXCAN_MAILBOX)i, TX);

    }

    Inverter_CAN_.mailboxStatus();

}


int ReadCAN(CAN_message_t &msg)
{

    return Inverter_CAN_.read(msg);

}


int WriteCAN(CAN_message_t &msg)
{

    return Inverter_CAN_.write(msg);

}


int load_can(uint32_t id, bool extended, uint8_t buf[])
{

    CAN_message_t tx_msg;

    tx_msg.id = id;
    tx_msg.flags.extended = extended;
    tx_msg.seq = true;

    //memcpy(&tx_msg.buf[0], &buf, tx_msg.len);

    for(uint8_t i = 0; i < tx_msg.len; i++)
    {

        tx_msg.buf[i] = buf[i];

    }

    
    return WriteCAN(tx_msg);

}



void CANevents()
{

    Inverter_CAN_.events();

}