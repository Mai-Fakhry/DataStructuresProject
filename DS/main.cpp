#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include "Post.hpp"
#include "Forum.hpp"
#include "User.hpp"
#include "Post.cpp"
#include "Forum.cpp"
#include "User.cpp"

using namespace std;

int main() {
    Forum forum;
    vector<User> users;
    int choice;

    do {
        cout << "\n--- Forum Menu ---\n";
        cout << "1. Register new user\n";
        cout << "2. Add a new post\n";
        cout << "3. Add a reply to a post\n";
        cout << "4. Display a specific post\n";
        cout << "5. Display post chain for a post\n";
        cout << "6. Display all posts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string userName;
                cout << "Enter your user name: ";
                getline(cin, userName);
                users.push_back(User(userName));
                cout << "User " << userName << " registered successfully!\n";
                break;
            }

            case 2: {
                if (users.empty()) {
                    cout << "No users registered.\n";
                    break;
                }

                string userName;
                cout << "Enter your user name: ";
                getline(cin, userName);
                
                User* user = nullptr;
                for (auto& u : users) {
                    if (u.getName() == userName) {
                        user = &u;
                        break;
                    }
                }

                if (user == nullptr) {
                    cout << "User not found.\n";
                    break;
                }

                string content;
                cout << "Enter the content of the new post: ";
                getline(cin, content);
                user->addPost(forum, content);
                cout << "Post added successfully!\n";
                break;
            }

            case 3: {
                if (users.empty()) {
                    cout << "No users registered.\n";
                    break;
                }

                string userName;
                cout << "Enter your user name: ";
                getline(cin, userName);
                
                User* user = nullptr;
                for (auto& u : users) {
                    if (u.getName() == userName) {
                        user = &u;
                        break;
                    }
                }

                if (user == nullptr) {
                    cout << "User not found.\n";
                    break;
                }

                int parentId;
                cout << "Enter the ID of the post you want to reply to: ";
                cin >> parentId;
                cin.ignore();

                string replyContent;
                cout << "Enter your reply: ";
                getline(cin, replyContent);

                user->addPost(forum, replyContent, parentId);
                cout << "Reply added successfully!\n";
                break;
            }

            case 4: {
                if (users.empty()) {
                    cout << "No users registered.\n";
                    break;
                }

                string userName;
                cout << "Enter your user name: ";
                getline(cin, userName);

                User* user = nullptr;
                for (auto& u : users) {
                    if (u.getName() == userName) {
                        user = &u;
                        break;
                    }
                }

                if (user == nullptr) {
                    cout << "User not found.\n";
                    break;
                }

                int postId;
                cout << "Enter the ID of the post you want to display: ";
                cin >> postId;
                cin.ignore();

                // Ensure the post exists before displaying it
                try {
                    Post post = forum.getPostById(postId);
                    cout << post;
                } catch (const out_of_range& e) {
                    cout << "Post with ID " << postId << " does not exist.\n";
                }
                break;
            }

            case 5: {
                if (users.empty()) {
                    cout << "No users registered.\n";
                    break;
                }

                string userName;
                cout << "Enter your user name: ";
                getline(cin, userName);

                User* user = nullptr;
                for (auto& u : users) {
                    if (u.getName() == userName) {
                        user = &u;
                        break;
                    }
                }

                if (user == nullptr) {
                    cout << "User not found.\n";
                    break;
                }

                int postId;
                cout << "Enter the ID of the post you want to display the chain for: ";
                cin >> postId;
                cin.ignore();

                // Ensure the post exists before displaying the chain
                try {
                    user->displayPostChain(forum, postId);
                } catch (const out_of_range& e) {
                    cout << "Post with ID " << postId << " does not exist.\n";
                }
                break;
            }

            case 6: {
                forum.displayForum(); // Display all posts in the forum
                break;
            }

            case 7:
                cout << "Exiting the forum. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
