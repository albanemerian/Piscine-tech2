#!/bin/bash

EXECUTABLE="./pushswap_checker"


declare -a test_cases=(
    "3 2 1"   
    "5 1 4 2 3"
    "10 3 7 2 5"
    "1 2 3 4 5"
    " "        
    "1 2 5 6 a"
    "2 1 3 4 5"
    "2 1 3 6 5 8"
    "2 1 3 6 5 8"
    "1 -2 3 4 5"
    "-4 1 5 -2 9 80 -90 3"
    "83 5 8 33 785 4 7 25 8 42 78 2 6 4 76 345 14 90 58 27 46 56 12 1 7 5 7 8 9" 
    "4 3 2 1"
    "9 8 7 6 5 4 3 2 1"
    "1 3 2"
    "10 20 30 40 50"
    "50 40 30 20 10"
    "5 4 3 2 1"
    "1 1 1 1 1"
    "1 2 3 4 5 6 7 8 9 10"
    "10 9 8 7 6 5 4 3 2 1"
    "1 3 5 7 9 2 4 6 8 10"
    "10 8 6 4 2 9 7 5 3 1"
    "1 4 2 5 3"
    "5 3 4 1 2"
    "2 4 1 3 5"
    "3 1 4 2 5"
    "5 2 4 1 3"
    "3 5 1 4 2"
    "4 2 5 1 3"
)


declare -a commands=(
    "sa ra sa"                  
    "pb pb ra pa pa sa ra"
    "pb pb pb sa ra pa pa pa"   
    ""                          
    ""
    "pa pb ra" 
    "sa sf"     
    "sa pb pb pb sa pa pa pa"
    "sa pb pb pb"
    "sa"
    "pb pb pb pb pb pb pb pb sb pa rrb pa sa rb rb rb pa ra rrb rrb sb rrb"
    "sa pb rr ra rrr sb sc pa ra sa sc sb pa pb"       
    "sa ra sa ra"
    "pb pb pb pb pb pb pb pb pb pb pa pa pa pa pa pa pa pa pa pa"
    "sa ra sa sa"
    "ra ra ra ra ra"
    "pb pb pb pb pb pa pa pa pa pa"
    "sa ra sa ra sa"
    "sa sa sa sa sa"
    "ra ra ra ra ra ra ra ra ra ra"
    "pb pb pb pb pb pb pb pb pb pb pa pa pa pa pa pa pa pa pa pa"
    "pb pb pb pb pb pb pb pb pb pb pa pa pa pa pa pa pa pa pa pa"
    "sa ra sa ra sa"
    "sa ra sa ra sa"
    "sa ra sa ra sa"
    "sa rb sa ra sa"
    "sa rr rb ra sb rrr"
    "rb ra rb rb sa sa sb"
    "rb rb ra ra sa sa"
    "rb rb rb sa sa sa"
)


declare -a expected_outputs=(
    "KO: ([1,3,2],[])"
    "KO: ([5,2,3,4,1],[])"
    "KO: ([10,3,7,2,5],[])"
    "OK"
    ""
    ""
    ""
    "OK"
    "KO: ([6,5,8],[3,2,1])"
    "OK"
    "KO: ([-90,-4,-2],[3,9,80,5,1])"
    "KO: ([8,785,4,7,25,8,42,78,2,6,4,76,345,14,90,58,27,46,56,12,1,7,5,7,8,9,83,5],[33])"
    "KO: ([4,1,3,2],[])"
    "KO: ([9,8,7,6,5,4,3,2,1],[])"
    "OK"
    "OK"
    "KO: ([50,40,30,20,10],[])"
    "KO: ([2,5,1,4,3],[])"
    "OK"
    "OK"
    "KO: ([10,9,8,7,6,5,4,3,2,1],[])"
    "KO: ([1,3,5,7,9,2,4,6,8,10],[])"
    "KO: ([4,10,2,9,7,5,3,1,8,6],[])"
    "KO: ([5,1,3,4,2],[])"
    "KO: ([1,5,2,3,4],[])"
    "KO: ([1,4,3,5,2],[])"
    "KO: ([3,4,2,5,1],[])"
    "KO: ([2,4,1,3,5],[])"
    "KO: ([1,4,2,3,5],[])"
    "KO: ([2,4,5,1,3],[])"

)

declare -a expected_exit_codes=(
    0
    0
    0
    0
    84
    84
    84
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
    0
)


echo "Running tests..."
for i in "${!test_cases[@]}"; do
    input="${test_cases[$i]}"
    cmd="${commands[$i]}"
    expected="${expected_outputs[$i]}"
    expected_exit_code="${expected_exit_codes[$i]}"

    echo -n "Test $((i + 1)): Input: '$input', Commands: '$cmd' => "

    if [ -z "$input" ]; then

        $EXECUTABLE $input 2>/dev/null
        exit_code=$?
        if [ $exit_code -eq $expected_exit_code ]; then
            echo "Passed (Exit code: $exit_code)"
        else
            echo "Failed (Exit code: $exit_code, Expected: $expected_exit_code)"
        fi
    else
        output=$(echo "$cmd" | $EXECUTABLE $input 2>/dev/null)
        exit_code=$?

        if [ "$output" == "$expected" ] && [ $exit_code -eq $expected_exit_code ]; then
            echo -e "\033[0;32mPASS\033[0m"
        else
            echo -e "\033[0;31mFailed (Output: '$output', Expected: '$expected', Exit code: $exit_code, Expected: $expected_exit_code)\033[0m"
        fi
    fi
done


