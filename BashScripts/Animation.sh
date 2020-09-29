#!/bin/bash

row=10
col=5
msg="Prepare for the countdown..."

clear
tput cup $row $col
echo -n "$msg"

for i in {10..01}
do
    tput cup $row $l
    echo -n "$i"
    sleep 1
done
echo

clear
sleep 1



echo "   ___  ___  ____  ____  __ ______  ___  ___  ___            "
echo "  / _ )/ _ \/ __ \/ __ \/ //_/ /\ \/ / |/ ( )/ __/           "
echo " / _  / , _/ /_/ / /_/ / ,< / /__\  /    /|/_\ \             "
echo "/____/_/|_|\____/\____/_/|_/____//_/_/|_/__/___/_____  _  __ "
echo "            / _ | / |/ /  _/  |/  / _ /_  __/  _/ __ \/ |/ / "
echo "           / __ |/    // // /|_/ / __ |/ / _/ // /_/ /    /  "
echo "          /_/ |_/_/|_/___/_/  /_/_/ |_/_/ /___/\____/_/|_/   "
echo ""
sleep 4
clear
sleep 2
echo -e "Wasn't\nThat\nCool?"
sleep 2
clear

