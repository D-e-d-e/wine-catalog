# Wine Diary

A terminal-based application written in C to save, rate, and manage a personal wine collection.
Born from a passion for wine and C programming.

## Features

- Add new wines with details like name, type, grape variety, year, rating (1-5), and notes

- View the complete list of saved wines

- Sort wines by rating or year

- Automatic saving and loading from a .csv file

- Calculate the average rating

## Wine Structure

Each wine is represented by:

    Name

    Type (e.g., Red, White, Rosé)

    Grape variety (e.g., Nebbiolo, Merlot)

    Production year

    Rating (1 to 5)

    Optional notes

## Compilation

To compile the project, run:
```shell
make
```
Or manually:
```shell
gcc -Wall -o wine-diary src/main.c src/vini.c src/file.c
```
Usage

After compiling, run the program with:
```shell
./wine-diary
```
Follow the on-screen menu to add, search, or view wines.
## CSV File Format

Data is saved in wines.csv with the following format:

Name,Type,Grape Variety,Year,Rating,Notes

## Features to Add (TODO)

    Advanced filters by type or rating

    Export in .txt or .vcf format

    More interactive and user-friendly interface

## Tested On

    Linux (Fedora)
    (Windows and Mac support coming soon)

## Author

Created by Sabau Denis as a personal project to improve knowledge of the C language and Git usage.
Feel free to use, modify, and distribute it freely.