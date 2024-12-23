#include "User.hpp"
#include <stdexcept>

User::User() : name("") {}

User::User(const std::string& name) : name(name) {}

std::string User::getName() const {
    return name;
}

void User::addPost(Forum& forum, const std::string& content, int parentId) {
    std::string quotedContent = "";

    if (parentId != 0) {
        try {
            Post parentPost = forum.getPostById(parentId);
            quotedContent = parentPost.getContent();
        } catch (const std::out_of_range&) {
            throw std::invalid_argument("Parent post not found.");
        }
    }

    forum.addPost(content, name, parentId, quotedContent);
}

void User::displayPostChain(const Forum& forum, int postId) const {
    forum.displayPostChain(postId);
}
