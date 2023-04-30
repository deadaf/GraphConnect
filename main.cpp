#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * Sorts the elements in the range [first, last) using the given comparison function.
 *
 * @tparam Iterator The type of iterator used to access the elements.
 * @tparam Compare The type of the comparison function.
 * @param first An iterator to the first element in the range to be sorted.
 * @param last An iterator to one-past-the-last element in the range to be sorted.
 * @param cmp A binary comparison function that takes two elements as arguments and returns true if the first argument is less than the second.
 *
 * @note This function uses the Selection Sort algorithm, which has a worst-case time complexity of O(n^2).
 *       This algorithm is not recommended for sorting large collections of data.
 */
template <typename Iterator, typename Compare>
void mySort(Iterator first, Iterator last, Compare cmp)
{
    // Iterate over the range [first, last) and select the i-th smallest element by swapping it with the element at index i.
    for (auto it = first; it != last; ++it)
    {
        // Iterate over the range [it, last) to find the smallest element.
        for (auto jt = it; jt != last; ++jt)
        {
            // If the current element is smaller than the element at index i, swap them.
            if (cmp(*jt, *it))
            {
                swap(*it, *jt);
            }
        }
    }
}

class User
{
public:
    string name;
    int age;
    char gender;
    string favorite_color;
    string password;

    User(string name, int age, char gender, string favorite_color, string password = "abcd")
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->favorite_color = favorite_color;

        // Huffman Encoding
        unordered_map<char, int> freq;
        for (char c : password)
            freq[c]++;

        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

        for (auto p : freq)
            pq.push({p.second, new Node(p.first)});

        while (pq.size() > 1)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            auto node = new Node('\0');
            node->left = p1.second;
            node->right = p2.second;
            pq.push({p1.first + p2.first, node});
        }

        auto root = pq.top().second;

        unordered_map<char, string> huffmanCode;
        encode(root, "", huffmanCode);

        string encodedPassword = "";
        for (char c : password)
            encodedPassword += huffmanCode[c];

        this->password = encodedPassword;
    }

private:
    struct Node
    {
        char ch;
        int freq;
        Node *left, *right;

        Node(char ch) : ch(ch), freq(0), left(nullptr), right(nullptr) {}
        Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
    };

    static void encode(Node *root, string str,
                       unordered_map<char, string> &huffmanCode)
    {
        if (root == nullptr)
            return;

        if (!root->left && !root->right)
        {
            huffmanCode[root->ch] = str;
        }

        encode(root->left, str + "0", huffmanCode);
        encode(root->right, str + "1", huffmanCode);
    }
};

class Graph
{
private:
    vector<User> users;

public:
    void add_new_user(User user)
    {
        users.push_back(user);
    }

