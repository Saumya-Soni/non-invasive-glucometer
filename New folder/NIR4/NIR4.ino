#define photodiodePin A0
int adcValue = 0;
int mappedVoltage = 0;
int glucoseValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  adcValue = analogRead(photodiodePin);
  mappedVoltage = map(adcValue, 49, 1014, 65, 85);
  glucoseValue = 0.1702 * mappedVoltage * mappedVoltage * mappedVoltage - 35.538 * mappedVoltage * mappedVoltage + 2424.4 * mappedVoltage - 53568;

  Serial.print("ADC Value = ");
  Serial.println(adcValue);
  Serial.print("Mapped Voltage Value = ");
  Serial.println(mappedVoltage);
  Serial.println();
  Serial.print("Output Glucose Value = ");
  Serial.println(glucoseValue);

  Serial.println();
  delay(3000);
}
