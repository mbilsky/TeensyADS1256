#include <SPI.h>



//(other stuff for getting the ADS1526 to work is in the next tab
#define ADS_RST_PIN    8 //ADS1256 reset pin
#define ADS_RDY_PIN    22 //ADS1256 data ready
#define ADS_CS_PIN    21 //ADS1256 chip select

/* 
    CLK  - pin 13
    DIN  - pin 11 (MOSI)
    DOUT - pin 12 (MISO)
*/


//put the ADC constants here

double resolution = 8388608.; //2^23-1

//this needs to match the setting in the ADC init function in the library tab
double Gain = 64.; //be sure to have a period 

double vRef = 5.0; //reference voltage

//we'll calculate this in setup
double bitToVolt = 0.;

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("booting");
  //initialize the ADS
  pinMode(ADS_CS_PIN, OUTPUT);

  pinMode(ADS_RDY_PIN, INPUT);
  pinMode(ADS_RST_PIN, OUTPUT);

  SPI.begin();

  initADS();
  Serial.println("done init");

  //determine the conversion factor
    //do some calculations for the constants
  bitToVolt = resolution*Gain/vRef;
}

int32_t val1;
int32_t val2;
int32_t val3;

void loop() {
  // put your main code here, to run repeatedly:

double value = 0;
for (int i = 0; i <1; i++){
  read_three_values();
  value += val1;
}

value /=1.;

  Serial.print(value,8);
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  Serial.println(val3);

//
//double value = 0;
//for (int i = 0; i <10; i++){
//  value += read_Value();
//}
//
//value /= 10.;
//value /= bitToVolt;
//
//Serial.println(value,11);
}
