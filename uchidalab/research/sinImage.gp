set term png size 100,70
set output 'sinImage.png'

set border 0
set format xy ""
unset tics
unset key

#set size 1.0
set lmargin 0
set rmargin 0

#set xrange [0:10]

plot 0.5*sin(1.5*x)
