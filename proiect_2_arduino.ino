#define stp 2
#define dir 3
#define MS1 4
#define MS2 5



SharpIR SharpIR(ir, model);
int cal_cap = 33;
int cal_dist = 0;
int dist_motor = 1;
char resultBuffer[128];
char capacitanceStr[32];
char distanceStr[32];

int x;
int nr=0;


#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

//#define OLED_RESET 6
//Adafruit_SSD1306 display(OLED_RESET);

const int OUT_PIN = A2;
const int IN_PIN = A0;

//Capacitance between IN_PIN and Ground
//Stray capacitance is always present. Extra capacitance can be added to
//allow higher capacitance to be measured.
const float IN_STRAY_CAP_TO_GND = 24.48; //initially this was 30.00, then 24.48 (for seeeduino lite 26.40)
const float IN_EXTRA_CAP_TO_GND = 0.0;
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND + IN_EXTRA_CAP_TO_GND;
const int MAX_ADC_VALUE = 1023;

void setup()
{
  pinMode(OUT_PIN, OUTPUT);
  //digitalWrite(OUT_PIN, LOW);  //This is the default state for outputs
  pinMode(IN_PIN, OUTPUT);
  //digitalWrite(IN_PIN, LOW);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  // Clear the buffer.
  //isplay.clearDisplay();
  // Set text size and color
  //display.setTextColor(WHITE);

  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  
  digitalWrite(MS1,LOW);
  digitalWrite(MS2,LOW);
  
  Serial.begin(115200);
}

void loop()
{
  //Capacitor under test between OUT_PIN and IN_PIN
  //Rising high edge on OUT_PIN
  pinMode(IN_PIN, INPUT);
  digitalWrite(OUT_PIN, HIGH);
  int val = analogRead(IN_PIN);

  //Clear everything for next measurement
  digitalWrite(OUT_PIN, LOW);
  pinMode(IN_PIN, OUTPUT);

  //Calculate and print result

  float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val) + cal_cap ;

  Serial.print(F("Capacitance Value = "));
  Serial.print(capacitance, 3);
  Serial.print(F(" pF ("));
  Serial.print(val);
  Serial.println(F(") "));
  

  float distance = -0.2963 *capacitance + 28.458 + cal_dist;
  
  Serial.print(F("Distance = "));
  Serial.print(distance, 3);
  Serial.print(F(" cm ("));
  
  
  digitalWrite(dir, HIGH);
  while(nr<1)
  { 
  for(x= 0; x< dist_motor * 2700; x++)  
  {
    digitalWrite(stp,HIGH); 
    delay(1);
    digitalWrite(stp,LOW); 
    delay(1);
  }
  nr++;
  }

   /*----------------------------------------------------------------PLOT DISTANTA SI CAPACITATE*/
  /*dtostrf(distance, 8, 6, distanceStr);
  dtostrf(capacitance, 8, 6, capacitanceStr);
  sprintf(resultBuffer, "%s %s", capacitanceStr, distanceStr);
  Serial.println(resultBuffer);
  */
  

  /*display.clearDisplay(); // clear buffer
  display.setCursor(0,0);
  display.setTextSize(1);
  display.print("A0 -||- A2");
  display.print("\n\n");
  display.setTextSize(2);
  display.print(capacitance, 3);
  display.print(" pF");
  display.display();*/
    
  while (millis() % 500 != 0);
}
