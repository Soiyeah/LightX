int led1 = 12;      //Initialize led pins.
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;

char mode='m';

String fullStr, subStr;   // for receiving data.

int i = 1;

boolean soundstate;

unsigned long currentMillis;
int del = 150;


void setup() 
{
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);   
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT); 
  
  Serial.begin(9600);
  pinMode(3,INPUT); //SIG of the Sound Sensor connected to Digital Pin 3

}

void loop() 
{
    switch(mode)
    {
        case 'm':
              
              break;

        case 's':
              upSweep();
              break;

    }       


  if(Serial.available())
  {
    fullStr = Serial.readString();
 
    while((fullStr.length() >= 2))                // If received more than one command.
    {
        subStr = fullStr.substring(0,2);          // get only the 1st 2 characters(Eg: "1H").
        Serial.println("sub string: "+subStr);    
        ledControl(subStr);                       // call ledControl function with current command.
        fullStr.remove(0,2);                      // remove 1st 2 characters from the full string.
                                                  
    }  

  }

}


void ledControl(String str)
{
  
  if(str.equals("1H"))
  {
    digitalWrite(led1,HIGH);
  }
  else if(str.equals("2H"))
  {
    digitalWrite(led2,HIGH);
  } 
  else if(str.equals("3H"))
  {
    digitalWrite(led3,HIGH);   
  }
    else if(str.equals("4H"))
  {
    digitalWrite(led4,HIGH);
  }   
  else if(str.equals("5H"))
  {
    digitalWrite(led5,HIGH);   
  }
    else if(str.equals("6H"))
  {
    mode='s';
    // edited!!!!!!!! 
  }

  else if(str.equals("1L"))
  {
    digitalWrite(led1,LOW);
  } 
  else if(str.equals("2L"))
  {
    digitalWrite(led2,LOW);
  } 
  else if(str.equals("3L"))
  {
    digitalWrite(led3,LOW);   
  }
    else if(str.equals("4L"))
  {
    digitalWrite(led4,LOW);
  } 
  else if(str.equals("5L"))
  {
    digitalWrite(led5,LOW);   
  }
    else if(str.equals("6L"))
  {
    digitalWrite(led6,LOW);   
  }
  
  delay(10);
}


void upSweep()        //------------ Pattern 1 - Up sweep ---------------//
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    switch(i)
    {
        case 1:

          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
          delay(del);
          digitalWrite(led4, LOW);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW); 

            i++;
             break;

        case 2:

          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          delay(del);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
            
            i++;
             break;

        case 3:

          digitalWrite(led1, HIGH);
          delay(del);
          digitalWrite(led1, LOW);
          i++;  
             break;
             
        default:
            i = 1;
    }           
  }
  else
  {
    allOff();
  }
}


void allOff()
{
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
}








