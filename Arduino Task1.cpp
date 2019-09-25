#define pinRed 13
#define pinYellow 12
#define pinGreen 8
#define pinButton 3
#define pinPotentiometer A1

volatile int delayTime = 1000;
volatile bool flag;

void setup() {

  pinMode( pinRed, OUTPUT );
  pinMode( pinYellow, OUTPUT );
  pinMode( pinGreen, OUTPUT );
  pinMode( pinButton, INPUT_PULLUP );
  pinMode( pinPotentiometer, INPUT );

  Serial.begin( 9600 );

  attachInterrupt( 1, reverse, FALLING );

}

void reverse () {
  
  //digitalWrite( pinGreen, LOW );
  lightGreen( 0 );
  lightYellow( delayTime );
  lightRed( delayTime );
  flag = 1;

}

void loop() {
  
  flag = 0;
  
  if( !flag ){
    lightRed( delayTime );
  }
  lightYellow( delayTime );
  lightGreen( delayTime );
  lightYellow( delayTime );

}

void lightRed(int timer) {

  digitalWrite( pinRed, HIGH );
  delay( timer );
  digitalWrite( pinRed, LOW );

}

void lightYellow(int timer) {

  digitalWrite( pinYellow, HIGH );
  delay( timer );
  digitalWrite( pinYellow, LOW );

}

void lightGreen(int timer) {

  digitalWrite( pinGreen, HIGH );
  delay( timer );
  digitalWrite( pinGreen, LOW );

}