    void delete_a_user(string name)
    {
        bool found = false;
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            if (it->name == name)
            {
                found = true;
                users.erase(it);
                break;
            }
        }
        if (!found)
        {
            cout << "User not found" << endl;
        }
        else
        {
            cout << "User deleted" << endl;
        }
    }

    User *find_a_user_by_name(string name)
    {
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            if (it->name == name)
            {
                return &(*it);
            }
        }
        return nullptr;
    }

    void get_matching_users(User user)
    {
        int count = 0;
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            if (it->name != user.name)
            {
                count = 0;
                if (it->age == user.age)
                {
                    count++;
                }
                if (it->gender == user.gender)
                {
                    count++;
                }
                if (it->favorite_color == user.favorite_color)
                {
                    count++;
                }
                if (count >= 2)
                {
                    cout << "Name: " << it->name << ", Age: " << it->age << ", Gender: " << it->gender << ", Favorite Color: " << it->favorite_color << endl;
                }
            }
        }
    }

    void sort_users_by_name()
    {
        mySort(users.begin(), users.end(), [](const User &user1, const User &user2)
               { return user1.name < user2.name; });
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            cout << "Name: " << it->name << ", Age: " << it->age << ", Gender: " << it->gender << ", Favorite Color: " << it->favorite_color << ", Password: " << it->password << endl;
        }
    }

    void sort_users_by_age()
    {
        mySort(users.begin(), users.end(), [](const User &user1, const User &user2)
               { return user1.age < user2.age; });
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            cout << "Name: " << it->name << ", Age: " << it->age << ", Gender: " << it->gender << ", Favorite Color: " << it->favorite_color << ", Password: " << it->password << endl;
        }
    }

    void addDummyUsers()
    {
        add_new_user(User("Aman", 22, 'F', "Blue"));
        add_new_user(User("Ball", 26, 'M', "Green"));
        add_new_user(User("Cat", 30, 'M', "Red"));
        add_new_user(User("Dark", 28, 'M', "Blue"));
        add_new_user(User("Evil", 22, 'F', "Green"));
        add_new_user(User("For", 32, 'M', "Yellow"));
        add_new_user(User("Github", 29, 'F', "Red"));
        add_new_user(User("Harshit", 27, 'M', "Blue"));
    }

    vector<User> find_similar_named_users(string name)
    {
        vector<User> matching_users;
        int n = name.size();

        for (auto it = users.begin(); it != users.end(); ++it)
        {
            int m = it->name.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (name[i - 1] == it->name[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            int lcs_length = dp[n][m];
            double similarity = (double)lcs_length / max(n, m);

            if (similarity >= 0.5)
            {
                matching_users.push_back(*it);
            }
        }

        if (matching_users.empty())
        {
            cout << "No matching users found." << endl;
        }

        return matching_users;
    }
};

int main()
{

    Graph graph;
    bool running = true;

    while (running)
    {
        cout << "GraphConnect - Choose an option:" << endl;
        cout << "0. Add dummy users" << endl; // for testing purposes
        cout << "1. Add a new user" << endl;
        cout << "2. Delete a user" << endl;
        cout << "3. Find a user by name" << endl;
        cout << "4. Get matching users" << endl;
        cout << "5. Sort users by name" << endl;
        cout << "6. Sort users by age" << endl;
        cout << "7. Find Similar Users" << endl;
        cout << "8. Exit" << endl;

        int option;
        cin >> option;

        system("clear"); // clear the console
        switch (option)
        {

        case 0:
            graph.addDummyUsers();
            cout << "=> Added dummy users" << endl;
            break;

        case 1:
        {
            string new_user_name, new_favorite_color, new_password;
            int new_age;
            char new_gender;

            cout << "Enter user details: " << endl;
            cout << "Name: ";
            cin >> new_user_name;
            cout << "Age: ";
            cin >> new_age;
            cout << "Gender (M/F): ";
            cin >> new_gender;
            cout << "Favorite Color: ";
            cin >> new_favorite_color;
            cout << "Password: ";
            cin >> new_password;

            User user(new_user_name, new_age, new_gender, new_favorite_color, new_password);
            graph.add_new_user(user);

            cout << "New user added successfully!" << endl;

            break;
        }
        case 2:
        {

            cout << "Enter the name of the user you want to delete: ";
            string name;
            cin >> name;
            graph.delete_a_user(name);
            break;
        }

        case 3:
        {
            cout << "Enter the name of the user you want to find: ";
            string user_to_find;
            cin >> user_to_find;
            User *searchResult = graph.find_a_user_by_name(user_to_find);
            if (searchResult != nullptr)
            {
                cout << searchResult->name << " " << searchResult->age << endl;
            }
            else
            {
                cout << "User not found" << endl;
            }
            break;
        }

        case 4:
        {
            cout << "Enter the name of the user you want to find matches for: ";
            string user_to_find;
            cin >> user_to_find;
            User *searchResult = graph.find_a_user_by_name(user_to_find);
            if (searchResult != nullptr)
            {
                graph.get_matching_users(*searchResult);
            }
            else
            {
                cout << "User not found" << endl;
            }
            break;
        }
        case 5:
        {
            graph.sort_users_by_name();
            break;
        }
        case 6:
        {
            graph.sort_users_by_age();
            break;
        }
        case 7:
        {
            vector<User> matching_users = graph.find_similar_named_users("Alicia");
            if (!matching_users.empty())
            {
                for (auto user : matching_users)
                {
                    cout << "Name: " << user.name << ", Age: " << user.age << ", Gender: " << user.gender << ", Favorite Color: " << user.favorite_color << endl;
                }
            }
            break;
        }
        case 8:
        {
            running = false;
            break;
        }
        }
    }
}