import sqlite3

conn = sqlite3.connect()  # pasta onde eata o banco de dados
cursor = conn.execute('select * from estados')
rows = cursor.fetchall()
rows

for row in rows:
    print(row)
