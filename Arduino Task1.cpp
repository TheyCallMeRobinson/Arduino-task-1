#define PIN_RED 13
#define PIN_YELLOW 12
#define PIN_GREEN 8
#define PIN_BUTTON 3
#define PIN_POTENTIOMETER A1

volatile int delayTimer = 1000;
volatile bool flag;

void setup() {

  pinMode( PIN_RED, OUTPUT );
  pinMode( PIN_YELLOW, OUTPUT );
  pinMode( PIN_GREEN, OUTPUT );
  pinMode( PIN_BUTTON, INPUT_PULLUP );
  pinMode( PIN_POTENTIOMETER, INPUT );

  Serial.begin( 9600 );

//  attachInterrupt( 1, reverse, FALLING );

}

//void reverse () {
//  
//  digitalWrite( PIN_GREEN, LOW );
//
//}

void loop() {

  delayTimer = 10 * (analogRead( PIN_POTENTIOMETER ) / 1023);
  if ( delayTimer < 50 ) {
    delayTimer = 50;
  }
  
  lightBulb( delayTimer, "r" );
  lightBulb( delayTimer, "y" );
  
  digitalWrite( PIN_GREEN, HIGH );
  for ( int i = 0; i < delayTimer; i++ ) {
    
    flag = digitalRead( PIN_BUTTON );
    
    if (!flag) {
      
      delay(1);
    
    } else {
      
      digitalWrite( PIN_GREEN, LOW );
      break;
    
    }
  
  }
  digitalWrite( PIN_GREEN, LOW );
  
  lightBulb( delayTimer, "y" );

}

void lightBulb( int timer, char modeBulb ) {

  if (modeBulb = "r"){
    
    digitalWrite( PIN_RED, HIGH );
    delay( timer );
    digitalWrite( PIN_RED, LOW );
  
  } else if (modeBulb = "y") {
    
    digitalWrite( PIN_YELLOW, HIGH );
    delay( timer );
    digitalWrite( PIN_YELLOW, LOW );
  
  } else if (modeBulb = "g") {
    
    digitalWrite( PIN_GREEN, HIGH );
    delay( timer );
    digitalWrite( PIN_GREEN, LOW );
  
  }
  
}

