
//Press the button and immediately the blue light turns on and then hold it for three seconds (or until the red light comes on)
//then the shutdown process would have been started

const int buttonPin       = 6; //since button is connected to d4
const int warningLedPin   = 2; //since warningled(blue) is connected to d2
const int confirmLedPin   = 3; //since confirmled(red) is connected to d3
      int buttonState     = 0; //initializing state to zero  
      int flag            = 0; //flag is used so that once shutdown is confirmed it can't be initiated again 
void setup() 
{
  //initializing button as input
  pinMode(buttonPin, INPUT);
  pinMode(warningLedPin, INPUT);
  pinMode(confirmLedPin, INPUT);

  //initializing the serial monitor
  Serial.begin(9600);
}

void loop() 
{
 digitalWrite(warningLedPin,LOW);
 digitalWrite(confirmLedPin,LOW);

 if(flag == 0)
 {   
 //read input from button
 buttonState = digitalRead(buttonPin);

 if(buttonState == HIGH)
  {
  digitalWrite(warningLedPin,HIGH);
  Serial.println("SHUTDOWN INITIATED");
  delay(3000);
  buttonState = digitalRead(buttonPin);
    
  if(buttonState == HIGH)
        {
         digitalWrite(confirmLedPin,HIGH);
         Serial.print("SHUTDOWN CONFIRMED");
         flag = 1;
         delay(1000);        //otherwise you won't notice the red led being turned on
        }
  else
        {
         Serial.print("SHUTDOWN ABORTED");   
        }
    
  }


}
else
Serial.println("SYSTEM ALREADY SHUTDOWN");
}