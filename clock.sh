#!/bin/bash

runTime = 100

while [ $runTime -ge 0 ]
do
    date +%T
    runTime=$(( $runTime-1 ))
    sleep 1
 
done



