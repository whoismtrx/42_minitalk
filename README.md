# minitalk

![](https://github.com/whoismtrx/42_minitalk/blob/main/minitalk.gif)

## Overview

This project is a small data exchange program using UNIX signals. You need to communicate two separate proccesses. One of them will be the server and the other one will be the client.

## Key Features

The project is divided into two parts `Mandatory` and `Bonus`, every part has two programs, one for the `server` and the other one for the `client`.
- `server`: The server runs first, displays its PID, and waits for the client to send a message.
- `client`: The client takes the server's PID and a string as arguments, sends the string to the server.

The server displays the string. the string can contain Unicode characters in the bonus part.

## Getting Started

To get started using minitalk, you need to clone the repository and run the following commands:

```
git clone git@github.com:whoismtrx/42_minitalk.git minitalk
cd minitalk
make
```

## Usage

To run the server, you should run the executable named `server` with no arguments:

```
./server
PID : 12345
```

To run the client, you need to provide the server's PID and a string as arguments:

```
./client 12345 "Hello, World!"
```

## Implementation

The server and the client communicate using UNIX signals `SIGUSR1` and `SIGUSR2`. The server waits for the client to send a signals, the client iterates over the string characters, looks for the bit representation of the characters, and sends a signal to the server for each bit, `SIGUSR1` or `SIGUSR2` for `1` or `0` it's depending on the bit value and what signal you choose to represent it. The server receives the signals and reconstructs the string.

## Resources

- [Introduction To Unix Signals Programming](https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html)
- [Why is Sigaction() a better option than Signal()](https://www.emblogic.com/blog/02/why-is-sigaction-a-better-option-than-signal/)
- [Basics of Bit Manipulation](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/)
- [Characters, Symbols and the Unicode Miracle](https://www.youtube.com/watch?v=MijmeoH9LT4)