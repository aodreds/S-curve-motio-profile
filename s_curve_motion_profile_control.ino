/* S-shape motion control */
/* Sarayut Pongsanthia */

#include <stdio.h>
  
void setup() {
  Serial.begin(9600);             // open the serial port at 9600 bps:
  pinMode(LED_BUILTIN, OUTPUT);   // Onboard LED a cycle blink.
  pinMode(9,OUTPUT);              // PWM output control motor.
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() { 
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(1);                           // wait for a second
  digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
  delay(1000);                        // wait for a second
  { 
    
    double mn = 0;   /*  start point seconds. */
    double mx = 5;   /*  time seconds */
    double a1 = 8;      double a2 = 8;              /* accel and decel slope  */
    double c1 = 0.8;    double c2 = 4.2;            /* half point of slope  */
    double y1;          double y2;      double y;
    double temp;                                    /* temp variable for calculation */
    double x[1000], f[1000];                        /* this is static allocation */
    int n = 1000;                                   /*  assign No. of point plot. */
    int i;
    
      for (i = 0; i < n ; i++)  
      {
        temp = double((mx-mn)/(n));
        f[i] = mn + temp * i;
        {
            y1 = 1/(1 + exp(-a1*(f[i]-c1)));      /* S-curve acceleration */
            y2 = 1/(1 + exp(-a2*(f[i]-c2)));      /* S-curve deceleration */
            y  = abs((y1)- y2)*255;               /* absolute and *255 for scale up to PWM */
            
            /*PWM analog output pin 9 from y value 0 - 255 */
            analogWrite(9,y);
            analogWrite(10,y);
            analogWrite(11,y);
            
            /*print labels */
            Serial.print("y ");
            Serial.print(i);        /* prints a label */
            Serial.print(" = ");
            Serial.println(y,3);    /* print the number */                   
      }
    }
  }
} 
