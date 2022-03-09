import sys

temp = sys.stdin.readline().split(" ")
countOfNumber = int(temp[0])
countOfSlice = int(temp[1])

arr = sys.stdin.readline().split(" ")
arr = [int(i) for i in arr]

def slice_arr(pivot):
    temp = arr[0]
    numOfGroup = [1]
    for i in range(1, countOfNumber):
        if countOfSlice - len(numOfGroup) == countOfNumber - i:
            numOfGroup.append(1)
            continue
        if temp + arr[i] > pivot:
            temp = arr[i]
            numOfGroup.append(1)
        else:
            temp += arr[i]
            numOfGroup[-1] += 1
    return numOfGroup


max = sum(arr)+1
min = 1
pivot = int((max+min)/2)
numOfGroup = []

while min < max:
    temp = 0
    numOfGroup = [0]  # 잘라놓은 개수를 저장하는 배열
    boolean = 1
    for i in range(countOfNumber):

        # 피벗보다 더큰 원소를 발견했다.
        if arr[i] > pivot:
            boolean = 0
            # 멈춤
            break

        # 최종 그룹개수 - 묶은 그룹개수 == 총원소개수 - 현재index
        # 즉, 남은애들 모두 원소하나짜리 그룹화 시켜야하는 상황
        if countOfSlice - len(numOfGroup) == countOfNumber - i:
            temp = arr[i]
            numOfGroup.append(1)
            continue

        # 현재까지 구슬모음 + 지금구슬 > 목표값
        if temp + arr[i] > pivot:
            # 새로 구슬모음을 시작한다.
            temp = arr[i]
            numOfGroup.append(1)
        # 현재까지 구슬모음 + 지금구슬 <= 목표값
        else:
            # 지금 구슬모음에 추가한다.
            temp += arr[i]
            numOfGroup[-1] += 1

    count = len(numOfGroup)
    # count가 많을수록 최대값은 작아지고 count가 적을수록 최대값은 커진다.
    if countOfSlice < count or boolean == 0:  
        min = pivot+1
    else:
        max = pivot
    pivot = int((max+min)/2)

print(pivot)
for i in slice_arr(pivot):
    print(i, end=' ')
