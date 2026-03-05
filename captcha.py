import random
import string

print("Program started")

captcha = ""

for i in range(5):
    captcha += random.choice(string.ascii_letters + string.digits)

print("CAPTCHA:", captcha)

user = input("Enter the CAPTCHA: ")

if user == captcha:
    print("Correct! Verification successful.")
else:
    print("Incorrect CAPTCHA.")
