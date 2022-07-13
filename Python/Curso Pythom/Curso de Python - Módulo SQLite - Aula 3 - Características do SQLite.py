import sqlite3
from unittest.mock import patch

path = r'C:\SQlite\Curso Python'
print(path)
print(type(path))

conn = sqlite3.connect(path+r'\teste.db')
print(conn)
print(type(conn))
