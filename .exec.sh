#!/bin/bash
make;
cp push_swap .visualizers/;
python3 .visualizers/pyviz.py `ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
