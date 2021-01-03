#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(image[i][j].rgbtBlue + image[i][j].rgbtGreen +
            image[i][j].rgbtRed / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

int max(int sepiaRGB);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 *
            image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 *
            image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 *
            image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = max(sepiaRed);
            image[i][j].rgbtGreen = max(sepiaGreen);
            image[i][j].rgbtBlue = max(sepiaBlue);

        }
    }
    return;
}

// Function for calculated sepia values which are greater than 255.
int max(int sepiaRGB)
{
    if (sepiaRGB > 255)
    {
        sepiaRGB = 255;
    }
    return sepiaRGB;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Place a pixel in buffer and exchange pixels in decending order.
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = buffer;
        }
    }
    return;
}
