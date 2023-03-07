# Social Graph (College Mini Project)

SocialGraph is a console-based social networking site that allows users to create accounts, add personal details, and find matching users based on their preferences. The program is written in C++ and uses various data structures and algorithms.

The program uses graph data structure to store users and graph traversal techniques for matching. When the matching users command is given, it shows all users and the users they matched with, based on what preferences they were matched.

To use the application, you can compile the main.cpp file and run the executable. Once the program is running, you can use the following commands:

- `create_account`: Create a new user account and add personal details.
- `find_matches`: Find matching users based on similar personal details.
- `remove_account`: Remove an existing user account.
- `add_dummy_users`: Add a list of dummy users with random names and preferences.

After executing a command, the console will be cleared to display the appropriate output.

## Example Usage

```sh
$ ./GraphConnect
> create_account
Enter your name: Alice
Enter your age: 22
Enter your gender (M/F): F
Enter your favorite color: Blue
Account created successfully.

> add_details
Enter your name: Alice
Enter your age: 22
Enter your gender (M/F): F
Enter your favorite color: Red
Details added successfully.

> find_matches
Enter your name: Alice
Matches found:
- Bob (Green)
- Charlie (Blue)

> remove_account
Enter your name: Alice
Account removed successfully.

> exit
```

## License

SocialGraph is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as you see fit.
