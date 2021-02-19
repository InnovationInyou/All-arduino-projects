
long duration;
int distance;
int ping();

void setup(){
  pinMode(A1,INPUT);
  pinMode(A0,OUTPUT);
  pinMode(6,OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() 
{   
  int ping();
 digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);
  
  duration= pulseIn(A1,HIGH);
  distance=duration*0.034/2;

   if (distance < 100){   

    digitalWrite(6,HIGH);    
    Serial.println(distance);
    delay (5de2000);
    }
    if (distance > 100){   

    digitalWrite(6,LOW);    
    Serial.println(distance);
    delay (1000);
    }
    
}

