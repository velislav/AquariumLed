// Congiguration for Termometar
  #include <OneWire.h> 
  int DS18S20_Pin = 2; //DS18S20 Signal pin on digital 2
  float NewTemperature;
  OneWire ds(DS18S20_Pin);  // on digital pin 2

// Configuration for Real Time Clock
  #include <Wire.h>
  #include "RTClib.h"
  RTC_DS1307 RTC;
  String Time;
  unsigned long TimeInSec;
  // if you want to Ajust the Real Time Clock from your PC, change the value to 1. This is recommended for first run only. Must be changed to 0 with second fast upload exactly after the first one !
  byte AjustTheRealTimeClock = 0;
  int DayOfMonth;

// Configuration for Fan
  const int FanPin = 11;
  // The fun will start if the temperature is above 30 degree C.
  const int FanTempTrigger = 30;
  int FanStatus;
  
// Configuration for Led Lighting
// PWM: 3, 5, 6, 9, 10, and 11. Provide 8-bit PWM output with the analogWrite() function. 
  const int TwoBlueLeds = 5;
  const int TwoWhiteLeds = 6;
  const int ThreeWhiteLeds = 9;
  const int FourRedLeds = 10;
  int Brightness = 0;
  int BlueBeforeTwilightStart = 0;
  int BlueAfterTwilightEnd = 0;
  int RiseTheTimeInSecWith1Day = 0;

// Configuration for LCD
  /*
    The circuit:
   * LCD RS pin to digital pin 13
   * LCD Enable pin to digital pin 12
   * LCD D4 pin to digital pin 8
   * LCD D5 pin to digital pin 7
   * LCD D6 pin to digital pin 4
   * LCD D7 pin to digital pin 3
   * LCD R/W pin to ground
   * 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)
  
   */
  
  // include the library code:
  #include <LiquidCrystal.h>
  
  // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(13, 12, 8, 7, 4, 3);
  

