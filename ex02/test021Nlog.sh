#!/bin/bash

./test021 | grep -v "constructor" | grep -v "Constructor" | grep -v "Destructor" | grep -v "destructor"