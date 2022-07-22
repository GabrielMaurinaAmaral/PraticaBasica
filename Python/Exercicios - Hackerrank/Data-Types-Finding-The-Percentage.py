n = int(input())
student_marks = {}

for _ in range(n):
    name, *line = input().split()
    scores = list(map(float, line))
    student_marks[name] = scores
query_name = input()

media = 0
for score in student_marks[query_name]:
    media += score
print("%.2f" % (media/3))
