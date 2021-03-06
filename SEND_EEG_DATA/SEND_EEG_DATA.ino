/* Reading Multiple Channels of EEG Data
 * by Christian Henry
 *
 * Used to read more than 2 channels of EEG data. For 6 channels
 * or less, each can just take up an analog input of the arduino
 * board (using the UNO). 
 * For more than 6, a multiplexer (MAX4051) is used to cycle between inputs.
 *
 */

#define samplingRate 240

int EEG_data;
int counter;

void setup() {
  
  counter = 0;
  Serial.begin(9600); //start up our serial communication
  
}

void loop(){
  
  delay(1000/samplingRate);
  
  EEG_data = analogRead(0);
  
  // Test data
  //EEG_data = sin( 2.0 * PI * (50.0 / 1000.0) * millis() ) * 1024;
  
  //Incoming data comes in between 0 and 1023, but to easily send data via serial port
  //(with a single byte), it needs to be between 0 and 255. Scale it down for this.
  
  EEG_data = EEG_data / 4;
  Serial.write( EEG_data );
  
  counter++;
}
