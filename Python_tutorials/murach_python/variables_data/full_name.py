#!/usr/bin/python3

"""
This script demonstrates the creation of a full name by combining first and last names.

Usage:
1. Set the `first_name` variable to the desired first name.
2. Set the `last_name` variable to the desired last name.
3. The script will create a `full_name` by concatenating `first_name` and `last_name`.
4. The result will be printed to the console.

Example:
first_name = "Ada"
last_name = "Lovelace"
full_name = f"{first_name} {last_name}"
message = full_name
full_name = "{} {}".format(first_name, last_name)
print(message)

print(f"Hello, {full_name.title()}!")

print(full_name)
"""

first_name = "Ada"
last_name = "lovelace"
full_name = f"{first_name} {last_name}"
message = full_name
full_name = "{} {}".format(first_name, last_name)
print(message)

print(f"Hello, {full_name.title()}!")

print(full_name)

