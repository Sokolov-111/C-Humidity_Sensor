// Determine humidity wsing a sensor
#define sensor_pin A0                                    // Define analog pin

int LED_pins[] = {8, 9, 10, 11, 12, 13};                 // Define LED pins 
int array_size = sizeof(LED_pins) / sizeof(LED_pins[1]); // Define array size 

void setup() 
{
  for(int i = 0; i < array_size; i++)
  {
    pinMode(LED_pins[i], OUTPUT); // Initialize LED pins
  }
  Serial.begin(9600);             // Connect serial debugger
}

void loop() 
{
  int analog_value = map(analogRead(sensor_pin), 300, 1019, 0, array_size); // Read analog data and convert values 0 - array_size (6)

  for(int i = 0; i < array_size; i++)  // Check every pin
  {
    if(i < analog_value)               // If LED number < analog value
      digitalWrite(LED_pins[i], HIGH); // Turn On the LED
    else
      digitalWrite(LED_pins[i], LOW);  // Turn Off the LED

    Serial.println("DEBUG ----------------------- >>>>"); // Write debug data at serial monitor
    Serial.println(analog_value);                         // This log prints value at sensor
  }
}
