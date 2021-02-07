import cs50
import sys
import csv

# Ensure correct usage
if len(sys.argv) != 3:
    sys.exit("Usage Error")

# Open and read csv and txt file
with open(sys.argv[1], "r") as csv_file:
    reader = csv.reader(csv_file)
    txt_file = open(sys.argv[2], "r")
    seq = txt_file.read()

    STRs = []
    people = {}
    for ind, row in enumerate(csv_file):
        if ind == 0:
            STRs = [STR for STR in row.strip().split(',')][1:]
        else:
            cur_row = row.strip().split(',')
            people[cur_row[0]] = [int(x) for x in cur_row[1:]]
    
    final_STRs = []
    for STR in STRs:
        i = 0
        max_STR = -1
        cur_max = 0
        while i < len(seq):
            cur_window = seq[i:i + len(STR)]
            if cur_window == STR:
                cur_max += 1
                max_STR = max(max_STR, cur_max)
                i += len(STR)
            else:
                cur_max = 0
                i += 1
        final_STRs.append(max_STR)
    
    for name, data in people.items():
        if data == final_STRs:
            print(name)
            txt_file.close() 
            sys.exit(0)

    print("No match")
    txt_file.close()  
    sys.exit(0)
