#define PIN_RED 13
#define PIN_YELLOW 12
#define PIN_GREEN 8
#define PIN_BUTTON 3
#define PIN_POTENTIOMETER A1

volatile int delayTime = 1000;

void setup() {

  pinMode( PIN_RED, OUTPUT );
  pinMode( PIN_YELLOW, OUTPUT );
  pinMode( PIN_GREEN, OUTPUT );
  pinMode( PIN_BUTTON, INPUT_PULLUP );
  pinMode( PIN_POTENTIOMETER, INPUT );

  Serial.begin( 9600 );

  attachInterrupt( 1, reverse, FALLING );

}

void reverse () {
  
  digitalWrite( PIN_GREEN, LOW );

}

void loop() {

  delayTime = analogRead( PIN_POTENTIOMETER );
  
  lightRed( delayTime );
  lightYellow( delayTime );
  //lightGreen( delayTime );
  digitalWrite( PIN_GREEN, HIGH);
  
  for (int i = 0; i < delayTime; i++) {
  	digitalRead(flag1);
  	if (!flag1) {
  		delay(1);
	} else {
		digitalWrite( PIN_GREEN, LOW );
		break;
	}
  }
  
  digitalWrite( PIN_GREEN, LOW);
  lightYellow( delayTime );

}

void lightRed( int timer, string modeBulb ) {

  digitalWrite( PIN_RED, HIGH );
  delay( timer );
  digitalWrite( PIN_RED, LOW );

}

void lightYellow( int timer ) {

  digitalWrite( PIN_YELLOW, HIGH );
  delay( timer );
  digitalWrite( PIN_YELLOW, LOW );

}

void lightGreen( int timer ) {

  digitalWrite( PIN_GREEN, HIGH );
  delay( timer );
  digitalWrite( PIN_GREEN, LOW );

}