// Led Lighting Part 1
  //These 2 functions will rise or drop the brightness on Arduino's PWM output using 5 parameters: 
  // 1. PWM output Pin. This one can be 3,5,6,9 or 11 for Arduino Uno R3;
  // 2. Start Time in format HH:MM:SS start from 00:00:00 to 23:59:59; 
  // 3. End Time in format HH:MM:SS start from 00:00:00 to 23:59:59;
  // 4. Start Brightness. This value should be between 0 (the leds are off) and 255 (max brightness);
  // 5. End Brightness. This value should be between 0 (the leds are off) and 255 (max brightness);
  //
  // Notes: Start Time should be < from End Time for RiseTheBrightness and Start Time should be < from End Time for DropTheBrightness.
  // Start Brightness should be < from End Brightness for RiseTheBrightness and Start Brightness should be > from End Brightness for DropTheBrightness.
  //
  // 255-(50/1050 * 255) = 242.857142857 White and Red
  // 255-(100/1050* 255) = 230.714285714 Blue
  //  	            Astronomical	Nautical	Civil	 	 	Azimuth	                                                Length of day	            Solar noon
  //    Date	        Twilight	Twilight	Twilight	Sunrise	Sunset	Sunrise	              Sunset                   This day   Difference     Time Altitude Distance
  //                  starts	ends	starts	ends	starts	ends	                                                                                                                       (million km)
  //
  //     11 Aug 2013	04:54	19:16	05:19	18:52	05:44	18:27	06:05	18:05	75°East-northeast	285°West-northwest	12h 00m 05s	+ 07s	12:05	71.8° 	151.598
  void LedLighting() {   
    // Temp
    int TestOn = 0;
    if (TestOn == 1) {
          //RiseTheBrightness(TwoBlueLeds, "00:00:00", "23:59:59", 1, 1);
          //RiseTheBrightness(TwoWhiteLeds, "00:00:00", "23:59:59", 1, 1);
          //RiseTheBrightness(ThreeWhiteLeds, "00:00:00", "23:59:59", 1, 1);
          //RiseTheBrightness(FourRedLeds, "00:00:00", "23:59:59", 1, 1);   
    }

    // Main light configuration       
      // Twilight start:  05:44 - 06:05
        //RiseTheBrightness(TwoBlueLeds, "05:44:00", "06:05:00", BlueBeforeTwilightStart, 30);
        //RiseTheBrightness(TwoWhiteLeds, "05:44:00", "06:05:00", 0, 5);
        //RiseTheBrightness(ThreeWhiteLeds, "05:55:00", "06:05:00", 0, 5);
        
      // Sunrise:         06:05 - 06:15
        //RiseTheBrightness(TwoBlueLeds, "06:05:00", "06:15:00", 30, 100);
        //RiseTheBrightness(FourRedLeds, "06:05:00", "06:15:00", 1, 100);
        //RiseTheBrightness(TwoWhiteLeds, "06:05:00", "06:15:00", 5, 100);
        //RiseTheBrightness(ThreeWhiteLeds, "06:05:00", "06:15:00", 5, 100);
      
      // Day Light:       06:15 - 12:05, 12:05 - 17:55       
        //RiseTheBrightness(TwoBlueLeds, "06:15:00", "12:05:00", 100, 130);
        //RiseTheBrightness(FourRedLeds, "06:15:00", "12:05:00", 100, 130);
        //RiseTheBrightness(TwoWhiteLeds, "06:15:00", "12:05:00", 100, 130);
        //RiseTheBrightness(ThreeWhiteLeds, "06:15:00", "12:05:00", 100, 130);
        
        //DropTheBrightness(TwoBlueLeds, "12:05:00", "17:55:00", 130, 100);
        //DropTheBrightness(FourRedLeds, "12:05:00", "17:55:00", 130, 100);
        //DropTheBrightness(TwoWhiteLeds, "12:05:00", "17:55:00", 130, 100);
        //DropTheBrightness(ThreeWhiteLeds, "12:05:00", "17:55:00", 130, 100);
      
      // Sunset:          17:55 - 18:05
        //DropTheBrightness(TwoBlueLeds, "17:55:00", "18:05:00", 100, 30);
        //DropTheBrightness(FourRedLeds, "17:55:00", "18:05:00", 100, 0);
        //DropTheBrightness(TwoWhiteLeds, "17:55:00", "18:05:00", 100, 5);
        //DropTheBrightness(ThreeWhiteLeds, "17:55:00", "18:05:00", 100, 5);  
      
      // Twilight end:    18:05 - 18:27
        //DropTheBrightness(TwoBlueLeds, "18:05:00", "18:27:00", 30, BlueAfterTwilightEnd);
        //DropTheBrightness(TwoWhiteLeds, "18:05:00", "18:27:00", 5, 0);
        //DropTheBrightness(ThreeWhiteLeds, "18:05:00", "18:16:00", 5, 0);
        
     
    // Moon phase
    // To configure Moon phase just change ActivateMoonPhaseLight = 1 for ON and ActivateMoonPhaseLight = 0 for OFF.
    byte ActivateMoonPhaseLight = 0;
    if (ActivateMoonPhaseLight == 1) {    
      if (DayOfMonth == 1) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 1;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "19:18:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "19:18:00", "19:28:00", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 2) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 2;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "20:04:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "20:04:00", "20:14:00", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 3) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 4;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "20:51:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "20:51:00", "21:01:00", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 4) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 7;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "21:39:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "21:39:00", "21:49:00", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 5) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 10;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "22:20:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "22:20:00", "22:30:00", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 6) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 13;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:23:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "23:23:00", "23:33:00", BlueAfterTwilightEnd, 0);      
      }    
      if (DayOfMonth == 7) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 17;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:50:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "23:50:00", "23:59:59", BlueAfterTwilightEnd, 0);      
      }
      if (DayOfMonth == 8) {
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 20;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);      
      }
      if (DayOfMonth == 9) {
        // Continue from date 8
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 20;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "00:20:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "00:20:00", "00:30:00", BlueAfterTwilightEnd, 0);
        
        // Actual day
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 23;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);     
      }
      if (DayOfMonth == 10) {
        // Continue from date 9
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 23;        
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "01:18:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);        
        DropTheBrightness(TwoBlueLeds, "01:18:00", "01:28:00", BlueAfterTwilightEnd, 0); 
        
        // Actual day
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 26;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
      }
      if (DayOfMonth == 11) {
        // Continue from date 10
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 26;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "02:18:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "02:18:00", "02:28:00", BlueAfterTwilightEnd, 0);      
        
        // Actual Day
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 28;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
              
      }
      if (DayOfMonth == 12) {
        // Continue from date 11
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 28;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "03:18:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);        
        DropTheBrightness(TwoBlueLeds, "03:18:00", "03:28:00", BlueAfterTwilightEnd, 0);
        
        // Actual Day
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 29;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);   
      }
      if (DayOfMonth == 13) {
        // Continue from date 12
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 29;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "04:16:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "04:16:00", "04:26:00", BlueAfterTwilightEnd, 0);
        
        // Actual Day
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 30;
        RiseTheBrightness(TwoBlueLeds, "18:27:00", "23:59:59", BlueAfterTwilightEnd, BlueAfterTwilightEnd);    
      }    
      if (DayOfMonth == 14) {
        // Continue from date 13        
        BlueBeforeTwilightStart = 0;
        BlueAfterTwilightEnd = 30;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:12:00", BlueAfterTwilightEnd, BlueAfterTwilightEnd);
        DropTheBrightness(TwoBlueLeds, "05:12:00", "05:22:00", BlueAfterTwilightEnd, 0);           
        
        // Actual Day
        BlueBeforeTwilightStart = 30;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "18:41:00", "18:51:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "18:51:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }        
      if (DayOfMonth == 15) {
        // Continue from date 14
        BlueBeforeTwilightStart = 30;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);

        // Actual Day        
        BlueBeforeTwilightStart = 29;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "19:33:00", "19:43:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "19:43:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }    
      if (DayOfMonth == 16) {
        // Continue from date 15
        BlueBeforeTwilightStart = 29;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
        
        // Actual Day
        BlueBeforeTwilightStart = 28;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "20:24:00", "20:34:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "20:34:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }    
      if (DayOfMonth == 17) {
        // Continue from date 16
        BlueBeforeTwilightStart = 28;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);        
        
        // Actual Day
        BlueBeforeTwilightStart = 26;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "21:14:00", "21:24:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "21:24:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 18) {
        // Continue from date 17
        BlueBeforeTwilightStart = 26;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);        
        
        // Actual Day
        BlueBeforeTwilightStart = 23;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "22:03:00", "22:13:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "22:13:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 19) {
        // Continue from date 18
        BlueBeforeTwilightStart = 23;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);        
        
        // Actual Day
        BlueBeforeTwilightStart = 21;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "22:52:00", "23:02:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "23:02:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 20) {
        // Continue from date 19
        BlueBeforeTwilightStart = 21;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);

        // Actual Day        
        BlueBeforeTwilightStart = 18;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "23:41:00", "23:51:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "23:51:00", "23:59:59", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 21) {
        // Continue from date 20
        BlueBeforeTwilightStart = 18;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);        
      }
      if (DayOfMonth == 22) {
        BlueBeforeTwilightStart = 15;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "00:00:00", "00:10:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "00:10:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);        
      }
      if (DayOfMonth == 23) {
        BlueBeforeTwilightStart = 12;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "00:30:00", "00:40:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "00:40:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 25) {
        BlueBeforeTwilightStart = 9;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "01:18:00", "01:28:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "01:38:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }    
      if (DayOfMonth == 24) {
        BlueBeforeTwilightStart = 7;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "02:05:00", "02:15:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "02:15:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 26) {
        BlueBeforeTwilightStart = 4;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "02:51:00", "03:01:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "03:01:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);    
      }
      if (DayOfMonth == 27) {
        BlueBeforeTwilightStart = 3;
        BlueAfterTwilightEnd = 0;        
        RiseTheBrightness(TwoBlueLeds, "03:37:00", "03:47:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "03:47:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }
      if (DayOfMonth == 28) {
        BlueBeforeTwilightStart = 1;
        BlueAfterTwilightEnd = 0;
        RiseTheBrightness(TwoBlueLeds, "04:22:00", "04:32:00", 1, BlueBeforeTwilightStart);      
        RiseTheBrightness(TwoBlueLeds, "04:32:00", "05:44:00", BlueBeforeTwilightStart, BlueBeforeTwilightStart);
      }  
    }
  }



