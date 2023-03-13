#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIG 24
#define ECHO 22

char LED[] = {25,26,27,28};

void setup()
	{
		wiringPiSetup();
		pinMode(TRIG,OUTPUT);
		pinMode(ECHO, INPUT);
		
		for(int i=0;i < 4; i++)
		{
		pinMode(LED[i],OUTPUT);
		}
		
		digitalWrite(TRIG, LOW);
		delay(100);
	
	}
	
int toCM()
	{
		digitalWrite(TRIG,HIGH);
		delayMicroseconds(20);
		digitalWrite(TRIG,LOW);
		
		while(digitalRead(ECHO) == LOW);
		long startTime = micros();
		
		while(digitalRead(ECHO) == HIGH);
		long endTime = micros();
		
		int distance = (endTime - startTime) / 58;
		
		return distance;
	}
	
int main(void)
	{
			while(1)
			{
					setup();
					delay(1500);
					printf("Distance: %d cm\n" , toCM());
					int d,j,k;
					d = toCM();
			
					if(d <= 25)
					{
						k=3;
						
					}
					else if(d <= 50)
					{
						k=2;
					}	
					
					else if(d <= 75)
					{
						k=1;
					}
					
					else
					{
						k = 0;
					}
					
					for(j=3; j >= k; j--)
					{
						digitalWrite(LED[j], HIGH);
					}
					
					for(int i=k-1; i >= 0; i--)
					{
						digitalWrite(LED[i], LOW);
					}
			}
			return 0;
	}
