list = [5, 22, 3, -6, 48]

def bubbleSort(list):
  for j in range(len(list) - 1):
    for i in range(len(list) - 1):
      if list[i] > list[i+1]:
        list[i], list[i+1] = list[i+1], list[i]
  return list

print('After sort:  ', list)

bubbleSort(list)

print('Before sort: ', list)