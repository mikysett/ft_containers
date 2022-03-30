#! /bin/bash

./ft_containers > out_ft
./std_containers > out_std
echo -e "DIFF: FT_CONTAINERS -VS- STD_CONTAINERS"
diff out_ft out_std
rm out_ft out_std