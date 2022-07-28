#include "Arduino.h"

// C++ code
//

#define stopGF1 5
#define attGF1 4
#define goGF1 0

#define stopGF2 2
#define attGF2 14
#define goGF2 12

int stopF = 0;
int attF = 0;
int goF = 0;


// START CREATE FUNCTIONS

void tlLOG(String logtxt){
  Serial.println(logtxt.c_str());
}

void fswF(int F, int swV){
  digitalWrite(F, swV);
}

void fswGF(int stopV, int attV, int goV, int stopF, int attF, int goF){
  Serial.print("RED Value: ");
  if (stopV == 1){
    fswF(stopF, 1);
    Serial.println("1");
  }else{
    fswF(stopF, 0);
    Serial.println("0");
  }
  Serial.print("YELLOW Value: ");
  if (attV == 1){
    fswF(attF, 1);
    Serial.println("1");
  }else{
    fswF(attF, 0);
    Serial.println("0");
  }

  Serial.print("GREEN Value: ");
  if (goV == 1){
    fswF(goF, 1);
    Serial.println("1");
  }else{
    fswF(goF, 0);
    Serial.println("0");
  }
}

void dfnnFGF(int nGF){
  Serial.print("Grupo Focal: ");
  Serial.println(nGF);
  switch (nGF){
    case 1 :
      stopF = stopGF1;
      attF = attGF1;
      goF = goGF1;
    break;
    case 2 :
      stopF = stopGF2;
      attF = attGF2;
      goF = goGF2;
    break;
  }
}

void pwGF(int stopV, int attV, int goV, int nGF){
  tlLOG("# # #");
  dfnnFGF(nGF);
  fswGF(stopV, attV, goV, stopF, attF, goF);
  Serial.println("# # #");
}

void setup()
{
  Serial.begin(74880);
  tlLOG("--- Start Setup ---");
  pinMode(stopGF1, OUTPUT);
  pinMode(attGF1, OUTPUT);
  pinMode(goGF1, OUTPUT);
  pinMode(stopGF2, OUTPUT);
  pinMode(attGF2, OUTPUT);
  pinMode(goGF2, OUTPUT);

  tlLOG("=== Start Test ===");
  pwGF(0, 0, 0, 1);
  pwGF(0, 0, 0, 2);


  pwGF(0, 0, 1, 1);
  pwGF(0, 0, 1, 2);
  delay(500);
  pwGF(0, 1, 0, 1);
  pwGF(0, 1, 0, 2);
  delay(500);
  pwGF(1, 0, 0, 1);
  pwGF(1, 0, 0, 2);
  delay(500);

  pwGF(1, 0, 0, 1);
  pwGF(1, 0, 0, 2);
  delay(250);
  pwGF(0, 1, 0, 1);
  pwGF(0, 1, 0, 2);
  delay(250);
  pwGF(0, 0, 1, 1);
  pwGF(0, 0, 1, 2);
  delay(250);

  pwGF(1, 1, 1, 1);
  pwGF(1, 1, 1, 2);
  delay(1000);
  pwGF(0, 0, 0, 1);
  pwGF(0, 0, 0, 2);
  delay(500);
  tlLOG("=== End Test ===");

  tlLOG("--- End Setup ---");
}

void loop()
{
  tlLOG("+++ Start Loop +++");
  pwGF(0, 0, 1, 1);
  pwGF(1, 0, 0, 2);
  delay(8000);
  pwGF(0, 1, 0, 1);
  pwGF(1, 0, 0, 2);
  delay(3000);

  pwGF(1, 0, 0, 1);
  pwGF(0, 0, 1, 2);
  delay(8000);
  pwGF(1, 0, 0, 1);
  pwGF(0, 1, 0, 2);
  delay(3000);
  tlLOG("+++ End Loop +++");
}






