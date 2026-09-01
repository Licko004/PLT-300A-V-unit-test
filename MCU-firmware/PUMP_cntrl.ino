#include <Timer.h>

Timer timer;

int PWM_pin = 3;
int CNTRL = 5;
int state_cnt = 0;
int stop = 6;
int MCU_fault = 8;

unsigned long start_time = 0;
unsigned long elapsed_ms = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(PWM_pin, OUTPUT);
pinMode(CNTRL, INPUT);
pinMode(stop, INPUT);
pinMode(MCU_fault, OUTPUT);
//Serial.begin(115200);

/***********MCU fault signal send*********************/
digitalWrite(MCU_fault, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
/***********PWM control for PUMP*********************/
int CNTRL_state = digitalRead(CNTRL);
int stop_state = digitalRead(stop);

if (CNTRL_state == 1) {
  state_cnt ++;
  delay(50);
}
if (stop_state == 1){
  switch (state_cnt) {
    // case 1:
    //   analogWrite(PWM_pin, 64);
    //   break;
    case 1:
      analogWrite(PWM_pin, 127);
      break;
    // case 3:
    //   analogWrite(PWM_pin, 191);
    //   break;
    case 2: 
      analogWrite(PWM_pin, 255);
      break;
    case 3:
      analogWrite(PWM_pin, 191); //Set PWM to 75% for leakage test
      break;
    default:
      analogWrite(PWM_pin, 0);
      break;
}
}else {
  analogWrite(PWM_pin, 0);
}

}


