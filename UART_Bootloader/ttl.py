import serial
import time

# Path to your hex file (change this to the actual file path)
hex_file_path = "APP_Trial.hex"

# Configure the serial port (replace with your port and settings)
serial_port = 'COM16'
baud_rate = 9600
timeout = .01  # Timeout in seconds for the read operation

def send_hex_file(file_path):
    try:
        with serial.Serial(serial_port, baud_rate, timeout=timeout) as ser, open(file_path, 'r') as hex_file:
            for line_number, line in enumerate(hex_file, start=1):
                print(f"Sending line {line_number}: {line.strip()}")
                
                # Send each character of the line
                for char in line:
                    ser.write(char.encode('utf-8'))
                    print(f"Sent: {char}")
                    time.sleep(0.01)  # Short delay between characters

                #Wait for 'o' acknowledgment from the target
                while True:
                    response = ser.read(1)
                    if response == b'o':
                        print(f"Received acknowledgment for line {line_number}")
                        break
                    time.sleep(0.1)  # Short delay before checking again

        print("Hex file sent successfully.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    send_hex_file(hex_file_path)



# import serial
# import time

# # Configure the serial port (replace with your port and settings)
# serial_port = 'COM9'  # Change this to your serial port
# baud_rate = 9600    # Change this to the appropriate baud rate

# def send_hex_file(file_path):
#     ser = serial.Serial(serial_port, baud_rate, timeout=1)
#     try:
#         with open(file_path, 'r') as file:
#             line_number = 0
#             for line in file:
#                 line_number += 1
#                 print(f"Sending line {line_number}: {line.strip()}")
                
#                 for char in line:
#                     ser.write(char.encode('utf-8'))
#                     print(f"Sent: {char}")
#                     time.sleep(0.01)  # Short delay between characters

#                 # Wait for 'o' acknowledgment from the target
#                 while True:
#                     response = ser.read().decode('utf-8')
#                     if response == 'o':
#                         print(f"Received acknowledgment for line {line_number}")
#                         break
#                     time.sleep(0.1)  # Short delay before checking again

#         print("Hex file sent successfully.")
#     except Exception as e:
#         print(f"Error: {e}")
#     finally:
#         ser.close()

# # Path to your hex file (change this to the actual file path)
# hex_file_path = 'E:\stm_cube\APP_Trial\Debug\APP_Trial1.txt'

# # Send the hex file to the target
# send_hex_file(hex_file_path)


