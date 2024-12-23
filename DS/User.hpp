#ifndef USER_HPP
#define USER_HPP

#include "Forum.hpp"
#include <string>

class User {
private:
    std::string name;

public:
    User();
    User(const std::string& name);

    std::string getName() const;
    void addPost(Forum& forum, const std::string& content, int parentId = 0);
    void displayPostChain(const Forum& forum, int postId) const;
};

#endif
