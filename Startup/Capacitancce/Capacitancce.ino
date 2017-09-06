#include <CapacitiveSensor.h>

void setup() {
  CapacitiveSensor cap12 = CapacitiveSensor(1,2);
  CapacitiveSensor cap34 = CapacitiveSensor(1,3);
  unsigned long cs1=0;
  unsigned long cs2=0;
  int channel1 = 0;
  int channel2 = 0;
  int countc1 = 0;
  int countc2 = 0;
  Serial.begin(9600);
}

void loop() {
 checkc1();
}


void checkc1(){
long cs1 = cap12.capacitiveSensor(80); // cs resolution is set to 80
// CsSum 3800 is the threshold
if(cs1>=3800){
  countc1++;
  delay(500);
  borderloop();
}
else{
  checkc1();
  // Loops through checkc1 iteratively
}
}

void borderloop(){
long cs1 = cap12.capacitiveSensor(80);
long cs2 = cap34.capacitiveSensor(80);
  if(cs1>=3800){
  countc1++;
  delay(500);
  checkc1();
}
  if(cs2>=3800){
    countc2++;
    delay(500);
    checkc2();
  }
  }


void checkc2(){
  
}
void sendsignal1(){
  switch(channel1){
  case 1:
  // Sends signal of 1 to the TV
  sendsignal2();
  break;

  case 2:
  // Sends signal of 2 to the TV
  sendsignal2();
  break;

  case 3:
  // Sends signal of 3 to the TV
  sendsignal2();
  break;

  case 4:
  // Sends signal of 4 to the TV
  sendsignal2();
  break;

  case 5:
  // Sends signal of 5 to the TV
  sendsignal2();
  break;

  case 6:
  // Sends signal of 6 to the TV
  sendsignal2();
  break;

 case 7:
  // Sends signal of 7 to the TV
  sendsignal2();
  break;

 case 8:
  // Sends signal of 8 to the TV
  sendsignal2();
  break;

 case 9:
  // Sends signal of 9 to the TV
  sendsignal2();
  break;
  
  }
}

void sendsignal2(){
    switch(channel2){
  case 1:
  // Sends signal of 1 to the TV
  resetvalues();
  break;

  case 2:
  // Sends signal of 2 to the TV
  break;

  case 3:
  // Sends signal of 3 to the TV
  break;

  case 4:
  // Sends signal of 4 to the TV
  break;

  case 5:
  // Sends signal of 5 to the TV
  break;

  case 6:
  // Sends signal of 6 to the TV
  break;

 case 7:
  // Sends signal of 7 to the TV
  break;

 case 8:
  // Sends signal of 8 to the TV
  break;

 case 9:
  // Sends signal of 9 to the TV
  break;
  
}
}

void resetvalues(){
  cs1=0;
  cs2=0;
  channel1 = 0;
  channel2 = 0;
  countc1 = 0;
  countc2 = 0;
  delay(1000);
  loop();
}
}

