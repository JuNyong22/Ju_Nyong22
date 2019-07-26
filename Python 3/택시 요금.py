def bill(time, distance):
	distance = distance // 132
	distance = distance  * 100

	if time >= 0 and time <= 4:
		pay = 4600
		pay = pay + distance

	else: 
		pay = 3800
		pay = pay + distance

	return pay

t = float(input("현재 시간: "))
d = float(input("갈 거리: "))
print(t, d)

all = bill(t, d)

print("Pay: ", all)
