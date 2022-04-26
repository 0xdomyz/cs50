import csv

name = input("name: ")
number = input("number: ")

with open("phone.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])
