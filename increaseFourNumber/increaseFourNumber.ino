#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

unsigned long Cur_ms_Count; // Stores the current time in ms
unsigned long Last_ms_Count; // Stores the last time in ms the counter was last updated
int Count; // Stores the value that will be displayed

void setup(){
    /* Set DIO pins to outputs */
    pinMode(LATCH_DIO, OUTPUT);
    pinMode(CLK_DIO, OUTPUT);
    pinMode(DATA_DIO, OUTPUT);

    /* Initillase the registers used to store the crrent time and count */
    Cur_ms_Count = millis();
    Last_ms_Count = 0;
    Count = 0;
}

/* Main program */
void loop(){
    /* Get how much time has passed in milliseconds */
    Cur_ms_Count = millis();

    /* If 100ms has passed then add one to the counter */
    if(Cur_ms_Count - Last_ms_Count > 1000){
        Last_ms_Count = Cur_ms_Count;

        if(Count < 9999){
            Count++;
        } else{
            Count = 0;
        }
    }

    /* Update the display with the current counter value */
    WriteNumber(Count);
}

/* Write a decimal number between 0 and 9999 to the display */
void WriteNumber(int Number){
    WriteNumberToSegment(0, Number / 1000);
    WriteNumberToSegment(1, (Number / 100) % 10);
    WriteNumberToSegment(2, (Number / 10) % 10);
    WriteNumberToSegment(3, Number % 10);
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value){
    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment]);
    digitalWrite(LATCH_DIO, HIGH);
}