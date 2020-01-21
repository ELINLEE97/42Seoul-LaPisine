#!/bin/sh
cat /etc/passwd | grep -v '^#' | sed -n '2,$p' | rev | cut -d ':' -f 7 | sort -r | sed -n ''"$FT_LINE1"','"$FT_LINE2"'p' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
