import calendar

m, d, y = map(int, input().strip().split())

print(calendar.day_name[calendar.weekday(y, m, d)].upper())