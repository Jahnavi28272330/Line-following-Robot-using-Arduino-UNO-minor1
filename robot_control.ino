#define enA 5//Enable1 L293 Pin enA
#define in1 2 //Motor1  L293 Pin in1
#define in2 4 //Motor1  L293 Pin in2

#define enB 3 //Enable2 L293 Pin enB
#define in3 6 //Motor2  L293 Pin in3
#define in4 7 //Motor2  L293 Pin in4

#define Front_R_S 12 //ir sensor Right
#define Front_L_S 11 //ir sensor Left

#define Front_Obs_S 13 //ir sensor Obstavle

#define Back_R_S 8 //ir sensor Right
#define Back_L_S 9 //ir sensor Left

#define Back_Obs_S 10 //ir sensor Obstavle

#define ReedSwitch A0

void setup()
{
  Serial.begin(9600);
 
  pinMode(ReedSwitch, INPUT_PULLUP);
 
  pinMode(Front_R_S, INPUT);
  pinMode(Front_L_S, INPUT);
 
  pinMode(Back_R_S, INPUT);
  pinMode(Back_L_S, INPUT);
 
  pinMode(Front_Obs_S, INPUT);
  pinMode(Back_Obs_S, INPUT);
 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  analogWrite(enA, 102);
  analogWrite(enB, 102);
 
  delay(1000);
}

void loop()
{
  if(digitalRead(ReedSwitch) == 1)
  {
    Serial.println("Front");
   
    while(1)
    {
      if(digitalRead(Front_Obs_S) == 0)
      {
        Stop();
      }
     
      if((digitalRead(Front_R_S) == 1) && (digitalRead(Front_L_S) == 1) && (digitalRead(Front_Obs_S) == 1))
      {
        backward();
      }   //if Right Sensor and Left Sensor are at White color then it will call forword function
     
      else if((digitalRead(Front_R_S) == 0) && (digitalRead(Front_L_S) == 1) && (digitalRead(Front_Obs_S) == 1))
      {
        turnBackRight();
      } //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
     
      else if((digitalRead(Front_R_S) == 1) && (digitalRead(Front_L_S) == 0) && (digitalRead(Front_Obs_S) == 1))
      {
        turnBackLeft();
      }  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
     
      else if((digitalRead(Front_R_S) == 0) && (digitalRead(Front_L_S) == 0) && (digitalRead(Front_Obs_S) == 1))
      {
        Stop();
      } //if Right Sensor and Left Sensor are at Black color then it will call Stop function

      if(digitalRead(ReedSwitch) == 0)
      {
        break;
      }
    }
  }

  else if(digitalRead(ReedSwitch) == 0)
  {
    Serial.println("Back");
   
    while(1)
    {
      if(digitalRead(Back_Obs_S) == 0)
      {
        Stop();
      }
     
      if((digitalRead(Back_R_S) == 1) && (digitalRead(Back_L_S) == 1) && (digitalRead(Back_Obs_S) == 1))
      {
        forward();
      }   //if Right Sensor and Left Sensor are at White color then it will call forword function
     
      else if((digitalRead(Back_R_S) == 0) && (digitalRead(Back_L_S) == 1) && (digitalRead(Back_Obs_S) == 1))
      {
        turnFrontRight();
      } //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
     
      else if((digitalRead(Back_R_S) == 1) && (digitalRead(Back_L_S) == 0) && (digitalRead(Back_Obs_S) == 1))
      {
        turnFrontLeft();
      }  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
     
      else if((digitalRead(Back_R_S) == 0) && (digitalRead(Back_L_S) == 0) && (digitalRead(Back_Obs_S) == 1))
      {
        Stop();
      } //if Right Sensor and Left Sensor are at Black color then it will call Stop function

      if(digitalRead(ReedSwitch) == 1)
      {
        break;
      }
    }
  }
}

void forward()
{  //forward
  Serial.println("forward");
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin
}

void backward()
{  //backward
  Serial.println("backward");
  digitalWrite(in1, LOW); //Right Motor forword Pin
  digitalWrite(in2, HIGH);  //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin
}

void turnFrontRight()
{ //turnFrontRight
  Serial.println("turnFrontRight");
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin  
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin
}

void turnFrontLeft()
{ //turnFrontLeft
  Serial.println("turnFrontLeft");
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forword Pin
}

void turnBackRight()
{ //turnBackRight
  Serial.println("turnBackRight");
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forword Pin
}

void turnBackLeft()
{ //turnBackLeft
  Serial.println("turnBackLeft");
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin  
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin
}

void Stop()
{ //stop
  Serial.println("Stop");
  digitalWrite(in1, LOW); //Right Motor forword Pin
  digitalWrite(in2, LOW); //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin
}