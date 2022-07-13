sex = ''
while sex != 'M' and sex != 'F':
    sex = str(input("what is your sex? ")).strip().upper()
    if sex != 'M' and sex != 'F':
        print("try again")

print("fim")
