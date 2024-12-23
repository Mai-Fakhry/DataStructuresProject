#ifndef FORUM_HPP
#define FORUM_HPP

#include "Post.hpp" // Make sure the Post class is defined elsewhere
#include <map>
#include <stack>
#include <iostream>
#include <stdexcept>

class Forum {
private:
    std::map<int, Post> posts;
    int lastPostId;

public:
    Forum(); // Constructor

    // Methods for adding posts, getting posts, displaying post chain, and displaying the forum
    void addPost(const std::string& content, const std::string& author, int parentId = 0, const std::string& quotedContent = "");
    int getLastPostId() const;
    Post getPostById(int postId) const;
    void displayPostChain(int postId) const;
    void displayForum() const;
};

#endif
