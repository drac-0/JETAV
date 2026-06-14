#!/usr/bin/bash

for i in ../bin/*; do
      for j in ../db/*; do
            ./a.out "$i" "$j"
      done
done
