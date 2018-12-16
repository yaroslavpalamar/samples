#!/bin/sh
# tcpdump icmp
# tcpdump host 1.2.3.4
# tcpdump src 1.2.3.4
# tcpdump dst 1.2.3.4
# tcpdump greater 64  // packets greater then 64 bytes
# tcpdump less 32
#tcpdump -vvAls0 | grep 'GET'
#tcpdump -vvAls0 | grep 'Host:'

# DNS traffic:
tcpdump -vvAs0 port 5
