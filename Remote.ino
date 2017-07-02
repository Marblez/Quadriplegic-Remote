// Initialized values for running the circuit
int analogPin= 0;
int raw= 0;
int Vin= 5; // Voltage of circuit
float Vout= 0;
float R1= 330; // Resistance of variable resistor in ohms
float R2= 0;
float R3 = 0; // Calibrated Value after 10 seconds
float temp = 0;
float buffer = 0;
float offset = 7000;
unsigned long StartTime = 0;
float checkpoint = 0;


int IRledPin =  13;    // LED connected to digital pin 13

// Sets up Arduino on launch
void setup()
{
Serial.begin(9600); // Serial connection rate
pinMode(LED_BUILTIN, OUTPUT); // Enable LED Light Output
pinMode(IRledPin, OUTPUT); 
}

void loop()
{
  
unsigned long CurrentTime = millis();
unsigned long ElapsedTime = CurrentTime - StartTime; 

if(ElapsedTime<10000 && checkpoint==1){
// Only works for first 10 seconds
// Prints time
Serial.print("Time:");
Serial.println(ElapsedTime);
// Checks photoresistor for input
raw= analogRead(analogPin);
if(raw) //Output valid
{

// Calculates resistance of the photoresistor
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;

R2= R1 * buffer;
if(temp=0){
  temp = R2;
  // Sets temp as the previous value
}
else{
  R3=(R2+temp)/2;
  // Averages previous and current value to set as R3
  temp = R3;
}
if((R2-R3)!<offset){
  checkpoint = 1;
}
delay(1000);// Delays loop by 1 second
}
}


else{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
// Calculates current value of R2
if((R2-R3)<offset){
// If difference is over 7000 ohms, trigger TV and LED 
  Serial.println("Trigger the TV");
  digitalWrite(LED_BUILTIN, HIGH);
  SendSignal();
  delay(1000);
  // Delays loop by 2 seconds to prevent
  // triggering of TV twice
}
// Prints current voltage and resistance values for checking
digitalWrite(LED_BUILTIN, LOW);
Serial.print("Voltage: ");
Serial.println(Vout);
Serial.print("Resistance: ");
Serial.println(R2);
delay(1000);
// Delays loop by 1 second
}
}
}

void SendSignal() {
  // This is the code for my particular Nikon, for others use the tutorial
  // to 'grab' the proper code from the remote
 
pulseIR(2500);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(1280);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(1280);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(27660);
pulseIR(2500);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(560);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(1260);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(1260);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(27680);
pulseIR(2480);
delayMicroseconds(600);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(560);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(1280);
delayMicroseconds(560);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(1280);
delayMicroseconds(560);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
delayMicroseconds(580);
pulseIR(660);
delayMicroseconds(580);
pulseIR(640);
Serial.println("Sent Signal");
}

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
