# Algorithms & Problem Solving Lab Project: Huffman Encoded Password and User Management

This project is an implementation of user management and password encoding using the Huffman algorithm. It provides functionality to add a new user, delete a user, find a user by name, and get matching users.
The program is written in C++ and uses various data structures and algorithms.


## Implementation Details
### Password Encoding
The <b>`User`</b> class stores user information such as name, age, gender, favorite color, and an encoded password using Huffman encoding. The constructor of the User class takes these attributes as arguments and encodes the password using Huffman encoding before storing it.

### User Management
The `Graph` class stores the `User` objects and provides functionality to add a new user, delete a user, find a user by name, and get matching users.

- `add_new_user(User user)` - adds a new User object to the users vector.
- `delete_a_user(string name)` - deletes the User object with the given name.
- `find_a_user_by_name(string name)` - finds and returns the User object with the given name.
- `get_matching_users(User user)` - finds and returns all the User objects with matching age, gender, and favorite color except for the given user.

### Password Encoding Algorithm
The password encoding algorithm used is the `Huffman encoding` algorithm. The `User` constructor uses a binary min-heap to create a Huffman tree, and then uses a depth-first traversal to generate Huffman codes for each character in the password.

### Sorting Algorithm
The `mySort` function is an implementation of the `Selection Sort` algorithm, which sorts the elements in the range [first, last) using the given comparison function.

## Compilation and Execution
To compile the program, use the following command:
```
g++ main.cpp -o main
```

To run the program, use the following command:
```
./main
```

## Features
1. Add a new user - adds a new user to the list of users with name, age, gender, favorite color, and password.
2. Delete a user - deletes the user with the given name from the list of users.
3. Find a user by name - finds and returns the user with the given name.
4. Get matching users - finds and returns all the users with matching age, gender, and favorite color except for the given user.
5. Password encoding - encodes the password using Huffman encoding.
6. Sorting - sorts the elements in the range [first, last) using the given comparison function.

## Data Structures and Algorithms
1. Huffman Encoding - used to encode the password.
2. Selection Sort - used to sort the elements in the range [first, last) using the given comparison function.

## Other Notes
- The password is encoded using Huffman encoding for security purposes.
- The `mySort` function uses the Selection Sort algorithm, which has a worst-case time complexity of O(n^2). This algorithm is not recommended for sorting large collections of data.
- The `User` class stores user information such as name, age, gender, favorite color, and an encoded password using Huffman encoding.
- The `Graph` class stores the `User` objects and provides functionality to add a new user, delete a user, find a user by name, and get matching users.
- The program can be compiled and run on a Unix-like system using the commands provided above.

## License
GraphConnect is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as you see fit.
