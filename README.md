# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.
## Subject
You must create a communication program in the form of a client and a server.
* The server must be started first. After its launch, it has to print its PID.
* The client takes two parameters: 1) The server PID 2) The string to send.
* The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
* The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
* Your server should be able to receive strings from several clients in a row without needing to restart.
* The communication between your client and your server has to be done only using UNIX signals.
* You can only use these two signals: SIGUSR1 and SIGUSR2.
## Description
The server process starts by displaying its own PID on the console. It indefinitely listens SIGUSR1 and SIGUSR2 signals.
The client process takes two arguments: the server's PID (obtained from the server process) and a string to be sent to the server.
Each character in the string is converted to its binary representation, and each bit is sent as a signal to the server process. 
A SIGUSR1 signal is sent for a binary 1, and a SIGUSR2 signal is sent for a binary 0. There is a small delay (usleep(35)) between each signal to ensure proper signal handling.
The server has a signal handler function that is triggered when a signal is received. Inside the handler, a number is constructed based on the received signals.
Once all the bits have been received, the number is written to the console.
## Installation
 ```
 git clone git@github.com:pweinstock/minitalk.git
 cd minitalk
 make
 ```
## Running
```
$ ./server
server pid is: <pid_server>
```
```
$ ./client <pid_server> <string>
```
