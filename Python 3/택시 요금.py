def bill(time, distance):
	#거리에 따른 비용 증가
	distance = distance // 132
	distance = distance  * 100

	#12시에서 4시 사이에는 택시 요금이 4600원
	if time >= 0 and time <= 4:
		pay = 4600
		pay = pay + distance

	#일반 택시 요금은 3800원
	else: 
		pay = 3800
		pay = pay + distance

	return pay

t = float(input("현재 시간: "))
d = float(input("갈 거리: "))
print(t, d)

all = bill(t, d)

print("Pay: ", all)
