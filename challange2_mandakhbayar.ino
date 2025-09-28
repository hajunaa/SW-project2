int ledPin = 7;

int period_us = 100;   
int duty_percent = 0;  

void setup() {
  pinMode(ledPin, OUTPUT);
}
void set_period(int period) {
  period_us = period;
}
void set_duty(int duty) {
  if (duty < 0) duty = 0;
  if (duty > 100) duty = 100;
  duty_percent = duty;
}
void pwm_cycle() {
  int highTime = (period_us * duty_percent) / 100;
  int lowTime  = period_us - highTime;

  if (highTime > 0) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(highTime);
  }
  if (lowTime > 0) {
    digitalWrite(ledPin, LOW);
    delayMicroseconds(lowTime);
  }
}
void loop() {

  for (int d = 0; d <= 100; d++) {
    set_duty(d);
    for (int i = 0; i < 1000 / period_us; i++) { 
      pwm_cycle();
    }
  }
  
  for (int d = 100; d >= 0; d--) {
    set_duty(d);
    for (int i = 0; i < 1000 / period_us; i++) {
      pwm_cycle();
    }
  }
}
