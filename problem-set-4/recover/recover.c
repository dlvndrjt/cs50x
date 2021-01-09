#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Check input count
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open memory card & read it
    FILE *file = fopen(argv[1], "r");

    // Check if file is corrupted
    if (file == NULL)
    {
        printf("Error\n");
        return 2;
    }

    typedef uint8_t BYTE;
    int blockSize = 512;
    BYTE buffer[blockSize];
    size_t bytesRead;
    bool firstjpg = false;
    FILE *currentFile;
    char currentFileName[100];
    int currentFileNumber = 0;
    bool foundjpg = false;

    // Repeat until end of card
    while (true)
    {
        // Read 512 bytes into buffer
        bytesRead = fread(buffer, sizeof(BYTE), blockSize, file);

        // End program if all files are read
        if (bytesRead == 0)
        {
            break;
        }

        // Check if its a Jpg file by reviewing the 4 initial bytes of the file
        if (buffer [0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            foundjpg = true;

            if (!firstjpg)
            {
                firstjpg = true;
            }
            else
            {
                fclose(currentFile);
            }
            sprintf(currentFileName, "%03i.jpg", currentFileNumber);
            currentFile = fopen(currentFileName, "w");
            fwrite(buffer, sizeof(BYTE), bytesRead, currentFile);
            currentFileNumber++;
        }
        else
        {
            if (foundjpg)
            {
                fwrite(buffer, sizeof(BYTE), bytesRead, currentFile);
            }
        }
    }
    // Close remaining files
    fclose(file);
    fclose(currentFile);
    return 0;
}
