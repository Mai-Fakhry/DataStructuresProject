#include "Post.hpp"


Post::Post() : id(0), parentId(0), quotedContent("") {}

Post::Post(int id, const string& content, const string& author, int parentId, const string& quotedContent)
    : id(id), content(content), author(author), parentId(parentId), quotedContent(quotedContent) {}

string Post::getContent() const {
    return content;
}

string Post::getAuthor() const {
    return author;
}

string Post::getQuotedContent() const {
    return quotedContent;
}

// Add a reply to the current post
bool Post::addReply(const Post& reply) {
    if (reply.id == this->id) {
        return false; // A post cannot reply to itself
    }
    replies.push_back(reply);
    return true;
}

int Post::getParentId() const {
    return parentId;
}

int Post::getId() const {
    return id;
}

// Display post details, including quoted content
void Post::display(ostream& out, int depth) const {
    for (int i = 0; i < depth; i++) out << "  "; 
    out << "Post ID: " << id << " | Author: " << author << "\n";

    if (!quotedContent.empty()) {
        for (int i = 0; i < depth; i++) out << "  "; 
        out << "Quoted: " << quotedContent << "\n";
    }

    for (int i = 0; i < depth; i++) out << "  "; 
    out << "Content: " << content << "\n";

    // Recursively display replies
    for (const auto& reply : replies) {
        reply.display(out, depth + 1);
    }
    out << "\n";
}

ostream& operator<<(ostream& out, const Post& post) {
    post.display(out);
    return out;
}

istream& operator>>(istream& in, Post& post) {
    cout << "Enter post content: ";
    getline(in, post.content);
    cout << "Enter post author: ";
    getline(in, post.author);
    return in;
}
