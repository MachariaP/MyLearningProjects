#!/usr/bin/python3

def display_menu():
    print("COMMAND MENU")
    print("list - List all movies")
    print("add - Add a movie")
    print("del - Delete a movie")
    print("exit - Exit program")
    print()

def list(movie_list):
    if len(movie_list) == 0:
        print("There are no movies in the list.\n")
        rerurn
    else:
        i = 1
    for row in movie_list:
        print(str(i) + ". " + row[0] + " (" + str(row[1]) + ") ")
        i += 1
    print()

def add(movie_list):
    name = input("Name: ")
    year = input("Year: ")
    movie = []
    movie.append(name)
    movie.append(year)
    movie_list.append(movie)
    print(movie[0] + " was added.\n")

def delete(movie_list):
    number = int(input("Number: "))
    if number < 1 or number > len(movie_list):
        print("Invalid movie number.\n")
    else:
        movie = movie_list.pop(number-1)
        print(movie[0] + " was deleted.\n")

def main():
    # LIst of movies
    movie_list = [["Monty Python and the Holy Grail", 1975, 9.99],
                    ["on the Waterfront", 1979, 12.3],
                    ["Cat on a Hot Tin Roof", 1983, 7.50]]
    
    # Display the menu
    display_menu()

    # Main loop
    while True:
        command = input("command: ")
        if command.lower() == "list":
            list(movie_list)
        elif command.lower() == "add":
            add(movie_list)
        elif command.lower() == "del":
            delete(movie_list)
        elif command.lower() == "exit":
            break
        else:
            print("Not a valid command. Please try again.\n")

    print("Bye!")

if __name__ == "__main__":
    main()
