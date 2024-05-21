///////////////////////
#include <SD.h>
#include <TMRpcm.h>
#include <stdio.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;
///////////////////////
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//////////////////////
int lm35 = A1;
int relay = 0;
int relay2 = 1;
char file[64];
const char* file_n = "";
//String file_2[] = {"0","1"};
//////////list_file///////////
/*const char *file_name[] = {"0.wav", "1.wav", "2.wav", "3.wav", "4.wav", "5.wav",
                    "6.wav", "7.wav", "8.wav", "9.wav",
                    "10.wav", "11.wav", "12.wav", "13.wav", "14.wav",
                    "15.wav", "16.wav", "17.wav", "18.wav", "19.wav",
                    "20.wav", "21.wav", "22.wav", "23.wav", "24.wav",
                    "25.wav", "26.wav", "27.wav", "28.wav", "29.wav", "30.wav"
                   };*/
////////////////////
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600); //Serial Com for debugging
  tmrpcm.speakerPin = 9; //Auido out on pin 9
  tmrpcm.quality(1);
  //////////////////////
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  if (SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD OK");
    return;
  }
  /////////////////////
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  ////////////////////////////
  int damadc = analogRead(lm35);
  int dama = damadc * 4.88;
  dama = dama / 10;
  ////////////////////////////
  lcd.setCursor(0, 0);
  lcd.print("Dama=");
  lcd.setCursor(6, 0);
  lcd.print(dama);
  lcd.setCursor(9, 0);
  lcd.print("c");
  lcd.setCursor(0, 1);
  lcd.print("matin omid");
  delay(1000);
  lcd.clear();
  ///////////////////////
  /* sprintf(file,"%d",dama);
    strcat(file, ".wav");
    to_string(dama) + ".wav";
    String file = file_2[dama] + ".wav";
    char file = dama;
    char sx = ".wav";
    strcat(file,sx);
    sprintf(file,64,"%s%d.wav",file_n,dama);*/
  //file  = "dfdfd"; file_name[dama]// sprintf(file_name,30, "%s%d");
  //tmrpcm.play(FIN(dama));
  if (digitalRead(10) == 1) {
    int x  = dama;
    if(x==0){tmrpcm.play("0.wav");}
    if(x==1){tmrpcm.play("1.wav");}
    if(x==2){tmrpcm.play("2.wav");}
    if(x==3){tmrpcm.play("3.wav");}
    if(x==4){tmrpcm.play("4.wav");}
    if(x==5){tmrpcm.play("5.wav");}
    if(x==6){tmrpcm.play("6.wav");}
    if(x==7){tmrpcm.play("7.wav");}
    if(x==8){tmrpcm.play("8.wav");}
    if(x==9){tmrpcm.play("9.wav");}
    if(x==10){tmrpcm.play("10.wav");}
    if(x==11){tmrpcm.play("11.wav");}
    if(x==12){tmrpcm.play("12.wav");}
    if(x==13){tmrpcm.play("13.wav");}
    if(x==14){tmrpcm.play("14.wav");}
    if(x==15){tmrpcm.play("15.wav");}
    if(x==16){tmrpcm.play("16.wav");}
    if(x==17){tmrpcm.play("17.wav");}
    if(x==18){tmrpcm.play("18.wav");}
    if(x==19){tmrpcm.play("19.wav");}
    if(x==20){tmrpcm.play("20.wav");}
    if(x==21){tmrpcm.play("21.wav");}
    if(x==22){tmrpcm.play("22.wav");}
    if(x==23){tmrpcm.play("23.wav");}
    if(x==24){tmrpcm.play("24.wav");}
    if(x==25){tmrpcm.play("25.wav");}
    if(x==26){tmrpcm.play("26.wav");}
    if(x==27){tmrpcm.play("27.wav");}
    if(x==28){tmrpcm.play("28.wav");}
    if(x==29){tmrpcm.play("29.wav");}
    if(x==30){tmrpcm.play("30.wav");}
    

  }

  if (dama >= 37) {
    digitalWrite(relay, HIGH);
    if (dama <= 17) {
      digitalWrite(relay2, HIGH);
    }
  }
}