// Do not touch below this line !
void setup() {
  // Setup for LCD
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
  // Setup for Termometar
    Serial.begin(9600);
  // Setup for Real Time Clock
    //Serial.begin(57600);
    Wire.begin();
    RTC.begin();
    if (AjustTheRealTimeClock == 1) {
      RTC.adjust(DateTime(__DATE__, __TIME__));
    }
    if (! RTC.isrunning()) {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      //RTC.adjust(DateTime(__DATE__, __TIME__));
    }

}

void loop() {
  // Loop for Real Time Clock
    RealTimeClock();
  // Loop for Termometar
    Temperature();
  // Loop for Led Lighting
    LedLighting();  
  // Fan();  
    Fan();
  // General delay
    delay(1000);
}

//// Fan Part
  void Fan() {
    // Stop the fan if the fan is not stopped and temp is below FanTempTrigger and be sure that the last value is not very close to the the new one.
      if ((NewTemperature < (FanTempTrigger-1)) && (FanStatus == 1)) {
        analogWrite(FanPin,0);
        FanStatus = 0;
      }
    // Start the fan if the fan is not started and temp is above FanTempTrigger
    if ((NewTemperature >= FanTempTrigger) && (FanStatus == 0)){
      analogWrite(FanPin,255);
      FanStatus = 1;
    }
  }


