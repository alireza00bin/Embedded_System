#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <queue.h>
#define IN1 13
#define IN2 12
#define motorPin 7
#define TriggerPin A1
#define EchoPin A2
float duration;
float distance;

QueueHandle_t queue_gas_sensor;
QueueHandle_t queue_distance_sensor;

void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );
void Task4( void *pvParameters );

void setup()
{
  Serial.begin(9600);
  queue_gas_sensor = xQueueCreate(10, sizeof(float));
  queue_distance_sensor = xQueueCreate(10, sizeof(float));

  xTaskCreate(Task1, "MQ2", 128, NULL, 1, NULL);
  xTaskCreate(Task2, "SR04", 128, NULL, 1, NULL);
  xTaskCreate(Task3, "DC Motor", 128, NULL, 2, NULL);
  xTaskCreate(Task4, "FAN", 128, NULL, 2, NULL);
}

void loop()
{

}

// GAS DETECTOR
void Task1(void *pvParameters) 
{
  pinMode(A0, INPUT);
  while (true)
  {
    float a = analogRead(A0);
    float gas = map(a, 0, 1023, 0, 255);
    xQueueSend(queue_gas_sensor, &gas, portMAX_DELAY);
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Wait for 1000 millisecond(s)
  }
}

// Ultrasonic
void Task2(void *pvParameters) 
{
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  while (true)
  {
    //Clear trigger Pin
    digitalWrite(TriggerPin, LOW);
    vTaskDelay( 2 / portTICK_PERIOD_MS ); // Wait for 2 microseconds

    //Sets the trigger Pin on HIGH state for 10 micro seconds
    digitalWrite(TriggerPin, HIGH);
    vTaskDelay( 10 / portTICK_PERIOD_MS ); // Wait for 10 microseconds  
    digitalWrite(TriggerPin, LOW);

    //Reads the echoPin, returns the sound wave travel time in microseconds
    duration=pulseIn(EchoPin, HIGH);
    distance=(duration*0.034)/2;
    xQueueSend(queue_distance_sensor, &distance, portMAX_DELAY);
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Wait for 1000 millisecond(s)
  }
  
  
}

//1st DC Motor -> 
void Task3(void *pvParameters) 
{
  pinMode(IN1, OUTPUT); //L2930 Input 1
  pinMode(IN2, OUTPUT); //L2930 Input 2
  int gas;
  float distance;
  while (true)
  {
    if (xQueueReceive(queue_gas_sensor, &gas, portMAX_DELAY) == pdPASS || xQueueReceive(queue_distance_sensor, &distance, portMAX_DELAY) == pdPASS)
    {
      if (distance < 95 || gas > 55)
      {
        //Counter Clockwise
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); //1 second
      }
      if (distance > 105 || gas < 45)
      {
        //Round Clock
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); //1 second
      }
      
      
    }
  }
  
}

//2nd DC Motor -> FAN
void Task4(void *pvParameters) 
{
  pinMode(motorPin, OUTPUT);
  int gas;
  float distance;
  int speed;
  while (true)
  {
    if (xQueueReceive(queue_gas_sensor, &gas, portMAX_DELAY) == pdPASS || xQueueReceive(queue_distance_sensor, &distance, portMAX_DELAY) == pdPASS)
    {
      //Danger State
      if (distance < 95 || gas > 55)
      {
        analogWrite(motorPin, 0);
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); //1 second
      }
      //Normal State
      if (distance > 105 || gas < 45)
      {
        speed = (gas * 255.0) / 1023.0;
        analogWrite(motorPin, speed);
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); //1 second
      }
    }
  }
  
}
