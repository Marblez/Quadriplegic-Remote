void setup() {
  CapacitiveSensor cap12 = CapacitiveSensor(1,2);
  CapacitiveSensor cap34 = CapacitiveSensor(3,4);
  unsigned long cs1=0;
  unsigned long cs2=0;
  int channel1 = 0;
  int channel2 = 0;
  
}

void loop() {
 Serial.begin(9600);
 checkc1();
}

void checkc1(){
long cs1 = cap12.capacitiveSensor(80); // cs resolution is set to 80
// CsSum 3800 is the threshold
if(cs1>=3800){
  
}
else{
  
}
}

void checkc2(){
  
}
void sendsignal1(){
  switch(channel1){
  case 1:
  // Sends signal of 1 to the TV
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

void sendsignal2(){
    switch(channel2){
  case 1:
  // Sends signal of 1 to the TV
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

