#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Forum.hpp"

using namespace std;

class User {
private:
    string name;

public:
    User();
    User(string name);
    string getName() const;
    void addPost(Forum& forum, const string& content, int parentId = 0);
    void displayPostChain(Forum& forum, int postId);
    void displayPost(Forum& forum, int postId);
};

#endif
