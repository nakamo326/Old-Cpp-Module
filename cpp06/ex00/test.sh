#! /bin/bash

BLU="\e[0;34m"
GRN="\e[32m"
RED="\e[31m"
NC="\e[0m"


printf "${BLU}--Char test--${NC}\n"
./convert " "
./convert "a"
./convert "~"

printf "${BLU}--Int test--${NC}\n"
./convert 10
./convert 10000
printf "${BLU}./convert 2147483647${NC}\n"
./convert 2147483647
printf "${BLU}./convert 2147483648${NC}\n"
./convert 2147483648
printf "${BLU}./convert -2147483648${NC}\n"
./convert -2147483648
printf "${BLU}./convert -2147483649${NC}\n"
./convert -2147483649

printf "${BLU}--float test--${NC}\n"
printf "${BLU}./convert 4.2f${NC}\n"
./convert 4.2f
printf "${BLU}./convert 42.0f${NC}\n"
./convert 42.0f
printf "${BLU}./convert 1234.1234f${NC}\n"
./convert 1234.1234f
printf "${BLU}float max${NC}\n"
./convert 340282346638528859811704183484516925440.0f
printf "${BLU}float overflow+${NC}\n"
./convert 3402823466385288598117041834845169264400.0f
printf "${BLU}float overflow-${NC}\n"
./convert -3402823466385288598117041834845169264400.0f


printf "${BLU}--double test--${NC}\n"
./convert 4.2
./convert 42.0
./convert 1234.1234
printf "${BLU}float max${NC}\n"
./convert 340282346638528859811704183484516925440.0
printf "${BLU}float overflow${NC}\n"
./convert 3402823466385288598117041834845169264400000.0

printf "${BLU}double max digits${NC}\n"
./convert 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999900000000000000000000000000000000000000000000000000000000000000000000.0
printf "${BLU}double overflow${NC}\n"
./convert 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999000000000000000000000000000000000000000000000000000000000000000000000.0