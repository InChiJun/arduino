import turtle
import serial

def map_value(value, from_min, from_max, to_min, to_max):
    # Ensure the value is within the input range
    value = max(min(value, from_max), from_min)
    
    # Calculate the mapped value
    from_range = from_max - from_min
    to_range = to_max - to_min
    mapped_value = (value - from_min) * to_range / from_range + to_min
    
    return mapped_value


# Initialize the turtle
window = turtle.Screen()
tt = turtle.Turtle()

# Configure the serial port
#ser = serial.Serial(port='COM10', baudrate=9600, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS)
ser = serial.Serial(
    port = '/dev/ttyACM0', 
    baudrate=115200, 
    parity='N',
    stopbits=1,
    bytesize=8,
    timeout=8
    )
while True:
    try:
        # Read data from the serial port
        data = ser.readline().decode().strip()
        #print("%s\n",data);
        # Split the data into x and y coordinates (assuming a format like "x,y")
        x, y, button = map(int, data.split(','))
        mapX=map_value(x, 0, 1023, -100, 100)
        mapY=map_value(y, 0, 1023, -100, 100)
        
        #print(x,y,button)
        # Move the turtle to the new coordinates
        tt.goto(mapX, mapY)

    except (serial.SerialException, ValueError):
        pass

# Close the serial port when done
ser.close()
turtle.done()