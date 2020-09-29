#!/bin/bash -i

history > SavageUserHistory.txt

year=`date +%Y`
month=`date +%m`
day=`date +%d`

echo "Date: $month-$day-$year" >> SavageUserHistory.txt
