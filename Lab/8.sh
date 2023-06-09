#!/bin/bash

filename="example.txt"
echo "File opened."

# Open the file for writing
exec 3>$filename

# Write to the file
echo "Hello, World!" >&3

# Close the file
exec 3>&-

echo "File closed."

# To Run: chmod +x 8.sh 
# ./8.sh  
