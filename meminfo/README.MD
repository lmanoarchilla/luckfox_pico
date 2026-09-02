Meminfo - Iteration 1

Simple C program that reads RAM information from the Linux /proc/meminfo file.

This first iteration uses fscanf() to parse the file and retrieve:

Total memory (MemTotal)
Available memory (MemAvailable)
Used memory, calculated as:
Used = Total - Available

The values are read in kB and displayed in MB.

Build
make
Run
./meminfo

Example output:

fscanf - RAM Total: 180 MB
fscanf - RAM Used : 27 MB
fscanf - RAM Free : 153 MB

This is the first iteration of a small Linux system monitoring tool that will be progressively extended with additional features.