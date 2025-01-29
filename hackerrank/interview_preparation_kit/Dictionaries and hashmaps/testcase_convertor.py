f = open("D:\Desktop\hackerrank\input08.txt", "r")
# print(f.readline())
header_str = f.readline()
val = int(header_str.strip())

output = "vector<vector<int>> queries = {"

while val:
    temp = f.readline()
    val2 = temp.strip().split(" ")
    val3 = []
    for x in val2:
        val3.append(int(x))

    temp_str = "{" + str(val3[0]) + ", " + str(val3[1]) + "}, "
    output += temp_str
    val -=1

output += "};"
print(output)