#!/usr/bin/env python
# -*- coding: utf-8 -*-
# compare client.py with server.py and check that better to use variables for localhost and port
# like in server.py
import socket

sock = socket.socket()
sock.connect(('localhost', 5005))
sock.send('hello, world!')

data = sock.recv(30)
sock.close()

print data
