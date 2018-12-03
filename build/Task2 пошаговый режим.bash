#!/bin/bash

m="$(uname -m)"
if [[ "${m}" -eq "x86_64" ]]
then
./"Task2 Linux 64-bit" stepbystep
else
./"Task2 Linux 32-bit" stepbystep
fi
