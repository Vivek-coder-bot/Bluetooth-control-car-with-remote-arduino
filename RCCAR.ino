//including the libraries
#include <SoftwareSerial.h> // TX RX software library for bluetooth





//Initializing pins for bluetooth Module
int bluetoothTx = 2; // bluetooth tx to 2 pin
int bluetoothRx = 3; // bluetooth rx to 3 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

//Front Motor Pins  

int Motor1_Pin1 = 7;  
int Motor1_Pin2 = 8;  

//Back Motor Pins      
int Motor2_Pin1 = 9; 
int Motor2_Pin2 = 10;




char command ; //variable to store the data
 //Variable to control the speed of motor

void setup() 
{       
  //Set the baud rate of serial communication and bluetooth module at same rate.
  Serial.begin(9600);  
  bluetooth.begin(9600);


  pinMode(Motor1_Pin1, OUTPUT);  
  pinMode(Motor1_Pin2, OUTPUT);
 
  pinMode(Motor2_Pin1, OUTPUT);  
  pinMode(Motor2_Pin2, OUTPUT);
  


}

void loop(){
  if(bluetooth.available() > 0){  //Checking if there is some data available or not
    command = bluetooth.read();   //Storing the data in the 'command' variable
    Serial.println(command);      //Printing it on the serial monitor
    
    //Change pin mode only if new command is different from previous.   
    switch(command){
    case 'F':  //Moving the Car Forward
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'B':  //Moving the Car Backward
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'L':  //Moving the Car Left
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'R':   //Moving the Car Right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);  
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'S':   //Stop
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      break; 
    case 'I':  //Moving the Car Forward right
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      break; 
    case 'J':  //Moving the Car backward right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      break;        
    case 'G':  //Moving the Car Forward left
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break; 
    case 'H':  //Moving the Car backward left
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break;
    
      }
      }
    }
    


  