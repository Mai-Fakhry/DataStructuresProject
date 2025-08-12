#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Post {
private:
    int id;
    int parentId;  // ID of the parent post 
    string content;
    string author;
    vector<Post> replies;  // All replies to this post
    string quotedContent;  // Stores quoted content 

public:
    Post();
    Post(int id, const string& content, const string& author, int parentId, const string& quotedContent = "");

    string getContent() const;
    string getAuthor() const;
    string getQuotedContent() const;

    bool addReply(const Post& reply);
    int getParentId() const;
    int getId() const;

    void display(ostream& out, int depth = 0) const;

    friend ostream& operator<<(ostream& out, const Post& post);
    friend istream& operator>>(istream& in, Post& post);
};

#endif
