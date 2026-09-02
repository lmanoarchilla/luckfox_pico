#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linux virtual file that provides information about system memory usage
#define MEMINFO_PATH "/proc/meminfo"

int main(void)
{
FILE *fp;
char key[64];
unsigned long value_kb;
char unit[16];

// Memory values retrieved from /proc/meminfo
unsigned long mem_total_kb = 0;
unsigned long mem_available_kb = 0;

// Open /proc/meminfo for reading
fp = fopen(MEMINFO_PATH, "r");
if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
}

/*
 * Read /proc/meminfo line by line.
 *
 * Each entry normally follows this format:
 *     MemTotal:       184320 kB
 *
 * fscanf() extracts:
 *     key      -> "MemTotal:"
 *     value_kb -> 184320
 *     unit     -> "kB"
 */
while (fscanf(fp, "%63s %lu %15s", key, &value_kb, unit) == 3) {

    // Store the values needed to calculate memory usage
    if (strcmp(key, "MemTotal:") == 0) {
        mem_total_kb = value_kb;
    } else if (strcmp(key, "MemAvailable:") == 0) {
        mem_available_kb = value_kb;
    }
}

fclose(fp);

// Check that the required memory values were successfully read
if (mem_total_kb == 0 || mem_available_kb == 0) {
    fprintf(stderr, "Error: unable to read memory information\n");
    return EXIT_FAILURE;
}

// Calculate used memory
unsigned long mem_used_kb = mem_total_kb - mem_available_kb;

// Display memory information in MB
printf("fscanf - RAM Total: %lu MB\n", mem_total_kb / 1024);
printf("fscanf - RAM Used : %lu MB\n", mem_used_kb / 1024);
printf("fscanf - RAM Free : %lu MB\n", mem_available_kb / 1024);

return EXIT_SUCCESS;

}