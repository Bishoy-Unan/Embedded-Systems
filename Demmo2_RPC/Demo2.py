import serial
import time
from datetime import datetime
# Open serial port
ser = serial.Serial('COM16', 9600)  # Adjust port name and baud rate

try:
    # Read data from UART
    while True:
        user_input = int(input("Enter the service number: "))    
        # Get current date and time
        current_time = datetime.now()

        # Print the current time
        print("Current time:", current_time)
        
        if user_input == 0:
            ser.write(bytes([0x00]))
            time.sleep(0.1)
            ser.write(bytes([0x10]))
            time.sleep(0.1)
            switch = ser.read(1)
            

            ser.write(bytes([0x00]))
            time.sleep(0.1)
            ser.write(bytes([0x11]))
            time.sleep(0.1)
            led = ser.read(1)
            
            if switch.decode() == '1'  and led.decode() == '0':
                
                print("test case 1")
                print("SWITCH released and LED off")
                print("test case resault PASS")
                print("-----------------------------------------")
                file_path = "testcases.txt"
                with open(file_path, 'a') as file:
                    print("-----------------------------------------\n")
                    file.write("test case 1\n")
                    file.write("SWITCH released and LED off\n")
                    file.write("test case resault PASS\n")
                    file.write("-----------------------------------------\n")
            elif switch.decode() == '0'  and led.decode() == '1':
                print("test case 2")
                print("SWITCH pressed and LED on")
                print("test case resault PASS")
                print("-----------------------------------------")
                with open(file_path, 'a') as file:
                    file.write("test case 2\n")
                    file.write("SWITCH pressed and LED on\n")
                    file.write("test case resault PASS\n")
                    file.write("-----------------------------------------\n")
            elif switch.decode() == '0'  and led.decode() == '0':
                print("test case 3")
                print("SWITCH pressed and LED off")
                print("test case resault FAIL")
                print("-----------------------------------------")
                with open(file_path, 'a') as file:
                    file.write("test case 3\n")
                    file.write("SWITCH pressed and LED off\n")
                    file.write("test case resault FAIL\n")
                    file.write("-----------------------------------------\n")
            elif switch.decode() == '1'  and led.decode() == '1':
                print("test case 4")
                print("SWITCH pressed and LED on")
                print("test case resault FAIL")
                print("-----------------------------------------")
                with open(file_path, 'a') as file:
                    file.write("test case 4\n")
                    file.write("SWITCH pressed and LED on\n")
                    file.write("test case resault FAIL\n")
                    file.write("-----------------------------------------\n")
                    
            
            
            

except KeyboardInterrupt:
    print("Keyboard interrupt detected. Exiting.")

finally:
    # Close serial port
    ser.close()
