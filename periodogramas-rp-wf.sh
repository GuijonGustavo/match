#!/bin/sh

# Made by:
# Sergio Mendoza <sergio@mendozza.org>
# Instituto de Astronomia UNAM
# Ciudad Universitaria
# Ciudad de Mexico
# Mexico
# Sun Mar 13 20:50:53 UTC 2016

###########
# GRAPH01 #
###########
# Gnuplot commands begin

gnuplot << EOF
#set nokey
set datafile missing "NA"
set xlabel 'Period (days)'
set ylabel 'Coefficient of determination'


set terminal pslatex color auxfile
set output 'RPopticalOrig.tex'
set xrange[50:500]
set yrange[0:.41]
set mxtics 5

set ytics format "%.2f"
set ytics autofreq 0.04#0,0.01,0.02
set xtics autofreq 100#0.02#0,0.01,0.02

set arrow 1 from 314,0 to 314,0.41 nohead lw 2 lc rgb "#ffc0cb" 
set arrow 2 from 429,0 to 429,0.41 nohead lw 2 lc rgb "#ffc0cb"
plot 'data/optical_rpt_oj287-1-2000.dat' w l title "rp", 'data/oj287_optical_wf.dat' u 1:2 smooth acsplines title "wf"

EOF

# Gnuplot commands end
# Convert previous output to encapsulated postscript:
./gnutex2eps RPopticalOrig.tex

