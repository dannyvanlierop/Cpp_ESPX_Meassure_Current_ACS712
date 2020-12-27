
const int currentPin = A0;
int sensitivity = 66;
int adcValue = 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
int wattResult = 0;

void setup()
{
  Serial.begin(115200);
  delay(2000);
}

void loop()
{
  adcValue = analogRead(currentPin);
  Serial.print(" Raw Sensor Value = " );
  Serial.print(adcValue);

  adcVoltage = (adcValue / 1023.0) * 5000;
  Serial.print(" Voltage(mV) = ");
  Serial.print(adcVoltage);

  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);

  //Correct negative to positive
  if (currentValue < 0) {
    currentValue *= -1;
    
    //Correct ghost values
    //if (currentValue < 0.15) {
      //currentValue = 0;
    //}
  }



  wattResult = currentValue * 230;

  Serial.print(" Ampere = ");
  Serial.print(currentValue, 3);
  Serial.print(" Watt = ");
  Serial.println(wattResult);

  delay(500);
}
