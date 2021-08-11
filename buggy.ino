//https://www.youtube.com/watch?v=ZDtRWmBMCmw

#define THROTTLE_PWM_CH_PIN 12 //PWM_CH pins are the pins that listen to the PWM signals sent by the reciever
#define THROTTLE_PWM_CH_PCICR 0xb00000001 //Specifies that that bit should be set high in the PCICR to enable interrupts for the group that the specified pin is in.
#define THROTTLE_PWM_CH_PCMSK0 0xb00000000 //Specifies the exact pin in the group that the interrupt service routine should be triggered from.

#define STEERING_PWM_CH_PIN 7
#define STEERING_PWM_CH_PCICR 0xb00000001
#define STEERING_PWM_CH_PCMSK0 0xb00000000

#define CLUTCH_PWM_CH_PIN 13
#define CLUTCH_PWM_CH_PCICR 0x00000001
#define CLUTCH_PWM_CH_PCMSK0 0x00000000

#define THROTTLE_PWM_OUT_PIN 10 //PWM_OUT are used for sending. These pins must support outputting PWM
#define STEERING_PWM_OUT_PIN 11

#define GPS_RX_PIN 2;
#define GPS_TX_PIN 3;

uint16_t pwm_timings[3];
uint16_t pwm_previous_rise[3];
byte pwm_states;

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello World!");
    cli(); //temporarily pause interrupts
	PCICR |= THROTTLE_PWM_CH_PCICR;
    PCICR |= STEERING_PWM_CH_PCICR;
    PCICR |= CLUTCH_PWM_CH_PCICR;

    //PCMSK0 |= THROTTLE_PWM_CH_PCMSK0; //enable which pins within a group can trigger interrupt handlers. Each bit corresponds to a specific pin within the group
    //PCMSK1 |= 0xb00000000;
    //PCMSK2 |= 0xb00000000; //will be configured when I work out which pins will be used

    sei(); //reenable interrupts
}

//group 0 interrupt service routine
ISR (PCINT0_vect) {
    if(PIND & 0xb00000000) { //PIND stores the interrupts that have been triggered

    }
}

ISR (PCINT1_vect) {
    if(PIND & 0xb00000000) { //PIND stores the interrupts that have been triggered
        
    }
}

ISR (PCINT2_vect) {
    if(PIND & 0xb00000000) { //PIND stores the interrupts that have been triggered
        
    }
}

void loop()
{
	
}
