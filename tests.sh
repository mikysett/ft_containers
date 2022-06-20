#! /bin/bash

export WHT="\033[0;37m"
export BLK="\033[0;30m"
export RED="\033[0;31m"
export YEL="\033[0;33m"
export BLU="\033[0;34m"
export GRN="\033[0;32m"

make re
if [ $? != 0 ]
	then
		echo -e "$RED FAILED TO COMPILE FT_CONTAINER $WHT"
		exit 1
fi
make stdlib
if [ $? != 0 ]
	then
		echo -e "$RED FAILED TO COMPILE STD_CONTAINER $WHT"
		exit 1
fi

# The argument is used only by eval_main.cpp (provided by school) as seed
./ft_containers 100 > out_ft
./std_containers 100 > out_std

echo -e "\n $YEL DIFF: FT_CONTAINERS -VS- STD_CONTAINERS $WHT"
diff -y -W 200 out_ft out_std

echo -e "\n $YEL EXECUTION TIMES: $WHT"
echo -e "\n $BLU ft_containers $WHT"
time ./ft_containers 100 > out_ft
echo -e "\n $BLU std_containers $WHT"
time ./std_containers 100 > out_std

rm out_ft out_std