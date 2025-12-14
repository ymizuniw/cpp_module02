#!/bin/bash

./test022 | grep -v "constructor" | grep -v "Constructor" | grep -v "Destructor" | grep -v "destructor"