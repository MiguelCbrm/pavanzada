#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here
send "4\r"
send "4 4\r"
send "1.4000\r"
send "0.5000 0.7000 0.8000 0.6000\r"
send "2 2\r"
send "1.000\r"
send "0.0000 0.0000\r"
send "2 1\r"
send "0.0000\r"
send "0.9000 0.8000\r"
send "2 1\r"
send "0.1000\r"
send "0.4000 0.5000 0.0000\r"




expect "Final Porbability: 1.000000" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Final Porbability: 0.250000" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Final Porbability: 0.980000" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Final Porbability: 0.760000" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