//// Real Time Clock Part
  void RealTimeClock() {
    String TempRTCHours;
    String TempRTCMinutes;
    String TempRTCSeconds;
    DateTime now = RTC.now();
      
    //Hours format
    if (now.hour() < 10) {
      TempRTCHours = "0" + String(now.hour());
    } else {
      TempRTCHours = String(now.hour());
    }
    
    // Minutes format
    if (now.minute() < 10) {
      TempRTCMinutes = "0" + String(now.minute());
    } else {
      TempRTCMinutes = String(now.minute());
    }
    
    // Seconds format
    if (now.second() < 10) {
      TempRTCSeconds = "0" + String(now.second());
    } else {
      TempRTCSeconds = String(now.second());
    }
     
    Time = TempRTCHours + ":" + TempRTCMinutes + ":" + TempRTCSeconds;
    //unsigned long HoursRTCInSec;
    //unsigned long MinutesRTCInSec;
    //unsigned long SecondsRTCInSec;
    //int HoursRTC = int(now.hour());
    //Serial.print("HoursRTC from RealTimeClock function: ");
    //Serial.println(HoursRTC);
    
    //HoursRTCInSec = long(HoursRTC)*3600;
    //Serial.print("HoursRTCInSec from RealTimeClock function: ");
    //Serial.println(HoursRTCInSec);

    //MinutesRTCInSec = long(now.minute()*60);
    //Serial.print("MinutesRTCInSec from RealTimeClock function: ");
    //Serial.println(MinutesRTCInSec);
    
    //SecondsRTCInSec = long(now.second());
    //Serial.print("SecondsRTCInSec from RealTimeClock function: ");
    //Serial.println(SecondsRTCInSec);
    
    TimeInSec =  long(now.hour())*3600 + long(now.minute())*60 + long(now.second());
    //Serial.print("TimeInSec from RealTimeClock function: ");
    //Serial.println(TimeInSec);
    
    Serial.print("    ");
    Serial.println(Time);
    lcd.setCursor(4, 0);
    lcd.print(Time);
    
    // Store the day of the month. This is needed for moon phase calculation.
    DayOfMonth = int(now.day());
  }

