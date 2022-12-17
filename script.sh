#!/bin/bash

# Constants
readonly ROWS=3
readonly COLS=3
readonly TIMEOUT=10 # seconds

# Initialize the board
board=()
for ((i=0; i<ROWS; i++))
do
    for ((j=0; j<COLS; j++))
    do
        board[$i,$j]=' '
    done
done

# Function to print the board
function printBoard()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        for ((j=0; j<COLS; j++))
        do
            printf "%c" "${b[$i,$j]}"
            if [[ $j -lt $((COLS-1)) ]]
            then
                printf "|"
            fi
        done
        printf "\n"
        if [[ $i -lt $((ROWS-1)) ]]
        then
            printf "-+-+-\n"
        fi
    done
}

# Function to check if someone has won the game
function checkWin()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        if [[ ${b[$i,0]} != ' ' && ${b[$i,0]} == ${b[$i,1]} && ${b[$i,1]} == ${b[$i,2]} ]]
        then
            return 0
        fi
    done
    for ((i=0; i<COLS; i++))
    do
        if [[ ${b[0,$i]} != ' ' && ${b[0,$i]} == ${b[1,$i]} && ${b[1,$i]} == ${b[2,$i]} ]]
        then
            return 0
        fi
    done
    if [[ ${b[0,0]} != ' ' && ${b[0,0]} == ${b[1,1]} && ${b[1,1]} == ${b[2,2]} ]]
    then
        return 0
    fi
    if [[ ${b[0,2]} != ' ' && ${b[0,2]} == ${b[1,1]} && ${b[1,1]} == ${b[2,0]} ]]
    then
        return 0
    fi
    return 1
}

# Function to check if the game is a tie
function checkTie()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        for ((j=0; j<COLS; j++))
        do
            if [[ ${b[$i,$j]} == ' ' ]]
            then
                return 1
            fi
        done
    done
    return 0
}

# Function to get the next move from the user
function getMove()
{
    local -n b=$1
    local turn=$2
    local row=-1
    local col=-1
    local validMove=false
    while [[ $validMove == false ]#!/bin/bash

# Constants
readonly ROWS=3
readonly COLS=3
readonly TIMEOUT=10 # seconds

# Initialize the board
board=()
for ((i=0; i<ROWS; i++))
do
    for ((j=0; j<COLS; j++))
    do
        board[$i,$j]=' '
    done
done

# Function to print the board
function printBoard()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        for ((j=0; j<COLS; j++))
        do
            printf "%c" "${b[$i,$j]}"
            if [[ $j -lt $((COLS-1)) ]]
            then
                printf "|"
            fi
        done
        printf "\n"
        if [[ $i -lt $((ROWS-1)) ]]
        then
            printf "-+-+-\n"
        fi
    done
}

# Function to check if someone has won the game
function checkWin()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        if [[ ${b[$i,0]} != ' ' && ${b[$i,0]} == ${b[$i,1]} && ${b[$i,1]} == ${b[$i,2]} ]]
        then
            return 0
        fi
    done
    for ((i=0; i<COLS; i++))
    do
        if [[ ${b[0,$i]} != ' ' && ${b[0,$i]} == ${b[1,$i]} && ${b[1,$i]} == ${b[2,$i]} ]]
        then
            return 0
        fi
    done
    if [[ ${b[0,0]} != ' ' && ${b[0,0]} == ${b[1,1]} && ${b[1,1]} == ${b[2,2]} ]]
    then
        return 0
    fi
    if [[ ${b[0,2]} != ' ' && ${b[0,2]} == ${b[1,1]} && ${b[1,1]} == ${b[2,0]} ]]
    then
        return 0
    fi
    return 1
}

# Function to check if the game is a tie
function checkTie()
{
    local -n b=$1
    for ((i=0; i<ROWS; i++))
    do
        for ((j=0; j<COLS; j++))
        do
            if [[ ${b[$i,$j]} == ' ' ]]
            then
                return 1
            fi
        done
    done
    return 0
}

# Function to get the next move from the user
function getMove()
{
    local -n b=$1
    local turn=$2
    local row=-1
    local col=-1
    local validMove=false
    while [[ $validMove == false ]
