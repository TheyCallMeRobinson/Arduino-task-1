#define PIN_RED 13
#define PIN_YELLOW 12
#define PIN_GREEN 8

volatile int delayTime = 1000;

void setup() {

  pinMode( PIN_RED, OUTPUT );
  pinMode( PIN_YELLOW, OUTPUT );
  pinMode( PIN_GREEN, OUTPUT );

}

void loop() {
  
  lightEnable( delayTime, PIN_RED );
  lightEnable( delayTime, PIN_YELLOW );
  lightEnable( delayTime, PIN_GREEN );
  lightEnable( delayTime, PIN_YELLOW );

}

void lightEnable( int timer, int modeBulb ) {

  if (modeBulb == PIN_RED){
    
    digitalWrite( PIN_RED, HIGH );
    delay( timer );
    digitalWrite( PIN_RED, LOW );
  
  } 
  
  if (modeBulb == PIN_YELLOW) {
    
    digitalWrite( PIN_YELLOW, HIGH );
    delay( timer );
    digitalWrite( PIN_YELLOW, LOW );
    
  }

  if (modeBulb == PIN_GREEN) {
    
    digitalWrite( PIN_GREEN, HIGH );
    delay( timer );
    digitalWrite( PIN_GREEN, LOW );
    
  }
}
