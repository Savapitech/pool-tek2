#!/bin/bash

COUNT=$1

shuf -i 1-100000 -n "$COUNT" | tr '\n' ' '
echo
