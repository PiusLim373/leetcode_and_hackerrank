start_time = [1, 3, 0, 5, 5, 8]
duration = [1, 1, 6, 2, 4, 1]
end_time = []
for i in range(len(start_time)):
    end_time.append(start_time[i] + duration[i])

print(start_time)
print(end_time)