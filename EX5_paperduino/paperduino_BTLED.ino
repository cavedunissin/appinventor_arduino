#include <SoftwareSerial.h> //�ޥ�SoftwareSerial�禡�w

int led = 1;  //LED�bDI1
SoftwareSerial BT(3, 4); //�]�w�Ť��bPaperduino�WTX�BRX���}��

void setup() {
  BT.begin(9600);//�]�w�P�Ū޳q�T���j�v
  pinMode(led, OUTPUT);
}

void loop() {
  int insize;
  byte cmmd[20];
  if ((insize = BT.available() > 0)) //�P�_�O�_���������Ť��T��
  {
    for (int i = 0; i < insize; i++)
      cmmd[i] = BT.read(); //Ū���Ť���T
    switch (cmmd[0])
    {
      case 'a'://�Y������r��'a'�ɡA�h��LED�G
        digitalWrite(led, HIGH);
        break;
      case 'b'://�Y������r��'b'�ɡA�h��LED�G
        digitalWrite(led, LOW);
        break;
    }
  }
}