//// Temperature part
  void Temperature() {  
    NewTemperature = getTemp();
      Serial.print("    ");
      Serial.print(NewTemperature);
      Serial.println(" C");
      Serial.println();
      lcd.setCursor(4, 1);
      lcd.print(NewTemperature);
      lcd.setCursor(9, 1);
      lcd.print(" ");
      lcd.setCursor(10, 1);
      lcd.print((char)223);
      lcd.setCursor(11, 1);
      lcd.print("C");
  }
  
  float getTemp(){
    //returns the temperature from one DS18S20 in DEG Celsius
    byte data[12];
    byte addr[8];
  
    if ( !ds.search(addr)) {
        //no more sensors on chain, reset search
        ds.reset_search();
        return -1000;
    }
    if ( OneWire::crc8( addr, 7) != addr[7]) {
        Serial.println("CRC is not valid!");
        return -1000;
    }
    if ( addr[0] != 0x10 && addr[0] != 0x28) {
        Serial.print("Device is not recognized");
        return -1000;
    }
    
    ds.reset();
    ds.select(addr);
    ds.write(0x44,1); // start conversion, with parasite power on at the end
    byte present = ds.reset();
    ds.select(addr);    
    ds.write(0xBE); // Read Scratchpad
  
    for (int i = 0; i < 9; i++) { // we need 9 bytes
      data[i] = ds.read();
    }
    
    ds.reset_search();
    
    byte MSB = data[1];
    byte LSB = data[0];
  
    float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float TemperatureSum = tempRead / 16;
    
    return TemperatureSum; 
  }




