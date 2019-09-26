#define PIN_RED 13
#define PIN_YELLOW 12
#define PIN_GREEN 8
#define PIN_BUTTON 3
#define PIN_POTENTIOMETER A1

volatile double delayTimer = 1000;
volatile int delayTimerInteger;
volatile bool flag;

void setup() {

  pinMode( PIN_RED, OUTPUT );
  pinMode( PIN_YELLOW, OUTPUT );
  pinMode( PIN_GREEN, OUTPUT );
  pinMode( PIN_BUTTON, INPUT_PULLUP );
  pinMode( PIN_POTENTIOMETER, INPUT );

  Serial.begin( 9600 );

}

void loop() {

  delayTimer = 10000 * (analogRead( PIN_POTENTIOMETER ) / 1023);
  if ( delayTimer < 50 ) {
    delayTimer = 50;
  }
  delayTimerInteger = static_cast<int>( std::round(delayTimer) );
  
  lightBulb( delayTimerInteger, PIN_RED );
  lightBulb( delayTimerInteger, PIN_YELLOW );
  
  digitalWrite( PIN_GREEN, HIGH );
  for ( int i = 0; i < delayTimerInteger; i++ ) {
    
    flag = digitalRead( PIN_BUTTON );
    
    if (!flag) {
      
      delay(1);
    
    } else {
      
      digitalWrite( PIN_GREEN, LOW );
      break;
    
    }
  
  }
  digitalWrite( PIN_GREEN, LOW );
  
  lightBulb( delayTimerInteger, PIN_YELLOW );

}

void lightBulb( int timer, int modeBulb ) {

  if (modeBulb = PIN_RED){
    
    digitalWrite( PIN_RED, HIGH );
    delay( timer );
    digitalWrite( PIN_RED, LOW );
  
  } else if (modeBulb = PIN_YELLOW) {
    
    digitalWrite( PIN_YELLOW, HIGH );
    delay( timer );
    digitalWrite( PIN_YELLOW, LOW );
  
  } else if (modeBulb = PIN_GREEN) {
    
    digitalWrite( PIN_GREEN, HIGH );
    delay( timer );
    digitalWrite( PIN_GREEN, LOW );
  
  }
  
}

