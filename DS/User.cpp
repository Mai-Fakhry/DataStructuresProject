#include "User.hpp"

User::User() : name("") {}

User::User(string name) : name(name) {}

string User::getName() const {
    return name;
}

// Add a post to the forum
void User::addPost(Forum& forum, const string& content, int parentId) {
    string quotedContent = "";
    
    if (parentId != 0) {
        Post parentPost = forum.getPostById(parentId);
        quotedContent = parentPost.getContent();  // Get the content of the post being replied to
    }
    
    forum.addPost(content, name, parentId, quotedContent);
}

// Display a post chain 
void User::displayPostChain(Forum& forum, int postId) {
    forum.displayPostChain(postId);
}

// Display a specific post
void User::displayPost(Forum& forum, int postId) {
    Post post = forum.getPostById(postId);
    cout << post.getAuthor() << ": " << post.getContent() << endl;
}
