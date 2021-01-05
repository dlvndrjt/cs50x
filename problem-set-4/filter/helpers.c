#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Function declaration for Sepia image
int max(int sepiaRGB);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = max(sepiaRed);
            image[i][j].rgbtGreen = max(sepiaGreen);
            image[i][j].rgbtBlue = max(sepiaBlue);

        }
    }
    return;
}

// Function description for calculated sepia values which are greater than 255.
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

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary container to transfer pixels that have been modified
    RGBTRIPLE temp [height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Variables to install the average RGB
    float arg_red = 0;
    float arg_green = 0;
    float arg_blue = 0;

    // For pixels on the four corner-sides  *  *
    // For pixel on the left-top-corner     *  *
    arg_red = round((image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / 4.00);
    arg_green = round((image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / 4.00);
    arg_blue = round((image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4.00);

    temp[0][0].rgbtRed = max(arg_red);
    temp[0][0].rgbtGreen = max(arg_green);
    temp[0][0].rgbtBlue = max(arg_blue);

    // For pixel on the left-bottom-corner
    arg_red = round((image[height][0].rgbtRed + image[height][1].rgbtRed + image[height - 1][0].rgbtRed +
                     image[height - 1][1].rgbtRed) / 4.00);
    arg_green = round((image[height][0].rgbtGreen + image[height][1].rgbtGreen + image[height - 1][0].rgbtGreen +
                       image[height - 1][1].rgbtGreen) / 4.00);
    arg_blue = round((image[height][0].rgbtBlue + image[height][1].rgbtBlue + image[height - 1][0].rgbtBlue +
                      image[height - 1][1].rgbtBlue) / 4.00);

    temp[height][0].rgbtRed = max(arg_red);
    temp[height][0].rgbtGreen = max(arg_green);
    temp[height][0].rgbtBlue = max(arg_blue);

    // For pixel on the right-top-corner
    arg_red = round((image[0][width].rgbtRed + image[0][width - 1].rgbtRed + image[1][width].rgbtRed +
                     image[1][width - 1].rgbtRed) / 4.00);
    arg_green = round((image[0][width].rgbtGreen + image[0][width - 1].rgbtGreen + image[1][width].rgbtGreen +
                       image[1][width - 1].rgbtGreen) / 4.00);
    arg_blue = round((image[0][width].rgbtBlue + image[0][width - 1].rgbtBlue + image[1][width].rgbtBlue +
                      image[1][width - 1].rgbtBlue) / 4.00);

    temp[0][width].rgbtRed = max(arg_red);
    temp[0][width].rgbtGreen = max(arg_green);
    temp[0][width].rgbtBlue = max(arg_blue);

    // For pixel on the right-bottom-corner
    arg_red = round((image[height][width].rgbtRed + image[height][width - 1].rgbtRed + image[height - 1][width].rgbtRed +
                     image[height - 1][width - 1].rgbtRed) / 4.00);
    arg_green = round((image[height][width].rgbtGreen + image[height][width - 1].rgbtGreen + image[height - 1][width].rgbtGreen +
                       image[height - 1][width - 1].rgbtGreen) / 4.00);
    arg_blue = round((image[height][width].rgbtBlue + image[height][width - 1].rgbtBlue + image[height - 1][width].rgbtBlue +
                      image[height - 1][width - 1].rgbtBlue) / 4.00);

    temp[height][width].rgbtRed = max(arg_red);
    temp[height][width].rgbtGreen = max(arg_green);
    temp[height][width].rgbtBlue = max(arg_blue);


    // For pixels on the edges of the image apart from the four corners
    for (int i = 1; i < width - 1; i++)
    {
        // For pixels on the edges of the top-side
        arg_red = round((image[0][i - 1].rgbtRed + image[0][i].rgbtRed + image[0][i + 1].rgbtRed + image[1][i - 1].rgbtRed +
                         image[1][i].rgbtRed + image[1][i + 1].rgbtRed) / 6.00);
        arg_green = round((image[0][i - 1].rgbtGreen + image[0][i].rgbtGreen + image[0][i + 1].rgbtGreen + image[1][i - 1].rgbtGreen +
                           image[1][i].rgbtGreen + image[1][i + 1].rgbtGreen) / 6.00);
        arg_blue = round((image[0][i - 1].rgbtBlue + image[0][i].rgbtBlue + image[0][i + 1].rgbtBlue + image[1][i - 1].rgbtBlue +
                          image[1][i].rgbtBlue + image[1][i + 1].rgbtBlue) / 6.00);

        temp[0][i].rgbtRed = max(arg_red);
        temp[0][i].rgbtGreen = max(arg_green);
        temp[0][i].rgbtBlue = max(arg_blue);

        // For pixels on the edges of the bottom-side
        arg_red = round((image[height][i - 1].rgbtRed + image[height][i].rgbtRed + image[height][i + 1].rgbtRed +
                         image[height - 1][i - 1].rgbtRed + image[height - 1][i].rgbtRed + image[height - 1][i + 1].rgbtRed) / 6.00);
        arg_green = round((image[height][i - 1].rgbtGreen + image[height][i].rgbtGreen + image[height][i + 1].rgbtGreen +
                           image[height - 1][i - 1].rgbtGreen + image[height - 1][i].rgbtGreen + image[height - 1][i + 1].rgbtGreen) / 6.00);
        arg_blue = round((image[height][i - 1].rgbtBlue + image[height][i].rgbtBlue + image[height][i + 1].rgbtBlue +
                          image[height - 1][i - 1].rgbtBlue + image[height - 1][i].rgbtBlue + image[height - 1][i + 1].rgbtBlue) / 6.00);

        temp[height][i].rgbtRed = max(arg_red);
        temp[height][i].rgbtGreen = max(arg_green);
        temp[height][i].rgbtBlue = max(arg_blue);
    }

    // For pixels on the edges of the image apart from the four corners
    for (int i = 1; i < height - 1; i++)
    {
        // For pixels on the edges of the left-side
        arg_red = round((image[i - 1][0].rgbtRed + image[i][0].rgbtRed + image[i + 1][0].rgbtRed + image[i - 1][1].rgbtRed +
                         image[i][1].rgbtRed + image[i + 1][1].rgbtRed) / 6.00);
        arg_green = round((image[i - 1][0].rgbtGreen + image[i][0].rgbtGreen + image[i + 1][0].rgbtGreen + image[i - 1][1].rgbtGreen +
                           image[i][1].rgbtGreen + image[i + 1][1].rgbtGreen) / 6.00);
        arg_blue = round((image[i - 1][0].rgbtBlue + image[i][0].rgbtBlue + image[i + 1][0].rgbtBlue + image[i - 1][1].rgbtBlue +
                          image[i][1].rgbtBlue + image[i + 1][1].rgbtBlue) / 6.00);

        temp[i][0].rgbtRed = max(arg_red);
        temp[i][0].rgbtGreen = max(arg_green);
        temp[i][0].rgbtBlue = max(arg_blue);

        // For pixels on the edges of the right-side
        arg_red = round((image[i - 1][width].rgbtRed + image[i][width].rgbtRed + image[i + 1][width].rgbtRed +
                         image[i - 1][width - 1].rgbtRed + image[i][width - 1].rgbtRed + image[i + 1][width - 1].rgbtRed) / 6.00);
        arg_green = round((image[i - 1][width].rgbtGreen + image[i][width].rgbtGreen + image[i + 1][width].rgbtGreen +
                           image[i - 1][width - 1].rgbtGreen + image[i][width - 1].rgbtGreen + image[i + 1][width - 1].rgbtGreen) / 6.00);
        arg_blue = round((image[i - 1][width].rgbtBlue + image[i][width].rgbtBlue + image[i + 1][width].rgbtBlue +
                          image[i - 1][width - 1].rgbtBlue + image[i][width - 1].rgbtBlue + image[i + 1][width - 1].rgbtBlue) / 6.00);

        temp[i][width].rgbtRed = max(arg_red);
        temp[i][width].rgbtGreen = max(arg_green);
        temp[i][width].rgbtBlue = max(arg_blue);
    }


    // For rest of the pixels in the image
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            arg_red = round((image[i - 1][i - 1].rgbtRed + image[i - 1][i].rgbtRed + image[i - 1][i + 1].rgbtRed + image[i][i - 1].rgbtRed +
                             image[i][i].rgbtRed + image[i][i + 1].rgbtRed + image[i + 1][i - 1].rgbtRed + image[i + 1][i].rgbtRed +
                             image[i + 1][i + 1].rgbtRed) / 9.00);
            arg_green = round((image[i - 1][i - 1].rgbtGreen + image[i - 1][i].rgbtGreen + image[i - 1][i + 1].rgbtGreen +
                               image[i][i - 1].rgbtGreen + image[i][i].rgbtGreen + image[i][i + 1].rgbtGreen + image[i + 1][i - 1].rgbtGreen +
                               image[i + 1][i].rgbtGreen + image[i + 1][i + 1].rgbtGreen) / 9.00);
            arg_blue = round((image[i - 1][i - 1].rgbtBlue + image[i - 1][i].rgbtBlue + image[i - 1][i + 1].rgbtBlue +
                              image[i][i - 1].rgbtBlue + image[i][i].rgbtBlue + image[i][i + 1].rgbtBlue + image[i + 1][i - 1].rgbtBlue +
                              image[i + 1][i].rgbtBlue + image[i + 1][i + 1].rgbtBlue) / 9.00);

            temp[i][j].rgbtRed = max(arg_red);
            temp[i][j].rgbtGreen = max(arg_green);
            temp[i][j].rgbtBlue = max(arg_blue);
        }
    }

    // Transfer pixels from temporary container back to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
