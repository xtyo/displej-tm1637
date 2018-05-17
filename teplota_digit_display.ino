#include <DallasTemperature.h>
#include <OneWire.h> 
#include <TM1637.h>

TM1637 tm1637(9,10);//piny prvního displeje
TM1637 tm1637b(11,12);//piny druhýho displeje





// nastavení čísla vstupního pinu teplotních čidel
const int pinCidlaDS = 6;
// vytvoření instance oneWireDS z knihovny OneWire
OneWire oneWireDS(pinCidlaDS);
// vytvoření instance senzoryDS z knihovny DallasTemperature
DallasTemperature senzoryDS(&oneWireDS);

void setup() {

  tm1637.init(D4056A);
  tm1637.set(3);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

  tm1637b.init(D4056A);
  tm1637b.set(7);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;


  
  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600);
  // zapnutí komunikace knihovny s teplotním čidlem
  senzoryDS.begin();

}

void loop() {
  // načtení informací ze všech připojených čidel na daném pinu
  senzoryDS.requestTemperatures();
  // výpis teploty čidel na sériovou linku

  /*
  Serial.print("Teplota cidla 1: ");
  Serial.print(senzoryDS.getTempCByIndex(0));
  Serial.println(" stupnu Celsia");
delay(1000);

    Serial.print("Teplota cidla 2: ");
  Serial.print(senzoryDS.getTempCByIndex(1));
  Serial.print(" ");
  Serial.print(char(176));
  Serial.println("C");
  // pauza pro přehlednější výpis
  delay(1000);

*/




   float temp = senzoryDS.getTempCByIndex(0);   //načtení teploty prvního čidla
  tm1637.display(temp);//vypsáný teploty prvního čidla na první displej

   float tempb = senzoryDS.getTempCByIndex(1);//načtení teploty druhého čidla
   tm1637b.display(tempb);//vypsáný teploty druhého čidla na druhý displej

  



}
