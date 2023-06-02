#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <Servo.h>
#include <queue.h>

#define IN1 13
#define IN2 12

Servo servo1;
int pos = 0;

QueueHandle_t queue_task2_task3; // send status of switch to task 3 and choose fast mode or slow mode
QueueHandle_t queue_task1_task4; // send temperature to task 4 and calculate speed

int temp;
int speed;
bool type_of_speed;
void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );
void Task4( void *pvParameters );

void spin(bool status) {
  
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
  }
  
  queue_task2_task3 = xQueueCreate(10, sizeof(bool));
  queue_task1_task4 = xQueueCreate(10, sizeof(int));

  xTaskCreate(Task1, "Temperature", 128, NULL, 1, NULL);
  xTaskCreate(Task2, "Switch", 128, NULL, 3, NULL);
  xTaskCreate(Task3, "Type Of Speed", 128, NULL, 2, NULL);
  xTaskCreate(Task4, "DC Motor", 128, NULL, 0, NULL);
  
}

// Temperature
void Task1(void *pvParameters) 
{
  pinMode(A0, INPUT);   // TMP36
  while (true)
  {
    temp = map((analogRead(A0) - 20) * 3.04, 0, 1023, 20, 40);
    xQueueSend(queue_task1_task4, &temp, portMAX_DELAY);
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Wait for 1000 millisecond(s)
  }
}

// Switch
void Task2(void *pvParameters)
{
  pinMode(A1, INPUT);
  while (true)
  {
    type_of_speed = digitalRead(A1);
    xQueueSend(queue_task2_task3, &type_of_speed, portMAX_DELAY);
    vTaskDelay( 100 / portTICK_PERIOD_MS ); // Wait for 100 millisecond(s)
  }
     
}

// Servo Motor
void Task3(void *pvParameters) 
{

  servo1.attach(11);    
  bool status;

  while (true)
  {
    if (xQueueReceive(queue_task2_task3, &status, portMAX_DELAY) == pdPASS)
    {
      if(status == HIGH){
  	  for(pos=0; pos<=180; pos++){
      	servo1.write(pos);
      	vTaskDelay( 20 / portTICK_PERIOD_MS );
  	  }
  	  vTaskDelay( 500 / portTICK_PERIOD_MS );
  	  for(pos=180; pos>=0; pos--){
      	servo1.write(pos);
      	vTaskDelay( 20 / portTICK_PERIOD_MS );
  	  }
  	  vTaskDelay( 500 / portTICK_PERIOD_MS );
      }
      else{
      	for(pos=0; pos<=180; pos++){
        	servo1.write(pos);
        	vTaskDelay( 50 / portTICK_PERIOD_MS );
      	}
      	vTaskDelay( 500 / portTICK_PERIOD_MS );
      	for(pos=180; pos>=0; pos--){
        	servo1.write(pos);
        	vTaskDelay( 50 / portTICK_PERIOD_MS );
      	}
      	vTaskDelay( 500 / portTICK_PERIOD_MS );
      }
    }
    
    
  }
  
}

void Task4(void *pvParameters) 
{
  pinMode(IN1, OUTPUT); //L293D Input 1
  pinMode(IN2, OUTPUT); //L293D Input 2

  // value_from_queue = temperature
  int value_from_queue = 0;
  while (true)
  {
    if (xQueueReceive(queue_task1_task4, &value_from_queue, portMAX_DELAY) == pdPASS)
    {
      speed = value_from_queue - 20;
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      //analogWrite(speed);
    }
    
    
  }
  
}
void loop()
{
  
}
