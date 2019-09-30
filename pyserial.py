
import serial,time
an=0
arduino=serial.Serial('/dev/ttyACM1',115200,timeout=0.5)

while(True):
    
    arduino.write('y')
    
    an=an+1
    anu=str(an)
    arduino.write(anu)
    arduino.write('x')
    arduino.write(str(200))
    time.sleep(.01)
    
