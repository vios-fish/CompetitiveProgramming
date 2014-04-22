#! /bin/bash

for filename in $*
do
	../submit.rb -judge aoj $filename
done
