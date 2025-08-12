#ifndef FORUM_HPP
#define FORUM_HPP

#include <iostream>
#include <map>
#include <stack>
#include "Post.hpp"

using namespace std;

class Forum {
private:
    map<int, Post> posts;
    int lastPostId;

public:
    Forum();
    void addPost(const string& content, const string& author, int parentId = 0, const string& quotedContent = "");
    int getLastPostId() const;
    void displayPostChain(int postId);
    Post getPostById(int postId);
    void displayForum() const;
};

#endif
