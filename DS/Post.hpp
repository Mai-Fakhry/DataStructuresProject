#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <vector>
#include <string>

class Post {
private:
    int id;
    std::string content;
    std::string author;
    int parentId;
    std::string quotedContent;
    std::vector<Post> replies;

public:
    Post();  // Default constructor
    Post(int id, const std::string& content, const std::string& author, int parentId, const std::string& quotedContent = "");

    // Getters
    int getId() const;
    std::string getContent() const;
    std::string getAuthor() const;
    std::string getQuotedContent() const;
    int getParentId() const;

    // Methods
    bool addReply(const Post& reply);
    void display(std::ostream& out, int depth = 0) const;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& out, const Post& post);
    friend std::istream& operator>>(std::istream& in, Post& post);
};

#endif
