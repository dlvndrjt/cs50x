import sys
import re

# Prompt input from user
card_no = input("Number: ")

while len(card_no) < 0 or len(card_no) > 16:  # Re-prompt until requirements are met
    card_no = input("Number: ")


# Calculate Checksum
card_no_list = list(card_no)  # Convert input into list

if len(card_no_list) == 13 or len(card_no_list) == 15:  # Figure out if card_no has required amount of no
    every_other_no = card_no_list[1::2]  # Slice notation a[start_index:end_index:step]
    rest_no = card_no_list[::2]  # Numbers other than every other number
elif len(card_no_list) == 16:  # Figure out if card_no has required amount of no
    every_other_no = card_no_list[::2]  # Slice notation a[start_index:end_index:step]
    rest_no = card_no_list[1::2]  # Numbers other than every other number
else:  # Terminate program
    print("INVALID\n")
    sys.exit()

every_other_no_mult = [int(i) * 2 for i in every_other_no]  # Convert string into int and multiply it by 2 using list comprehension

first_no = [int(i / 10) for i in every_other_no_mult]  # Separate 2 digit no into individual digits; first digit
second_no = [int(i % 10) for i in every_other_no_mult]  # Separate 2 digit no into individual digits; second digit

rest_no = [int(i) for i in rest_no]  # Convert string into int using list comprehension

final_sum = sum(first_no) + sum(second_no) + sum(rest_no)  # Add all numbers with each other using the sum() function


# Verify & match card_no to card type
if final_sum % 10 != 0:  # Verify Checksum
    print("INVALID\n")
elif re.search("^34|37", card_no):  # Match required starting number with card_no using ReGex
    print("AMEX\n")
elif re.search("51|55", card_no):  # Match required starting number with card_no using ReGex
    print("MASTERCARD\n")
elif re.search("^4", card_no):  # Match required starting number with card_no using ReGex
    print("VISA\n")
else:
    print("INVALID\n")
