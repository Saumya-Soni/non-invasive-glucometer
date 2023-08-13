#define photodiodePin A0
int adcValue = 0;
int mappedVoltage = 0;
int glucoseValue1 = 0;
//int glucoseValue2 = 0;
//int glucoseValue3 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  adcValue = analogRead(photodiodePin);
  mappedVoltage = map(adcValue, 49, 1014, 0, 85);

  //if(adcValue==1014)
  //{
  //  mappedVoltage = 0;
  //}
  //else if (adcValue==49)
  //{
  //  mappedVoltage = 300;
  //}
  //for (int i=0;)
  //mappedVoltage = adcValue;

  glucoseValue1 = 0.1702 * mappedVoltage * mappedVoltage * mappedVoltage - 35.538 * mappedVoltage * mappedVoltage + 2424.4 * mappedVoltage - 53568;

  //glucoseValue2 = 21.998*mappedVoltage*mappedVoltage-157.73*mappedVoltage+335.55;
  //glucoseValue3 = 0.00008*mappedVoltage*mappedVoltage+0.1873*mappedVoltage+46.131;

  Serial.print("ADC Value = ");
  Serial.println(adcValue);
  //Serial.print("Input Voltage Value = ");
  //Serial.println(inputVoltage);
  Serial.print("Mapped Voltage Value = ");
  Serial.println(mappedVoltage);
  Serial.println();
  Serial.print("Output Glucose Value = ");
  Serial.println(glucoseValue1);
  //Serial.println(glucoseValue2);
  //Serial.println(glucoseValue3);
  Serial.println();
  delay(3000);
}
