print("Please input the file name that contains the data u want to process:")

# filename = str(input())
filename = "data.txt"

print('filename is:', filename)

# Open and read in all of the data
file_obj = open(filename, 'r')
file_data = file_obj.read()

# Get another file to write the data to
file_save_obj = open("saving_data.txt", 'w')

# Parse using ","
file_data = file_data.replace("[", "")
file_data = file_data.replace("]", "")
file_data = file_data.split(",")
counter = 0
i = 0
j = 0
result_array = [[0 for x in range (512)] for y in range (8)]
for item in file_data:
    counter += 1 
    file_save_obj.write(str(int(float(item) * 256)))
    # if (counter % 8 == 0):
    #     file_save_obj.write("\n")
    # else:
    #     file_save_obj.write("\t")
    file_save_obj.write("\t")
    
    # print("i is ",i, "j is", j)

#     result_array[j][i] = int(float(item) * 256)

#     if (j < 7):
#         j += 1
#     else:
#         j = 0
    
#     if (i < 511):
#         i += 1
#     else:
#         i = 0

# for i in range (8):
#     for j in range (512):
#         print("i is ",i, "j is", j)
#         file_save_obj.write(str(result_array[i][j]))
#         file_save_obj.write("\t")
#     file_save_obj.write("\n")
