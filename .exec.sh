#!/bin/bash
make;
python3 .pyviz.py `ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
