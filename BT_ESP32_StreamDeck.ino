/*******************************************************************
Disaster of Puppets
YouTube: Http://disasterofpuppets.com
Twitch: Https://twitch.tv/disasterofpuppets

//I needed to use (DOIT ESP32 DEVKIT V1) as the board I had, yours may differ
Don't forget to press the flash button when uploading the sketch

Based on Tv-K's https://github.com/T-vK/ESP32-BLE-Keyboard

 *******************************************************************/

#include <BleKeyboard.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

bool muted = 1;
int runonce = 0;

BleKeyboard bleKeyboard;

int keypress = 1000; // delay between keypad press and release
const byte ROWS = 6;
const byte COLS = 8;

char hexaKeys[ROWS][COLS] = 
{

    {'0', '1', '2', '3', '4', '5', '6', '7'}, 
    {'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'},
    {'G', 'H', '~', '~', '~', '~', 'I', 'J'},
    {'K', 'L', '~', '~', '~', '~', 'M', 'N'},
    {'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
    {'W', 'X', 'Y', 'Z', '!', '@', '#', '$'},
};

byte rowPins[ROWS] = {13, 14, 27, 26, 25, 33}; //13,14,27,26,25,33 
byte colPins[COLS] = {15,16,17,18,19,23,32,4}; // PINS 15,RX2,TX2,18,19,23,32,4

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LiquidCrystal_I2C lcd(0x27,16,2); 


// put your setup code here, to run once:
void setup() {
  

  Serial.begin(115200);
  bleKeyboard.begin();
  
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();

}

void loop() {

/*
 * This works..because outside of the matrix code?
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
Serial.println("Pausing Music...");
bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
delay(1000);
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
Serial.println("Resuming Music...");
bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
*/

  if(bleKeyboard.isConnected()) {



if (runonce == 0){
//run your default state here, eg I duplicated button 1's functionality

    Serial.println("Connected to Bluetooth");
    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("D.I.Y. Stream Deck");
    lcd.setCursor(0,1);
    lcd.print("                ");
    runonce = 1;
}

  /* 
   //saving here for example of multiple keys at once
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */


//*********** Keypad Matrix *************
char customKey = customKeypad.getKey();
 
if (customKey){
     switch (customKey){

// ROW 1-------------------------------------------        


// Live   
    
  case '0':
    Serial.println("0");

    Serial.println("PAUSE");
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        //this was working when using the example code. Keypad issue / incompatability?
    delay(keypress);

    
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("PC / Live");
  break;

// Craft Desk

  case '1':
    Serial.println("1");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Blur ON");
  break;

// Craft Desk FullScreen Cam

  case '2':
    Serial.println("2");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Blur OFF");
  break;

// Spare

  case '3':
   Serial.println("3");

    delay(keypress);
    break;

// Idle

  case '4':
    Serial.println("4");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Idle");
    break;

//Disclaimer

  case '5':
    Serial.println("5");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Disclaimer");
    break;

// Zoom

  case '6':
    Serial.println("6");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Zoom");
    break;

// BRB
  case '7':
    Serial.println("7");        

    Serial.println("Sending F20...");
    bleKeyboard.write(KEY_F20);
    
    
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("BRB");
    break;

// ROW 2 ---------------------------------

// Fullscreen PC Webcam

  case '8':
    Serial.println("8");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("FS Cam");
    break;

//Spare

  case '9':
    Serial.println("9");
    delay(keypress);
    break;

// Dodgy Paintbrush Time
  case 'A':
    Serial.println("A");

    delay(keypress);           
    break;

//Spare
  case 'B':
    Serial.println("B");
    delay(keypress);
    break;

//Red
  case 'C':
    Serial.println("C");

    delay(keypress);
    break;

//Green
  case 'D':
    Serial.println("D");

    delay(keypress);
    break;

//Blue
  case 'E':
    Serial.println("E");

    delay(keypress);
    break;

//DoorPrize
  case 'F':
    Serial.println("F");

    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Door Prize");
    break;

// ROW 3 ---------------------------------

// Logitech Webcam Toggle

  case 'G':
    Serial.println("G");

      delay(keypress);
      break;

// Panasonic Cam Toggle

  case 'H':
    Serial.println("H");

      delay(keypress);
      break;
    
// Spare

  case 'I':
    Serial.println("I");

    delay(keypress);
    break;

// Spare

  case 'J':
    Serial.println("J");

      delay(keypress);
      break;
          
    
// ROW 4 ---------------------------------


//Iphone Desk Cam Toggle

  case 'K':
    Serial.println("K");

      delay(keypress);
      break;

// Iphone Bot Cam Toggle
  
  case 'L':
    Serial.println("L");

      delay(keypress);
      break;

//Nulls

  case '~':
    Serial.println("~ NULL ~");
    delay(keypress);
    break;

// Spare

  case 'M':
      Serial.println("M");

      delay(keypress);  
      break;

// Spare

  case 'N':
      Serial.println("N");

      delay(keypress);
      break;          

// ROW 5 ---------------------------------

// Stamp

  case 'O':
    Serial.println("O");

    delay(keypress);
    break;

// BS

  case 'P':
    Serial.println("P");

    delay(keypress);
    break;

// KISS

  case 'Q':
    Serial.println("Q");

    delay(keypress);
    break;

//PUN

  case 'R':
    Serial.println("R");

    delay(keypress);
    break;

// Who are these people?

  case 'S':
    Serial.println("S");

    delay(keypress);
    break;

// I disagree

  case 'T':
    Serial.println("T");

    delay(keypress);
    break;

// Sexytimes

  case 'U':
    Serial.println("U");

    delay(keypress);
    break;

// Why is / isn't it working gif?

  case 'V':
    Serial.println("V");

    delay(keypress);
    break;       

// ROW 6 ------------------------------

// GG

  case 'W': 
    Serial.println("W");

    delay(keypress);
    break;

// McScuse me          

  case 'X':
    Serial.println("X");

    delay(keypress);
    break;

// Cheese it

  case 'Y':
    Serial.println("Y");

    delay(keypress);
    break;

// Tech support

  case 'Z':
    Serial.println("Z");

    delay(keypress);
    break;

// Sthap it

  case '!':
    Serial.println("!");

    delay(keypress);
    break;   

// Phrasing

  case '@':
    Serial.println("@");

    delay(keypress);
    break;   

// Kruiz Control Reset

  case '#':
    Serial.println("#");

    delay(keypress);
    break;   

// Mute

  case '$':
    Serial.println("$");
    if (muted) {

      delay(keypress);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("***MUTED***");
      muted = 0;
    }
    else if (!muted) {

      delay(keypress);
      lcd.setCursor(0,1);
      lcd.print("                ");
      muted = 1;     
    }
    break;
            
            
     }
  }
  
}
}

 
