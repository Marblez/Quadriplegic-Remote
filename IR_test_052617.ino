
int IRledPin =  13;    // LED connected to digital pin 13
 
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
  Serial.println("Sending IR signal");
 
  SendCode();
 
  delay(2000);  // wait one minute (60 seconds * 1000 milliseconds)
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendCode() {
  // This is the code for my particular Nikon, for others use the tutorial
  // to 'grab' the proper code from the remote
 
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(360);
delayMicroseconds(700);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(780);
pulseIR(340);
delayMicroseconds(1800);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(780);
pulseIR(340);
delayMicroseconds(48540);
pulseIR(300);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(780);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(44280);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(780);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(48620);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(1880);
pulseIR(280);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(280);
delayMicroseconds(44280);
pulseIR(300);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(800);
pulseIR(280);
delayMicroseconds(1840);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(780);
pulseIR(280);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
delayMicroseconds(800);
pulseIR(260);
delayMicroseconds(1860);
pulseIR(300);
delayMicroseconds(760);
pulseIR(300);
Serial.println("sent signal"); 
  delay(65); // wait 65 milliseconds before sending it again

}
