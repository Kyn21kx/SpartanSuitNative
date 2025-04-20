import socket
import sys
import time

def udp_sender():
    # Set default values
    server_ip = "127.0.0.1"  # Default to localhost
    server_port = 8080       # Default port
    message = "Hello, UDP Server!"  # Default message
    repeat = 10               # Default number of messages to send
    delay = 2                # Default delay between messages in seconds
    
    # Parse command line arguments
    if len(sys.argv) > 1:
        server_ip = sys.argv[1]
    if len(sys.argv) > 2:
        server_port = int(sys.argv[2])
    if len(sys.argv) > 3:
        message = sys.argv[3]
    if len(sys.argv) > 4:
        repeat = int(sys.argv[4])
    if len(sys.argv) > 5:
        delay = float(sys.argv[5])
    
    # Create UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    print(f"UDP sender started - targeting {server_ip}:{server_port}")
    
    # Send messages
    for i in range(repeat):
        # Send the message
        bytes_sent = sock.sendto(message.encode(), (server_ip, server_port))
        
        # Print confirmation
        print(f"Message {i+1}/{repeat} sent: '{message}' ({bytes_sent} bytes)")
        
        # Add delay if specified and not the last message
        if delay > 0 and i < repeat - 1:
            time.sleep(delay)
    
    print("All messages sent, closing sender.")
    sock.close()

if __name__ == "__main__":
    udp_sender()