//// Led Lighting Part 2
  void RiseTheBrightness(int LedPin, String StartTimeString, String EndTimeString, int StartBrightness, int EndBrightness) {
    //Serial.println(" ");
    //Serial.print("Converting StartTimeString to StartTime numbers ... ");    
    unsigned long StartTime = ConvertTimeToSec(StartTimeString);
    //Serial.println("Done!");
    //Serial.print("StartTime: ");
    //Serial.println(StartTime);

    //Serial.print("Converting EndTimeString to EndTime numbers ... ");    
    unsigned long EndTime = ConvertTimeToSec(EndTimeString);
    //Serial.println("Done!");
    //Serial.print("EndTime: ");
    //Serial.println(EndTime);
    
    //Serial.print("TimeInSec: ");
    //Serial.println(TimeInSec);
      
    // If the EndTime is a hour from next day add 86400 sec = 1 day 
    if (EndTime < StartTime) {
      if (TimeInSec <  EndTime) {
        TimeInSec = TimeInSec + 86400;
        int RiseTheTimeInSecWith1Day = 1;
        //Serial.print("TimeInSec plus 24h: ");
        //Serial.println(TimeInSec);
      }
      EndTime = EndTime + 86400;
      //Serial.print("StartTime: ");
      //Serial.println(StartTime);
      //Serial.print("EndTime plus 24h: ");
      //Serial.println(EndTime);
    }
    
    // Calculate the rising time
    float RisingTime = EndTime - StartTime;
    float BrightnessDelta = EndBrightness - StartBrightness;
    float SecToNextBrightnessChange = RisingTime / BrightnessDelta;
    
    if ((TimeInSec > StartTime) && (TimeInSec <= EndTime)) {
      //Serial.print("Entering the Rise Loop for LedPin: ");
      //Serial.println(LedPin);
      //Serial.print("TimeInSec: ");
      //Serial.println(TimeInSec);
      //Serial.print("Brightness: ");
      //Serial.println(Brightness);
      
      // Calculating the first Brightness value
      if ((Brightness < StartBrightness) || (Brightness > EndBrightness)) {
        Brightness = StartBrightness;
        analogWrite(LedPin,Brightness);
      }
      if ((Brightness >= StartBrightness) && (Brightness <= EndBrightness)) {
        Brightness = StartBrightness + (1 * (TimeInSec - StartTime)/SecToNextBrightnessChange);
        analogWrite(LedPin,Brightness);
      }
    }
    if (RiseTheTimeInSecWith1Day == 1) {
      TimeInSec = TimeInSec - 86400;      
      RiseTheTimeInSecWith1Day = 0;
    }     
  }
  
  void DropTheBrightness(int LedPin, String StartTimeString, String EndTimeString, int StartBrightness, int EndBrightness) {
    unsigned long StartTime = ConvertTimeToSec(StartTimeString);
    unsigned long EndTime = ConvertTimeToSec(EndTimeString);
    
    // If the EndTime is a hour from next day add 86400 sec = 1 day 
    if (EndTime < StartTime) {
      if (TimeInSec <  EndTime) {
        TimeInSec = TimeInSec + 86400;
        int RiseTheTimeInSecWith1Day = 1;
      }
      EndTime = EndTime + 86400;
    }
    
    // Calculate the droping time
    float DropingTime = EndTime - StartTime;
    float BrightnessDelta = StartBrightness - EndBrightness;
    float SecToNextBrightnessChange = DropingTime / BrightnessDelta;

    if ((TimeInSec > StartTime) && (TimeInSec <= EndTime)) {
      //Serial.print("Entering the Drop Loop for LedPin: ");
      //Serial.println(LedPin);
      //Serial.print("TimeInSec: ");
      //Serial.println(TimeInSec);  
      //Serial.print("Brightness: ");
      //Serial.println(Brightness);
      
      // Calculating the first Brightness value
      if ((Brightness > StartBrightness) || (Brightness < EndBrightness)) {
        Brightness = StartBrightness;
        analogWrite(LedPin,Brightness);
      }
      if ((Brightness <= StartBrightness) && (Brightness >= EndBrightness)) {
        Brightness = StartBrightness - (1 * (TimeInSec - StartTime)/SecToNextBrightnessChange);
        analogWrite(LedPin,Brightness);
      }
    }
    if (RiseTheTimeInSecWith1Day == 1) {
      TimeInSec = TimeInSec - 86400;      
      RiseTheTimeInSecWith1Day = 0;
    } 
  }
  
  unsigned long ConvertTimeToSec(String TimeFormat) {
    String StringHours = TimeFormat.substring(0,2);
    int Hours = StringHours.toInt();
    String StringMinutes = TimeFormat.substring(3,5);
    int Minutes = StringMinutes.toInt();
    String StringSeconds = TimeFormat.substring(6);
    int Seconds = StringSeconds.toInt();
    //Serial.println(" ");
    //Serial.print("Hours: ");
    //Serial.println(Hours);
    //Serial.print("Minutes: ");
    //Serial.println(Minutes);
    //Serial.print("Seconds: ");
    //Serial.println(Seconds);
    //Serial.print("HoursInSec: ");
    //unsigned long HoursInSec;
    //HoursInSec = long(Hours) * 3600;
    //Serial.println(HoursInSec);
    //Serial.print("MinutesInSec: ");
    //Serial.println(Minutes*60);
    //Serial.print("Seconds: ");
    //Serial.println(Seconds);
    //Serial.print("Return value: ");
    //unsigned long ReturnValue;
    //ReturnValue = long(Hours)*3600 + long(Minutes)*60 + long(Seconds);
    //Serial.println(ReturnValue);
    return (long(Hours)*3600 + long(Minutes)*60 + long(Seconds));
  }
  


