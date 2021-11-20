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
./convert 4.2f
./convert 42.0f
./convert 1234.1234f
./convert 340282346638528859811704183484516925440.0f
./convert 3402823466385288598117041834845169264400.0f

printf "${BLU}--double test--${NC}\n"
./convert 4.2f
./convert 42.0f
./convert 1234.1234f
./convert 340282346638528859811704183484516925440.0f
./convert 3402823466385288598117041834845169264400.0f