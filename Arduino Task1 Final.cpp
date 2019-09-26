#define PIN_RED 13
#define PIN_YELLOW 12
#define PIN_GREEN 8
#define PIN_BUTTON 3
#define PIN_POTENTIOMETER A0

volatile int delayTime;
volatile bool flag;

void setup() {

  pinMode( PIN_RED, OUTPUT );
  pinMode( PIN_YELLOW, OUTPUT );
  pinMode( PIN_GREEN, OUTPUT );
  pinMode( PIN_BUTTON, INPUT_PULLUP );
  pinMode( PIN_POTENTIOMETER, INPUT );

}

void loop() {
  
  delayTime = analogRead( PIN_POTENTIOMETER );
  
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
    for (int i = 0; i < timer; i++) {
      flag = digitalRead( PIN_BUTTON );
    
      if ( flag ) {
        delay(1);
      } else {
        digitalWrite( PIN_YELLOW, LOW );
        i = timer;
      }
    }
    digitalWrite( PIN_YELLOW, LOW );
    
  }

  if (modeBulb == PIN_GREEN) {
    
    digitalWrite( PIN_GREEN, HIGH );
    for (int i = 0; i < timer; i++) {
      flag = digitalRead( PIN_BUTTON );
    
      if ( flag ) {
        delay(1);
      } else {
        digitalWrite( PIN_GREEN, LOW );
        i = timer;
        digitalWrite( PIN_YELLOW, HIGH );
        delay (timer);
        
      }
    }
    digitalWrite( PIN_GREEN, LOW );
    
  }
}
