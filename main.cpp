#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstdlib>

using namespace std;

// Define User structure
struct User
{
    string name;
    int age;
    char gender;
    string favorite_color;

    User(string name, int age, char gender, string favorite_color)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->favorite_color = favorite_color;
    }
};

// Define Graph structure
class Graph
{
private:
    unordered_map<string, vector<string>> adjacency_list;

public:
    void add_user(User user)
    {
        string name = user.name;
        adjacency_list[name] = vector<string>{to_string(user.age), string(1, user.gender), user.favorite_color};
    }

    void add_edge(string user1, string user2)
    {
        if (adjacency_list.find(user1) != adjacency_list.end() && adjacency_list.find(user2) != adjacency_list.end())
        {
            adjacency_list[user1].push_back(user2);
            adjacency_list[user2].push_back(user1);
        }
    }
    vector<string> get_matches(string name)
    {
        vector<string> matches;
        if (adjacency_list.find(name) != adjacency_list.end())
        {
            auto user_data = adjacency_list[name];
            for (auto &kv : adjacency_list)
            {
                auto &other_name = kv.first;
                if (other_name != name && user_data == kv.second)
                {
                    matches.push_back(other_name);
                }
            }
        }
        return matches;
    }
    void print_graph()
    {
        for (auto &kv : adjacency_list)
        {
            cout << kv.first << ": ";
            for (auto &adj_user : kv.second)
            {
                cout << adj_user << " ";
            }
            cout << endl;
        }
    }
};

// Define GraphConnect application
class GraphConnect
{
public:
    Graph graph;

public:
    void create_user()
    {
        string name, favorite_color;
        int age;
        char gender;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter favorite color: ";
        cin >> favorite_color;
        User user(name, age, gender, favorite_color);
        graph.add_user(user);
        cout << "User created successfully!" << endl;
    }

    void find_matches()
    {
        string name;
        cout << "Enter name: ";
        cin >> name;
        auto matches = graph.get_matches(name);
        if (matches.empty())
        {
            cout << "No matches found." << endl;
        }
        else
        {
            cout << "Matches for " << name << ":" << endl;
            for (auto &match : matches)
            {
                cout << match << endl;
            }
        }
    }
    void add_dummy_users()
    {
        vector<User> dummy_users{
            User("Alice", 22, 'F', "Blue"),
            User("Bob", 26, 'M', "Green"),
            User("Charlie", 30, 'M', "Red"),
            User("David", 28, 'M', "Blue"),
            User("Eve", 24, 'F', "Green"),
            User("Frank", 32, 'M', "Yellow"),
            User("Grace", 29, 'F', "Red"),
            User("Henry", 27, 'M', "Blue"),
            User("Ivy", 25, 'F', "Green"),
            User("Jack", 31, 'M', "Yellow")};
        for (const auto &user : dummy_users)
        {
            graph.add_user(user);
        }
        cout << "Added " << dummy_users.size() << " dummy users to the graph." << endl;
    }
};

int main()
{
    GraphConnect app;
    bool running = true;
    while (running)
    {
        cout << "GraphConnect - Choose an option:" << endl;
        cout << "1. Create user" << endl;
        cout << "2. Find matches" << endl;
        cout << "3. Remove user" << endl;
        cout << "4. Add dummy users" << endl;
        cout << "5. Print graph" << endl;
        cout << "6. Quit" << endl;
        int choice;
        cin >> choice;
        system("clear"); // clear the console
        switch (choice)
        {
        case 1:
            app.create_user();
            break;
        case 2:
            app.find_matches();
            break;
        case 3:
            // app.remove_user();
            break;
        case 4:
            app.add_dummy_users();
            break;
        case 5:
            app.graph.print_graph();
            break;
        case 6:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}