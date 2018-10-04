int led1 = 12;      //Initialize led pins.
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;

char mode='s';

String fullStr, subStr;   // for receiving data.

long randNumber; // for randomFlash pattern

int patternNumber = 1;

int bpp = 100; // beats per pattern

int i = 1;
int plot=0;

long beatCount=0;   // counts how many times the lights were lit

boolean soundstate;

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 200;           // interval at which to blink (milliseconds)

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
        
              patternMixer();
              
              break;
    }       


  if(Serial.available())
  {
    fullStr = Serial.readString();
 
    while((fullStr.length() >= 2))                // If received more than one command.
    {
        subStr = fullStr.substring(0,2);          // get only the 1st 2 characters(Eg: "1H").
       // Serial.println("sub string: "+subStr);    
        ledControl(subStr);                       // call ledControl function with current command.
        fullStr.remove(0,2);                      // remove 1st 2 characters from the full string.
                                                  
    }  
  }
  
}


void patternMixer()
{
    //Serial.println(plot);

    if(beatCount <= bpp)   // change pattern every 20 beats
    {
       Serial.println("pat 1");
       pattern1();   
    }
    else if(beatCount <= (bpp*2))
    {
      Serial.println("pat 2");      
      pattern2();
    }
    else if(beatCount <= (bpp*3))
    {
      Serial.println("pat 3");  
      pattern3();
    }
    else if(beatCount <= (bpp*4))
    {
      Serial.println("pat 4");  
      pattern4();
    }
    else if(beatCount <= (bpp*5))
    {
      Serial.println("pat 5");  
      pattern5();
    }
    else if(beatCount > (bpp*5))
    {
      beatCount = 0;
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


void pattern1()        //------------ Pattern 1 - Up sweep ---------------//
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    plot = 1;
    beatCount++;    // increase beat count
    
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
    plot=0;
    allOff();
  }
}


void pattern2()        //------------ Pattern 2 - Random flash ---------------//
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    
    plot = 1;
    beatCount++;    // increase beat count

    randNumber = random(7,13); // generate random number between 7 & 12 inclusive
    digitalWrite(randNumber, HIGH);
    delay(del);
                  
  }
  else
  {
    plot=0;
    allOff();
  }
}


void pattern3() //------------ Pattern 3 - Random flash inverse ---------------//
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    
    plot = 1;
    beatCount++;    // increase beat count

    randNumber = random(7,13); // generate random number between 7 & 12 inclusive
    digitalWrite(randNumber, LOW);
    delay(del);
                  
  }
  else
  {
    plot=0;
    allOn();
  }
}


void pattern4()     //----------------- Pattern 4 - Strobe ----------------//
{

  soundstate = digitalRead(3);

  if(soundstate == 1)
  {
    beatCount++;    // increase beat count
    allOn();
    delay(del + 50);
  
  }
  else
  {

    allOff();

  }
 
}

void pattern5()        //------------ Pattern 5 - edges ---------------//
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    plot = 1;
    beatCount++;    // increase beat count
    
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

          digitalWrite(led4, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led1, HIGH);
          delay(del);
          digitalWrite(led4, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led1, LOW); 

            
            i++;
             break;

        case 3:

          digitalWrite(led1, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led6, HIGH);
          delay(del);
          digitalWrite(led1, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led6, LOW); 
          
          i++;  
             break;
             
        default:
            i = 1;
    }           
  }
  else
  {
    plot=0;
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


void allOn()
{
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
}








