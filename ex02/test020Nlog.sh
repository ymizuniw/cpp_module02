#!/bin/bash

./test020 | grep -v "constructor" | grep -v "Constructor" | grep -v "Destructor" | grep -v "destructor"